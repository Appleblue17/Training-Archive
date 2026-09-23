"""crawler/scripts/qq_share.py 单元测试（v0.3.3 起：只发 review 文件）。"""

import json

import pytest

from crawler.scripts import qq_share as qs


# ---------------------------------------------------------------------------
# clean_for_qq
# ---------------------------------------------------------------------------
def test_clean_for_qq_escapes_cq_brackets():
    assert qs.clean_for_qq("a[b]c") == "a&#91;b&#93;c"


def test_clean_for_qq_strips_markdown():
    text = "**粗** *斜* ~~删~~ `行内`\n# 标题\n```\ncode\n```"
    out = qs.clean_for_qq(text)
    assert "**" not in out and "~~" not in out and "`" not in out
    assert "粗" in out and "行内" in out and "标题" in out
    assert "code" not in out


# ---------------------------------------------------------------------------
# build_review_file_name
# ---------------------------------------------------------------------------
def test_build_review_file_name_uses_date_and_name(tmp_path):
    folder = tmp_path / "c"
    folder.mkdir()
    (folder / "contest.json").write_text(json.dumps(
        {"date": "2026-08-06", "name": '2026钉耙/编程"联赛'}), encoding="utf-8")
    name = qs.build_review_file_name(str(folder))
    assert name == "2026-08-06_2026钉耙编程联赛_复盘.md"


def test_build_review_file_name_fallback(tmp_path):
    assert qs.build_review_file_name(str(tmp_path / "missing")) == "review.md"
    folder = tmp_path / "c"
    folder.mkdir()
    (folder / "contest.json").write_text(json.dumps({"name": ""}), encoding="utf-8")
    assert qs.build_review_file_name(str(folder)) == "review.md"


# ---------------------------------------------------------------------------
# ai_task_enabled / _load_env_qq
# ---------------------------------------------------------------------------
def test_ai_task_enabled(monkeypatch):
    monkeypatch.setattr(qs, "_load_config", lambda: {"ai_tasks": {"share": {"enabled": True}}})
    assert qs.ai_task_enabled("share") is True
    monkeypatch.setattr(qs, "_load_config", lambda: {"ai_tasks": {"share": {"enabled": False}}})
    assert qs.ai_task_enabled("share") is False
    monkeypatch.setattr(qs, "_load_config", lambda: {})
    assert qs.ai_task_enabled("share") is False
    monkeypatch.setattr(qs, "_load_config", lambda: {"ai_tasks": {"share": True}})
    assert qs.ai_task_enabled("share") is True


def test_load_env_qq(tmp_path, monkeypatch):
    env = tmp_path / ".env"
    env.write_text("QQ_NAPCAT_TOKEN=tok\nQQ_GROUP_ID=12345\n", encoding="utf-8")
    monkeypatch.setattr(qs, "ENV_PATH", str(env))
    assert qs._load_env_qq() == {"napcat_token": "tok", "group_id": 12345}


def test_load_env_qq_ignores_bad_group_id(tmp_path, monkeypatch, capsys):
    env = tmp_path / ".env"
    env.write_text("QQ_GROUP_ID=abc\n", encoding="utf-8")
    monkeypatch.setattr(qs, "ENV_PATH", str(env))
    assert qs._load_env_qq() == {}
    assert "QQ_GROUP_ID" in capsys.readouterr().out


# ---------------------------------------------------------------------------
# send_contest_share（只发文件 + 已发送标记）
# ---------------------------------------------------------------------------
class FakeSender:
    result = True
    last = None

    def __init__(self, ws_url, group_id, token=""):
        self.sent = []
        self.closed = False
        FakeSender.last = self

    def _connect(self):
        if self.connect_error:
            raise RuntimeError("connect refused")

    connect_error = False

    def _close(self):
        self.closed = True

    def send_file(self, file_path, file_name=None):
        self.sent.append((file_path, file_name))
        return self.result


def _make_contest(tmp_path, name="2026-01-01 x", review=True):
    folder = tmp_path / "contests" / name
    folder.mkdir(parents=True)
    if review:
        (folder / "review.md").write_text("# 复盘", encoding="utf-8")
    return folder


@pytest.fixture()
def send_env(tmp_path, monkeypatch):
    FakeSender.result = True
    FakeSender.last = None
    FakeSender.connect_error = False
    monkeypatch.setattr(qs, "QQGroupSender", FakeSender)
    monkeypatch.setattr(qs, "create_connection", lambda *a, **k: object())
    monkeypatch.setattr(qs, "_load_qq_config",
                        lambda: {"napcat_ws_url": "ws://x", "group_id": 123})
    return tmp_path


def test_send_contest_share_missing_review_skips(send_env):
    folder = _make_contest(send_env, review=False)
    assert qs.send_contest_share(str(folder)) is False
    assert FakeSender.last is None


def test_send_contest_share_already_sent_skips(send_env):
    folder = _make_contest(send_env)
    qs._mark_sent(str(folder))
    assert qs.send_contest_share(str(folder)) is False
    assert FakeSender.last is None


def test_send_contest_share_unconfigured_napcat_skips(send_env, monkeypatch):
    monkeypatch.setattr(qs, "_load_qq_config", lambda: {})
    folder = _make_contest(send_env)
    assert qs.send_contest_share(str(folder)) is False
    assert not qs._is_sent(str(folder))


def test_send_contest_share_success_marks_sent(send_env):
    folder = _make_contest(send_env)
    assert qs.send_contest_share(str(folder)) is True
    assert qs._is_sent(str(folder))
    assert FakeSender.last.sent and FakeSender.last.sent[0][0].endswith("review.md")
    assert FakeSender.last.closed is True


def test_send_contest_share_file_failure_not_marked(send_env):
    FakeSender.result = False
    folder = _make_contest(send_env)
    assert qs.send_contest_share(str(folder)) is False
    assert not qs._is_sent(str(folder))


def test_send_contest_share_connect_failure_not_marked(send_env):
    FakeSender.connect_error = True
    folder = _make_contest(send_env)
    assert qs.send_contest_share(str(folder)) is False
    assert not qs._is_sent(str(folder))


# ---------------------------------------------------------------------------
# 入口选择逻辑
# ---------------------------------------------------------------------------
def test_send_for_all_skips_sent_and_missing_review(tmp_path, monkeypatch):
    sent_names = []
    monkeypatch.setattr(qs, "send_contest_share",
                        lambda folder: sent_names.append(folder) or True)
    _make_contest(tmp_path, "a")
    marked = _make_contest(tmp_path, "b")
    qs._mark_sent(str(marked))
    _make_contest(tmp_path, "c", review=False)
    n = qs.send_contest_shares_for_all(contests_root=str(tmp_path / "contests"))
    assert n == 1
    assert sent_names == [str(tmp_path / "contests" / "a")]


def test_send_for_links_filters_by_link(tmp_path, monkeypatch):
    sent = []
    monkeypatch.setattr(qs, "send_contest_share", lambda folder: sent.append(folder) or True)
    root = tmp_path / "contests"
    for name, link in [("a", "https://qoj.ac/contest/1"), ("b", "https://qoj.ac/contest/2")]:
        folder = root / name
        folder.mkdir(parents=True)
        (folder / "contest.json").write_text(json.dumps({"link": link}), encoding="utf-8")
    n = qs.send_contest_shares_for_links({"https://qoj.ac/contest/2"}, contests_root=str(root))
    assert n == 1
    assert sent == [str(root / "b")]


def test_send_from_crawl(monkeypatch):
    monkeypatch.setattr(qs, "load_new_contests", lambda: ["f1", "f2"])
    monkeypatch.setattr(qs, "send_contest_share", lambda folder: folder == "f2")
    assert qs.send_contest_shares_from_crawl() == 1


# ---------------------------------------------------------------------------
# CLI main()
# ---------------------------------------------------------------------------
def test_main_empty_links_does_not_scan_all(monkeypatch):
    called = []
    monkeypatch.setattr(qs, "send_contest_shares_for_all",
                        lambda **k: called.append("all") or 0)
    assert qs.main(["--links", ""]) == 1
    assert called == []


def test_main_links(monkeypatch):
    monkeypatch.setattr(qs, "send_contest_shares_for_links", lambda links, **k: 2)
    assert qs.main(["--links", "https://qoj.ac/contest/1"]) == 0


def test_main_single_folder(monkeypatch):
    seen = []
    monkeypatch.setattr(qs, "send_contest_share", lambda folder: seen.append(folder))
    assert qs.main(["contests/x"]) == 0
    assert seen == ["contests/x"]
