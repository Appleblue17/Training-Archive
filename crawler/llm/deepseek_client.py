#!/usr/bin/env python3
"""DeepSeek API 客户端（OpenAI 兼容接口）。

供 report.py（完整复盘报告）使用。
- call_deepseek()：单次对话补全，调用方传入 prompt / api_key / system_message / temperature
- 模块导入时自动：加载仓库根 .env（不覆盖已有环境变量）+ 归一化代理 URL
"""
import os

from dotenv import load_dotenv

# 本地开发：从仓库根 .env 加载凭据（CI 无 .env，静默跳过；不覆盖已有环境变量）
load_dotenv()

def normalize_proxy_env():
    """归一化代理环境变量，避免 httpx / OpenAI 客户端构造失败。

    - httpx（openai 底层）只认 socks5://，不认 socks://；clash 等代理工具导出的
      ALL_PROXY 常为 "socks://127.0.0.1:7890"，否则客户端构造报
      "Unknown scheme for proxy URL"。
    - NO_PROXY / no_proxy 里形如 [::1] 的带括号 IPv6 会被 httpx 当成 URL 解析，
      在端口处抛 "InvalidURL: Invalid port ':1]'"，直接导致 OpenAI 客户端无法创建
      （部分发行版 / 容器会同时导出 ::1,[::1]）。统一去掉方括号。
    """
    for proxy_var in (
        "ALL_PROXY",
        "all_proxy",
        "HTTP_PROXY",
        "http_proxy",
        "HTTPS_PROXY",
        "https_proxy",
    ):
        value = os.environ.get(proxy_var, "")
        if value.startswith("socks://"):
            os.environ[proxy_var] = "socks5://" + value[len("socks://") :]
    for no_proxy_var in ("NO_PROXY", "no_proxy"):
        value = os.environ.get(no_proxy_var)
        if value and ("[" in value or "]" in value):
            os.environ[no_proxy_var] = value.replace("[", "").replace("]", "")


normalize_proxy_env()

BASE_URL = "https://api.deepseek.com"
MODEL = "deepseek-chat"

# 完整复盘报告默认 system prompt
DEFAULT_SYSTEM_MESSAGE = (
    "你是算法竞赛复盘助手，输出结构清晰的中文 Markdown 报告。"
)


def call_deepseek(prompt, api_key, system_message=None, temperature=0.3):
    """调用 DeepSeek 单次对话补全，返回模型输出文本。

    system_message 缺省时使用 DEFAULT_SYSTEM_MESSAGE（复盘助手）。
    """
    from openai import OpenAI

    if system_message is None:
        system_message = DEFAULT_SYSTEM_MESSAGE
    client = OpenAI(api_key=api_key, base_url=BASE_URL)
    resp = client.chat.completions.create(
        model=MODEL,
        messages=[
            {"role": "system", "content": system_message},
            {"role": "user", "content": prompt},
        ],
        temperature=temperature,
    )
    return resp.choices[0].message.content
