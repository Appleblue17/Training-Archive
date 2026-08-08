# Changelog

> 格式基于 [Keep a Changelog](https://keepachangelog.com/)。

## [Unreleased]

### Added

- 新增 `docs/roadmap.md`：记录 v0.2.0 / v0.3.0 规划讨论与决策（双版本架构、功能分级、爬虫触发机制、DeepSeek 报告生成、GitHub OAuth 账号系统等）
- 选定 UI 库 shadcn/ui 与图标库 lucide-react（替换 react-icons）
- 爬虫订阅模型：`crawler/subscriptions.json` 统一订阅配置（QOJ / HDU / NowCoder 按 `platform` + `enabled` 过滤），替换 `input_contests.json`
- 全量提交采集：`_archive_submission()` 按 `submission_id` 幂等归档到 `submissions.json` 与 `problems/<letter>/submissions/<id>.<ext>`；源码抓取失败不阻断元数据记录
- 复盘报告生成：`crawler/report.py` 调用 DeepSeek 生成 `review.md`（存在即跳过，幂等），支持对已结束且有提交的比赛生成
- 定时任务入口：`crawler/scheduled_task.py` 任务 A（抓订阅比赛 + 增量同步）与任务 B（`--submissions-only` 每日增量同步）；单平台失败不阻断；`finish()` 仅在完整同步时推进 `last-update.json`
- deploy 分支专用 `.gitignore.deploy`（contests/ 与爬虫增量状态纳入版本控制，保证增量同步跨运行生效，手动上传代码可正常跟踪）
- 双定时工作流：`crawler-scheduled.yml`（任务 A，每 30 分钟）与 `crawler.yml`（任务 B，每日 20:00 UTC），共享 `concurrency` 组，提交时用 `.gitignore.deploy` 覆盖 `.gitignore`；**定时未启用**（未实测前手动触发验证）
- 题目标签支持：`problem.json` 新增 `tags`，QOJ 爬虫 best-effort 提取，前端以彩色徽章渲染
- 搜索功能：构建时脚本 `scripts/generate-search-index.mjs` 扫描 `contests/` 生成 `public/search-index.json`（问题级索引），新增 `/search` 页支持关键词（多词 AND）+ 标签过滤，结果按平台徽章/比赛/日期展示并链接到文件查看页；`pnpm build` 前置生成索引
- Dashboard（C3）：统计卡片（比赛/题目/已解决/提交/AC + 平台分布）、最近比赛、最近完成题目、contribution 绿点图（52 周，按提交日期聚合）、复盘报告区（当前报告全文 + 往期列表）；数据在构建时从 `contests/` 聚合
- 复盘时间轴页（C4）：`/review/[contest]` 按 `submit_time` 展示每次提交（状态着色、语言、耗时/内存、源码与平台链接）+ LLM 复盘报告全文
- 共享服务端数据模块 `src/lib/contests-data.ts`（`getContests`/`getAllSubmissions`/`getReviews`）与 Markdown 渲染工具 `src/utils/render-markdown.ts`（文件查看器与复盘报告共用同一 unified 流水线）
- UI 库落地（C5）：引入 shadcn/ui 风格基础组件（`src/components/ui/`：`button` / `card` / `badge` / `input`，基于 `class-variance-authority` + `tailwind-merge` + `@radix-ui/react-slot`）与 `src/lib/utils.ts`（`cn()`）；`Card` 支持 `asChild`；Dashboard / 复盘时间轴 / 搜索 / 复盘详情页逐步应用 `Card`，搜索输入框应用 `Input`
- 图标库迁移（C5）：`react-icons` → **lucide-react**，全量替换 13 个文件中的图标引用（品牌图标如 Github 改用 `ExternalLink`）
- 前端收尾（C6）：全局错误边界 `error.tsx`（渲染错误可重置）、自定义 `not-found.tsx`（404 页 + 返回入口）、全局 `loading.tsx` 骨架屏；无障碍复查确认表格展开行 `aria-expanded`、搜索/看板/报告区 `aria-label`、复制按钮自带文本均覆盖
- README 页实现：`/readme` 构建时读取仓库根 `README.md`，用统一 unified 流水线渲染（替换占位页，移除 `<img>` 警告）

### Changed

- 爬虫与复盘报告解耦：`crawler/scheduled_task.py` 不再调用报告生成（只负责抓取与提交同步）；`crawler/report.py` 作为独立总结脚本运行；两个爬虫工作流均追加独立的报告生成步骤（`python3 crawler/report.py`），爬虫失败不生成报告，报告失败不阻断提交/部署
- 依赖加固：`crawler/requirements.txt` 新增 `setuptools`（Python 3.12+ 移除标准库 distutils，而 `undetected_chromedriver` 3.5.5 仍依赖 `distutils.version`，CI ubuntu-latest 导入即报错）
- 新增 `.env.example`（QOJ/HDU 凭据、NowCoder Cookie、`DEEPSEEK_API_KEY` 模板；`.gitignore` 例外保留该模板可提交）
- 本地浏览器驱动路径统一命名：`crawler/chrome-linux` → `crawler/chrome-linux64`、`crawler/chromedriver_linux64` → `crawler/chromedriver-linux64`（`base.py`、两个 `.gitignore`、`docs/notes.md` 同步）
- 完善文档体系：README 文档索引新增 roadmap；`docs/notes.md` 补充 v0.2.0 待办与技术栈决策
- 爬虫统一改为经 `crawler/scheduled_task.py` 入口运行；`deploy.yml` 触发条件扩展为同时监听两个爬虫工作流
- 前端代码审查修复：格式化工具抽离到 `src/utils/format.ts`、URL 拼接抽离到 `src/utils/url.ts`；文件查看器重构为公共组件 + 页面薄封装；平台徽章修复 fallback；竞赛表格题号列数动态自适应（`maxProblems`）并提升键盘可访问性；首页分页边界、日期排序、横向滚动容器；布局响应式（`w-full max-w-6xl px-4`）
- QOJ 比赛列表跳过未开始的比赛（与 HDU / NowCoder 行为一致）

### Fixed

- 根路径 `/` 404：首页逻辑抽到共享 `home-view.tsx`，新增 `(main)/page.tsx` 渲染第 1 页（静态导出生成 `index.html`），`/pageN` 复用同一视图
- 竞赛列表表格布局恢复 v0.1.0 样式：移除 `overflow-x-auto`/`overflow-hidden` 包裹（表格直接渲染），表格 `w-[calc(100%+144px)] table-fixed`，题目列自然延伸到框右侧可见；题号列保底 17 列（A–Q）兼容 >17 题比赛动态扩展；展开块随表格完整渲染不再被截断
- 面包屑 Home 不高亮：`isActive` 对 Home 特判 `/` 与 `/pageN` 前缀
- Markdown 样式缺失：`github-markdown-dark.css` / `katex.min.css` / `github-dark.css` 原只在文件查看器客户端组件 import，按 chunk 切分后 review / readme / dashboard 等页不加载 → 移入根布局全局加载，所有页面统一渲染样式
- 跨赛季提交错误归档：QOJ 提交列表按用户全部历史提交遍历，Universal Cup 等题目跨赛季复用（同名/同链接）会产生早于比赛开始的历史提交被误归档。`_update_submission_status` 增加时间窗口校验（早于 `start_time` 1 天以上视为不匹配，落入 staged）；前端 `getInContestTime` 对早于比赛开始的提交 fallback 显示日期、`convertDurationToHHMMSS` 对负数取 0（修复 E 题显示 -1817:-27:-42 的问题）
- 新增 `crawler/fetch_recent.py`：只爬取最近 N 天提交的测试脚本（`--platform` / `--days`），通过把增量基准 `last_update_time` 设为 `now - N` 天实现，不读取/不推进 `last-update.json`（不污染正式增量状态），三平台通用

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
