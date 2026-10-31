"""crawler/scripts/report.py 单元测试。"""

import json
import os
from datetime import datetime, timedelta, timezone

import pytest

from crawler.scripts import report

beijing = timezone(timedelta(hours=8))


def _make_contest(tmp_path, *, end_time="2026-01-01T12:00:00+08:00",
                  submissions=None, review=None, name="Test Contest"):
    folder = tmp_path / "contests" / f"2026-01-01 {name}"
    folder.mkdir(parents=True)
    contest = {
        "name": name,
        "date": "2026-01-01",
        "platform": "qoj",
        "start_time": "2026-01-01T08:00:00+08:00",
        "link": "https://qoj.ac/contest/1",
    }
    if end_time is not None:
        contest["end_time"] = end_time
    (folder / "contest.json").write_text(json.dumps(contest), encoding="utf-8")
    if submissions is not None:
        (folder / "submissions.json").write_text(json.dumps(submissions), encoding="utf-8")
    if review is not None:
        (folder / "review.md").write_text(review, encoding="utf-8")
    return folder


# ---------------------------------------------------------------------------
# _problem_id_from_link
# ---------------------------------------------------------------------------
@pytest.mark.parametrize("link,expected", [
    ("https://acm.hdu.edu.cn/contest/problem?cid=1&pid=1006", "1006"),
    ("https://qoj.ac/problem/123", "123"),
    ("https://qoj.ac/problem/123/", "123"),
    ("nope", None),
    ("", None),
    (None, None),
])
def test_problem_id_from_link(link, expected):
    assert report._problem_id_from_link(link) == expected


# ---------------------------------------------------------------------------
# _filter_submissions_before_end
# ---------------------------------------------------------------------------
def test_filter_submissions_no_end_time_keeps_all():
    subs = [{"submit_time": "2030-01-01T00:00:00+08:00"}]
    assert report._filter_submissions_before_end(subs, {}) == subs


def test_filter_submissions_drops_post_contest():
    subs = [
        {"submit_time": "2026-01-01T09:00:00+08:00"},
        {"submit_time": "2026-01-01T13:00:00+08:00"},
    ]
    out = report._filter_submissions_before_end(
        subs, {"end_time": "2026-01-01T12:00:00+08:00"})
    assert out == [subs[0]]


def test_filter_submissions_keeps_unparseable():
    subs = [{"submit_time": None}, {"submit_time": "garbage"}, {}]
    out = report._filter_submissions_before_end(
        subs, {"end_time": "2026-01-01T12:00:00+08:00"})
    assert len(out) == 3


# ---------------------------------------------------------------------------
# _build_submissions_block / _build_problems_block
# ---------------------------------------------------------------------------
def _sub(sid, status="AC"):
    return {"submission_id": sid, "status": status, "language": "C++",
            "submit_time": "2026-01-01T09:00:00+08:00"}


def test_build_submissions_block_includes_source_when_budget_allows():
    block = report._build_submissions_block(
        [_sub("1")], {"A": {"1": "int main(){}"}}, lambda s: "A", 100000)
    assert "int main(){}" in block
    assert "源码因长度限制省略" not in block


def test_build_submissions_block_omits_source_when_budget_tight():
    block = report._build_submissions_block(
        [_sub("1")], {"A": {"1": "x" * 5000}}, lambda s: "A", 200)
    assert "x" * 100 not in block
    assert "源码" in block


def test_build_submissions_block_empty():
    assert "无提交数据" in report._build_submissions_block([], {}, lambda s: "A", 100)


def test_build_problems_block_reads_statement_and_drops_dup_title(tmp_path):
    folder = tmp_path / "c"
    pdir = folder / "problems" / "A"
    pdir.mkdir(parents=True)
    (pdir / "problem.json").write_text(json.dumps(
        {"name": "Sum", "link": "https://qoj.ac/problem/1", "time_limit": "1s",
         "solved": True, "solve_time": "10min"}), encoding="utf-8")
    (pdir / "statement.md").write_text(
        "## A. Sum\n\n求 a+b。", encoding="utf-8")
    block = report._build_problems_block(
        {"A": json.loads((pdir / "problem.json").read_text(encoding="utf-8"))}, str(folder))
    assert "### A. Sum" in block
    assert "求 a+b。" in block
    # 原始 statement 首行 "## A. Sum" 应被丢弃（只保留生成的 "### A. Sum"）
    assert "\n## A. Sum" not in block
    assert "solved: 是" in block


def test_build_problems_block_empty():
    assert "无题目数据" in report._build_problems_block({}, "/tmp/none")


# ---------------------------------------------------------------------------
# build_prompt
# ---------------------------------------------------------------------------
def test_build_prompt_replaces_placeholders(tmp_path, monkeypatch):
    monkeypatch.setattr(report, "TEMPLATE_PATH", str(tmp_path / "nope.md"))
    folder = _make_contest(tmp_path, submissions=[_sub("1")])
    pdir = folder / "problems" / "A"
    pdir.mkdir(parents=True)
    (pdir / "problem.json").write_text(json.dumps(
        {"name": "Sum", "link": "https://qoj.ac/problem/1"}), encoding="utf-8")
    prompt = report.build_prompt(str(folder))
    assert "{{contest_info}}" not in prompt
    assert "{{problems}}" not in prompt
    assert "{{submissions}}" not in prompt
    assert "Test Contest" in prompt
    assert "#1" in prompt


# ---------------------------------------------------------------------------
# generate_review
# ---------------------------------------------------------------------------
def test_generate_review_skips_existing(tmp_path):
    folder = _make_contest(tmp_path, submissions=[_sub("1")], review="old")
    assert report.generate_review(str(folder)) == "skipped"


def test_generate_review_requires_api_key(tmp_path, monkeypatch):
    monkeypatch.delenv("DEEPSEEK_API_KEY", raising=False)
    folder = _make_contest(tmp_path, submissions=[_sub("1")])
    assert report.generate_review(str(folder)) == "failed"
    assert not (folder / "review.md").exists()


def test_generate_review_skips_no_submissions(tmp_path, monkeypatch):
    monkeypatch.setenv("DEEPSEEK_API_KEY", "k")
    folder = _make_contest(tmp_path, submissions=[])
    assert report.generate_review(str(folder)) == "skipped"


def test_generate_review_skips_future_contest(tmp_path, monkeypatch):
    monkeypatch.setenv("DEEPSEEK_API_KEY", "k")
    future = (datetime.now(beijing) + timedelta(days=1)).isoformat()
    folder = _make_contest(tmp_path, end_time=future, submissions=[_sub("1")])
    assert report.generate_review(str(folder)) == "skipped"


def test_generate_review_skips_missing_end_time(tmp_path, monkeypatch):
    monkeypatch.setenv("DEEPSEEK_API_KEY", "k")
    folder = _make_contest(tmp_path, end_time=None, submissions=[_sub("1")])
    assert report.generate_review(str(folder)) == "skipped"


@pytest.mark.parametrize("bad_content", [None, "", "   "])
def test_generate_review_empty_llm_output_is_failure(tmp_path, monkeypatch, bad_content):
    """回归：空/None 输出不得写 0 字节 review.md（否则永久被跳过）。"""
    monkeypatch.setenv("DEEPSEEK_API_KEY", "k")
    monkeypatch.setattr(report, "call_deepseek", lambda *a, **k: bad_content)
    folder = _make_contest(tmp_path, submissions=[_sub("1")])
    assert report.generate_review(str(folder)) == "failed"
    assert not (folder / "review.md").exists()


def test_generate_review_writes_file(tmp_path, monkeypatch):
    monkeypatch.setenv("DEEPSEEK_API_KEY", "k")
    monkeypatch.setattr(report, "call_deepseek", lambda *a, **k: "# 复盘\n内容")
    folder = _make_contest(tmp_path, submissions=[_sub("1")])
    assert report.generate_review(str(folder)) == "generated"
    assert (folder / "review.md").read_text(encoding="utf-8") == "# 复盘\n内容"


def test_generate_review_deepseek_exception_is_failure(tmp_path, monkeypatch):
    monkeypatch.setenv("DEEPSEEK_API_KEY", "k")
    def boom(*a, **k):
        raise RuntimeError("api down")
    monkeypatch.setattr(report, "call_deepseek", boom)
    folder = _make_contest(tmp_path, submissions=[_sub("1")])
    assert report.generate_review(str(folder)) == "failed"
    assert not (folder / "review.md").exists()


# ---------------------------------------------------------------------------
# CLI main()
# ---------------------------------------------------------------------------
def test_main_empty_links_arg_fails_without_full_scan(tmp_path, monkeypatch):
    """回归：--links 存在但为空不得退化为全量扫描。"""
    called = []
    monkeypatch.setattr(report, "generate_reviews_for_all",
                        lambda *a, **k: called.append("all") or (0, 0))
    assert report.main(["--links", ""]) == 1
    assert called == []


def test_main_links_calls_generate_for_links(monkeypatch):
    monkeypatch.setattr(report, "generate_reviews_for_links",
                        lambda links, **k: (1, 0))
    assert report.main(["--links", "https://qoj.ac/contest/1"]) == 0


def test_main_links_reports_failure(monkeypatch):
    monkeypatch.setattr(report, "generate_reviews_for_links", lambda links, **k: (0, 1))
    assert report.main(["--links", "https://qoj.ac/contest/1"]) == 1


def test_main_no_args_full_scan(monkeypatch):
    monkeypatch.setattr(report, "generate_reviews_for_all", lambda **k: (2, 0))
    assert report.main([]) == 0


def test_main_from_crawl(monkeypatch):
    monkeypatch.setattr(report, "load_new_contests", lambda: ["contests/a", "contests/b"])
    monkeypatch.setattr(report, "generate_review", lambda f: "generated")
    assert report.main(["--from-crawl"]) == 0
