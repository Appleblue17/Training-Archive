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

| 部分 | 技术 |
|------|------|
| 前端 | Next.js 15（静态导出）、React 19、TypeScript、Tailwind CSS、Motion |
| 文档渲染 | unified / remark / rehype（Markdown + 数学公式 + 代码高亮）、react-pdf |
| 爬虫 | Python、undetected_chromedriver、BeautifulSoup |
| CI/CD | GitHub Actions（crawler.yml / deploy.yml） |
| 包管理 | pnpm（registry: https://registry.npmmirror.com/） |

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

# 准备配置与环境变量（见 crawler/subscriptions.example.json 与 .env.example）
# 任务A：抓订阅比赛 + 增量同步提交
python3 crawler/scheduled_task.py
# 任务B：每日增量同步提交
python3 crawler/scheduled_task.py --submissions-only
# 复盘报告（独立于爬虫）
python3 crawler/report.py
```

爬虫会生成 `contests/` 数据目录与各平台日志文件（均已被 `.gitignore` 忽略）。

## 文档

| 文档 | 内容 |
|------|------|
| [docs/CHANGELOG.md](docs/CHANGELOG.md) | 变更日志（Keep a Changelog 格式） |
| [docs/architecture.md](docs/architecture.md) | 架构设计、组件职责、技术决策 |
| [docs/roadmap.md](docs/roadmap.md) | 开发规划：v0.2.0 / v0.3.0 路线图与决策记录 |
| [docs/notes.md](docs/notes.md) | 开发笔记：进度、待办、注意事项 |
| [docs/agent-workflow.md](docs/agent-workflow.md) | AI Agent 开发工作流规范 |

## License

[MIT](LICENSE) © Appleblue17

本项目仅用于学习与个人归档用途。
