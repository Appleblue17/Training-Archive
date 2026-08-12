# Training Archive

算法竞赛训练归档站：自动抓取 QOJ / HDU / NowCoder 的参赛提交与题目，归档为静态站点，便于回溯自己的训练记录与解题代码。

在线访问：<https://appleblue17.github.io/Training-Archive/>

## 功能特性

- **竞赛归档**：按平台（QOJ / HDU / NowCoder）归档竞赛，展示竞赛列表、题目状态与文件
- **题目状态标记**：AC / 尝试未解决（黄色背景）等提交状态一目了然，显示提交时间与解决耗时
- **文件查看器**：在线预览 Markdown（GFM / 数学公式 / KaTeX / 代码高亮）、PDF、源码文件，支持下载
- **复盘报告**：每场完赛自动生成 LLM 复盘报告（DeepSeek）与 QQ 群分享文本
- **日志页面**：查看各平台爬虫运行日志与 staged submissions
- **自动抓取**：自托管脚本（`crawler/server-task.sh`）定时运行爬虫，检测到竞赛变化后自动提交并部署到 GitHub Pages

## 技术栈

| 部分     | 技术                                                                   |
| -------- | ---------------------------------------------------------------------- |
| 前端     | Next.js 15（静态导出）、React 19、TypeScript、Tailwind CSS、Motion     |
| 文档渲染 | unified / remark / rehype（Markdown + 数学公式 + 代码高亮）、react-pdf |
| 爬虫     | Python、undetected_chromedriver、BeautifulSoup                         |
| CI/CD    | GitHub Actions（deploy.yml 构建部署 Pages）+ 自托管爬虫脚本（server-task.sh） |
| 包管理   | pnpm（registry: https://registry.npmmirror.com/）                      |

## 目录结构

```
├── src/                        # Next.js 前端（列表、搜索、Dashboard、复盘、文件查看器）
├── crawler/                    # Python 爬虫
│   ├── platforms/              # BaseCrawler 基类 + qoj/hdu/nowcoder 平台实现
│   ├── scripts/                # scheduled_task.py / report.py / alarm.py / server-task.sh
│   ├── llm/                    # DeepSeek 客户端
│   ├── subscriptions/          # 订阅配置（每个 .json 一份列表，模板见 .example.json）
│   └── config.json             # 平台启用、请求间隔、cron 表达式（scheduled 块）
├── contests/                   # 竞赛数据（爬虫生成，不纳入版本控制）
├── .github/workflows/          # crawler*.yml（抓取）、deploy.yml（部署）
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
# 复盘报告（--from-crawl 只对本次爬取新建的比赛生成）
python3 crawler/scripts/report.py --from-crawl
# 补生成：扫描所有缺报告的已结束比赛，或只生成指定比赛
python3 crawler/scripts/report.py
python3 crawler/scripts/report.py "contests/2026-08-01 xxx"
```

爬虫会生成 `contests/` 数据目录与各平台日志文件（均已被 `.gitignore` 忽略）。

## 部署方式

静态版（v0.3.0 起）统一为**一种部署方式**：自托管脚本运行爬虫，产物 push 回 `deploy` 分支，由 GitHub Actions 的 `deploy.yml` 自动构建并部署到 GitHub Pages。动态版（v0.4.0）规划中，详见 [docs/roadmap.md](docs/roadmap.md) §1.1。

### 部署（唯一方式）：自托管爬虫 + GitHub Pages

提供一键管理脚本 `crawler/server-task.sh`（完整流程：pull → 爬取 → 报告 → 清理 → 提交推送）：

```bash
crawler/server-task.sh incremental  # 提交增量同步（--submissions-only）
crawler/server-task.sh sync         # 同步订阅：历史/过期立即爬，未来比赛写入闹钟
crawler/server-task.sh fire         # 闹钟到点触发（无到期安静退出）
crawler/server-task.sh install      # 安装 cron 定时（从 config.json 的 scheduled 块读取表达式）
crawler/server-task.sh uninstall    # 卸载 cron
crawler/server-task.sh status       # 查看状态 / 日志
```

> v0.3.0 起 `server-task.sh` 将替换为跨平台守护进程 `crawler/scripts/daemon.py`（支持 Windows / macOS）。

**闹钟机制**：订阅条目可选填 `end_time`（比赛结束时间，ISO 格式）。`sync` 把未来比赛写入运行时状态文件 `crawler/alarms.json`（gitignore，不提交）并标记为 `planned`，cron 按 `config.json` 的 `scheduled` 块间隔调用 `fire`：到点即爬取该场比赛并立即生成复盘报告。状态模型：`planned` / `pending` / `archived` / `failed`；爬取失败即 `failed`（不再自动重试），由自动 `sync` 重试：成功 → `archived`，失败保持 `failed`。订阅里修改 `end_time` 或删除条目时，`sync` 会相应重新安排或剪除闹钟。详见 [docs/architecture.md](docs/architecture.md) §4.6。

运行环境要求：已 clone 仓库、根目录有 `.env` 凭据、`pip install -r crawler/requirements.txt`、Chrome/Chromedriver 在 `crawler/chrome-linux64/` 与 `crawler/chromedriver-linux64/`、已配置 push 凭据（SSH key 或 token）。

> `deploy.yml` 通过 `push` 到 `deploy` 分支触发：带 `[contests-changed]` 标记的提交才会部署，仅状态变化的提交会跳过。

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
