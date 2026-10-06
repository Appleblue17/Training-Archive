# 端到端测试手册（E2E Testing）

> 面向 v1.0.0-beta 的跨平台验收手册。覆盖「订阅 → 闹钟 → 抓取 → 复盘 → 推送 → 部署」
> 全链路，以及睡眠 / 休眠 / 重启 / 断网 / 进程被杀 / 断电等特殊情况。
> 自动化脚本：`crawler/scripts/e2e_test.py`；本手册是判定的单一事实来源。

---

## 1. 目的与范围

1. 验证在 **Linux** 与 **Windows 11** 上，自托管守护进程链路可完整跑通。
2. 验证异常/边界情况下的行为可预期、可恢复、不丢数据、不重复推送。
3. 记录证据，作为 v1.0.0-beta.1 预发布的放行依据。

不在本轮范围：macOS（已决定暂不实测）、动态版（v1.x）。

---

## 2. 测试环境矩阵

| 项 | Linux | Windows 11 |
|----|-------|------------|
| 发行版 / 版本 | （填写） | （填写） |
| Python | 3.12+（`.venv`） | 3.12+（`.venv`） |
| Chrome | `crawler/chrome-linux64/chrome` 或系统 Chrome | `crawler/chrome-win64/chrome.exe` 或系统 Chrome |
| ChromeDriver | `crawler/chromedriver-linux64/chromedriver` | `crawler/chromedriver-win64/chromedriver.exe` |
| pandoc | `pandoc --version` | `pandoc --version`（HDU/NowCoder 需要） |
| 自启机制 | systemd user / `install --system` | schtasks ONLOGON |
| 非无头（QOJ 反爬） | `xvfb-run -a env CHROME_HEADLESS=0` | 交互式桌面会话 + `CHROME_HEADLESS=0` |

---

## 3. 一次性准备

### 3.1 公共

```bash
# 1. 依赖
python3 -m venv .venv
.venv/bin/pip install -r crawler/requirements-dev.txt   # 含 requirements.txt
# Windows: .venv/Scripts/pip install -r crawler/requirements-dev.txt

# 2. 凭据
cp .env.example .env      # 填入 QOJ/HDU/NowCoder（见 .env.example 注释）
                          # 建议同时填 DEEPSEEK_API_KEY 以测试复盘

# 3. 爬虫配置（本机自用，gitignore）
cp crawler/config.example.json crawler/config.json
# 在 config.json 中把要测试的平台 enabled 置为 true

# 4. 确认 git 可用且能 push 到 origin
git status
```

### 3.2 Linux

```bash
sudo apt install pandoc
# QOJ 需要虚拟显示 + 非无头：
sudo apt install xvfb
```

### 3.3 Windows 11

1. 安装 Python 3.12+（勾选 Add to PATH）与 Git for Windows；安装 pandoc：`winget install --id JohnMacFarlane.Pandoc`。
2. Chrome 与 chromedriver **大版本必须一致**：
   - 用系统 Chrome 时，从 https://googlechromelabs.github.io/chrome-for-testing/ 下载同版本 driver，
     放到 `crawler/chromedriver-win64/chromedriver.exe`，或设 `CHROMEDRIVER_PATH`。
   - 也可用 `CHROME_BINARY` 指向自备 Chrome。
3. PowerShell 中准备 venv（同 3.1，用 `.venv/Scripts/pip`）。
4. 若测试 QOJ：`$env:CHROME_HEADLESS = "0"`，并保持交互式桌面（不能作为无桌面服务运行）。

---

## 4. 自动化 E2E 脚本

脚本位于 `crawler/scripts/e2e_test.py`，跨平台、无第三方依赖（仅标准库）。
**所有写操作都在 `.e2e/sandbox` 隔离副本内**：origin 是本地临时裸仓库，
不会污染真实 `contests/`、不会向 GitHub 推送、不会改动真实订阅。

```bash
.venv/bin/python crawler/scripts/e2e_test.py check [--no-network]
.venv/bin/python crawler/scripts/e2e_test.py unit
.venv/bin/python crawler/scripts/e2e_test.py offline
.venv/bin/python crawler/scripts/e2e_test.py live --links "<链接>" [--platform qoj] [--mode auto|crawl|full] [--share] [--headful]
.venv/bin/python crawler/scripts/e2e_test.py service
.venv/bin/python crawler/scripts/e2e_test.py events
.venv/bin/python crawler/scripts/e2e_test.py all
```

结果同时在终端汇总并写入 `.e2e/report.json`；任一 `FAIL` 时退出码为 1。

### 4.1 `check`
自检：OS、Python、依赖（croniter/filelock/dotenv/undetected_chromedriver/bs4/openai/websocket）、
git、Chrome 与 driver、pandoc、`.env` 关键字段、`config.json` 启用平台、平台网络连通性。
→ **预期**：依赖/Chrome/driver 三项必须 PASS；pandoc 与网络失败仅 WARN。

### 4.2 `unit`
运行 `crawler/tests` pytest。
→ **预期**：全部通过（当前 205 条）。

### 4.3 `offline`
在沙箱内、不联网、不启 Chrome、不调 LLM，验证编排逻辑：
`alarm` 分类（HISTORY/EXPIRED/future→planned）、`due` 触发、`mark` 状态机
（archived/failed/RETRY→archived）、赛前提醒窗口与去重、**双实例锁**、
**daemon-state.json 损坏自愈**、**alarms.json 损坏中止**、`daemon status`、
`commit_and_push`（有变化才提交 `[contests-changed]`，无变化跳过）。
→ **预期**：全部 PASS（基线 20 项）。其中 7.6、7.7 已由本阶段自动覆盖。
该阶段已纳入 CI（`crawler-tests.yml` 的 `e2e-offline` job，ubuntu + windows 双矩阵）。

### 4.4 `live`
在沙箱内对真实链接执行 `daemon.py sync`：
- `--mode crawl`：订阅按 HISTORY 处理 → 只抓取 + 提交推送，**不调 LLM**。
- `--mode full`：订阅按 EXPIRED 处理 → 抓取 + 生成 `review.md` + 提交推送（**消耗 DeepSeek token**）。
- `--mode auto`（默认）：有 `DEEPSEEK_API_KEY` 则 full，否则 crawl。
- `--share`：同时验证 QQ 群分享（发送失败仅 WARN）。
→ **预期**：`daemon sync` 退出码 0；闹钟归档；比赛目录与 `review.md` 落盘；
本地裸 origin 的 `deploy` 最新提交带 `[contests-changed]`。

### 4.5 `service` / `events`
分别打印「自启服务测试步骤」与「特殊事件测试清单」（见第 7 节）。

### 4.6 沙箱机制

`git archive HEAD` → `.e2e/sandbox`（**只含已提交的 HEAD**，未提交改动不进入；测试前先提交）；
真实 `.env` 被复制进沙箱；Chrome 路径通过 `CHROME_BINARY` / `CHROMEDRIVER_PATH` 注入；
`TMPDIR/TEMP/TMP` 指向 `.e2e/tmp`，使 filelock 锁与真实 daemon 隔离。
沙箱保留在 `.e2e/`（已 gitignore）供事后检查。

---

## 5. Linux 端全链路步骤

```bash
cd /path/to/Training-Archive
.venv/bin/python crawler/scripts/e2e_test.py check          # 1. 环境
.venv/bin/python crawler/scripts/e2e_test.py unit           # 2. 单测
.venv/bin/python crawler/scripts/e2e_test.py offline        # 3. 离线链路

# 4. 实时链路 - 只抓取 + 推送（不花 token）
.venv/bin/python crawler/scripts/e2e_test.py live --links "https://ac.nowcoder.com/acm/contest/108303" --platform nowcoder --mode crawl

# 5. 实时链路 - 抓取 + 复盘 + 推送（QOJ 反爬需 xvfb + 非无头）
xvfb-run -a .venv/bin/python crawler/scripts/e2e_test.py live --links "https://qoj.ac/contest/3588" --platform qoj --mode full --headful
```

**预期**：每步退出码 0；`.e2e/sandbox/contests/<date> <name>/` 生成
`contest.json` / `problems/` / `submissions.json`，full 模式还有 `review.md`；
`git -C .e2e/origin.git log -1 --pretty=%s deploy` 含 `[contests-changed]`。

---

## 6. Windows 11 端全链路步骤

PowerShell：

```powershell
cd C:/path/to/Training-Archive
.venv/Scripts/python.exe crawler/scripts/e2e_test.py check
.venv/Scripts/python.exe crawler/scripts/e2e_test.py unit
.venv/Scripts/python.exe crawler/scripts/e2e_test.py offline

# 实时链路（NowCoder/HDU 可直接无头；HDU/NowCoder 题面需要 pandoc）
.venv/Scripts/python.exe crawler/scripts/e2e_test.py live --links "https://ac.nowcoder.com/acm/contest/108303" --platform nowcoder --mode full

# QOJ：必须非无头（保持桌面会话）
$env:CHROME_HEADLESS = "0"
.venv/Scripts/python.exe crawler/scripts/e2e_test.py live --links "https://qoj.ac/contest/3588" --platform qoj --mode full --headful
```

**预期**：同第 5 节。特别注意 Windows 上验证中文路径/比赛名、`pandoc` 可用性、
以及子进程编码（若出现 `UnicodeDecodeError` 请记录并反馈，这是本轮重点观察项）。

---

## 7. 特殊情况测试（核心）

> 这些事件无法完全自动化。每条给出：操作 → 预期 → 验证 → 通过标准。
> 建议在**前台运行** `.venv/bin/python crawler/scripts/daemon.py run` 观察日志，
> 或安装服务后操作。`daemon.py status` / `daemon.py log` 随时可查。

### 7.1 睡眠 / 待机（suspend）

- **目的**：验证睡眠期间错过调度后，恢复时**每个任务只补跑一次**、不追赶历史。
- **操作**：让 daemon 运行；记下当前时间；系统睡眠 10~30 分钟后唤醒。
- **预期**：唤醒后 30 秒内（`POLL_INTERVAL`），日志出现 `[run] task due: <task>`；
  随后 `daemon-state.json` 的 `last_run` 更新为唤醒时刻；同一任务不会连续重复触发。
- **验证**：`tail -n 50 crawler/daemon.log` 查 `task due` / `run started`；`cat crawler/daemon-state.json`。
- **通过标准**：恢复后每个到期任务只执行一次；无重复抓取、无重复推送。

### 7.2 休眠（hibernate）

- 与 7.1 相同，但会话可能是重启后的新进程。若 `install` 已注册，恢复后服务由系统拉起；
  若未注册，需手动 `daemon.py run`。
- **通过标准**：状态文件保留；重启/恢复后任务按 `last_run` 判断，不重复也不永久跳过。

### 7.3 关机重启（reboot）

- **前置**：`daemon.py install`（Linux systemd user / Windows schtasks ONLOGON）。
- **操作**：重启系统并登录；等待 1~2 分钟。
- **预期**：服务自动启动；`daemon.log` 出现新的 `=== daemon run started ===`；
  首次迭代对每个任务判定到期并各跑一次。
- **验证**：Linux `systemctl --user status training-archive-daemon.service`；
  Windows `schtasks /Query /TN TrainingArchiveDaemon /V /FO LIST`；通用 `daemon.py status`。
- **通过标准**：重启后无需人工干预即恢复调度；`contests/` 无重复数据。

### 7.4 网络断开 / 恢复

- **操作**：daemon 运行中，禁用网卡；手动触发一次 `daemon.py sync`（或等待到点）。
  恢复网络后再次 `daemon.py sync`。
- **预期**：
  1. 断网时爬取失败 → `scheduled_task.py` 非零退出 → daemon 把本次涉及链接
     `mark --failed`，**不提交、不推送**；日志含 `Sync crawl failed; marking involved alarms as failed.`。
  2. 恢复后 `sync` 输出 `RETRY` 并重试一次；成功则 `archived`，失败保持 `failed`。
- **验证**：`crawler/alarms.json` 中链接 `status` 变化；本地 origin 无新提交。
- **通过标准**：失败被显式标记且可重试；数据不丢、不误标 archived。

### 7.5 进程被杀（kill -9 / 任务管理器）

- **操作**：daemon 运行中，`kill -9 <pid>`（Windows：任务管理器结束进程），
  立即重新 `daemon.py run`。
- **预期**：`filelock` 的锁由操作系统在进程退出时释放，重启不会被残留锁卡住；
  若另一个 daemon 仍在运行，新实例日志为 `Another task is already running, skip this run.`。
- **通过标准**：强制终止后可立即重启；状态文件（可能被截断）能自愈（见 7.6）。

### 7.6 断电 / 非正常退出

- **背景**：`daemon-state.json` 与 `alarms.json` 目前是**非原子写入**，
  写入过程中断电可能留下截断的 JSON。
- **操作**：模拟——手动把 `daemon-state.json` 写成半截 JSON，再启动 daemon。
- **预期**：`load_state` 捕获解析错误 → 视为全新状态（`last_run` 为空 →
  各任务判定到期、各跑一次）；`alarm.py` 对损坏 `alarms.json` 会**报错中止**，
  不静默重建（避免已归档比赛重爬）。
- **通过标准**：daemon 不崩溃；损坏的 `daemon-state.json` 自愈；
  损坏的 `alarms.json` 被识别并给出明确错误。
- **备注**：`offline` 阶段已自动覆盖「损坏 `daemon-state.json` 自愈」与「损坏
  `alarms.json` 中止」两项（无需手动）；本节保留人工复核断电后的完整恢复。
  两处写入已在 v1.0.0-beta 改为原子写入（`crawler/scripts/jsonio.py`：临时文件 + fsync +
  `os.replace`），断电不再产生截断 JSON；本节仍可用于人工复核恢复行为。

### 7.7 双实例并发（锁）

- **操作**：两个终端同时 `daemon.py sync`。
- **预期**：一个正常执行，另一个立即输出 `Another task is already running, skip this run.`
  并以退出码 1 结束；不会并发抓取/提交。
- **通过标准**：无竞态、无重复提交。
- **备注**：`offline` 阶段已自动验证（持锁进程存在时 `sync` 立即跳过）。本节可在
  安装自启服务后再人工复核一次。

### 7.8 系统时钟 / 时区变化

- **操作**：把系统时区改为非 UTC+8（如 `TZ=America/New_York` 或系统设置），
  触发一次 `daemon.py sync` / 查看日志时间戳。
- **预期**：`daemon.log` 时间戳始终为北京时间（UTC+8）；调度按北京时间计算。
- **通过标准**：时间语义不受宿主时区影响。

### 7.9 长时间运行（日志与资源）

- **操作**：daemon 持续运行 >= 24 小时（或加速触发多次任务），观察
  `crawler/daemon.log` 体积与进程内存。
- **预期**：功能正常；`daemon.log` 达到 10MB 时会轮转为 `daemon.log.1`（只保留一份
  历史，避免占满磁盘；见 `daemon._rotate_log_if_needed`）。
- **通过标准**：24 小时无崩溃；日志文件不超过上限（轮转后当前文件变小、`daemon.log.1` 存在）。

---

## 8. 证据收集

每个平台至少保留：

```bash
.venv/bin/python crawler/scripts/e2e_test.py check   > e2e-check-<os>.log 2>&1
.venv/bin/python crawler/scripts/e2e_test.py unit    > e2e-unit-<os>.log  2>&1
.venv/bin/python crawler/scripts/e2e_test.py offline > e2e-offline-<os>.log 2>&1
.venv/bin/python crawler/scripts/e2e_test.py live ... > e2e-live-<os>.log 2>&1
# 特殊情况证据
tail -n 200 crawler/daemon.log
cat crawler/daemon-state.json
cat crawler/alarms.json
systemctl --user status training-archive-daemon.service 2>&1   # 或 schtasks /Query
```

`.e2e/report.json` 是脚本的结构化结果；这些日志与截图一并附在测试记录里。

---

## 9. 结果记录模板

| # | 测试项 | 平台 | 结果(PASS/FAIL/WARN/SKIP) | 证据 | 备注 |
|---|--------|------|---------------------------|------|------|
| 1 | `check` | | | | |
| 2 | `unit` | | | | |
| 3 | `offline` | | | | |
| 4 | `live --mode crawl` | | | | |
| 5 | `live --mode full` | | | | |
| 6 | 睡眠恢复（7.1） | | | | |
| 7 | 休眠恢复（7.2） | | | | |
| 8 | 关机重启（7.3） | | | | |
| 9 | 断网/恢复（7.4） | | | | |
| 10 | 进程被杀（7.5） | | | | |
| 11 | 断电自愈（7.6） | | | | |
| 12 | 双实例锁（7.7） | | | | |
| 13 | 时区（7.8） | | | | |
| 14 | 长时运行（7.9） | | | | |

---

## 10. 已知限制

- 沙箱基于 `git archive HEAD`，**未提交改动不生效**；正式测试前先提交。
- `live --mode full` 会真实调用 DeepSeek，产生 token 消耗；只想验证链路可用 `--mode crawl`。
- QOJ 的 Cloudflare 反爬：Linux 需 `xvfb-run` + `CHROME_HEADLESS=0`；
  Windows 必须保持交互式桌面，不能用无桌面的服务方式运行。
- 自启服务 `install` 会真正注册当前用户的开机自启并立即启动服务，测试后务必 `uninstall`。
- 全局锁文件在 `TMPDIR`；E2E 已隔离，但真实 `daemon.py` 与 E2E 同时运行互不影响。

---

## 附录 A. Linux 实测记录（2026-10-06）

环境：Linux 7.0.0、Python 3.14.4、Node 22.23.2；均通过 `live --mode crawl`（不调 LLM）。

| 平台 | 链接 | 用时 | 结果 |
|------|------|------|------|
| NowCoder | `https://ac.nowcoder.com/acm/contest/108303` | 52s | 13 题 + 40 条提交（20+20 分页）；sync 退出 0；闹钟 archived；本地 origin 收到 `[contests-changed]` |
| HDU | `https://acm.hdu.edu.cn/contest/problems?cid=1230` | 23s | 25 条提交（状态页无分页）；sync 退出 0；归档 + 推送 |
| QOJ | `https://qoj.ac/contest/3588` | 635s（`xvfb-run` + `--headful`） | 13 题 PDF + 50 条提交；sync 退出 0；归档 + 推送；**部分提交源码偶发被 Cloudflare 挑战页挡住（已内建一次重试）**，属已知偶发问题，不阻断整场 |

**完整链路（含复盘）**：NowCoder `108303` 用 `live --mode full` 75s 跑通
「抓取 → DeepSeek 生成 18.8KB `review.md` → 归档 → 推送」。首次尝试时 NowCoder 题目解析
曾偶发 `'NoneType' object has no attribute 'find'`（疑似反爬/页面变体），重试即成功——
与 QOJ 的 Cloudflare 偶发同类，daemon 的 `failed → 下次 sync 重试` 机制可兜底。

自动化统计：`offline` 20 项、`all`（check+unit+offline）28 项全部 PASS，pytest 205 条通过。

**发布演练**：在真实 `contests/` 数据下 `pnpm build` 静态导出成功，`pnpm lint` /
`pnpm exec tsc --noEmit` / `pnpm test` 均通过。

CI：`Crawler Tests` 的 `pytest` 与 `e2e-offline`（均 ubuntu-latest + windows-latest）以及
`Frontend Tests`（lint + tsc + vitest）全绿。`e2e-offline` 在 windows runner（cp1252 控制台）上
曾暴露「打印中文结果 UnicodeEncodeError」，已通过入口脚本 reconfigure stdout 为 UTF-8 修复。

> **待补**：Windows 11 端的 `live` 实测记录（按第 6 节执行后填入本节与第 9 节模板）。
