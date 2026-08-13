# Training Archive

算法竞赛训练归档站：自动抓取 QOJ / HDU / NowCoder 的参赛提交与题目，归档为静态站点，便于回溯自己的训练记录与解题代码。

在线访问：<https://appleblue17.github.io/Training-Archive/>

## 功能特性

- **竞赛归档**：按平台（QOJ / HDU / NowCoder）归档竞赛，展示竞赛列表、题目状态与文件
- **题目状态标记**：AC / 尝试未解决（黄色背景）等提交状态一目了然，显示提交时间与解决耗时
- **文件查看器**：在线预览 Markdown（GFM / 数学公式 / KaTeX / 代码高亮）、PDF、源码文件，支持下载
- **复盘报告**：每场完赛自动生成 LLM 复盘报告（DeepSeek）与 QQ 群分享文本
- **赛前提醒**：预订的比赛开始前自动在 QQ 群发提醒
- **状态页面**：查看爬虫配置、各平台最后更新时间、待回填提交与订阅列表（/status）
- **自动抓取**：自托管守护进程（`crawler/scripts/daemon.py`）定时运行爬虫，检测到竞赛变化后自动提交并部署到 GitHub Pages

## 技术栈

| 部分     | 技术                                                                   |
| -------- | ---------------------------------------------------------------------- |
| 前端     | Next.js 15（静态导出）、React 19、TypeScript、Tailwind CSS、Motion     |
| 文档渲染 | unified / remark / rehype（Markdown + 数学公式 + 代码高亮）、react-pdf |
| 爬虫     | Python、undetected_chromedriver、BeautifulSoup                         |
| CI/CD    | GitHub Actions（deploy.yml 构建部署 Pages）+ 自托管爬虫守护进程（daemon.py） |
| 包管理   | pnpm（registry: https://registry.npmmirror.com/）                      |

## 目录结构

```
├── src/                        # Next.js 前端（列表、搜索、Dashboard、复盘、状态页、文件查看器）
├── crawler/                    # Python 爬虫
│   ├── platforms/              # BaseCrawler 基类 + qoj/hdu/nowcoder 平台实现
│   ├── scripts/                # scheduled_task.py / report.py / alarm.py / daemon.py
│   ├── llm/                    # DeepSeek 客户端
│   ├── subscriptions/          # 订阅配置（每个 .json 一份列表，模板见 .example.json）
│   └── config.json             # 平台启用、请求间隔、cron 表达式（scheduled 块）
├── contests/                   # 竞赛数据（爬虫生成，不纳入版本控制）
├── .github/workflows/          # deploy.yml（部署）
└── docs/                       # 项目文档（见下）
```

## 快速开始

### 前端

```bash
pnpm install    # 安装依赖
pnpm dev        # 开发模式（需要本地存在 contests/ 数据目录）
pnpm build      # 生产构建（静态导出到 out/）
pnpm lint       # 代码检查
```

> 生产构建时会将 `contests/` 复制到 `public/contests/` 后静态导出（见 `deploy.yml`）。

### 爬虫

```bash
pip install -r crawler/requirements.txt

# 默认模式：抓订阅比赛 + 全量增量提交（手动/临时）
python3 crawler/scripts/scheduled_task.py
# 只查订阅/新建比赛（有新建才回填其提交；高频触发推荐）
python3 crawler/scripts/scheduled_task.py --contests-only
# 只抓指定订阅链接（闹钟 fire / sync 补抓用）
python3 crawler/scripts/scheduled_task.py --contests-only --links "https://qoj.ac/contest/123"
# 提交增量模式（每日增量提交同步）
python3 crawler/scripts/scheduled_task.py --submissions-only
# 复盘报告（--links 按订阅链接反查生成，报告条件 = 订阅填了 end_time；--from-crawl 只对本次爬取新建的比赛生成）
python3 crawler/scripts/report.py --links "https://qoj.ac/contest/123,https://qoj.ac/contest/456"
python3 crawler/scripts/report.py --from-crawl
python3 crawler/scripts/report.py --from-crawl --links "https://qoj.ac/contest/123"
# 补生成：扫描所有缺报告的已结束比赛，或只生成指定比赛
python3 crawler/scripts/report.py
python3 crawler/scripts/report.py "contests/2026-08-01 xxx"
# QQ 群分享（可选，config.json 的 ai_tasks.share.enabled 开启后 daemon 自动调用；NapCat 配置见 crawler/config.example.json 的 qq 块）
python3 crawler/scripts/qq_share.py --links "https://qoj.ac/contest/123,https://qoj.ac/contest/456" [--file-only]
python3 crawler/scripts/qq_share.py "contests/2026-08-01 xxx"
```

爬虫会生成 `contests/` 数据目录与各平台日志文件（均已被 `.gitignore` 忽略）。

### QQ 群机器人（可选）

`crawler/scripts/qq_bot.py` 是常驻 QQ 群机器人：在群里 **@机器人** 发指令，即可查询 daemon 运行状态、即将开始的比赛、闹钟概览、已归档比赛与复盘状态。它轮询 NapCat 的群消息记录增量拉取（无需修改 NapCat 的上报配置），默认每 3 秒一次。

**前置条件**：

1. **NapCat**（QQ 机器人框架）已启动并启用正向 WS 服务（如 `ws://127.0.0.1:6700`，在 `onebot11_<qq>.json` 中开启）。
2. **配置**（敏感项放 `.env`，请自行填写，不会提交）：
   - `crawler/config.json` 的 `qq` 块：`napcat_ws_url`（NapCat 正向 WS 地址）
   - `.env`：`QQ_NAPCAT_TOKEN`（NapCat Bearer token）、`QQ_GROUP_ID`（目标群号，数字）、`QQ_BOT_UID`（机器人 QQ 号，用于识别「@我」）

**运行**：

```bash
# 前台常驻轮询（调试用）
python3 crawler/scripts/qq_bot.py run
# 拉取一次消息并处理（调试用）
python3 crawler/scripts/qq_bot.py once

# 注册为独立自启服务（可单独管理，与 daemon 互不影响）
python3 crawler/scripts/daemon.py install-qqbot
sudo .venv/bin/python crawler/scripts/daemon.py install-qqbot --system   # 仅 Linux：系统级服务（开机即启动，需 sudo）
python3 crawler/scripts/daemon.py uninstall-qqbot                        # 注销服务
```

**指令列表**（须在群里 **@机器人** 才生效；`/status` 也可用自然语言，如「@机器人 状态」）：

| 指令 | 别名 | 说明 |
|------|------|------|
| `/status` | `/st` | daemon 运行状态（计划 / 最近运行 / 闹钟概览，不含已归档） |
| `/upcoming` | `/u` | 即将开始的比赛（闹钟内未来比赛，按开始时间排序） |
| `/alarms` | `/a` | 闹钟概览（不含已归档，含 due / scheduled / failed） |
| `/contests` | `/c` | 已归档比赛（最近 10 场）+ 复盘状态 ✓/✗ |
| `/review` | `/rv` | 复盘查询（无参数 = 最近复盘；带关键词 = 搜索摘要） |
| `/fortune` | `/f` | 今日运势（按人 + 日期确定性选择 + 幸运数字 + 今日 / 明日比赛提醒） |
| `/subs` | - | 订阅列表；`/subs add <link> [end=时间] [start=时间] [备注]` 新增、`/subs del <link>` 删除（改动后自动同步）；时间格式 `ISO 8601 北京时间`（如 `2026-08-15T23:00:00+08:00`），格式错误会提示并拒绝写入；只有一个时间参数时可省略 `end=` 前缀（自动识别） |
| `/sync` | - | 触发一次完整同步（后台执行，完成后群里回复结果） |
| `/help` | `/h` | 指令列表 |

> 订阅管理（`/subs`）与 `/sync` 仅在 `deploy` 分支工作区生效（防止在非生产分支误改订阅）；`/fortune` 按人 + 北京日期确定性生成，同一天同一人结果一致，可通过 `config.json` 的 `qq.fortune_salt` 更换盐值。

日志写入 `crawler/qq-bot.log`，增量进度存 `crawler/bot-state.json`（两者均被 gitignore，不提交）。

## 部署方式

静态版（v0.3.0 起）统一为**一种部署方式**：自托管脚本运行爬虫，产物 push 回 `deploy` 分支，由 GitHub Actions 的 `deploy.yml` 自动构建并部署到 GitHub Pages。动态版（v0.4.0）规划中，详见 [docs/roadmap.md](docs/roadmap.md) §1.1。

### 部署（唯一方式）：跨平台守护进程 + GitHub Pages

提供跨平台守护进程 `crawler/scripts/daemon.py`（完整流程：pull → 爬取 → 报告 → 清理 → 提交推送）：

```bash
python3 crawler/scripts/daemon.py run             # 主循环（前台运行；安装为服务后由系统拉起）
python3 crawler/scripts/daemon.py sync            # 同步订阅：历史/过期立即爬，未来比赛写入闹钟
python3 crawler/scripts/daemon.py fire            # 闹钟到点触发（无到期安静退出）
python3 crawler/scripts/daemon.py incremental     # 提交增量同步（--submissions-only）
python3 crawler/scripts/daemon.py remind          # 赛前提醒检查（开始前向 QQ 群发提醒）
python3 crawler/scripts/daemon.py install         # 注册开机自启（按 OS：systemd user / launchd / schtasks）
python3 crawler/scripts/daemon.py install --system   # 仅 Linux：系统级服务（开机即启动、无需登录，需 sudo）
python3 crawler/scripts/daemon.py uninstall       # 注销开机自启
python3 crawler/scripts/daemon.py uninstall --system # 仅 Linux：注销系统级服务（需 sudo）
python3 crawler/scripts/daemon.py install-qqbot       # 注册 QQ 群机器人独立服务（见「快速开始 → QQ 群机器人」）
python3 crawler/scripts/daemon.py uninstall-qqbot     # 注销 QQ 群机器人服务
python3 crawler/scripts/daemon.py status          # 查看状态 / 日志
```

- **主循环调度**：`run` 按 `config.json` 的 `scheduled` 块调度任务（`fire` / `sync` / `incremental` / `remind`），睡眠/关机恢复后每个任务只补跑一次。
- **开机自启**：`install` 按操作系统注册——Linux systemd user unit、macOS launchd、Windows schtasks（默认「登录时启动」，适合个人电脑）。
- **无头服务器**：`install --system`（仅 Linux）注册系统级 systemd service（`/etc/systemd/system/`，`WantedBy=multi-user.target`），开机即启动、无需登录会话；服务以实际用户身份运行（`User=<owner>`，sudo 时取 `SUDO_USER`），git 凭据 / `.env` 与手动运行一致。需 root：
  ```bash
  sudo .venv/bin/python crawler/scripts/daemon.py install --system
  ```

**闹钟机制**：订阅条目可选填 `end_time`（比赛结束时间）。未来比赛由 `sync` 写入闹钟表，`fire` 到点爬取并生成复盘报告；订阅修改或删除时会相应重新安排或剪除闹钟。详见 [docs/architecture.md](docs/architecture.md) §4.6。

**赛前提醒**：闹钟内的未来比赛，开始前自动在 QQ 群发提醒（可填 `start_time` 指定开始时间，未填按 `end_time` 推算）。详见 [docs/architecture.md](docs/architecture.md) §4.6。

**前置依赖**（自托管运行机器需全部具备）：

1. **Python 3 + venv**（推荐）：已 clone 本仓库，然后
   ```bash
   python3 -m venv .venv
   .venv/bin/pip install -r crawler/requirements.txt
   ```
   ⚠️ 后续所有 `daemon.py` 命令（尤其 `install`）都用 `.venv/bin/python` 执行——`install` 会把「执行 install 的 python 解释器」写进服务启动命令，若用系统 python3（可能缺 `dotenv`/`croniter`/`filelock`）注册，服务启动会因缺依赖失败。
2. **Chrome + Chromedriver**：见下节（Linux 仓库已带 `crawler/chrome-linux64/` 与 `crawler/chromedriver-linux64/`）。
3. **pandoc**：HDU / NowCoder 题目 HTML→Markdown 转换必需（Linux `apt install pandoc` / macOS `brew install pandoc` / Windows winget）。
4. **`.env` 凭据**：仓库根目录（QOJ 账号等；已被 gitignore，不会提交）。
5. **git push 凭据**：SSH key 或 token，对 `deploy` 分支有写权限（daemon 启动后会自动 checkout `deploy` 分支并 pull，检测到竞赛变化后 push）。

### Chrome 环境准备（按平台）

爬虫用 undetected_chromedriver 驱动无头 Chrome，驱动路径按平台自动解析（`CHROME_BINARY` / `CHROMEDRIVER_PATH` 环境变量可覆盖默认路径）：

| 平台 | Chrome | Chromedriver |
|------|--------|--------------|
| Linux | `crawler/chrome-linux64/chrome` | `crawler/chromedriver-linux64/chromedriver` |
| Windows | `crawler/chrome-win64/chrome.exe` | `crawler/chromedriver-win64/chromedriver.exe` |
| macOS | 系统 Google Chrome | `crawler/chromedriver-mac*/chromedriver`（缺失时交给自动查找） |

- **Linux**：仓库已带 `crawler/chrome-linux64/` 与 `crawler/chromedriver-linux64/`，直接可用。
- **Windows / macOS**：下载与 Chrome 大版本匹配的 chromedriver 放入对应目录，或直接用 `CHROME_BINARY` / `CHROMEDRIVER_PATH` 指向自备路径。
- **版本匹配**：chromedriver 需与 Chrome 主版本一致（下载：<https://googlechromelabs.github.io/chrome-for-testing/>）。
- HDU / NowCoder 题目 HTML→Markdown 依赖 **pandoc**（Linux `apt install pandoc` / macOS `brew install pandoc` / Windows winget）。

### fork 部署（参数化）

前端常量已 env 化，fork 后构建时设置以下变量即可不改代码部署到自己的 GitHub Pages：

| 环境变量 | 默认值 | 说明 |
|----------|--------|------|
| `NEXT_PUBLIC_BASE_PATH` | `/Training-Archive` | 仓库子路径（GitHub Pages project site 为 `/<仓库名>`，自定义域名根部署设空） |
| `NEXT_PUBLIC_SITE_URL` | `https://appleblue17.github.io` | 站点根域名（`https://<用户名>.github.io`） |
| `NEXT_PUBLIC_REPO_URL` | `https://github.com/appleblue17/Training-Archive/` | 仓库地址（页脚 / README 页 / Actions 链接） |

示例（fork 到 `yourname/my-training-archive`）：

```yaml
# deploy.yml 的 Build 步骤追加：
env:
  NEXT_PUBLIC_BASE_PATH: /my-training-archive
  NEXT_PUBLIC_SITE_URL: https://yourname.github.io
  NEXT_PUBLIC_REPO_URL: https://github.com/yourname/my-training-archive/
```

> `deploy.yml` 通过 `push` 到 `deploy` 分支触发；守护进程只在 contests/ 有实质更新（新比赛 / 新提交 / 新报告）时才提交推送（带 `[contests-changed]` 标记触发部署），仅 crawler 状态 / 日志变化时不发提交（已在本地持久化）。

### 动态版（v0.4.0 规划中）

自建服务器 / Docker 部署 Next.js 动态服务，支持账号系统、个人收藏、正式资源保护与精确到分钟的调度，详见 [docs/roadmap.md](docs/roadmap.md) §1.1 / §3 / §5。

## 文档

| 文档                                             | 内容                                       |
| ------------------------------------------------ | ------------------------------------------ |
| [docs/CHANGELOG.md](docs/CHANGELOG.md)           | 变更日志（Keep a Changelog 格式）          |
| [docs/architecture.md](docs/architecture.md)     | 架构设计、组件职责、技术决策               |
| [docs/roadmap.md](docs/roadmap.md)               | 开发规划：v0.2.x / v0.3.0 / v0.4.0 路线图与决策记录 |
| [docs/notes.md](docs/notes.md)                   | 开发笔记：当前进度、待办、注意事项         |
| [docs/agent-workflow.md](docs/agent-workflow.md) | AI Agent 开发工作流规范                    |

## License

[MIT](LICENSE) © Appleblue17

本项目仅用于学习与个人归档用途。
