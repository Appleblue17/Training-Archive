#!/usr/bin/env python3
"""爬虫任务入口（按模式运行：比赛抓取 / 提交增量同步）。

默认模式（无参数）：
    某场预订的比赛结束后 → 抓取整场比赛数据。
    幂等：比赛目录存在即跳过抓取。

--contests-only（推荐给高频触发）：
    只检查订阅有没有触发（新建比赛）。有新建比赛时才回填这些比赛的
    提交记录；没有新建比赛则完全不碰提交，保持轻量。已有比赛的增量
    提交同步交给 --submissions-only。注意：--contests-only 不推进 last-update。

--submissions-only（提交增量模式）：
    每天一次对所有已开始/进行中的比赛做增量提交抓取（沿用 last-update.json）。

复盘报告由独立脚本生成，不在此入口内调用：
    python3 crawler/scripts/report.py --from-crawl    # 只对本次爬取新建的比赛生成（推荐）
    python3 crawler/scripts/report.py                 # 扫描所有已结束且缺 review.md 的比赛
    python3 crawler/scripts/report.py <contest_folder>  # 只生成指定比赛

比赛抓取模式（默认 / --contests-only）结束时会把本次新建的比赛文件夹列表写入
crawler/new-contests.json（临时状态文件，gitignore），report.py / qq_share.py
以 --from-crawl 读取该文件，只对这些比赛生成报告，而不是扫描全部比赛。

平台启用/禁用：
    crawler/config.json 中每个平台条目可用 "enabled" 字段控制（缺省 false 视为禁用）：
        { "qoj": { "enabled": true, ... }, "hdu": { "enabled": false, ... } }
    显式 enabled: true 的平台才会被执行；配置文件缺失 / 解析失败时全部平台禁用。

用法：
    python3 crawler/scripts/scheduled_task.py              # 默认：抓比赛 + 全量增量提交
    python3 crawler/scripts/scheduled_task.py --contests-only    # 只查订阅/新建比赛，有新建才回填其提交
    python3 crawler/scripts/scheduled_task.py --submissions-only # 提交增量模式（每天一次增量提交同步）
    python3 crawler/scripts/scheduled_task.py --contests-only --links "https://...,https://..."
        # 只抓指定订阅链接的比赛（服务器闹钟 fire / sync 补抓用）；与 --contests-only
        # 语义一致：新建比赛才回填其提交、不推进 last-update。不能与 --submissions-only 同用。
"""
import importlib
import json
import os
import sys

from dotenv import load_dotenv

# 本地开发：从仓库根 .env 加载凭据（CI 无 .env，静默跳过；不覆盖已有环境变量）
load_dotenv()

# 脚本位于 crawler/scripts/，仓库根为 ../../（使 crawler 包可导入）
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..")))

PLATFORM_ORDER = ("qoj", "hdu", "nowcoder")

# platform -> (crawler module name, crawler class name)
PLATFORM_CLASSES = {
    "qoj": ("crawler.platforms.qoj.qoj", "QOJCrawler"),
    "hdu": ("crawler.platforms.hdu.hdu", "HDUCrawler"),
    "nowcoder": ("crawler.platforms.nowcoder.nowcoder", "NOWCODERCrawler"),
}

CONFIG_PATH = "crawler/config.json"
NEW_CONTESTS_PATH = "crawler/new-contests.json"


def _write_new_contests(crawlers):
    """把本次运行新建的比赛文件夹写入 new-contests.json，供 report.py --from-crawl 使用。

    - 有新建比赛：覆盖写入列表（去重保持顺序）
    - 无新建比赛：删除旧文件，避免 report.py --from-crawl 用上上次的陈旧列表
    """
    folders = []
    seen = set()
    for c in crawlers:
        for f in getattr(c, "_new_contest_folders", []):
            if f not in seen:
                seen.add(f)
                folders.append(f)

    if folders:
        with open(NEW_CONTESTS_PATH, "w", encoding="utf-8") as f:
            json.dump(folders, f, ensure_ascii=False, indent=2)
        print(f"[task] New contests recorded for report: {folders}")
    else:
        if os.path.exists(NEW_CONTESTS_PATH):
            os.remove(NEW_CONTESTS_PATH)
            print(f"[task] No new contests; removed {NEW_CONTESTS_PATH}.")


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


def run_platform(platform, mode, only_links=None):
    """运行单个平台的爬虫。返回 (ok, crawler)。异常被捕获记录，不阻断其他平台。

    mode:
        "full"         默认：抓比赛 + 全量增量提交同步
        "contests"     --contests-only：只抓订阅的新比赛；有新建才回填其提交
        "submissions"  --submissions-only（提交增量）：只做增量提交同步
    only_links: 只抓指定订阅链接（--links，服务器闹钟/历史补抓用）。
                为 None 时抓全部订阅。
    """
    crawler = crawler_for(platform)
    crawler._only_links = only_links
    ok = False
    try:
        # HDU 的 login 签名不同（login(link)），由其内部流程自行登录；
        # QOJ / NowCoder 需要先登录。
        if platform in ("qoj", "nowcoder"):
            crawler.login()

        if mode == "submissions":
            crawler.fetch_submissions()
        else:
            crawler.fetch_contests()
            if mode == "full":
                crawler.fetch_submissions()
            elif crawler._new_contests:
                # contests-only：订阅触发（新建了比赛）才回填对应提交记录；
                # 没有新建比赛时完全不碰提交，保持轻量。不推进 last-update。
                crawler._contests_only = True
                crawler.fetch_submissions()
        ok = True
    except Exception as e:
        print(f"[task] {platform} failed: {e}")
    finally:
        # finish() 内部 deinit_driver()，且仅在提交抓取完整时推进 last-update
        # （contests-only 模式始终不推进，见 BaseCrawler.finish）
        try:
            crawler.finish()
        except Exception as e:
            print(f"[task] {platform} finish failed: {e}")
    return ok, crawler


def main():
    args = sys.argv[1:]
    submissions_only = "--submissions-only" in args
    contests_only = "--contests-only" in args
    if submissions_only and contests_only:
        print(
            "[task] --contests-only and --submissions-only are mutually exclusive; "
            "exiting."
        )
        sys.exit(1)

    # --links "link1,link2"：只抓指定订阅链接（服务器闹钟/历史补抓用）。
    # 仅对比赛抓取有意义；与 --submissions-only（纯提交增量）互斥。
    only_links = None
    if "--links" in args:
        idx = args.index("--links")
        if idx + 1 >= len(args):
            print("[task] --links requires a comma-separated list of links; exiting.")
            sys.exit(1)
        if submissions_only:
            print("[task] --links cannot be combined with --submissions-only; exiting.")
            sys.exit(1)
        only_links = {
            l.strip().rstrip("/")
            for l in args[idx + 1].split(",")
            if l.strip()
        }
        if not only_links:
            print("[task] --links list is empty; exiting.")
            sys.exit(1)
        print(f"[task] Only fetching links: {sorted(only_links)}")

    mode = (
        "contests"
        if contests_only
        else ("submissions" if submissions_only else "full")
    )

    enabled_platforms = _load_enabled_platforms()
    print(f"[task] Enabled platforms: {', '.join(enabled_platforms)}")

    ok_platforms = []
    ok_crawlers = []
    for platform in enabled_platforms:
        ok, crawler = run_platform(platform, mode, only_links=only_links)
        if ok:
            ok_platforms.append(platform)
            ok_crawlers.append(crawler)
        else:
            print(f"[task] Platform {platform} did not complete successfully.")

    if not ok_platforms:
        print("[task] All platforms failed. Exiting with error.")
        sys.exit(1)

    # 记录本次新建的比赛，供 report.py --from-crawl 只生成这些
    # （提交增量模式仅增量同步，不新建比赛，不写文件）
    if mode != "submissions":
        _write_new_contests(ok_crawlers)

    print(f"[task] Completed platforms: {', '.join(ok_platforms)}")


if __name__ == "__main__":
    main()
