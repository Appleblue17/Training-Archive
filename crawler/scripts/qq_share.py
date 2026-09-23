#!/usr/bin/env python3
"""QQ 群分享（share AI task）：把 review.md 文件发送到 QQ 群。

流程（每场比赛）：
  1. review.md 不存在 → 跳过（share 依赖 report task 生成的完整报告）
  2. 连接 NapCat（OneBot 11 正向 WebSocket）→ 上传 review.md 文件（upload_group_file）
  3. 发送成功后写入已发送标记 contests/<folder>/qq-share.sent（gitignore，不入库）；
     失败不写标记，下次重试

规则：
  - review.md 不存在：跳过（不自行生成报告）
  - 已发送标记存在：跳过（幂等，避免重复群发历史比赛）
  - NapCat 未配置 / 连接失败 / 发送失败：记 log 告警，不阻断 daemon 主流程

与 report 解耦：report.py 不再串联本模块；由 daemon 的 sync/fire 在 report
成功后按 config.json 的 ai_tasks.share.enabled 单独调用。

配置（crawler/config.json，非敏感部分）：
  "ai_tasks": { "share": { "enabled": true } }
  "qq": { "napcat_ws_url": "ws://127.0.0.1:6700" }   # NapCat WebSocket 地址

敏感配置放仓库根 .env（勿提交；.env.example 为模板）：
  QQ_NAPCAT_TOKEN=<NapCat 鉴权 token>
  QQ_GROUP_ID=<目标 QQ 群号>
  # token / group_id 仅从 .env 读取，config.json 的 qq 块只放非敏感项。

用法：
    python3 crawler/scripts/qq_share.py --links "link1,link2"  # 按订阅链接反查比赛（daemon 用）
    python3 crawler/scripts/qq_share.py --from-crawl           # 只对本次爬取新建的比赛
    python3 crawler/scripts/qq_share.py <contest_folder>       # 指定比赛（文件夹相对仓库根）
    python3 crawler/scripts/qq_share.py                        # 补发：扫描所有未发送的比赛

注：文案（qq-share.txt / DeepSeek 简化版）已在 v0.3.3 移除，只发送 review 文件。
"""
import json
import os
import re
import sys
import time
import uuid
from datetime import datetime, timedelta, timezone

from dotenv import load_dotenv

# 本地开发：从仓库根 .env 加载 QQ 凭据（CI 无 .env，静默跳过）
load_dotenv()

# 脚本位于 crawler/scripts/，仓库根为 ../../（使 crawler 包可导入）
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..")))

from crawler.scripts.new_contests import load_new_contests

# websocket-client 库（发送到 NapCat 用）
_WS_IMPORT_ERROR = None
try:
    from websocket import create_connection
except ImportError as e:  # pragma: no cover
    _WS_IMPORT_ERROR = e
    create_connection = None

# 已发送标记：发送成功后写入比赛文件夹（两个 .gitignore 均忽略），用于幂等补发。
SENT_MARKER_NAME = "qq-share.sent"

# 北京时间（与项目其余部分一致）
BEIJING = timezone(timedelta(hours=8))

# 仓库根 / 配置路径
REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
CONFIG_PATH = os.path.join(REPO_ROOT, "crawler", "config.json")
ENV_PATH = os.path.join(REPO_ROOT, ".env")
CONTESTS_ROOT = os.path.join(REPO_ROOT, "contests")

# 消息发送频率控制（每条消息至少间隔此秒数，避免被风控）
MIN_SEND_INTERVAL = 1.5

# OneBot 11 action 名
ACTION_SEND_GROUP_MSG = "send_group_msg"
ACTION_UPLOAD_GROUP_FILE = "upload_group_file"


# ---------------------------------------------------------------------------
# 配置读取
# ---------------------------------------------------------------------------
def _load_config():
    """读取 config.json；缺失/解析失败返回 {}。"""
    try:
        with open(CONFIG_PATH, "r", encoding="utf-8") as f:
            cfg = json.load(f)
        return cfg if isinstance(cfg, dict) else {}
    except Exception:
        return {}


def ai_task_enabled(name):
    """读取 config.json 的 ai_tasks.<name>.enabled；缺省 False（显式启用才开启）。"""
    cfg = _load_config()
    task = cfg.get("ai_tasks", {}).get(name, {})
    if isinstance(task, dict):
        return bool(task.get("enabled", False))
    return bool(task)


def _load_env_qq():
    """从 .env 读取 QQ 敏感配置；.env 缺失/无字段返回 {}。

    字段映射：QQ_NAPCAT_TOKEN → napcat_token，QQ_GROUP_ID → group_id。
    """
    try:
        from dotenv import dotenv_values
        env = dotenv_values(ENV_PATH)
    except Exception:
        env = {}
    out = {}
    if env.get("QQ_NAPCAT_TOKEN"):
        out["napcat_token"] = env["QQ_NAPCAT_TOKEN"]
    if env.get("QQ_GROUP_ID"):
        try:
            out["group_id"] = int(env["QQ_GROUP_ID"])
        except (TypeError, ValueError):
            print(f"[qq-share] .env 的 QQ_GROUP_ID 非数字，已忽略: "
                  f"{env['QQ_GROUP_ID']!r}")
    return out


def _load_qq_config():
    """读取 QQ 配置。

    - config.json 的 qq 块：非敏感项（napcat_ws_url）
    - .env：敏感项 napcat_token（QQ_NAPCAT_TOKEN）与 group_id（QQ_GROUP_ID），
      仅从 .env 读取，不回退 config.json（敏感内容不进仓库）。
    """
    cfg = _load_config()
    qq = cfg.get("qq", {})
    if not isinstance(qq, dict):
        qq = {}
    qq.update(_load_env_qq())
    return qq


# ---------------------------------------------------------------------------
# 文本清洗（适配 QQ 消息格式）
# ---------------------------------------------------------------------------
def clean_for_qq(text):
    """清洗文本以适配 QQ 消息格式。

    1. 转义 `[` 和 `]`（QQ CQ 码标识符，未转义可能导致消息丢失或解析错误）
    2. 移除 Markdown 标记：**加粗**、*斜体*、~~删除线~~、`行内代码`、```代码块```
    3. 保留换行等基本格式
    """
    # 1. 转义 CQ 码标识符（`[` → `&#91;`, `]` → `&#93;`）
    text = text.replace("[", "&#91;").replace("]", "&#93;")

    # 2. 移除代码块 ```...```
    text = re.sub(r"```.*?```", "", text, flags=re.DOTALL)

    # 3. 去掉行内代码的反引号，保留内部文字
    text = re.sub(r"`([^`]+)`", r"\1", text)

    # 4. 移除 Markdown 标记
    text = re.sub(r"\*\*(.+?)\*\*", r"\1", text)   # **加粗**
    text = re.sub(r"\*(.+?)\*", r"\1", text)       # *斜体*
    text = re.sub(r"~~(.+?)~~", r"\1", text)       # ~~删除线~~
    text = re.sub(r"^#+\s+", "", text, flags=re.MULTILINE)  # # 标题

    return text.strip()


# ---------------------------------------------------------------------------
# NapCat 群聊发送器（每次调用建连，发完即关；daemon 低频调用，无需长连接）
# ---------------------------------------------------------------------------
class QQGroupSender:
    """通过 NapCat（OneBot 11 正向 WebSocket）向指定 QQ 群发送消息与文件。"""

    def __init__(self, ws_url, group_id, token=""):
        self.ws_url = ws_url
        self.group_id = group_id
        self.token = token
        self._ws = None
        self._last_send_ts = 0.0

    def _connect(self):
        """建立 WebSocket 连接（带 Bearer token 鉴权）。"""
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
        """发送频率限制：两次 action 之间至少间隔 MIN_SEND_INTERVAL 秒。"""
        elapsed = time.time() - self._last_send_ts
        if elapsed < MIN_SEND_INTERVAL:
            time.sleep(MIN_SEND_INTERVAL - elapsed)

    def _call(self, action, params):
        """发送一个 OneBot action，返回响应 dict；失败返回 None。

        NapCat 正向 WS 会先推送事件帧（如 meta_event，无 echo），因此
        循环 recv 跳过事件帧，直到拿到匹配本次请求 echo 的响应。
        """
        if self._ws is None:
            return None
        self._throttle()
        eid = uuid.uuid4().hex[:8]
        payload = json.dumps(
            {"action": action, "params": params, "echo": eid},
            ensure_ascii=False,
        )
        try:
            self._ws.send(payload)
            self._last_send_ts = time.time()
            while True:
                msg = json.loads(self._ws.recv())
                if not isinstance(msg, dict):
                    continue
                if msg.get("echo") == eid:
                    return msg
                # 事件帧（无 echo 或 echo 不匹配）：跳过，继续等本次响应
        except Exception as e:
            print(f"[qq-share] {action} 失败: {e}")
            return None

    def send_text(self, text):
        """按段落（空行分隔）逐条发送纯文本到群。

        模板约定：两个换行符隔开的分段 = 一条独立 QQ 消息。逐段发送，
        段间由 _throttle 限速（MIN_SEND_INTERVAL）。全部发送成功返回 True，
        任一失败即中断并返回 False。
        """
        paragraphs = [p.strip() for p in text.split("\n\n") if p.strip()]
        if not paragraphs:
            return False
        for para in paragraphs:
            resp = self._call(
                ACTION_SEND_GROUP_MSG,
                {"group_id": self.group_id, "message": para},
            )
            if resp is None:
                return False
            if resp.get("status") not in ("ok", "async"):
                print(f"[qq-share] send_group_msg 返回错误: {resp.get('msg', 'unknown')}")
                return False
        return True

    def send_file(self, file_path, file_name=None):
        """发送文件到群（upload_group_file）。成功返回 True。

        file_name 可自定义（如带比赛名）；缺省用原文件名。
        """
        name = file_name or os.path.basename(file_path)
        resp = self._call(
            ACTION_UPLOAD_GROUP_FILE,
            {
                "group_id": self.group_id,
                "file": os.path.abspath(file_path),
                "name": name,
            },
        )
        if resp is None:
            return False
        if resp.get("status") in ("ok", "async"):
            return True
        print(f"[qq-share] upload_group_file 返回错误: {resp.get('msg', 'unknown')}")
        return False


# ---------------------------------------------------------------------------
# 已发送标记
# ---------------------------------------------------------------------------
def _sent_marker_path(contest_folder):
    return os.path.join(contest_folder, SENT_MARKER_NAME)


def _is_sent(contest_folder):
    """该比赛是否已发送过（标记文件存在）。"""
    return os.path.isfile(_sent_marker_path(contest_folder))


def _mark_sent(contest_folder):
    """写入已发送标记（发送成功后调用）。写入失败只告警，不视为发送失败。"""
    try:
        with open(_sent_marker_path(contest_folder), "w", encoding="utf-8") as f:
            f.write(datetime.now(BEIJING).isoformat() + "\n")
    except OSError as e:
        print(f"[qq-share] Failed to write sent marker for {contest_folder}: {e}")


# ---------------------------------------------------------------------------
# 发送入口
# ---------------------------------------------------------------------------
def build_review_file_name(contest_folder):
    """为比赛的 review.md 生成更详细的发送文件名。

    格式：{date}_{比赛名}_{复盘}.md，去掉引号等不适合作文件名的字符。
    例：2026-08-06_2026钉耙编程中国大学生算法设计暑期联赛（6）_复盘.md
    fallback：无法读取 contest.json 时用 review.md。
    """
    try:
        with open(os.path.join(contest_folder, "contest.json"), "r", encoding="utf-8") as f:
            contest = json.load(f)
    except Exception:
        return "review.md"
    if not isinstance(contest, dict):
        return "review.md"
    date = str(contest.get("date") or "").strip()
    name = str(contest.get("name") or "").strip()
    if not name:
        return "review.md"
    # 过滤文件名字符非法字符（QQ 文件名也适用）：引号、斜杠、反斜杠等
    name = re.sub(r'["\'\\/:*?<>|]', "", name).strip()
    prefix = f"{date}_" if date else ""
    fname = f"{prefix}{name}_复盘.md"
    # 文件名安全兜底：过滤控制字符与首尾空白
    fname = re.sub(r"[\x00-\x1f]", "", fname).strip()
    return fname or "review.md"


def send_contest_share(contest_folder):
    """对一场比赛把 review.md 文件发送到 QQ 群。

    返回 True 表示发送成功（已写入 qq-share.sent 标记）；False 表示跳过 /
    失败（不写标记，下次可重试）。不抛异常。
    """
    folder_name = os.path.basename(contest_folder)
    review_path = os.path.join(contest_folder, "review.md")

    # 依赖检查：review 必须存在（report task 生成的完整报告）
    if not os.path.isfile(review_path):
        print(f"[qq-share] Skipped {folder_name}: review.md not found (report task "
              "must run first).")
        return False

    # 幂等：已发送标记存在则跳过，避免重复群发历史比赛
    if _is_sent(contest_folder):
        print(f"[qq-share] Skipped {folder_name}: already sent "
              f"({SENT_MARKER_NAME} exists).")
        return False

    qq_cfg = _load_qq_config()
    ws_url = qq_cfg.get("napcat_ws_url", "")
    group_id = qq_cfg.get("group_id", 0)
    if not ws_url or not group_id:
        print(f"[qq-share] NapCat 未配置（qq.napcat_ws_url / qq.group_id 缺失）；"
              f"跳过发送 {folder_name}。")
        return False
    if create_connection is None:
        print(f"[qq-share] websocket-client 未安装（pip install websocket-client）；"
              f"跳过发送 {folder_name}。")
        return False

    # 连接 NapCat 并上传 review 文件
    sender = QQGroupSender(ws_url, group_id, qq_cfg.get("napcat_token", ""))
    try:
        sender._connect()
    except Exception as e:
        print(f"[qq-share] NapCat 连接失败 {ws_url}: {e}；跳过发送 {folder_name}。")
        return False

    try:
        review_file_name = build_review_file_name(contest_folder)
        file_ok = sender.send_file(review_path, file_name=review_file_name)
    except Exception as e:
        print(f"[qq-share] 发送异常: {e}")
        return False
    finally:
        sender._close()

    if not file_ok:
        print(f"[qq-share] 文件发送失败；{folder_name} 未标记，下次重试。")
        return False

    _mark_sent(contest_folder)
    print(f"[qq-share] Sent {folder_name} to group {group_id}.")
    return True


def send_contest_shares_for_links(links_filter, contests_root=CONTESTS_ROOT):
    """按订阅链接反查比赛文件夹，逐个执行 share 流程。返回成功发送数量。

    daemon 的 sync/fire 使用：与 report.py --links 相同的反查方式。
    """
    if not os.path.isdir(contests_root):
        print(f"[qq-share] {contests_root} does not exist, nothing to do.")
        return 0
    sent = 0
    for name in sorted(os.listdir(contests_root)):
        contest_folder = os.path.join(contests_root, name)
        if not os.path.isdir(contest_folder):
            continue
        try:
            with open(os.path.join(contest_folder, "contest.json"), "r", encoding="utf-8") as f:
                contest = json.load(f)
        except Exception:
            continue
        link = str((contest or {}).get("link") or "").rstrip("/")
        if link in links_filter and send_contest_share(contest_folder):
            sent += 1
    return sent


def send_contest_shares_from_crawl():
    """只对本次爬取新建的比赛执行 share 流程。返回成功发送数量。"""
    sent = 0
    for folder in load_new_contests():
        if send_contest_share(folder):
            sent += 1
    return sent


def send_contest_shares_for_all(contests_root=CONTESTS_ROOT):
    """扫描所有已有 review.md 且未发送（缺 qq-share.sent 标记）的比赛。

    返回成功发送数量。发送成功写入标记后不会重复发送（幂等）。
    """
    if not os.path.isdir(contests_root):
        print(f"[qq-share] {contests_root} does not exist, nothing to do.")
        return 0
    sent = 0
    for name in sorted(os.listdir(contests_root)):
        contest_folder = os.path.join(contests_root, name)
        if not os.path.isdir(contest_folder):
            continue
        # 预过滤：无 review 或已发送的跳过，避免为它们反复建连 NapCat
        if not os.path.isfile(os.path.join(contest_folder, "review.md")):
            continue
        if _is_sent(contest_folder):
            continue
        if send_contest_share(contest_folder):
            sent += 1
    return sent


def main(argv=None):
    """CLI 入口。返回进程退出码。

    发送失败不产生非零退出码（不阻断 daemon 主流程，review 已生成成功）。
    """
    if argv is None:
        argv = sys.argv[1:]
    args = [a for a in argv if not a.startswith("--")]
    from_crawl = "--from-crawl" in argv

    # --links "link1,link2"：按订阅链接反查比赛（daemon sync/fire 用）。
    # --links 存在但解析为空时直接返回：否则会退化为"全量扫描"，
    # 可能把所有未发送的比赛都群发出去。
    links_filter = None
    if "--links" in argv:
        idx = argv.index("--links")
        raw = argv[idx + 1] if idx + 1 < len(argv) else ""
        links_filter = {l.strip().rstrip("/") for l in raw.split(",") if l.strip()}
        if not links_filter:
            print("[qq-share] --links provided but empty; refusing to scan all contests.")
            return 1

    if from_crawl:
        sent = send_contest_shares_from_crawl()
        print(f"[qq-share] Sent {sent} share(s) from crawl.")
        return 0
    if links_filter:
        sent = send_contest_shares_for_links(links_filter)
        print(f"[qq-share] Sent {sent} share(s) for links.")
        return 0
    if args:
        # 单场比赛：发送失败也返回 0（不阻断 daemon 主流程）
        send_contest_share(args[0])
        return 0
    sent = send_contest_shares_for_all()
    print(f"[qq-share] Sent {sent} share(s).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
