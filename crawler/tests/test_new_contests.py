"""crawler/scripts/new_contests.py 单元测试。"""

import json

import pytest

from crawler.scripts import new_contests as nc


def test_missing_file_returns_empty(tmp_path, monkeypatch, capsys):
    monkeypatch.setattr(nc, "NEW_CONTESTS_PATH", str(tmp_path / "missing.json"))
    assert nc.load_new_contests() == []
    assert "not found" in capsys.readouterr().out


def test_valid_list_roundtrip(tmp_path, monkeypatch):
    path = tmp_path / "new.json"
    path.write_text(json.dumps(["contests/a", "contests/b"]), encoding="utf-8")
    monkeypatch.setattr(nc, "NEW_CONTESTS_PATH", str(path))
    assert nc.load_new_contests() == ["contests/a", "contests/b"]


def test_non_list_returns_empty(tmp_path, monkeypatch, capsys):
    path = tmp_path / "new.json"
    path.write_text(json.dumps({"a": 1}), encoding="utf-8")
    monkeypatch.setattr(nc, "NEW_CONTESTS_PATH", str(path))
    assert nc.load_new_contests() == []
    assert "not a list" in capsys.readouterr().out


def test_corrupt_returns_empty(tmp_path, monkeypatch, capsys):
    path = tmp_path / "new.json"
    path.write_text("{broken", encoding="utf-8")
    monkeypatch.setattr(nc, "NEW_CONTESTS_PATH", str(path))
    assert nc.load_new_contests() == []
    assert "Failed to read" in capsys.readouterr().out
