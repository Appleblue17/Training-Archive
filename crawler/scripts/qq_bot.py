#!/usr/bin/env python3
"""QQ 群机器人：接收群消息（@机器人触发），按指令回复。

架构：
  - 轮询 NapCat 的 get_group_msg_history 拉取群消息（方案 A，不改 NapCat 配置）
  - 增量追踪：按 message_seq 去重，last_seq 持久化到 crawler/bot-state.json
  - 必须 @机器人 才响应（检测消息段的 at，qq == 机器人 UID）
  - 指令注册表：装饰器 @command 注册，支持 /指令 前缀 + 自然语言关键词
  - 回复自动限长分条，避免刷屏

指令（先做基础版）：
  /status    daemon 运行状态（scheduled / 最近运行 / 闹钟概览，不含 archived）
  /upcoming  即将开始的比赛（未来闹钟按时间排序）
  /alarms    闹钟概览（不含 archived，含 due / scheduled / failed）
  /contests  已归档比赛（含复盘状态 ✓/✗）
  /fortune   今日运势（随机趣味 + 今日比赛提醒）
  /help      指令列表

自然语言示例（需 @机器人）：
  @机器人 状态          → /status
  @机器人 最近有什么比赛 → /upcoming
  @机器人 今日运势      → /fortune

用法：
    python3 crawler/scripts/qq_bot.py run      # 常驻轮询
    python3 crawler/scripts/qq_bot.py once     # 拉一次消息并处理（调试用）
"""
import json
import os
import random
import re
import sys
import time
import uuid
from datetime import datetime, timedelta

from dotenv import load_dotenv

load_dotenv()

# 脚本位于 crawler/scripts/，仓库根为 ../../（使 crawler 包可导入）
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..")))

# websocket-client（与 qq_share.py 相同方式）
_WS_IMPORT_ERROR = None
try:
    from websocket import create_connection
except ImportError as e:  # pragma: no cover
    _WS_IMPORT_ERROR = e
    create_connection = None

from crawler.platforms.base import beijing

# 仓库根 / 配置路径
REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
CONFIG_PATH = os.path.join(REPO_ROOT, "crawler", "config.json")
ENV_PATH = os.path.join(REPO_ROOT, ".env")
CONTESTS_ROOT = os.path.join(REPO_ROOT, "contests")
ALARMS_PATH = os.path.join(REPO_ROOT, "crawler", "alarms.json")
BOT_STATE_PATH = os.path.join(REPO_ROOT, "crawler", "bot-state.json")
QQ_BOT_LOG = os.path.join(REPO_ROOT, "crawler", "qq-bot.log")
SUBSCRIPTIONS_DIR = os.path.join(REPO_ROOT, "crawler", "subscriptions")

# 消息发送频率控制（复用 qq_share 的间隔，避免风控）
MIN_SEND_INTERVAL = 1.5

# 轮询间隔（秒）
POLL_INTERVAL = 3.0

# 单条 QQ 消息内容上限（字符；超出按段落分条）
MAX_MSG_CHARS = 1200

# 列表类指令的最大条目数（避免刷屏）
MAX_LIST_ITEMS = 10

# 机器人自己的 UID（config.json qq.bot_uid，缺省从 .env QQ_BOT_UID 读）
# 用于过滤自己发的消息 + 检测 @ 自己

ACTION_GET_GROUP_MSG_HISTORY = "get_group_msg_history"
ACTION_SEND_GROUP_MSG = "send_group_msg"

# 告警日志节流：常驻轮询下"未配置/连接失败"只按间隔报一次，避免刷屏
WARN_CONFIG_INTERVAL = 60.0   # 未配置 NapCat 的告警间隔
WARN_CONN_INTERVAL = 30.0     # 连接失败告警间隔
_last_config_warn_ts = 0.0
_last_conn_warn_ts = 0.0


# ---------------------------------------------------------------------------
# 配置读取（与 qq_share.py 保持一致）
# ---------------------------------------------------------------------------
def _load_config():
    try:
        with open(CONFIG_PATH, "r", encoding="utf-8") as f:
            cfg = json.load(f)
        return cfg if isinstance(cfg, dict) else {}
    except Exception:
        return {}


def _load_env():
    try:
        from dotenv import dotenv_values
        return dotenv_values(ENV_PATH)
    except Exception:
        return {}


def load_qq_config():
    """qq 配置 = config.json qq 块 + .env 敏感项。"""
    cfg = _load_config()
    qq = cfg.get("qq", {})
    if not isinstance(qq, dict):
        qq = {}
    env = _load_env()
    if env.get("QQ_NAPCAT_TOKEN"):
        qq["napcat_token"] = env["QQ_NAPCAT_TOKEN"]
    if env.get("QQ_GROUP_ID"):
        try:
            qq["group_id"] = int(env["QQ_GROUP_ID"])
        except (TypeError, ValueError):
            pass
    if env.get("QQ_BOT_UID"):
        qq["bot_uid"] = str(env["QQ_BOT_UID"])
    return qq


# ---------------------------------------------------------------------------
# NapCat 连接（复用 qq_share 的调用模式）
# ---------------------------------------------------------------------------
class NapCatClient:
    """NapCat 正向 WS 客户端：支持调用 action（含拉取历史消息）。"""

    def __init__(self, ws_url, token=""):
        self.ws_url = ws_url
        self.token = token
        self._ws = None
        self._last_send_ts = 0.0

    def _connect(self):
        header = []
        if self.token:
            header = ["Authorization: Bearer " + self.token]
        self._ws = create_connection(self.ws_url, header=header, timeout=10)

    def _close(self):
        if self._ws is not None:
            try:
                self._ws.close()
            except Exception:
                pass
            self._ws = None

    def _throttle(self):
        elapsed = time.time() - self._last_send_ts
        if elapsed < MIN_SEND_INTERVAL:
            time.sleep(MIN_SEND_INTERVAL - elapsed)

    def call(self, action, params, timeout=15):
        """发送 action，返回响应 dict；失败返回 None。跳过事件帧。"""
        if self._ws is None:
            return None
        self._throttle()
        eid = uuid.uuid4().hex[:8]
        payload = json.dumps(
            {"action": action, "params": params, "echo": eid}, ensure_ascii=False
        )
        try:
            self._ws.send(payload)
            self._last_send_ts = time.time()
            self._ws.settimeout(timeout)
            while True:
                msg = json.loads(self._ws.recv())
                if not isinstance(msg, dict):
                    continue
                if msg.get("echo") == eid:
                    return msg
        except Exception as e:
            print(f"[qq-bot] {action} 失败: {e}")
            return None

    def send_text(self, group_id, text, log=print):
        """发送纯文本到群。自动按段落分条 + 限长。返回成功发送条数。"""
        # 分条：先按空行分段，再把超长段按 MAX_MSG_CHARS 切
        paragraphs = []
        for p in text.split("\n\n"):
            p = p.strip()
            if not p:
                continue
            while len(p) > MAX_MSG_CHARS:
                paragraphs.append(p[:MAX_MSG_CHARS])
                p = p[MAX_MSG_CHARS:]
            paragraphs.append(p)
        if not paragraphs:
            return 0
        sent = 0
        for para in paragraphs:
            resp = self.call(
                ACTION_SEND_GROUP_MSG,
                {"group_id": group_id, "message": para},
            )
            if resp is None:
                log("send_group_msg 失败（无响应）。")
                break
            if resp.get("status") in ("ok", "async"):
                sent += 1
            else:
                log(f"send_group_msg 返回错误: {resp.get('msg', 'unknown')}")
                break
        return sent


# ---------------------------------------------------------------------------
# 指令注册表
# ---------------------------------------------------------------------------
COMMANDS = {}


def command(name, *aliases, keywords=()):
    """注册指令。name 为 /name 前缀；aliases 为其他 /别名；keywords 为自然语言关键词。

    用法：
        @command("status", "st", keywords=("状态", "运行状态"))
        def cmd_status(args, ctx):
            return "回复文本"
    """
    def decorator(fn):
        for key in (name, *aliases):
            COMMANDS["/" + key] = fn
        COMMANDS["__kw__" + name] = (keywords, fn)
        return fn
    return decorator


# ---------------------------------------------------------------------------
# 数据读取（alarms / contests / daemon 状态）
# ---------------------------------------------------------------------------
def _load_json(path, default=None):
    try:
        with open(path, "r", encoding="utf-8") as f:
            return json.load(f)
    except Exception:
        return default


def _load_alarms():
    """读取闹钟表 {link: entry}。"""
    entries = _load_json(ALARMS_PATH, []) or []
    return {e.get("link", ""): e for e in entries if e.get("link")}


def _parse_time(s):
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


def _format_dt(dt, now=None):
    """格式化为人类可读：今天/明天/后天 + 时间。"""
    if dt is None:
        return "?"
    now = now or datetime.now(beijing)
    day = (dt.date() - now.date()).days
    hm = dt.strftime("%H:%M")
    if day == 0:
        return f"今天 {hm}"
    if day == 1:
        return f"明天 {hm}"
    if day == 2:
        return f"后天 {hm}"
    return dt.strftime("%m-%d %H:%M")


def _short_contest_name(contest_folder):
    """从比赛文件夹名提取简称（去日期前缀）。"""
    name = os.path.basename(contest_folder)
    # "2026-08-06 2026钉耙..." → 去掉开头日期
    m = re.match(r"^\d{4}-\d{2}-\d{2}\s+(.+)$", name)
    return m.group(1) if m else name


def _alarm_display_name(link):
    """从 link 找比赛名（contests/ 下匹配 contest.json 的 link）。"""
    if os.path.isdir(CONTESTS_ROOT):
        for name in sorted(os.listdir(CONTESTS_ROOT)):
            folder = os.path.join(CONTESTS_ROOT, name)
            if not os.path.isdir(folder):
                continue
            contest = _load_json(os.path.join(folder, "contest.json"), {})
            if str((contest or {}).get("link") or "").rstrip("/") == link.rstrip("/"):
                return _short_contest_name(folder)
    return link


# ---------------------------------------------------------------------------
# 指令实现
# ---------------------------------------------------------------------------
@command("help", "h", keywords=("帮助", "菜单", "指令"))
def cmd_help(args, ctx):
    lines = [
        "可用指令（需 @我）：",
        "/status 运行状态（不含已归档）",
        "/upcoming 即将开始的比赛",
        "/alarms 闹钟概览",
        "/contests 已归档比赛 + 复盘状态",
        "/fortune 今日运势",
        "/help 本菜单",
    ]
    return "\n".join(lines)


@command("status", "st", keywords=("状态", "运行状态", "daemon"))
def cmd_status(args, ctx):
    """daemon 状态：scheduled / 最近运行 / 闹钟概览（不含 archived）。"""
    cfg = _load_config()
    scheduled = cfg.get("scheduled", {})
    lines = ["【运行状态】"]
    # scheduled
    sched_parts = []
    for k in ("sync", "fire", "incremental"):
        if k in scheduled:
            sched_parts.append(f"{k}:{scheduled[k]}")
    if sched_parts:
        lines.append("计划: " + "  ".join(sched_parts))
    # 最近运行（读 daemon-state.json 的 last_run）
    state = _load_json(os.path.join(REPO_ROOT, "crawler", "daemon-state.json"), {})
    last_run = state.get("last_run") or {}
    now = datetime.now(beijing)
    run_parts = []
    for k in ("sync", "fire", "incremental"):
        ts = last_run.get(k)
        if ts:
            dt = _parse_time(ts)
            if dt:
                run_parts.append(f"{k}:{_format_dt(dt, now)}")
    if run_parts:
        lines.append("最近: " + "  ".join(run_parts))
    else:
        lines.append("最近: (尚未运行)")
    # 闹钟概览（不含 archived）
    alarms = _load_alarms()
    active = [e for e in alarms.values() if e.get("status") != "archived"]
    lines.append(f"闹钟: {len(active)} 条进行中")
    return "\n".join(lines)


@command("upcoming", "u", keywords=("最近比赛", "即将", "接下来", "有什么比赛", "比赛"))
def cmd_upcoming(args, ctx):
    """即将开始的比赛：未来闹钟按时间排序。"""
    alarms = _load_alarms()
    now = datetime.now(beijing)
    upcoming = []
    for e in alarms.values():
        if e.get("status") != "planned":
            continue
        fire_at = e.get("fire_at")
        dt = _parse_time(fire_at)
        if dt and dt > now:
            upcoming.append((dt, e))
    upcoming.sort(key=lambda x: x[0])
    if not upcoming:
        return "最近没有已安排的未来比赛。"
    lines = ["【即将开始的比赛】"]
    for dt, e in upcoming[:MAX_LIST_ITEMS]:
        name = _alarm_display_name(e.get("link", ""))
        lines.append(f"· {_format_dt(dt, now)}  {name}")
    if len(upcoming) > MAX_LIST_ITEMS:
        lines.append(f"... 共 {len(upcoming)} 场")
    return "\n".join(lines)


@command("alarms", "a", keywords=("闹钟", "预定", "预订"))
def cmd_alarms(args, ctx):
    """闹钟概览（不含 archived）：due/scheduled/failed。"""
    alarms = _load_alarms()
    now = datetime.now(beijing)
    active = [e for e in alarms.values() if e.get("status") != "archived"]
    if not active:
        return "没有进行中的闹钟。"
    lines = ["【闹钟概览】"]
    for e in sorted(active, key=lambda x: x.get("fire_at") or ""):
        link = e.get("link", "")
        name = _alarm_display_name(link)
        status = e.get("status", "?")
        if status == "planned":
            dt = _parse_time(e.get("fire_at"))
            state = "已到点" if (dt and dt <= now) else "等待中"
        elif status == "pending":
            state = "待同步"
        elif status == "failed":
            state = f"失败(尝试{e.get('attempts', 0)})"
        else:
            state = status
        fire = _format_dt(_parse_time(e.get("fire_at")), now) if e.get("fire_at") else "-"
        lines.append(f"· [{state}] {fire}  {name}")
        if len(lines) > MAX_LIST_ITEMS + 1:
            lines.append(f"... 共 {len(active)} 条")
            break
    return "\n".join(lines)


@command("contests", "c", keywords=("归档", "已归档", "比赛列表", "历史比赛"))
def cmd_contests(args, ctx):
    """已归档比赛（近 10 场）+ 复盘状态。"""
    if not os.path.isdir(CONTESTS_ROOT):
        return "暂无比赛数据。"
    folders = [f for f in sorted(os.listdir(CONTESTS_ROOT))
               if os.path.isdir(os.path.join(CONTESTS_ROOT, f))]
    if not folders:
        return "暂无已归档比赛。"
    lines = ["【最近比赛 + 复盘状态】"]
    for name in folders[-MAX_LIST_ITEMS:][::-1]:
        folder = os.path.join(CONTESTS_ROOT, name)
        has_review = os.path.isfile(os.path.join(folder, "review.md"))
        mark = "✓ 已复盘" if has_review else "✗ 未复盘"
        lines.append(f"· {_short_contest_name(folder)}  {mark}")
    return "\n".join(lines)


@command("fortune", "f", keywords=("运势", "今日运势", "运气"))
def cmd_fortune(args, ctx):
    """今日运势：随机趣味签 + 今日/明日比赛提醒。"""
    fortunes = [
        ("大吉", "今天 AC 手感爆棚，难题也能一遍过！"),
        ("吉", "适合写题，注意边界条件别翻车~"),
        ("中吉", "稳扎稳打能出成绩，别急着提交。"),
        ("小吉", "今天的 WA 都是明天的经验，加油！"),
        ("凶", "建议先看题面再动手，避免低级失误。"),
        ("大凶", "今天就别硬磕难题了，补补题放松下~"),
    ]
    rank, advice = random.choice(fortunes)
    lines = [f"今日运势：{rank}"]
    lines.append(advice)
    # 今日/明日比赛提醒
    alarms = _load_alarms()
    now = datetime.now(beijing)
    soon = []
    for e in alarms.values():
        if e.get("status") != "planned":
            continue
        dt = _parse_time(e.get("fire_at"))
        if dt and now.date() <= dt.date() <= (now + timedelta(days=1)).date():
            soon.append((dt, e))
    if soon:
        soon.sort(key=lambda x: x[0])
        lines.append("")
        lines.append("近期比赛：")
        for dt, e in soon[:3]:
            lines.append(f"· {_format_dt(dt, now)}  {_alarm_display_name(e.get('link', ''))}")
    return "\n".join(lines)


# ---------------------------------------------------------------------------
# 消息解析与指令分发
# ---------------------------------------------------------------------------
def _message_text_and_at(msg):
    """从 OneBot 消息段数组提取 (纯文本, at 的 qq 列表)。"""
    message = msg.get("message") or []
    if isinstance(message, str):
        # 字符串格式（CQ 码）兜底：提取文本与 at
        text = message
        ats = re.findall(r"\[CQ:at,qq=(\d+)\]", message)
        text = re.sub(r"\[CQ:[^\]]*\]", "", text)
        return text.strip(), ats
    text_parts = []
    ats = []
    for seg in message:
        if not isinstance(seg, dict):
            continue
        if seg.get("type") == "text":
            text_parts.append((seg.get("data") or {}).get("text", ""))
        elif seg.get("type") == "at":
            ats.append(str((seg.get("data") or {}).get("qq", "")))
    return "".join(text_parts).strip(), ats


def _match_command(text):
    """匹配指令：先 /前缀，再自然语言关键词。返回 handler 或 None。"""
    text = text.strip()
    # /指令 [参数]
    if text.startswith("/"):
        parts = text[1:].split(None, 1)
        key = "/" + parts[0].lower()
        arg = parts[1] if len(parts) > 1 else ""
        fn = COMMANDS.get(key)
        if fn:
            return fn, arg
        return None, None
    # 自然语言关键词
    for name, val in COMMANDS.items():
        if not name.startswith("__kw__"):
            continue
        keywords, fn = val
        for kw in keywords:
            if kw in text:
                return fn, text
    return None, None


def _load_bot_state():
    state = _load_json(BOT_STATE_PATH, {})
    return state if isinstance(state, dict) else {}


def _save_bot_state(state):
    with open(BOT_STATE_PATH, "w", encoding="utf-8") as f:
        json.dump(state, f, ensure_ascii=False, indent=2)


def _handle_messages(client, group_id, messages, bot_uid, log=lambda s: None):
    """处理一批群消息：找出 @机器人 的指令并回复。返回回复条数。

    bot_uid 未配置（None/空）时无法识别 @，退化为处理所有非自己发的消息
    （风险：可能响应无关消息；建议配置 .env QQ_BOT_UID）。自己发的消息
    （user_id == bot_uid 或 message_sent_type == self）一律跳过，避免自触发。
    """
    replied = 0
    for msg in messages:
        # 忽略自己发的消息（NapCat 的 self 消息带 message_sent_type/self_id）
        if msg.get("post_type") == "message_sent" or msg.get("message_sent_type") == "self":
            continue
        text, ats = _message_text_and_at(msg)
        if not text:
            continue
        # bot_uid 配置了才要求 @机器人；否则退化为响应所有非自己消息
        if bot_uid and bot_uid not in ats:
            continue
        fn, arg = _match_command(text)
        if not fn:
            # 被 @ 但没匹配到指令：提示
            client.send_text(group_id, "收到！可用 /help 查看指令。", log=log)
            replied += 1
            continue
        try:
            reply = fn(arg, {"group_id": group_id})
        except Exception as e:
            print(f"[qq-bot] 指令处理异常: {e}")
            reply = f"处理出错：{e}"
        if reply:
            client.send_text(group_id, reply, log=log)
            replied += 1
    return replied


def _throttled_log(last_ts, interval, log, msg):
    """节流日志：距上次不足 interval 秒则跳过，返回上次时间戳。"""
    now = time.time()
    if now - last_ts < interval:
        return last_ts
    log(msg)
    return now


def process_once(qq_cfg, log=print):
    """轮询一次：拉取新消息并处理。返回处理条数。"""
    global _last_config_warn_ts, _last_conn_warn_ts
    ws_url = qq_cfg.get("napcat_ws_url", "")
    token = qq_cfg.get("napcat_token", "")
    group_id = qq_cfg.get("group_id", 0)
    bot_uid = qq_cfg.get("bot_uid", "")
    if not ws_url or not group_id:
        _last_config_warn_ts = _throttled_log(
            _last_config_warn_ts, WARN_CONFIG_INTERVAL, log,
            "NapCat 未配置（napcat_ws_url / group_id 缺失）；跳过轮询。",
        )
        return 0
    if create_connection is None:
        log("websocket-client 未安装。")
        return 0

    state = _load_bot_state()
    last_seq = state.get("last_seq") or 0

    client = NapCatClient(ws_url, token)
    try:
        client._connect()
    except Exception as e:
        _last_conn_warn_ts = _throttled_log(
            _last_conn_warn_ts, WARN_CONN_INTERVAL, log,
            f"NapCat 连接失败: {e}",
        )
        return 0
    try:
        resp = client.call(
            ACTION_GET_GROUP_MSG_HISTORY,
            {"group_id": group_id, "count": 100},
            timeout=15,
        )
        if resp is None:
            log("get_group_msg_history 失败。")
            return 0
        data = resp.get("data") or {}
        messages = data.get("messages") or []
        if not messages:
            return 0
        # 按 message_seq 增量过滤
        new_msgs = [m for m in messages if (m.get("message_seq") or 0) > last_seq]
        new_msgs.sort(key=lambda m: m.get("message_seq") or 0)
        if not new_msgs:
            return 0
        # 自己发的消息不参与处理、也不推进 last_seq：否则 bot 自己发的
        # 文件/文本（seq 往往最大）会把用户的增量窗口整体顶掉，用户消息
        # 被永久跳过。只基于非自己消息推进游标。
        non_self = [
            m for m in new_msgs
            if not (m.get("post_type") == "message_sent"
                    or m.get("message_sent_type") == "self")
        ]
        if not non_self:
            # 这批全是自己发的消息：不推进 last_seq，下轮继续拉（仍会跳过）
            return 0
        # 更新 last_seq 为这批非自己消息里最大的
        max_seq = max((m.get("message_seq") or 0) for m in non_self)
        replied = _handle_messages(client, group_id, non_self, bot_uid, log=log)
        state["last_seq"] = max(state.get("last_seq") or 0, max_seq)
        _save_bot_state(state)
        return replied
    finally:
        client._close()


def process_force(qq_cfg, log=print):
    """调试用：忽略 last_seq，处理最近一批所有非自己消息（不写状态文件）。"""
    ws_url = qq_cfg.get("napcat_ws_url", "")
    token = qq_cfg.get("napcat_token", "")
    group_id = qq_cfg.get("group_id", 0)
    bot_uid = qq_cfg.get("bot_uid", "")
    if not ws_url or not group_id or create_connection is None:
        log("配置缺失或 websocket-client 未安装。")
        return 0
    client = NapCatClient(ws_url, token)
    try:
        client._connect()
    except Exception as e:
        log(f"NapCat 连接失败: {e}")
        return 0
    try:
        resp = client.call(
            ACTION_GET_GROUP_MSG_HISTORY,
            {"group_id": group_id, "count": 30},
            timeout=15,
        )
        if resp is None:
            log("get_group_msg_history 失败。")
            return 0
        messages = (resp.get("data") or {}).get("messages") or []
        messages.sort(key=lambda m: m.get("message_seq") or 0)
        if not messages:
            log("无消息。")
            return 0
        for m in messages:
            text, ats = _message_text_and_at(m)
            is_self = m.get("post_type") == "message_sent" or m.get("message_sent_type") == "self"
            print(f"  seq={m.get('message_seq')} self={is_self} user={m.get('user_id')} "
                  f"at={ats} text={text[:50]!r}")
        replied = _handle_messages(client, group_id, messages, bot_uid, log=log)
        log(f"处理 {len(messages)} 条，回复 {replied} 条（调试模式，不更新 last_seq）。")
        return replied
    finally:
        client._close()


def _file_log(msg):
    """带时间戳写入 qq-bot.log 并打印（服务运行时可 tail 查看）。"""
    line = f"[{datetime.now(beijing).strftime('%Y-%m-%d %H:%M:%S')}] {msg}"
    print(line, flush=True)
    try:
        with open(QQ_BOT_LOG, "a", encoding="utf-8") as f:
            f.write(line + "\n")
    except OSError:
        pass


def run_forever(qq_cfg, log=_file_log):
    """常驻轮询循环。"""
    log("=== qq-bot run started ===")
    while True:
        try:
            process_once(qq_cfg, log=log)
        except Exception as e:
            log(f"轮询异常: {e}")
        time.sleep(POLL_INTERVAL)


def main(argv=None):
    args = argv if argv is not None else sys.argv[1:]
    cmd = args[0] if args else "run"
    qq_cfg = load_qq_config()
    if cmd == "once":
        n = process_once(qq_cfg)
        print(f"[qq-bot] processed {n} message(s).")
        return 0
    elif cmd == "force":
        n = process_force(qq_cfg)
        print(f"[qq-bot] force processed {n} message(s).")
        return 0
    elif cmd == "run":
        run_forever(qq_cfg)
        return 0
    else:
        print(__doc__)
        return 1


if __name__ == "__main__":
    sys.exit(main())
