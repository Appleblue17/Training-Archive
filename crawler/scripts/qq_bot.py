#!/usr/bin/env python3
"""QQ 群机器人：接收群消息（@机器人触发），按指令回复。

架构：
  - 轮询 NapCat 的 get_group_msg_history 拉取群消息（方案 A，不改 NapCat 配置）
  - 增量追踪：按消息 time（Unix 秒）去重，last_time 持久化到
    crawler/bot-state.json（注意：NapCat 的 message_seq / message_id 并非
    全局递增，不能用作增量游标，必须用 time）
  - 必须 @机器人 才响应（检测消息段的 at，qq == 机器人 UID）
  - 指令注册表：装饰器 @command 注册，支持 /指令 前缀 + 自然语言关键词
  - 回复自动限长分条，避免刷屏

指令：
  /status    daemon 运行状态（scheduled / 最近运行 / 闹钟概览，不含 archived）
  /upcoming  即将开始的比赛（未来闹钟按时间排序）
  /alarms    闹钟概览（不含 archived，含 due / scheduled / failed）
  /contests  已归档比赛（含复盘状态 ✓/✗）
  /review    复盘查询（无参数 = 最近有复盘的比赛；带关键词 = 搜索摘要）
  /fortune   今日运势（按人+日期确定性选择 + 今日比赛提醒）
  /subs      列出订阅
  /subs add <link> [end=时间] [start=时间] [备注]   新增订阅（platform 自动推断，写入 qqbot.json）
  /subs del <link>                          删除订阅（从所有订阅文件移除）
  /sync      触发一次完整同步（daemon.py sync，后台执行）
  /help      指令列表

/subs add 的时间参数：
  end=   比赛结束时间（ISO 8601 北京时间，如 2026-08-15T23:00:00+08:00）
  start= 比赛开始时间（可选，用于赛前提醒；不填回退 end-5h）
  键值顺序任意；其余文字自动作为备注；时间格式错误会终止并提示。
  只有一个时间参数时可省略 end= 前缀（如 /subs add <link> 2026-08-15T23:00:00+08:00）。

自然语言示例（需 @机器人）：
  @机器人 状态          → /status
  @机器人 最近有什么比赛 → /upcoming
  @机器人 今日运势      → /fortune

用法：
    python3 crawler/scripts/qq_bot.py run      # 常驻轮询
    python3 crawler/scripts/qq_bot.py once     # 拉一次消息并处理（调试用）
"""
import hashlib
import json
import os
import re
import subprocess
import sys
import threading
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

from crawler.platforms.base import beijing, load_subscriptions_dir

# 仓库根 / 配置路径
REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
CONFIG_PATH = os.path.join(REPO_ROOT, "crawler", "config.json")
ENV_PATH = os.path.join(REPO_ROOT, ".env")
CONTESTS_ROOT = os.path.join(REPO_ROOT, "contests")
ALARMS_PATH = os.path.join(REPO_ROOT, "crawler", "alarms.json")
BOT_STATE_PATH = os.path.join(REPO_ROOT, "crawler", "bot-state.json")
QQ_BOT_LOG = os.path.join(REPO_ROOT, "crawler", "qq-bot.log")
SUBSCRIPTIONS_DIR = os.path.join(REPO_ROOT, "crawler", "subscriptions")
# bot 管理的订阅写入文件（crawler/subscriptions/*.json 之一，按约定合并加载）
BOT_SUBS_FILE = os.path.join(SUBSCRIPTIONS_DIR, "qqbot.json")
# 生产分支：管理命令（改订阅 / 触发 sync）只在 deploy 分支工作区生效
PROD_BRANCH = "deploy"

# /subs add 的时间格式提示（用法说明 / 错误消息共用）
TIME_FMT_HINT = "ISO 8601 北京时间，如 2026-08-15T23:00:00+08:00"

# 消息发送频率控制（复用 qq_share 的间隔，避免风控）
MIN_SEND_INTERVAL = 1.5

# 轮询间隔（秒）
POLL_INTERVAL = 3.0

# 单条 QQ 消息内容上限（字符；超出按段落分条）
MAX_MSG_CHARS = 1200

# 列表类指令的最大条目数（避免刷屏）
MAX_LIST_ITEMS = 5

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


def _alarm_display_name(link, entry=None):
    """从闹钟条目显示比赛名：comments 优先；否则去 contests/ 匹配 contest.json。"""
    if entry and entry.get("comments"):
        return str(entry["comments"])
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
# 订阅管理 / 确定性随机 / 后台 sync 辅助
# ---------------------------------------------------------------------------
def _load_all_subscriptions():
    """加载全部订阅（含 enabled:false，按 link 去重；与 alarm.py plan 一致）。"""
    try:
        return load_subscriptions_dir(SUBSCRIPTIONS_DIR) or []
    except Exception:
        return []


def _infer_platform(link):
    """从链接推断平台。返回 qoj/hdu/nowcoder 或 None。"""
    link = (link or "").lower()
    if "qoj.ac" in link:
        return "qoj"
    if "hdu.edu.cn" in link:
        return "hdu"
    if "nowcoder.com" in link:
        return "nowcoder"
    return None


def _current_branch():
    """当前 git 分支名（异常返回空串）。"""
    try:
        r = subprocess.run(
            ["git", "-C", REPO_ROOT, "rev-parse", "--abbrev-ref", "HEAD"],
            capture_output=True, text=True,
        )
        return (r.stdout or "").strip()
    except Exception:
        return ""


def _fortune_salt():
    """确定性 salt：config.json qq.fortune_salt 可配；缺省固定值。"""
    cfg = _load_config()
    qq = cfg.get("qq", {}) or {}
    salt = (qq.get("fortune_salt") or "").strip()
    return salt or "training-archive"


def _deterministic_seed(scope, user_id):
    """按 scope + user_id + 北京日期 + salt 生成确定性种子（同一天同一人固定）。"""
    today = datetime.now(beijing).date().isoformat()
    key = f"{scope}:{user_id or 'anonymous'}:{today}:{_fortune_salt()}"
    return int(hashlib.md5(key.encode("utf-8")).hexdigest()[:8], 16)


def _truncate(s, n=28):
    """截断到 n 字符，超出加省略号。"""
    s = (s or "").strip()
    return s if len(s) <= n else s[: n - 1] + "…"


def _sync_failure_summary(lines, text):
    """失败场景摘要：优先提取中止原因，不再转发原始日志行。"""
    m = re.search(
        r"\[alarm\] ERROR: subscription (\S+) has invalid (end_time|start_time) '([^']*)'",
        text,
    )
    if m:
        link, field, val = m.group(1), m.group(2), m.group(3)
        field_cn = "结束时间" if field == "end_time" else "开始时间"
        return "\n".join([
            "⚠️ 同步中止：订阅时间格式错误",
            f"· {_truncate(link)} 的{field_cn} {val!r} 无效",
            "· 该订阅已跳过；请修正后重试（/subs del 删除后重新 /subs add）",
        ])
    if "subscription file(s) with format problems" in text:
        return "\n".join([
            "⚠️ 同步中止：订阅文件格式有问题",
            "· 部分订阅被跳过（详见服务器 daemon 日志）",
            "· 请修正订阅文件后重试",
        ])
    if "Sync crawl failed" in text:
        return "\n".join([
            "⚠️ 同步失败：爬取出错",
            "· 相关比赛已标记 failed，下次 sync 自动重试",
        ])
    if "review generation failed" in text:
        return "\n".join([
            "⚠️ 同步中止：复盘生成失败",
            "· 未归档，下次 sync 将重试",
        ])
    # 兜底：返回退出码 + 最后几行
    head = next((l for l in lines if l.startswith("[ERROR]") or "aborting sync" in l), None)
    tail = "\n".join(lines[-3:] or ["(无输出)"])
    return "⚠️ 同步失败\n" + (f"· {head}\n" if head else "") + tail


def _sync_ok_summary(lines, text):
    """成功场景摘要：待处理分类 / 爬取结果 / 复盘分享 / 推送状态。"""
    parts = ["✅ 同步完成"]

    # 待处理（alarm.py plan 分类）
    m = re.search(
        r"\[alarm\] plan:\s*(\d+)\s*history,\s*(\d+)\s*expired,\s*(\d+)\s*retry,\s*(\d+)\s*alarms",
        text,
    )
    if m:
        n_hist, n_exp, n_retry, n_alarms = map(int, m.groups())
        total = n_hist + n_exp + n_retry
        if total == 0:
            parts.append(f"· 没有待处理的比赛（闹钟 {n_alarms} 条）")
        else:
            label = []
            if n_hist:
                label.append(f"{n_hist} 历史")
            if n_exp:
                label.append(f"{n_exp} 过期")
            if n_retry:
                label.append(f"{n_retry} 重试")
            parts.append("· 待处理：" + " / ".join(label))

    # 爬取结果（daemon 的 Crawling 行 + 爬虫输出分类）
    crawl = next((l for l in lines if "Crawling:" in l), None)
    if crawl:
        n_links = len([x for x in crawl.split("Crawling:", 1)[1].split(",") if x.strip()])
        finished = len(re.findall(r"Finished fetching contest:", text))
        already = len(re.findall(r"Contest folder already exists", text)) + len(
            re.findall(r"not new in this run", text)
        )
        not_started = re.findall(r"Contest (.+?) has not started yet", text)
        detail = []
        if finished:
            detail.append(f"{finished} 场新建")
        if already:
            detail.append(f"{already} 场已存在")
        for name in not_started[:2]:
            detail.append(f"1 场未开始（{_truncate(name)}）")
        if len(not_started) > 2:
            detail.append(f"等 {len(not_started)} 场未开始")
        parts.append(
            "· 爬取 " + str(n_links) + " 场"
            + ("：" + "，".join(detail) if detail else "（无结果）")
        )

    # 复盘 / 分享
    m = re.search(r"\[report\] Generated (\d+) review\(s\).*?\((\d+) failed\)", text)
    if m:
        line = f"· 复盘 {m.group(1)} 篇"
        if int(m.group(2)):
            line += f"（{m.group(2)} 篇失败）"
        parts.append(line)
    m = re.search(r"\[qq-share\] Sent (\d+) share\(s\)", text)
    if m:
        parts.append(f"· 分享 {m.group(1)} 条")

    # 推送状态
    if "Pushed to deploy." in text:
        parts.append("· 已推送 deploy")
    elif "No contest data changes" in text:
        parts.append("· 无数据变更，未推送")

    return "\n".join(parts)


def _sync_summary(returncode, out):
    """把 daemon.py sync 输出压缩成易读摘要（替代原始 log 尾部转发）。

    解析 plan 分类、爬取结果（新建/已存在/未开始/失败）、复盘与分享数、
    推送状态；失败时给出中止原因。不再把原始日志行发到群里。
    """
    lines = [ln for ln in out.splitlines() if ln.strip()]
    text = "\n".join(lines)
    if returncode != 0:
        return _sync_failure_summary(lines, text)
    return _sync_ok_summary(lines, text)


def _run_sync_and_report():
    """后台执行 daemon.py sync，完成后向群发送结果摘要（独立 WS 连接）。"""
    try:
        proc = subprocess.run(
            [sys.executable, os.path.join(SCRIPT_DIR, "daemon.py"), "sync"],
            capture_output=True, text=True,
        )
        summary = _sync_summary(proc.returncode, (proc.stdout or "") + (proc.stderr or ""))
    except Exception as e:
        summary = f"sync 执行异常：{e}"
    qq = load_qq_config()
    ws_url = qq.get("napcat_ws_url", "")
    group_id = qq.get("group_id", 0)
    if not ws_url or not group_id:
        print(f"[qq-bot] sync 完成但无法发送结果（NapCat 未配置）: {summary}")
        return
    client = NapCatClient(ws_url, qq.get("napcat_token", ""))
    try:
        client._connect()
    except Exception as e:
        print(f"[qq-bot] 发送 sync 结果失败: {e}")
        return
    try:
        client.send_text(group_id, summary)
    finally:
        client._close()


def _subs_list():
    """列出全部订阅。"""
    subs = _load_all_subscriptions()
    if not subs:
        return "暂无订阅。"
    lines = [f"【订阅列表】共 {len(subs)} 条"]
    for s in subs:
        flag = "✓" if s.get("enabled", True) else "✗"
        plat = s.get("platform", "?")
        link = s.get("link", "")
        line = f"· {flag} [{plat}] {link}"
        if s.get("start_time"):
            line += f"  start={s['start_time']}"
        if s.get("end_time"):
            line += f"  end={s['end_time']}"
        if s.get("comments"):
            line += f"  ({s['comments']})"
        lines.append(line)
    return "\n".join(lines)


def _subs_add_usage():
    """/subs add 用法说明（含时间格式）。"""
    return "\n".join([
        "用法：/subs add <link> [end=结束时间] [start=开始时间] [备注]",
        "时间格式：" + TIME_FMT_HINT,
        "（只有一个时间参数时可省略 end=，如 /subs add <link> 2026-08-15T23:00:00+08:00）",
    ])


def _subs_add(parts):
    """新增订阅：end=/start= 键值（顺序任意）+ 其余拼为备注；写入 qqbot.json 后后台 sync。

    恰好一个裸 token（无 end=/start= 前缀）且能解析为时间 → 自动作为
    end_time（省去 end= 前缀）；多个裸 token 不识别（避免把备注误判为时间）。
    时间格式错误：终止（不写入）并提示，格式见 TIME_FMT_HINT。
    """
    if not parts:
        return _subs_add_usage()
    link = parts[0].strip()
    if not re.match(r"^https?://", link):
        return "link 需以 http:// 或 https:// 开头。"
    # 解析键值参数（end=/start=）与备注（其余 token 拼合）
    end_time = start_time = None
    comments = []
    for tok in parts[1:]:
        t = tok.strip()
        if not t:
            continue
        low = t.lower()
        if low.startswith("end="):
            v = t[len("end="):].strip()
            if _parse_time(v) is None:
                return f"end 时间格式错误：{v!r}（应为 {TIME_FMT_HINT}）"
            end_time = v
        elif low.startswith("start="):
            v = t[len("start="):].strip()
            if _parse_time(v) is None:
                return f"start 时间格式错误：{v!r}（应为 {TIME_FMT_HINT}）"
            start_time = v
        else:
            comments.append(t)
    # 裸时间 token 自动识别：恰好一个裸 token 且能解析为时间 → 作为 end_time
    if not end_time and len(comments) == 1:
        v = comments[0]
        if _parse_time(v) is not None:
            end_time = v
            comments = []
    for s in _load_all_subscriptions():
        if str(s.get("link", "")).rstrip("/") == link.rstrip("/"):
            return f"已存在该订阅：{link}"
    platform = _infer_platform(link)
    if not platform:
        return "无法推断平台（支持 qoj.ac / hdu.edu.cn / nowcoder.com），请检查链接。"
    entry = {"platform": platform, "link": link, "enabled": True}
    if end_time:
        entry["end_time"] = end_time
    if start_time:
        entry["start_time"] = start_time
    if comments:
        entry["comments"] = " ".join(comments)
    os.makedirs(SUBSCRIPTIONS_DIR, exist_ok=True)
    items = _load_json(BOT_SUBS_FILE, []) or []
    if not isinstance(items, list):
        items = []
    items.append(entry)
    with open(BOT_SUBS_FILE, "w", encoding="utf-8") as f:
        json.dump(items, f, ensure_ascii=False, indent=2)
        f.write("\n")
    threading.Thread(target=_run_sync_and_report, daemon=True).start()
    msg = f"已添加订阅 [{platform}] {link}"
    if entry.get("end_time"):
        msg += f"  end={entry['end_time']}"
    if entry.get("start_time"):
        msg += f"  start={entry['start_time']}"
    if entry.get("comments"):
        msg += f"  ({entry['comments']})"
    return msg + "\n开始同步（完成后回复结果）。"


def _subs_del(link):
    """删除订阅：从所有订阅文件移除该 link 条目，随后后台触发 sync。"""
    if not link:
        return "用法：/subs del <link>"
    link = link.strip()
    removed = 0
    if not os.path.isdir(SUBSCRIPTIONS_DIR):
        return f"未找到订阅：{link}"
    for fname in sorted(os.listdir(SUBSCRIPTIONS_DIR)):
        if not fname.endswith(".json") or fname.endswith(".example.json"):
            continue
        path = os.path.join(SUBSCRIPTIONS_DIR, fname)
        items = _load_json(path, []) or []
        if not isinstance(items, list):
            continue
        new_items = [s for s in items
                     if str(s.get("link", "")).rstrip("/") != link.rstrip("/")]
        if len(new_items) == len(items):
            continue
        with open(path, "w", encoding="utf-8") as f:
            json.dump(new_items, f, ensure_ascii=False, indent=2)
            f.write("\n")
        removed += len(items) - len(new_items)
    if not removed:
        return f"未找到订阅：{link}"
    threading.Thread(target=_run_sync_and_report, daemon=True).start()
    return f"已删除订阅 {link}（{removed} 条）。开始同步（完成后回复结果）。"


# ---------------------------------------------------------------------------
# 指令实现
# ---------------------------------------------------------------------------
@command("help", "h", keywords=("帮助", "菜单", "指令"))
def cmd_help(args, ctx):
    lines = [
        "指令列表",
        "/status 运行状态",
        "/upcoming 即将开始的比赛",
        "/alarms 闹钟概览",
        "/contests 最近比赛 + 复盘状态",
        "/review 复盘查询（/review 关键词）",
        "/fortune 今日运势",
        "/subs 订阅列表",
        "/subs add <link> [end=时间] [start=时间] [备注]",
        "/subs del <link>",
        "/sync 触发同步",
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
    """即将开始的比赛：未来闹钟按开始时间排序（无 start_time 用 fire_at）。"""
    alarms = _load_alarms()
    now = datetime.now(beijing)
    upcoming = []
    for e in alarms.values():
        if e.get("status") != "planned":
            continue
        dt = _parse_time(e.get("start_time")) or _parse_time(e.get("fire_at"))
        if dt and dt > now:
            upcoming.append((dt, e))
    upcoming.sort(key=lambda x: x[0])
    if not upcoming:
        return "最近没有已安排的未来比赛。"
    lines = ["【即将开始的比赛】"]
    for dt, e in upcoming[:MAX_LIST_ITEMS]:
        name = _alarm_display_name(e.get("link", ""), e)
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
    """已归档比赛（近 5 场）+ 复盘状态。"""
    if not os.path.isdir(CONTESTS_ROOT):
        return "暂无比赛数据。"
    folders = [f for f in sorted(os.listdir(CONTESTS_ROOT))
               if os.path.isdir(os.path.join(CONTESTS_ROOT, f))]
    if not folders:
        return "暂无已归档比赛。"
    lines = ["【最近比赛】"]
    for name in folders[-MAX_LIST_ITEMS:][::-1]:
        folder = os.path.join(CONTESTS_ROOT, name)
        has_review = os.path.isfile(os.path.join(folder, "review.md"))
        mark = "✓ 已复盘" if has_review else "✗ 未复盘"
        lines.append(f"· {_short_contest_name(folder)}  {mark}")
    return "\n".join(lines)


@command("review", "rv", keywords=("复盘", "复盘报告", "报告", "review"))
def cmd_review(args, ctx):
    """复盘查询：无参数 = 最近有复盘的比赛；带关键词 = 搜索并返回摘要。"""
    if not os.path.isdir(CONTESTS_ROOT):
        return "暂无比赛数据。"
    keyword = args.strip()
    entries = []
    for name in sorted(os.listdir(CONTESTS_ROOT)):
        folder = os.path.join(CONTESTS_ROOT, name)
        if not os.path.isdir(folder):
            continue
        review_path = os.path.join(folder, "review.md")
        if not os.path.isfile(review_path):
            continue
        if keyword and keyword.lower() not in name.lower():
            continue
        try:
            with open(review_path, "r", encoding="utf-8") as f:
                text = f.read()
        except OSError:
            text = ""
        entries.append((name, text))
    if not entries:
        if keyword:
            return f"没有找到包含「{keyword}」的复盘。"
        return "暂无复盘报告。"
    entries.sort(key=lambda x: x[0])
    if keyword:
        lines = [f"【复盘】「{keyword}」匹配 {len(entries)} 场"]
        for name, text in entries[:MAX_LIST_ITEMS]:
            title = _short_contest_name(name)
            snippet = "\n".join(l for l in text.splitlines() if l.strip())[:400]
            lines.append(f"\n· {title}\n{snippet}")
        if len(entries) > MAX_LIST_ITEMS:
            lines.append(f"... 共 {len(entries)} 场，可用更具体的关键词。")
    else:
        lines = ["【最近复盘】"]
        for name, text in entries[-MAX_LIST_ITEMS:][::-1]:
            lines.append(f"· {_short_contest_name(name)}")
        lines.append("可用 /review <关键词> 查看摘要。")
    return "\n".join(lines)


@command("fortune", "f", keywords=("运势", "今日运势", "运气"))
def cmd_fortune(args, ctx):
    """今日运势：按 user+日期 确定性选择（同一天同一人固定，跨天变化）+ 今日/明日比赛提醒。"""
    fortunes = [
        ("大吉", "今天 AC 手感爆棚，难题也能一遍过！"),
        ("吉", "适合写题，注意边界条件别翻车~"),
        ("中吉", "稳扎稳打能出成绩，别急着提交。"),
        ("小吉", "今天的 WA 都是明天的经验，加油！"),
        ("凶", "建议先看题面再动手，避免低级失误。"),
        ("大凶", "今天就别硬磕难题了，补补题放松下~"),
    ]
    seed = _deterministic_seed("fortune", ctx.get("user_id"))
    rank, advice = fortunes[seed % len(fortunes)]
    lucky = seed % 100
    lines = [f"今日运势：{rank}（幸运数字 {lucky}）"]
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
            lines.append(f"· {_format_dt(dt, now)}  {_alarm_display_name(e.get('link', ''), e)}")
    return "\n".join(lines)


@command("subs", keywords=("订阅", "订阅列表"))
def cmd_subs(args, ctx):
    """订阅管理：无参数列出；add 新增；del 删除（改订阅会后台触发 sync）。"""
    # 全部按空白切分：add 的 end=/start=/备注 在 _subs_add 内逐个解析
    parts = args.split()
    op = parts[0].lower() if parts else ""
    if op == "add":
        if _current_branch() != PROD_BRANCH:
            return f"订阅管理仅在 {PROD_BRANCH} 分支可用（当前分支 {_current_branch()}）。"
        return _subs_add(parts[1:] if len(parts) > 1 else [])
    if op == "del":
        if _current_branch() != PROD_BRANCH:
            return f"订阅管理仅在 {PROD_BRANCH} 分支可用（当前分支 {_current_branch()}）。"
        return _subs_del(parts[1] if len(parts) > 1 else "")
    return _subs_list()


@command("sync", keywords=("同步", "同步一次", "运行同步"))
def cmd_sync(args, ctx):
    """触发一次完整同步（daemon.py sync，后台执行；完成后群里回复结果）。"""
    if _current_branch() != PROD_BRANCH:
        return f"同步仅在 {PROD_BRANCH} 分支可用（当前分支 {_current_branch()}）。"
    threading.Thread(target=_run_sync_and_report, daemon=True).start()
    return "收到，开始同步（爬取 → 报告 → 推送，约几分钟），完成后回复结果。"


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

    bot_uid 已配置：仅响应 @ 自己的消息；被 @ 但没匹配到指令时给 /help 提示。
    bot_uid 未配置（None/空）：无法识别 @，退化为只响应明确以 / 开头的指令，
    且未匹配指令时静默跳过（不回提示）——避免把群聊普通消息当指令，逐条
    回「/help」刷屏。仍建议配置 .env QQ_BOT_UID 以获得 @ 识别。
    自己发的消息（user_id == bot_uid 或 message_sent_type == self）一律跳过。
    """
    replied = 0
    for msg in messages:
        # 忽略自己发的消息（NapCat 的 self 消息带 message_sent_type/self_id）
        if msg.get("post_type") == "message_sent" or msg.get("message_sent_type") == "self":
            continue
        text, ats = _message_text_and_at(msg)
        if not text:
            continue
        # bot_uid 配置了才要求 @机器人
        if bot_uid and bot_uid not in ats:
            continue
        # bot_uid 未配置：只处理 /指令，普通聊天一律忽略（防刷屏）
        if not bot_uid and not text.startswith("/"):
            continue
        fn, arg = _match_command(text)
        if not fn:
            if not bot_uid:
                # 未配置 bot_uid 时 /xxx 未匹配指令也静默，避免逐条回复刷屏
                continue
            # 被 @ 但没匹配到指令：提示
            client.send_text(group_id, "收到！可用 /help 查看指令。", log=log)
            replied += 1
            continue
        ctx = {
            "group_id": group_id,
            "user_id": str(msg.get("user_id") or ""),
            "client": client,
        }
        try:
            reply = fn(arg, ctx)
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
    if not bot_uid:
        _last_config_warn_ts = _throttled_log(
            _last_config_warn_ts, WARN_CONFIG_INTERVAL, log,
            "QQ_BOT_UID 未配置：无法识别 @，仅响应 /指令（普通消息忽略）；"
            "建议在 .env 配置 QQ_BOT_UID。",
        )

    state = _load_bot_state()
    last_time = state.get("last_time") or 0

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
        # 增量游标用消息 time（Unix 秒）：NapCat 的 message_seq / message_id
        # 并非全局递增（各发送者独立/随机），按 seq 过滤会把新消息永久挡掉。
        # 只基于非自己消息推进游标：bot 自己发的文件/文本（time 往往最新）
        # 不参与推进，避免把用户的增量窗口整体顶掉。
        non_self = [
            m for m in messages
            if not (m.get("post_type") == "message_sent"
                    or m.get("message_sent_type") == "self")
        ]
        new_msgs = [m for m in non_self if (m.get("time") or 0) > last_time]
        new_msgs.sort(key=lambda m: m.get("time") or 0)
        if not new_msgs:
            # 无新消息（含全为自己消息的情况）：不推进 last_time
            return 0
        # 更新 last_time 为这批非自己消息里最大的 time
        max_time = max((m.get("time") or 0) for m in new_msgs)
        replied = _handle_messages(client, group_id, new_msgs, bot_uid, log=log)
        state["last_time"] = max(state.get("last_time") or 0, max_time)
        _save_bot_state(state)
        return replied
    finally:
        client._close()


def process_force(qq_cfg, log=print):
    """调试用：忽略 last_time，处理最近一批所有非自己消息（不写状态文件）。"""
    ws_url = qq_cfg.get("napcat_ws_url", "")
    token = qq_cfg.get("napcat_token", "")
    group_id = qq_cfg.get("group_id", 0)
    bot_uid = qq_cfg.get("bot_uid", "")
    if not ws_url or not group_id or create_connection is None:
        log("配置缺失或 websocket-client 未安装。")
        return 0
    if not bot_uid:
        log("QQ_BOT_UID 未配置：无法识别 @，仅响应 /指令（普通消息忽略）。")
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
        messages.sort(key=lambda m: m.get("time") or 0)
        if not messages:
            log("无消息。")
            return 0
        for m in messages:
            text, ats = _message_text_and_at(m)
            is_self = m.get("post_type") == "message_sent" or m.get("message_sent_type") == "self"
            print(f"  time={m.get('time')} self={is_self} user={m.get('user_id')} "
                  f"at={ats} text={text[:50]!r}")
        replied = _handle_messages(client, group_id, messages, bot_uid, log=log)
        log(f"处理 {len(messages)} 条，回复 {replied} 条（调试模式，不更新 last_time）。")
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
