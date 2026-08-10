#!/usr/bin/env python3
"""本次爬取新建比赛列表的读写（scheduled_task.py 写入，report.py / qq_share.py 读取）。

任务A（crawler/scripts/scheduled_task.py）结束时把本次新建的比赛文件夹写入
crawler/new-contests.json（临时状态文件，gitignore）；report.py / qq_share.py
以 --from-crawl 读取该文件，只对这些比赛生成报告，而不是扫描全部比赛。
"""

import json
import os

# 本次爬取新建的比赛列表（scheduled_task.py 任务A 写入；--from-crawl 读取）。
# 状态文件固定位于仓库根 crawler/ 下：本模块在 crawler/scripts/，上溯两级到仓库根。
NEW_CONTESTS_PATH = os.path.join(
    os.path.dirname(os.path.abspath(__file__)),
    "..",
    "..",
    "crawler",
    "new-contests.json",
)


def load_new_contests():
    """读取 crawler/new-contests.json，返回本次爬取新建的比赛文件夹列表。

    文件缺失 / 解析失败 / 非列表时返回 []（调用方据此安全地跳过）。
    """
    if not os.path.exists(NEW_CONTESTS_PATH):
        print(f"[new-contests] {NEW_CONTESTS_PATH} not found, nothing to do.")
        return []
    try:
        with open(NEW_CONTESTS_PATH, "r", encoding="utf-8") as f:
            folders = json.load(f)
    except Exception as e:
        print(
            f"[new-contests] Failed to read {NEW_CONTESTS_PATH}: {e}; nothing to do."
        )
        return []
    if not isinstance(folders, list):
        print(f"[new-contests] {NEW_CONTESTS_PATH} is not a list; nothing to do.")
        return []
    return folders
