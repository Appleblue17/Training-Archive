# Changelog

> 格式基于 [Keep a Changelog](https://keepachangelog.com/)。

## [Unreleased]

### Added

- 新增 `docs/roadmap.md`：记录 v0.2.0 / v0.3.0 规划讨论与决策（双版本架构、功能分级、爬虫触发机制、DeepSeek 报告生成、GitHub OAuth 账号系统等）
- 选定 UI 库 shadcn/ui 与图标库 lucide-react（替换 react-icons）

### Changed

- 完善文档体系：README 文档索引新增 roadmap；`docs/notes.md` 补充 v0.2.0 待办与技术栈决策

## [0.1.0] - 2026-01-04

包含 contest 归档 Web 应用（Next.js 静态站点）与 QOJ / HDU / NowCoder 三平台爬虫。此部分变更均按 Git 历史整理。

### Added

- 初始化 Next.js 项目与全局布局（导航、页脚、站点标题与图标）
- contest 列表首页：contest 表格、平台徽章、题目状态（AC/尝试未解决）、文件图标、分页（每页 20 条）
- contest / 题目 / 文件多级路由（`/view/contests/...`）
- 文件查看器：Markdown（GFM、数学公式、KaTeX、代码高亮）、PDF（懒加载、滚动）、源码高亮
- 文件下载与元数据展示（提交状态、提交/解决时间、内存/时间限制等）
- 日志页面：展示各平台爬虫日志与 staged submissions
- 爬虫状态徽章与最后更新时间显示
- 面包屑导航、README 页面
- QOJ 爬虫：登录、contest 抓取、提交与代码文件抓取
- HDU 爬虫：登录、contest 抓取、HTML 转 Markdown 题目
- NowCoder 爬虫：登录（Cookie）、contest抓取、提交抓取
- `BaseCrawler` 基类：配置加载、日志、随机等待、北京时间处理、语言识别、文件写入
- 日志清理脚本（`crawler/clean-log.py`）
- GitHub Actions 工作流：`crawler.yml`（定时抓取，检测变更后自动提交）、`deploy.yml`（构建并部署到 GitHub Pages）
- MIT License

### Changed

- contest / 题目元数据结构重构，统一由 `contest.json` / `problem.json` 描述
- URL 处理重构：基于 `NODE_ENV` 的 `BASE_URL` / `PREFIX_URL` / `REPO_URL` 统一管理
- 提交抓取逻辑拆分为独立模块，便于扩展新平台
- 文件查看器简化：移除 PDF wrapper，直接使用 `FileViewerPDF`
- 爬虫调度调整为仅当contest数据变化时提交推送
- 时间处理统一使用北京时间；提交耗时改为 `solve_time - start_time`
- 多处样式与布局优化（响应式、悬停效果、行高、平台徽章颜色、面包屑高度等）
- 2025-08-10 前端细节调整：
  - 修复无关联文件的题目项行高异常
  - 题目文件视图移除重复的代码文件展示，代码改在右侧展示
  - 悬停代码文件时展示其详细信息，与其他文件保持一致
  - 尝试但未解决的题目网格使用黄色背景标记
- 实现日志页面并改进面包屑样式

### Fixed

- 数学公式分隔符正则全局匹配问题
- 提交抓取无提交时死循环（补 `break`）
- 北京时间解析与时区（Beijing time）处理
- 分页边界与显示问题
- 爬虫退出清理（`finish` 方法）；HDU / QOJ 登录方法增加显式等待
- 部署工作流：日期格式、pnpm 安装顺序、Node 版本、PNPM 缓存等 CI 问题

### Removed

- 停止跟踪 contest 数据文件（`contests/`、staged submissions、log、config 等，改为运行时生成），这些文件移动至 deploy 分支跟踪
