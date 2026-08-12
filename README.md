# Training Archive

算法竞赛训练归档站：自动抓取 QOJ / HDU / NowCoder 的参赛提交与题目，归档为静态站点，便于回溯自己的训练记录与解题代码。

在线访问：<https://appleblue17.github.io/Training-Archive/>

## 功能特性

- **竞赛归档**：按平台（QOJ / HDU / NowCoder）归档竞赛，展示竞赛列表、题目状态与文件
- **题目状态标记**：AC / 尝试未解决（黄色背景）等提交状态一目了然，显示提交时间与解决耗时
- **文件查看器**：在线预览 Markdown（GFM / 数学公式 / KaTeX / 代码高亮）、PDF、源码文件，支持下载
- **复盘报告**：每场完赛自动生成 LLM 复盘报告（DeepSeek）与 QQ 群分享文本
- **日志页面**：查看各平台爬虫运行日志与 staged submissions
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
├── src/                        # Next.js 前端（列表、搜索、Dashboard、复盘、文件查看器）
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
```

爬虫会生成 `contests/` 数据目录与各平台日志文件（均已被 `.gitignore` 忽略）。

## 部署方式

静态版（v0.3.0 起）统一为**一种部署方式**：自托管脚本运行爬虫，产物 push 回 `deploy` 分支，由 GitHub Actions 的 `deploy.yml` 自动构建并部署到 GitHub Pages。动态版（v0.4.0）规划中，详见 [docs/roadmap.md](docs/roadmap.md) §1.1。

### 部署（唯一方式）：跨平台守护进程 + GitHub Pages

提供跨平台守护进程 `crawler/scripts/daemon.py`（完整流程：pull → 爬取 → 报告 → 清理 → 提交推送）：

```bash
python3 crawler/scripts/daemon.py run             # 主循环（前台运行；安装为服务后由系统拉起）
python3 crawler/scripts/daemon.py sync            # 同步订阅：历史/过期立即爬，未来比赛写入闹钟
python3 crawler/scripts/daemon.py fire            # 闹钟到点触发（无到期安静退出）
python3 crawler/scripts/daemon.py incremental     # 提交增量同步（--submissions-only）
python3 crawler/scripts/daemon.py install         # 注册开机自启（按 OS：systemd user / launchd / schtasks）
python3 crawler/scripts/daemon.py install --system   # 仅 Linux：系统级服务（开机即启动、无需登录，需 sudo）
python3 crawler/scripts/daemon.py uninstall       # 注销开机自启
python3 crawler/scripts/daemon.py uninstall --system # 仅 Linux：注销系统级服务（需 sudo）
python3 crawler/scripts/daemon.py status          # 查看状态 / 日志
```

- **主循环调度**：`run` 用 croniter 解析 `config.json` 的 `scheduled` 块（三个表达式），睡眠/关机恢复后每个任务只补跑一次（不追赶历史，靠任务自身增量/幂等覆盖错过时段）。
- **开机自启**：`install` 按操作系统注册——Linux systemd user unit、macOS launchd、Windows schtasks（默认「登录时启动」，适合个人电脑）。
- **无头服务器**：`install --system`（仅 Linux）注册系统级 systemd service（`/etc/systemd/system/`，`WantedBy=multi-user.target`），开机即启动、无需登录会话；服务以实际用户身份运行（`User=<owner>`，sudo 时取 `SUDO_USER`），git 凭据 / `.env` 与手动运行一致。需 root：
  ```bash
  sudo .venv/bin/python crawler/scripts/daemon.py install --system
  ```

**闹钟机制**：订阅条目可选填 `end_time`（比赛结束时间，ISO 格式）。`sync` 把未来比赛写入运行时状态文件 `crawler/alarms.json`（gitignore，不提交）并标记为 `planned`，守护进程主循环按 `config.json` 的 `scheduled` 块间隔调度 `fire`：到点即爬取该场比赛并立即生成复盘报告。状态模型：`planned` / `pending` / `archived` / `failed`；爬取失败即 `failed`（不再自动重试），由自动 `sync` 重试：成功 → `archived`，失败保持 `failed`。订阅里修改 `end_time` 或删除条目时，`sync` 会相应重新安排或剪除闹钟。详见 [docs/architecture.md](docs/architecture.md) §4.6。

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
