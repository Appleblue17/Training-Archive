#!/usr/bin/env python3
"""服务器闹钟机制（部署方式二：自建服务器 cron）的闹钟表管理。

背景：订阅列表（crawler/subscriptions/*.json）中每条可选填 end_time：
  - 不填 end_time    = 历史比赛：sync 时立即爬取归档，不生成复盘报告
  - end_time 在未来  = 未来比赛：sync 写入闹钟表，到点（fire）爬取并生成报告
  - end_time 已过    = 过期比赛：sync 立即爬取并生成报告（如闹钟失败后补漏）

闹钟表 crawler/alarms.json 是运行时状态文件（gitignore，不提交），由本模块
统一读写；server-task.sh 的 sync / fire 子命令编排：
  sync  → alarm.py plan   （输出 HISTORY / EXPIRED 链接，写入未来闹钟）
  fire  → alarm.py due    （输出到点未触发的闹钟链接，cron 每分钟调用）
  fire  → alarm.py mark   （成功后标记 fired；失败标记 failed / 计数）

子命令（输出 tab 分隔，供 bash 解析）：
  python3 crawler/scripts/alarm.py plan
      读取订阅 + 闹钟表，输出：
        HISTORY\t<link>   历史比赛：立即爬取，不生成报告
        EXPIRED\t<link>   过期比赛：立即爬取并生成报告
      未来比赛写入闹钟表（按 link 幂等，fire_at 变化时更新）。
  python3 crawler/scripts/alarm.py due
      输出 DUE\t<link>：fire_at 已到、未触发、未失败的闹钟；无则无输出（fire 每分钟
      调用，保持安静避免刷日志）。
  python3 crawler/scripts/alarm.py mark <link> --fired|--failed
      标记闹钟状态：--fired 置 fired=true（保留历史，plan 跳过）；
      --failed 计数 +1，超过 MAX_ATTEMPTS 置 failed=true（fire 不再重试，靠下次
      sync 补抓）。
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

# 单条闹钟最多失败次数；超过后置 failed=true（fire 不再重试，靠下次 sync 补抓）。
# fire 每分钟跑一次，3 次失败约等于连续 3 分钟重试，足够覆盖瞬时网络抖动。
MAX_ATTEMPTS = 3


def _load_alarms():
    """读取闹钟表，返回 {link: entry}。文件缺失/损坏时返回空 dict。"""
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
    return {e.get("link", ""): e for e in entries if e.get("link")}


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


def _new_entry(platform, link, end_time, fire_at):
    return {
        "platform": platform,
        "link": link,
        "end_time": end_time,
        "fire_at": fire_at,
        "fired": False,
        "failed": False,
        "attempts": 0,
        "added_at": datetime.now(beijing).isoformat(),
    }


def cmd_plan():
    """读取订阅 + 闹钟表：输出 HISTORY / EXPIRED 链接，写入未来闹钟。

    - 只处理「已启用平台（config.json）」+「订阅级 enabled」的条目。
    - 已 fired 的条目跳过（历史已归档 / 闹钟已完成）。
    - 不填 end_time → HISTORY（立即爬，不报告）。
    - end_time <= now → EXPIRED（立即爬 + 报告）；重置失败状态允许本次重试。
    - end_time > now → 写入/更新闹钟（fire_at = end_time）。
    - 不在订阅中的闹钟（含 fired 历史）剪除。
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
    active_links = set()
    for s in active:
        link = str(s.get("link") or "").rstrip("/")
        if not link:
            continue
        active_links.add(link)
        end_dt = _parse_time(s.get("end_time"))
        existing = alarms.get(link)
        if existing and existing.get("fired"):
            # 已处理过，跳过
            continue

        if end_dt is None:
            # 历史比赛：立即爬取，不生成报告
            if existing is None:
                alarms[link] = _new_entry(
                    s.get("platform"), link, s.get("end_time"), None
                )
            else:
                # 重新尝试（如上次爬取失败）
                existing.update({"fired": False, "failed": False, "attempts": 0})
            history_links.append(link)
        elif end_dt <= now:
            # 过期比赛：立即爬取 + 生成报告（如闹钟失败后补漏）
            fire_at = s.get("end_time")
            if existing is None:
                alarms[link] = _new_entry(s.get("platform"), link, fire_at, fire_at)
            else:
                existing.update(
                    {"fired": False, "failed": False, "attempts": 0, "fire_at": fire_at}
                )
            expired_links.append(link)
        else:
            # 未来比赛：写闹钟
            fire_at = s.get("end_time")
            if existing is None:
                alarms[link] = _new_entry(s.get("platform"), link, fire_at, fire_at)
            else:
                existing.update(
                    {
                        "platform": s.get("platform"),
                        "end_time": fire_at,
                        "fire_at": fire_at,
                        "fired": False,
                        "failed": False,
                        "attempts": 0,
                    }
                )

    # 剪除已不在订阅中的闹钟（含 fired 历史）
    for link in list(alarms):
        if link not in active_links:
            del alarms[link]

    _save_alarms(alarms)

    for link in history_links:
        print(f"HISTORY\t{link}")
    for link in expired_links:
        print(f"EXPIRED\t{link}")
    print(
        f"[alarm] plan: {len(history_links)} history, {len(expired_links)} expired, "
        f"{len(alarms)} alarms tracked."
    )


def cmd_due():
    """输出 DUE\t<link>：fire_at 已到、未触发、未失败的闹钟。

    fire 每分钟调用；无到期闹钟时**无任何输出**，避免刷日志。
    """
    alarms = _load_alarms()
    now = datetime.now(beijing)
    due = []
    for e in alarms.values():
        if e.get("fired") or e.get("failed"):
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

    --fired：置 fired=true（保留历史条目，plan 跳过）。
    --failed：attempts +1；超过 MAX_ATTEMPTS 置 failed=true（fire 不再重试）。
    """
    link = link.rstrip("/")
    alarms = _load_alarms()
    e = alarms.get(link)
    if e is None:
        print(f"[alarm] mark {link}: not found; nothing to do.")
        return
    if state == "fired":
        e["fired"] = True
        e["failed"] = False
        e["attempts"] = 0
        print(f"[alarm] mark {link}: fired.")
    elif state == "failed":
        e["attempts"] = e.get("attempts", 0) + 1
        if e["attempts"] >= MAX_ATTEMPTS:
            e["failed"] = True
            print(
                f"[alarm] mark {link}: failed "
                f"(attempts={e['attempts']} >= {MAX_ATTEMPTS}); waiting for sync."
            )
        else:
            print(
                f"[alarm] mark {link}: failed "
                f"(attempts={e['attempts']}/{MAX_ATTEMPTS}); will retry."
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
    print(f"{'link':<56} {'platform':<8} {'fire_at':<26} state")
    for e in sorted(alarms.values(), key=lambda x: x.get("fire_at") or "9999"):
        fire_at = e.get("fire_at") or "-"
        if e.get("fired"):
            state = "fired"
        elif e.get("failed"):
            state = f"failed({e.get('attempts', 0)})"
        elif fire_at == "-":
            state = "pending(history)"
        else:
            dt = _parse_time(fire_at)
            state = "due" if (dt and dt <= now) else "scheduled"
        print(f"{e['link']:<56} {e.get('platform', ''):<8} {fire_at:<26} {state}")


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
            print("usage: alarm.py mark <link> --fired|--failed", file=sys.stderr)
            sys.exit(1)
        cmd_mark(args[1], args[2].lstrip("-"))
    elif cmd == "list":
        cmd_list()
    else:
        print(f"unknown command: {cmd}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()
