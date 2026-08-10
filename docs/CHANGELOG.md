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
- 历史提交查看路由：`/view/contests/[contest]/problems/[problem]/submissions/[file]` 支持查看某道题的全部历史提交源码（按 `submissions/<id>.<ext>` 生成静态页，`FileViewerPage` 新增 `subdir` 支持，面包屑展示 submissions 段）

### Changed

- 爬虫目录按职责重组：平台爬虫移入 `crawler/platforms/{qoj,hdu,nowcoder}/`（公共逻辑 `crawler/base.py` → `crawler/platforms/base.py`），DeepSeek 客户端移入 `crawler/llm/deepseek_client.py`（未来可扩展多平台 API），报告模板移入 `crawler/prompts/`（`prompt.template.example.md` / `qq-share.template.example.md`），可执行脚本移入 `crawler/scripts/`（`scheduled_task.py` / `report.py` / `qq_share.py` / `clean-log.py` / `new_contests.py`）；各子目录补 `__init__.py` 成包，导入统一为完全限定（`from crawler.platforms.base import ...`）。平台状态文件路径改为 `crawler/platforms/<platform>/{log,contests,staged-submissions}.json`（前端 log/ 页面 `src/lib/global.ts` 同步）；`new-contests.json` 保持在 `crawler/` 根；CI 工作流、`crawler/server-task.sh` 与文档命令改为 `crawler/scripts/...`；`.gitignore` / `.gitignore.deploy` 路径同步
- 任务A 新增 **`--contests-only`** 模式（高频触发专用）：`crawler-scheduled.yml`（每 30 分钟）与 `server-task.sh run a` 改用 `python3 crawler/scripts/scheduled_task.py --contests-only`——只检查订阅有没有触发（新建比赛），有新建才以该场 `start_time` 为截止回填这些比赛的提交记录，无新建则完全不碰提交，保持轻量；**不推进 `last-update.json`**（已有比赛增量由每日任务B `--submissions-only` 负责，推进会跳过已有比赛在两次任务之间的新提交）。实现：`scheduled_task.run_platform` 改传 mode（`full`/`contests`/`submissions`），`BaseCrawler` 新增 `_contests_only` 标志（`finish()` 在 contests-only 始终不推进 last-update），HDU/NowCoder 的 `fetch_submissions_get_submissions` 只遍历本次新建比赛（其余订阅跳过），QOJ 以最早新比赛开始时间为提交截止（`_register_submission(deadline=...)`）。完整任务A（默认 `scheduled_task.py`）保留为手动/临时模式
- 订阅配置改为目录式管理：`crawler/subscriptions/` 目录取代单文件 `crawler/subscriptions.json`，目录下每个 `*.json` 文件是一份订阅列表（文件名随意，可按平台/系列/月份分组），`BaseCrawler._load_subscriptions` 重写为扫描目录——只识别 `.json` 文件，按文件名排序合并，重复 `link` 去重（保留先出现的条目）；文件缺失/解析失败/非列表时记录日志并跳过；**模板文件 `*.example.json` 跳过**（示例比赛不是真实订阅）。开发分支 `.gitignore` 用 `crawler/subscriptions/*` 忽略目录内容（**不能忽略目录本身**，否则 `!` 规则无法重新纳入模板），模板 `crawler/subscriptions/subscriptions.example.json` 通过 `!` 例外保留提交（deploy 分支 `.gitignore.deploy` 无需改动，目录默认被跟踪）
- 复盘报告改为 `--from-crawl` 模式：任务A 结束把本次新建的比赛文件夹写入 `crawler/new-contests.json`（临时文件，gitignore；无新建比赛时删除旧文件），`report.py` / `qq_share.py` 新增 `--from-crawl` 只对这些比赛生成 review / qq-share（幂等，不再每次全量扫描）；读写逻辑抽离为共享模块 `crawler/new_contests.py`；两个爬虫工作流与 `crawler/server-task.sh` 的 report 步骤改用 `python3 crawler/report.py --from-crawl`（任务B 无新建比赛自然跳过）。注意：**进行中**被首次抓取的比赛当次不会生成报告，且后续不再新建该文件夹，需手动指定文件夹或全量扫描补生成
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
- 复盘报告 prompt 模板化：`crawler/prompt.template.md`（gitignore 本地可自由调整，副本 `crawler/prompt.template.example.md` 可提交），注入内容用占位符 `{{contest_info}}` / `{{problems}}` / `{{submissions}}`；题目块新增**完整题面**（`statement.md`，丢弃与题号标题重复的首行）与 solved/solve_time 状态，提交源码按剩余预算（`MAX_PROMPT_CHARS` 减去固定内容）截断、题面优先保留；`report.py` 内置同名 fallback 模板（与 `.example.md` 内容一致）
- QQ 群分享简化版报告：`generate_qq_share` 基于已生成的 `review.md` 再调一次 DeepSeek（更高 temperature），生成轻松幽默、带 emoji 的**纯文本**总结（200-300 字），落盘 `qq-share.txt`；模板 `crawler/qq-share.template.md`（gitignore 本地可自由调整，副本 `crawler/qq-share.template.example.md` 可提交，占位符 `{{review}}`，内置 fallback 与副本一致）；完整报告生成后自动串联生成简化版（幂等），`--qq-only` 支持单独补生成。**QQ 群发送集成尚未接入（后续阶段）**
- 爬虫脚本模块化拆分：DeepSeek 客户端抽离为 `crawler/deepseek_client.py`（`call_deepseek` + 代理归一化 + `.env` 加载，report / qq_share 共用）；QQ 群分享简化版抽离为 `crawler/qq_share.py`（独立可运行：`python3 crawler/qq_share.py [folder]`）；`report.py` 仅保留完整报告生成并转调 `qq_share`，`--qq-only` 作为兼容入口保留
- 前端内部路由统一改为**根相对路径 + `next/link`**（`joinUrl("/", ...)` 或 `href="/"`，Link 自动添加一次 `basePath`）；外部链接（平台 contest/problem、下载类）保留 `<a>` + `PREFIX_URL`（见 `docs/architecture.md` §5 ADR）
- Dashboard 复盘入口改版：移除独立 "Contest Reviews" 板块，有 `review.md` 的比赛在"最近比赛"列表中显示 Review 链接（`ArrowUpRight` 图标）；平台分布计数改为 `x{count}` 展示；搜索页结果列表间距收紧
- 搜索索引 `public/search-index.json` 重新生成，清除已删除比赛的陈旧条目（现仅含现有钉耙编程 A–M 比赛）
- 入口链接统一指向题面页：搜索/最近完成/复盘时间轴等链接目标改为 `statement.md`/`statement.pdf` 优先（`generate-search-index.mjs` 与 Dashboard 聚合逻辑同步），代码页另以 `Code` 图标单独提供（Dashboard Recently Solved 每行含题面链接 + 代码图标链接）
- 时间显示统一为 `YYYY/MM/DD HH:MM`（24 小时制，北京时间，无秒）：`src/utils/format.ts` 新增 `formatDateTime`，Dashboard 最近完成与复盘时间轴共用
- 内容查看类链接统一新标签页打开（`target="_blank"` + `rel="noopener noreferrer"`）：复盘 Source / 原始 markdown、Dashboard 题面与代码、搜索全部结果
- lucide 图标尺寸统一（`size-4` 等）：页脚 GitHub 图标、日志/文件查看器的复制按钮与源码/下载图标（视觉一致性微调）
- `/readme` 页渲染样式与文件查看器统一：直接复用 `FileViewerMarkdown` 组件（深色 `bg-[#0d1117]` 容器、边框、右上角复制按钮、`p-12` 可滚动区域），不再使用 `Card` 包裹；README 缺失时以同风格容器显示提示
- Dashboard 统计卡片 AC 替换为 **Total Code**：新增 `getTotalCodeBytes()`（`contests/*/problems/*/submissions/` 归档源码字节数总和，`formatSize` 显示），AC 提交数语义与 Solved 重复且无区分度
- Contribution 绿点图改版：①方格布局由 `grid grid-rows-7`（隐式列被 `justify-content: stretch` 拉伸导致横向 gap 虚大）改为 **flex 每列固定 10px**（`flex flex-col gap-[3px]` 按周分列），横向/纵向 gap 严格一致；②新增 **X 轴月份标签**（锚定该月第一天所在周列，绝对定位）与 **Y 轴星期标签**（Sun/Mon/Wed/Fri，与 7 行对齐）；③悬浮提示改为**自定义 tooltip**（绝对定位 + `scrollLeft` 校正，首行下方/其余上方显示，`YYYY/MM/DD` 日期），替代原生 `title`；单元格保留 `role="img"` + `aria-label`
- Contribution 卡片宽度与 Y 轴标签收尾：卡片加 `w-fit max-w-full`（不再被 `w-full` 容器拉伸，收缩到内容宽度）；Y 轴星期标签补全 7 天（Sun–Sat，列宽 26→30px）
- 部署方式确认与文档化：静态版（v0.2.0）拆为两种部署方式——①GitHub Actions 自动任务（开启两个 workflow 的 `schedule`，零运维）；②自建服务器 cron 跑同一套脚本（关闭 schedule，产物 push 回 `deploy` 分支触发部署，需自行接入部署触发）；动态版（v0.3.x）单列。记录至 `docs/roadmap.md` §1.1 并写入 README「部署方式」章节
- 方式二一键管理脚本 `crawler/server-task.sh`：复刻 Action 完整流程（pull deploy 分支 → 跑爬虫任务 → 生成报告 → 清理日志 → 提交推送，`[contests-changed]` 标记规则一致）；子命令 `run [a|b]` / `install` / `uninstall` / `status` / `log [N]`；内建 `flock` 防并发、`.env` 加载（cron 环境不继承）、`TZ=Asia/Shanghai`、venv 自动探测、依赖检查、cron 时区自动适配
- `deploy.yml` 支持方式二部署触发：新增 `on: push: branches: [deploy]`——push 事件免日期校验，仅带 `[contests-changed]` 标记的提交部署；`deploy` job 条件收紧为 `should_deploy == 'true' || workflow_dispatch`（原 `!= workflow_run` 会让 push 事件无条件部署）
- `.gitignore` / `.gitignore.deploy` 忽略 `crawler/server-task.log`（运行日志不入库）

### Fixed

- `/log` 页面在日志文件缺失时显示占位提示而非报错：日志是运行时产物（`crawler/global.log.json` 与 `crawler/platforms/*/log.json` 被 gitignore 不提交版本控制），deploy 分支 / 全新 clone 上 `/log` 读取路径必然不存在，此前页面显示 `Error reading file: ENOENT...`（空内容在 log 类型还显示 "Invalid log format"）。改为读取失败返回空串、前端渲染"暂无日志文件"占位（含生成路径提示），有日志时正常显示
- 静态导出在无可用数据时失败：全部 5 个动态路由（`/[page]`、`/review/[contest]`、`/view/contests/[contest]/[file]`、`/view/contests/[contest]/problems/[problem]/[file]`、`/view/contests/[contest]/problems/[problem]/submissions/[file]`）的 `generateStaticParams` 在 `contests/` 无数据或不存在时返回空数组 / `readdirSync` 抛错，`output: export` 判定动态路由无法构建而报错。统一改为：`contests/` 不存在时判空，无匹配数据时返回占位参数（`~no-data~`），页面内部渲染"暂无数据"提示；`/[page]` 兜底输出 `page1`（HomeView 渲染空列表）。数据由爬虫生成后占位页自然消失。影响面：deploy 分支旧数据（无 `submissions.json`/`review.md`/提交历史）或全新 clone 空 `contests/` 时 build 均可通过
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
- 线上链接双前缀 404：`next/link` 的 `addBasePath()` 会无条件给 href 添加 `basePath`，而内部路由代码又手动 `joinUrl(PREFIX_URL, ...)` 拼接一次 → 生成 `/Training-Archive/Training-Archive/...`，线上页面点击 404（已 curl 实测验证）。修复：内部路由改用根相对路径（`joinUrl("/", ...)` / `href="/"`），由 Link 仅添加一次前缀；外部/下载类链接保留 `<a>` + `PREFIX_URL`（不经过 Link，行为本就正确）
- 复盘时间轴 Source 链接 404：源码文件位于 `problems/<letter>/submissions/<id>.<ext>`，而链接指向 `problems/<letter>/<file>` 且无对应路由。新增 `submissions/[file]` 路由并修正 `sourceHref`
- 搜索/最近完成入口误链到代码页：`generate-search-index.mjs` 的 `viewFile` 取问题目录首个非 JSON 文件，`code.cpp` 字典序排在 `statement.md` 前 → 已解决题目搜索结果指向代码查看页。改为 `statement.md`/`statement.pdf` 优先
- view 链接缺 `/contests/` 段：`review-timeline`/`review` 页/`dashboard`/`search` 用裸 `contestFolder`（仅文件夹名）拼接 `view` 路由，但路由实际为 `/view/contests/<folder>/...` → 404。四处统一补上 `"contests"` 段（`contest-table` 用含前缀的 `rel_path`，本就正确）

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
