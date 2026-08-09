# Changelog

> 格式基于 [Keep a Changelog](https://keepachangelog.com/)。

## [Unreleased]

### Added

- 平台启用/禁用管理：`crawler/config.json` 每个平台条目支持 `enabled` 字段（**缺省 `false` 视为禁用**，配置文件缺失/解析失败时全部平台禁用），`scheduled_task.py` 启动时按此过滤（任务A/任务B 均生效）；HDU/NowCoder 默认 `enabled: false`；新增模板 `crawler/config.example.json`（gitignore 例外保留模板可提交）
- `config.json` 不再存放用户名等凭据：登录凭据统一由环境变量提供（QOJ/HDU 用户名密码、NowCoder Cookie，见 `.env.example`）
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

- 订阅条目字段 `name` 改名为 `comments`（纯用户备注，代码不读取）；`subscriptions.json` 订阅级 `enabled` 缺省视为启用（与 `config.json` 平台级缺省禁用区分）
- NowCoder 环境变量拼写统一为 `NOWCODER_*`（原 `NEWCODER_COOKIE_*` 为历史遗留错拼）：代码、CI 工作流、文档同步；**CI Secrets 与本地 `.env` 需改名为 `NOWCODER_COOKIE_NOWCODERUID` / `NOWCODER_COOKIE_T`，并新增 `NOWCODER_USERNAME`**（登录态校验用昵称）
- 爬虫与复盘报告解耦：`crawler/scheduled_task.py` 不再调用报告生成（只负责抓取与提交同步）；`crawler/report.py` 作为独立总结脚本运行；两个爬虫工作流均追加独立的报告生成步骤（`python3 crawler/report.py`），爬虫失败不生成报告，报告失败不阻断提交/部署
- 依赖加固：`crawler/requirements.txt` 新增 `setuptools`（Python 3.12+ 移除标准库 distutils，而 `undetected_chromedriver` 3.5.5 仍依赖 `distutils.version`，CI ubuntu-latest 导入即报错）
- 新增 `.env.example`（QOJ/HDU 凭据、NowCoder Cookie、`DEEPSEEK_API_KEY` 模板；`.gitignore` 例外保留该模板可提交）
- 本地浏览器驱动路径统一命名：`crawler/chrome-linux` → `crawler/chrome-linux64`、`crawler/chromedriver_linux64` → `crawler/chromedriver-linux64`（`base.py`、两个 `.gitignore`、`docs/notes.md` 同步）
- 统一爬虫入口：删除 qoj/hdu/nowcoder 三平台模块的 `__main__` 直跑块（原 HDU/NowCoder 的假禁用块不生效，QOJ 的直跑块与新入口重复），全部改为经 `crawler/scheduled_task.py` 运行；删除失效测试脚本 `crawler/fetch_recent.py`；README / notes 命令速查更新为新入口
- 完善文档体系：README 文档索引新增 roadmap；`docs/notes.md` 补充 v0.2.0 待办与技术栈决策
- 爬虫统一改为经 `crawler/scheduled_task.py` 入口运行；`deploy.yml` 触发条件扩展为同时监听两个爬虫工作流
- 前端代码审查修复：格式化工具抽离到 `src/utils/format.ts`、URL 拼接抽离到 `src/utils/url.ts`；文件查看器重构为公共组件 + 页面薄封装；平台徽章修复 fallback；竞赛表格题号列数动态自适应（`maxProblems`）并提升键盘可访问性；首页分页边界、日期排序、横向滚动容器；布局响应式（`w-full max-w-6xl px-4`）
- QOJ 比赛列表跳过未开始的比赛（与 HDU / NowCoder 行为一致）
- 复盘报告 prompt 模板化：`crawler/prompt.template.md`（git 跟踪可直接编辑），注入内容用占位符 `{{contest_info}}` / `{{problems}}` / `{{submissions}}`；题目块新增**完整题面**（`statement.md`，丢弃与题号标题重复的首行）与 solved/solve_time 状态，提交源码按剩余预算（`MAX_PROMPT_CHARS` 减去固定内容）截断、题面优先保留；`report.py` 内置同名 fallback 模板

### Fixed

- HDU / NowCoder 提交记录补抓 `problem_id` 字段（此前只存 `problem_link`，题目映射的 name 兜底失效）：两个平台从 status 页题目列（`cols[2]`，与 `problem_link` 同列）抓取题目 ID（如 "1006"）。注意 **HDU/NowCoder 的 status 页该列显示的是题目 ID 而非题目名**，故不再存 `problem_name`；QOJ 从 `#123. Name` 同时提取 `problem_id`（"123"）与 `problem_name`（真实题目名）。三平台提交的题目匹配统一为三级：`problem_link` → `problem_id` → `problem_name`（`base.py` 新增 `_problem_id_from_link` helper；`report.py` 同步支持，link 有格式差异时不再显示 "?"）
- 补订已完成比赛提交抓不到：HDU/NowCoder 的提交记录在比赛 status 页里，补订时若提交早于全局 `last-update.json`，`_register_submission` 对第一条提交就 `return True` 直接停止，一场都抓不到。`fetch_contests` 记录本次新建的比赛（`_new_contests`），`fetch_submissions` 对首次抓取的比赛以 `start_time` 为截止全量回填（`_deadline_for` + `_register_submission(deadline=...)`）；非首次仍按全局 last-update 增量
- 早于比赛开始时间的提交（跨赛季复用同一道题的历史提交）统一丢弃：`_update_submission_status` 匹配改为从 link/id/name 候选中选"start_time 最晚且不晚于提交时间"的比赛（提交属于其发生的赛季），早于所有匹配比赛开始的提交返回 `DISCARD` 直接丢弃、不再落入 staged；staged 重试循环对 `DISCARD` 的旧提交同样清除。QOJ 全局时间线同样适用
- `contests.json` 条目补充 `start_time` / `end_time`（此前缺失导致时间窗口校验退化为全部匹配）；`fetch_submissions` 改用 `_load_contests_with_times()` 为旧条目按比赛文件夹 `contest.json` 回填一次
- 本地爬虫读不到 `.env` 凭据（`os.getenv` 返回 None → login fatal）：`scheduled_task.py` / `report.py` 顶部新增 `load_dotenv()` 自动加载仓库根 `.env`（不覆盖已有环境变量，CI 无 `.env` 时静默跳过）；`requirements.txt` 新增 `python-dotenv`
- `is_logged_in()` 的 `self.username` 无赋值来源（config.json 不再含 username 后会 `AttributeError`）：QOJ/HDU 在 `login()` 内从环境变量读用户名后赋值，NowCoder 在 `login()` 内读 `NOWCODER_USERNAME` 赋值；QOJ `fetch_submissions` 复用 `self.username`（不再重复读环境变量）
- NowCoder 未迁移订阅模型：`fetch_contests_get_contest_list` 仍读旧的 `input_contests.json`（文件不存在 → 永远抓不到比赛），改为与 HDU/QOJ 一致的 `_load_subscriptions(self.platform_name)`，删除 `input_contests_path`
- `BaseCrawler` 不再把 `config.json` 的 `enabled` 键注入实例（该键仅供 `scheduled_task.py` 过滤平台）
- 根路径 `/` 404：首页逻辑抽到共享 `home-view.tsx`，新增 `(main)/page.tsx` 渲染第 1 页（静态导出生成 `index.html`），`/pageN` 复用同一视图
- 竞赛列表表格布局恢复 v0.1.0 样式：移除 `overflow-x-auto`/`overflow-hidden` 包裹（表格直接渲染），表格 `w-[calc(100%+144px)] table-fixed`，题目列自然延伸到框右侧可见；题号列保底 17 列（A–Q）兼容 >17 题比赛动态扩展；展开块随表格完整渲染不再被截断
- 面包屑 Home 不高亮：`isActive` 对 Home 特判 `/` 与 `/pageN` 前缀
- Markdown 样式缺失：`github-markdown-dark.css` / `katex.min.css` / `github-dark.css` 原只在文件查看器客户端组件 import，按 chunk 切分后 review / readme / dashboard 等页不加载 → 移入根布局全局加载，所有页面统一渲染样式
- 跨赛季提交错误归档：QOJ 提交列表按用户全部历史提交遍历，Universal Cup 等题目跨赛季复用（同名/同链接）会产生早于比赛开始的历史提交被误归档。`_update_submission_status` 增加时间窗口校验（早于 `start_time` 1 天以上视为不匹配，落入 staged）；前端 `getInContestTime` 对早于比赛开始的提交 fallback 显示日期、`convertDurationToHHMMSS` 对负数取 0（修复 E 题显示 -1817:-27:-42 的问题）

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
