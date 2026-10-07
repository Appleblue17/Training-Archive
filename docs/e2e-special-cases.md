# 特殊情况测试操作手册（Linux 完整指令版）

> 配套 [docs/e2e-testing.md](e2e-testing.md) 第 7 节，给出**可直接复制执行的完整指令**。
> 当前状态（诚实说明）：
> - 已自动化并由 `e2e_test.py offline` 实际跑通：**7.6 状态损坏**、**7.7 双实例锁**（另含赛前提醒）。
> - 尚未在 Linux 上实机执行：**7.1 睡眠 / 7.2 休眠 / 7.3 重启 / 7.4 断网 / 7.5 进程被杀 /
>   7.8 时区 / 7.9 长时运行**——这些需要真实的挂起 / 重启 / 断网操作，本手册把步骤补齐。

---

## 0. 重要安全前提

`daemon.py sync / fire / incremental` 会调用 `ensure_deploy_branch()`：**在所在仓库
`git checkout deploy` 并 `git pull origin deploy`**，成功爬取后还会 `git push origin deploy`。

> ⚠️ **绝对不要在上面的开发仓库直接跑这些命令**（会切分支并推送到真实 GitHub）。
> 下面所有步骤都在 `e2e_test.py` 构建的 **隔离沙箱 `.e2e/sandbox`** 内执行；
> 该沙箱的 `origin` 是本地裸仓库 `.e2e/origin.git`，不会碰 GitHub。

---

## 1. 通用准备（每个子项开始前先执行一次）

```bash
# 1.1 变量（按你的仓库路径）
REAL=/home/miniese/github/Training-Archive
PY="$REAL/.venv/bin/python"
SB="$REAL/.e2e/sandbox"

# 1.2 构建隔离沙箱（--platform nowcoder 只是示例，按需换平台）
cd "$REAL"
"$PY" crawler/scripts/e2e_test.py sandbox --platform nowcoder
cd "$SB"

# 1.3 Chrome / driver 指向真实仓库自带的二进制（沙箱不含未跟踪的二进制）
export CHROME_BINARY="$REAL/crawler/chrome-linux64/chrome"
export CHROMEDRIVER_PATH="$REAL/crawler/chromedriver-linux64/chromedriver"
#    QOJ 需要非无头 + 虚拟显示：export CHROME_HEADLESS=0，并用 xvfb-run -a 包裹命令

# 1.4 让调度变成"每分钟"，方便观察（incremental 设为几乎不跑，避免频繁真实抓取）
"$PY" - <<'PY'
import json
p = "crawler/config.json"
cfg = json.load(open(p, encoding="utf-8"))
cfg["scheduled"] = {
    "fire": "* * * * *",
    "sync": "* * * * *",
    "remind": "* * * * *",
    "incremental": "0 0 1 1 *",
}
json.dump(cfg, open(p, "w", encoding="utf-8"), ensure_ascii=False, indent=2)
print(cfg["scheduled"])
PY

# 1.5 调度/重启类测试：清空订阅，让任务只记日志、不真正抓取（断网测试除外，见 §5）
rm -f crawler/subscriptions/*.json

# 1.6 常用观察命令
"$PY" crawler/scripts/daemon.py status          # 计划 / 状态 / 闹钟 / git
tail -n 50 crawler/daemon.log
cat crawler/daemon-state.json
cat crawler/alarms.json 2>/dev/null
```

> 沙箱内路径均相对 `$SB`；`$PY` 始终指向**真实仓库的 venv**，别用沙箱里没有的 python。

---

## 2. 7.1 睡眠 / 待机（suspend）后恢复

**目的**：睡眠期间错过调度，恢复时每个任务**只补跑一次**、不追赶历史。

```bash
# 2.1 前台启动主循环（建议放 tmux：tmux new -s ta）
cd "$SB"
"$PY" crawler/scripts/daemon.py run
#    看到 "=== daemon run started ===" 与 "scheduled: ..." 后保持运行

# 2.2 另开一个终端，记录基线
"$PY" "$SB/crawler/scripts/daemon.py" status
tail -n 5 "$SB/crawler/daemon.log"

# 2.3 触发睡眠（三选一）
sudo systemctl suspend          # 通用
sudo pm-suspend                 # 部分发行版
# 或笔记本合盖（若配置为 suspend）

# 2.4 唤醒后等待 >= 90 秒（POLL_INTERVAL=30s + 每分钟任务），然后观察
tail -n 40 "$SB/crawler/daemon.log" | grep -E "task due|run started|sync done|fire"
cat "$SB/crawler/daemon-state.json"
pgrep -af "crawler/scripts/daemon.py run"
```

- **预期**：唤醒后日志出现每个到期任务的 `[run] task due: <task>`；`daemon-state.json` 的
  `last_run` 更新为唤醒后时间；同一任务不会连续爆发式重跑。
- **通过标准**：进程仍在；每个到期任务恢复后只跑一次；`last_run` 前进到唤醒时刻。
- **证据**：`tail -n 100 crawler/daemon.log` + `cat crawler/daemon-state.json`。

---

## 3. 7.2 休眠（hibernate）后恢复

与 §2 相同，仅挂起命令不同；若休眠导致会话重启，则按 §4 的「服务自启」验证恢复。

```bash
sudo systemctl hibernate        # 需要 swap >= 内存；否则改用 suspend
# 恢复后：
"$PY" "$SB/crawler/scripts/daemon.py" status
grep -E "daemon run started|task due" "$SB/crawler/daemon.log" | tail -n 20
```

- **预期**：状态文件保留；恢复后按 `last_run` 判断，不重复也不永久跳过。
- **通过标准**：与 §2 相同；若进程重启，`daemon.log` 出现新的 `=== daemon run started ===`。

---

## 4. 7.3 关机重启（reboot）

**目的**：验证 `install` 注册的自启在重启后自动拉起调度。

```bash
# 4.1 注册自启（在沙箱内，只影响当前用户的 systemd user unit）
cd "$SB"
"$PY" crawler/scripts/daemon.py install
systemctl --user status training-archive-daemon.service --no-pager
"$PY" crawler/scripts/daemon.py status          # autostart: systemd user unit

# 4.2 重启
sudo reboot

# 4.3 重启并登录后
systemctl --user is-active training-archive-daemon.service     # 期望 active
systemctl --user status training-archive-daemon.service --no-pager
"$PY" "$SB/crawler/scripts/daemon.py" status
grep "daemon run started" "$SB/crawler/daemon.log" | tail -n 2

# 4.4 测试完务必注销，避免留下 systemd unit
"$PY" "$SB/crawler/scripts/daemon.py" uninstall
systemctl --user status training-archive-daemon.service --no-pager   # 期望 not found
```

- **预期**：登录后服务自动 active；`daemon.log` 出现新的 `=== daemon run started ===`；
  首次迭代对每个任务判定到期并各跑一次。
- **通过标准**：无需人工干预即恢复；`daemon.py status` 显示 unit 已安装且活跃。
- **⚠️ 已知缺口（发现项）**：`install` 生成的 unit 是
  `ExecStart=<venv python> <repo>/crawler/scripts/daemon.py run`，**不含** `CHROME_BINARY` /
  `CHROMEDRIVER_PATH` / `DISPLAY` / `xvfb-run`，也没有 `Environment=`。因此服务方式下
  真实抓取任务需要这些环境时**可能失败**（日志会记录，daemon 不退出）。沙箱内因订阅已清空，
  调度本身可正常验证。若要服务方式实抓，需要给 unit 加 `Environment=` 或用 wrapper；
  这属于 v1.0.0 可选加固项，等你决定。
- **补充验证**（可选）：`install --system`（需 sudo，写 `/etc/systemd/system`）同理，
  用 `uninstall --system` 注销。

---

## 5. 7.4 网络断开 / 恢复

**目的**：断网时爬取失败 → 标记 `failed`、不提交；恢复后 `sync` 输出 `RETRY` 并重试。

```bash
# 5.1 构建带真实链接的沙箱（HISTORY：只抓取不调 LLM，避免 token）
cd "$REAL"
"$PY" crawler/scripts/e2e_test.py sandbox --platform nowcoder --links "https://ac.nowcoder.com/acm/contest/108303"
cd "$SB"
export CHROME_BINARY="$REAL/crawler/chrome-linux64/chrome"
export CHROMEDRIVER_PATH="$REAL/crawler/chromedriver-linux64/chromedriver"
cat crawler/subscriptions/e2e.json          # 确认只有该链接、无 end_time

# 5.2 记录基线
git -C "$REAL/.e2e/origin.git" log -1 --pretty=%s deploy

# 5.3 断网（三选一；先 ip link 看网卡名）
IFACE=$(ip route get 1.1.1.1 | awk '{print $5; exit}'); echo "$IFACE"
sudo ip link set dev "$IFACE" down
# 或：nmcli networking off
# 或：拔网线 / 关 Wi-Fi

# 5.4 触发一次 sync（可直接跑，无需 run 循环）
"$PY" crawler/scripts/daemon.py sync; echo "sync exit=$?"
tail -n 30 crawler/daemon.log
cat crawler/alarms.json
git -C "$REAL/.e2e/origin.git" log -1 --pretty=%s deploy   # 期望与 5.2 相同（无新提交）

# 5.5 恢复网络后重试
sudo ip link set dev "$IFACE" up
"$PY" crawler/scripts/daemon.py sync; echo "sync exit=$?"
cat crawler/alarms.json
git -C "$REAL/.e2e/origin.git" log -1 --pretty=%s deploy   # 期望出现 [contests-changed]
```

- **预期**：断网时 `scheduled_task.py` 非零 → daemon 打印
  `Sync crawl failed; marking involved alarms as failed.`，对应链接 `status=failed`，**不提交**；
  恢复后 `sync` 输出 `RETRY`，成功则 `archived` 并推送。
- **通过标准**：失败被显式标记且可恢复；数据不丢、不误标 archived。

**无权限断网时的模拟**（不改动真实网卡，仅模拟抓取失败）：

@@@@bash
# 把要测平台的 base_url 指向不可达端口，制造抓取失败
"$PY" - <<'PY'
import json
p = "crawler/config.json"
cfg = json.load(open(p, encoding="utf-8"))
cfg["nowcoder"]["base_url"] = "http://127.0.0.1:9"
json.dump(cfg, open(p, "w", encoding="utf-8"), ensure_ascii=False, indent=2)
PY
"$PY" crawler/scripts/daemon.py sync; echo "exit=$?"     # 期望非 0；alarms 链接 status=failed
# 恢复后
"$PY" - <<'PY'
import json
p = "crawler/config.json"
cfg = json.load(open(p, encoding="utf-8"))
cfg["nowcoder"]["base_url"] = "https://ac.nowcoder.com"
json.dump(cfg, open(p, "w", encoding="utf-8"), ensure_ascii=False, indent=2)
PY
"$PY" crawler/scripts/daemon.py sync; echo "exit=$?"     # 期望 RETRY 后 archived 并推送
@@@@

---

## 6. 7.5 进程被杀（kill -9）

```bash
# 6.1 启动主循环
cd "$SB"
"$PY" crawler/scripts/daemon.py run &
PID=$!; echo "PID=$PID"
sleep 3

# 6.2 强杀（用 ps -p "$PID" 判断，避免 pgrep -f 匹配到外层 shell 命令行）
kill -9 "$PID"
sleep 1
ps -p "$PID" >/dev/null 2>&1 && echo "仍在运行(FAIL)" || echo "已停止"

# 6.3 残留锁文件不会阻塞（filelock 用 OS 锁，文件存在与否无关）
touch /tmp/training-archive-daemon.lock
"$PY" crawler/scripts/daemon.py sync; echo "exit=$?"     # 期望正常执行，不输出 Another task
rm -f /tmp/training-archive-daemon.lock

# 6.4 重启主循环，确认可立即恢复
"$PY" crawler/scripts/daemon.py run &
sleep 2; pgrep -af "crawler/scripts/daemon.py run"
kill %1 2>/dev/null
```

- **预期**：强杀后无残留锁问题，可立即重启。
- **通过标准**：6.3 的 `sync` 不出现 `Another task is already running`。

---

## 7. 7.6 断电 / 非正常退出（状态损坏自愈）

已由 `e2e_test.py offline` 自动覆盖；想手工复核：

```bash
cd "$SB"

# 7.6.1 daemon-state.json 损坏 → status 不崩溃、last_run 重置
printf '{ this is not json' > crawler/daemon-state.json
"$PY" crawler/scripts/daemon.py status; echo "status exit=$?"
grep "failed to read" crawler/daemon.log | tail -n 1

# 7.6.2 alarms.json 损坏 → plan 报错中止（不静默重建）
printf 'not-json' > crawler/alarms.json
"$PY" crawler/scripts/alarm.py plan; echo "plan exit=$?"   # 期望非 0 + [alarm] ERROR
rm -f crawler/alarms.json
```

- **通过标准**：`status` 退出 0 且自愈；`plan` 非 0 并给出 `[alarm] ERROR`。
- **说明**：两处写入已改为原子写入（`crawler/scripts/jsonio.py`），正常断电不再产生截断 JSON。

---

## 8. 7.7 双实例并发（锁）

已由 `offline` 自动覆盖；手工复核：

```bash
# 终端 A：占用全局锁 60 秒
"$PY" - <<'PY'
import tempfile, time
from filelock import FileLock
lock = FileLock(tempfile.gettempdir() + "/training-archive-daemon.lock")
lock.acquire(timeout=0)
print("holding lock 60s"); time.sleep(60)
PY

# 终端 B（趁 A 持锁时执行）
cd "$SB"
"$PY" crawler/scripts/daemon.py sync; echo "exit=$?"
# 期望输出：Another task is already running, skip this run. 且 exit=1
```

- **通过标准**：第二个实例立即跳过、退出码 1，不并发抓取/提交。

---

## 9. 7.8 系统时钟 / 时区变化

```bash
cd "$SB"

# 9.1 以非 UTC+8 时区运行
TZ=America/New_York "$PY" crawler/scripts/daemon.py sync; echo "exit=$?"

# 9.2 日志时间戳应为北京时间（UTC+8），与宿主时区无关
tail -n 5 crawler/daemon.log
date          # 对比：宿主时区可能不同

# 9.3 可选：改系统时区后重复（测完改回）
#     sudo timedatectl set-timezone America/New_York
#     sudo timedatectl set-timezone Asia/Shanghai
```

- **预期 / 通过标准**：`daemon.log` 时间戳始终为 UTC+8；调度按北京时间计算。

---

## 10. 7.9 长时间运行（日志与资源）

```bash
cd "$SB"

# 10.1 后台常驻并周期采样
nohup "$PY" crawler/scripts/daemon.py run >/tmp/ta-run.out 2>&1 &
PID=$!; echo "PID=$PID"
for i in $(seq 1 10); do
  printf "%s rss=%s log=%s\n" "$(date +%H:%M:%S)" "$(ps -o rss= -p $PID 2>/dev/null | tr -d ' ')" "$(du -h crawler/daemon.log | cut -f1)"
  sleep 60
done

# 10.2 轮转快速验证（把上限临时调成 100 字节，触发一次轮转）
"$PY" - <<'PY'
import os
from crawler.scripts import daemon
daemon.LOG_MAX_BYTES = 100
daemon.log("rotation smoke test")
print("backup exists:", os.path.exists(daemon.LOG_BACKUP_FILE))
PY

kill "$PID" 2>/dev/null
```

- **预期**：长时间无崩溃；`daemon.log` 达 10MB 时轮转为 `daemon.log.1`，当前文件变小。
- **通过标准**：24 小时无崩溃；日志不无限增长；`daemon.log.1` 按预期出现。

---

## 11. 一键顺序（照抄执行）

```bash
REAL=/home/miniese/github/Training-Archive
PY="$REAL/.venv/bin/python"

# 准备
cd "$REAL" && "$PY" crawler/scripts/e2e_test.py sandbox --platform nowcoder
cd "$REAL/.e2e/sandbox"
export CHROME_BINARY="$REAL/crawler/chrome-linux64/chrome"
export CHROMEDRIVER_PATH="$REAL/crawler/chromedriver-linux64/chromedriver"
rm -f crawler/subscriptions/*.json

# 7.1/7.2/7.5/7.9：按上文各节命令执行，再做挂起/重启
# 7.3：install -> reboot -> status -> uninstall（见 §4）
# 7.4：用带真实链接的 sandbox（见 §5）
# 7.6/7.7：见 §7、§8（或直接 "$PY" crawler/scripts/e2e_test.py offline）
```

---

## 12. 实机执行结果（2026-10-07，Ubuntu / Linux）

下列**非破坏性**子项已在本机隔离沙箱实际执行并通过：

| 子项 | 方式 | 结果 |
|------|------|------|
| 7.5 进程被杀 | `kill -9` run 进程后 `ps -p $PID` | 进程消失；再 `touch` 残留锁文件后 `sync` 仍退出 0，未被 "Another task" 阻塞 |
| 7.6 状态损坏 | 写坏 `daemon-state.json` / `alarms.json` | `status` 退出 0 自愈；`plan` 退出 1 并输出 `[alarm] ERROR` |
| 7.7 双实例锁 | 另一进程持锁时跑 `sync` | 退出 1，输出 `Another task is already running, skip this run.` |
| 7.8 时区 | `TZ=America/New_York sync` | 宿主 UTC 04 / NY 00 时，日志时间戳 `2026-10-07 12:08:52`（恰为 UTC+8），确认按北京时间 |
| 7.9 轮转 | 临时 `LOG_MAX_BYTES=100` 记一条日志 | 生成 `daemon.log.1`，`backup_exists: True` |
| 7.1 / 7.2 睡眠·休眠（**模拟**） | `last_run` 设为 30 分钟前（错过约 6 次 `*/5`），跑 `run` 75s | 每个任务**只补跑 1 次**，`last_run` 前进到恢复时刻 |
| 7.4 断网（**模拟**） | `nowcoder.base_url` 指向不可达端口 | `sync` 退出 1、链接 `status=failed`（attempts=1）、origin 无新提交；恢复后 `RETRY` → `archived` + `[contests-changed]` |

**仍需你实机执行**（真实 OS 操作）：7.1 真实睡眠、7.2 真实休眠、7.3 关机重启、7.4 真实断网
（模拟只能覆盖核心逻辑，不能覆盖 OS 挂起/重启后的进程与服务行为）。

---

## 附：Windows 差异（供后续）

- 命令换成 `.venv/Scripts/python.exe`；锁文件在 `%TEMP%/training-archive-daemon.lock`。
- 睡眠/休眠用「开始菜单 -> 电源」或 `powercfg`；重启后自启是 **schtasks ONLOGON**，
  查看 `schtasks /Query /TN TrainingArchiveDaemon /V /FO LIST`，注销 `daemon.py uninstall`。
- 断网用「网络和 Internet -> 禁用适配器」或 `Disable-NetAdapter`。
- 杀进程用任务管理器，或 `Stop-Process -Id <pid> -Force`。
- QOJ 需 `$env:CHROME_HEADLESS="0"` 且保持桌面会话。
- 详见 [docs/e2e-testing.md](e2e-testing.md) 第 6 节与附录 B。
