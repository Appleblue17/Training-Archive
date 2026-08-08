#!/usr/bin/env python3
"""只爬取最近提交的测试脚本（不推进 last-update，不污染正式增量状态）。

用法：
    python3 crawler/fetch_recent.py --platform qoj --days 30
    python3 crawler/fetch_recent.py --all --days 7

说明：
    - 把增量基准 last_update_time 设为 now - N 天，只抓最近 N 天的提交；
      QOJ/HDU/NowCoder 的提交列表均按时间降序遍历，到达时间界限即停止。
    - 不读取 / 不推进 crawler/last-update.json；不调用 finish()。
    - 环境变量：QOJ_USERNAME / QOJ_PASSWORD（QOJ 登录用，见 crawler/qoj/qoj.py）。
"""
import argparse
import os
import sys
from datetime import datetime, timedelta, timezone

sys.path.append(os.path.abspath(os.path.dirname(__file__)))

import scheduled_task

beijing = timezone(timedelta(hours=8))
PLATFORM_ORDER = scheduled_task.PLATFORM_ORDER


def run_platform_recent(platform, days):
    crawler = scheduled_task.crawler_for(platform)
    try:
        # QOJ / NowCoder 需要先登录；HDU 由其内部流程自行登录
        if platform in ("qoj", "nowcoder"):
            crawler.login()

        # 增量基准：now - days（仅本次运行生效，不落盘）
        crawler.last_update_time = datetime.now(beijing) - timedelta(days=days)

        # 加载 contests 与 staged（与 fetch_submissions() 一致）
        crawler.contests = crawler._load_file(crawler.contests_path)
        crawler.staged_submissions = crawler._load_file(crawler.submissions_path)

        # 先尝试更新 staged 提交（与正式流程一致）
        crawler.log("info", "Start updating staged submissions...")
        new_staged = []
        for entry in crawler.staged_submissions:
            if not crawler._update_submission_status(entry):
                new_staged.append(entry)
        crawler.staged_submissions = new_staged
        crawler._write_file(crawler.submissions_path, crawler.staged_submissions)

        # 抓取最近提交（到达时间界限即停止）
        crawler.log("info", f"Start fetching recent submissions (last {days} days)...")
        crawler.fetch_submissions_get_submissions()
        print(f"[fetch_recent] {platform}: done.")
    except Exception as e:
        print(f"[fetch_recent] {platform} failed: {e}")
    finally:
        # 不调用 finish()（不推进 last-update）；仅关闭浏览器驱动
        try:
            crawler.deinit_driver()
        except Exception as e:
            print(f"[fetch_recent] {platform} deinit failed: {e}")


def main():
    parser = argparse.ArgumentParser(
        description="只爬取最近提交（测试用，不推进 last-update）"
    )
    parser.add_argument(
        "--platform",
        choices=list(PLATFORM_ORDER) + ["all"],
        default="qoj",
        help="平台：qoj / hdu / nowcoder / all（默认 qoj）",
    )
    parser.add_argument(
        "--days",
        type=int,
        default=30,
        help="只抓最近 N 天的提交（默认 30）",
    )
    args = parser.parse_args()

    platforms = PLATFORM_ORDER if args.platform == "all" else [args.platform]

    for platform in platforms:
        run_platform_recent(platform, args.days)


if __name__ == "__main__":
    main()
