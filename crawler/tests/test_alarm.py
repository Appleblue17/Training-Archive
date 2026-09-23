"""crawler/scripts/alarm.py 单元测试：时间解析、状态迁移与 plan 分类。"""

import json
from datetime import datetime, timedelta, timezone

import pytest

from crawler.scripts import alarm

beijing = timezone(timedelta(hours=8))


def _past_iso(hours=1):
    return (datetime.now(beijing) - timedelta(hours=hours)).isoformat()


def _future_iso(hours=24):
    return (datetime.now(beijing) + timedelta(hours=hours)).isoformat()


@pytest.fixture()
def env(tmp_path, monkeypatch):
    """把 alarm 的路径常量指向 tmp，返回 (alarms_path, config_path, subs_dir)。"""
    alarms_path = tmp_path / "alarms.json"
    config_path = tmp_path / "config.json"
    subs_dir = tmp_path / "subs"
    subs_dir.mkdir()
    monkeypatch.setattr(alarm, "ALARMS_PATH", str(alarms_path))
    monkeypatch.setattr(alarm, "CONFIG_PATH", str(config_path))
    monkeypatch.setattr(alarm, "SUBSCRIPTIONS_DIR", str(subs_dir))
    return alarms_path, config_path, subs_dir


def _write_config(config_path, enabled=("qoj",)):
    config_path.write_text(json.dumps({p: {"enabled": True} for p in enabled}),
                           encoding="utf-8")


def _write_subs(subs_dir, entries):
    (subs_dir / "s.json").write_text(json.dumps(entries), encoding="utf-8")


def _write_alarms(alarms_path, entries):
    alarms_path.write_text(json.dumps(entries), encoding="utf-8")


def _read_alarms(alarms_path):
    return {e["link"]: e for e in json.loads(alarms_path.read_text(encoding="utf-8"))}


# ---------------------------------------------------------------------------
# 基础解析
# ---------------------------------------------------------------------------
@pytest.mark.parametrize("value,expected_hour", [
    ("2026-01-01T08:00:00", 8),
    ("2026-01-01T08:00:00+08:00", 8),
    ("2026-01-01T00:00:00Z", 8),
])
def test_parse_time(value, expected_hour):
    dt = alarm._parse_time(value)
    assert dt is not None and dt.hour == expected_hour and dt.utcoffset() == timedelta(hours=8)


@pytest.mark.parametrize("value", [None, "", "  ", "not-a-time", "2026-13-40T00:00:00"])
def test_parse_time_invalid(value):
    assert alarm._parse_time(value) is None


def test_has_time_value():
    assert not alarm._has_time_value(None)
    assert not alarm._has_time_value("")
    assert not alarm._has_time_value("   ")
    assert alarm._has_time_value("2026-01-01T00:00:00")


def test_effective_start_prefers_explicit_start():
    s = {"start_time": "2026-01-01T08:00:00+08:00",
         "end_time": "2026-01-01T13:00:00+08:00"}
    assert alarm._effective_start_time(s) == "2026-01-01T08:00:00+08:00"


def test_effective_start_falls_back_to_end_minus_5h():
    s = {"end_time": "2026-01-01T13:00:00+08:00"}
    assert alarm._effective_start_time(s) == "2026-01-01T08:00:00+08:00"


def test_effective_start_none_without_times():
    assert alarm._effective_start_time({}) is None


@pytest.mark.parametrize("old,expected", [
    ({"fired": True}, alarm.STATUS_ARCHIVED),
    ({"failed": True}, alarm.STATUS_FAILED),
    ({}, alarm.STATUS_PLANNED),
])
def test_migrate_alarm(old, expected):
    migrated = alarm._migrate_alarm(dict(old))
    assert migrated["status"] == expected
    assert "fired" not in migrated and "failed" not in migrated


def test_migrate_alarm_keeps_new_format():
    e = {"status": "planned", "link": "x"}
    assert alarm._migrate_alarm(e) is e


# ---------------------------------------------------------------------------
# _load_alarms
# ---------------------------------------------------------------------------
def test_load_alarms_missing_returns_empty(env):
    alarms_path, _, _ = env
    assert alarm._load_alarms() == {}


def test_load_alarms_corrupt_returns_none(env):
    alarms_path, _, _ = env
    alarms_path.write_text("{broken", encoding="utf-8")
    assert alarm._load_alarms() is None


def test_load_alarms_non_list_returns_none(env):
    alarms_path, _, _ = env
    alarms_path.write_text(json.dumps({"a": 1}), encoding="utf-8")
    assert alarm._load_alarms() is None


def test_load_alarms_dedups_by_link(env):
    alarms_path, _, _ = env
    _write_alarms(alarms_path, [{"link": "x", "status": "planned"},
                                {"link": "x", "status": "archived"}])
    assert alarm._load_alarms()["x"]["status"] == "archived"


# ---------------------------------------------------------------------------
# cmd_plan 分类
# ---------------------------------------------------------------------------
def test_plan_missing_config_aborts_and_keeps_alarms(env, capsys):
    """回归：config 缺失/损坏时不得把全部闹钟当空表剪除。"""
    alarms_path, config_path, subs_dir = env
    existing = [{"link": "https://qoj.ac/contest/1", "status": "archived",
                 "end_time": None, "start_time": None}]
    _write_alarms(alarms_path, existing)
    _write_subs(subs_dir, [{"platform": "qoj", "link": "https://qoj.ac/contest/1"}])
    # config.json 不存在
    assert alarm.cmd_plan() == 1
    assert _read_alarms(alarms_path)["https://qoj.ac/contest/1"]["status"] == "archived"


def test_plan_corrupt_config_aborts(env):
    alarms_path, config_path, subs_dir = env
    _write_alarms(alarms_path, [{"link": "https://qoj.ac/contest/1",
                                 "status": "archived"}])
    config_path.write_text("{broken", encoding="utf-8")
    assert alarm.cmd_plan() == 1
    assert "https://qoj.ac/contest/1" in _read_alarms(alarms_path)


def test_plan_history_classification(env, capsys):
    alarms_path, config_path, subs_dir = env
    _write_config(config_path)
    _write_subs(subs_dir, [{"platform": "qoj", "link": "https://qoj.ac/contest/1"}])
    assert alarm.cmd_plan() == 0
    out = capsys.readouterr().out
    assert "HISTORY\thttps://qoj.ac/contest/1" in out
    assert _read_alarms(alarms_path)["https://qoj.ac/contest/1"]["status"] == alarm.STATUS_PENDING


def test_plan_expired_classification(env, capsys):
    alarms_path, config_path, subs_dir = env
    _write_config(config_path)
    _write_subs(subs_dir, [{"platform": "qoj", "link": "https://qoj.ac/contest/1",
                            "end_time": _past_iso(2)}])
    assert alarm.cmd_plan() == 0
    assert "EXPIRED\thttps://qoj.ac/contest/1" in capsys.readouterr().out


def test_plan_future_writes_planned(env, capsys):
    alarms_path, config_path, subs_dir = env
    _write_config(config_path)
    end = _future_iso(24)
    _write_subs(subs_dir, [{"platform": "qoj", "link": "https://qoj.ac/contest/1",
                            "end_time": end}])
    assert alarm.cmd_plan() == 0
    out = capsys.readouterr().out
    assert "HISTORY\t" not in out and "EXPIRED\t" not in out
    entry = _read_alarms(alarms_path)["https://qoj.ac/contest/1"]
    assert entry["status"] == alarm.STATUS_PLANNED
    assert entry["fire_at"] == end


def test_plan_archived_unchanged_is_skipped(env, capsys):
    alarms_path, config_path, subs_dir = env
    _write_config(config_path)
    _write_subs(subs_dir, [{"platform": "qoj", "link": "https://qoj.ac/contest/1"}])
    _write_alarms(alarms_path, [{"link": "https://qoj.ac/contest/1",
                                 "status": alarm.STATUS_ARCHIVED,
                                 "end_time": None, "start_time": None}])
    assert alarm.cmd_plan() == 0
    assert "HISTORY\t" not in capsys.readouterr().out
    assert _read_alarms(alarms_path)["https://qoj.ac/contest/1"]["status"] == alarm.STATUS_ARCHIVED


def test_plan_failed_unchanged_emits_retry(env, capsys):
    alarms_path, config_path, subs_dir = env
    _write_config(config_path)
    end = _past_iso(2)
    sub = {"platform": "qoj", "link": "https://qoj.ac/contest/1", "end_time": end}
    _write_subs(subs_dir, [sub])
    _write_alarms(alarms_path, [{
        "link": "https://qoj.ac/contest/1", "status": alarm.STATUS_FAILED,
        "end_time": end, "start_time": alarm._effective_start_time(sub),
        "attempts": 1,
    }])
    assert alarm.cmd_plan() == 0
    out = capsys.readouterr().out
    assert f"RETRY\thttps://qoj.ac/contest/1\t{end}" in out
    # 保持 failed 不重置
    assert _read_alarms(alarms_path)["https://qoj.ac/contest/1"]["status"] == alarm.STATUS_FAILED


def test_plan_prunes_removed_subscriptions(env):
    alarms_path, config_path, subs_dir = env
    _write_config(config_path)
    _write_subs(subs_dir, [{"platform": "qoj", "link": "https://qoj.ac/contest/1"}])
    _write_alarms(alarms_path, [
        {"link": "https://qoj.ac/contest/1", "status": alarm.STATUS_ARCHIVED,
         "end_time": None, "start_time": None},
        {"link": "https://qoj.ac/contest/old", "status": alarm.STATUS_ARCHIVED},
    ])
    assert alarm.cmd_plan() == 0
    alarms = _read_alarms(alarms_path)
    assert "https://qoj.ac/contest/old" not in alarms


def test_plan_invalid_end_time_errors_and_preserves_alarm(env, capsys):
    alarms_path, config_path, subs_dir = env
    _write_config(config_path)
    _write_subs(subs_dir, [{"platform": "qoj", "link": "https://qoj.ac/contest/1",
                            "end_time": "not-a-time"}])
    _write_alarms(alarms_path, [{"link": "https://qoj.ac/contest/1",
                                 "status": alarm.STATUS_PLANNED,
                                 "end_time": None, "start_time": None}])
    assert alarm.cmd_plan() == 1
    assert "https://qoj.ac/contest/1" in _read_alarms(alarms_path)


def test_plan_platform_disabled(env, capsys):
    alarms_path, config_path, subs_dir = env
    _write_config(config_path, enabled=("hdu",))
    _write_subs(subs_dir, [{"platform": "qoj", "link": "https://qoj.ac/contest/1"}])
    assert alarm.cmd_plan() == 0
    assert "HISTORY\t" not in capsys.readouterr().out
