#!/usr/bin/env python3
"""爬虫任务入口（任务A：预订比赛抓取+复盘；任务B：提交记录周期同步）。

任务A（默认）：
    某场预订的比赛结束后 → 抓取整场比赛数据 → 立即生成复盘报告。
    实现：fetch_contests（抓订阅的、已开始的比赛）+ fetch_submissions（增量同步提交，
    含 staged 映射）+ report.generate_reviews_for_all（对已结束且缺 review.md 的比赛生成报告）。
    幂等：比赛目录存在即跳过抓取；review.md 存在即跳过报告。

任务B（--submissions-only）：
    每天一次对所有已开始/进行中的比赛做增量提交抓取（沿用 last-update.json）。

用法：
    python3 crawler/scheduled_task.py               # 任务A（GitHub Actions 每 15~30 分钟）
    python3 crawler/scheduled_task.py --submissions-only  # 任务B（每天一次）
"""
import importlib
import os
import sys

import report

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..")))

PLATFORM_ORDER = ("qoj", "hdu", "nowcoder")

# platform -> (crawler module name, crawler class name)
PLATFORM_CLASSES = {
    "qoj": ("crawler.qoj.qoj", "QOJCrawler"),
    "hdu": ("crawler.hdu.hdu", "HDUCrawler"),
    "nowcoder": ("crawler.nowcoder.nowcoder", "NOWCODERCrawler"),
}


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

    ok_platforms = []
    for platform in PLATFORM_ORDER:
        ok, crawler = run_platform(platform, submissions_only)
        if ok:
            ok_platforms.append(platform)
        else:
            print(f"[task] Platform {platform} did not complete successfully.")

    if not ok_platforms:
        print("[task] All platforms failed. Exiting with error.")
        sys.exit(1)

    # 任务A：对所有已结束且缺 review.md 的比赛生成复盘报告
    if not submissions_only:
        count = report.generate_reviews_for_all()
        print(f"[task] Generated {count} review(s).")

    print(f"[task] Completed platforms: {', '.join(ok_platforms)}")


if __name__ == "__main__":
    main()
