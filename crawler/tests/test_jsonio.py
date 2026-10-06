"""jsonio.write_json_atomic 测试。"""

import json
import os

from crawler.scripts.jsonio import write_json_atomic


def test_write_json_atomic_roundtrip(tmp_path):
    path = tmp_path / "state.json"
    write_json_atomic(str(path), {"a": 1, "中文": "值"}, ensure_ascii=False, indent=2)
    assert json.loads(path.read_text(encoding="utf-8")) == {"a": 1, "中文": "值"}


def test_write_json_atomic_overwrites(tmp_path):
    path = tmp_path / "state.json"
    path.write_text("old", encoding="utf-8")
    write_json_atomic(str(path), [1, 2, 3])
    assert json.loads(path.read_text(encoding="utf-8")) == [1, 2, 3]


def test_write_json_atomic_no_leftover_temp(tmp_path):
    path = tmp_path / "state.json"
    write_json_atomic(str(path), {"x": 1})
    assert [p for p in os.listdir(tmp_path) if p.startswith(".tmp-")] == []
