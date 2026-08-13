#!/usr/bin/env python3
"""daemon.py — 跨平台守护进程（v0.3.0 起替代 crawler/server-task.sh）

在服务器或个人电脑上持续运行，按 crawler/config.json 的 scheduled 块
（cron 表达式）+ 闹钟表 crawler/alarms.json 调度爬虫任务：
  - fire         闹钟到点触发（无到期闹钟安静退出）
  - sync         同步订阅：历史/过期立即爬，未来比赛写入闹钟
  - incremental  提交增量同步（scheduled_task.py --submissions-only）
  - remind       赛前提醒：planned 比赛开始前 15 分钟向 QQ 群发提醒

复盘报告（report.py）：sync/fire 爬取成功后生成；任一应生成报告的比赛的
review 生成失败 → 该次 sync/fire 中止（不 mark archived、不提交推送，下次
重试）。QQ 群分享（qq_share.py）：report 全部成功后按 config.json 的
ai_tasks.share.enabled 单独调用；NapCat 未配置/发送失败仅告警不阻断。

与 server-task.sh 语义一致（git 流程、闹钟分类、失败标记原样保留），
提交规则调整为：仅 contests/ 有实质更新才提交推送（带 [contests-changed] 标记），
仅 crawler 状态/日志变化时不提交（已在本地持久化）。区别是：
  - 跨平台：Linux / macOS / Windows 均可运行
  - run 主循环：croniter 解析表达式 + 状态文件防重复；睡眠恢复后每个任务
    只补跑一次（不追赶历史，靠任务自身增量/幂等覆盖错过时段）
  - install 按 OS 注册开机自启：systemd user / launchd / schtasks
  - install --system（仅 Linux）：注册系统级 systemd service，开机即启动、
    无需登录会话（适合无头服务器）；服务以实际用户身份运行（User=<owner>）
  - 跨平台文件锁：filelock（替代 flock）

用法:
  python3 crawler/scripts/daemon.py run            主循环（前台运行；安装为服务后由系统拉起）
  python3 crawler/scripts/daemon.py sync           同步订阅（一次性）
  python3 crawler/scripts/daemon.py fire           闹钟到点触发（一次性；无到期安静退出）
  python3 crawler/scripts/daemon.py incremental    提交增量同步（一次性）
  python3 crawler/scripts/daemon.py remind         赛前提醒检查（一次性；发 QQ 群提醒）
  python3 crawler/scripts/daemon.py install        注册开机自启（按 OS；默认登录后启动）
  python3 crawler/scripts/daemon.py install --system   仅 Linux：注册系统级服务（开机即启动，需 sudo）
  python3 crawler/scripts/daemon.py uninstall      注销开机自启
  python3 crawler/scripts/daemon.py uninstall --system  仅 Linux：注销系统级服务（需 root）
  python3 crawler/scripts/daemon.py install-qqbot      注册 qq-bot 独立服务（QQ 群指令轮询）
  python3 crawler/scripts/daemon.py install-qqbot --system  仅 Linux：注册系统级 qq-bot 服务（需 sudo）
  python3 crawler/scripts/daemon.py uninstall-qqbot      注销 qq-bot 服务
  python3 crawler/scripts/daemon.py uninstall-qqbot --system  仅 Linux：注销系统级 qq-bot 服务（需 root）
  python3 crawler/scripts/daemon.py status         查看状态（scheduled / 闹钟 / 自启 / git / 日志）
  python3 crawler/scripts/daemon.py log [N]        查看最近 N 行运行日志（默认 50）
  python3 crawler/scripts/daemon.py --help         显示本帮助

环境要求:
  - 已 clone 本仓库（deploy 分支）
  - 仓库根目录存在 .env（凭据；已被 gitignore，不会提交）
  - 建议使用 venv：python3 -m venv .venv && .venv/bin/pip install -r
    crawler/requirements.txt；install 用哪个 python 执行，服务就用哪个
    python 运行（务必用 .venv/bin/python 执行 install）
  - Chrome / Chromedriver（见 README 部署指引；Linux 默认
    crawler/chrome-linux64/ 与 crawler/chromedriver-linux64/）
  - pandoc（HDU / NowCoder 题目 HTML→Markdown 转换必需）
  - push 到 GitHub 的凭据已配置（SSH key 或 token；deploy 分支写权限）
"""

import getpass
import json
import os
import platform
import shutil
import subprocess
import sys
import tempfile
import time
from datetime import datetime

from dotenv import load_dotenv

# 让 `from crawler.platforms.base import beijing` 可用（与其他 scripts 一致）
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "..")))

from crawler.platforms.base import beijing  # noqa: E402
from crawler.scripts.qq_share import (  # noqa: E402
    QQGroupSender,
    _load_qq_config,
    ai_task_enabled,
    clean_for_qq,
    create_connection,
)

try:
    from croniter import croniter
    from filelock import FileLock, Timeout
except ImportError as e:
    print(
        f"[daemon] Missing dependency {e.name}. "
        "Run: pip install -r crawler/requirements.txt",
        file=sys.stderr,
    )
    sys.exit(1)

# ---------------------------------------------------------------------------
# 常量
# ---------------------------------------------------------------------------
REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
SCRIPT_DIR = os.path.join(REPO_ROOT, "crawler", "scripts")
LOG_FILE = os.path.join(REPO_ROOT, "crawler", "daemon.log")
STATE_FILE = os.path.join(REPO_ROOT, "crawler", "daemon-state.json")
CONFIG_PATH = os.path.join(REPO_ROOT, "crawler", "config.json")
DEPLOY_BRANCH = "deploy"
LOCK_PATH = os.path.join(tempfile.gettempdir(), "training-archive-daemon.lock")
POLL_INTERVAL = 30  # 主循环检查间隔（秒）

# 任务名 → config.json scheduled 块键名（默认表达式与 config.example.json 一致）
TASKS = ("fire", "sync", "incremental", "remind")
DEFAULT_SCHEDULED = {
    "fire": "*/5 * * * *",        # 闹钟检查
    "sync": "0 */3 * * *",        # 订阅同步
    "incremental": "0 4 * * *",   # 提交增量（每日）
    "remind": "*/5 * * * *",      # 赛前提醒（开始前 15 分钟发 QQ 群提醒）
}

# systemd / launchd 服务名
UNIT_NAME = "training-archive-daemon"
PLIST_LABEL = "com.trainingarchive.daemon"
SCHTASKS_NAME = "TrainingArchiveDaemon"

# qq-bot 服务（独立于 daemon，可单独管理）
QQBOT_UNIT_NAME = "training-archive-qqbot"
QQBOT_PLIST_LABEL = "com.trainingarchive.qqbot"
QQBOT_SCHTASKS_NAME = "TrainingArchiveQQBot"


# ---------------------------------------------------------------------------
# 日志
# ---------------------------------------------------------------------------
def log(msg):
    """带时间戳写入 daemon.log 并打印到 stdout（服务日志/终端可见）。"""
    line = f"[{datetime.now(beijing).strftime('%Y-%m-%d %H:%M:%S')}] {msg}"
    print(line, flush=True)
    try:
        with open(LOG_FILE, "a", encoding="utf-8") as f:
            f.write(line + "\n")
    except OSError:
        pass


def log_raw(text):
    """子进程原始输出：原样写入日志文件并打印（不带时间戳）。"""
    text = text.rstrip("\n")
    if not text:
        return
    print(text, flush=True)
    try:
        with open(LOG_FILE, "a", encoding="utf-8") as f:
            f.write(text + "\n")
    except OSError:
        pass


# ---------------------------------------------------------------------------
# 子进程 / git 工具
# ---------------------------------------------------------------------------
def run_py(script, *args, capture=False):
    """运行 crawler/scripts/ 下的脚本（用当前解释器，保证依赖一致）。

    capture=True 时返回 subprocess.CompletedProcess（不写日志，用于 due 等轻量查询）。
    默认流式转发输出：子进程每产生一行，立即 log_raw 写入日志并打印——
    sync/fire 爬取长任务时实时可见，而不是等任务结束后一次性输出。
    stderr 并入同一流（日志本就区分 stdout/stderr）。
    返回 Popen（已 wait，returncode 可用）。

    关键：PYTHONUNBUFFERED=1——子进程 stdout 被重定向到管道时，Python 默认
    用块缓冲（4-8KB），print() 不带 flush 的日志会攒在子进程缓冲区里，直到
    进程结束才 flush 到管道；daemon 侧流式读取也读不到（表现为爬取过程静默、
    结束后一次性输出）。强制无缓冲后每行 print 立即到达管道，流式转发才生效。
    """
    cmd = [sys.executable, os.path.join(SCRIPT_DIR, script), *args]
    env = dict(os.environ)
    env["PYTHONUNBUFFERED"] = "1"
    if capture:
        return subprocess.run(cmd, text=True, capture_output=True, env=env)
    log("$ " + " ".join(cmd))
    # stderr=STDOUT 合并为单一管道：避免双管道各自读、互等填满造成死锁
    proc = subprocess.Popen(
        cmd,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        bufsize=1,
        env=env,
    )
    assert proc.stdout is not None
    for line in proc.stdout:
        log_raw(line)
    proc.wait()
    return proc


def git(*args, check=True):
    return subprocess.run(["git", *args], text=True, capture_output=True, check=check)


def setup_env():
    """加载根目录 .env（cron/服务环境不继承 shell 环境变量）。"""
    env_file = os.path.join(REPO_ROOT, ".env")
    if os.path.exists(env_file):
        load_dotenv(env_file)
    else:
        log("[WARN] .env not found; platform logins may fail.")


def ensure_deploy_branch():
    """切到 deploy 分支并 pull（与 server-task.sh 一致；pull 失败不阻断）。"""
    os.chdir(REPO_ROOT)
    r = git("rev-parse", "--verify", DEPLOY_BRANCH, check=False)
    if r.returncode != 0:
        log(f"Branch '{DEPLOY_BRANCH}' not found. Create it first (e.g. from master).")
        raise SystemExit(1)
    git("checkout", DEPLOY_BRANCH, check=False)
    git("pull", "--ff-only", "origin", DEPLOY_BRANCH, check=False)


def commit_and_push():
    """提交并推送——仅当 contests/ 有实质更新时。

    无实质更新（contests/ 未变化）时不提交不推送：爬虫状态与日志
    （last-update.json、staged-submissions.json、log.json、daemon.log 等）
    已在本地文件系统持久化（deploy 分支工作区），无需同步远端。
    仅 contests/ 变化（新比赛 / 新提交 / 新报告）才发 [contests-changed]
    提交，触发 deploy.yml 部署。
    """
    git("config", "user.name", "server-task[bot]", check=False)
    git("config", "user.email", "server-task[bot]@users.noreply.github.com", check=False)
    shutil.copy(os.path.join(REPO_ROOT, ".gitignore.deploy"), os.path.join(REPO_ROOT, ".gitignore"))
    git("add", ".gitignore", "crawler", "contests", check=False)
    git("reset", "HEAD", "crawler/chromedriver-linux64/chromedriver", check=False)

    # core.quotepath=false：比赛名含中文时 git 默认转义非 ASCII 路径，
    # grep '^contests/' 会误判；统一用 quotepath=false 取文件名判断。
    r = git("-c", "core.quotepath=false", "diff", "--cached", "--name-only", check=False)
    changed = [line for line in r.stdout.splitlines() if line.startswith("contests/")]
    if not changed:
        log("No contest data changes; skip commit/push (crawler state persists locally).")
        return

    git("commit", "-m", "[auto] [contests-changed] Update contest and submission data")
    git("push", "origin", DEPLOY_BRANCH)
    log(f"Pushed to {DEPLOY_BRANCH}.")


# ---------------------------------------------------------------------------
# 文件锁（跨平台，替代 flock -n）
# ---------------------------------------------------------------------------
def with_lock(fn):
    """非阻塞获取锁；拿不到则记日志跳过（与 server-task.sh flock -n 一致）。"""
    lock = FileLock(LOCK_PATH)
    try:
        lock.acquire(timeout=0)
    except Timeout:
        log("Another task is already running, skip this run.")
        return 1
    try:
        return fn()
    finally:
        lock.release()


# ---------------------------------------------------------------------------
# 任务：incremental / sync / fire（逻辑与 server-task.sh 一一对应）
# ---------------------------------------------------------------------------
def _deps_ok():
    """Python 依赖检查（与 server-task.sh 一致）。"""
    try:
        import undetected_chromedriver  # noqa: F401
        return True
    except ImportError:
        log("Missing Python dependencies. Run: pip install -r crawler/requirements.txt")
        return False


def cmd_incremental():
    """提交增量同步：scheduled_task.py --submissions-only + 报告 + 提交推送。"""
    def _run():
        log("=== incremental (--submissions-only) ===")
        ensure_deploy_branch()
        setup_env()
        if not _deps_ok():
            return 1
        # 与 action/server-task 一致：增量同步失败即中止，不提交推送
        p = run_py("scheduled_task.py", "--submissions-only")
        if p.returncode != 0:
            log("[WARN] scheduled_task --submissions-only failed; aborting before commit.")
            return p.returncode
        # 复盘报告：无新建比赛时 --from-crawl 自然跳过；失败仅告警
        p = run_py("report.py", "--from-crawl")
        if p.returncode != 0:
            log("[WARN] report.py failed (skipped review generation).")
        run_py("clean-log.py", capture=True)
        commit_and_push()
        log("=== done (incremental) ===")
        return 0

    return with_lock(_run)


def _parse_plan_output(plan_out):
    """解析 alarm.py plan 的 tab 分隔输出为 (history, expired, retry)。

    history / expired 为链接列表；retry 为 (link, end_time) 元组列表：
    end_time 非空 = 原 EXPIRED/planned 任务（重试成功要生成报告），
    空 = 原 HISTORY 任务（重试成功不生成报告）。
    """
    history, expired, retry = [], [], []
    for line in plan_out.splitlines():
        if line.startswith("HISTORY\t"):
            history.append(line.split("\t", 1)[1])
        elif line.startswith("EXPIRED\t"):
            expired.append(line.split("\t", 1)[1])
        elif line.startswith("RETRY\t"):
            parts = line.split("\t", 2)
            retry.append((parts[1], parts[2] if len(parts) > 2 else ""))
    return history, expired, retry


def cmd_sync():
    """同步订阅：plan 分类 → 爬取 HISTORY/EXPIRED/RETRY → 报告 → mark archived。

    爬取失败 → 本次涉及的全部链接 mark --failed（下次 sync 重试）。
    报告条件 = 订阅填了 end_time：EXPIRED 必生成；RETRY 仅当原任务填了
    end_time（第 3 列非空）才生成；HISTORY 不生成。
    review 生成失败 → 本次 sync 中止（不 mark archived、不提交推送）。
    report 成功后若 ai_tasks.share.enabled 开启 → 调 qq_share.py 群发
    （失败仅告警，不阻断 sync）。
    """
    def _run():
        log("=== sync ===")
        ensure_deploy_branch()
        setup_env()
        if not _deps_ok():
            return 1

        # 1. plan 分类订阅并写闹钟表。转发所有 [alarm] 诊断行到日志：
        #    plan 汇总、WARNING（failed 重试 / 订阅条目告警）、ERROR（订阅文件
        #    格式有问题 / 时间字段非法被跳过）。plan 返回非零（格式有问题）→
        #    **中止本次 sync**：不爬取不提交，用户修复订阅后重跑——避免把
        #    "填错时间" 静默当作 HISTORY 立即爬掉且不生成报告。
        proc = run_py("alarm.py", "plan", capture=True)
        plan_out = proc.stdout
        for l in plan_out.splitlines():
            if l.startswith("[alarm]"):
                log(l)
        if proc.returncode != 0:
            log("[ERROR] alarm.py plan failed (subscription file / time format "
                "problems); aborting sync. Fix the subscriptions and re-run.")
            return proc.returncode
        history_links, expired_links, retry_links = _parse_plan_output(plan_out)
        retry_all = [link for link, _ in retry_links]
        all_links = list(dict.fromkeys(history_links + expired_links + retry_all))

        if not all_links:
            log("No history/expired/retry links; nothing to crawl.")
            log("=== sync done ===")
            return 0

        # 2. 爬取（失败：本次涉及的全部链接 mark --failed，下次 sync 重试）
        links_csv = ",".join(all_links)
        log(f"Crawling: {links_csv}")
        p = run_py("scheduled_task.py", "--contests-only", "--links", links_csv)
        if p.returncode != 0:
            log("Sync crawl failed; marking involved alarms as failed.")
            for link in all_links:
                run_py("alarm.py", "mark", link, "--failed", capture=True)
            return p.returncode

        # 3. 复盘报告：只对填了 end_time 的比赛生成（HISTORY 不生成）。
        #    报告条件 = 订阅的 end_time 标记，而非"本次是否新建"——按链接
        #    反查比赛文件夹生成（report.py --links），不依赖 new-contests.json。
        #    EXPIRED 必生成；RETRY 按第 3 列 end_time 判断：非空 = 原
        #    EXPIRED/planned（生成），空 = 原 HISTORY（不生成）。
        #    任一应生成报告的比赛的 review 生成失败 → 中止本次 sync
        #    （不 mark archived、不提交推送；下次 sync 重试）。
        report_links = list(
            dict.fromkeys(expired_links + [link for link, et in retry_links if et])
        )
        if report_links:
            log("Generating reviews for expired/retried contests.")
            p = run_py("report.py", "--links", ",".join(report_links))
            if p.returncode != 0:
                log("[WARN] review generation failed; aborting before mark "
                    "archived (retried next sync).")
                return p.returncode
            # QQ 群分享（share AI task）：report 成功后按 config.json 的
            # ai_tasks.share.enabled 显式开启才调用；失败仅告警不阻断。
            if ai_task_enabled("share"):
                log("Generating QQ group shares for reports.")
                run_py("qq_share.py", "--links", ",".join(report_links))

        # 4. 标记已处理完（archived；保留历史，plan 下次跳过）
        for link in all_links:
            run_py("alarm.py", "mark", link, "--archived", capture=True)

        run_py("clean-log.py", capture=True)
        commit_and_push()
        log("=== sync done ===")
        return 0

    return with_lock(_run)


def _due_links():
    """alarm.py due 输出 DUE\t<link>；无到期闹钟返回空列表（安静，不写日志）。"""
    proc = run_py("alarm.py", "due", capture=True)
    links = []
    for line in proc.stdout.splitlines():
        if line.startswith("DUE\t"):
            links.append(line.split("\t", 1)[1])
    return links


def cmd_fire():
    """闹钟到点触发：due 无到期安静退出；有则爬取 + 报告 + mark archived。

    爬取失败 → mark --failed（fire 只查 planned，失败后不再自动重试，
    靠下次 sync 重试一次）。
    review 生成失败 → 本次 fire 中止（不 mark archived、不提交推送）。
    report 成功后若 ai_tasks.share.enabled 开启 → 调 qq_share.py 群发
    （失败仅告警，不阻断 fire）。
    """
    # 先读闹钟表（轻量）；无到期则安静退出（不写日志、不碰 git）
    due_links = _due_links()
    if not due_links:
        return 0

    def _run():
        log("=== fire ===")
        ensure_deploy_branch()
        setup_env()
        if not _deps_ok():
            return 1

        links_csv = ",".join(due_links)
        log(f"Fire due: {links_csv}")
        p = run_py("scheduled_task.py", "--contests-only", "--links", links_csv)
        if p.returncode != 0:
            log("Fire crawl failed; marking due alarms as failed.")
            for link in due_links:
                run_py("alarm.py", "mark", link, "--failed", capture=True)
            return p.returncode

        # 到期比赛（填了 end_time 的未来比赛）都要生成报告。报告条件 =
        # 订阅的 end_time 标记（fire due），按链接反查比赛文件夹生成
        # （report.py --links），不依赖 new-contests.json——比赛此前已
        # 归档过（非本次新建）也要生成，否则会漏掉复盘。
        # 任一应生成报告的比赛的 review 生成失败 → 中止本次 fire
        # （不 mark archived；下次 sync 兜底重试）。
        log("Generating reviews for due contests.")
        p = run_py("report.py", "--links", ",".join(due_links))
        if p.returncode != 0:
            log("[WARN] review generation failed; aborting before mark "
                "archived (retried next sync).")
            return p.returncode
        # QQ 群分享（share AI task）：report 成功后按 config.json 的
        # ai_tasks.share.enabled 显式开启才调用；失败仅告警不阻断。
        if ai_task_enabled("share"):
            log("Generating QQ group shares for reports.")
            run_py("qq_share.py", "--links", ",".join(due_links))

        for link in due_links:
            run_py("alarm.py", "mark", link, "--archived", capture=True)

        run_py("clean-log.py", capture=True)
        commit_and_push()
        log("=== fire done ===")
        return 0

    return with_lock(_run)


def _remind_minutes_left(start_iso, now):
    """距离比赛开始的分钟数（四舍五入，至少 1）；解析失败返回 None。"""
    try:
        start = datetime.fromisoformat(str(start_iso))
        if start.tzinfo is None:
            start = start.replace(tzinfo=beijing)
        start = start.astimezone(beijing)
    except (TypeError, ValueError):
        return None
    minutes = (start - now).total_seconds() / 60.0
    return max(1, int(round(minutes)))


def _fmt_remind_time(start_iso, now):
    """提醒消息里的开始时间：今天/明天 HH:MM，更远则 MM-DD HH:MM。"""
    try:
        start = datetime.fromisoformat(str(start_iso))
        if start.tzinfo is None:
            start = start.replace(tzinfo=beijing)
        start = start.astimezone(beijing)
    except (TypeError, ValueError):
        return str(start_iso)
    day = (start.date() - now.date()).days
    hm = start.strftime("%H:%M")
    if day == 0:
        return f"今天 {hm}"
    if day == 1:
        return f"明天 {hm}"
    return start.strftime("%m-%d %H:%M")


def cmd_remind():
    """赛前提醒：planned 且进入提醒窗口的比赛，向 QQ 群发提醒并标记 reminded。

    alarm.py remind 只读输出 REMIND\t<link>\t<start_time>\t<comments>；
    发送成功后调 mark --reminded（发送失败不标记，下轮重试）。NapCat 未配置 /
    连接失败 / 发送失败仅告警，不阻断 daemon 主流程。
    """
    def _run():
        proc = run_py("alarm.py", "remind", capture=True)
        reminds = []
        for line in proc.stdout.splitlines():
            if not line.startswith("REMIND\t"):
                continue
            parts = line.split("\t", 3)
            reminds.append({
                "link": parts[1],
                "start_time": parts[2] if len(parts) > 2 else "",
                "comments": parts[3] if len(parts) > 3 else "",
            })
        if not reminds:
            return 0

        qq_cfg = _load_qq_config()
        ws_url = qq_cfg.get("napcat_ws_url", "")
        group_id = qq_cfg.get("group_id", 0)
        if not ws_url or not group_id:
            log(f"赛前提醒：NapCat 未配置（{len(reminds)} 条待提醒），跳过发送。")
            return 0
        if create_connection is None:
            log("赛前提醒：websocket-client 未安装，跳过发送。")
            return 0

        sender = QQGroupSender(ws_url, group_id, qq_cfg.get("napcat_token", ""))
        try:
            sender._connect()
        except Exception as e:
            log(f"赛前提醒：NapCat 连接失败 {ws_url}: {e}")
            return 0
        try:
            for r in reminds:
                now = datetime.now(beijing)
                mins = _remind_minutes_left(r["start_time"], now)
                name = r["comments"] or r["link"]
                if mins is None:
                    st = str(r["start_time"])
                else:
                    st = _fmt_remind_time(r["start_time"], now)
                head = "【赛前提醒】"
                body = f"「{name}」将于 {st} 开始，还有约 {mins} 分钟，记得提前做好准备！"
                ok = sender.send_text(clean_for_qq(f"{head}\n{body}"))
                if ok:
                    run_py("alarm.py", "mark", r["link"], "--reminded", capture=True)
                    log(f"赛前提醒已发送：{name}（{st} 开始）。")
                else:
                    log(f"赛前提醒发送失败（下轮重试）：{name}。")
        finally:
            sender._close()
        return len(reminds)

    return with_lock(_run)


# ---------------------------------------------------------------------------
# 主循环（run）
# ---------------------------------------------------------------------------
def load_scheduled():
    """读取 config.json scheduled 块（缺失/非法回落默认值），返回 {task: expr}。"""
    scheduled = dict(DEFAULT_SCHEDULED)
    if os.path.exists(CONFIG_PATH):
        try:
            with open(CONFIG_PATH, "r", encoding="utf-8") as f:
                cfg = json.load(f)
            block = cfg.get("scheduled", {})
            for task in TASKS:
                expr = block.get(task)
                if expr and croniter.is_valid(expr):
                    scheduled[task] = expr
                elif expr:
                    log(f"[run] invalid cron for {task}: {expr!r}; using default {scheduled[task]}")
        except Exception as e:
            log(f"[run] failed to parse {CONFIG_PATH}: {e}; using defaults")
    return scheduled


def load_state():
    """读取 daemon-state.json（运行时状态，gitignore）。缺失/损坏返回空 dict。"""
    if not os.path.exists(STATE_FILE):
        return {"last_run": {}}
    try:
        with open(STATE_FILE, "r", encoding="utf-8") as f:
            state = json.load(f)
        if not isinstance(state, dict):
            return {"last_run": {}}
        state.setdefault("last_run", {})
        return state
    except Exception as e:
        log(f"[run] failed to read {STATE_FILE}: {e}; starting fresh.")
        return {"last_run": {}}


def save_state(state):
    with open(STATE_FILE, "w", encoding="utf-8") as f:
        json.dump(state, f, ensure_ascii=False, indent=2)


def _is_due(task, expr, now, state):
    """任务是否到期：首次运行视为到期（启动即跑一次）；此后按 cron 表达式判断。

    睡眠恢复后：从 last_run 计算下一次，若 <= now 则到期（只补跑一次，
    不追赶历史——执行后 last_run 更新为 now，下次计算自然跳到未来）。
    """
    last = state.get("last_run", {}).get(task)
    if not last:
        return True
    try:
        dt = datetime.fromisoformat(last)
        nxt = croniter(expr, dt).get_next(datetime)
    except (ValueError, KeyError) as e:
        log(f"[run] bad state/last_run for {task}: {e}; treating as due.")
        return True
    return nxt <= now


def cmd_run():
    """主循环：每 POLL_INTERVAL 秒检查三个任务是否到期，到期则执行。"""
    log("=== daemon run started ===")
    log(f"Lock: {LOCK_PATH}")
    scheduled = load_scheduled()
    log("[run] scheduled: " + ", ".join(f"{k}={v}" for k, v in scheduled.items()))
    try:
        while True:
            now = datetime.now(beijing)
            state = load_state()
            for task in TASKS:
                if not _is_due(task, scheduled[task], now, state):
                    continue
                log(f"[run] task due: {task}")
                try:
                    if task == "fire":
                        cmd_fire()
                    elif task == "sync":
                        cmd_sync()
                    elif task == "incremental":
                        cmd_incremental()
                    elif task == "remind":
                        cmd_remind()
                except SystemExit as e:
                    # 任务失败（returncode 非零）不应杀死 daemon；记日志继续
                    log(f"[run] task {task} exited with code {e.code}")
                except Exception as e:
                    log(f"[run] task {task} failed: {e}")
                # 无论成败都推进 last_run：下次触发按 cron 排程（失败的任务
                # 由 sync 兜底重试，与 server-task.sh 语义一致）
                state = load_state()
                state["last_run"][task] = now.isoformat()
                save_state(state)
            time.sleep(POLL_INTERVAL)
    except KeyboardInterrupt:
        log("=== daemon stopped (Ctrl+C) ===")


# ---------------------------------------------------------------------------
# 开机自启注册（install / uninstall）
# ---------------------------------------------------------------------------
def _system():
    s = platform.system()
    return {"Linux": "linux", "Darwin": "macos", "Windows": "windows"}.get(s, s.lower())


def _service_command():
    """安装为服务时拉起 run 的完整命令（[python, script, run]）。"""
    return [sys.executable, os.path.join(REPO_ROOT, "crawler", "scripts", "daemon.py"), "run"]


def _qqbot_service_command():
    """安装为服务时拉起 qq-bot 的完整命令（[python, qq_bot.py, run]）。"""
    return [sys.executable, os.path.join(REPO_ROOT, "crawler", "scripts", "qq_bot.py"), "run"]


def install_linux(system=False):
    """注册开机自启：默认 systemd user unit（登录后启动）；system=True 时注册
    系统级 systemd service（开机即启动，无需登录会话，适合无头服务器）。
    无 systemd 时回落 cron @reboot（仅 user 模式）。"""
    if system:
        return install_linux_system()
    systemd_dir = os.path.expanduser("~/.config/systemd/user")
    if shutil.which("systemctl") and (os.path.isdir(systemd_dir) or True):
        os.makedirs(systemd_dir, exist_ok=True)
        unit = os.path.join(systemd_dir, f"{UNIT_NAME}.service")
        py, script, run = _service_command()
        content = f"""[Unit]
Description=Training Archive Crawler Daemon
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
ExecStart={py} {script} {run}
WorkingDirectory={REPO_ROOT}
Restart=on-failure
RestartSec=30

[Install]
WantedBy=default.target
"""
        with open(unit, "w", encoding="utf-8") as f:
            f.write(content)
        subprocess.run(["systemctl", "--user", "daemon-reload"], check=False)
        subprocess.run(
            ["systemctl", "--user", "enable", "--now", f"{UNIT_NAME}.service"],
            check=False,
        )
        log(f"Installed systemd user unit: {unit}")
        log("Start at login: systemctl --user enable --now training-archive-daemon.service")
        return
    # fallback: cron @reboot
    entry = f"@reboot cd {REPO_ROOT} && {' '.join(_service_command())} >> {LOG_FILE} 2>&1"
    crontab = subprocess.run(["crontab", "-l"], text=True, capture_output=True)
    lines = [l for l in crontab.stdout.splitlines() if UNIT_NAME not in l]
    lines.append(entry)
    subprocess.run(["crontab", "-"], input="\n".join(lines) + "\n", text=True)
    log("Installed cron @reboot (systemd not available).")


def install_linux_system():
    """注册系统级 systemd service（/etc/systemd/system，WantedBy=multi-user.target）。

    开机即启动、不依赖登录会话（适合无头服务器）。服务以实际用户身份运行
    （User=<owner>，sudo 执行时取 SUDO_USER），保证 git 凭据 / .env 与手动
    运行一致。需要 root，请用：
        sudo .venv/bin/python crawler/scripts/daemon.py install --system
    """
    if not shutil.which("systemctl"):
        log("[ERROR] systemd not available on this host; cannot install system service.")
        return 1
    if os.geteuid() != 0:
        log("[ERROR] 'install --system' needs root to write /etc/systemd/system.")
        log("Run: sudo .venv/bin/python crawler/scripts/daemon.py install --system")
        return 1
    owner = os.environ.get("SUDO_USER") or getpass.getuser()
    unit = f"/etc/systemd/system/{UNIT_NAME}.service"
    py, script, run = _service_command()
    content = f"""[Unit]
Description=Training Archive Crawler Daemon
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
User={owner}
ExecStart={py} {script} {run}
WorkingDirectory={REPO_ROOT}
Restart=on-failure
RestartSec=30

[Install]
WantedBy=multi-user.target
"""
    with open(unit, "w", encoding="utf-8") as f:
        f.write(content)
    subprocess.run(["systemctl", "daemon-reload"], check=False)
    subprocess.run(
        ["systemctl", "enable", "--now", f"{UNIT_NAME}.service"],
        check=False,
    )
    log(f"Installed systemd system unit: {unit} (User={owner})")
    log("Starts at boot without login (multi-user.target).")
    log("Manage: systemctl status/enable/disable training-archive-daemon.service")
    return 0


def install_macos():
    """launchd LaunchAgent：登录时启动 + KeepAlive（崩溃自动拉起）。"""
    agents_dir = os.path.expanduser("~/Library/LaunchAgents")
    os.makedirs(agents_dir, exist_ok=True)
    plist = os.path.join(agents_dir, f"{PLIST_LABEL}.plist")
    py, script, run = _service_command()
    content = f"""<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>Label</key>
    <string>{PLIST_LABEL}</string>
    <key>ProgramArguments</key>
    <array>
        <string>{py}</string>
        <string>{script}</string>
        <string>{run}</string>
    </array>
    <key>WorkingDirectory</key>
    <string>{REPO_ROOT}</string>
    <key>RunAtLoad</key>
    <true/>
    <key>KeepAlive</key>
    <true/>
    <key>StandardOutPath</key>
    <string>{LOG_FILE}</string>
    <key>StandardErrorPath</key>
    <string>{LOG_FILE}</string>
</dict>
</plist>
"""
    with open(plist, "w", encoding="utf-8") as f:
        f.write(content)
    subprocess.run(["launchctl", "unload", plist], check=False)
    subprocess.run(["launchctl", "load", plist], check=False)
    log(f"Installed launchd agent: {plist}")


def install_windows():
    """schtasks ONLOGON：登录时启动（pythonw 无控制台窗口）。"""
    python = sys.executable
    pythonw = python.replace("python.exe", "pythonw.exe")
    if os.path.exists(pythonw):
        python = pythonw
    script = os.path.join(REPO_ROOT, "crawler", "scripts", "daemon.py")
    # schtasks 的 TR 参数引号规则：命令本身和每个含空格的参数都要包引号
    tr = f'"{python}" "{script}" run'
    r = subprocess.run(
        ["schtasks", "/Create", "/F", "/TN", SCHTASKS_NAME, "/SC", "ONLOGON",
         "/TR", tr, "/RL", "LIMITED"],
        text=True, capture_output=True,
    )
    if r.returncode != 0:
        log(f"[WARN] schtasks failed: {r.stdout.strip()} {r.stderr.strip()}")
        return 1
    log(f"Installed scheduled task: {SCHTASKS_NAME} (ONLOGON)")


def cmd_install(system=False):
    """按 OS 注册开机自启。system=True：注册系统级服务（目前仅 Linux systemd，
    开机即启动、无需登录会话，适合无头服务器）；其余平台忽略并回落默认行为。"""
    s = _system()
    if system and s != "linux":
        log(f"[WARN] '--system' is only supported on Linux (current: {s}); "
            "falling back to user autostart.")
        system = False
    if s == "linux":
        return install_linux(system)
    elif s == "macos":
        install_macos()
    elif s == "windows":
        install_windows()
    else:
        log(f"[WARN] unsupported platform: {platform.system()}; manual setup required.")
        return 1
    log("Install done. Run 'daemon.py run' once now to verify, or start via the service.")
    return 0


# ---------------------------------------------------------------------------
# qq-bot 服务安装（独立于 daemon；install-qqbot / uninstall-qqbot）
# ---------------------------------------------------------------------------
def install_qqbot_linux(system=False):
    """注册 qq-bot 自启：默认 systemd user unit；system=True 时系统级。"""
    if system:
        return install_qqbot_linux_system()
    systemd_dir = os.path.expanduser("~/.config/systemd/user")
    if shutil.which("systemctl") and (os.path.isdir(systemd_dir) or True):
        os.makedirs(systemd_dir, exist_ok=True)
        unit = os.path.join(systemd_dir, f"{QQBOT_UNIT_NAME}.service")
        py, script, run = _qqbot_service_command()
        content = f"""[Unit]
Description=Training Archive QQ Bot (group command polling)
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
ExecStart={py} {script} {run}
WorkingDirectory={REPO_ROOT}
Restart=on-failure
RestartSec=30

[Install]
WantedBy=default.target
"""
        with open(unit, "w", encoding="utf-8") as f:
            f.write(content)
        subprocess.run(["systemctl", "--user", "daemon-reload"], check=False)
        subprocess.run(
            ["systemctl", "--user", "enable", "--now", f"{QQBOT_UNIT_NAME}.service"],
            check=False,
        )
        log(f"Installed systemd user unit: {unit}")
        log("Start at login: systemctl --user enable --now training-archive-qqbot.service")
        return
    log("[ERROR] qq-bot needs systemd (user unit); no fallback available.")
    return 1


def install_qqbot_linux_system():
    """系统级 qq-bot service（/etc/systemd/system，开机即启动）。"""
    if not shutil.which("systemctl"):
        log("[ERROR] systemd not available on this host; cannot install qq-bot service.")
        return 1
    if os.geteuid() != 0:
        log("[ERROR] 'install-qqbot --system' needs root to write /etc/systemd/system.")
        log("Run: sudo .venv/bin/python crawler/scripts/daemon.py install-qqbot --system")
        return 1
    owner = os.environ.get("SUDO_USER") or getpass.getuser()
    unit = f"/etc/systemd/system/{QQBOT_UNIT_NAME}.service"
    py, script, run = _qqbot_service_command()
    content = f"""[Unit]
Description=Training Archive QQ Bot (group command polling)
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
User={owner}
ExecStart={py} {script} {run}
WorkingDirectory={REPO_ROOT}
Restart=on-failure
RestartSec=30

[Install]
WantedBy=multi-user.target
"""
    with open(unit, "w", encoding="utf-8") as f:
        f.write(content)
    subprocess.run(["systemctl", "daemon-reload"], check=False)
    subprocess.run(
        ["systemctl", "enable", "--now", f"{QQBOT_UNIT_NAME}.service"],
        check=False,
    )
    log(f"Installed systemd system unit: {unit} (User={owner})")
    log("Manage: systemctl status/enable/disable training-archive-qqbot.service")
    return 0


def install_qqbot_macos():
    """launchd LaunchAgent：登录时启动 + KeepAlive。"""
    agents_dir = os.path.expanduser("~/Library/LaunchAgents")
    os.makedirs(agents_dir, exist_ok=True)
    plist = os.path.join(agents_dir, f"{QQBOT_PLIST_LABEL}.plist")
    py, script, run = _qqbot_service_command()
    content = f"""<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>Label</key>
    <string>{QQBOT_PLIST_LABEL}</string>
    <key>ProgramArguments</key>
    <array>
        <string>{py}</string>
        <string>{script}</string>
        <string>{run}</string>
    </array>
    <key>WorkingDirectory</key>
    <string>{REPO_ROOT}</string>
    <key>RunAtLoad</key>
    <true/>
    <key>KeepAlive</key>
    <true/>
    <key>StandardOutPath</key>
    <string>{LOG_FILE}</string>
    <key>StandardErrorPath</key>
    <string>{LOG_FILE}</string>
</dict>
</plist>
"""
    with open(plist, "w", encoding="utf-8") as f:
        f.write(content)
    subprocess.run(["launchctl", "unload", plist], check=False)
    subprocess.run(["launchctl", "load", plist], check=False)
    log(f"Installed launchd agent: {plist}")


def install_qqbot_windows():
    """schtasks ONLOGON：登录时启动（pythonw 无控制台窗口）。"""
    python = sys.executable
    pythonw = python.replace("python.exe", "pythonw.exe")
    if os.path.exists(pythonw):
        python = pythonw
    script = os.path.join(REPO_ROOT, "crawler", "scripts", "qq_bot.py")
    tr = f'"{python}" "{script}" run'
    r = subprocess.run(
        ["schtasks", "/Create", "/F", "/TN", QQBOT_SCHTASKS_NAME, "/SC", "ONLOGON",
         "/TR", tr, "/RL", "LIMITED"],
        text=True, capture_output=True,
    )
    if r.returncode != 0:
        log(f"[WARN] schtasks failed: {r.stdout.strip()} {r.stderr.strip()}")
        return 1
    log(f"Installed scheduled task: {QQBOT_SCHTASKS_NAME} (ONLOGON)")


def cmd_install_qqbot(system=False):
    """注册 qq-bot 自启（独立服务，可单独管理）。"""
    s = _system()
    if system and s != "linux":
        log(f"[WARN] '--system' is only supported on Linux (current: {s}); "
            "falling back to user autostart.")
        system = False
    if s == "linux":
        return install_qqbot_linux(system)
    elif s == "macos":
        install_qqbot_macos()
    elif s == "windows":
        install_qqbot_windows()
    else:
        log(f"[WARN] unsupported platform: {platform.system()}; manual setup required.")
        return 1
    log("Install done. Start via the service, or run 'qq_bot.py run' to verify.")
    return 0


def uninstall_qqbot_linux(system=False):
    if system:
        return uninstall_qqbot_linux_system()
    unit = os.path.expanduser(f"~/.config/systemd/user/{QQBOT_UNIT_NAME}.service")
    if os.path.exists(unit):
        subprocess.run(
            ["systemctl", "--user", "disable", "--now", f"{QQBOT_UNIT_NAME}.service"], check=False
        )
        os.remove(unit)
        subprocess.run(["systemctl", "--user", "daemon-reload"], check=False)
        log(f"Removed systemd user unit: {unit}")
        return
    log("(qq-bot user service not installed)")


def uninstall_qqbot_linux_system():
    unit = f"/etc/systemd/system/{QQBOT_UNIT_NAME}.service"
    if not os.path.exists(unit):
        log("(qq-bot system service not installed)")
        return
    if os.geteuid() != 0:
        log("[ERROR] 'uninstall-qqbot --system' needs root to remove /etc/systemd/system.")
        return 1
    subprocess.run(
        ["systemctl", "disable", "--now", f"{QQBOT_UNIT_NAME}.service"], check=False
    )
    os.remove(unit)
    subprocess.run(["systemctl", "daemon-reload"], check=False)
    log(f"Removed systemd system unit: {unit}")


def uninstall_qqbot_macos():
    plist = os.path.expanduser(f"~/Library/LaunchAgents/{QQBOT_PLIST_LABEL}.plist")
    if os.path.exists(plist):
        subprocess.run(["launchctl", "unload", plist], check=False)
        os.remove(plist)
        log(f"Removed launchd agent: {plist}")
    else:
        log("(qq-bot launchd agent not installed)")


def uninstall_qqbot_windows():
    subprocess.run(["schtasks", "/Delete", "/F", "/TN", QQBOT_SCHTASKS_NAME], check=False)
    log(f"Removed scheduled task: {QQBOT_SCHTASKS_NAME}")


def cmd_uninstall_qqbot(system=False):
    s = _system()
    if system and s != "linux":
        log(f"[WARN] '--system' is only supported on Linux (current: {s}); "
            "falling back to user autostart removal.")
        system = False
    if s == "linux":
        return uninstall_qqbot_linux(system)
    elif s == "macos":
        uninstall_qqbot_macos()
    elif s == "windows":
        uninstall_qqbot_windows()
    else:
        log(f"[WARN] unsupported platform: {platform.system()}")
        return 1
    log("Uninstall done.")
    return 0


def uninstall_linux(system=False):
    if system:
        return uninstall_linux_system()
    unit = os.path.expanduser(f"~/.config/systemd/user/{UNIT_NAME}.service")
    if os.path.exists(unit):
        subprocess.run(
            ["systemctl", "--user", "disable", "--now", f"{UNIT_NAME}.service"], check=False
        )
        os.remove(unit)
        subprocess.run(["systemctl", "--user", "daemon-reload"], check=False)
        log(f"Removed systemd user unit: {unit}")
        return
    # fallback cron
    crontab = subprocess.run(["crontab", "-l"], text=True, capture_output=True)
    lines = [l for l in crontab.stdout.splitlines() if UNIT_NAME not in l]
    subprocess.run(["crontab", "-"], input="\n".join(lines) + "\n", text=True)
    log("Removed cron @reboot entry.")


def uninstall_linux_system():
    unit = f"/etc/systemd/system/{UNIT_NAME}.service"
    if not os.path.exists(unit):
        log("(system service not installed)")
        return
    if os.geteuid() != 0:
        log("[ERROR] 'uninstall --system' needs root to remove /etc/systemd/system.")
        log("Run: sudo .venv/bin/python crawler/scripts/daemon.py uninstall --system")
        return 1
    subprocess.run(
        ["systemctl", "disable", "--now", f"{UNIT_NAME}.service"], check=False
    )
    os.remove(unit)
    subprocess.run(["systemctl", "daemon-reload"], check=False)
    log(f"Removed systemd system unit: {unit}")


def uninstall_macos():
    plist = os.path.expanduser(f"~/Library/LaunchAgents/{PLIST_LABEL}.plist")
    if os.path.exists(plist):
        subprocess.run(["launchctl", "unload", plist], check=False)
        os.remove(plist)
        log(f"Removed launchd agent: {plist}")


def uninstall_windows():
    subprocess.run(["schtasks", "/Delete", "/F", "/TN", SCHTASKS_NAME], check=False)
    log(f"Removed scheduled task: {SCHTASKS_NAME}")


def cmd_uninstall(system=False):
    s = _system()
    if system and s != "linux":
        log(f"[WARN] '--system' is only supported on Linux (current: {s}); "
            "falling back to user autostart removal.")
        system = False
    if s == "linux":
        return uninstall_linux(system)
    elif s == "macos":
        uninstall_macos()
    elif s == "windows":
        uninstall_windows()
    else:
        log(f"[WARN] unsupported platform: {platform.system()}")
        return 1
    log("Uninstall done.")
    return 0


# ---------------------------------------------------------------------------
# status / log
# ---------------------------------------------------------------------------
def _autostart_info():
    s = _system()
    if s == "linux":
        sys_unit = f"/etc/systemd/system/{UNIT_NAME}.service"
        if os.path.exists(sys_unit):
            r = subprocess.run(["systemctl", "is-enabled", f"{UNIT_NAME}.service"],
                               text=True, capture_output=True)
            return f"systemd system unit: {sys_unit} ({r.stdout.strip()})"
        unit = os.path.expanduser(f"~/.config/systemd/user/{UNIT_NAME}.service")
        if os.path.exists(unit):
            r = subprocess.run(["systemctl", "--user", "is-enabled", f"{UNIT_NAME}.service"],
                               text=True, capture_output=True)
            return f"systemd user unit: {unit} ({r.stdout.strip()})"
        crontab = subprocess.run(["crontab", "-l"], text=True, capture_output=True)
        if UNIT_NAME in crontab.stdout:
            return "cron @reboot"
        return "(not installed)"
    if s == "macos":
        plist = os.path.expanduser(f"~/Library/LaunchAgents/{PLIST_LABEL}.plist")
        return f"launchd agent: {plist}" if os.path.exists(plist) else "(not installed)"
    if s == "windows":
        r = subprocess.run(["schtasks", "/Query", "/TN", SCHTASKS_NAME],
                           text=True, capture_output=True)
        return f"schtasks: {SCHTASKS_NAME}" if r.returncode == 0 else "(not installed)"
    return "(unsupported platform)"


def _qqbot_autostart_info():
    """qq-bot 服务自启状态（独立服务）。"""
    s = _system()
    if s == "linux":
        sys_unit = f"/etc/systemd/system/{QQBOT_UNIT_NAME}.service"
        if os.path.exists(sys_unit):
            r = subprocess.run(["systemctl", "is-enabled", f"{QQBOT_UNIT_NAME}.service"],
                               text=True, capture_output=True)
            return f"systemd system unit: {sys_unit} ({r.stdout.strip()})"
        unit = os.path.expanduser(f"~/.config/systemd/user/{QQBOT_UNIT_NAME}.service")
        if os.path.exists(unit):
            r = subprocess.run(["systemctl", "--user", "is-enabled", f"{QQBOT_UNIT_NAME}.service"],
                               text=True, capture_output=True)
            return f"systemd user unit: {unit} ({r.stdout.strip()})"
        return "(not installed)"
    if s == "macos":
        plist = os.path.expanduser(f"~/Library/LaunchAgents/{QQBOT_PLIST_LABEL}.plist")
        return f"launchd agent: {plist}" if os.path.exists(plist) else "(not installed)"
    if s == "windows":
        r = subprocess.run(["schtasks", "/Query", "/TN", QQBOT_SCHTASKS_NAME],
                           text=True, capture_output=True)
        return f"schtasks: {QQBOT_SCHTASKS_NAME}" if r.returncode == 0 else "(not installed)"
    return "(unsupported platform)"


def cmd_status():
    print("== scheduled (config.json) ==")
    for k, v in load_scheduled().items():
        print(f"  {k}: {v}")
    print("\n== state ==")
    state = load_state()
    print(f"  last_run: {state.get('last_run') or '(none yet; first run will execute all)'}")
    print(f"  state file: {STATE_FILE}")
    print("\n== autostart ==")
    print(f"  daemon: {_autostart_info()}")
    print(f"  qq-bot: {_qqbot_autostart_info()}")
    print("\n== qq-bot ==")
    qqbot_state = os.path.join(REPO_ROOT, "crawler", "bot-state.json")
    if os.path.exists(qqbot_state):
        try:
            with open(qqbot_state, "r", encoding="utf-8") as f:
                bs = json.load(f)
            print(f"  last_time: {bs.get('last_time') or '(none)'}")
        except Exception:
            print("  last_time: (unreadable)")
    else:
        print("  last_time: (no state yet)")
    print("\n== alarms ==")
    proc = run_py("alarm.py", "list", capture=True)
    print(proc.stdout or "(no alarms)")
    print("\n== git ==")
    r = git("branch", "--show-current", check=False)
    print(f"  branch: {r.stdout.strip()}")
    r = git("status", "-sb", check=False)
    print("  " + "\n  ".join(r.stdout.splitlines()[:3]))
    print("\n== last runs ==")
    print_cmd_log(20)


def print_cmd_log(n):
    if os.path.exists(LOG_FILE):
        with open(LOG_FILE, "r", encoding="utf-8") as f:
            lines = f.readlines()
        print("".join(lines[-n:]), end="")
    else:
        print("(no log yet)")


def cmd_log(n=50):
    print_cmd_log(n)


def cmd_help():
    print(__doc__)


# ---------------------------------------------------------------------------
def main():
    args = sys.argv[1:]
    cmd = args[0] if args else ""
    try:
        if cmd in ("--help", "-h", ""):
            cmd_help()
        elif cmd == "run":
            cmd_run()
        elif cmd == "fire":
            sys.exit(cmd_fire())
        elif cmd == "sync":
            sys.exit(cmd_sync())
        elif cmd == "incremental":
            sys.exit(cmd_incremental())
        elif cmd == "remind":
            sys.exit(cmd_remind())
        elif cmd == "install":
            sys.exit(cmd_install("--system" in args[1:]))
        elif cmd == "uninstall":
            sys.exit(cmd_uninstall("--system" in args[1:]))
        elif cmd == "install-qqbot":
            sys.exit(cmd_install_qqbot("--system" in args[1:]))
        elif cmd == "uninstall-qqbot":
            sys.exit(cmd_uninstall_qqbot("--system" in args[1:]))
        elif cmd == "status":
            cmd_status()
        elif cmd == "log":
            n = int(args[1]) if len(args) > 1 and args[1].isdigit() else 50
            cmd_log(n)
        else:
            print(f"unknown command: {cmd}", file=sys.stderr)
            cmd_help()
            sys.exit(1)
    except KeyboardInterrupt:
        log("interrupted.")
        sys.exit(130)


if __name__ == "__main__":
    main()
