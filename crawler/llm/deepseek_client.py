#!/usr/bin/env python3
"""DeepSeek API 客户端（OpenAI 兼容接口）。

供 report.py（完整复盘报告）与 qq_share.py（QQ 群分享简化版）共用。
- call_deepseek()：单次对话补全，调用方传入 prompt / api_key / system_message / temperature
- 模块导入时自动：加载仓库根 .env（不覆盖已有环境变量）+ 归一化代理 URL
"""
import os

from dotenv import load_dotenv

# 本地开发：从仓库根 .env 加载凭据（CI 无 .env，静默跳过；不覆盖已有环境变量）
load_dotenv()

# httpx（openai 底层）只认 socks5://，不认 socks://；clash 等代理工具导出的
# ALL_PROXY 常为 "socks://127.0.0.1:7890"，会导致 OpenAI 客户端构造时报
# "Unknown scheme for proxy URL"。统一归一化为 socks5://（socksio 已装）。
for _proxy_var in (
    "ALL_PROXY",
    "all_proxy",
    "HTTP_PROXY",
    "http_proxy",
    "HTTPS_PROXY",
    "https_proxy",
):
    _proxy_value = os.environ.get(_proxy_var, "")
    if _proxy_value.startswith("socks://"):
        os.environ[_proxy_var] = "socks5://" + _proxy_value[len("socks://") :]

BASE_URL = "https://api.deepseek.com"
MODEL = "deepseek-chat"

# 完整复盘报告默认 system prompt（qq-share 有自己专门的 system prompt）
DEFAULT_SYSTEM_MESSAGE = (
    "你是算法竞赛复盘助手，输出结构清晰的中文 Markdown 报告。"
)


def call_deepseek(prompt, api_key, system_message=None, temperature=0.3):
    """调用 DeepSeek 单次对话补全，返回模型输出文本。

    system_message 缺省时使用 DEFAULT_SYSTEM_MESSAGE（复盘助手）；
    qq_share.py 传入自己的氛围组 system prompt。
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
