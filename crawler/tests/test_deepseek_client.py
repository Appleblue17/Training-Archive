"""deepseek_client 的代理环境变量归一化测试。"""

import os

from crawler.llm.deepseek_client import normalize_proxy_env


def test_normalize_socks_and_bracketed_ipv6(monkeypatch):
    monkeypatch.setenv("ALL_PROXY", "socks://127.0.0.1:7890")
    monkeypatch.setenv("NO_PROXY", "localhost,::1,[::1]")
    normalize_proxy_env()
    assert os.environ["ALL_PROXY"] == "socks5://127.0.0.1:7890"
    assert os.environ["NO_PROXY"] == "localhost,::1,::1"


def test_normalize_leaves_plain_values(monkeypatch):
    monkeypatch.setenv("HTTPS_PROXY", "http://127.0.0.1:7890")
    monkeypatch.setenv("NO_PROXY", "localhost,127.0.0.1")
    normalize_proxy_env()
    assert os.environ["HTTPS_PROXY"] == "http://127.0.0.1:7890"
    assert os.environ["NO_PROXY"] == "localhost,127.0.0.1"
