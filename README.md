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
│   ├── platforms/              # 各平台爬虫
│   │   ├── base.py             # BaseCrawler 基类（日志、配置、时间、文件写入）
│   │   └── {qoj,hdu,nowcoder}/ # 各平台爬虫
│   ├── scripts/                # 可执行脚本（scheduled_task.py、report.py、clean-log.py 等）
│   ├── llm/                    # LLM 客户端（deepseek_client.py）
│   └── prompts/                # 报告模板（.example.md 提交，本地模板 gitignore）
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
# 默认模式：抓订阅比赛 + 全量增量提交（手动/临时）
python3 crawler/scripts/scheduled_task.py
# 只查订阅/新建比赛（--contests-only：有新建才回填其提交；高频触发推荐）
python3 crawler/scripts/scheduled_task.py --contests-only
# 只抓指定订阅链接（服务器闹钟 fire / sync 补抓用；与 --contests-only 语义一致）
python3 crawler/scripts/scheduled_task.py --contests-only --links "https://qoj.ac/contest/123"
# 提交增量模式（--submissions-only：每日一次增量提交同步）
python3 crawler/scripts/scheduled_task.py --submissions-only
# 复盘报告（独立于爬虫，只对本次爬取新建的比赛生成；--links 可只对指定链接生成）
python3 crawler/scripts/report.py --from-crawl
python3 crawler/scripts/report.py --from-crawl --links "https://qoj.ac/contest/123"
# 补生成：扫描所有缺报告的已结束比赛，或只生成指定比赛
python3 crawler/scripts/report.py
python3 crawler/scripts/report.py "contests/2026-08-01 xxx"
```

爬虫会生成 `contests/` 数据目录与各平台日志文件（均已被 `.gitignore` 忽略）。

## 部署方式

网站提供三种部署方式，当前实现为**静态版（v0.2.x）**；动态版（v0.3.x）规划中，详见 [docs/roadmap.md](docs/roadmap.md) §1.1。

### 方式一：GitHub Actions 自动任务（默认，零运维）

GitHub 云端定时运行爬虫，自动提交并部署到 GitHub Pages：

1. 在仓库 Secrets 配置凭据（QOJ/HDU 账号、NowCoder Cookie、`DEEPSEEK_API_KEY`，见 `.env.example`）。
2. 开启两个工作流的定时（取消注释 `schedule`）：
   - `.github/workflows/crawler-scheduled.yml`：每 30 分钟查订阅/新建比赛（`--contests-only`，有新建才回填其提交）
   - `.github/workflows/crawler.yml`：每日 20:00 UTC 提交增量同步（`--submissions-only`）
3. 爬虫完成后自动触发 `deploy.yml` 部署 Pages。

### 方式二：自建服务器跑脚本

关闭工作流的定时（保留手动触发），在服务器上用 cron 跑同一套脚本，产物 push 回 `deploy` 分支，由 GitHub Actions 的 `deploy.yml` 自动构建部署 Pages。提供一键管理脚本 `crawler/server-task.sh`（复刻 Action 完整流程：pull → 爬取 → 报告 → 清理 → 提交推送）：

```bash
# 提交增量同步（--submissions-only；每日一次，install 的 cron 自动调用）
crawler/server-task.sh incremental

# 更新订阅后手动同步（闹钟机制）：
#   历史比赛（订阅不填 end_time）→ 立即爬取归档，不生成报告
#   过期比赛（end_time 已过）    → 立即爬取并生成报告（如闹钟失败后补漏）
#   未来比赛（end_time 未到）    → 写入闹钟表，到点由 fire 触发
#   失败重试（上次 failed）      → 重试一次：成功 → archived，失败保持 failed（日志会提示）
crawler/server-task.sh sync

# 安装 / 卸载 cron 定时（闹钟检查每分钟 + 提交增量每日，自动适配服务器时区）
crawler/server-task.sh install
crawler/server-task.sh uninstall

# 查看状态（cron / 闹钟 / git / 日志）/ 查看日志
crawler/server-task.sh status
crawler/server-task.sh log [N]
```

**闹钟机制（方式二专用）**：订阅条目可选填 `end_time`（比赛结束时间，ISO 格式，如 `"2026-08-15T23:00:00+08:00"`）。`sync` 把未来比赛写入运行时状态文件 `crawler/alarms.json`（gitignore，不提交）并标记为 `planned`，cron 每分钟调用 `fire` 检查：到点即爬取该场比赛（`--contests-only --links`）并立即生成复盘报告，精确到分钟，替代原来的 30 分钟轮询。闹钟状态模型：`planned`（未来等 fire）/ `pending`（sync 待立即处理）/ `archived`（已处理完，fire 忽略）/ `failed`（爬取失败，fire 忽略）。**爬取失败即标记 `failed`（不再自动重试），下次手动 `sync` 重试一次：成功 → `archived`，失败保持 `failed`，且 sync 日志会提示用户**。订阅里修改 `end_time` 或删除条目时，`sync` 会相应重新安排或剪除闹钟。方式一（GitHub Actions）仍用轮询，不读取 `end_time` 字段。

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
