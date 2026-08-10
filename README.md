# Training Archive

算法竞赛训练归档站：自动抓取 QOJ / HDU / NowCoder 的参赛提交与题目，归档为静态站点，便于回溯自己的训练记录与解题代码。

在线访问：<https://appleblue17.github.io/Training-Archive/>

## 功能特性

- **竞赛归档**：按平台（QOJ / HDU / NowCoder）归档竞赛，展示竞赛列表、题目状态与文件
- **题目状态标记**：AC / 尝试未解决（黄色背景）等提交状态一目了然，显示提交时间与解决耗时
- **文件查看器**：在线预览 Markdown（GFM / 数学公式 / KaTeX / 代码高亮）、PDF、源码文件，支持下载
- **日志页面**：查看各平台爬虫运行日志与 staged submissions，掌握抓取状态
- **自动抓取**：GitHub Actions 定时运行爬虫，检测到竞赛变化后自动提交并部署到 GitHub Pages

## 技术栈

| 部分     | 技术                                                                   |
| -------- | ---------------------------------------------------------------------- |
| 前端     | Next.js 15（静态导出）、React 19、TypeScript、Tailwind CSS、Motion     |
| 文档渲染 | unified / remark / rehype（Markdown + 数学公式 + 代码高亮）、react-pdf |
| 爬虫     | Python、undetected_chromedriver、BeautifulSoup                         |
| CI/CD    | GitHub Actions（crawler.yml / deploy.yml）                             |
| 包管理   | pnpm（registry: https://registry.npmmirror.com/）                      |

## 目录结构

```
├── src/                        # Next.js 前端
│   ├── app/
│   │   ├── (main)/             # 主页、dashboard、日志、README 页面
│   │   └── view/contests/      # 竞赛 / 题目 / 文件查看路由
│   ├── components/             # 文件查看器、元数据显示、平台徽章等
│   ├── lib/                    # 类型定义、全局配置（BASE_URL 等）
│   └── utils/                  # 文件元数据读取等工具
├── crawler/                    # Python 爬虫
│   ├── base.py                 # BaseCrawler 基类（日志、配置、时间、文件写入）
│   ├── clean-log.py            # 日志清理脚本
│   └── {qoj,hdu,nowcoder}/     # 各平台爬虫
├── contests/                   # 竞赛数据（爬虫生成，不纳入版本控制）
├── .github/workflows/          # crawler.yml（抓取）、deploy.yml（部署）
└── docs/                       # 项目文档（见下）
```

## 快速开始

### 前端

```bash
# 安装依赖
pnpm install

# 开发模式（需要本地存在 contests/ 数据目录）
pnpm dev

# 生产构建（静态导出到 out/）
pnpm build
pnpm start

# 代码检查
pnpm lint
```

> 生产构建时会将 `contests/` 复制到 `public/contests/` 后静态导出（见 `deploy.yml`）。
> 若本地没有竞赛数据，列表页会为空，可参考爬虫部分抓取数据。

### 爬虫

```bash
# 安装依赖
pip install -r crawler/requirements.txt

# 准备配置与环境变量（见 crawler/subscriptions/subscriptions.example.json、.env.example）
# 订阅文件放在 crawler/subscriptions/ 目录（每个 .json 一份列表，文件名随意）
# 任务A（默认完整：抓订阅比赛 + 全量增量提交）
python3 crawler/scheduled_task.py
# 任务A（--contests-only：只查订阅/新建比赛，有新建才回填其提交；高频触发推荐）
python3 crawler/scheduled_task.py --contests-only
# 任务B：每日增量同步提交
python3 crawler/scheduled_task.py --submissions-only
# 复盘报告（独立于爬虫，只对本次爬取新建的比赛生成）
python3 crawler/report.py --from-crawl
# 补生成：扫描所有缺报告的已结束比赛，或只生成指定比赛
python3 crawler/report.py
python3 crawler/report.py "contests/2026-08-01 xxx"
```

爬虫会生成 `contests/` 数据目录与各平台日志文件（均已被 `.gitignore` 忽略）。

## 部署方式

网站提供三种部署方式，当前实现为**静态版（v0.2.x）**；动态版（v0.3.x）规划中，详见 [docs/roadmap.md](docs/roadmap.md) §1.1。

### 方式一：GitHub Actions 自动任务（默认，零运维）

GitHub 云端定时运行爬虫，自动提交并部署到 GitHub Pages：

1. 在仓库 Secrets 配置凭据（QOJ/HDU 账号、NowCoder Cookie、`DEEPSEEK_API_KEY`，见 `.env.example`）。
2. 开启两个工作流的定时（取消注释 `schedule`）：
   - `.github/workflows/crawler-scheduled.yml`：每 30 分钟查订阅/新建比赛（`--contests-only`，有新建才回填其提交）
   - `.github/workflows/crawler.yml`：每日 20:00 UTC 任务 B（提交增量同步）
3. 爬虫完成后自动触发 `deploy.yml` 部署 Pages。

### 方式二：自建服务器跑脚本

关闭工作流的定时（保留手动触发），在服务器上用 cron 跑同一套脚本，产物 push 回 `deploy` 分支，由 GitHub Actions 的 `deploy.yml` 自动构建部署 Pages。提供一键管理脚本 `crawler/server-task.sh`（复刻 Action 完整流程：pull → 爬取 → 报告 → 清理 → 提交推送）：

```bash
# 一键运行（任务 A：查订阅/新建比赛（--contests-only）；任务 B：仅提交增量同步）
crawler/server-task.sh run [a/b]

# 安装 / 卸载 cron 定时（任务 A 每 30 分钟 + 任务 B 每日，自动适配服务器时区）
crawler/server-task.sh install
crawler/server-task.sh uninstall

# 查看状态 / 日志
crawler/server-task.sh status
crawler/server-task.sh log [N]
```

服务器环境要求：已 clone 仓库、根目录有 `.env` 凭据、`pip install -r crawler/requirements.txt`、Chrome/Chromedriver 在 `crawler/chrome-linux64/` 与 `crawler/chromedriver-linux64/`、已配置 push 凭据（SSH key 或 token）。

> `deploy.yml` 已支持 `push` 到 `deploy` 分支触发：带 `[contests-changed]` 标记的提交才会部署，仅状态变化的提交会跳过。

### 方式三：动态版（v0.3.x 规划中）

自建服务器 / Docker 部署 Next.js 动态服务，支持账号系统、个人收藏、正式资源保护与精确到分钟的调度，详见 [docs/roadmap.md](docs/roadmap.md) §1.1 / §3 / §5。

## 文档

| 文档                                             | 内容                                       |
| ------------------------------------------------ | ------------------------------------------ |
| [docs/CHANGELOG.md](docs/CHANGELOG.md)           | 变更日志（Keep a Changelog 格式）          |
| [docs/architecture.md](docs/architecture.md)     | 架构设计、组件职责、技术决策               |
| [docs/roadmap.md](docs/roadmap.md)               | 开发规划：v0.2.0 / v0.3.0 路线图与决策记录 |
| [docs/notes.md](docs/notes.md)                   | 开发笔记：进度、待办、注意事项             |
| [docs/agent-workflow.md](docs/agent-workflow.md) | AI Agent 开发工作流规范                    |

## License

[MIT](LICENSE) © Appleblue17

本项目仅用于学习与个人归档用途。
