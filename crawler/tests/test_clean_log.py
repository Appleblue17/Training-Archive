"""crawler/scripts/clean-log.py 单元测试（文件名含连字符，按路径加载）。"""

import importlib.util
import json
import os

import pytest

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))


def _load_module():
    path = os.path.join(REPO_ROOT, "crawler", "scripts", "clean-log.py")
    spec = importlib.util.spec_from_file_location("crawler_clean_log", path)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


@pytest.fixture()
def mod():
    return _load_module()


def test_trims_to_keep_last_n(tmp_path, mod, capsys):
    path = tmp_path / "log.json"
    path.write_text(json.dumps(list(range(10))), encoding="utf-8")
    mod.clean_log_file(str(path), keep=3)
    assert json.loads(path.read_text(encoding="utf-8")) == [7, 8, 9]
    assert "Cleaned" in capsys.readouterr().out


def test_keeps_when_below_limit(tmp_path, mod, capsys):
    path = tmp_path / "log.json"
    path.write_text(json.dumps([1, 2]), encoding="utf-8")
    mod.clean_log_file(str(path), keep=5)
    assert json.loads(path.read_text(encoding="utf-8")) == [1, 2]
    assert "already" in capsys.readouterr().out


def test_non_list_is_untouched(tmp_path, mod, capsys):
    path = tmp_path / "log.json"
    path.write_text(json.dumps({"a": 1}), encoding="utf-8")
    mod.clean_log_file(str(path), keep=1)
    assert json.loads(path.read_text(encoding="utf-8")) == {"a": 1}
    assert "not a list" in capsys.readouterr().out


def test_missing_or_corrupt_does_not_raise(tmp_path, mod, capsys):
    mod.clean_log_file(str(tmp_path / "missing.json"))
    (tmp_path / "bad.json").write_text("{oops", encoding="utf-8")
    mod.clean_log_file(str(tmp_path / "bad.json"))
    assert "Error processing" in capsys.readouterr().out
