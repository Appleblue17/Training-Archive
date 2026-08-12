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

- **爬虫子系统**：定时抓取竞赛、题目、提交与代码，写入 `contests/` 目录和各类日志。入口 `crawler/scripts/scheduled_task.py` 提供三种模式（默认 / `--contests-only` / `--submissions-only`）；复盘报告由独立脚本 `crawler/scripts/report.py` 生成。
- **前端子系统**：Next.js 静态导出。构建时通过 `fs` 读取 `contests/` 目录与 JSON 元数据，生成竞赛列表、题目详情、文件查看与复盘页面。
- **CI/CD**：`crawler-scheduled.yml`（`--contests-only`）与 `crawler.yml`（`--submissions-only`）在 `deploy` 分支上运行爬虫并提交数据；`deploy.yml` 检测到数据变更后构建并发布到 GitHub Pages。方式二（自建服务器）由 `crawler/server-task.sh` 复刻同样的流程，产物 push 回 `deploy` 分支触发部署。

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
| `(main)/page.tsx` + `(main)/(home)/[page]/page.tsx` | 竞赛列表（服务端取数 + 分页，每页 20 条），与根路径共用 `home-view.tsx` |
| `(main)/(home)/[page]/contest-table.tsx` | 竞赛表格（客户端）：可展开行、题目状态、悬停元数据面板 |
| `(main)/search/page.tsx` + `search-client.tsx` | 搜索页（服务端读构建时索引，客户端过滤） |
| `(main)/dashboard/page.tsx` + `dashboard-client.tsx` | 数据看板（统计卡片、绿点图、最近动态、复盘报告） |
| `(main)/review/[contest]/page.tsx` + `review-timeline.tsx` | 复盘时间轴页：提交序列 + LLM 报告 |
| `(main)/log/page.tsx` + `log-page.tsx` | 日志页：各平台日志与 staged submissions |
| `(main)/readme/page.tsx` | README 页（构建时渲染仓库根 README） |
| `view/contests/[contest]/[file]/page.tsx` | 竞赛级文件查看页 |
| `view/contests/[contest]/problems/[problem]/[file]/page.tsx` | 题目级文件查看页 |
| `view/contests/[contest]/problems/[problem]/submissions/[file]/page.tsx` | 题目历史提交查看页 |

### 3.2 关键模块

| 模块 | 职责 |
|------|------|
| `src/lib/types.ts` | 数据类型：`FileMetadataType` / `CodeFileType` / `ProblemInfoType` / `ContestInfoType` / `SearchIndexEntryType` |
| `src/lib/global.ts` | 全局配置：`BASE_URL` / `PREFIX_URL` / `REPO_URL`、`allowedExtensions`、`logFileList`、`ITEMS_PER_PAGE` |
| `src/lib/contests-data.ts` | 服务端数据读取（仅服务端 import）：`getContests` / `getAllSubmissions` / `getReviews` / `safeParseJson` |
| `scripts/generate-search-index.mjs` | 构建时扫描 `contests/` 生成 `public/search-index.json`（问题级索引） |
| `src/utils/get-file-metadata.ts` | 读取文件元数据，合并 `<file>.json` 侧车文件 |
| `src/utils/format.ts` | 格式化工具：`formatKey` / `formatSize` / `formatDate` / `formatDateTime`（`YYYY/MM/DD HH:MM`，24h 北京时间） |
| `src/utils/url.ts` | 轻量 URL 拼接 `joinUrl`（客户端组件替代 `path.join`） |
| `src/utils/render-markdown.ts` | 服务端 Markdown→HTML（unified 流水线，与文件查看器共用；复盘报告渲染） |
| `src/components/metadata-display.tsx` | 元数据面板 |
| `src/components/platform-badge.tsx` | 平台徽章（qoj / hdu / nowcoder / codeforces） |
| `src/components/ui/` | 基础 UI 组件（shadcn/ui 风格）：`button` / `card` / `badge` / `input`；`Card` 支持 `asChild` |
| `src/lib/utils.ts` | `cn()`：tailwind-merge + clsx 合并 className |

### 3.3 文件查看器（`file-viewer/`）

按扩展名分发：

- `file-viewer.tsx`：入口，按 `allowedExtensions` 分发到 PDF / Markdown / 源码 / 不支持类型（提供下载）。
- `file-viewer-page.tsx`：竞赛级 / 题目级 / 题目历史提交查看页的公共渲染组件，支持 `subdir` 拼接到题目目录路径。
- `file-viewer-pdf.tsx`：PDF 渲染（react-pdf）。
- `file-viewer-markdown-wrapper.tsx`：**服务端**调用共享 `render-markdown.ts` 的 unified 流水线（remark-parse → remark-math → remark-gfm → remark-img-links → remark-rehype → rehype-sanitize → rehype-highlight → rehype-katex → rehype-format → rehype-stringify）。
- `file-viewer-markdown.tsx`：**客户端**渲染 HTML（`dangerouslySetInnerHTML`）并提供复制按钮。
- `file-viewer-source.tsx`：**客户端**源码高亮（react-syntax-highlighter）并提供复制按钮。

> 数学公式预处理：`$$\n...\n$$` 在 wrapper 中被临时改写为 `$$$$\n...\n$$$$` 以适配 KaTeX 流水线（见 `file-viewer-markdown-wrapper.tsx` 的 `mathRegex`）。

### 3.4 静态生成与部署

- 所有页面通过 `generateStaticParams` + 构建时 `fs` 扫描 `contests/` 生成静态路由；`contests/` 不存在或无可匹配数据时返回占位参数，页面渲染"暂无数据"。
- 生产构建（`NODE_ENV=production`）时 `next.config.ts` 启用 `output: "export"`、`basePath: "/Training-Archive"`；`BASE_URL` / `PREFIX_URL` 据此切换（见 `src/lib/global.ts`）。
- 搜索索引：`pnpm build` 先运行 `scripts/generate-search-index.mjs` 生成 `public/search-index.json`，搜索页在构建时读取并传给客户端组件过滤（方案 A：构建索引 + 前端过滤；动态版 v0.3.0 改服务端 API + DB）。
- `deploy.yml` 先将 `contests/` 复制到 `public/contests/`，再执行 `pnpm build`，最后由 `actions-gh-pages` 发布 `out/`。
- 主分支（`main`）不含 `contests/` 数据；实际爬取与部署都在 `deploy` 分支进行。

### 3.5 UI 组件与图标

- 基础组件采用 shadcn/ui 风格（自行维护 `src/components/ui/`，基于 `class-variance-authority` + `tailwind-merge` + `@radix-ui/react-slot`），依赖 `src/lib/utils.ts` 的 `cn()`。
- 图标统一使用 **lucide-react**（替代 react-icons；lucide 已移除品牌图标，品牌链接用 `ExternalLink` 等通用图标）。

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
| `_update_submission_status()` | 提交落盘 | 按 `problem_link`/`problem_id`/`problem_name` 匹配竞赛题目，全量归档到 `submissions.json` + `submissions/<id>.<ext>`，并写入 `code.<ext>` 与 `problem.json`；匹配不到则进 staged submissions |
| `_archive_submission()` | 单份提交全量归档 | 按 `submission_id` 幂等去重；源码抓取失败不阻断元数据记录 |
| `_load_subscriptions()` | 加载订阅配置 | 合并 `crawler/subscriptions/` 目录下所有 `.json`（按 `link` 去重），按 `platform` + `enabled` 过滤 |
| `_mark_submissions_complete()` | 标记提交抓取完整 | 仅在完整结束时调用；`finish()` 据此决定是否推进 `last-update.json` |
| `finish()` | 收尾 | 关闭驱动；**仅当** `_mark_submissions_complete()` 被调用过才更新 `last-update.json`；**contests-only 模式始终不推进** |

其他基础设施：

- **浏览器**：`undetected_chromedriver`，无头模式；CI 用 `CHROME_BINARY` / `CHROMEDRIVER_PATH` 环境变量，本地用 `crawler/chrome-linux64` 与 `crawler/chromedriver-linux64`。
- **日志**：`log()` 写平台日志（`crawler/platforms/<platform>/log.json`），`important`/`error`/`fatal` 同时写全局日志（`crawler/global.log.json`）；`fatal` 抛出异常终止。
- **HTML→Markdown**：`_convert_html_to_markdown()` 调用 **pandoc**（HDU/NowCoder 题目），随后 `_clean_pandoc_markdown()` 清理 KaTeX 标记、数学公式与多余空行。
- **时间**：`beijing = timezone(timedelta(hours=8))`，所有时间解析与写入统一北京时间。
- **语言识别**：`_get_extension_name()` 把提交语言映射为文件扩展名（cpp/go/java/kt/pas/py/rs/c/d/txt）。

### 4.2 平台子类

| 模块 | 平台 | 登录方式 | 备注 |
|------|------|----------|------|
| `crawler/platforms/qoj/qoj.py` | QOJ (qoj.ac) | 用户名/密码（`QOJ_USERNAME`/`QOJ_PASSWORD`） | 题目 PDF 下载或打印；**订阅驱动** |
| `crawler/platforms/hdu/hdu.py` | HDU | 用户名/密码（`HDU_USERNAME`/`HDU_PASSWORD`） | HTML→Markdown 题目；**订阅驱动**；**已停用** |
| `crawler/platforms/nowcoder/nowcoder.py` | NowCoder | 昵称 + Cookie（`NOWCODER_USERNAME` / `NOWCODER_COOKIE_*`） | HTML→Markdown 题目；**订阅驱动**；**已停用** |

### 4.3 订阅模型与爬虫模式

统一订阅配置存放在 `crawler/subscriptions/` 目录（模板 `crawler/subscriptions/subscriptions.example.json`）。目录下每个 `*.json` 文件都是一份订阅列表（文件名随意，按文件名排序合并，重复 `link` 去重，模板文件 `*.example.json` 跳过）。单个文件格式：

```json
[
  { "platform": "qoj", "link": "https://qoj.ac/contest/123", "comments": "可选备注", "enabled": true },
  { "platform": "qoj", "link": "https://qoj.ac/contest/456", "end_time": "2026-08-15T23:00:00+08:00" }
]
```

订阅条目 `enabled` 为**订阅级**开关（缺省视为启用）；可选填 `end_time`（比赛结束时间，北京时间 ISO），**仅部署方式二（自建服务器）的闹钟机制读取**，方式一（Actions 轮询）不读取该字段。三平台均以订阅为唯一来源。

**平台启用/禁用**：`crawler/config.json` 中每个平台条目用 `enabled` 字段控制（缺省 `false` 视为禁用），`scheduled_task.py` 启动时读取过滤平台；与订阅级 `enabled` 是两套独立配置。`config.json` 只存放**非敏感**运行参数（`enabled` / `base_url` / `min_wait_time` / `max_wait_time` / `scheduled`）；登录凭据一律走环境变量（`.env` / CI secrets）。

```json
{
  "scheduled": { "fire": "*/5 * * * *", "sync": "0 */3 * * *", "incremental": "0 4 * * *" },
  "qoj":    { "enabled": true,  "base_url": "https://qoj.ac", "min_wait_time": 0.5, "max_wait_time": 2 },
  "hdu":    { "enabled": false, "base_url": "https://acm.hdu.edu.cn", "min_wait_time": 0, "max_wait_time": 0.5 },
  "nowcoder": { "enabled": false, "base_url": "https://ac.nowcoder.com", "min_wait_time": 0, "max_wait_time": 0.5 }
}
```

`scheduled` 块为**部署方式二**的 cron 表达式（`server-task.sh install` 读取生成 crontab，见 4.6）：`fire`（闹钟检查）、`sync`（订阅同步）、`incremental`（提交增量）。服务器上可直接修改后重跑 `install` 生效。

`scheduled_task.py` 提供三个入口（**只负责爬虫**，复盘报告由 `report.py` 独立生成，见 4.4）：

| 模式 | 命令 | 调度 | 职责 |
|------|------|------|------|
| 默认（完整） | `python3 crawler/scripts/scheduled_task.py` | 手动/临时 | 抓订阅的已开始比赛 → 增量同步提交 |
| `--contests-only` | `python3 crawler/scripts/scheduled_task.py --contests-only` | 方式一 `crawler-scheduled.yml` 高频触发 | 只检查订阅有没有触发（新建比赛）；有新建才回填这些比赛的提交记录，无新建则完全不碰提交。**不推进 `last-update.json`** |
| `--contests-only --links` | `python3 crawler/scripts/scheduled_task.py --contests-only --links "..."` | 方式二闹钟 `fire` / `sync` 内部调用 | 只抓**指定订阅链接**的比赛，语义与 `--contests-only` 一致；与 `--submissions-only` 互斥 |
| `--submissions-only`（提交增量） | `python3 crawler/scripts/scheduled_task.py --submissions-only` | 方式一 `crawler.yml` 每日 | 对所有已开始/进行中的比赛做增量提交抓取 |

`--contests-only` 实现要点：`run_platform` 在 `fetch_contests` 后检查 `crawler._new_contests`，为空直接结束；非空则置 `crawler._contests_only = True` 再 `fetch_submissions()`——HDU/NowCoder 只遍历本次新建的比赛，QOJ 以最早新比赛开始时间为提交截止，`BaseCrawler.finish()` 在 contests-only 模式始终不推进 `last-update.json`。

两个爬虫工作流在爬虫步骤之后均追加独立的报告生成步骤（`report.py --from-crawl`），与爬虫解耦：爬虫失败不生成报告，报告失败不阻断提交/部署。`--from-crawl` 只对本次新建的比赛生成（读取 `crawler/new-contests.json`，见 4.4），`--submissions-only`（无新建比赛）自然跳过。

### 4.4 复盘报告（`crawler/scripts/report.py`，独立总结脚本）

- 四种模式：
  - `python3 crawler/scripts/report.py --from-crawl`（**推荐**）：只对本次爬取新建的比赛生成（读 `crawler/new-contests.json`，无文件/空列表时跳过）
  - `python3 crawler/scripts/report.py --from-crawl --links "link1,link2"`：只对**指定订阅链接**的比赛生成（同批爬取只对过期比赛生成报告）
  - `python3 crawler/scripts/report.py`：扫描所有已结束且缺 `review.md` 的比赛补生成
  - `python3 crawler/scripts/report.py <contest_folder>`：只生成指定比赛
- 比赛抓取模式结束时把本次新建的比赛文件夹写入 `crawler/new-contests.json`（临时状态文件，gitignore；无新建比赛时删除），`report.py` / `qq_share.py` 以 `--from-crawl` 读取；读写逻辑统一在共享模块 `crawler/scripts/new_contests.py`。
- 读取 `contest.json`、`submissions.json`、`problems/<letter>/submissions/<id>.<ext>`，**不做分析性预处理**，原始提交序列直接送 DeepSeek（OpenAI 兼容接口，`deepseek-chat`，API key 从环境变量 `DEEPSEEK_API_KEY` 读取）。
- 输出 `contests/<date> <name>/review.md`；`review.md` 已存在即跳过（幂等）。只对 `end_time` 已过且有提交数据的比赛生成。
- QQ 群分享简化版（`qq-share.txt`）由 `crawler/scripts/qq_share.py` 生成，完整报告生成后自动串联，也支持 `--from-crawl` 单独补生成。

### 4.5 增量抓取逻辑

- `last-update.json` 记录各平台最后更新时间；`_register_submission()` 遇到早于该时间的提交即停止。
- 未匹配到已归档竞赛的提交先进入 `crawler/platforms/<platform>/staged-submissions.json`，下次运行时优先尝试回填。
- 若题目已 AC 且旧提交非 AC，不会用旧提交覆盖；新 AC 提交更新 `solve_time`（取最早的 AC 时间）。
- 提交抓取**完整性校验**：只有遍历完所有分页或到达 last-update 才标记完整；`finish()` 仅在此情况下推进 `last-update.json`，否则下次重跑，避免静默漏提交。
- **contests-only 不回填已有比赛、不推进 `last-update.json`**：新建比赛的提交以该场 `start_time` 为截止全量回填（`_deadline_for`，与默认模式首次抓取一致），已有比赛的增量由每日 `--submissions-only` 推进。

**deploy 分支状态跟踪约定**：开发分支的 `.gitignore` 忽略爬虫数据与状态文件（`contests/`、`last-update.json`、`crawler/platforms/*/contests.json`、`crawler/platforms/*/staged-submissions.json`、`config.json`、`crawler/subscriptions/`）；仓库另提交一份 **`.gitignore.deploy`**，其中这些文件均纳入版本控制。CI 工作流在提交前执行 `cp .gitignore.deploy .gitignore` 后再 `git add`，因此 deploy 分支会自然跟踪竞赛数据与增量状态（增量同步跨运行生效），也支持手动上传代码。仅 crawler 状态变化时同样提交（消息不带 `[contests-changed]` 标记，不触发部署）。日志、chromedriver 二进制、`new-contests.json`（临时报告列表）与 `alarms.json`（闹钟表，见 4.6）始终不提交。

### 4.6 服务器闹钟机制（部署方式二专用，`crawler/scripts/alarm.py`）

**背景**：方式二早期沿用方式一的轮询思路（cron 定期扫描所有订阅、比较时间判断是否到点），精确度差且每次跑全量扫描。改用**闹钟表 + 定期检查**：订阅条目填 `end_time`（见 4.3），`sync` 时把未来比赛写入闹钟表，cron 按 `config.json` 的 `scheduled` 块间隔检查到点即触发。

**闹钟表 `crawler/alarms.json`**：运行时状态文件，`alarm.py` 统一读写，两个 `.gitignore` 均忽略、**不提交**。每条记录含 `link` / `platform` / `end_time` / `fire_at` / `status` / `attempts` / `updated_at`。

**状态模型**：

| status | 含义 | 处理 |
|--------|------|------|
| `planned` | 未来比赛：`fire_at = end_time`，等待 fire | `due` 只查这个状态；到点由 fire 爬取 + 报告 |
| `pending` | sync 已安排立即处理（HISTORY / EXPIRED 待爬取，`fire_at` 为空） | fire 忽略；爬取成功后置 `archived`，失败置 `failed` |
| `archived` | 已处理完（历史/过期已归档、未来已触发） | sync 跳过、fire 忽略 |
| `failed` | 爬取失败 | fire 忽略；下次 sync **重试一次**：成功 → `archived`，失败保持 `failed` |

**与订阅文件保持同步**：`plan` 检测订阅里修改 `end_time`（信息变更 → 重新安排，archived 也会被重新激活）；订阅里删除条目 → 剪除对应闹钟。`failed` 条目**永不重置**，只有重试成功（`mark --archived`）才改变状态。旧格式闹钟表（`fired`/`failed` 布尔）在 `_load_alarms` 读入时自动迁移：`fired → archived`、`failed → failed`、其余 → `planned`。

**子命令**：

| 子命令 | 职责 |
|--------|------|
| `alarm.py plan` | 扫描订阅：输出 `HISTORY` / `EXPIRED` / `RETRY` 链接，写未来闹钟（`planned`）。archived 且信息未变跳过；failed 且信息未变输出 `RETRY`（保持 failed 不重置）；其余按 `end_time` 重新分类。有 failed 重试时输出 `WARNING`。剪除订阅中已删除条目的闹钟 |
| `alarm.py due` | 输出 `status == planned` 且 `fire_at` 已到的闹钟；pending/archived/failed 一律忽略；无则空输出 |
| `alarm.py mark <link> --archived` | 标记已处理完（attempts 清零，plan 下次跳过） |
| `alarm.py mark <link> --failed` | attempts +1、置 `failed`（fire 不再重试；下次 sync 重试一次） |
| `alarm.py list` | 列出全部闹钟 |

**server-task.sh 集成**：

- `cmd_sync`（`crawler/server-task.sh sync`）：①`plan` 分类订阅并写闹钟表，有 `RETRY`/`WARNING` 时记录日志；②爬取 HISTORY + EXPIRED + RETRY 比赛（`--contests-only --links`）；③对 EXPIRED 与 RETRY 生成报告（`report.py --from-crawl --links`，幂等）；④全部 `mark --archived`。**爬取失败时本次涉及的全部链接 `mark --failed`**（下次 sync 重试），不再静默退出。
- `cmd_fire`（`crawler/server-task.sh fire`）：先 `due`，**无到期闹钟安静退出**；有则走与 `sync` 相同的完整流程（爬取 → 报告 → mark archived）。**爬取失败 `mark --failed`**——fire 只查 planned，失败后不再自动重试，靠下次 sync 重试一次（成功 → `archived`，失败保持 `failed`）。
- `cmd_incremental`（`crawler/server-task.sh incremental`）：对应 `scheduled_task.py --submissions-only`，每日对所有已开始/进行中的比赛做增量提交抓取。
- `install` 从 `crawler/config.json` 的 `scheduled` 块读取 3 条 cron 表达式生成 crontab（缺失/非法时回落到默认值），`status` 展示闹钟表与 crontab。

**只对方式二生效**：方式一（GitHub Actions 轮询）不读取 `end_time` 字段，`alarm.py` 与 `sync`/`fire` 仅服务器使用。

## 5. 关键技术决策记录（ADR）

| 决策 | 理由 | 影响 |
|------|------|------|
| 前端静态导出 + 构建时读 `fs` | 内容变更频率低，纯静态站点部署简单（GitHub Pages） | 每次数据变更需重新构建；页面仅反映构建时数据 |
| 元数据使用 JSON 侧车文件（`<file>.json`） | 与文件实体一一对应，便于爬虫增量写入与前端合并读取 | `getFileMetadata()` 统一合并逻辑 |
| 时间统一北京时间 | 竞赛平台均为中国时区，避免时区转换歧义 | 前端 `parseToBeijingTime` 与爬虫 `_convert_to_beijing_time` 双端一致 |
| URL 双端常量（`BASE_URL`/`PREFIX_URL`） | 区分页面路由前缀与资源前缀，适配 GitHub Pages `basePath` | 内部路由用根相对路径 + `next/link`（Link 自动添加一次 `basePath`）；`PREFIX_URL` 仅用于 `<a>` 外部/下载类链接。二者混用会产生双前缀 404 |
| 爬虫数据不纳入 `main` 分支 | 避免大量二进制/JSON 数据污染主分支；`deploy` 分支专管数据与部署 | 主分支本地开发需自行准备 `contests/` |
| 爬虫状态文件在 `deploy` 分支纳入版本控制 | 增量同步依赖跨运行持久的状态（last-update / 平台索引 / staged） | 开发分支 `.gitignore` 忽略；CI 用 `.gitignore.deploy` 覆盖后正常 `git add` |
| 订阅模型 `crawler/subscriptions/` 目录 | 统一管理预订比赛；多文件按 `link` 去重合并，文件名随意便于分组 | 三平台均为订阅驱动；订阅目录开发分支 gitignore，deploy 分支纳入版本控制 |
| 全量提交采集（`submissions/` + `submissions.json`） | 复盘报告需要完整提交序列（含每份源码） | 每次提交都抓源码，初始同步耗时更长 |
| LLM 复盘报告（DeepSeek） | 每场一份 `review.md`，原始提交序列直接送 LLM，不做预处理 | 依赖 `DEEPSEEK_API_KEY`；存在即跳过（幂等） |
| 爬虫调度恢复为定时（两个模式） | `--contests-only`（查订阅/新建比赛）与 `--submissions-only`（提交增量同步）分离；复盘报告由 `report.py` 独立运行 | `crawler-scheduled.yml` + `crawler.yml`，`concurrency` 串行防冲突 |
| 服务器闹钟机制（方式二专用） | 方式二用闹钟表 + cron 检查替代轮询：订阅填 `end_time`，`sync` 写闹钟、`fire` 到点触发 | `crawler/scripts/alarm.py` + `crawler/alarms.json`（gitignore）；`server-task.sh` 的 `sync`/`fire`/`incremental` 与 `install`（cron 从 `config.json` 的 `scheduled` 块读取）；状态模型 `planned/pending/archived/failed`，fire 失败即 failed、由 sync 重试 |
| 平台启用/禁用由 `config.json` 控制 | HDU/NowCoder 平台结构变动/登录不稳定，默认停用；QOJ 为主力 | 每个平台条目 `enabled` 字段（缺省 false 视为禁用），`scheduled_task.py` 启动时过滤；代码保留，未删除 |

## 6. 已知限制

- 前端无自动化测试；目前仅靠 `pnpm lint` 与人工验收。
- HDU/NowCoder 爬虫默认停用（`config.json` 中 `enabled: false`），当前只有 QOJ 在运行。
- `report.py` 提示词有长度上限（`MAX_PROMPT_CHARS`），超限时旧提交源码会被省略（元数据保留）。
- Dashboard 复盘报告区与复盘时间轴页依赖 `review.md`；`submissions.json` 为空时统计与绿点图显示零值。

## 7. 相关文档

- `README.md`：快速开始与目录结构
- `docs/CHANGELOG.md`：变更日志
- `docs/notes.md`：开发笔记与待办
- `docs/agent-workflow.md`：Agent 开发工作流
