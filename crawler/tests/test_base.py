"""crawler/platforms/base.py 纯逻辑单元测试。

不实例化 BaseCrawler（其 __init__ 会启动 Chrome）；用 __new__ 构造裸对象，
只设置被测方法需要的最小属性。
"""

import json
import os
from datetime import datetime, timedelta, timezone

import pytest

from crawler.platforms import base


def make_crawler(**attrs):
    """构造不启动 driver 的 BaseCrawler 裸对象。"""
    c = base.BaseCrawler.__new__(base.BaseCrawler)
    c.platform_name = "qoj"
    c.log = lambda *a, **k: None
    c._new_contests = {}
    c._contests_only = False
    c._submissions_fetch_complete = False
    for k, v in attrs.items():
        setattr(c, k, v)
    return c


# ---------------------------------------------------------------------------
# load_subscriptions_dir
# ---------------------------------------------------------------------------
def _write(path, data):
    with open(path, "w", encoding="utf-8") as f:
        json.dump(data, f)


def test_load_subscriptions_missing_dir(tmp_path):
    logs = []
    assert base.load_subscriptions_dir(str(tmp_path / "nope"), log=lambda l, m: logs.append((l, m))) == []
    assert logs and logs[0][0] == "warning"


def test_load_subscriptions_merges_sorted_and_skips_non_json(tmp_path):
    _write(tmp_path / "b.json", [{"platform": "qoj", "link": "https://qoj.ac/contest/2"}])
    _write(tmp_path / "a.json", [{"platform": "qoj", "link": "https://qoj.ac/contest/1"}])
    (tmp_path / "notes.txt").write_text("[]", encoding="utf-8")
    (tmp_path / "sample.example.json").write_text(
        '[{"platform": "qoj", "link": "https://qoj.ac/contest/EXAMPLE"}]', encoding="utf-8"
    )
    subs = base.load_subscriptions_dir(str(tmp_path))
    assert [s["link"] for s in subs] == [
        "https://qoj.ac/contest/1",
        "https://qoj.ac/contest/2",
    ]


def test_load_subscriptions_dedup_normalizes_trailing_slash(tmp_path):
    _write(tmp_path / "a.json", [{"platform": "qoj", "link": "https://qoj.ac/contest/1/"}])
    _write(tmp_path / "b.json", [{"platform": "qoj", "link": "https://qoj.ac/contest/1"}])
    logs = []
    subs = base.load_subscriptions_dir(str(tmp_path), log=lambda l, m: logs.append((l, m)))
    assert len(subs) == 1
    assert any(l == "warning" and "Duplicate" in m for l, m in logs)


def test_load_subscriptions_platform_filter_and_enabled(tmp_path):
    _write(tmp_path / "a.json", [
        {"platform": "qoj", "link": "https://qoj.ac/contest/1"},
        {"platform": "qoj", "link": "https://qoj.ac/contest/2", "enabled": False},
        {"platform": "hdu", "link": "https://acm.hdu.edu.cn/contest/3"},
        {"link": "https://qoj.ac/contest/4"},
    ])
    qoj = base.load_subscriptions_dir(str(tmp_path), platform="qoj")
    assert [s["link"] for s in qoj] == ["https://qoj.ac/contest/1"]
    # platform=None 返回全部（含 enabled:false 与缺 platform）
    assert len(base.load_subscriptions_dir(str(tmp_path))) == 4


def test_load_subscriptions_bad_files_are_skipped(tmp_path):
    (tmp_path / "bad.json").write_text("{not json", encoding="utf-8")
    _write(tmp_path / "notlist.json", {"link": "x"})
    _write(tmp_path / "nlink.json", [{"platform": "qoj"}])
    logs = []
    subs = base.load_subscriptions_dir(str(tmp_path), log=lambda l, m: logs.append((l, m)))
    assert subs == []
    levels = [l for l, _ in logs]
    assert "error" in levels  # bad.json
    assert "warning" in levels  # notlist / no link


# ---------------------------------------------------------------------------
# BaseCrawler 纯方法
# ---------------------------------------------------------------------------
@pytest.mark.parametrize("language,expected", [
    ("C++", "cpp"),
    ("C++17", "cpp"),
    ("GCC", "cpp"),
    ("GNU G++17", "cpp"),
    ("Go", "go"),
    ("Java", "java"),
    ("Kotlin", "kt"),
    ("Pascal", "pas"),
    ("Python3", "py"),
    ("Rust", "rs"),
    ("C", "c"),
    ("D", "d"),
    ("Brainfuck", "txt"),
])
def test_get_extension_name(language, expected):
    assert make_crawler()._get_extension_name(language) == expected


def test_convert_to_beijing_time_naive_and_aware():
    c = make_crawler()
    naive = datetime(2026, 1, 1, 12, 0, 0)
    assert c._convert_to_beijing_time(naive).utcoffset() == timedelta(hours=8)
    aware = datetime(2026, 1, 1, 4, 0, 0, tzinfo=timezone.utc)
    assert c._convert_to_beijing_time(aware).hour == 12


def test_convert_iso_to_beijing_handles_z():
    c = make_crawler()
    assert c._convert_iso_to_beijing("2026-01-01T00:00:00Z").isoformat() ==         "2026-01-01T08:00:00+08:00"
    # naive 按北京墙钟解释
    assert c._convert_iso_to_beijing("2026-01-01T00:00:00").isoformat() ==         "2026-01-01T00:00:00+08:00"


def test_clean_pandoc_markdown_basic():
    c = make_crawler()
    md = (
        "::: {.katex-display}\n"
        "[[$\\frac{a}{b}$]{.katex-mathml}]{.katex}\n"
        ":::\n\n\n\n"
    )
    out = c._clean_pandoc_markdown(md)
    assert "\\frac{a}{b}" in out
    assert "katex" not in out
    assert "\n\n\n" not in out


@pytest.mark.parametrize("link,expected", [
    ("https://acm.hdu.edu.cn/contest/problem?cid=123&pid=1006", "1006"),
    ("https://ac.nowcoder.com/acm/contest/1/problem?pid=42", "42"),
    ("https://qoj.ac/problem/123", "123"),
    ("https://qoj.ac/problem/123/", "123"),
    ("https://qoj.ac/problem/abc", None),
    ("", None),
    (None, None),
])
def test_problem_id_from_link(link, expected):
    assert make_crawler()._problem_id_from_link(link) == expected


def test_deadline_for_returns_contest_start_only_for_new_contest():
    c = make_crawler()
    c._new_contests = {"https://qoj.ac/contest/1": "2026-01-01T10:00:00+08:00"}
    got = c._deadline_for("https://qoj.ac/contest/1")
    assert got is not None and got.hour == 10
    assert c._deadline_for("https://qoj.ac/contest/2") is None


def test_deadline_for_invalid_start_time_falls_back_to_none():
    c = make_crawler()
    c._new_contests = {"https://qoj.ac/contest/1": "not-a-time"}
    assert c._deadline_for("https://qoj.ac/contest/1") is None


def test_contests_only_deadline_uses_earliest_start():
    c = make_crawler()
    c._contests_only = True
    c._new_contests = {
        "a": "2026-01-01T10:00:00+08:00",
        "b": "2026-01-01T08:00:00+08:00",
    }
    assert c._contests_only_deadline().hour == 8
    c._contests_only = False
    assert c._contests_only_deadline() is None


# ---------------------------------------------------------------------------
# finish() / last-update 水位
# ---------------------------------------------------------------------------
def test_finish_does_not_advance_when_incomplete(tmp_path):
    c = make_crawler()
    c.deinit_driver = lambda: None
    lu = tmp_path / "last-update.json"
    lu.write_text("{}", encoding="utf-8")
    c.last_update_path = str(lu)
    c._submissions_fetch_complete = False
    c.finish()
    assert json.loads(lu.read_text(encoding="utf-8")) == {}


def test_finish_advances_to_fetch_start_time(tmp_path):
    """回归：last-update 必须写抓取开始时间，而非抓取结束时间。

    用结束时间会漏掉"抓取期间新产生、但下一次抓取开始时已早于水位"的提交。
    """
    c = make_crawler()
    c.deinit_driver = lambda: None
    lu = tmp_path / "last-update.json"
    lu.write_text("{}", encoding="utf-8")
    c.last_update_path = str(lu)
    c._submissions_fetch_complete = True
    start = datetime(2026, 1, 1, 10, 0, 0, tzinfo=base.beijing)
    c._fetch_started_at = start
    c.finish()
    assert json.loads(lu.read_text(encoding="utf-8"))["qoj"] == start.isoformat()


def test_finish_never_regresses_watermark(tmp_path):
    """水位单调不回退：开始时间早于已存水位时保留较晚的旧水位。"""
    c = make_crawler()
    c.deinit_driver = lambda: None
    lu = tmp_path / "last-update.json"
    later = datetime(2026, 1, 2, 10, 0, 0, tzinfo=base.beijing)
    lu.write_text(json.dumps({"qoj": later.isoformat()}), encoding="utf-8")
    c.last_update_path = str(lu)
    c._submissions_fetch_complete = True
    c._fetch_started_at = datetime(2026, 1, 1, tzinfo=base.beijing)
    c.finish()
    assert json.loads(lu.read_text(encoding="utf-8"))["qoj"] == later.isoformat()


def test_finish_contests_only_never_advances(tmp_path):
    c = make_crawler()
    c.deinit_driver = lambda: None
    lu = tmp_path / "last-update.json"
    lu.write_text("{}", encoding="utf-8")
    c.last_update_path = str(lu)
    c._submissions_fetch_complete = True
    c._contests_only = True
    c._fetch_started_at = datetime(2026, 1, 1, tzinfo=base.beijing)
    c.finish()
    assert json.loads(lu.read_text(encoding="utf-8")) == {}


def test_fetch_submissions_records_start_time(tmp_path):
    c = make_crawler()
    c.last_update_path = str(tmp_path / "last-update.json")
    c.submissions_path = str(tmp_path / "staged.json")
    c.contests_path = str(tmp_path / "contests.json")
    c._load_contests_with_times = lambda: []
    c.fetch_submissions_get_submissions = lambda: None
    before = datetime.now(base.beijing)
    c.fetch_submissions()
    after = datetime.now(base.beijing)
    assert before <= c._fetch_started_at <= after


def test_fetch_submissions_mid_fetch_exception_invalidates_completeness(tmp_path):
    """回归：某场比赛抓取中抛异常时，即使更早的比赛已标记完成，
    本次也不得推进 last-update（否则失败比赛的提交会被永久跳过）。"""
    c = make_crawler()
    c.last_update_path = str(tmp_path / "last-update.json")
    c.submissions_path = str(tmp_path / "staged.json")
    c.contests_path = str(tmp_path / "contests.json")
    c._load_contests_with_times = lambda: []

    def partial_then_raise():
        c._mark_submissions_complete()  # 模拟第一场成功
        raise RuntimeError("second contest blew up")

    c.fetch_submissions_get_submissions = partial_then_raise
    with pytest.raises(RuntimeError):
        c.fetch_submissions()
    assert c._submissions_fetch_complete is False
