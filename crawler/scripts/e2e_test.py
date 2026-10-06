#!/usr/bin/env python3
"""跨平台端到端（E2E）测试脚本。

用途：在 Linux / Windows 上一键验证「订阅 → 闹钟 → 抓取 → 复盘 → 推送」
链路，以及运行环境依赖与守护进程编排逻辑。所有会写数据的操作都在
.e2e/sandbox 隔离副本里执行（origin 是本地临时裸仓库），不会污染真实仓库、
不会向 GitHub 推送、不会改动真实订阅。

命令：
    .venv/bin/python crawler/scripts/e2e_test.py check      # 环境自检
    .venv/bin/python crawler/scripts/e2e_test.py unit       # 爬虫单元测试
    .venv/bin/python crawler/scripts/e2e_test.py offline    # 离线链路冒烟（不联网）
    .venv/bin/python crawler/scripts/e2e_test.py live --links "https://qoj.ac/contest/3588" --platform qoj
    .venv/bin/python crawler/scripts/e2e_test.py service    # 打印自启服务测试步骤
    .venv/bin/python crawler/scripts/e2e_test.py events     # 打印特殊事件测试清单
    .venv/bin/python crawler/scripts/e2e_test.py all        # check + unit + offline

完整人工测试手册（含睡眠 / 休眠 / 重启 / 断网等特殊情况）：
    docs/e2e-testing.md

说明：本脚本测试的是当前 git HEAD（git archive HEAD）。未提交的改动不会
进入沙箱；正式测试前请先提交。
"""
import argparse
import glob
import io
import json
import os
import platform
import shutil
import socket
import subprocess
import sys
import tarfile
import time
from datetime import datetime, timedelta, timezone

BEIJING = timezone(timedelta(hours=8))

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
E2E_DIR = os.path.join(REPO_ROOT, ".e2e")
SANDBOX = os.path.join(E2E_DIR, "sandbox")
ORIGIN = os.path.join(E2E_DIR, "origin.git")
TMP = os.path.join(E2E_DIR, "tmp")
REPORT_PATH = os.path.join(E2E_DIR, "report.json")

REAL_ENV = os.path.join(REPO_ROOT, ".env")
REAL_CONFIG = os.path.join(REPO_ROOT, "crawler", "config.json")
EXAMPLE_CONFIG = os.path.join(REPO_ROOT, "crawler", "config.example.json")
SCRIPTS = os.path.join("crawler", "scripts")

PLATFORMS = ("qoj", "hdu", "nowcoder")
PLATFORM_HOSTS = {
    "qoj": "qoj.ac",
    "hdu": "acm.hdu.edu.cn",
    "nowcoder": "ac.nowcoder.com",
}
ENV_KEYS = (
    "QOJ_USERNAME", "QOJ_PASSWORD",
    "HDU_USERNAME", "HDU_PASSWORD",
    "NOWCODER_COOKIE_NOWCODERUID", "NOWCODER_COOKIE_T",
    "DEEPSEEK_API_KEY",
)

RESULTS = []


# ---------------------------------------------------------------------------
# 结果收集 / 输出
# ---------------------------------------------------------------------------
ICONS = {"PASS": "[PASS]", "FAIL": "[FAIL]", "WARN": "[WARN]",
         "SKIP": "[SKIP]", "INFO": "[INFO]"}


def record(name, status, detail=""):
    RESULTS.append({"name": name, "status": status, "detail": str(detail)[:2000]})
    print(f"{ICONS.get(status, status)} {name}" + (f" -- {detail}" if detail else ""),
          flush=True)
    return status == "PASS"


def ok(name, cond, detail=""):
    return record(name, "PASS" if cond else "FAIL", detail)


def warn(name, cond, detail=""):
    return record(name, "WARN" if not cond else "PASS", detail)


# ---------------------------------------------------------------------------
# 通用工具
# ---------------------------------------------------------------------------
def run(cmd, cwd=None, env=None, timeout=None):
    """text 模式运行命令，超时返回 returncode=124。"""
    try:
        return subprocess.run(cmd, cwd=cwd, env=env, text=True,
                              capture_output=True, timeout=timeout)
    except subprocess.TimeoutExpired as e:
        out = e.stdout or ""
        err = e.stderr or ""
        if isinstance(out, bytes):
            out = out.decode(errors="replace")
        if isinstance(err, bytes):
            err = err.decode(errors="replace")
        return subprocess.CompletedProcess(cmd, 124, out, err)


def run_bytes(cmd, cwd=None):
    return subprocess.run(cmd, cwd=cwd, capture_output=True)


def tail(text, n=1200):
    text = (text or "").strip()
    return text[-n:]


def infer_platform(link):
    low = (link or "").lower()
    if "qoj.ac" in low:
        return "qoj"
    if "hdu" in low:
        return "hdu"
    if "nowcoder.com" in low:
        return "nowcoder"
    return None


def resolve_chrome():
    """返回 (chrome_binary, chromedriver) 绝对路径，优先环境变量。

    沙箱副本不含 gitignore 的 Chrome 二进制，因此实际运行时通过
    CHROME_BINARY / CHROMEDRIVER_PATH 把真实仓库的二进制传给子进程。
    """
    binary = os.environ.get("CHROME_BINARY")
    driver = os.environ.get("CHROMEDRIVER_PATH")
    if sys.platform.startswith("win"):
        bin_default = os.path.join(REPO_ROOT, "crawler", "chrome-win64", "chrome.exe")
        drv_default = os.path.join(REPO_ROOT, "crawler", "chromedriver-win64", "chromedriver.exe")
    elif sys.platform == "darwin":
        bin_default = "/Applications/Google Chrome.app/Contents/MacOS/Google Chrome"
        matches = sorted(glob.glob(os.path.join(REPO_ROOT, "crawler", "chromedriver-mac*", "chromedriver")))
        drv_default = matches[-1] if matches else None
    else:
        bin_default = os.path.join(REPO_ROOT, "crawler", "chrome-linux64", "chrome")
        drv_default = os.path.join(REPO_ROOT, "crawler", "chromedriver-linux64", "chromedriver")
    if not binary and bin_default and os.path.exists(bin_default):
        binary = bin_default
    if not driver and drv_default and os.path.exists(drv_default):
        driver = drv_default
    return binary, driver


def child_env(headful=False):
    """子进程环境：隔离锁目录 + 传递 Chrome 路径 + 可选非无头。"""
    env = dict(os.environ)
    env["PYTHONUNBUFFERED"] = "1"
    os.makedirs(TMP, exist_ok=True)
    # filelock 的锁文件在 tempfile.gettempdir()；隔离后不会和真实 daemon 抢锁
    env["TMPDIR"] = TMP
    env["TEMP"] = TMP
    env["TMP"] = TMP
    binary, driver = resolve_chrome()
    if binary:
        env["CHROME_BINARY"] = binary
    if driver:
        env["CHROMEDRIVER_PATH"] = driver
    if headful:
        env["CHROME_HEADLESS"] = "0"
    return env


def sandbox_script(script, *args, timeout=None, headful=False):
    path = os.path.join(SANDBOX, SCRIPTS, script)
    return run([sys.executable, path, *args], cwd=SANDBOX,
               env=child_env(headful=headful), timeout=timeout)


def sandbox_git(*args):
    return run(["git", "-c", "core.autocrlf=false", *args], cwd=SANDBOX)


def has_deepseek_key():
    if os.environ.get("DEEPSEEK_API_KEY"):
        return True
    return bool(read_env_file().get("DEEPSEEK_API_KEY"))


def read_env_file(path=REAL_ENV):
    values = {}
    if not os.path.exists(path):
        return values
    try:
        with open(path, "r", encoding="utf-8") as f:
            for line in f:
                line = line.strip()
                if not line or line.startswith("#") or "=" not in line:
                    continue
                key, _, value = line.partition("=")
                values[key.strip()] = value.strip()
    except OSError:
        pass
    return values


# ---------------------------------------------------------------------------
# 环境自检
# ---------------------------------------------------------------------------
def cmd_check(args):
    record("OS", "INFO",
           f"{platform.system()} {platform.release()} ({platform.machine()})")
    record("Python", "INFO", f"{sys.version.split()[0]} @ {sys.executable}")

    missing = []
    for mod in ("croniter", "filelock", "dotenv", "undetected_chromedriver",
                "bs4", "openai", "websocket"):
        try:
            __import__(mod)
        except ImportError:
            missing.append(mod)
    ok("Python dependencies", not missing,
       "all present" if not missing else f"missing: {', '.join(missing)} "
       "(pip install -r crawler/requirements.txt)")

    git = shutil.which("git")
    ok("git", bool(git), git or "not found in PATH")

    binary, driver = resolve_chrome()
    ok("Chrome binary", bool(binary), binary or
       "not found; set CHROME_BINARY or place crawler/chrome-<os> (QOJ/HDU/NowCoder 抓取必需)")
    ok("ChromeDriver", bool(driver), driver or
       "not found; set CHROMEDRIVER_PATH or place crawler/chromedriver-<os>")

    pandoc = shutil.which("pandoc")
    warn("pandoc", bool(pandoc),
         pandoc or "not found; HDU / NowCoder 题面 HTML→Markdown 转换需要它")

    env_values = read_env_file()
    if not os.path.exists(REAL_ENV):
        record("Root .env", "WARN", "not found; 平台登录会失败 (cp .env.example .env)")
    else:
        present = [k for k in ENV_KEYS if env_values.get(k)]
        record("Root .env", "INFO", f"present; filled keys: {', '.join(present) or '(none)'}")
        for key in ("DEEPSEEK_API_KEY",):
            warn(f".env {key}", bool(env_values.get(key)),
                 "set" if env_values.get(key) else "缺失 → 复盘报告不会生成 (report.py 返回 failed)")

    cfg = {}
    if os.path.exists(REAL_CONFIG):
        try:
            with open(REAL_CONFIG, "r", encoding="utf-8") as f:
                cfg = json.load(f)
        except Exception as e:
            record("crawler/config.json", "FAIL", f"parse error: {e}")
    else:
        record("crawler/config.json", "WARN", "not found; 爬虫会认为所有平台禁用")
    if cfg:
        enabled = [p for p in PLATFORMS if cfg.get(p, {}).get("enabled", False)]
        record("Enabled platforms", "INFO", ", ".join(enabled) or "(none)")

    if getattr(args, "no_network", False):
        record("Network", "SKIP", "--no-network")
    else:
        failures = []
        for plat, host in PLATFORM_HOSTS.items():
            try:
                with socket.create_connection((host, 443), timeout=8):
                    pass
            except OSError as e:
                failures.append(f"{host}: {e}")
        warn("Network (443 to platforms)", not failures,
             "reachable" if not failures else "; ".join(failures) +
             "  (代理环境下直连可能失败，仅告警)")
    return RESULTS


# ---------------------------------------------------------------------------
# 单元测试
# ---------------------------------------------------------------------------
def cmd_unit(args):
    tests = os.path.join(REPO_ROOT, "crawler", "tests")
    r = run([sys.executable, "-m", "pytest", tests, "-q"], cwd=REPO_ROOT,
            timeout=getattr(args, "timeout", 600))
    line = ""
    for candidate in reversed((r.stdout or "").splitlines()):
        if "passed" in candidate or "failed" in candidate or "error" in candidate.lower():
            line = candidate
            break
    ok("crawler pytest", r.returncode == 0, line or tail(r.stdout + r.stderr))
    return RESULTS


# ---------------------------------------------------------------------------
# 沙箱
# ---------------------------------------------------------------------------
def build_sandbox(links=None, platforms=None, share=False, history=False):
    """构建隔离测试仓库：git archive HEAD → .e2e/sandbox，origin 为本地裸仓库。

    history=True：订阅不写 end_time（HISTORY，只抓取不生成报告，不调 LLM）。
    history=False：订阅写已过去的 end_time（EXPIRED，抓取 + 复盘）。
    """
    for path in (SANDBOX, ORIGIN):
        if os.path.exists(path):
            shutil.rmtree(path)
    os.makedirs(SANDBOX)
    os.makedirs(TMP, exist_ok=True)

    archived = run_bytes(["git", "archive", "--format=tar", "HEAD"], cwd=REPO_ROOT)
    if archived.returncode != 0:
        raise RuntimeError("git archive failed: " + archived.stderr.decode(errors="replace"))
    with tarfile.open(fileobj=io.BytesIO(archived.stdout)) as tf:
        try:
            tf.extractall(SANDBOX, filter="data")
        except TypeError:  # Python < 3.12
            tf.extractall(SANDBOX)

    # 配置：从真实 config 派生，只启用本次要测的平台
    src = REAL_CONFIG if os.path.exists(REAL_CONFIG) else EXAMPLE_CONFIG
    with open(src, "r", encoding="utf-8") as f:
        cfg = json.load(f)
    platforms = set(platforms or [])
    for plat in PLATFORMS:
        cfg.setdefault(plat, {})["enabled"] = plat in platforms
    cfg.setdefault("ai_tasks", {}).setdefault("report", {})["enabled"] = True
    cfg["ai_tasks"].setdefault("share", {})["enabled"] = bool(share)
    with open(os.path.join(SANDBOX, "crawler", "config.json"), "w", encoding="utf-8") as f:
        json.dump(cfg, f, ensure_ascii=False, indent=2)

    # 订阅：清空归档里带进来的真实订阅，只保留本次测试的 fixture
    sub_dir = os.path.join(SANDBOX, "crawler", "subscriptions")
    if os.path.isdir(sub_dir):
        for name in os.listdir(sub_dir):
            if name.endswith(".json") and not name.endswith(".example.json"):
                os.remove(os.path.join(sub_dir, name))
    os.makedirs(sub_dir, exist_ok=True)
    now = datetime.now(BEIJING)
    entries = []
    if links:
        for link in links:
            entry = {"platform": infer_platform(link), "link": link,
                     "enabled": True, "comments": "e2e live"}
            if not history:
                entry["end_time"] = (now - timedelta(minutes=1)).isoformat()
                entry["start_time"] = (now - timedelta(hours=5)).isoformat()
            entries.append(entry)
    else:
        entries.append({"platform": "qoj", "link": "https://qoj.ac/contest/0",
                        "enabled": True, "comments": "e2e fixture",
                        "end_time": (now + timedelta(hours=2)).isoformat()})
    with open(os.path.join(sub_dir, "e2e.json"), "w", encoding="utf-8") as f:
        json.dump(entries, f, ensure_ascii=False, indent=2)

    if os.path.exists(REAL_ENV):
        shutil.copyfile(REAL_ENV, os.path.join(SANDBOX, ".env"))

    # git 初始化 + 本地裸 origin
    if sandbox_git("init", "-q", "-b", "deploy").returncode != 0:
        sandbox_git("init", "-q")
        sandbox_git("checkout", "-q", "-b", "deploy")
    sandbox_git("config", "user.name", "E2E")
    sandbox_git("config", "user.email", "e2e@example.com")
    sandbox_git("add", "-A")
    sandbox_git("commit", "-q", "-m", "e2e sandbox init")
    run(["git", "init", "-q", "--bare", ORIGIN])
    sandbox_git("remote", "add", "origin", ORIGIN.replace("\\", "/"))
    sandbox_git("push", "-q", "-u", "origin", "deploy")
    return SANDBOX


def _write_subscriptions(entries):
    path = os.path.join(SANDBOX, "crawler", "subscriptions", "e2e.json")
    with open(path, "w", encoding="utf-8") as f:
        json.dump(entries, f, ensure_ascii=False, indent=2)


def _alarms_path():
    return os.path.join(SANDBOX, "crawler", "alarms.json")


def _load_alarms():
    path = _alarms_path()
    if not os.path.exists(path):
        return []
    with open(path, "r", encoding="utf-8") as f:
        raw = json.load(f)
    if isinstance(raw, list):
        return raw
    if isinstance(raw, dict):
        return list(raw.values())
    return []


def _save_alarms(entries):
    with open(_alarms_path(), "w", encoding="utf-8") as f:
        json.dump(entries, f, ensure_ascii=False, indent=2)


def _alarm_by_link(link):
    for e in _load_alarms():
        if (e.get("link") or "").rstrip("/") == link.rstrip("/"):
            return e
    return None


# ---------------------------------------------------------------------------
# 离线链路（不联网、不启动 Chrome、不调 LLM）
# ---------------------------------------------------------------------------
PROBE_SOURCE = '''\
import os
import sys

sys.path.insert(0, os.getcwd())
from crawler.scripts import daemon  # noqa: E402

daemon.ensure_deploy_branch()
if (sys.argv[1] if len(sys.argv) > 1 else "create") == "create":
    folder = "contests/2099-01-01 E2E Probe"
    os.makedirs(folder, exist_ok=True)
    with open(os.path.join(folder, "contest.json"), "w", encoding="utf-8") as f:
        f.write('{"name": "E2E Probe", "link": "https://example.com/e2e-probe"}')
daemon.commit_and_push()
'''


LOCK_HOLDER_SOURCE = '''\
import os
import sys
import tempfile
import time

from filelock import FileLock

ready, seconds = sys.argv[1], float(sys.argv[2]) if len(sys.argv) > 2 else 60.0
lock = FileLock(os.path.join(tempfile.gettempdir(), "training-archive-daemon.lock"))
lock.acquire(timeout=0)
try:
    with open(ready, "w", encoding="utf-8") as f:
        f.write("ready")
    time.sleep(seconds)
finally:
    lock.release()
'''


def cmd_offline(args):
    build_sandbox(platforms={"qoj"})
    now = datetime.now(BEIJING)
    history_link = "https://qoj.ac/contest/901"
    expired_link = "https://qoj.ac/contest/902"
    future_link = "https://qoj.ac/contest/903"

    # 1. plan 分类
    if os.path.exists(_alarms_path()):
        os.remove(_alarms_path())
    _write_subscriptions([
        {"platform": "qoj", "link": history_link, "enabled": True, "comments": "history"},
        {"platform": "qoj", "link": expired_link, "enabled": True,
         "end_time": (now - timedelta(hours=1)).isoformat(), "comments": "expired"},
        {"platform": "qoj", "link": future_link, "enabled": True,
         "end_time": (now + timedelta(hours=2)).isoformat(),
         "start_time": (now + timedelta(hours=-3)).isoformat(), "comments": "future"},
    ])
    r = sandbox_script("alarm.py", "plan")
    out = r.stdout or ""
    ok("alarm plan exit 0", r.returncode == 0, tail(out + r.stderr))
    ok("alarm plan HISTORY", f"HISTORY\t{history_link}" in out)
    ok("alarm plan EXPIRED", f"EXPIRED\t{expired_link}" in out)
    ok("alarm plan future not emitted",
       future_link not in [l.split("\t", 1)[-1] for l in out.splitlines()
                           if l.startswith(("HISTORY\t", "EXPIRED\t", "RETRY\t"))])
    alarm = _alarm_by_link(future_link)
    ok("alarm planned written", bool(alarm) and alarm.get("status") == "planned",
       json.dumps(alarm, ensure_ascii=False) if alarm else "missing")

    # 2. due：把 planned 的 fire_at 拨到过去
    entries = _load_alarms()
    for e in entries:
        if (e.get("link") or "").rstrip("/") == future_link:
            e["fire_at"] = (now - timedelta(minutes=1)).isoformat()
    _save_alarms(entries)
    r = sandbox_script("alarm.py", "due")
    ok("alarm due fires", f"DUE\t{future_link}" in (r.stdout or ""), tail(r.stdout))

    # 3. mark 状态机
    r = sandbox_script("alarm.py", "mark", future_link, "--archived")
    e = _alarm_by_link(future_link)
    ok("alarm mark archived", r.returncode == 0 and e and e.get("status") == "archived",
       e.get("status") if e else "missing")

    r = sandbox_script("alarm.py", "mark", future_link, "--failed")
    e = _alarm_by_link(future_link)
    ok("alarm mark failed", r.returncode == 0 and e and e.get("status") == "failed",
       e.get("status") if e else "missing")
    r = sandbox_script("alarm.py", "plan")
    ok("alarm failed -> RETRY", f"RETRY\t{future_link}" in (r.stdout or ""), tail(r.stdout))
    sandbox_script("alarm.py", "mark", future_link, "--archived")
    e = _alarm_by_link(future_link)
    ok("alarm retry -> archived", e and e.get("status") == "archived")

    # 4. daemon status / 提交推送机制
    r = sandbox_script("daemon.py", "status")
    ok("daemon status exit 0", r.returncode == 0, tail(r.stdout + r.stderr))

    probe = os.path.join(SANDBOX, "_e2e_probe.py")
    with open(probe, "w", encoding="utf-8") as f:
        f.write(PROBE_SOURCE)
    r = run([sys.executable, probe, "create"], cwd=SANDBOX, env=child_env(), timeout=120)
    ok("commit_and_push creates commit", r.returncode == 0, tail(r.stdout + r.stderr))
    log = run(["git", "-C", ORIGIN, "log", "-1", "--pretty=%s", "deploy"])
    ok("origin deploy has [contests-changed]",
       "[contests-changed]" in (log.stdout or ""), tail(log.stdout))
    r = run([sys.executable, probe, "noop"], cwd=SANDBOX, env=child_env(), timeout=120)
    ok("commit_and_push skips when unchanged",
       r.returncode == 0 and "No contest data changes" in (r.stdout or ""),
       tail(r.stdout + r.stderr))

    # 5. 赛前提醒窗口（REMIND）+ 已提醒去重
    remind_link = "https://qoj.ac/contest/904"
    _save_alarms([{
        "platform": "qoj", "link": remind_link, "status": "planned",
        "end_time": (now + timedelta(hours=3)).isoformat(),
        "fire_at": (now + timedelta(hours=3)).isoformat(),
        "start_time": (now + timedelta(minutes=10)).isoformat(),
        "comments": "e2e remind", "attempts": 0,
    }])
    r = sandbox_script("alarm.py", "remind")
    ok("alarm remind in window", f"REMIND	{remind_link}" in (r.stdout or ""), tail(r.stdout))
    sandbox_script("alarm.py", "mark", remind_link, "--reminded")
    r = sandbox_script("alarm.py", "remind")
    ok("alarm remind once", f"REMIND	{remind_link}" not in (r.stdout or ""), tail(r.stdout))

    # 6. 双实例锁：另一进程持锁时 sync 立即跳过
    holder = os.path.join(SANDBOX, "_e2e_lock_holder.py")
    with open(holder, "w", encoding="utf-8") as f:
        f.write(LOCK_HOLDER_SOURCE)
    ready = os.path.join(TMP, "e2e-lock-ready")
    if os.path.exists(ready):
        os.remove(ready)
    proc = subprocess.Popen([sys.executable, holder, ready, "60"], cwd=SANDBOX,
                            env=child_env(), stdout=subprocess.PIPE,
                            stderr=subprocess.STDOUT, text=True)
    waited = 0.0
    while not os.path.exists(ready) and waited < 15:
        time.sleep(0.1)
        waited += 0.1
    ok("lock holder acquired", os.path.exists(ready))
    r = sandbox_script("daemon.py", "sync", timeout=60)
    combined = (r.stdout or "") + (r.stderr or "")
    ok("second instance skips (lock)",
       r.returncode != 0 and "Another task is already running" in combined,
       tail(combined, 300))
    proc.terminate()
    try:
        proc.wait(timeout=10)
    except Exception:
        proc.kill()

    # 7. daemon-state.json 损坏自愈
    with open(os.path.join(SANDBOX, "crawler", "daemon-state.json"), "w", encoding="utf-8") as f:
        f.write("{ this is not json")
    r = sandbox_script("daemon.py", "status")
    ok("corrupt state self-heals", r.returncode == 0 and "last_run" in (r.stdout or ""),
       tail(r.stdout + r.stderr, 300))

    # 8. alarms.json 损坏 → plan 中止（不静默重建）
    with open(_alarms_path(), "w", encoding="utf-8") as f:
        f.write("not-json")
    r = sandbox_script("alarm.py", "plan")
    combined = (r.stdout or "") + (r.stderr or "")
    ok("corrupt alarms aborts plan",
       r.returncode != 0 and "[alarm] ERROR" in combined, tail(combined, 300))
    return RESULTS


# ---------------------------------------------------------------------------
# 实时链路（真实抓取；沙箱内）
# ---------------------------------------------------------------------------
def cmd_live(args):
    links = [l.strip().rstrip("/") for l in args.links.split(",") if l.strip()]
    if not links:
        record("live links", "FAIL", "--links 为空")
        return RESULTS
    platforms = set(args.platform.split(",")) if args.platform else set()
    platforms.update(filter(None, (infer_platform(l) for l in links)))
    unknown = [l for l in links if not infer_platform(l)]
    if unknown:
        record("live links platform", "FAIL",
               f"无法识别平台: {unknown}；请用 --platform 指定")
        return RESULTS

    mode = args.mode
    if mode == "auto":
        mode = "full" if has_deepseek_key() else "crawl"
        record("live mode", "INFO",
               f"auto -> {mode}" + ("" if mode == "full" else
               "（未检测到 DEEPSEEK_API_KEY，只测抓取+推送，不测复盘）"))
    if mode == "full" and not has_deepseek_key():
        record("live mode", "FAIL", "full 模式需要 DEEPSEEK_API_KEY")
        return RESULTS

    record("live links", "INFO", ", ".join(links))
    record("live platforms", "INFO", ", ".join(sorted(platforms)))
    try:
        build_sandbox(links=links, platforms=platforms, share=args.share,
                      history=(mode == "crawl"))
    except Exception as e:
        record("build sandbox", "FAIL", str(e))
        return RESULTS
    record("sandbox", "INFO", SANDBOX)

    started = time.time()
    r = sandbox_script("daemon.py", "sync", timeout=args.timeout, headful=args.headful)
    elapsed = time.time() - started
    out = (r.stdout or "") + "\n" + (r.stderr or "")
    ok("daemon sync exit 0", r.returncode == 0, f"{elapsed:.0f}s; " + tail(out, 800))

    # 验证 alarms 归档
    for link in links:
        e = _alarm_by_link(link)
        ok(f"alarm archived {link}", bool(e) and e.get("status") == "archived",
           (e or {}).get("status", "missing"))

    # 验证比赛数据落盘
    matched = []
    for root, _dirs, files in os.walk(os.path.join(SANDBOX, "contests")):
        if "contest.json" not in files:
            continue
        try:
            with open(os.path.join(root, "contest.json"), "r", encoding="utf-8") as f:
                data = json.load(f)
        except Exception:
            continue
        if str(data.get("link") or "").rstrip("/") in links:
            matched.append((root, data))
    ok("contest folders created", len(matched) == len(links),
       f"{len(matched)}/{len(links)}")

    if mode == "full":
        reviews = [os.path.exists(os.path.join(root, "review.md")) for root, _ in matched]
        ok("review.md generated", bool(matched) and all(reviews),
           " ".join(f"{os.path.basename(r)}={v}" for (r, _), v in zip(matched, reviews)))
    if args.share:
        sent = [os.path.exists(os.path.join(root, "qq-share.sent")) for root, _ in matched]
        warn("qq-share.sent", bool(matched) and all(sent),
             "QQ 分享失败仅告警，不阻断 sync")

    log = run(["git", "-C", ORIGIN, "log", "-1", "--pretty=%s", "deploy"])
    ok("origin deploy has [contests-changed]",
       "[contests-changed]" in (log.stdout or ""), tail(log.stdout))

    if any(tag in out for tag in ("Traceback (most recent call last)", "[ERROR]")):
        record("daemon.log scan", "WARN", "输出中出现 Traceback 或 [ERROR]，请检查 daemon.log")
    else:
        record("daemon.log scan", "PASS", "无 Traceback / [ERROR]")
    return RESULTS


# ---------------------------------------------------------------------------
# 自启服务 / 特殊事件（打印清单）
# ---------------------------------------------------------------------------
def cmd_service(args):
    sysname = platform.system()
    if sys.platform.startswith("win"):
        cmds = [
            "python crawler\\scripts\\daemon.py install",
            'schtasks /Query /TN TrainingArchiveDaemon /V /FO LIST',
            "python crawler\\scripts\\daemon.py status",
            "python crawler\\scripts\\daemon.py uninstall",
        ]
    elif sysname == "Darwin":
        cmds = [
            "python3 crawler/scripts/daemon.py install",
            "launchctl list | grep trainingarchive",
            "python3 crawler/scripts/daemon.py status",
            "python3 crawler/scripts/daemon.py uninstall",
        ]
    else:
        cmds = [
            ".venv/bin/python crawler/scripts/daemon.py install",
            "systemctl --user status training-archive-daemon.service",
            ".venv/bin/python crawler/scripts/daemon.py status",
            ".venv/bin/python crawler/scripts/daemon.py uninstall",
        ]
    record("autostart commands", "INFO", " | ".join(cmds))
    print("\n自启服务测试（对照 docs/e2e-testing.md 第 3 节）：")
    for c in cmds:
        print("  $ " + c)
    print("注意：install 会真正注册当前用户的开机自启并立即启动服务；"
          "测试后务必 uninstall。")
    return RESULTS


def cmd_events(args):
    doc = os.path.join(REPO_ROOT, "docs", "e2e-testing.md")
    events = [
        "睡眠 / 待机（suspend）后恢复",
        "休眠（hibernate）后恢复",
        "关机重启（reboot）",
        "网络断开 / 恢复",
        "进程被杀（kill -9 / 任务管理器结束）",
        "断电 / 非正常退出",
        "双实例并发（锁）",
        "系统时钟 / 时区变化",
        "长时间运行（日志与内存）",
    ]
    record("special events", "INFO", f"{len(events)} 项，详见 {doc}")
    for e in events:
        print("  - " + e)
    return RESULTS


# ---------------------------------------------------------------------------
# 汇总
# ---------------------------------------------------------------------------
def summarize():
    counts = {"PASS": 0, "FAIL": 0, "WARN": 0, "SKIP": 0, "INFO": 0}
    for r in RESULTS:
        counts[r["status"]] = counts.get(r["status"], 0) + 1
    print("\n" + "=" * 64)
    print(f"结果: PASS={counts['PASS']} FAIL={counts['FAIL']} "
          f"WARN={counts['WARN']} SKIP={counts['SKIP']} INFO={counts['INFO']}")
    failures = [r for r in RESULTS if r["status"] == "FAIL"]
    if failures:
        print("失败项:")
        for r in failures:
            print(f"  - {r['name']}: {r['detail']}")
    os.makedirs(E2E_DIR, exist_ok=True)
    try:
        with open(REPORT_PATH, "w", encoding="utf-8") as f:
            json.dump({"timestamp": datetime.now(BEIJING).isoformat(),
                       "os": f"{platform.system()} {platform.release()}",
                       "python": sys.version.split()[0],
                       "results": RESULTS}, f, ensure_ascii=False, indent=2)
        print(f"报告已写入: {REPORT_PATH}")
    except OSError as e:
        print(f"写入报告失败: {e}")
    return 1 if failures else 0


def main(argv=None):
    parser = argparse.ArgumentParser(description="Training Archive 跨平台 E2E 测试")
    sub = parser.add_subparsers(dest="command")

    p = sub.add_parser("check", help="环境自检")
    p.add_argument("--no-network", action="store_true", help="跳过网络连通性检查")
    p = sub.add_parser("unit", help="运行爬虫 pytest")
    p.add_argument("--timeout", type=int, default=600)
    sub.add_parser("offline", help="离线链路冒烟（不联网）")
    p = sub.add_parser("live", help="实时链路（真实抓取，沙箱内）")
    p.add_argument("--links", required=True, help="逗号分隔的测试比赛链接")
    p.add_argument("--platform", default="", help="逗号分隔平台（缺省从链接推断）")
    p.add_argument("--mode", choices=["auto", "crawl", "full"], default="auto",
                   help="crawl=只抓取+推送; full=抓取+复盘+推送")
    p.add_argument("--share", action="store_true", help="同时测试 QQ 分享")
    p.add_argument("--headful", action="store_true",
                   help="CHROME_HEADLESS=0（QOJ 反爬需要；Linux 需配合 xvfb-run）")
    p.add_argument("--timeout", type=int, default=3600)
    p = sub.add_parser("service", help="打印自启服务测试步骤")
    p = sub.add_parser("events", help="打印特殊事件测试清单")
    p = sub.add_parser("all", help="check + unit + offline")

    args = parser.parse_args(argv)
    cmd = args.command or "check"

    try:
        if cmd == "check":
            cmd_check(args)
        elif cmd == "unit":
            cmd_unit(args)
        elif cmd == "offline":
            cmd_offline(args)
        elif cmd == "live":
            cmd_live(args)
        elif cmd == "service":
            cmd_service(args)
        elif cmd == "events":
            cmd_events(args)
        elif cmd == "all":
            cmd_check(args)
            cmd_unit(args)
            cmd_offline(args)
    except KeyboardInterrupt:
        record("interrupted", "WARN", "Ctrl+C")
    return summarize()


if __name__ == "__main__":
    sys.exit(main())
