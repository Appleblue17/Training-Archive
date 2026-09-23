"""crawler/scripts/qq_share.py 单元测试。"""

import json

import pytest

from crawler.scripts import qq_share as qs


# ---------------------------------------------------------------------------
# clean_for_qq / _strip_code_fence
# ---------------------------------------------------------------------------
def test_clean_for_qq_escapes_cq_brackets():
    assert qs.clean_for_qq("a[b]c") == "a&#91;b&#93;c"


def test_clean_for_qq_strips_markdown():
    text = "**粗** *斜* ~~删~~ `行内`\n# 标题\n```\ncode\n```"
    out = qs.clean_for_qq(text)
    assert "**" not in out and "~~" not in out and "`" not in out
    assert "粗" in out and "行内" in out and "标题" in out
    assert "code" not in out


def test_strip_code_fence():
    assert qs._strip_code_fence("```markdown\nhello\n```") == "hello"
    assert qs._strip_code_fence("plain") == "plain"
    assert qs._strip_code_fence("```only-fence") == ""


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
    # 简写布尔形式
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
# CLI main()
# ---------------------------------------------------------------------------
def test_main_empty_links_does_not_scan_all(monkeypatch, capsys):
    """回归：--links 为空不得退化为全量扫描（可能群发全部比赛）。"""
    called = []
    monkeypatch.setattr(qs, "send_contest_shares_for_all",
                        lambda **k: called.append("all") or 0)
    assert qs.main(["--links", ""]) == 1
    assert called == []


def test_main_links(monkeypatch):
    monkeypatch.setattr(qs, "send_contest_shares_for_links", lambda links, **k: 2)
    assert qs.main(["--links", "https://qoj.ac/contest/1"]) == 0
