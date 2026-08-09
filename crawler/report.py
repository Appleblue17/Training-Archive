#!/usr/bin/env python3
"""复盘报告生成模块（DeepSeek，OpenAI 兼容接口）。

对每场已结束的比赛生成 contests/<date> <name>/review.md：
- 读取 contest.json、problems/*/problem.json、submissions.json
- 原始提交序列（含代码与时间戳）直接送 LLM，不做分析性预处理
- review.md 已存在则跳过（幂等，避免重复消耗 token）
- API key 从环境变量 DEEPSEEK_API_KEY 读取（CI secret / 服务器环境变量）

用法：
    python3 crawler/report.py                  # 扫描所有已结束且缺报告的比赛
    python3 crawler/report.py <contest_folder> # 只生成指定比赛（文件夹相对仓库根）
"""
import json
import os
import re
import sys
from datetime import datetime

from dotenv import load_dotenv

# 本地开发：从仓库根 .env 加载 DEEPSEEK_API_KEY（CI 无 .env，静默跳过）
load_dotenv()

# httpx（openai 底层）只认 socks5://，不认 socks://；clash 等代理工具导出的
# ALL_PROXY 常为 "socks://127.0.0.1:7890"，会导致 OpenAI 客户端构造时报
# "Unknown scheme for proxy URL"。统一归一化为 socks5://（socksio 已装）。
for _proxy_var in (
    "ALL_PROXY",
    "all_proxy",
    "HTTP_PROXY",
    "http_proxy",
    "HTTPS_PROXY",
    "https_proxy",
):
    _proxy_value = os.environ.get(_proxy_var, "")
    if _proxy_value.startswith("socks://"):
        os.environ[_proxy_var] = "socks5://" + _proxy_value[len("socks://") :]

# 北京时间（UTC+8）
from datetime import timezone, timedelta

beijing = timezone(timedelta(hours=8))

BASE_URL = "https://api.deepseek.com"
MODEL = "deepseek-chat"

# 提示词安全上限：超出后仅保留较新提交的源码，旧提交只留元数据，
# 避免请求体超过模型上下文限制（DeepSeek 上下文 64K tokens）。
# 题面与比赛信息等固定内容优先保留，提交源码按剩余预算截断。
MAX_PROMPT_CHARS = 240_000

# 提示词模板：crawler/prompt.template.md（git 跟踪，可直接编辑）。
# 占位符：
#   {{contest_info}} 比赛信息块（程序生成，缺字段省略行）
#   {{problems}}     题目列表 + 完整题面（程序生成，含 solved 状态）
#   {{submissions}}  提交时间轴 + 源码（程序生成，按剩余预算截断）
TEMPLATE_PATH = os.path.join(os.path.dirname(os.path.abspath(__file__)), "prompt.template.md")

# 模板读取失败的兜底（与 prompt.template.md 内容一致）
DEFAULT_TEMPLATE = """\
你是一名经验丰富的算法竞赛教练。请根据以下比赛数据撰写一份中文复盘报告。

## 比赛信息
{{contest_info}}

## 题目列表与题面
{{problems}}

## 提交记录（按时间升序，含每份源码）
{{submissions}}

## 要求

请输出 Markdown 格式的复盘报告，包含：

1. **总体表现总结**：AC 数量、失败提交次数、用时分布与整体节奏。
2. **逐题分析**：对每道题给出题意理解、AC 时间线、WA/失败次数、关键转折点与解题思路。
3. **失误与改进建议**：按优先级列出可执行的改进项，作为下一场比赛的行动清单。

格式要求：

- 报告开头用一级标题，标题为比赛名称。
- 不要复述完整代码，只引用关键片段。
- 全部使用中文。
"""


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
    """从 problem_link 提取平台题目 ID（与 crawler/base.py 的 helper 一致）。

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


def call_deepseek(prompt, api_key):
    from openai import OpenAI

    client = OpenAI(api_key=api_key, base_url=BASE_URL)
    resp = client.chat.completions.create(
        model=MODEL,
        messages=[
            {
                "role": "system",
                "content": "你是算法竞赛复盘助手，输出结构清晰的中文 Markdown 报告。",
            },
            {"role": "user", "content": prompt},
        ],
        temperature=0.3,
    )
    return resp.choices[0].message.content


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


if __name__ == "__main__":
    if len(sys.argv) > 1:
        target = sys.argv[1]
        ok = generate_review(target)
        sys.exit(0 if ok else 1)
    else:
        count = generate_reviews_for_all()
        print(f"[report] Generated {count} review(s).")
