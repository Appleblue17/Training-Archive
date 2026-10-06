#!/usr/bin/env python3
"""JSON 原子写入工具。

daemon-state.json / alarms.json 等运行时状态文件原先是「直接以 'w' 打开再写」，
断电或进程在写入中途被杀会留下截断的 JSON（state 可自愈但会丢上次调度时间；
alarms 损坏则 plan 直接中止）。改为「同目录临时文件 + os.replace」原子替换：
任意时刻磁盘上的文件要么是旧完整内容、要么是新完整内容。
"""
import json
import os
import tempfile


def write_json_atomic(path, data, **dump_kwargs):
    """把 data 以 JSON 原子写入 path（同目录临时文件 + os.replace）。"""
    directory = os.path.dirname(os.path.abspath(path)) or "."
    os.makedirs(directory, exist_ok=True)
    fd, tmp = tempfile.mkstemp(prefix=".tmp-", suffix=".json", dir=directory)
    try:
        with os.fdopen(fd, "w", encoding="utf-8") as f:
            json.dump(data, f, **dump_kwargs)
            f.flush()
            os.fsync(f.fileno())
        os.replace(tmp, path)
    except BaseException:
        try:
            os.remove(tmp)
        except OSError:
            pass
        raise
