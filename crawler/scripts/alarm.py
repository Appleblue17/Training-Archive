#!/usr/bin/env python3
"""服务器闹钟机制（部署方式二：自建服务器 cron）的闹钟表管理。

订阅列表（crawler/subscriptions/*.json）中每条可选填 end_time：
  - 不填 end_time    = 历史比赛：sync 立即爬取归档，不生成复盘报告
  - end_time 在未来  = 未来比赛：sync 写入闹钟表，到点（fire）爬取并生成报告
  - end_time 已过    = 过期比赛：sync 立即爬取并生成报告（如闹钟失败后补漏）

未来比赛可另填 start_time（比赛开始时间，可选）：
  - 填了 start_time → 赛前提醒用该时间
  - 没填 → 回退为 end_time - 5 小时（HDU 暑期联赛默认 5 小时）
  daemon 的 remind 任务在 start_time 前 15 分钟（config.json qq.
  remind_before_minutes，缺省 15）向 QQ 群发提醒，发成功后标记 reminded_at。

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
  python3 crawler/scripts/alarm.py remind
      输出 REMIND\t<link>\t<start_time>\t<comments>：planned 且已进入赛前提醒
      窗口（start_time 前 remind_before_minutes 分钟内）且未提醒过（reminded_at
      为空）的闹钟；daemon 发送成功后调 mark --reminded 标记。
  python3 crawler/scripts/alarm.py mark <link> --archived|--failed|--reminded
      标记状态：--archived 置 archived（attempts 清零，sync/fire 处理成功）；
      --failed attempts +1、置 failed（fire 不再重试，下次 sync 重试一次）；
      --reminded 置 reminded_at（赛前提醒已发送，不再重复提醒）。
  python3 crawler/scripts/alarm.py list
      人类可读列出全部闹钟（server-task.sh status 用）。
"""

import json
import os
import sys
from datetime import datetime, timedelta

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

# 赛前提醒：缺 start_time 时用 end_time - DEFAULT_CONTEST_DURATION_HOURS 推算
# （HDU 暑期联赛默认 5 小时）；提醒窗口为 start_time 前 REMIND_MINUTES 分钟。
DEFAULT_CONTEST_DURATION_HOURS = 5
REMIND_MINUTES = 15


def _load_alarms():
    """读取闹钟表，返回 {link: entry}。

    文件不存在 = 首次运行，返回 {}（正常从零开始）。
    文件存在但读取/解析失败 = 状态损坏：返回 None（调用方必须处理——
    cmd_plan 据此中止返回非零，避免把全部闹钟当空表重建导致已归档比赛重爬）。
    """
    if not os.path.exists(ALARMS_PATH):
        return {}
    try:
        with open(ALARMS_PATH, "r", encoding="utf-8") as f:
            entries = json.load(f)
    except Exception as e:
        print(f"[alarm] ERROR: Failed to read {ALARMS_PATH}: {e}; "
              "alarm state may be lost if we continue.")
        return None
    if not isinstance(entries, list):
        print(f"[alarm] ERROR: {ALARMS_PATH} is not a list; alarm state may be lost.")
        return None
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


def _has_time_value(v):
    """订阅时间字段是否有实际值（None / 空串视为未填）。"""
    return v is not None and str(v).strip() != ""


def _effective_start_time(s):
    """订阅 → 比赛开始时间（ISO）：显式 start_time 优先；否则 end_time - 5 小时。"""
    st = _parse_time(s.get("start_time"))
    if st is not None:
        return st.isoformat()
    end = _parse_time(s.get("end_time"))
    if end is not None:
        return (end - timedelta(hours=DEFAULT_CONTEST_DURATION_HOURS)).isoformat()
    return None


def _remind_window_minutes():
    """赛前提醒提前量（分钟）：config.json qq.remind_before_minutes，缺省 15。"""
    try:
        with open(CONFIG_PATH, "r", encoding="utf-8") as f:
            config = json.load(f)
        qq = config.get("qq", {})
        v = int(qq.get("remind_before_minutes", REMIND_MINUTES))
        return v if v > 0 else REMIND_MINUTES
    except Exception:
        return REMIND_MINUTES


def _new_entry(platform, link, end_time, fire_at, status, start_time=None, comments=""):
    return {
        "platform": platform,
        "link": link,
        "end_time": end_time,
        "start_time": start_time,
        "fire_at": fire_at,
        "status": status,
        "comments": comments,
        "attempts": 0,
        "updated_at": datetime.now(beijing).isoformat(),
    }


def _subscription_diag():
    """订阅加载诊断收集器：返回 (log_callback, counters)。

    load_subscriptions_dir 对坏文件 / 坏条目默认静默跳过（log=None 时 _log
    是空操作）。这里接住 error/warning 并输出到 stdout（daemon sync 会转发
    到日志），用户能立刻看到格式有问题的订阅文件；counters 供 plan 汇总行
    报告数量。
    """
    counters = {"errors": 0, "warnings": 0}

    def _log(level, msg):
        counters["errors" if level == "error" else "warnings"] += 1
        print(f"[alarm] {level.upper()}: {msg}")

    return _log, counters


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
    - 订阅文件解析失败 / 非列表 / 条目缺 link / 重复 link：输出
      [alarm] ERROR/WARNING 诊断。
    - 订阅条目的 end_time / start_time 字段存在但格式无法解析：输出
      [alarm] ERROR 并**跳过该条目**（不当 HISTORY 静默处理），且本命令返回
      非零——daemon sync 检测到后中止（含 /sync 手动触发），修复后重跑。
    """
    enabled = set(_load_enabled_platforms())
    sub_log, sub_diag = _subscription_diag()
    subs = load_subscriptions_dir(
        SUBSCRIPTIONS_DIR, platform=None, log=sub_log
    )
    active = [
        s for s in subs
        if s.get("platform") in enabled and s.get("enabled", True)
    ]
    alarms = _load_alarms()
    if alarms is None:
        # 闹钟表损坏：中止（返回非零，daemon sync 不爬取不提交）。不能当
        # 空表继续——那样会把全部 archived 状态丢掉，已归档比赛全部重爬。
        print("[alarm] ERROR: alarms.json unreadable; aborting plan. "
              "Fix or remove crawler/alarms.json, then re-run sync.")
        return 1
    now = datetime.now(beijing)

    history_links = []
    expired_links = []
    retry_links = []
    active_links = set()
    time_errors = 0
    for s in active:
        link = str(s.get("link") or "").rstrip("/")
        if not link:
            continue
        # 只要订阅里存在该 link 就加入 active_links：即使时间字段非法被跳过
        # 也不剪除其既有闹钟（否则填错时间会把 archived/planned 闹钟删掉）。
        active_links.add(link)
        end_time = s.get("end_time")
        start_time = s.get("start_time")
        # 时间格式校验：字段存在但无法解析 → ERROR + 跳过（不参与分类，
        # 既有闹钟保留，修复后下次 plan 再处理）。避免把"填错时间"静默当作
        # "未填"（HISTORY 立即爬取且不生成报告）。
        if _has_time_value(end_time) and _parse_time(end_time) is None:
            time_errors += 1
            print(
                f"[alarm] ERROR: subscription {link} has invalid end_time "
                f"{end_time!r}; skipped."
            )
            continue
        if _has_time_value(start_time) and _parse_time(start_time) is None:
            time_errors += 1
            print(
                f"[alarm] ERROR: subscription {link} has invalid start_time "
                f"{start_time!r}; skipped."
            )
            continue
        end_dt = _parse_time(end_time)
        existing = alarms.get(link)

        if existing is not None:
            st = existing.get("status")
            unchanged = (
                existing.get("end_time") == end_time
                and existing.get("start_time") == _effective_start_time(s)
            )
            if unchanged and existing.get("comments") != str(s.get("comments") or ""):
                # comments 仅展示用（赛前提醒 / 列表）：原地更新，不触发重分类
                existing["comments"] = str(s.get("comments") or "")
                existing["updated_at"] = datetime.now(beijing).isoformat()
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
                # 未来闹钟未到点：等 fire。fire_at 与 end_time 不一致（损坏/
                # 被外部改过）时顺手修正，否则可能永不触发或提前触发。
                if existing.get("fire_at") != end_time:
                    existing["fire_at"] = end_time
                    existing["updated_at"] = datetime.now(beijing).isoformat()
                continue
            # 其余情况（新建 / 信息变更 / pending 遗留 / planned 已到点 / failed 但信息变更）
            # → 重新分类。重建条目（信息变更时 attempts 清零属合理重置）。

        # 重新分类
        if end_dt is None:
            # 历史比赛：立即爬取，不生成报告
            alarms[link] = _new_entry(
                s.get("platform"), link, None, None, STATUS_PENDING,
                start_time=_effective_start_time(s),
                comments=str(s.get("comments") or ""),
            )
            history_links.append(link)
        elif end_dt <= now:
            # 过期比赛：立即爬取 + 生成报告（如闹钟失败后补漏）。
            # start_time 存计算值（end_time - 5h）：下次 plan 的 unchanged
            # 比较才成立，否则 archived 条目 start_time=null != 计算值，
            # 每次 sync 都把同一场当 EXPIRED 重爬。
            alarms[link] = _new_entry(
                s.get("platform"), link, end_time, None, STATUS_PENDING,
                start_time=_effective_start_time(s),
                comments=str(s.get("comments") or ""),
            )
            expired_links.append(link)
        else:
            # 未来比赛：写闹钟，等 fire（赛前提醒用 start_time）
            alarms[link] = _new_entry(
                s.get("platform"), link, end_time, end_time, STATUS_PLANNED,
                start_time=_effective_start_time(s),
                comments=str(s.get("comments") or ""),
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
    if sub_diag["errors"] or time_errors:
        print(
            "[alarm] ERROR: subscription file(s) with format problems were skipped; "
            "their contests will NOT be synced. Fix them and re-run sync."
        )
    diag = ""
    if sub_diag["errors"] or sub_diag["warnings"] or time_errors:
        diag = (
            f", subscription diag: {sub_diag['errors']} errors, "
            f"{sub_diag['warnings']} warnings"
        )
        if time_errors:
            diag += f", {time_errors} invalid time"
    print(
        f"[alarm] plan: {len(history_links)} history, {len(expired_links)} expired, "
        f"{len(retry_links)} retry, {len(alarms)} alarms tracked{diag}."
    )
    # 格式有问题（文件坏 / 时间非法）→ 返回非零，daemon sync 据此中止
    return 1 if (sub_diag["errors"] or time_errors) else 0


def cmd_due():
    """输出 DUE\t<link>：status == planned、fire_at 已到、未失败的闹钟。

    fire 任务定时调用（daemon 默认每 5 分钟）；无到期闹钟时**无任何输出**，
    避免刷日志。
    pending / archived / failed 一律忽略（fire 只处理未来闹钟）。
    """
    alarms = _load_alarms()
    if alarms is None:
        return
    now = datetime.now(beijing)
    due = []
    for e in alarms.values():
        if e.get("status") != STATUS_PLANNED:
            continue
        fire_at = e.get("fire_at")
        if not fire_at:
            continue
        dt = _parse_time(fire_at)
        if dt is None:
            # fire_at 损坏：跳过（不当作到期触发），plan 下次会修正 fire_at
            continue
        if dt <= now:
            due.append(e.get("link"))
    for link in sorted(due):
        print(f"DUE\t{link}")


def cmd_remind():
    """输出 REMIND\t<link>\t<start_time>\t<comments>：planned 且进入赛前提醒窗口。

    提醒窗口 = [start_time - remind_before_minutes, start_time)。已提醒过
    （reminded_at 非空）不再输出。无待提醒时**无任何输出**（daemon 每 5 分钟
    调用，保持安静避免刷日志）。daemon 发送成功后调 mark --reminded 标记。
    """
    window = timedelta(minutes=_remind_window_minutes())
    alarms = _load_alarms()
    if alarms is None:
        return
    now = datetime.now(beijing)
    for e in sorted(alarms.values(), key=lambda x: x.get("start_time") or ""):
        if e.get("status") != STATUS_PLANNED:
            continue
        start = _parse_time(e.get("start_time"))
        if start is None:
            continue
        if not (start - window <= now < start):
            continue
        if e.get("reminded_at"):
            continue
        comments = str(e.get("comments") or "").replace("\t", " ").replace("\n", " ")
        print(f"REMIND\t{e['link']}\t{start.isoformat()}\t{comments}")


def cmd_mark(link, state):
    """标记闹钟状态。

    --archived：置 archived（attempts 清零）；sync / fire 处理成功时调用。
    --failed：attempts +1、置 failed（fire 不再重试，下次 sync 重试一次）。
    条目不存在时创建 minimal 条目（兜底：如 plan 后表被外部清理）。
    """
    link = link.rstrip("/")
    alarms = _load_alarms()
    if alarms is None:
        print(f"[alarm] ERROR: alarms.json unreadable; cannot mark {link}.", file=sys.stderr)
        sys.exit(1)
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
    elif state == "reminded":
        e["reminded_at"] = datetime.now(beijing).isoformat()
        e["updated_at"] = datetime.now(beijing).isoformat()
        print(f"[alarm] mark {link}: reminded.")
    else:
        print(f"[alarm] mark: unknown state {state!r}.", file=sys.stderr)
        sys.exit(1)
    _save_alarms(alarms)


def cmd_list():
    """人类可读列出全部闹钟（server-task.sh status 用）。"""
    alarms = _load_alarms()
    if alarms is None:
        print("(alarms.json unreadable)")
        return
    if not alarms:
        print("(no alarms)")
        return
    now = datetime.now(beijing)
    print(f"{'link':<56} {'platform':<8} {'status':<10} {'start_time':<26} {'fire_at':<26} attempts")
    for e in sorted(alarms.values(), key=lambda x: x.get("link", "")):
        fire_at = e.get("fire_at") or "-"
        start_at = e.get("start_time") or "-"
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
            f"{status:<10} {start_at:<26} {fire_at:<26} {e.get('attempts', 0)}"
        )


def main():
    args = sys.argv[1:]
    if not args:
        print(__doc__)
        sys.exit(1)
    cmd = args[0]
    if cmd == "plan":
        sys.exit(cmd_plan())
    elif cmd == "due":
        cmd_due()
    elif cmd == "remind":
        cmd_remind()
    elif cmd == "mark":
        if len(args) < 3:
            print("usage: alarm.py mark <link> --archived|--failed|--reminded", file=sys.stderr)
            sys.exit(1)
        cmd_mark(args[1], args[2].lstrip("-"))
    elif cmd == "list":
        cmd_list()
    else:
        print(f"unknown command: {cmd}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
