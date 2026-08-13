# Changelog

> 格式基于 [Keep a Changelog](https://keepachangelog.com/)。

## [0.3.2] - 2026-08-13

### Added

- **QQ 群机器人（`crawler/scripts/qq_bot.py`）**：常驻轮询 NapCat 群消息记录增量拉取（无需修改上报配置），在群里 **@机器人** 发指令即可查询 daemon 状态 / 即将开始的比赛 / 闹钟概览 / 已归档比赛与复盘状态 / 今日运势（`/status` `/upcoming` `/alarms` `/contests` `/fortune` `/help` + 自然语言关键词）；`daemon.py` 新增 `install-qqbot` / `uninstall-qqbot` 独立自启服务
- **qq-bot 新指令**（`qq_bot.py`）：
  - `/review`（`/rv`）复盘查询：无参数返回最近有复盘的比赛，带关键词搜索并返回摘要（截断 400 字符）
  - `/subs` 订阅管理：列出全部订阅；`/subs add <link> [end=时间] [start=时间] [备注]` 新增（platform 自动推断，写入 `crawler/subscriptions/qqbot.json`；`end=`/`start=` 可选键值，顺序任意，其余 token 拼为备注，时间格式 `ISO 8601 北京时间`）；`/subs del <link>` 删除（从所有订阅文件移除）；改动后后台触发一次 `daemon.py sync` 并在群里回复结果
  - `/sync` 手动触发一次完整同步（后台执行，完成后群里回复结果）
  - `/subs` 与 `/sync` 仅 `deploy` 分支工作区生效（`PROD_BRANCH` 保护，防止在非生产分支误改订阅）
- **今日运势确定性**（`qq_bot.py`）：`/fortune` 从随机改为按「user_id + 北京日期 + salt」确定性选择（同一天同一人结果一致，跨天变化），新增幸运数字；salt 可配 `config.json` 的 `qq.fortune_salt`（缺省固定值）
- **赛前提醒（`alarm.py remind` + `daemon.py remind`）**：planned 闹钟在比赛开始前 `qq.remind_before_minutes` 分钟（缺省 15）向 QQ 群发【赛前提醒】🏁，发送成功后 `mark --reminded`（失败下轮重试）；订阅可填 `start_time`（未填回退 `end_time - 5h`）；`scheduled` 块新增 `remind`（缺省 `*/5 * * * *`）；`/upcoming` 改用 `start_time` 排序、闹钟显示名优先取 `comments`

### Fixed

- **订阅时间格式校验**（`qq_bot.py` + `alarm.py` + `daemon.py`）：`/subs add` 的 `end=`/`start=` 时间格式错误 → 终止不写入并提示（给出 `ISO 8601 北京时间` 示例）；手动 `sync` 时 `alarm.py plan` 发现订阅条目时间字段存在但解析失败 → 跳过该条目并输出 `[alarm] ERROR`（汇总行追加 `N invalid time`），`daemon.py sync` 收到非零返回即中止（不爬取不提交），避免把填错时间当 HISTORY 立即爬掉
- **qq-bot 增量游标改用消息 `time`**（`qq_bot.py`）：NapCat 的 `message_seq` / `message_id` 并非全局递增，用作游标会把新消息永久挡掉；改为按非自己消息的 `time` 推进

## [0.3.1] - 2026-08-12

### Added

- **QQ 群分享（share AI task，`crawler/scripts/qq_share.py`）**：将比赛复盘（`review.md`）改写成轻松随性的纯文本（`qq-share.txt`，DeepSeek 独立调用、更高 temperature），并通过 NapCat（OneBot 11 正向 WebSocket，Bearer token 鉴权）发送到 QQ 群——群发文字（`send_group_msg`，CQ 码转义 + Markdown 清洗）+ 上传 `review.md` 文件（`upload_group_file`）；发送成功后删除 `qq-share.txt`（临时产物，不入 git）
  - 文字缺失（生成失败/为空）：记 log，跳过文字直接发 review 文件
  - `review.md` 不存在：跳过（share 依赖 report 生成的完整报告，不自行生成）
  - NapCat 未配置 / 连接失败 / 发送失败：仅告警不阻断 daemon（`qq-share.txt` 保留供下次重试）
  - 新增 `ai_tasks.share.enabled` 配置开关（显式开启才调用；缺省 `false`）与 `qq` 块（`napcat_ws_url` / `napcat_token` / `group_id`）；`config.example.json` 已更新
  - 新增依赖 `websocket-client`（`crawler/requirements.txt`）

### Changed

- **report 与 share 解耦**（`report.py` / `daemon.py`）：`report.py` 不再串联生成 `qq-share.txt`；由 daemon 的 sync/fire 在 report 全部成功后按 `ai_tasks.share.enabled` 单独调用 `qq_share.py --links`
- **review 生成失败阻断归档**（`daemon.py` + `report.py`）：`report.py --links` 任一应生成报告的比赛的 review 生成失败 → 返回非零；sync/fire 据此中止（不 `mark --archived`、不提交推送，下次 sync 重试），避免「已归档但缺复盘」
- **`qq-share.txt` 不进 git**：`.gitignore` / `.gitignore.deploy` 忽略 `contests/*/qq-share.txt`；deploy 分支 `git rm --cached` 清理已跟踪的遗留文件

### Removed

- **`report.py --qq-only` 兼容入口**：转调 qq_share.py 的入口已由 qq_share.py 直接提供（`--links` / `--from-crawl` / `<folder>` / 全量扫描）

## [0.3.0] - 2026-08-12

### Added

- **跨平台守护进程 `crawler/scripts/daemon.py`**（替代 v0.2.x 的 `crawler/server-task.sh`）：
  - 子命令 `run` / `sync` / `fire` / `incremental` / `install` / `uninstall` / `status` / `log`；`run` 主循环用 croniter 解析 `config.json` 的 `scheduled` 块调度任务，睡眠/关机恢复后每个任务只补跑一次
  - `install` 按操作系统注册开机自启：Linux systemd user unit、macOS launchd、Windows schtasks（默认「登录时启动」）
  - `install --system`（仅 Linux）：注册系统级 systemd service（`/etc/systemd/system/`，`WantedBy=multi-user.target`），开机即启动、无需登录会话（适合无头服务器）；服务以实际用户身份运行（`User=<owner>`，sudo 时取 `SUDO_USER`），需 root 执行
  - 跨平台串行锁改用 filelock（替代 flock），新增依赖 `croniter` / `filelock`（`crawler/requirements.txt`）
- **fork 部署参数化**：`next.config.ts` 的 `basePath` / `assetPrefix` 与 `global.ts` 的 `REPO_URL` / `BASE_URL` / `PREFIX_URL` 支持 env 覆盖（`NEXT_PUBLIC_BASE_PATH` / `NEXT_PUBLIC_SITE_URL` / `NEXT_PUBLIC_REPO_URL`，默认值不变）

### Changed

- **浏览器驱动路径按平台解析**（`base.py`）：`CHROME_BINARY` / `CHROMEDRIVER_PATH` env 优先，缺省按 `sys.platform` 回落——Linux 用 `crawler/chrome-linux64`、Windows 用 `crawler/chrome-win64`、macOS 用系统 Google Chrome + `crawler/chromedriver-mac*`（glob 匹配）
- **仅 contests/ 有实质更新才提交推送**（`daemon.py`）：无新比赛 / 新提交 / 新报告时不再发 `[auto] Update crawler state` 提交（crawler 状态与日志已在本地文件系统持久化，无需同步远端）；只有 contests/ 变化才提交 `[contests-changed]` 触发部署

### Removed

- **Actions 爬虫链路**：删除 `crawler-scheduled.yml` / `crawler.yml`；`deploy.yml` 去掉 `workflow_run` 监听（保留 `push` 触发）。静态版部署统一为「自托管爬虫 + GitHub Pages」（详见 `docs/roadmap.md` §1.1）。
- **`crawler/server-task.sh`**：由 `crawler/scripts/daemon.py` 替代（cron/`flock` 依赖 Linux 环境，改为跨平台守护进程 + 跨平台自启）。

### Fixed

- **复盘报告触发条件改为订阅 `end_time`**（`daemon.py` 的 sync/fire）：报告条件从「本次爬取新建比赛」（`report.py --from-crawl` + `new-contests.json`）改为「订阅填了 `end_time`」（EXPIRED / RETRY / fire due），按订阅链接反查 `contests/` 生成（`report.py --links`）——比赛此前已归档过（非本次新建）也要生成，避免漏掉复盘。RETRY 按原任务 `end_time` 判断：空 = 原 HISTORY 不生成报告，非空 = 原 EXPIRED/planned 生成报告
- **HTML→Markdown 公式乱码（pandoc 版本差异）**：pandoc 3.1.x（Debian apt 版）会把 KaTeX 视觉 HTML（`span.katex-html`，`aria-hidden`）当普通内容输出，产生 `[[$x$][[[]{.strut...}...]]` 嵌套乱码，而 3.7+ 自动忽略。修复：转换前用 BeautifulSoup 删除 `span.katex-html` / `span.katex-error`（TeX 源码在 `span.katex-mathml` 的 `<annotation>` 里，保留不受影响），使新旧 pandoc 输出一致；顺带修复空 `<div>` 产生的多冒号 `:::::` 容器残留，与 `::: katex-display` 块级公式容器被压成单行的问题
- **`sync` / `fire` 日志不再「爬完才一次性输出」**（`daemon.py`）：两层修复——`run_py` 改为流式转发子进程输出（`Popen` + 逐行 `log_raw`，stderr 并入同一管道避免双管道死锁）；**关键**是给子进程注入 `PYTHONUNBUFFERED=1`（stdout 被重定向到管道时 Python 默认块缓冲，子进程 `print()` 不带 flush 的日志会攒到进程结束才 flush，daemon 流式读取也读不到）——强制无缓冲后每行日志立即到达管道实时转发；`log` / `log_raw` 的 `print` 加 `flush=True`，systemd/journald 场景下实时落盘
- **订阅文件格式有问题时 sync 立刻提示**（`alarm.py` + `daemon.py`）：`plan` 读取订阅时接住 `load_subscriptions_dir` 的 error/warning 诊断（此前 `log=None` 静默跳过），输出 `[alarm] ERROR/WARNING` 与汇总行计数（`subscription diag: N errors, M warnings`），坏文件条目不会同步；`daemon.py` 的 `sync` 转发所有 `[alarm]` 行到日志，用户无需翻日志文件也能在终端/systemd journal 立刻看到

## [0.2.1] - 2026-08-12

### Added

- **服务器闹钟机制（部署方式二专用）**：订阅条目可选填 `end_time`，未来比赛写入闹钟表 `crawler/alarms.json`（gitignore），到点由 `fire` 触发爬取并立即生成复盘报告；方式一（GitHub Actions 轮询）不读取该字段
  - 新增 `crawler/scripts/alarm.py`（`plan` / `due` / `mark` / `list`）与闹钟状态模型 `planned` / `pending` / `archived` / `failed`；爬取失败即 `failed`，由自动 `sync` 重试一次（成功 → `archived`，失败保持 `failed`）
  - `crawler/server-task.sh` 新增 `sync` / `fire` 子命令；`scheduled_task.py` 新增 `--links`（只抓指定订阅链接）；`report.py --from-crawl` 新增 `--links` 过滤

### Changed

- **cron 配置外置到 `crawler/config.json` 的 `scheduled` 块**：`server-task.sh install` 从该块读取表达式生成 crontab（缺失/非法回落默认值），删除硬编码 cron 与时区自动调整逻辑
- **去除「任务A/B」别名**，统一以 `scheduled_task.py` 模式指代：`server-task.sh` 删除 `run [a|b]`，新增 `incremental`（内部调用 `--submissions-only`）

### Fixed

- `deploy.yml` 标记检查误触发（`--pretty=%s` 只取 subject 第一行）
- 自动提交 `[contests-changed]` 标记对中文路径失效（`git -c core.quotepath=false` 三处统一）
- `/log` 页面在日志文件缺失时显示占位提示而非报错
- 静态导出在无可用数据时失败（动态路由统一判空 + 占位参数兜底）

## [0.2.0] - 2026-08-10

### Added

- 平台启用/禁用：`crawler/config.json` 的 `enabled` 字段（缺省禁用），HDU/NowCoder 默认停用
- 爬虫订阅模型：`crawler/subscriptions/` 目录式订阅配置（取代单文件与各平台 `input_contests.json`）
- 全量提交采集：每份提交归档到 `submissions.json` + `problems/<letter>/submissions/<id>.<ext>`，供复盘使用
- 复盘报告：`report.py` 调用 DeepSeek 生成 `review.md`（幂等，存在即跳过）；QQ 群分享简化版 `qq-share.txt`
- 定时任务入口：`scheduled_task.py` 三种模式（默认 / `--contests-only` / `--submissions-only`）；`finish()` 仅在完整同步时推进 `last-update.json`
- deploy 分支专用 `.gitignore.deploy`（竞赛数据与爬虫增量状态纳入版本控制）
- 双定时工作流：`crawler-scheduled.yml` + `crawler.yml`，提交时用 `.gitignore.deploy` 覆盖 `.gitignore`
- 前端：题目标签、搜索页（构建时索引 + 前端过滤）、Dashboard（统计 / 最近动态 / contribution 绿点图 / 复盘报告区）、复盘时间轴页、全局错误边界与加载骨架屏、README 页、历史提交查看路由
- UI 库 shadcn/ui + 图标库 lucide-react（替换 react-icons）
- 新增 `.env.example`（凭据模板）与 `docs/roadmap.md`

### Changed

- 爬虫目录按职责重组（`platforms/`、`scripts/`、`llm/`、`prompts/`），导入统一为完全限定
- 订阅配置改为目录式管理：`crawler/subscriptions/` 下每个 `.json` 一份列表，按文件名合并、重复 `link` 去重、模板文件跳过
- 复盘报告改为 `--from-crawl` 模式（只对本次新建比赛生成）；爬虫与报告解耦（爬虫失败不生成报告，报告失败不阻断部署）
- NowCoder 环境变量统一 `NOWCODER_*`（`NOWCODER_USERNAME` + Cookie）
- 前端：内部路由统一根相对路径 + `next/link`（修复双前缀 404）；URL/格式化工具抽离；文件查看器重构为公共组件；竞赛表格题号动态自适应；响应式布局
- 时间显示统一 `YYYY/MM/DD HH:MM`（北京时间）；内容查看类链接统一新标签页
- 部署方式确认与文档化（方式一 Actions / 方式二自建服务器 / 方式三动态版规划中）

### Fixed

- HDU/NowCoder 提交记录补抓 `problem_id` 字段；补订已完成比赛以 `start_time` 为截止全量回填
- 跨赛季复用题目导致历史提交误归档（提交时间窗口校验，早于比赛开始的提交丢弃）
- 本地爬虫读不到 `.env` 凭据（脚本顶部 `load_dotenv()`）
- `is_logged_in()` 的 `self.username` 无赋值来源；NowCoder 未迁移订阅模型
- 根路径 `/` 404、竞赛列表表格布局、面包屑 Home 不高亮、Markdown 样式缺失（移入根布局全局加载）
- 线上链接双前缀 `/Training-Archive/Training-Archive/...` 404、复盘时间轴 Source 链接 404
- 搜索/最近完成入口误链到代码页（改 `statement.md`/`statement.pdf` 优先）

## [0.1.0] - 2026-01-04

### Added

- 初始化 Next.js 项目与全局布局（导航、页脚、面包屑）
- contest 列表首页（分页、平台徽章、题目状态）、多级文件查看路由、文件查看器（Markdown / PDF / 源码）、日志页面
- QOJ / HDU / NowCoder 三平台爬虫与 `BaseCrawler` 基类、日志清理脚本
- GitHub Actions 工作流：`crawler.yml`（定时抓取自动提交）、`deploy.yml`（构建部署 Pages）

### Changed

- contest / 题目元数据结构重构，统一由 `contest.json` / `problem.json` 描述
- 时间处理统一北京时间；提交耗时改为 `solve_time - start_time`
- 多处样式与布局优化（响应式、悬停效果、平台徽章颜色等）

### Fixed

- 数学公式分隔符正则全局匹配、提交抓取无提交时死循环、分页边界、爬虫退出清理
- 部署工作流 CI 问题（日期格式、pnpm 安装顺序、Node 版本、缓存）

### Removed

- 停止跟踪 contest 数据文件（`contests/`、staged submissions、log、config 等改为运行时生成），移至 deploy 分支跟踪
