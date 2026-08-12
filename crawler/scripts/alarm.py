#!/usr/bin/env python3
"""服务器闹钟机制（部署方式二：自建服务器 cron）的闹钟表管理。

订阅列表（crawler/subscriptions/*.json）中每条可选填 end_time：
  - 不填 end_time    = 历史比赛：sync 立即爬取归档，不生成复盘报告
  - end_time 在未来  = 未来比赛：sync 写入闹钟表，到点（fire）爬取并生成报告
  - end_time 已过    = 过期比赛：sync 立即爬取并生成报告（如闹钟失败后补漏）

闹钟表 crawler/alarms.json 是运行时状态文件（gitignore，不提交），由本模块
统一读写；daemon.py 的 sync / fire 子命令编排：
  sync  → alarm.py plan   （输出 HISTORY / EXPIRED / RETRY 链接，写未来闹钟）
  fire  → alarm.py due    （输出到点未触发的闹钟链接，daemon 定时调用）
  fire  → alarm.py mark   （成功后标记 archived；失败标记 failed）

状态模型（每条闹钟一个 status）：
  planned   未来比赛：fire_at = end_time，等待 fire（due 只查这个状态）
  pending   sync 已安排立即处理（HISTORY / EXPIRED 待爬取；fire_at 为空）
  archived  已处理完（历史/过期已归档、未来已触发）；sync 跳过、fire 忽略
  failed    爬取失败：fire 忽略，下次 sync 重试一次（成功 → archived，失败保持 failed）

与订阅文件保持同步：
  - 订阅里修改 end_time → plan 检测到信息变更，重新安排（archived 也会被重新激活）
  - 订阅里删除条目 → plan 剪除对应闹钟（含 archived 历史）
  - failed 条目**永不重置**：只有重试成功（mark --archived）才改变状态

子命令（输出 tab 分隔，供 bash 解析）：
  python3 crawler/scripts/alarm.py plan
      读取订阅 + 闹钟表，输出：
        HISTORY\t<link>   历史比赛：立即爬取，不生成报告
        EXPIRED\t<link>   过期比赛：立即爬取并生成报告
        RETRY\t<link>     上次失败的比赛：本次 sync 重试一次（第 3 列 =
                         end_time：空 = 原 HISTORY 不生成报告；非空 = 原
                         EXPIRED/planned 生成报告）
      未来比赛写入/更新闹钟表（planned）。有 failed 重试时输出
      "[alarm] WARNING: ..." 提示用户。
  python3 crawler/scripts/alarm.py due
      输出 DUE\t<link>：status == planned、fire_at 已到、未失败的闹钟；
      无则无输出（fire 每分钟调用，保持安静避免刷日志）。pending/archived/failed 忽略。
  python3 crawler/scripts/alarm.py mark <link> --archived|--failed
      标记状态：--archived 置 archived（attempts 清零，sync/fire 处理成功）；
      --failed attempts +1、置 failed（fire 不再重试，下次 sync 重试一次）。
  python3 crawler/scripts/alarm.py list
      人类可读列出全部闹钟（server-task.sh status 用）。
"""

import json
import os
import sys
from datetime import datetime

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..")))

from crawler.platforms.base import beijing, load_subscriptions_dir

# 本模块在 crawler/scripts/，仓库根为 ../..
REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
ALARMS_PATH = os.path.join(REPO_ROOT, "crawler", "alarms.json")
CONFIG_PATH = os.path.join(REPO_ROOT, "crawler", "config.json")
SUBSCRIPTIONS_DIR = os.path.join(REPO_ROOT, "crawler", "subscriptions")

# 平台顺序（与 scheduled_task.py 保持一致）
PLATFORM_ORDER = ("qoj", "hdu", "nowcoder")

# 闹钟状态
STATUS_PLANNED = "planned"      # 未来比赛：等 fire（fire_at = end_time）
STATUS_PENDING = "pending"      # sync 已安排立即处理（HISTORY/EXPIRED 待爬，fire_at 为空）
STATUS_ARCHIVED = "archived"    # 已处理完：sync 跳过、fire 忽略
STATUS_FAILED = "failed"        # 爬取失败：fire 忽略，下次 sync 重试一次


def _load_alarms():
    """读取闹钟表，返回 {link: entry}。文件缺失/损坏时返回空 dict。

    兼容旧格式迁移：旧条目用 fired/failed 布尔推断状态，统一为
    status 字段（fired → archived，failed → failed，其余 → planned）。
    """
    if not os.path.exists(ALARMS_PATH):
        return {}
    try:
        with open(ALARMS_PATH, "r", encoding="utf-8") as f:
            entries = json.load(f)
    except Exception as e:
        print(f"[alarm] Failed to read {ALARMS_PATH}: {e}; starting fresh.")
        return {}
    if not isinstance(entries, list):
        return {}
    alarms = {}
    for e in entries:
        link = e.get("link", "")
        if not link:
            continue
        alarms[link] = _migrate_alarm(e)
    return alarms


def _migrate_alarm(e):
    """旧格式（fired/failed 布尔）迁移到新 status 字段；已是新格式原样返回。"""
    if "status" in e:
        return e
    e = dict(e)
    if e.get("fired"):
        e["status"] = STATUS_ARCHIVED
    elif e.get("failed"):
        e["status"] = STATUS_FAILED
    else:
        e["status"] = STATUS_PLANNED
    e.pop("fired", None)
    e.pop("failed", None)
    return e


def _save_alarms(alarms):
    """写回闹钟表（按 link 排序，便于阅读与 diff）。"""
    entries = sorted(alarms.values(), key=lambda e: e.get("link", ""))
    with open(ALARMS_PATH, "w", encoding="utf-8") as f:
        json.dump(entries, f, ensure_ascii=False, indent=2)


def _load_enabled_platforms():
    """与 scheduled_task.py 一致：config.json 中显式 enabled: true 的平台。"""
    if not os.path.exists(CONFIG_PATH):
        return []
    try:
        with open(CONFIG_PATH, "r", encoding="utf-8") as f:
            config = json.load(f)
    except Exception as e:
        print(f"[alarm] Failed to parse {CONFIG_PATH}: {e}; all platforms disabled.")
        return []
    return [p for p in PLATFORM_ORDER if config.get(p, {}).get("enabled", False)]


def _parse_time(s):
    """解析 ISO 时间为北京时间 aware datetime；无效返回 None。

    naive 时间按北京时间墙钟解释（与爬虫约定一致）；Z 后缀视为 UTC。
    """
    if not s:
        return None
    s = str(s).strip()
    if s.endswith("Z") or s.endswith("z"):
        s = s[:-1] + "+00:00"
    try:
        dt = datetime.fromisoformat(s)
    except ValueError:
        return None
    if dt.tzinfo is None:
        dt = dt.replace(tzinfo=beijing)
    return dt.astimezone(beijing)


def _new_entry(platform, link, end_time, fire_at, status):
    return {
        "platform": platform,
        "link": link,
        "end_time": end_time,
        "fire_at": fire_at,
        "status": status,
        "attempts": 0,
        "updated_at": datetime.now(beijing).isoformat(),
    }


def cmd_plan():
    """读取订阅 + 闹钟表：输出 HISTORY / EXPIRED / RETRY 链接，写未来闹钟。

    - 只处理「已启用平台（config.json）」+「订阅级 enabled」的条目。
    - archived 且订阅信息未变 → 跳过（已处理完）。
    - failed 且订阅信息未变 → 输出 RETRY（**保持 failed 不重置**，本次重试一次，
      由 sync 爬取结果决定 archived 或继续 failed）。
    - planned 且未到点 → 保持等 fire。
    - 其余（新建 / 信息变更 / pending 遗留 / planned 已到点 / failed 但信息变更）
      → 按 end_time 重新分类：不填 → HISTORY；已过 → EXPIRED（均置 pending 待爬）；
        未来 → planned（fire_at = end_time）。
    - 订阅中已删除的 link 剪除闹钟（含 archived 历史）。
    """
    enabled = set(_load_enabled_platforms())
    subs = load_subscriptions_dir(SUBSCRIPTIONS_DIR, platform=None)
    active = [
        s for s in subs
        if s.get("platform") in enabled and s.get("enabled", True)
    ]
    alarms = _load_alarms()
    now = datetime.now(beijing)

    history_links = []
    expired_links = []
    retry_links = []
    active_links = set()
    for s in active:
        link = str(s.get("link") or "").rstrip("/")
        if not link:
            continue
        active_links.add(link)
        end_time = s.get("end_time")
        end_dt = _parse_time(end_time)
        existing = alarms.get(link)

        if existing is not None:
            st = existing.get("status")
            unchanged = existing.get("end_time") == end_time
            if unchanged and st == STATUS_ARCHIVED:
                # 已处理完且订阅未变：跳过
                continue
            if unchanged and st == STATUS_FAILED:
                # 上次失败：本次 sync 重试一次（保持 failed，不重置）。
                # 输出第 3 列 = end_time，供 sync 判断重试成功后的报告策略：
                #   空（原 HISTORY）→ 不生成报告；非空（原 EXPIRED/planned）→ 生成。
                retry_links.append((link, end_time))
                continue
            if unchanged and st == STATUS_PLANNED and end_dt is not None and end_dt > now:
                # 未来闹钟未到点：等 fire
                continue
            # 其余情况（新建 / 信息变更 / pending 遗留 / planned 已到点 / failed 但信息变更）
            # → 重新分类。重建条目（信息变更时 attempts 清零属合理重置）。

        # 重新分类
        if end_dt is None:
            # 历史比赛：立即爬取，不生成报告
            alarms[link] = _new_entry(
                s.get("platform"), link, None, None, STATUS_PENDING
            )
            history_links.append(link)
        elif end_dt <= now:
            # 过期比赛：立即爬取 + 生成报告（如闹钟失败后补漏）
            alarms[link] = _new_entry(
                s.get("platform"), link, end_time, None, STATUS_PENDING
            )
            expired_links.append(link)
        else:
            # 未来比赛：写闹钟，等 fire
            alarms[link] = _new_entry(
                s.get("platform"), link, end_time, end_time, STATUS_PLANNED
            )

    # 剪除已不在订阅中的闹钟（含 archived 历史）
    for link in list(alarms):
        if link not in active_links:
            del alarms[link]

    _save_alarms(alarms)

    for link in history_links:
        print(f"HISTORY\t{link}")
    for link in expired_links:
        print(f"EXPIRED\t{link}")
    for link, end_time in retry_links:
        # 第 3 列 = end_time：空 = 原 HISTORY（重试成功不生成报告）；
        # 非空 = 原 EXPIRED/planned（重试成功要生成报告）。
        print(f"RETRY\t{link}\t{end_time or ''}")

    if retry_links:
        print(
            "[alarm] WARNING: "
            f"{len(retry_links)} previously failed alarm(s) will be retried: "
            f"{', '.join(link for link, _ in retry_links)}"
        )
    print(
        f"[alarm] plan: {len(history_links)} history, {len(expired_links)} expired, "
        f"{len(retry_links)} retry, {len(alarms)} alarms tracked."
    )


def cmd_due():
    """输出 DUE\t<link>：status == planned、fire_at 已到、未失败的闹钟。

    fire 任务定时调用（daemon 默认每 5 分钟）；无到期闹钟时**无任何输出**，
    避免刷日志。
    pending / archived / failed 一律忽略（fire 只处理未来闹钟）。
    """
    alarms = _load_alarms()
    now = datetime.now(beijing)
    due = []
    for e in alarms.values():
        if e.get("status") != STATUS_PLANNED:
            continue
        fire_at = e.get("fire_at")
        if not fire_at:
            continue
        dt = _parse_time(fire_at)
        if dt is None or dt <= now:
            due.append(e.get("link"))
    for link in sorted(due):
        print(f"DUE\t{link}")


def cmd_mark(link, state):
    """标记闹钟状态。

    --archived：置 archived（attempts 清零）；sync / fire 处理成功时调用。
    --failed：attempts +1、置 failed（fire 不再重试，下次 sync 重试一次）。
    条目不存在时创建 minimal 条目（兜底：如 plan 后表被外部清理）。
    """
    link = link.rstrip("/")
    alarms = _load_alarms()
    e = alarms.get(link)
    if e is None:
        e = _new_entry("", link, None, None, STATUS_PENDING)
        alarms[link] = e
    if state == "archived":
        e["status"] = STATUS_ARCHIVED
        e["attempts"] = 0
        e["updated_at"] = datetime.now(beijing).isoformat()
        print(f"[alarm] mark {link}: archived.")
    elif state == "failed":
        e["status"] = STATUS_FAILED
        e["attempts"] = e.get("attempts", 0) + 1
        e["updated_at"] = datetime.now(beijing).isoformat()
        print(
            f"[alarm] mark {link}: failed "
            f"(attempts={e['attempts']}); will retry on next sync."
        )
    else:
        print(f"[alarm] mark: unknown state {state!r}.", file=sys.stderr)
        sys.exit(1)
    _save_alarms(alarms)


def cmd_list():
    """人类可读列出全部闹钟（server-task.sh status 用）。"""
    alarms = _load_alarms()
    if not alarms:
        print("(no alarms)")
        return
    now = datetime.now(beijing)
    print(f"{'link':<56} {'platform':<8} {'status':<10} {'fire_at':<26} attempts")
    for e in sorted(alarms.values(), key=lambda x: x.get("link", "")):
        fire_at = e.get("fire_at") or "-"
        status = e.get("status", "?")
        if status == STATUS_PLANNED:
            dt = _parse_time(fire_at)
            state = "due" if (dt and dt <= now) else "scheduled"
        elif status == STATUS_PENDING:
            state = "pending(sync)"
        elif status == STATUS_ARCHIVED:
            state = "archived"
        elif status == STATUS_FAILED:
            state = f"failed({e.get('attempts', 0)})"
        else:
            state = status
        print(
            f"{e['link']:<56} {e.get('platform', ''):<8} "
            f"{status:<10} {fire_at:<26} {e.get('attempts', 0)}"
        )


def main():
    args = sys.argv[1:]
    if not args:
        print(__doc__)
        sys.exit(1)
    cmd = args[0]
    if cmd == "plan":
        cmd_plan()
    elif cmd == "due":
        cmd_due()
    elif cmd == "mark":
        if len(args) < 3:
            print("usage: alarm.py mark <link> --archived|--failed", file=sys.stderr)
            sys.exit(1)
        cmd_mark(args[1], args[2].lstrip("-"))
    elif cmd == "list":
        cmd_list()
    else:
        print(f"unknown command: {cmd}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
