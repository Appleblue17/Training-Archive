"""crawler/scripts/qq_bot.py 单元测试：指令匹配、消息解析、订阅新增。"""

import json
from datetime import datetime, timedelta, timezone

import pytest

from crawler.scripts import qq_bot as bot

beijing = timezone(timedelta(hours=8))


# ---------------------------------------------------------------------------
# _match_command
# ---------------------------------------------------------------------------
def test_match_slash_command_with_arg():
    fn, arg = bot._match_command("/subs add https://qoj.ac/contest/1")
    assert fn is bot.cmd_subs and arg == "add https://qoj.ac/contest/1"


def test_match_slash_command_case_insensitive():
    fn, arg = bot._match_command("/STATUS")
    assert fn is bot.cmd_status and arg == ""


def test_match_unknown_slash_command():
    assert bot._match_command("/nope") == (None, None)


def test_match_natural_language_basic():
    assert bot._match_command("状态")[0] is bot.cmd_status
    assert bot._match_command("最近比赛")[0] is bot.cmd_upcoming


def test_match_longest_keyword_wins():
    """回归：关键词按最长优先匹配，避免 '历史比赛' 命中更短的 '比赛'。"""
    assert bot._match_command("历史比赛")[0] is bot.cmd_contests
    assert bot._match_command("比赛列表")[0] is bot.cmd_contests
    assert bot._match_command("比赛")[0] is bot.cmd_upcoming


# ---------------------------------------------------------------------------
# _message_text_and_at
# ---------------------------------------------------------------------------
def test_message_text_and_at_segments():
    msg = {"message": [
        {"type": "text", "data": {"text": "  hi "}},
        {"type": "at", "data": {"qq": "123"}},
        {"type": "face", "data": {"id": 1}},
    ]}
    text, ats = bot._message_text_and_at(msg)
    assert text == "hi"
    assert ats == ["123"]


def test_message_text_and_at_cq_string_fallback():
    text, ats = bot._message_text_and_at({"message": "[CQ:at,qq=456] hello"})
    assert text == "hello"
    assert ats == ["456"]


# ---------------------------------------------------------------------------
# 展示辅助
# ---------------------------------------------------------------------------
def test_format_dt_relative_days():
    now = datetime(2026, 1, 1, 10, 0, tzinfo=beijing)
    assert bot._format_dt(datetime(2026, 1, 1, 18, 30, tzinfo=beijing), now) == "今天 18:30"
    assert bot._format_dt(datetime(2026, 1, 2, 9, 5, tzinfo=beijing), now) == "明天 09:05"
    assert bot._format_dt(datetime(2026, 1, 3, 9, 5, tzinfo=beijing), now) == "后天 09:05"
    assert bot._format_dt(datetime(2026, 2, 3, 9, 5, tzinfo=beijing), now) == "02-03 09:05"
    assert bot._format_dt(None, now) == "?"


def test_short_contest_name():
    assert bot._short_contest_name("2026-08-06 2026钉耙编程") == "2026钉耙编程"
    assert bot._short_contest_name("no-date") == "no-date"


@pytest.mark.parametrize("link,expected", [
    ("https://qoj.ac/contest/1", "qoj"),
    ("https://acm.hdu.edu.cn/contest/1", "hdu"),
    ("https://ac.nowcoder.com/acm/contest/1", "nowcoder"),
    ("https://example.com/contest/1", None),
    ("", None),
])
def test_infer_platform(link, expected):
    assert bot._infer_platform(link) == expected


# ---------------------------------------------------------------------------
# _subs_add
# ---------------------------------------------------------------------------
@pytest.fixture()
def subs_env(tmp_path, monkeypatch):
    subs_dir = tmp_path / "subs"
    subs_dir.mkdir()
    bot_subs = subs_dir / "qqbot.json"
    monkeypatch.setattr(bot, "SUBSCRIPTIONS_DIR", str(subs_dir))
    monkeypatch.setattr(bot, "BOT_SUBS_FILE", str(bot_subs))
    monkeypatch.setattr(bot, "_load_all_subscriptions", lambda: [])
    monkeypatch.setattr(bot, "_run_sync_and_report", lambda: None)
    return bot_subs


def test_subs_add_usage_without_args(subs_env):
    assert "用法" in bot._subs_add([])


def test_subs_add_rejects_non_url(subs_env):
    assert "http" in bot._subs_add(["not-a-url"])


def test_subs_add_writes_entry(subs_env):
    msg = bot._subs_add(["https://qoj.ac/contest/1", "end=2026-08-15T23:00:00+08:00", "备注"])
    assert "已添加订阅" in msg
    data = json.loads(subs_env.read_text(encoding="utf-8"))
    assert data[0]["link"] == "https://qoj.ac/contest/1"
    assert data[0]["platform"] == "qoj"
    assert data[0]["end_time"] == "2026-08-15T23:00:00+08:00"
    assert data[0]["comments"] == "备注"


def test_subs_add_bare_time_becomes_end(subs_env):
    bot._subs_add(["https://qoj.ac/contest/1", "2026-08-15T23:00:00+08:00"])
    data = json.loads(subs_env.read_text(encoding="utf-8"))
    assert data[0]["end_time"] == "2026-08-15T23:00:00+08:00"
    assert "comments" not in data[0]


def test_subs_add_bad_time_rejected(subs_env):
    msg = bot._subs_add(["https://qoj.ac/contest/1", "end=not-a-time"])
    assert "时间格式错误" in msg
    assert not subs_env.exists()


def test_subs_add_unknown_platform(subs_env):
    assert "无法推断平台" in bot._subs_add(["https://example.com/contest/1"])


def test_subs_add_duplicate(subs_env, monkeypatch):
    monkeypatch.setattr(bot, "_load_all_subscriptions",
                        lambda: [{"link": "https://qoj.ac/contest/1"}])
    assert "已存在该订阅" in bot._subs_add(["https://qoj.ac/contest/1"])


# ---------------------------------------------------------------------------
# _select_new_messages（同秒边界游标）
# ---------------------------------------------------------------------------
def _m(mid, time):
    return {"message_id": mid, "time": time, "user_id": "1"}


def test_select_new_messages_newer_than_cursor():
    msgs = [_m("1", 11), _m("2", 12)]
    new, last, seen = bot._select_new_messages(msgs, 10, [])
    assert [m["message_id"] for m in new] == ["1", "2"]
    assert last == 12
    assert seen == ["2"]  # 只保留新边界秒（12）的 id


def test_select_new_messages_same_second_boundary():
    """回归：同一秒内、游标之后到达的消息必须被补上。"""
    msgs = [_m("1", 10), _m("2", 10)]
    new, last, seen = bot._select_new_messages(msgs, 10, ["1"])
    assert [m["message_id"] for m in new] == ["2"]
    assert last == 10
    assert seen == ["1", "2"]


def test_select_new_messages_advance_resets_boundary_ids():
    msgs = [_m("3", 11)]
    new, last, seen = bot._select_new_messages(msgs, 10, ["1", "2"])
    assert [m["message_id"] for m in new] == ["3"]
    assert last == 11
    assert seen == ["3"]  # 旧边界秒的 id 不再保留


def test_select_new_messages_empty_id_boundary_skipped():
    msgs = [{"time": 10, "user_id": "1"}]
    new, last, seen = bot._select_new_messages(msgs, 10, [])
    assert new == []
    assert last == 10


def test_select_new_messages_none():
    new, last, seen = bot._select_new_messages([], 5, ["a"])
    assert new == []
    assert last == 5
    assert seen == ["a"]


def test_message_id_prefers_message_id_then_seq():
    assert bot._message_id({"message_id": 7}) == "7"
    assert bot._message_id({"message_seq": 8}) == "8"
    assert bot._message_id({}) == ""
