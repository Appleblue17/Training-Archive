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

- **爬虫子系统**：定时（任务A：预订比赛抓取，每 30 分钟；任务B：提交周期同步，每天）抓取竞赛、题目、提交与代码，写入 `contests/` 目录和各类日志；复盘报告由独立脚本 `crawler/report.py` 生成。
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
| `(main)/dashboard/dashboard-client.tsx` | 数据看板展示（客户端）：统计卡片、绿点图、最近动态、报告区 |
| `(main)/review/[contest]/page.tsx` | 复盘时间轴页：按 `submit_time` 展示提交序列 + LLM 报告 |
| `(main)/review/[contest]/review-timeline.tsx` | 提交时间轴（客户端）：状态着色、源码链接 |
| `(main)/log/page.tsx` + `log-page.tsx` | 日志页：按平台展示日志与 staged submissions |
| `(main)/readme/page.tsx` | README 页（占位，未实现） |
| `view/contests/[contest]/[file]/page.tsx` | 竞赛级文件查看页 |
| `view/contests/[contest]/problems/[problem]/[file]/page.tsx` | 题目级文件查看页 |

### 3.2 关键模块

| 模块 | 职责 |
|------|------|
| `src/lib/types.ts` | 数据类型：`FileMetadataType` / `CodeFileType` / `ProblemInfoType` / `ContestInfoType` / `SearchIndexEntryType` |
| `src/lib/global.ts` | 全局配置：`BASE_URL` / `PREFIX_URL` / `REPO_URL`、`allowedExtensions`、`logFileList`、`ITEMS_PER_PAGE` |
| `src/lib/contests-data.ts` | 服务端数据读取（仅服务端 import）：`getContests` / `getAllSubmissions` / `getReviews` / `safeParseJson`；首页与 Dashboard 共用 |
| `scripts/generate-search-index.mjs` | 构建时扫描 `contests/` 生成 `public/search-index.json`（问题级索引：题目/标签/比赛/平台/日期 + 跳转文件） |
| `src/utils/get-file-metadata.ts` | 读取文件元数据，合并 `<file>.json` 侧车文件 |
| `src/utils/format.ts` | 格式化工具：`formatKey` / `formatSize` / `formatDate` |
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

### 4.1 基类 `crawler/base.py`（`BaseCrawler`）

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
| `_load_subscriptions()` | 加载订阅配置 | 按 `platform` + `enabled` 过滤 `crawler/subscriptions.json` |
| `_mark_submissions_complete()` | 标记提交抓取完整 | 仅在完整结束时调用；`finish()` 据此决定是否推进 `last-update.json` |
| `finish()` | 收尾 | 关闭驱动；**仅当** `_mark_submissions_complete()` 被调用过才更新 `last-update.json`（避免抓取不完整时静默漏提交） |

其他基础设施：

- **浏览器**：`undetected_chromedriver`，无头模式；GitHub Actions 上使用 `CHROME_BINARY` / `CHROMEDRIVER_PATH` 环境变量，本地使用 `crawler/chrome-linux64` 与 `crawler/chromedriver-linux64`。
- **日志**：`log()` 写平台日志（`crawler/<platform>/log.json`），`important`/`error`/`fatal` 同时写全局日志（`crawler/global.log.json`）；`fatal` 抛出异常终止。
- **HTML→Markdown**：`_convert_html_to_markdown()` 调用 **pandoc**（HDU/NowCoder 题目），随后 `_clean_pandoc_markdown()` 清理 KaTeX 标记、数学公式与多余空行。
- **时间**：`beijing = timezone(timedelta(hours=8))`，所有时间解析与写入统一北京时间。
- **语言识别**：`_get_extension_name()` 把提交语言映射为文件扩展名（cpp/go/java/kt/pas/py/rs/c/d/txt）。

### 4.2 平台子类

| 模块 | 平台 | 登录方式 | 备注 |
|------|------|----------|------|
| `crawler/qoj/qoj.py` | QOJ (qoj.ac) | 用户名/密码（`QOJ_USERNAME`/`QOJ_PASSWORD`） | 题目 PDF 下载或打印；**订阅驱动**（只抓订阅链接） |
| `crawler/hdu/hdu.py` | HDU | 用户名/密码（`HDU_USERNAME`/`HDU_PASSWORD`） | HTML→Markdown 题目；**订阅驱动**；**已停用** |
| `crawler/nowcoder/nowcoder.py` | NowCoder | Cookie（`NEWCODER_COOKIE_*`） | HTML→Markdown 题目；**订阅驱动**；**已停用** |

### 4.3 订阅模型与两个任务

统一订阅配置 `crawler/subscriptions.json`（gitignore，用户维护；模板见 `crawler/subscriptions.example.json`）：

```json
[
  { "platform": "qoj", "link": "https://qoj.ac/contest/123", "name": "可选备注", "enabled": true }
]
```

三个平台均以订阅为唯一来源：QOJ 比赛列表按订阅链接过滤，HDU/NowCoder 遍历订阅链接解析比赛信息。

**平台启用/禁用**：`crawler/config.json` 中每个平台条目可用 `enabled` 字段控制（缺省 `true` 视为启用）。`scheduled_task.py` 启动时读取该文件过滤平台，显式 `enabled: false` 的平台不会被执行（任务A/任务B 均生效）。模板见 `crawler/config.example.json`（开发分支 gitignore，deploy 分支跟踪）。

`config.json` 只存放**非敏感**的运行参数（`enabled` / `base_url` / `min_wait_time` / `max_wait_time`）；**登录凭据一律走环境变量**（`.env` / CI secrets）：QOJ/HDU 用户名密码、NowCoder Cookie 由各平台 `login()` 从环境变量读取，见 `.env.example`。

```json
{
  "qoj":    { "enabled": true,  "base_url": "https://qoj.ac", "min_wait_time": 0.5, "max_wait_time": 2 },
  "hdu":    { "enabled": false, "base_url": "https://acm.hdu.edu.cn", "min_wait_time": 0, "max_wait_time": 0.5 },
  "nowcoder": { "enabled": false, "base_url": "https://ac.nowcoder.com", "min_wait_time": 0, "max_wait_time": 0.5 }
}
```

`crawler/scheduled_task.py` 提供两个任务入口（**只负责爬虫**，复盘报告由 `crawler/report.py` 独立生成，见 4.4）：

| 任务 | 命令 | 调度 | 职责 |
|------|------|------|------|
| 任务A（预订比赛抓取） | `python3 crawler/scheduled_task.py` | `crawler-scheduled.yml`，每 30 分钟 | 抓订阅的已开始比赛 → 增量同步提交 |
| 任务B（提交周期同步） | `python3 crawler/scheduled_task.py --submissions-only` | `crawler.yml`，每天 20:00 UTC | 对所有已开始/进行中的比赛做增量提交抓取 |

两个爬虫工作流在爬虫步骤之后均追加独立的报告生成步骤（`python3 crawler/report.py`），与爬虫解耦：爬虫失败不生成报告，报告失败不阻断提交/部署。

### 4.4 复盘报告（`crawler/report.py`，独立总结脚本）

- 独立于爬虫入口运行：`python3 crawler/report.py`（扫描所有已结束且缺 `review.md` 的比赛）或 `python3 crawler/report.py <contest_folder>`（只生成指定比赛）。

- 读取 `contest.json`、`submissions.json`、`problems/<letter>/submissions/<id>.<ext>`，**不做分析性预处理**，原始提交序列（含代码与时间戳）直接送 DeepSeek（OpenAI 兼容接口，`deepseek-chat`）。
- 输出 `contests/<date> <name>/review.md`；`review.md` 已存在即跳过（幂等）。
- API key 从环境变量 `DEEPSEEK_API_KEY` 读取（CI secret）。
- 只对 `end_time` 已过且有提交数据的比赛生成报告。

### 4.5 增量抓取逻辑

- `last-update.json` 记录各平台最后更新时间；`_register_submission()` 遇到早于该时间的提交即停止。
- 未匹配到已归档竞赛的提交先进入 `crawler/<platform>/staged-submissions.json`，下次运行时优先尝试回填（如新竞赛已归档）。
- 若题目已 AC 且旧提交非 AC，则不会用旧提交覆盖；新 AC 提交会更新 `solve_time`（取最早的 AC 时间）。
- 提交抓取**完整性校验**：只有遍历完所有分页或到达 last-update 才标记完整；`finish()` 仅在此情况下推进 `last-update.json`，否则下次重跑，避免静默漏提交。

**deploy 分支状态跟踪约定**：开发分支的 `.gitignore` 忽略爬虫数据与状态文件（`contests/`、`last-update.json`、`crawler/*/contests.json`、`crawler/*/staged-submissions.json`、`config.json`、`subscriptions.json`）；仓库另提交一份 **`.gitignore.deploy`**，其中这些文件均纳入版本控制。CI 工作流在提交前执行 `cp .gitignore.deploy .gitignore` 后再 `git add`，因此 deploy 分支会自然跟踪竞赛数据与增量状态（增量同步跨运行生效），也支持手动上传代码。仅 crawler 状态变化时同样提交（消息不带 `[contests-changed]` 标记，不触发部署）。日志、chromedriver 二进制、遗留 `input_*.json` 始终不提交。

## 5. 关键技术决策记录（ADR）

| 决策 | 理由 | 影响 |
|------|------|------|
| 前端静态导出 + 构建时读 `fs` | 内容变更频率低，纯静态站点部署简单（GitHub Pages） | 每次数据变更需重新构建；页面仅反映构建时数据 |
| 元数据使用 JSON 侧车文件（`<file>.json`） | 与文件实体一一对应，便于爬虫增量写入与前端合并读取 | `getFileMetadata()` 统一合并逻辑 |
| 时间统一北京时间 | 竞赛平台均为中国时区，避免时区转换歧义 | 前端 `parseToBeijingTime` 与爬虫 `_convert_to_beijing_time` 双端一致 |
| URL 双端常量（`BASE_URL`/`PREFIX_URL`） | 区分页面路由前缀与资源前缀，适配 GitHub Pages `basePath` | 修改部署路径只需改 `global.ts` 与 `next.config.ts` |
| 爬虫数据不纳入 `main` 分支 | 避免大量二进制/JSON 数据污染主分支；`deploy` 分支专管数据与部署 | 主分支本地开发需自行准备 `contests/` |
| 爬虫状态文件在 `deploy` 分支纳入版本控制 | 增量同步依赖跨运行持久的状态（last-update / 平台索引 / staged） | 开发分支 `.gitignore` 忽略；CI 用 `.gitignore.deploy` 覆盖后正常 `git add` |
| 订阅模型 `subscriptions.json` | 统一管理预订比赛，取代各平台零散的 `input_contests.json` | 三平台均为订阅驱动；订阅文件 gitignore，由用户维护 |
| 全量提交采集（`submissions/` + `submissions.json`） | 复盘报告需要完整提交序列（含每份源码） | 每次提交都抓源码，初始同步耗时更长 |
| LLM 复盘报告（DeepSeek） | 每场一份 `review.md`，原始提交序列直接送 LLM，不做预处理 | 依赖 `DEEPSEEK_API_KEY`；存在即跳过（幂等） |
| 爬虫调度恢复为定时（两个任务） | 任务A（预订抓取，每 30 分钟）与任务B（提交周期同步，每天）分离；复盘报告由 `report.py` 独立运行 | `crawler-scheduled.yml` + `crawler.yml`，`concurrency` 串行防冲突 |
| 平台启用/禁用由 `config.json` 控制 | HDU/NowCoder 平台结构变动/登录不稳定，默认停用；QOJ 为主力 | 每个平台条目 `enabled` 字段（缺省 true），`scheduled_task.py` 启动时过滤；代码保留，未删除 |

## 6. 已知限制

- `readme` 页面为占位（可考虑渲染仓库根 README）。
- 前端无自动化测试；目前仅靠 `pnpm lint` 与人工验收。
- HDU/NowCoder 爬虫默认停用（`config.json` 中 `enabled: false`），当前只有 QOJ 在运行；可通过改 `enabled` 随时启用。
- `report.py` 提示词有长度上限（`MAX_PROMPT_CHARS`），超限时旧提交源码会被省略（元数据保留）。
- Dashboard 复盘报告区与复盘时间轴页依赖 `review.md`（`crawler/report.py` 独立生成）；`submissions.json` 为空时统计与绿点图显示零值。

## 7. 相关文档

- `README.md`：快速开始与目录结构
- `docs/CHANGELOG.md`：变更日志
- `docs/notes.md`：开发笔记与待办
- `docs/agent-workflow.md`：Agent 开发工作流
