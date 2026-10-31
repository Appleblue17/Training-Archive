"""Chrome 启动参数（headless / root 沙箱）测试。"""

import os

from crawler.platforms import base


def _args(monkeypatch, root=False, headless=None, no_sandbox=None):
    monkeypatch.setattr(os, "geteuid", (lambda: 0) if root else (lambda: 1000), raising=False)
    if headless is None:
        monkeypatch.delenv("CHROME_HEADLESS", raising=False)
    else:
        monkeypatch.setenv("CHROME_HEADLESS", headless)
    if no_sandbox is None:
        monkeypatch.delenv("CHROME_NO_SANDBOX", raising=False)
    else:
        monkeypatch.setenv("CHROME_NO_SANDBOX", no_sandbox)
    return base._chrome_launch_args()


def test_headless_by_default(monkeypatch):
    assert "--headless" in _args(monkeypatch)


def test_headless_can_be_disabled(monkeypatch):
    assert "--headless" not in _args(monkeypatch, headless="0")


def test_root_adds_no_sandbox_and_dev_shm(monkeypatch):
    args = _args(monkeypatch, root=True)
    assert "--no-sandbox" in args
    assert "--disable-dev-shm-usage" in args


def test_non_root_has_no_no_sandbox(monkeypatch):
    assert "--no-sandbox" not in _args(monkeypatch, root=False)


def test_env_can_force_no_sandbox(monkeypatch):
    assert "--no-sandbox" in _args(monkeypatch, root=False, no_sandbox="1")
