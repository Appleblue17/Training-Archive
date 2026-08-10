#!/usr/bin/env python3
"""QQ 群分享简化版报告生成（DeepSeek）。

基于已生成的 review.md 再调一次 DeepSeek（更高 temperature），生成轻松幽默、
带 emoji 的纯文本总结（200-300 字），落盘 contests/<date> <name>/qq-share.txt。

- qq-share.txt 已存在则跳过（幂等）
- review.md 不存在则跳过（简化版依赖完整报告）
- API key 从环境变量 DEEPSEEK_API_KEY 读取（CI secret / 服务器环境变量）

用法：
    python3 crawler/qq_share.py                       # 扫描所有缺 qq-share 的比赛补生成
    python3 crawler/qq_share.py <contest_folder>      # 只生成指定比赛的 qq-share
    python3 crawler/report.py --qq-only [...]         # 兼容入口（转调本模块）
"""
import os
import sys

from dotenv import load_dotenv

# 本地开发：从仓库根 .env 加载 DEEPSEEK_API_KEY（CI 无 .env，静默跳过）
load_dotenv()

from deepseek_client import call_deepseek

# 模板：crawler/qq-share.template.md（gitignore，本地可自由调整）。
# 占位符：
#   {{review}} 完整复盘报告内容（程序注入，按 QQ_SHARE_MAX_REVIEW_CHARS 截断）
QQ_SHARE_TEMPLATE_PATH = os.path.join(
    os.path.dirname(os.path.abspath(__file__)), "qq-share.template.md"
)

# 简化版输入 review 的安全上限（review 为模型自产，通常很小；防御性截断）
QQ_SHARE_MAX_REVIEW_CHARS = 120_000

# 简化版 system prompt 与采样温度（更轻松随性，故调高 temperature）
QQ_SHARE_SYSTEM = (
    "你是算法竞赛战队的氛围组担当，擅长把比赛复盘改写成"
    "轻松幽默、有感染力、适合群聊分享的中文纯文本总结。"
)
QQ_SHARE_TEMPERATURE = 0.8

# 模板读取失败的兜底（与 crawler/qq-share.template.example.md 内容一致；
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
    """
    qq_path = os.path.join(contest_folder, "qq-share.txt")
    if os.path.exists(qq_path):
        print(f"[qq-share] Skipped {contest_folder}: qq-share.txt already exists.")
        return False

    api_key = os.getenv("DEEPSEEK_API_KEY")
    if not api_key:
        print("[qq-share] DEEPSEEK_API_KEY not set, skipping qq-share generation.")
        return False

    review_path = os.path.join(contest_folder, "review.md")
    if not os.path.exists(review_path):
        print(
            f"[qq-share] Skipped {contest_folder}: review.md not found, "
            "cannot generate qq-share."
        )
        return False
    try:
        with open(review_path, "r", encoding="utf-8") as f:
            review = f.read()
    except Exception as e:
        print(f"[qq-share] Failed to read {review_path}: {e}; skipping qq-share.")
        return False

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
        return False

    content = _strip_code_fence(content)
    if not content:
        print(f"[qq-share] qq-share for {contest_folder} returned empty content.")
        return False

    with open(qq_path, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"[qq-share] Wrote {qq_path}.")
    return True


def generate_qq_shares_for_all(contests_root="contests"):
    """扫描所有已有 review.md 但缺 qq-share.txt 的比赛，逐个生成简化版。"""
    if not os.path.isdir(contests_root):
        print(f"[qq-share] {contests_root} does not exist, nothing to do.")
        return 0

    generated = 0
    for name in sorted(os.listdir(contests_root)):
        contest_folder = os.path.join(contests_root, name)
        if not os.path.isdir(contest_folder):
            continue
        if generate_qq_share(contest_folder):
            generated += 1
    return generated


def main(argv=None):
    """CLI 入口。返回进程退出码。"""
    if argv is None:
        argv = sys.argv[1:]
    args = [a for a in argv if not a.startswith("--")]
    if args:
        ok = generate_qq_share(args[0])
        return 0 if ok else 1
    count = generate_qq_shares_for_all()
    print(f"[qq-share] Generated {count} qq-share(s).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
