#!/usr/bin/env python3
"""QQ 群分享（share AI task）：生成简化版报告 + 通过 NapCat 发送到 QQ 群。

流程（每场比赛）：
  1. 生成 qq-share.txt（DeepSeek 简化版，基于 review.md；幂等，已存在则跳过）
  2. 发送：连接 NapCat（OneBot 11 正向 WebSocket）→ 群发文字（qq-share.txt 内容）
     → 群发 review.md 文件（upload_group_file）
  3. 发送成功后删除 qq-share.txt（临时产物，不进入 git；失败保留供下次重试）

发送模式（config.json 的 qq.send_mode）：
  - text_and_file（默认）：文案 + review 文件（上述完整流程）
  - file_only：只发 review 文件，不生成/不发送文案（不产生 qq-share.txt、不调 LLM）

规则：
  - 文字缺失（qq-share.txt 生成失败/为空）：记入 log，跳过文字，直接发 review 文件
  - review.md 不存在：跳过（share 依赖 report task 生成的完整报告，不自行生成）
  - NapCat 未配置 / 连接失败 / 发送失败：记 log 告警，不阻断 daemon 主流程
  - qq-share.txt 已存在（上次发送失败遗留）：跳过生成直接重试发送

与 report 解耦：report.py 不再串联本模块；由 daemon 的 sync/fire 在 report
成功后按 config.json 的 ai_tasks.share.enabled 单独调用。

配置（crawler/config.json）：
  "ai_tasks": { "share": { "enabled": true } }
  "qq": {
    "napcat_ws_url": "ws://127.0.0.1:6700",   # NapCat WebSocket 地址
    "napcat_token": "",                        # NapCat 鉴权 token（如启用）
    "group_id": 123456789,                     # 目标 QQ 群号
    "send_mode": "text_and_file"               # 发送模式：
                                               #   text_and_file（默认）文案 + review 文件
                                               #   file_only 只发 review 文件（不生成/不发文案）
  }

用法：
    python3 crawler/scripts/qq_share.py --links "link1,link2"  # 按订阅链接反查比赛（daemon 用）
    python3 crawler/scripts/qq_share.py --from-crawl           # 只对本次爬取新建的比赛
    python3 crawler/scripts/qq_share.py <contest_folder>       # 指定比赛（文件夹相对仓库根）
    python3 crawler/scripts/qq_share.py                        # 扫描所有缺 qq-share 的比赛
    python3 crawler/scripts/qq_share.py <contest_folder> --file-only  # 强制只发 review 文件
"""
import json
import os
import re
import sys
import time
import uuid

from dotenv import load_dotenv

# 本地开发：从仓库根 .env 加载 DEEPSEEK_API_KEY（CI 无 .env，静默跳过）
load_dotenv()

# 脚本位于 crawler/scripts/，仓库根为 ../../（使 crawler 包可导入）
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..")))

from crawler.llm.deepseek_client import call_deepseek
from crawler.scripts.new_contests import load_new_contests

# websocket-client 库（发送到 NapCat 用）
_WS_IMPORT_ERROR = None
try:
    from websocket import create_connection
except ImportError as e:  # pragma: no cover
    _WS_IMPORT_ERROR = e
    create_connection = None

# 模板：crawler/prompts/qq-share.template.md（gitignore，本地可自由调整）。
# 占位符：
#   {{review}} 完整复盘报告内容（程序注入，按 QQ_SHARE_MAX_REVIEW_CHARS 截断）
QQ_SHARE_TEMPLATE_PATH = os.path.join(
    os.path.dirname(os.path.abspath(__file__)), "..", "prompts", "qq-share.template.md"
)

# 简化版输入 review 的安全上限（review 为模型自产，通常很小；防御性截断）
QQ_SHARE_MAX_REVIEW_CHARS = 120_000

# 简化版 system prompt 与采样温度（更轻松随性，故调高 temperature）
QQ_SHARE_SYSTEM = (
    "你是算法竞赛战队的氛围组担当，擅长把比赛复盘改写成"
    "轻松幽默、有感染力、适合群聊分享的中文纯文本总结。"
)
QQ_SHARE_TEMPERATURE = 0.8

# 模板读取失败的兜底（与 crawler/prompts/qq-share.template.example.md 内容一致；
# 实际模板被 gitignore，CI 等无文件环境用此兜底，保持一致行为）
DEFAULT_QQ_SHARE_TEMPLATE = """\
你是算法竞赛战队的"氛围组"担当，负责把比赛复盘改写成轻松、有感染力、适合发到 QQ 群分享的纯文本总结。

下面是一场已经结束的比赛完整复盘报告（Markdown）。请把它改写成一段**纯文本**（不要使用任何 Markdown 标记，不要加代码围栏），要求：

1. 先跟大家打个招呼，表示慰问和鼓励。
2. 你可以根据复盘报告，说一说比赛结果，简单总结亮点，有趣细节，精彩时刻等等，更多内容请自由发挥。但可以更侧重于鼓励和提醒大家，不必涉及太多题目和代码细节，也不必逐题分析。
3. 语言轻松，有感染力，而又不令人感到做作与不自然。你可以对队员们的出色表现表示由衷的惊叹，也可以对“差一点”或是“没时间”的遗憾表示惋惜，自然流露情感。
4. 注意语气和用词，避免使用容易令人反感或说教的语气和词句

格式要求：
- 输出**纯文本**，不要使用任何 Markdown 标记，不要加代码围栏
- 可用两个换行符隔开分段，每一段话代表 QQ 中的一条消息
- 全部使用中文
- 可以适当用 emoji 或颜文字点缀，但不要堆砌

完整复盘报告：

{{review}}
"""

# 仓库根 / 配置路径
REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
CONFIG_PATH = os.path.join(REPO_ROOT, "crawler", "config.json")
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


def _load_qq_config():
    """读取 config.json 的 qq 块；缺失返回 {}。"""
    cfg = _load_config()
    qq = cfg.get("qq", {})
    return qq if isinstance(qq, dict) else {}


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

    def send_contest(self, text, review_path, file_name=None):
        """发送文字 + review 文件到群。任一成功即整体成功。

        - text 非空：先发文字；文字发送失败不影响文件发送
        - review_path 存在：再发文件（file_name 自定义文件名，缺省 review.md）
        返回 (text_ok, file_ok)。
        """
        text_ok = False
        if text:
            text_ok = self.send_text(text)
            if not text_ok:
                print("[qq-share] 文字发送失败（继续尝试发文件）。")
        file_ok = False
        if review_path and os.path.isfile(review_path):
            file_ok = self.send_file(review_path, file_name=file_name)
        return text_ok, file_ok


# ---------------------------------------------------------------------------
# 生成 qq-share.txt
# ---------------------------------------------------------------------------
def _load_qq_share_template():
    """读取 QQ 分享简化版模板；失败时回退到内置默认模板。"""
    try:
        with open(QQ_SHARE_TEMPLATE_PATH, "r", encoding="utf-8") as f:
            return f.read()
    except Exception as e:
        print(
            f"[qq-share] Failed to load template {QQ_SHARE_TEMPLATE_PATH}: {e}; "
            "using built-in default."
        )
        return DEFAULT_QQ_SHARE_TEMPLATE


def _strip_code_fence(text):
    """剥离模型偶尔包裹的 ``` 围栏（纯文本输出不应包含 Markdown 标记）。"""
    text = text.strip()
    if text.startswith("```"):
        # 去掉首行 ``` 与可选的标注语言
        first_nl = text.find("\n")
        if first_nl == -1:
            return ""
        text = text[first_nl + 1 :]
    if text.endswith("```"):
        text = text[:-3]
    return text.strip()


def generate_qq_share(contest_folder):
    """基于 review.md 生成 QQ 群分享简化版 qq-share.txt。

    - qq-share.txt 已存在则跳过（幂等）
    - review.md 不存在则跳过（简化版依赖完整报告）
    - 独立 API 调用（更高 temperature），失败不阻断其他流程
    返回 "ok" / "skipped" / "failed"。
    """
    qq_path = os.path.join(contest_folder, "qq-share.txt")
    if os.path.exists(qq_path):
        print(f"[qq-share] Skipped {contest_folder}: qq-share.txt already exists.")
        return "skipped"

    api_key = os.getenv("DEEPSEEK_API_KEY")
    if not api_key:
        print("[qq-share] DEEPSEEK_API_KEY not set, skipping qq-share generation.")
        return "skipped"

    review_path = os.path.join(contest_folder, "review.md")
    if not os.path.exists(review_path):
        print(
            f"[qq-share] Skipped {contest_folder}: review.md not found, "
            "cannot generate qq-share."
        )
        return "skipped"
    try:
        with open(review_path, "r", encoding="utf-8") as f:
            review = f.read()
    except Exception as e:
        print(f"[qq-share] Failed to read {review_path}: {e}; skipping qq-share.")
        return "skipped"

    template = _load_qq_share_template()
    prompt = template.replace("{{review}}", review[:QQ_SHARE_MAX_REVIEW_CHARS])

    print(f"[qq-share] Generating qq-share for {contest_folder} ...")
    try:
        content = call_deepseek(
            prompt,
            api_key,
            system_message=QQ_SHARE_SYSTEM,
            temperature=QQ_SHARE_TEMPERATURE,
        )
    except Exception as e:
        print(f"[qq-share] DeepSeek call failed for qq-share {contest_folder}: {e}")
        return "failed"

    content = _strip_code_fence(content)
    if not content:
        print(f"[qq-share] qq-share for {contest_folder} returned empty content.")
        return "failed"

    with open(qq_path, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"[qq-share] Wrote {qq_path}.")
    return "ok"


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


def send_contest_share(contest_folder, force_file_only=False):
    """对一场比赛执行完整 share 流程：生成 qq-share → 群发 → 删除 qq-share。

    返回 True 表示流程成功完成（发送成功且 qq-share.txt 已清理）；
    False 表示跳过（review 缺失 / NapCat 未配置 / 发送失败），不抛异常。
    """
    folder_name = os.path.basename(contest_folder)
    review_path = os.path.join(contest_folder, "review.md")

    # 依赖检查：review 必须存在（report task 生成的完整报告）
    if not os.path.isfile(review_path):
        print(f"[qq-share] Skipped {folder_name}: review.md not found (report task "
              "must run first).")
        return False

    # 0. 发送模式：text_and_file（默认，文案+文件）/ file_only（只发文件）。
    #    force_file_only（--file-only CLI）优先于 config 的 qq.send_mode。
    qq_cfg = _load_qq_config()
    send_mode = str(qq_cfg.get("send_mode") or "text_and_file").strip().lower()
    file_only = force_file_only or send_mode == "file_only"

    # 1. 生成 qq-share.txt（存在则跳过：上次发送失败遗留，直接重试发送）。
    #    file_only 模式不生成/不读取文案，直接跳到发送文件。
    qq_path = os.path.join(contest_folder, "qq-share.txt")
    text = ""
    if not file_only:
        gen = generate_qq_share(contest_folder)
        if os.path.isfile(qq_path):
            try:
                with open(qq_path, "r", encoding="utf-8") as f:
                    text = f.read().strip()
            except Exception as e:
                print(f"[qq-share] Failed to read {qq_path}: {e}")
        if not text:
            print(f"[qq-share] qq-share text empty/missing for {folder_name}; "
                  "sending review file only (recorded in log).")
    else:
        print(f"[qq-share] {'--file-only CLI' if force_file_only else 'send_mode=file_only'}: "
              f"只发 review 文件，跳过文案（{folder_name}）。")

    # 2. NapCat 配置检查（qq_cfg 已在第 0 步加载）
    ws_url = qq_cfg.get("napcat_ws_url", "")
    group_id = qq_cfg.get("group_id", 0)
    if not ws_url or not group_id:
        print(f"[qq-share] NapCat 未配置（qq.napcat_ws_url / qq.group_id 缺失）；"
              f"跳过发送 {folder_name}（qq-share.txt 保留，未进入 git）。")
        return False
    if create_connection is None:
        print(f"[qq-share] websocket-client 未安装（pip install websocket-client）；"
              f"跳过发送 {folder_name}。")
        return False

    # 3. 连接 NapCat 并发送
    sender = QQGroupSender(
        ws_url, group_id, qq_cfg.get("napcat_token", "")
    )
    try:
        sender._connect()
    except Exception as e:
        print(f"[qq-share] NapCat 连接失败 {ws_url}: {e}；跳过发送 {folder_name}。")
        return False

    try:
        review_file_name = build_review_file_name(contest_folder)
        text_ok, file_ok = sender.send_contest(
            clean_for_qq(text) if text else "", review_path, file_name=review_file_name
        )
    except Exception as e:
        print(f"[qq-share] 发送异常: {e}")
        return False
    finally:
        sender._close()

    if not text_ok and not file_ok:
        print(f"[qq-share] 发送失败（文字与文件均未成功）；{folder_name} 保留待重试。")
        return False

    # 4. 发送成功 → 删除 qq-share.txt（临时产物，不进入 git）。
    #    file_only 模式从未生成/使用文案，不删除 qq-share.txt。
    if not file_only and os.path.isfile(qq_path):
        try:
            os.remove(qq_path)
            print(f"[qq-share] Removed {qq_path}（发送完成，不入 git）。")
        except OSError as e:
            print(f"[qq-share] Failed to remove {qq_path}: {e}（gitignore 兜底）。")
    print(f"[qq-share] Sent {folder_name} to group {group_id}.")
    return True


def send_contest_shares_for_links(links_filter, contests_root=CONTESTS_ROOT,
                                  force_file_only=False):
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
        if link in links_filter and send_contest_share(
                contest_folder, force_file_only=force_file_only):
            sent += 1
    return sent


def send_contest_shares_from_crawl(force_file_only=False):
    """只对本次爬取新建的比赛执行 share 流程。返回成功发送数量。"""
    sent = 0
    for folder in load_new_contests():
        if send_contest_share(folder, force_file_only=force_file_only):
            sent += 1
    return sent


def send_contest_shares_for_all(contests_root=CONTESTS_ROOT, force_file_only=False):
    """扫描所有已有 review.md 且未发送过 qq-share 的比赛。返回成功发送数量。

    注：未发送标记 = 存在未删除的 qq-share.txt；发送成功的比赛 qq-share.txt
    已被删除，不会重复发送（幂等）。
    """
    if not os.path.isdir(contests_root):
        print(f"[qq-share] {contests_root} does not exist, nothing to do.")
        return 0
    sent = 0
    for name in sorted(os.listdir(contests_root)):
        contest_folder = os.path.join(contests_root, name)
        if not os.path.isdir(contest_folder):
            continue
        qq_path = os.path.join(contest_folder, "qq-share.txt")
        if os.path.isfile(qq_path) and send_contest_share(
                contest_folder, force_file_only=force_file_only):
            sent += 1
    return sent


def main(argv=None):
    """CLI 入口。返回进程退出码。

    发送失败不产生非零退出码（不阻断 daemon 主流程，review 已生成成功）。
    --file-only：本次调用强制只发 review 文件（优先于 config 的 qq.send_mode）。
    """
    if argv is None:
        argv = sys.argv[1:]
    args = [a for a in argv if not a.startswith("--")]
    from_crawl = "--from-crawl" in argv
    force_file_only = "--file-only" in argv

    # --links "link1,link2"：按订阅链接反查比赛（daemon sync/fire 用）
    links_filter = None
    if "--links" in argv:
        idx = argv.index("--links")
        raw = argv[idx + 1] if idx + 1 < len(argv) else ""
        links_filter = {l.strip().rstrip("/") for l in raw.split(",") if l.strip()}

    if from_crawl:
        sent = send_contest_shares_from_crawl(force_file_only=force_file_only)
        print(f"[qq-share] Sent {sent} share(s) from crawl.")
        return 0
    if links_filter:
        sent = send_contest_shares_for_links(
            links_filter, force_file_only=force_file_only)
        print(f"[qq-share] Sent {sent} share(s) for links.")
        return 0
    if args:
        # 单场比赛：发送失败也返回 0（不阻断 daemon 主流程）
        send_contest_share(args[0], force_file_only=force_file_only)
        return 0
    sent = send_contest_shares_for_all(force_file_only=force_file_only)
    print(f"[qq-share] Sent {sent} share(s).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
