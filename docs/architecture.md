# 架构设计

> 本文档描述 Training Archive 的系统架构、组件职责与关键技术决策。相对稳定，重大变更时更新。

---

## 1. 系统概览

项目由两部分组成，通过 `contests/` 数据目录衔接：

```
┌──────────────────┐   抓取/归档    ┌──────────────────┐   构建时读取    ┌──────────────────┐
│  Python 爬虫     │ ────────────► │   contests/      │ ─────────────► │  Next.js 静态站点  │
│  qoj / hdu /     │   JSON + 文件  │  (deploy 分支跟踪)│   fs 读取       │  GitHub Pages 部署 │
│  nowcoder        │               └──────────────────┘                └──────────────────┘
└──────────────────┘
```

- **爬虫子系统**：定时（方式一 Actions：任务A 查订阅/预订比赛抓取，每 30 分钟 `--contests-only`；方式二服务器：预订比赛用闹钟机制 `sync`/`fire`，见 4.6；任务B 提交周期同步，每天）抓取竞赛、题目、提交与代码，写入 `contests/` 目录和各类日志；复盘报告由独立脚本 `crawler/scripts/report.py` 生成。
- **前端子系统**：Next.js 静态导出。构建时通过 `fs` 读取 `contests/` 目录与 JSON 元数据，生成竞赛列表、题目详情、文件查看与复盘页面。
- **CI/CD**：`crawler-scheduled.yml`（任务A）与 `crawler.yml`（任务B）在 `deploy` 分支上运行爬虫并提交数据；`deploy.yml` 检测到当日数据变更后构建并发布到 GitHub Pages。

## 2. 数据布局

`contests/` 目录结构（由爬虫生成，构建时被前端读取）：

```
contests/
└── <YYYY-MM-DD> <contest name>/
    ├── contest.json                 # 竞赛元数据
    ├── <attachment>.pdf             # 竞赛附件
    ├── submissions.json             # 全部提交元数据数组（复盘数据源）
    ├── review.md                    # LLM 复盘报告（DeepSeek 生成，存在即跳过）
    └── problems/
        └── <letter>/                # A、B、C ...
            ├── problem.json         # 题目元数据（含 solved / solve_time / submit_time / tags）
            ├── statement.pdf        # 题目 PDF
            ├── code.cpp             # AC/最新提交源码
            ├── code.cpp.json        # 提交元数据（status / language / time / memory ...）
            └── submissions/         # 每一份提交的源码（全量采集）
                └── <id>.cpp
```

### 元数据约定

| 文件 | 内容要点 |
|------|----------|
| `contest.json` | `name`、`date`、`platform`、`start_time`、`end_time`、`link`、`difficulty` 等 |
| `problem.json` | `letter`、`name`、`link`、`time_limit`、`memory_limit`、`solved`、`solve_time`、`submit_time`、`tags` |
| `code.<ext>.json` | 提交详情：`submission_id`、`status`、`language`、`submit_time` 等 |
| `submissions.json` | 全部提交元数据数组（`submission_id`、`problem`、`status`、`language`、`submit_time`、`time`、`memory`） |
| `review.md` | DeepSeek 生成的复盘报告，存在即跳过（幂等） |

时间统一为 **北京时间（UTC+8）ISO 格式**。

## 3. 前端架构

### 3.1 路由结构（`src/app/`）

| 路由 | 职责 |
|------|------|
| `layout.tsx` | 根布局：全局字体、页脚、favicon、markdown 样式（github-markdown-dark / katex / github-dark 全局加载） |
| `(main)/layout.tsx` | 主布局：标题、爬虫状态徽章、面包屑导航 |
| `(main)/page.tsx` | 根路径 `/`：竞赛列表第 1 页 |
| `(main)/(home)/[page]/page.tsx` | 竞赛列表 `/pageN`（服务端取数 + 分页），每页 20 条；与根路径共用 `home-view.tsx` |
| `(main)/(home)/[page]/contest-table.tsx` | 竞赛表格（客户端）：可展开行、题目状态、悬停元数据面板 |
| `(main)/search/page.tsx` | 搜索页（服务端读索引） |
| `(main)/search/search-client.tsx` | 搜索交互（客户端）：关键词 + 标签过滤、结果列表 |
| `(main)/dashboard/page.tsx` | 数据看板（服务端聚合统计/最近动态/contribution/复盘报告） |
| `(main)/dashboard/dashboard-client.tsx` | 数据看板展示（客户端）：统计卡片、绿点图、最近动态（含复盘入口，有 `review.md` 的比赛显示 Review 链接） |
| `(main)/review/[contest]/page.tsx` | 复盘时间轴页：按 `submit_time` 展示提交序列 + LLM 报告 |
| `(main)/review/[contest]/review-timeline.tsx` | 提交时间轴（客户端）：状态着色、源码链接 |
| `(main)/log/page.tsx` + `log-page.tsx` | 日志页：按平台展示日志与 staged submissions |
| `(main)/readme/page.tsx` | README 页（占位，未实现） |
| `view/contests/[contest]/[file]/page.tsx` | 竞赛级文件查看页 |
| `view/contests/[contest]/problems/[problem]/[file]/page.tsx` | 题目级文件查看页 |
| `view/contests/[contest]/problems/[problem]/submissions/[file]/page.tsx` | 题目历史提交查看页（`problems/<letter>/submissions/<id>.<ext>`） |

### 3.2 关键模块

| 模块 | 职责 |
|------|------|
| `src/lib/types.ts` | 数据类型：`FileMetadataType` / `CodeFileType` / `ProblemInfoType` / `ContestInfoType` / `SearchIndexEntryType` |
| `src/lib/global.ts` | 全局配置：`BASE_URL` / `PREFIX_URL` / `REPO_URL`、`allowedExtensions`、`logFileList`、`ITEMS_PER_PAGE` |
| `src/lib/contests-data.ts` | 服务端数据读取（仅服务端 import）：`getContests` / `getAllSubmissions` / `getReviews` / `safeParseJson`；首页与 Dashboard 共用 |
| `scripts/generate-search-index.mjs` | 构建时扫描 `contests/` 生成 `public/search-index.json`（问题级索引：题目/标签/比赛/平台/日期 + 跳转文件） |
| `src/utils/get-file-metadata.ts` | 读取文件元数据，合并 `<file>.json` 侧车文件 |
| `src/utils/format.ts` | 格式化工具：`formatKey` / `formatSize` / `formatDate` / `formatDateTime`（`YYYY/MM/DD HH:MM`，24h 北京时间） |
| `src/utils/url.ts` | 轻量 URL 拼接 `joinUrl`（客户端组件替代 `path.join`） |
| `src/utils/render-markdown.ts` | 服务端 Markdown→HTML（unified 流水线，与文件查看器共用；复盘报告渲染） |
| `src/components/metadata-display.tsx` | 元数据面板（格式化函数见 `src/utils/format.ts`） |
| `src/components/platform-badge.tsx` | 平台徽章（qoj / hdu / nowcoder / codeforces） |
| `src/components/ui/` | 基础 UI 组件（shadcn/ui 风格）：`button` / `card` / `badge` / `input`；`Card` 支持 `asChild`（@radix-ui/react-slot） |
| `src/lib/utils.ts` | `cn()`：tailwind-merge + clsx 合并 className（客户端工具） |
| `src/components/file-viewer/` | 文件查看器（见下） |

### 3.3 文件查看器（`file-viewer/`）

按扩展名分发：

- `file-viewer.tsx`：入口，按 `allowedExtensions` 分发到 PDF / Markdown / 源码 / 不支持类型（提供下载）。
- `file-viewer-page.tsx`：竞赛级 / 题目级 / 题目历史提交查看页的公共渲染组件，支持 `subdir`（如 `submissions`，历史提交路由使用）拼接到题目目录路径。
- `file-viewer-pdf.tsx`：PDF 渲染（react-pdf）。
- `file-viewer-markdown-wrapper.tsx`：**服务端**调用共享 `render-markdown.ts` 的 unified 流水线把 Markdown 转为 HTML（remark-parse → remark-math → remark-gfm → remark-img-links → remark-rehype → rehype-sanitize → rehype-highlight → rehype-katex → rehype-format → rehype-stringify）。
- `file-viewer-markdown.tsx`：**客户端**渲染 HTML（`dangerouslySetInnerHTML`）并提供复制按钮。
- `file-viewer-source.tsx`：**客户端**源码高亮（react-syntax-highlighter）并提供复制按钮。

> 数学公式预处理：`$$\n...\n$$` 在 wrapper 中被临时改写为 `$$$$\n...\n$$$$` 以适配 KaTeX 流水线（见 `file-viewer-markdown-wrapper.tsx` 的 `mathRegex`）。

### 3.4 静态生成与部署

- 所有页面通过 `generateStaticParams` + 构建时 `fs` 扫描 `contests/` 生成静态路由。
- 生产构建（`NODE_ENV=production`）时 `next.config.ts` 启用 `output: "export"`、`basePath: "/Training-Archive"`；`BASE_URL` / `PREFIX_URL` 据此切换（见 `src/lib/global.ts`）。
- 搜索索引：`pnpm build` 先运行 `scripts/generate-search-index.mjs` 生成 `public/search-index.json`，搜索页在构建时读取该索引并传给客户端组件过滤（**方案 A**：构建索引 + 前端过滤，不引搜索库，数据量小；必要时可加 Fuse.js）。动态版（v0.3.0）改用服务端 API + DB 查询，搜索页 UI 复用。
- `deploy.yml` 先将 `contests/` 复制到 `public/contests/`，再执行 `pnpm build`，最后由 `actions-gh-pages` 发布 `out/`。
- 主分支（`main`）不含 `contests/` 数据；实际爬取与部署都在 `deploy` 分支进行。

### 3.5 UI 组件与图标

- 基础组件采用 shadcn/ui 风格（自行维护 `src/components/ui/`，基于 `class-variance-authority` + `tailwind-merge` + `@radix-ui/react-slot`），依赖 `src/lib/utils.ts` 的 `cn()` 合并样式。
- 图标统一使用 **lucide-react**（替代 react-icons）。注意：lucide 已移除品牌图标（如 Github），品牌链接改用 `ExternalLink` 等通用图标。
- 已应用 `Card` 的页面：Dashboard、复盘时间轴、搜索页、复盘详情页（比赛信息卡 + 报告区）；搜索输入框用 `Input`。

## 4. 爬虫架构

### 4.1 基类 `crawler/platforms/base.py`（`BaseCrawler`）

统一的模板方法框架，平台差异由子类实现：

| 方法 | 职责 | 默认行为 |
|------|------|----------|
| `login()` | 平台登录 | 抽象，子类实现（QOJ/HDU 密码登录、NowCoder Cookie） |
| `fetch_contests()` | 竞赛抓取总流程 | 遍历竞赛 → 建目录 → 写 `contest.json` → 抓题目 → 写 `problem.json` |
| `fetch_contests_get_contest_list()` | 抓竞赛列表 | 抽象 |
| `fetch_contests_get_problem_list()` | 抓题目列表（可下载附件） | 抽象 |
| `fetch_contests_get_problem_details()` | 抓题目详情（PDF、时限/内存） | 抽象 |
| `fetch_submissions()` | 提交抓取总流程 | 先更新 staged submissions，再增量抓取新提交 |
| `fetch_submissions_get_submissions()` | 抓提交列表 | 抽象，逐条调用 `_register_submission()` |
| `fetch_submissions_fetch_source_code()` | 抓源码 | 抽象 |
| `_update_submission_status()` | 提交落盘 | 按 `problem_link`/`problem_name` 匹配竞赛题目，全量归档到 `submissions.json` + `submissions/<id>.<ext>`，并写入 `code.<ext>` 与 `problem.json`；匹配不到则进 staged submissions |
| `_archive_submission()` | 单份提交全量归档 | 按 `submission_id` 幂等去重；源码抓取失败不阻断元数据记录 |
| `_load_subscriptions()` | 加载订阅配置 | 合并 `crawler/subscriptions/` 目录下所有 `.json`（按 `link` 去重），按 `platform` + `enabled` 过滤 |
| `_mark_submissions_complete()` | 标记提交抓取完整 | 仅在完整结束时调用；`finish()` 据此决定是否推进 `last-update.json` |
| `finish()` | 收尾 | 关闭驱动；**仅当** `_mark_submissions_complete()` 被调用过才更新 `last-update.json`（避免抓取不完整时静默漏提交）；**contests-only 模式始终不推进**（增量由任务B负责） |

其他基础设施：

- **浏览器**：`undetected_chromedriver`，无头模式；GitHub Actions 上使用 `CHROME_BINARY` / `CHROMEDRIVER_PATH` 环境变量，本地使用 `crawler/chrome-linux64` 与 `crawler/chromedriver-linux64`。
- **日志**：`log()` 写平台日志（`crawler/platforms/<platform>/log.json`），`important`/`error`/`fatal` 同时写全局日志（`crawler/global.log.json`）；`fatal` 抛出异常终止。
- **HTML→Markdown**：`_convert_html_to_markdown()` 调用 **pandoc**（HDU/NowCoder 题目），随后 `_clean_pandoc_markdown()` 清理 KaTeX 标记、数学公式与多余空行。
- **时间**：`beijing = timezone(timedelta(hours=8))`，所有时间解析与写入统一北京时间。
- **语言识别**：`_get_extension_name()` 把提交语言映射为文件扩展名（cpp/go/java/kt/pas/py/rs/c/d/txt）。

### 4.2 平台子类

| 模块 | 平台 | 登录方式 | 备注 |
|------|------|----------|------|
| `crawler/platforms/qoj/qoj.py` | QOJ (qoj.ac) | 用户名/密码（`QOJ_USERNAME`/`QOJ_PASSWORD`） | 题目 PDF 下载或打印；**订阅驱动**（只抓订阅链接） |
| `crawler/platforms/hdu/hdu.py` | HDU | 用户名/密码（`HDU_USERNAME`/`HDU_PASSWORD`） | HTML→Markdown 题目；**订阅驱动**；**已停用** |
| `crawler/platforms/nowcoder/nowcoder.py` | NowCoder | 昵称 + Cookie（`NOWCODER_USERNAME` / `NOWCODER_COOKIE_*`） | HTML→Markdown 题目；**订阅驱动**；**已停用** |

### 4.3 订阅模型与两个任务

统一订阅配置存放在 `crawler/subscriptions/` 目录（开发分支 gitignore，用户维护；模板见 `crawler/subscriptions/subscriptions.example.json`）。目录下每个 `*.json` 文件都是一份订阅列表，**文件名随意**（可按平台 / 系列 / 月份等分组管理），运行时只识别 `.json` 文件，按文件名排序合并，重复 `link` 去重（保留先出现的条目）；**模板文件 `*.example.json` 跳过**（示例比赛不是真实订阅）。单个文件格式：

```json
[
  { "platform": "qoj", "link": "https://qoj.ac/contest/123", "comments": "可选备注", "enabled": true },
  { "platform": "qoj", "link": "https://qoj.ac/contest/456", "end_time": "2026-08-15T23:00:00+08:00" }
]
```

订阅条目 `enabled` 为**订阅级**开关（**缺省视为启用**，默认开启；设 `false` 暂时不抓该场，保留条目不删除）。

订阅条目可选填 `end_time`（比赛结束时间，**北京时间 ISO 格式**），仅**部署方式二（自建服务器）**的闹钟机制读取（见 4.6），方式一（GitHub Actions 轮询）不读取该字段、保持原样：

| end_time 取值 | 含义 | 行为 |
|---------------|------|------|
| 不填 | 历史比赛 | `sync` 立即爬取归档，**不生成报告** |
| 未来时间 | 未来比赛 | `sync` 写入闹钟表，到点由 `fire` 爬取 + **立即生成报告**（精确到分钟） |
| 已过时间 | 过期比赛（如闹钟失败后补漏） | `sync` 立即爬取 + **生成报告** |

三个平台均以订阅为唯一来源：QOJ 比赛列表按订阅链接过滤，HDU/NowCoder 遍历订阅链接解析比赛信息。

**平台启用/禁用**：`crawler/config.json` 中每个平台条目可用 `enabled` 字段控制（**缺省 `false` 视为禁用**）。`scheduled_task.py` 启动时读取该文件过滤平台，显式 `enabled: true` 的平台才会被执行（任务A/任务B 均生效）；配置文件缺失 / 解析失败时全部平台禁用。模板见 `crawler/config.example.json`（开发分支 gitignore，deploy 分支跟踪）。注意：这里的 `enabled` 是**平台级**开关，与订阅条目的**订阅级** `enabled` 是两套独立配置。

`config.json` 只存放**非敏感**的运行参数（`enabled` / `base_url` / `min_wait_time` / `max_wait_time`）；**登录凭据一律走环境变量**（`.env` / CI secrets）：QOJ/HDU 用户名密码、NowCoder Cookie 由各平台 `login()` 从环境变量读取，见 `.env.example`。

```json
{
  "qoj":    { "enabled": true,  "base_url": "https://qoj.ac", "min_wait_time": 0.5, "max_wait_time": 2 },
  "hdu":    { "enabled": false, "base_url": "https://acm.hdu.edu.cn", "min_wait_time": 0, "max_wait_time": 0.5 },
  "nowcoder": { "enabled": false, "base_url": "https://ac.nowcoder.com", "min_wait_time": 0, "max_wait_time": 0.5 }
}
```

`crawler/scripts/scheduled_task.py` 提供三个入口（**只负责爬虫**，复盘报告由 `crawler/scripts/report.py` 独立生成，见 4.4）：

| 任务 | 命令 | 调度 | 职责 |
|------|------|------|------|
| 任务A（完整，默认） | `python3 crawler/scripts/scheduled_task.py` | 手动/临时 | 抓订阅的已开始比赛 → 增量同步提交 |
| 任务A（`--contests-only`） | `python3 crawler/scripts/scheduled_task.py --contests-only` | `crawler-scheduled.yml`，每 30 分钟 | 只检查订阅有没有触发（新建比赛）；有新建才回填这些比赛的提交记录，无新建则完全不碰提交，保持轻量。**不推进 `last-update.json`**——已有比赛的增量由任务B负责 |
| 任务A（`--contests-only --links`） | `python3 crawler/scripts/scheduled_task.py --contests-only --links "https://qoj.ac/contest/123"` | 服务器闹钟 `fire` / `sync` 内部调用 | 只抓**指定订阅链接**的比赛（其余订阅跳过），语义与 `--contests-only` 一致；与 `--submissions-only` 互斥，`--links` 无值报错 |
| 任务B（提交周期同步） | `python3 crawler/scripts/scheduled_task.py --submissions-only` | `crawler.yml`，每天 20:00 UTC | 对所有已开始/进行中的比赛做增量提交抓取 |

`--contests-only` 实现要点：`scheduled_task.run_platform` 在 `fetch_contests` 后检查 `crawler._new_contests`，为空直接结束；非空则置 `crawler._contests_only = True` 再 `fetch_submissions()`——HDU/NowCoder 的 `fetch_submissions_get_submissions` 只遍历本次新建的比赛（其余订阅跳过），QOJ 以最早新比赛开始时间为提交截止（`_register_submission(deadline=...)`），`BaseCrawler.finish()` 在 contests-only 模式始终不推进 `last-update.json`。

两个爬虫工作流在爬虫步骤之后均追加独立的报告生成步骤（`python3 crawler/scripts/report.py --from-crawl`），与爬虫解耦：爬虫失败不生成报告，报告失败不阻断提交/部署。`--from-crawl` 只对本次新建的比赛生成（读取 `crawler/new-contests.json`，见 4.4），任务B（无新建比赛）自然跳过。

### 4.4 复盘报告（`crawler/scripts/report.py`，独立总结脚本）

- 独立于爬虫入口运行，四种模式：
  - `python3 crawler/scripts/report.py --from-crawl`（**推荐**）：只对本次爬取新建的比赛生成（读 `crawler/new-contests.json`，任务A 结束时写入；无文件/空列表时直接跳过）
  - `python3 crawler/scripts/report.py --from-crawl --links "link1,link2"`：在 `--from-crawl` 基础上只对**指定订阅链接**的比赛生成（闹钟 `sync` 同批爬取同时含历史与过期比赛时，只对过期比赛生成报告）
  - `python3 crawler/scripts/report.py`：扫描所有已结束且缺 `review.md` 的比赛补生成
  - `python3 crawler/scripts/report.py <contest_folder>`：只生成指定比赛
- 任务A（`crawler/scripts/scheduled_task.py`，含 `--contests-only`）结束时把本次新建的比赛文件夹写入 `crawler/new-contests.json`（临时状态文件，gitignore；无新建比赛时删除旧文件），`report.py` / `qq_share.py` 以 `--from-crawl` 读取；读写逻辑统一在共享模块 `crawler/scripts/new_contests.py`。
- 读取 `contest.json`、`submissions.json`、`problems/<letter>/submissions/<id>.<ext>`，**不做分析性预处理**，原始提交序列（含代码与时间戳）直接送 DeepSeek（OpenAI 兼容接口，`deepseek-chat`）。
- 输出 `contests/<date> <name>/review.md`；`review.md` 已存在即跳过（幂等）。
- API key 从环境变量 `DEEPSEEK_API_KEY` 读取（CI secret）。
- 只对 `end_time` 已过且有提交数据的比赛生成报告。
- QQ 群分享简化版（`qq-share.txt`）由独立模块 `crawler/scripts/qq_share.py` 生成，完整报告生成后自动串联，也支持 `--from-crawl` 单独补生成（`python3 crawler/scripts/qq_share.py --from-crawl` 或 `python3 crawler/scripts/report.py --from-crawl --qq-only`）。

### 4.5 增量抓取逻辑

- `last-update.json` 记录各平台最后更新时间；`_register_submission()` 遇到早于该时间的提交即停止。
- 未匹配到已归档竞赛的提交先进入 `crawler/platforms/<platform>/staged-submissions.json`，下次运行时优先尝试回填（如新竞赛已归档）。
- 若题目已 AC 且旧提交非 AC，则不会用旧提交覆盖；新 AC 提交会更新 `solve_time`（取最早的 AC 时间）。
- 提交抓取**完整性校验**：只有遍历完所有分页或到达 last-update 才标记完整；`finish()` 仅在此情况下推进 `last-update.json`，否则下次重跑，避免静默漏提交。
- **contests-only（`--contests-only`）不回填已有比赛、不推进 `last-update.json`**：新建比赛的提交以该场 `start_time` 为截止全量回填（`_deadline_for`，与任务A首次抓取一致），已有比赛的增量由每日任务B推进。若推进，会跳过已有比赛在两次任务之间的新提交，造成漏抓。

**deploy 分支状态跟踪约定**：开发分支的 `.gitignore` 忽略爬虫数据与状态文件（`contests/`、`last-update.json`、`crawler/platforms/*/contests.json`、`crawler/platforms/*/staged-submissions.json`、`config.json`、`crawler/subscriptions/`）；仓库另提交一份 **`.gitignore.deploy`**，其中这些文件均纳入版本控制。CI 工作流在提交前执行 `cp .gitignore.deploy .gitignore` 后再 `git add`，因此 deploy 分支会自然跟踪竞赛数据与增量状态（增量同步跨运行生效），也支持手动上传代码。仅 crawler 状态变化时同样提交（消息不带 `[contests-changed]` 标记，不触发部署）。日志、chromedriver 二进制、遗留 `input_*.json`、`new-contests.json`（临时报告列表，见 4.4）**与 `alarms.json`（闹钟表，见 4.6）**始终不提交。

### 4.6 服务器闹钟机制（部署方式二专用，`crawler/scripts/alarm.py`）

**背景**：方式二（自建服务器）早期沿用方式一的轮询思路——cron 每 30 分钟扫描所有订阅、爬平台比较时间判断是否到点，精确度差且每次都要跑全量扫描。改用**闹钟表 + 每分钟检查**：订阅条目填 `end_time`（见 4.3），`sync` 时把未来比赛写入闹钟表，cron 每分钟检查到点即触发。

**闹钟表 `crawler/alarms.json`**：运行时状态文件，`alarm.py` 统一读写，`.gitignore` 与 `.gitignore.deploy` 均忽略、**不提交**（服务器本地状态，不属于 deploy 分支数据）。每条记录含 `link` / `platform` / `end_time` / `fire_at` / `status` / `attempts` / `updated_at`。

**状态模型**（每条闹钟一个 `status` 字段，替代早期的 `fired`/`failed` 布尔组合）：

| status | 含义 | 处理 |
|--------|------|------|
| `planned` | 未来比赛：`fire_at = end_time`，等待 fire | `due` 只查这个状态；到点由 fire 爬取 + 报告 |
| `pending` | sync 已安排立即处理（HISTORY / EXPIRED 待爬取，`fire_at` 为空） | fire 忽略；爬取成功后置 `archived`，失败置 `failed` |
| `archived` | 已处理完（历史/过期已归档、未来已触发） | sync 跳过、fire 忽略 |
| `failed` | 爬取失败 | fire 忽略；下次 sync **重试一次**：成功 → `archived`，失败保持 `failed` |

**与订阅文件保持同步**：`plan` 检测订阅里修改 `end_time`（信息变更 → 重新安排，archived 也会被重新激活）；订阅里删除条目 → 剪除对应闹钟（含 archived 历史）。`failed` 条目**永不重置**，只有重试成功（`mark --archived`）才改变状态。

**子命令**：

| 子命令 | 职责 |
|--------|------|
| `alarm.py plan` | 扫描订阅：输出 `HISTORY` / `EXPIRED` / `RETRY` 链接，写未来闹钟（`planned`）。archived 且信息未变跳过；failed 且信息未变输出 `RETRY`（**保持 failed 不重置**）；其余（新建/信息变更/pending 遗留/planned 已到点）按 `end_time` 重新分类。有 failed 重试时输出 `WARNING` 提示用户。剪除订阅中已删除条目的闹钟 |
| `alarm.py due` | 输出 `status == planned` 且 `fire_at` 已到、未失败的闹钟；pending/archived/failed 一律忽略；无则空输出（cron 判断） |
| `alarm.py mark <link> --archived` | 标记已处理完（attempts 清零，保留历史，plan 下次跳过） |
| `alarm.py mark <link> --failed` | attempts +1、置 `failed`（fire 不再重试；下次 sync 重试一次） |
| `alarm.py list` | 列出全部闹钟（含状态与失败计数） |

旧格式闹钟表（`fired`/`failed` 布尔）在 `_load_alarms` 读入时自动迁移：`fired → archived`、`failed → failed`、其余 → `planned`。

**server-task.sh 集成**：

- `cmd_sync`（`crawler/server-task.sh sync`）：①`plan` 分类订阅并写闹钟表，有 `RETRY`/`WARNING` 时记录日志告知用户；②爬取 HISTORY + EXPIRED + RETRY 比赛（`--contests-only --links "..."`）；③对 EXPIRED 与 RETRY 生成报告（`report.py --from-crawl --links "..."`，幂等）；④全部 `mark --archived`。即：历史比赛立即爬取归档不生成报告，过期比赛立即爬取 + 报告，失败比赛重试一次（成功 → archived，失败保持 failed）。**爬取失败时本次涉及的全部链接 `mark --failed`**（下次 sync 重试），不再静默退出。
- `cmd_fire`（`crawler/server-task.sh fire`）：先 `due`，**无到期闹钟安静退出**（不产生提交）；有则走与 `sync` 相同的完整流程（爬取 → 报告 → mark archived）。**爬取失败 `mark --failed`**——fire 只查 planned，失败后不再自动重试，靠下次手动 `sync` 重试一次（成功 → archived，失败保持 failed）。
- `install` 的 cron 改为：闹钟检查 `* * * * *`（fire）+ 任务B 每日；`status` 展示闹钟表。
- **不做自动兜底**：failed 不会自动重扫，需手动 `sync` 重试（用户确认的取舍，避免低频全量重扫的复杂度）。

**只对方式二生效**：方式一（GitHub Actions 轮询）不读取 `end_time` 字段，`alarm.py` 与 `sync`/`fire` 仅服务器使用。

## 5. 关键技术决策记录（ADR）

| 决策 | 理由 | 影响 |
|------|------|------|
| 前端静态导出 + 构建时读 `fs` | 内容变更频率低，纯静态站点部署简单（GitHub Pages） | 每次数据变更需重新构建；页面仅反映构建时数据 |
| 元数据使用 JSON 侧车文件（`<file>.json`） | 与文件实体一一对应，便于爬虫增量写入与前端合并读取 | `getFileMetadata()` 统一合并逻辑 |
| 时间统一北京时间 | 竞赛平台均为中国时区，避免时区转换歧义 | 前端 `parseToBeijingTime` 与爬虫 `_convert_to_beijing_time` 双端一致 |
| URL 双端常量（`BASE_URL`/`PREFIX_URL`） | 区分页面路由前缀与资源前缀，适配 GitHub Pages `basePath` | 修改部署路径只需改 `global.ts` 与 `next.config.ts`。**内部路由一律用根相对路径 + `next/link`**（`joinUrl("/", ...)` / `href="/"`，由 Link 自动添加一次 `basePath`）；`PREFIX_URL` 仅用于 `<a>` 外部/下载类链接（不经过 Link，手动拼接一次前缀）。二者混用会因 `next/link` 的 `addBasePath()` 叠加产生 `/Training-Archive/Training-Archive/...` 双前缀 404（2026-08-10 已修复） |
| 爬虫数据不纳入 `main` 分支 | 避免大量二进制/JSON 数据污染主分支；`deploy` 分支专管数据与部署 | 主分支本地开发需自行准备 `contests/` |
| 爬虫状态文件在 `deploy` 分支纳入版本控制 | 增量同步依赖跨运行持久的状态（last-update / 平台索引 / staged） | 开发分支 `.gitignore` 忽略；CI 用 `.gitignore.deploy` 覆盖后正常 `git add` |
| 订阅模型 `crawler/subscriptions/` 目录 | 统一管理预订比赛，取代单文件 `subscriptions.json` 与各平台零散的 `input_contests.json`；多文件按 `link` 去重合并，文件名随意便于分组 | 三平台均为订阅驱动；订阅目录开发分支 gitignore，deploy 分支纳入版本控制 |
| 全量提交采集（`submissions/` + `submissions.json`） | 复盘报告需要完整提交序列（含每份源码） | 每次提交都抓源码，初始同步耗时更长 |
| LLM 复盘报告（DeepSeek） | 每场一份 `review.md`，原始提交序列直接送 LLM，不做预处理 | 依赖 `DEEPSEEK_API_KEY`；存在即跳过（幂等） |
| 爬虫调度恢复为定时（两个任务） | 任务A（查订阅/预订抓取，每 30 分钟 `--contests-only`，有新建才回填其提交）与任务B（提交周期同步，每天）分离；复盘报告由 `report.py` 独立运行 | `crawler-scheduled.yml` + `crawler.yml`，`concurrency` 串行防冲突 |
| 服务器闹钟机制（方式二专用） | 方式二（自建服务器）用闹钟表 + cron 每分钟检查替代 30 分钟轮询：订阅填 `end_time`，`sync` 写闹钟、`fire` 到点触发，精确到分钟；只对方式二生效，方式一（Actions 轮询）不读取 `end_time` | `crawler/scripts/alarm.py` + `crawler/alarms.json`（gitignore，不提交）；`server-task.sh` 新增 `sync`/`fire`，`install` 的 cron 改「闹钟每分钟 + 任务B 每日」；状态模型 `planned/pending/archived/failed`，fire 失败即 failed、不再自动重试（下次 sync 重试一次，成功 → archived，失败保持 failed），不做事后自动兜底 |
| 平台启用/禁用由 `config.json` 控制 | HDU/NowCoder 平台结构变动/登录不稳定，默认停用；QOJ 为主力 | 每个平台条目 `enabled` 字段（缺省 false 视为禁用），`scheduled_task.py` 启动时过滤；代码保留，未删除 |

## 6. 已知限制

- `readme` 页面为占位（可考虑渲染仓库根 README）。
- 前端无自动化测试；目前仅靠 `pnpm lint` 与人工验收。
- HDU/NowCoder 爬虫默认停用（`config.json` 中 `enabled: false`），当前只有 QOJ 在运行；可通过改 `enabled` 随时启用。
- `report.py` 提示词有长度上限（`MAX_PROMPT_CHARS`），超限时旧提交源码会被省略（元数据保留）。
- Dashboard 复盘报告区与复盘时间轴页依赖 `review.md`（`crawler/scripts/report.py` 独立生成）；`submissions.json` 为空时统计与绿点图显示零值。

## 7. 相关文档

- `README.md`：快速开始与目录结构
- `docs/CHANGELOG.md`：变更日志
- `docs/notes.md`：开发笔记与待办
- `docs/agent-workflow.md`：Agent 开发工作流
