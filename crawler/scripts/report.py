#!/usr/bin/env python3
"""复盘报告生成模块（DeepSeek，OpenAI 兼容接口）。

对每场已结束的比赛生成 contests/<date> <name>/review.md：
- 读取 contest.json、problems/*/problem.json、submissions.json
- 原始提交序列（含代码与时间戳）直接送 LLM，不做分析性预处理
- review.md 已存在则跳过（幂等，避免重复消耗 token）

生成完整报告后自动串联生成 QQ 群分享简化版 qq-share.txt
（逻辑在独立模块 crawler/scripts/qq_share.py，此处仅转调）。

API key 从环境变量 DEEPSEEK_API_KEY 读取（CI secret / 服务器环境变量）。

用法：
    python3 crawler/scripts/report.py --links "https://...,https://..."
        # 按订阅链接生成报告（daemon 的 sync/fire 用；报告条件 = 订阅里
        # 填了 end_time 的比赛：EXPIRED / RETRY / fire due，与是否新建无关）
    python3 crawler/scripts/report.py --from-crawl       # 只对本次爬取新建的比赛生成（手动）
    python3 crawler/scripts/report.py --from-crawl --links "https://...,https://..."
        # 只对本次新建中指定订阅链接的比赛生成（手动过滤用）
    python3 crawler/scripts/report.py                    # 扫描所有已结束且缺报告的比赛
    python3 crawler/scripts/report.py <contest_folder>   # 只生成指定比赛（文件夹相对仓库根）
    python3 crawler/scripts/report.py --qq-only          # 兼容入口：转调 qq_share.py（详见该模块）
"""
import json
import os
import re
import sys
from datetime import datetime

# 脚本位于 crawler/scripts/，仓库根为 ../../（使 crawler 包可导入）
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..")))

from crawler.llm.deepseek_client import call_deepseek
from crawler.scripts.new_contests import load_new_contests
from crawler.scripts.qq_share import generate_qq_share, generate_qq_shares_for_all

# 北京时间（UTC+8）
from datetime import timezone, timedelta

beijing = timezone(timedelta(hours=8))

# 提示词安全上限：超出后仅保留较新提交的源码，旧提交只留元数据，
# 避免请求体超过模型上下文限制（DeepSeek 上下文 64K tokens）。
# 题面与比赛信息等固定内容优先保留，提交源码按剩余预算截断。
MAX_PROMPT_CHARS = 240_000

# 提示词模板：crawler/prompts/prompt.template.md（gitignore，本地可自由调整）。
# 占位符：
#   {{contest_info}} 比赛信息块（程序生成，缺字段省略行）
#   {{problems}}     题目列表 + 完整题面（程序生成，含 solved 状态）
#   {{submissions}}  提交时间轴 + 源码（程序生成，按剩余预算截断）
TEMPLATE_PATH = os.path.join(
    os.path.dirname(os.path.abspath(__file__)), "..", "prompts", "prompt.template.md"
)

# 模板读取失败的兜底（与 crawler/prompts/prompt.template.example.md 内容一致；
# 实际模板被 gitignore，CI 等无文件环境用此兜底，保持一致行为）
DEFAULT_TEMPLATE = """\
你是一名经验丰富的 ACM/ICPC 算法竞赛教练。请根据以下比赛数据撰写一份中文复盘报告。

## 比赛信息
{{contest_info}}

## 题目列表与题面
{{problems}}

## 提交记录（按时间升序，含每份源码）
{{submissions}}

## 要求

请输出 Markdown 格式的复盘报告，包含但不限于：

1. **总体表现总结**：按照题目编号列表展示每道题的最终状态、罚时与 Dirt、解题时间线（提交时间、AC 时间、罚时等）。分析整体节奏与策略，发挥水平，做得好与不足的地方。
2. **逐题分析**：对**尝试过的**（即有提交记录）的每道题可先根据题意和代码，简单分析可能考察的模块或知识点，可能的解题思路，预估难度。随后，请详细分析时间线、未通过原因和关键转折点等。可注重以下内容：
   - 主要的错误类型（如边界条件、算法复杂度、低级错误等）。可包含关键代码片段的解析
   - 时间分配和策略调整
3. **补题推荐**：针对未完成的题目，可根据可能的解题思路和难度，和题目质量（最重要的），简要给出补题建议，或是更多的练习建议和方向。不要对每道题都分析解题思路或给出完整解法，而是按照题目质量与价值抽出几道（或者没有好题的话就不推荐）或者你觉得真正有价值的题目作为推荐。
4. **失误与改进建议**：总结本场比赛出现的不足，简要列出细致到题目与代码的失误点。提出可执行的改进项与建议（包括技术上和策略上的）。可包含一句话结语，总结本次比赛的整体感受、收获与反思，对队员的鼓励与建议。
   - 技术上：如算法、数据结构、代码风格、调试技巧等
   - 策略上：如题目选择顺序、时间分配、团队协作等

格式要求：
- 报告开头用一级标题，标题为比赛名称。
- 不要复述完整代码，只引用关键片段。
- 全部使用中文。
- 不必担忧篇幅，尽可能发掘细节和可能存在的问题和改进点

提示：
- 没有提交不代表没有尝试，可能是因为题目难度较高或时间不够（这在比赛中是常见的情况），**逐题分析**中只分析有提交记录的题目即可。
- 当一道题在通过之后，仍然有后续提交且与本题无关时，很可能是因为队员将此当作“虚拟打印”功能来使用，可以忽略，不必分析这些提交或是在报告中提及。
- ACM/ICPC 比赛中，队伍的最终排名以题目数量为第一优先级，罚时为第二优先级。若通过题目数量相同，则罚时少的队伍排名靠前。
- ACM/ICPC 比赛中，“罚时机制”是指在比赛中提交错误的次数所产生的时间惩罚。每次提交错误都会增加 20 分钟罚时。一般用总罚时 = 正确提交时间 + 错误提交次数 * 20 分钟。罚时机制的存在会影响队伍的排名，因此在比赛中需要合理安排提交策略，避免不必要的错误提交。
- ACM/ICPC 比赛中，比赛开始四小时后会进入“封榜”阶段，队员无法看到其他队伍在封榜期间的提交评测结果。封榜阶段的策略和心态调整非常重要。"""


def _load_template():
    """读取提示词模板文件；失败时回退到内置默认模板。"""
    try:
        with open(TEMPLATE_PATH, "r", encoding="utf-8") as f:
            return f.read()
    except Exception as e:
        print(f"[report] Failed to load template {TEMPLATE_PATH}: {e}; using built-in default.")
        return DEFAULT_TEMPLATE


def load_json(path):
    if not os.path.exists(path):
        return None
    try:
        with open(path, "r", encoding="utf-8") as f:
            return json.load(f)
    except Exception as e:
        print(f"[report] Failed to parse {path}: {e}")
        return None


def _problem_letter_map(contest_folder):
    """problems/<letter>/problem.json -> (letter, problem_entry)。"""
    result = {}
    problems_dir = os.path.join(contest_folder, "problems")
    if not os.path.isdir(problems_dir):
        return result
    for letter in sorted(os.listdir(problems_dir)):
        entry = load_json(os.path.join(problems_dir, letter, "problem.json"))
        if entry:
            result[letter] = entry
    return result


def _problem_id_from_link(link):
    """从 problem_link 提取平台题目 ID（与 crawler/platforms/base.py 的 helper 一致）。

    HDU/NowCoder：https://.../problem?cid=123&pid=1006  → "1006"
    QOJ：https://.../problem/123                          → "123"
    提取失败返回 None。
    """
    if not link:
        return None
    m = re.search(r"[?&]pid=(\d+)", link)
    if m:
        return m.group(1)
    m = re.search(r"/problem/(\d+)/?$", link)
    if m:
        return m.group(1)
    return None


def _build_problems_block(problems_map, contest_folder):
    """题目列表块：每题含元数据（link/时限/内存/solved）+ 完整题面（statement.md）。

    statement.md 由爬虫生成，首行为 "## <letter>. <name>" 标题，
    与本块开头的 "### <letter>. <name>" 重复，注入时丢弃首行。
    """
    lines = []
    if not problems_map:
        lines.append("（无题目数据）")
        return "\n".join(lines)

    for letter in sorted(problems_map):
        entry = problems_map[letter]
        lines.append(f"### {letter}. {entry.get('name', '?')}")
        if entry.get("link"):
            lines.append(f"- link: {entry['link']}")
        if entry.get("time_limit"):
            lines.append(f"- time_limit: {entry['time_limit']}")
        if entry.get("memory_limit"):
            lines.append(f"- memory_limit: {entry['memory_limit']}")
        if entry.get("solved"):
            solved_line = "- solved: 是"
            if entry.get("solve_time"):
                solved_line += f"（solve_time: {entry['solve_time']}）"
            lines.append(solved_line)
        elif "solved" in entry:
            lines.append("- solved: 否")

        statement_path = os.path.join(
            contest_folder, "problems", letter, "statement.md"
        )
        if os.path.exists(statement_path):
            try:
                with open(statement_path, "r", encoding="utf-8") as f:
                    statement = f.read().strip()
                # 丢弃与 ### 标题重复的首行（"## <letter>. <name>"）
                body = (
                    statement.split("\n", 1)[1].strip()
                    if "\n" in statement
                    else statement
                )
                if body:
                    lines.append("")
                    lines.append("题面：")
                    lines.append(body)
                else:
                    lines.append("（题面为空）")
            except Exception as e:
                lines.append(f"（题面读取失败：{e}）")
        else:
            lines.append("（无题面数据）")
        lines.append("")
    return "\n".join(lines).rstrip()


def _build_submissions_block(submissions_sorted, source_by_letter, letter_for, budget):
    """提交时间轴块：每份提交的元数据行 + 源码代码块，受 budget（字符数）限制。

    与旧版 build_prompt 内联逻辑一致：超预算时旧提交只保留元数据行、
    源码省略（较新的提交优先保留源码）。
    """
    lines = []
    if not submissions_sorted:
        lines.append("（无提交数据）")
        return "\n".join(lines)

    used = 0
    for i, sub in enumerate(submissions_sorted, 1):
        sub_lines = []
        sub_lines.append(
            f"### 提交 #{i}  id={sub.get('submission_id')}  题目={letter_for(sub)}  "
            f"状态={sub.get('status')}  语言={sub.get('language')}  "
            f"时间={sub.get('submit_time')}"
        )
        if sub.get("time") is not None:
            sub_lines.append(f"运行时间={sub.get('time')}")
        if sub.get("memory") is not None:
            sub_lines.append(f"内存={sub.get('memory')}")
        # 元数据行（计入长度上限；源码只对较新的提交保留）
        meta_len = sum(len(l) + 1 for l in sub_lines) + 60
        if used + meta_len > budget:
            sub_lines.append("（源码因长度限制省略）")
            sub_lines.append("```")
            lines.extend(sub_lines)
            break
        sub_lines.append("```")
        letter = letter_for(sub)
        code = source_by_letter.get(letter, {}).get(
            str(sub.get("submission_id"))
        ) or ""
        if used + meta_len + len(code) > budget and code:
            # 源码超限：截断为最近提交保留摘要
            keep = budget - used - meta_len - 40
            if keep > 200:
                sub_lines.append(code[:keep] + "\n...（源码截断）")
            else:
                sub_lines.append("（源码因长度限制省略）")
        else:
            sub_lines.append(code)
        sub_lines.append("```")
        block = "\n".join(sub_lines)
        lines.extend(sub_lines)
        used += len(block) + 1
    return "\n".join(lines)


def build_prompt(contest_folder):
    contest = load_json(os.path.join(contest_folder, "contest.json")) or {}
    submissions = load_json(os.path.join(contest_folder, "submissions.json")) or []
    problems_map = _problem_letter_map(contest_folder)

    # 提交 -> 题目字母：优先按 link 匹配，其次按 problem_id，最后按 name
    letter_by_link = {}
    letter_by_id = {}
    letter_by_name = {}
    for letter, entry in problems_map.items():
        if entry.get("link"):
            link = entry["link"].rstrip("/")
            letter_by_link[link] = letter
            pid = _problem_id_from_link(entry["link"])
            if pid:
                letter_by_id[pid] = letter
        if entry.get("name"):
            letter_by_name[entry["name"]] = letter

    def letter_for(sub):
        link = (sub.get("problem_link") or "").rstrip("/")
        if link in letter_by_link:
            return letter_by_link[link]
        pid = sub.get("problem_id") or _problem_id_from_link(link)
        if pid and pid in letter_by_id:
            return letter_by_id[pid]
        return letter_by_name.get(sub.get("problem_name"), "?")

    # letter -> {submission_id: source}（源码存于 problems/<letter>/submissions/<id>.<ext>）
    source_by_letter = {}
    for letter in problems_map:
        sdir = os.path.join(contest_folder, "problems", letter, "submissions")
        if not os.path.isdir(sdir):
            continue
        for fn in os.listdir(sdir):
            sid = os.path.splitext(fn)[0]
            try:
                with open(os.path.join(sdir, fn), "r", encoding="utf-8") as f:
                    source_by_letter.setdefault(letter, {})[sid] = f.read()
            except Exception:
                pass

    # 按提交时间升序排列（时间轴）
    def sort_key(sub):
        return sub.get("submit_time") or "0000-01-01T00:00:00"

    submissions_sorted = sorted(submissions, key=sort_key)

    # 比赛信息块（缺字段省略行）
    info_lines = []
    info_lines.append(f"- 名称：{contest.get('name', '?')}")
    info_lines.append(f"- 日期：{contest.get('date', '?')}")
    info_lines.append(f"- 平台：{contest.get('platform', '?')}")
    if contest.get("link"):
        info_lines.append(f"- 链接：{contest['link']}")
    if contest.get("start_time"):
        info_lines.append(f"- 开始：{contest['start_time']}")
    if contest.get("end_time"):
        info_lines.append(f"- 结束：{contest['end_time']}")
    contest_info = "\n".join(info_lines)

    # 题目块（含完整题面）优先保留；提交源码按剩余预算截断
    problems_block = _build_problems_block(problems_map, contest_folder)

    template = _load_template()
    prefix = template.replace("{{contest_info}}", contest_info).replace(
        "{{problems}}", problems_block
    )
    budget = MAX_PROMPT_CHARS - len(prefix)
    submissions_block = _build_submissions_block(
        submissions_sorted, source_by_letter, letter_for, budget
    )
    return prefix.replace("{{submissions}}", submissions_block)


def generate_review(contest_folder):
    """为单场比赛生成 review.md。已存在或缺少关键数据时跳过。返回 True 表示生成成功。"""
    review_path = os.path.join(contest_folder, "review.md")
    if os.path.exists(review_path):
        print(f"[report] Skipped {contest_folder}: review.md already exists.")
        return False

    api_key = os.getenv("DEEPSEEK_API_KEY")
    if not api_key:
        print("[report] DEEPSEEK_API_KEY not set, skipping report generation.")
        return False

    contest = load_json(os.path.join(contest_folder, "contest.json")) or {}
    submissions = load_json(os.path.join(contest_folder, "submissions.json")) or []
    if not submissions:
        print(f"[report] Skipped {contest_folder}: no submissions.json data.")
        return False

    # 只有已结束的比赛才生成报告
    end_time = contest.get("end_time")
    if not end_time:
        print(f"[report] Skipped {contest_folder}: contest has no end_time.")
        return False
    try:
        end_dt = datetime.fromisoformat(str(end_time).replace("Z", "+00:00"))
        if end_dt.tzinfo is None:
            end_dt = end_dt.replace(tzinfo=beijing)
        if end_dt.astimezone(beijing) > datetime.now(beijing):
            print(f"[report] Skipped {contest_folder}: contest has not ended yet.")
            return False
    except ValueError as e:
        print(f"[report] Skipped {contest_folder}: invalid end_time {end_time}: {e}")
        return False

    print(f"[report] Generating review for {contest_folder} ...")
    prompt = build_prompt(contest_folder)
    try:
        content = call_deepseek(prompt, api_key)
    except Exception as e:
        print(f"[report] DeepSeek call failed for {contest_folder}: {e}")
        return False

    with open(review_path, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"[report] Wrote {review_path}.")

    # 串联生成 QQ 群分享简化版（独立 API 调用，失败不阻断完整报告）
    generate_qq_share(contest_folder)
    return True


def generate_reviews_for_all(contests_root="contests"):
    """扫描所有已结束且缺 review.md 的比赛，逐个生成报告。返回成功生成的数量。"""
    if not os.path.isdir(contests_root):
        print(f"[report] {contests_root} does not exist, nothing to do.")
        return 0

    generated = 0
    for name in sorted(os.listdir(contests_root)):
        contest_folder = os.path.join(contests_root, name)
        if not os.path.isdir(contest_folder):
            continue
        if generate_review(contest_folder):
            generated += 1
    return generated


def generate_reviews_for_links(links_filter, contests_root="contests"):
    """按订阅链接反查比赛文件夹生成报告（不依赖 new-contests.json）。

    扫描 contests/ 下所有比赛的 contest.json，匹配 link 的才生成。
    daemon 的 sync/fire 使用：报告条件 = 订阅里**填了 end_time** 的比赛
    （EXPIRED / RETRY / fire due），与"本次是否新建"无关——比赛此前已
    归档过（非新建）也要生成，否则会漏掉复盘。
    """
    if not os.path.isdir(contests_root):
        print(f"[report] {contests_root} does not exist, nothing to do.")
        return 0
    generated = 0
    for name in sorted(os.listdir(contests_root)):
        contest_folder = os.path.join(contests_root, name)
        if not os.path.isdir(contest_folder):
            continue
        contest = load_json(os.path.join(contest_folder, "contest.json")) or {}
        link = str(contest.get("link") or "").rstrip("/")
        if link in links_filter and generate_review(contest_folder):
            generated += 1
    return generated


if __name__ == "__main__":
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    qq_only = "--qq-only" in sys.argv[1:]
    from_crawl = "--from-crawl" in sys.argv[1:]

    # --links "link1,link2"：只对指定订阅链接的比赛生成（服务器 sync 补抓已过期
    # 比赛时，同一批爬取可能同时含历史比赛，历史比赛不生成报告，用 --links 过滤）。
    links_filter = None
    if "--links" in sys.argv[1:]:
        idx = sys.argv[1:].index("--links")
        raw = sys.argv[1:][idx + 1] if idx + 1 < len(sys.argv[1:]) else ""
        links_filter = {
            l.strip().rstrip("/") for l in raw.split(",") if l.strip()
        }

    def _filter_by_links(folders):
        if not links_filter:
            return folders
        kept = []
        for f in folders:
            contest = load_json(os.path.join(f, "contest.json")) or {}
            link = str(contest.get("link") or "").rstrip("/")
            if link in links_filter:
                kept.append(f)
        return kept

    if from_crawl:
        # 只对本次爬取新建的比赛生成（手动场景；review.md / qq-share 存在仍幂等跳过）
        folders = _filter_by_links(load_new_contests())
        if qq_only:
            count = sum(1 for f in folders if generate_qq_share(f))
            print(f"[report] Generated {count} qq-share(s) from crawl.")
            sys.exit(0)
        count = sum(1 for f in folders if generate_review(f))
        print(f"[report] Generated {count} review(s) from crawl.")
        sys.exit(0)
    elif links_filter:
        # 订阅驱动（daemon 的 sync/fire）：报告条件 = 订阅里填了 end_time 的
        # 比赛（EXPIRED / RETRY / fire due），按链接反查比赛文件夹生成，
        # 不依赖 new-contests.json（与本次是否新建无关）。
        count = generate_reviews_for_links(links_filter)
        print(f"[report] Generated {count} review(s) for links.")
        sys.exit(0)
    elif qq_only:
        if args:
            ok = generate_qq_share(args[0])
            sys.exit(0 if ok else 1)
        count = generate_qq_shares_for_all()
        print(f"[report] Generated {count} qq-share(s).")
    elif args:
        target = args[0]
        ok = generate_review(target)
        sys.exit(0 if ok else 1)
    else:
        count = generate_reviews_for_all()
        print(f"[report] Generated {count} review(s).")
