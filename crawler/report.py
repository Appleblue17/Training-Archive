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
import sys
from datetime import datetime

# 北京时间（UTC+8）
from datetime import timezone, timedelta

beijing = timezone(timedelta(hours=8))

BASE_URL = "https://api.deepseek.com"
MODEL = "deepseek-chat"

# 提示词安全上限：超出后仅保留较新提交的源码，旧提交只留元数据，
# 避免请求体超过模型上下文限制（DeepSeek 上下文 64K tokens）。
MAX_PROMPT_CHARS = 240_000


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


def build_prompt(contest_folder):
    contest = load_json(os.path.join(contest_folder, "contest.json")) or {}
    submissions = load_json(os.path.join(contest_folder, "submissions.json")) or []
    problems_map = _problem_letter_map(contest_folder)

    # 提交 -> 题目字母：优先按 link 匹配，其次按 name 匹配
    letter_by_link = {}
    letter_by_name = {}
    for letter, entry in problems_map.items():
        if entry.get("link"):
            letter_by_link[entry["link"].rstrip("/")] = letter
        if entry.get("name"):
            letter_by_name[entry["name"]] = letter

    def letter_for(sub):
        link = (sub.get("problem_link") or "").rstrip("/")
        if link in letter_by_link:
            return letter_by_link[link]
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

    lines = []
    lines.append("你是一名经验丰富的算法竞赛教练。请根据以下比赛数据撰写一份中文复盘报告。")
    lines.append("")
    lines.append("## 比赛信息")
    lines.append(f"- 名称：{contest.get('name', '?')}")
    lines.append(f"- 日期：{contest.get('date', '?')}")
    lines.append(f"- 平台：{contest.get('platform', '?')}")
    if contest.get("link"):
        lines.append(f"- 链接：{contest['link']}")
    if contest.get("start_time"):
        lines.append(f"- 开始：{contest['start_time']}")
    if contest.get("end_time"):
        lines.append(f"- 结束：{contest['end_time']}")

    lines.append("")
    lines.append("## 题目列表")
    if problems_map:
        for letter in sorted(problems_map):
            entry = problems_map[letter]
            lines.append(f"- {letter}. {entry.get('name', '?')}")
            if entry.get("link"):
                lines.append(f"  link: {entry['link']}")
            if entry.get("time_limit"):
                lines.append(f"  time_limit: {entry['time_limit']}")
            if entry.get("memory_limit"):
                lines.append(f"  memory_limit: {entry['memory_limit']}")
    else:
        lines.append("（无题目数据）")

    lines.append("")
    lines.append("## 提交记录（按时间升序，含每份源码）")
    if not submissions_sorted:
        lines.append("（无提交数据）")
    else:
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
            if used + meta_len > MAX_PROMPT_CHARS:
                sub_lines.append("（源码因长度限制省略）")
                sub_lines.append("```")
                lines.extend(sub_lines)
                break
            sub_lines.append("```")
            letter = letter_for(sub)
            code = source_by_letter.get(letter, {}).get(
                str(sub.get("submission_id"))
            ) or ""
            if used + meta_len + len(code) > MAX_PROMPT_CHARS and code:
                # 源码超限：截断为最近提交保留摘要
                keep = MAX_PROMPT_CHARS - used - meta_len - 40
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

    lines.append("")
    lines.append("## 要求")
    lines.append(
        "请输出 Markdown 格式的复盘报告，包含：1) 总体表现总结；2) 每道题的分析"
        "（AC 时间线、WA/失败次数、关键转折点）；3) 失误与改进建议。"
    )
    lines.append(
        "报告开头用一级标题，标题为比赛名称。不要复述完整代码，只引用关键片段。"
    )

    return "\n".join(lines)


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
