"""crawler/scripts/daemon.py 单元测试：plan 解析、调度判断、分支守卫。"""

import json
import os
import subprocess
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


def test_is_due_non_dict_last_run_does_not_raise():
    """回归：last_run 本身不是 dict 时，查询也不能抛 AttributeError。"""
    state = {"last_run": 123}
    assert daemon._is_due("fire", "*/5 * * * *", datetime.now(beijing), state) is True


def test_load_state_normalizes_malformed_last_run(tmp_path, monkeypatch):
    f = tmp_path / "daemon-state.json"
    f.write_text(json.dumps({"last_run": 123}), encoding="utf-8")
    monkeypatch.setattr(daemon, "STATE_FILE", str(f))
    assert daemon.load_state()["last_run"] == {}


# ---------------------------------------------------------------------------
# 子进程编码（Windows 中文区域默认 cp936，中文输出/路径会解码失败）
# ---------------------------------------------------------------------------
def test_git_forces_utf8_decoding(monkeypatch):
    captured = {}

    def fake_run(cmd, **kwargs):
        captured.update(kwargs)
        return subprocess.CompletedProcess(cmd, 0, "", "")

    monkeypatch.setattr(daemon.subprocess, "run", fake_run)
    daemon.git("status")
    assert captured["encoding"] == "utf-8"
    assert captured["errors"] == "replace"


def test_run_py_forces_utf8_encoding(monkeypatch):
    captured = {}

    def fake_run(cmd, **kwargs):
        captured.update(kwargs)
        return subprocess.CompletedProcess(cmd, 0, "", "")

    monkeypatch.setattr(daemon.subprocess, "run", fake_run)
    daemon.run_py("alarm.py", "due", capture=True)
    assert captured["encoding"] == "utf-8"
    assert captured["env"]["PYTHONIOENCODING"] == "utf-8"


# ---------------------------------------------------------------------------
# daemon.log 轮转
# ---------------------------------------------------------------------------
def test_log_rotates_when_exceeding_max(tmp_path, monkeypatch):
    log_file = tmp_path / "daemon.log"
    backup = tmp_path / "daemon.log.1"
    monkeypatch.setattr(daemon, "LOG_FILE", str(log_file))
    monkeypatch.setattr(daemon, "LOG_BACKUP_FILE", str(backup))
    monkeypatch.setattr(daemon, "LOG_MAX_BYTES", 100)
    log_file.write_text("x" * 200, encoding="utf-8")
    daemon.log("hello")
    assert backup.exists() and backup.read_text(encoding="utf-8").startswith("x")
    assert "hello" in log_file.read_text(encoding="utf-8")
    assert log_file.stat().st_size < 200


def test_log_no_rotation_below_max(tmp_path, monkeypatch):
    log_file = tmp_path / "daemon.log"
    backup = tmp_path / "daemon.log.1"
    monkeypatch.setattr(daemon, "LOG_FILE", str(log_file))
    monkeypatch.setattr(daemon, "LOG_BACKUP_FILE", str(backup))
    monkeypatch.setattr(daemon, "LOG_MAX_BYTES", 10_000)
    daemon.log("hi")
    assert not backup.exists()
    assert "hi" in log_file.read_text(encoding="utf-8")


# ---------------------------------------------------------------------------
# install --xvfb 的 ExecStart 构造
# ---------------------------------------------------------------------------
def test_linux_exec_start_plain(monkeypatch):
    monkeypatch.setattr(daemon, "_service_command", lambda: ["/py", "/s.py", "run"])
    exec_start, problem = daemon._linux_exec_start(False)
    assert exec_start == "/py /s.py run"
    assert problem is None


def test_linux_exec_start_xvfb_wraps(monkeypatch):
    monkeypatch.setattr(daemon, "_service_command", lambda: ["/py", "/s.py", "run"])
    monkeypatch.setattr(
        daemon.shutil, "which",
        lambda name: "/usr/bin/xvfb-run" if name == "xvfb-run" else None,
    )
    exec_start, problem = daemon._linux_exec_start(True)
    assert exec_start == "/usr/bin/xvfb-run -a env CHROME_HEADLESS=0 /py /s.py run"
    assert problem is None


def test_linux_exec_start_xvfb_missing(monkeypatch):
    monkeypatch.setattr(daemon, "_service_command", lambda: ["/py", "/s.py", "run"])
    monkeypatch.setattr(daemon.shutil, "which", lambda name: None)
    exec_start, problem = daemon._linux_exec_start(True)
    assert exec_start == "/py /s.py run"
    assert "xvfb-run not found" in problem
