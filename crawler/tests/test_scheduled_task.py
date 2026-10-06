"""crawler/scripts/scheduled_task.py 单元测试。"""

import json

import pytest

from crawler.scripts import scheduled_task as st


# ---------------------------------------------------------------------------
# _load_enabled_platforms
# ---------------------------------------------------------------------------
def test_load_enabled_platforms_missing(tmp_path, monkeypatch):
    monkeypatch.setattr(st, "CONFIG_PATH", str(tmp_path / "nope.json"))
    assert st._load_enabled_platforms() == []


def test_load_enabled_platforms_filters(tmp_path, monkeypatch):
    cfg = tmp_path / "config.json"
    cfg.write_text(json.dumps({
        "qoj": {"enabled": True},
        "hdu": {"enabled": False},
        "nowcoder": {},
    }), encoding="utf-8")
    monkeypatch.setattr(st, "CONFIG_PATH", str(cfg))
    assert st._load_enabled_platforms() == ["qoj"]


def test_load_enabled_platforms_corrupt(tmp_path, monkeypatch):
    cfg = tmp_path / "config.json"
    cfg.write_text("{broken", encoding="utf-8")
    monkeypatch.setattr(st, "CONFIG_PATH", str(cfg))
    assert st._load_enabled_platforms() == []


# ---------------------------------------------------------------------------
# _write_new_contests
# ---------------------------------------------------------------------------
class _C:
    def __init__(self, folders):
        self._new_contest_folders = folders


def test_write_new_contests_dedups_and_writes(tmp_path, monkeypatch):
    path = tmp_path / "new.json"
    monkeypatch.setattr(st, "NEW_CONTESTS_PATH", str(path))
    st._write_new_contests([_C(["a", "b"]), _C(["b", "c"])])
    assert json.loads(path.read_text(encoding="utf-8")) == ["a", "b", "c"]


def test_write_new_contests_removes_stale_file(tmp_path, monkeypatch):
    path = tmp_path / "new.json"
    path.write_text(json.dumps(["old"]), encoding="utf-8")
    monkeypatch.setattr(st, "NEW_CONTESTS_PATH", str(path))
    st._write_new_contests([_C([])])
    assert not path.exists()


# ---------------------------------------------------------------------------
# run_platform
# ---------------------------------------------------------------------------
class FakeCrawler:
    def __init__(self, *, fail=None):
        self.fail = fail
        self._only_links = None
        self._new_contests = {}
        self._new_contest_folders = []
        self._contests_only = False
        self.calls = []
        self.finished = False

    def login(self):
        self.calls.append("login")

    def fetch_contests(self):
        self.calls.append("fetch_contests")
        if self.fail == "contests":
            raise RuntimeError("boom")

    def fetch_submissions(self):
        self.calls.append("fetch_submissions")

    def finish(self):
        self.calls.append("finish")
        self.finished = True


def test_run_platform_construction_failure_returns_not_ok(monkeypatch):
    """回归：crawler_for 构造失败不得抛出中断其余平台。"""
    def boom(platform):
        raise RuntimeError("no chromedriver")
    monkeypatch.setattr(st, "crawler_for", boom)
    ok, crawler = st.run_platform("qoj", "full")
    assert ok is False and crawler is None


def test_run_platform_success_full(monkeypatch):
    fake = FakeCrawler()
    monkeypatch.setattr(st, "crawler_for", lambda p: fake)
    ok, crawler = st.run_platform("qoj", "full", only_links={"x"})
    assert ok is True and crawler is fake
    assert fake.calls == ["login", "fetch_contests", "fetch_submissions", "finish"]
    assert fake._only_links == {"x"}


def test_run_platform_contests_only_skips_submissions_when_no_new(monkeypatch):
    fake = FakeCrawler()
    monkeypatch.setattr(st, "crawler_for", lambda p: fake)
    ok, _ = st.run_platform("qoj", "contests")
    assert ok is True
    assert "fetch_submissions" not in fake.calls


def test_run_platform_body_failure_still_finishes(monkeypatch):
    fake = FakeCrawler(fail="contests")
    monkeypatch.setattr(st, "crawler_for", lambda p: fake)
    ok, crawler = st.run_platform("qoj", "full")
    assert ok is False and crawler is fake
    assert fake.finished is True


def test_main_partial_failure_exits_nonzero(monkeypatch):
    """回归：部分平台失败时 main 必须返回非零。

    daemon sync/fire 只检查进程退出码就 mark --archived；若这里返回 0，
    失败平台未真正抓取的链接会被误标为已归档（不生成报告、不再重试）。
    """
    monkeypatch.setattr(st, "_load_enabled_platforms", lambda: ["qoj", "hdu"])
    monkeypatch.setattr(st, "run_platform",
                        lambda p, m, only_links=None: (p == "hdu", None))
    monkeypatch.setattr(st, "_write_new_contests", lambda crawlers: None)
    monkeypatch.setattr(st.sys, "argv", ["scheduled_task.py"])
    with pytest.raises(SystemExit) as ei:
        st.main()
    assert ei.value.code == 1
