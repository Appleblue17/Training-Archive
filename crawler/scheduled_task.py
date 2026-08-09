#!/usr/bin/env python3
"""爬虫任务入口（任务A：预订比赛抓取；任务B：提交记录周期同步）。

任务A（默认）：
    某场预订的比赛结束后 → 抓取整场比赛数据 → 增量同步提交（含 staged 映射）。
    幂等：比赛目录存在即跳过抓取。

任务B（--submissions-only）：
    每天一次对所有已开始/进行中的比赛做增量提交抓取（沿用 last-update.json）。

复盘报告由独立脚本生成，不在此入口内调用：
    python3 crawler/report.py                   # 扫描所有已结束且缺 review.md 的比赛
    python3 crawler/report.py <contest_folder>  # 只生成指定比赛

平台启用/禁用：
    crawler/config.json 中每个平台条目可用 "enabled" 字段控制（缺省 false 视为禁用）：
        { "qoj": { "enabled": true, ... }, "hdu": { "enabled": false, ... } }
    显式 enabled: true 的平台才会被执行；配置文件缺失 / 解析失败时全部平台禁用。

用法：
    python3 crawler/scheduled_task.py               # 任务A（GitHub Actions 每 15~30 分钟）
    python3 crawler/scheduled_task.py --submissions-only  # 任务B（每天一次）
"""
import importlib
import json
import os
import sys

from dotenv import load_dotenv

# 本地开发：从仓库根 .env 加载凭据（CI 无 .env，静默跳过；不覆盖已有环境变量）
load_dotenv()

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

PLATFORM_ORDER = ("qoj", "hdu", "nowcoder")

# platform -> (crawler module name, crawler class name)
PLATFORM_CLASSES = {
    "qoj": ("crawler.qoj.qoj", "QOJCrawler"),
    "hdu": ("crawler.hdu.hdu", "HDUCrawler"),
    "nowcoder": ("crawler.nowcoder.nowcoder", "NOWCODERCrawler"),
}

CONFIG_PATH = "crawler/config.json"


def _load_enabled_platforms():
    """从 crawler/config.json 读取启用的平台。

    每个平台条目可用 "enabled" 字段控制（默认禁用）；
    配置文件缺失 / 解析失败时全部平台禁用。
    """
    if not os.path.exists(CONFIG_PATH):
        return []
    try:
        with open(CONFIG_PATH, "r", encoding="utf-8") as f:
            config = json.load(f)
    except Exception as e:
        print(f"[task] Failed to parse {CONFIG_PATH}: {e}; All platforms disabled.")
        return []
    return [p for p in PLATFORM_ORDER if config.get(p, {}).get("enabled", False)]


def crawler_for(platform):
    module_path, class_name = PLATFORM_CLASSES[platform]
    module = importlib.import_module(module_path)
    return getattr(module, class_name)()


def run_platform(platform, submissions_only):
    """运行单个平台的爬虫。返回 (ok, crawler)。异常被捕获记录，不阻断其他平台。"""
    crawler = crawler_for(platform)
    ok = False
    try:
        # HDU 的 login 签名不同（login(link)），由其内部流程自行登录；
        # QOJ / NowCoder 需要先登录。
        if not submissions_only:
            if platform in ("qoj", "nowcoder"):
                crawler.login()
            crawler.fetch_contests()
            crawler.fetch_submissions()
        else:
            if platform in ("qoj", "nowcoder"):
                crawler.login()
            crawler.fetch_submissions()
        ok = True
    except Exception as e:
        print(f"[task] {platform} failed: {e}")
    finally:
        # finish() 内部 deinit_driver()，且仅在提交抓取完整时推进 last-update
        try:
            crawler.finish()
        except Exception as e:
            print(f"[task] {platform} finish failed: {e}")
    return ok, crawler


def main():
    submissions_only = "--submissions-only" in sys.argv[1:]

    enabled_platforms = _load_enabled_platforms()
    print(f"[task] Enabled platforms: {', '.join(enabled_platforms)}")

    ok_platforms = []
    for platform in enabled_platforms:
        ok, crawler = run_platform(platform, submissions_only)
        if ok:
            ok_platforms.append(platform)
        else:
            print(f"[task] Platform {platform} did not complete successfully.")

    if not ok_platforms:
        print("[task] All platforms failed. Exiting with error.")
        sys.exit(1)

    print(f"[task] Completed platforms: {', '.join(ok_platforms)}")


if __name__ == "__main__":
    main()
