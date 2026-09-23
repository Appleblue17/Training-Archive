"""crawler/scripts/daemon.py 单元测试：plan 解析、调度判断、分支守卫。"""

import os
from datetime import datetime, timedelta

import pytest

from crawler.platforms.base import beijing
from crawler.scripts import daemon


# ---------------------------------------------------------------------------
# _parse_plan_output
# ---------------------------------------------------------------------------
def test_parse_plan_output():
    out = (
        "HISTORY\thttps://qoj.ac/contest/1\n"
        "EXPIRED\thttps://qoj.ac/contest/2\n"
        "RETRY\thttps://qoj.ac/contest/3\thttps://qoj.ac/contest/3\n"
        "[alarm] plan: 1 history, 1 expired, 1 retry\n"
    )
    history, expired, retry = daemon._parse_plan_output(out)
    assert history == ["https://qoj.ac/contest/1"]
    assert expired == ["https://qoj.ac/contest/2"]
    assert retry == [("https://qoj.ac/contest/3", "https://qoj.ac/contest/3")]


def test_parse_plan_output_retry_without_end_time():
    _, _, retry = daemon._parse_plan_output("RETRY\thttps://qoj.ac/contest/1\t\n")
    assert retry == [("https://qoj.ac/contest/1", "")]


# ---------------------------------------------------------------------------
# _remind_minutes_left / _fmt_remind_time
# ---------------------------------------------------------------------------
def test_remind_minutes_left_rounds_up_min_one():
    now = datetime(2026, 1, 1, 10, 0, tzinfo=beijing)
    assert daemon._remind_minutes_left("2026-01-01T10:12:00+08:00", now) == 12
    assert daemon._remind_minutes_left("2026-01-01T10:00:10+08:00", now) == 1


def test_remind_minutes_left_invalid():
    now = datetime(2026, 1, 1, 10, 0, tzinfo=beijing)
    assert daemon._remind_minutes_left(None, now) is None
    assert daemon._remind_minutes_left("garbage", now) is None


def test_fmt_remind_time():
    now = datetime(2026, 1, 1, 10, 0, tzinfo=beijing)
    assert daemon._fmt_remind_time("2026-01-01T18:00:00+08:00", now) == "今天 18:00"
    assert daemon._fmt_remind_time("2026-01-02T18:00:00+08:00", now) == "明天 18:00"
    assert daemon._fmt_remind_time("2026-02-03T18:00:00+08:00", now) == "02-03 18:00"
    assert daemon._fmt_remind_time("garbage", now) == "garbage"


# ---------------------------------------------------------------------------
# _is_due
# ---------------------------------------------------------------------------
def test_is_due_first_run():
    assert daemon._is_due("fire", "*/5 * * * *", datetime.now(beijing), {"last_run": {}})


def test_is_due_bad_last_run_does_not_raise():
    """回归：损坏的 last_run（非字符串）不得让 daemon 主循环崩溃。"""
    state = {"last_run": {"fire": 123}}
    assert daemon._is_due("fire", "*/5 * * * *", datetime.now(beijing), state) is True


def test_is_due_respects_schedule():
    now = datetime(2026, 1, 1, 10, 2, tzinfo=beijing)
    state = {"last_run": {"fire": "2026-01-01T10:00:00+08:00"}}
    assert daemon._is_due("fire", "*/5 * * * *", now, state) is False
    state = {"last_run": {"fire": "2026-01-01T09:00:00+08:00"}}
    assert daemon._is_due("fire", "*/5 * * * *", now, state) is True


# ---------------------------------------------------------------------------
# ensure_deploy_branch
# ---------------------------------------------------------------------------
class _Result:
    def __init__(self, returncode=0, stdout=""):
        self.returncode = returncode
        self.stdout = stdout


@pytest.fixture()
def git_env(tmp_path, monkeypatch):
    monkeypatch.setattr(daemon, "REPO_ROOT", str(tmp_path))
    monkeypatch.setattr(os, "chdir", lambda p: None)

    def fake_git(*args, check=True):
        fake_git.calls.append(args)
        return fake_git.responses.get(args, _Result(0))

    fake_git.responses = {}
    fake_git.calls = []
    monkeypatch.setattr(daemon, "git", fake_git)
    return fake_git


def test_ensure_deploy_branch_success(git_env):
    git_env.responses[("checkout", "deploy")] = _Result(0)
    git_env.responses[("pull", "--ff-only", "origin", "deploy")] = _Result(0)
    daemon.ensure_deploy_branch()
    assert ("checkout", "deploy") in git_env.calls


def test_ensure_deploy_branch_missing_branch_aborts(git_env):
    git_env.responses[("rev-parse", "--verify", "deploy")] = _Result(1)
    with pytest.raises(SystemExit):
        daemon.ensure_deploy_branch()


def test_ensure_deploy_branch_checkout_failure_aborts(git_env):
    """回归：checkout 失败（如脏工作区）不得静默继续，否则会在错误分支上提交。"""
    git_env.responses[("checkout", "deploy")] = _Result(1)
    with pytest.raises(SystemExit):
        daemon.ensure_deploy_branch()
