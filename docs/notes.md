# 开发笔记

> 高时效文档：记录当前进度、待办事项与注意事项，随开发频繁更新。

---

## 最近更新

- 2026-08-12：**服务器闹钟机制状态模型重构**——闹钟表从 `fired`/`failed`/`attempts` 布尔组合改为显式 `status`：`planned`（未来等 fire）/ `pending`（sync 待立即处理）/ `archived`（已处理完，fire 忽略）/ `failed`（爬取失败，fire 忽略）。修复三个问题：①旧逻辑 `plan` 对未来条目无条件重置 `failed`/`attempts`，fire 失败记录被一次 sync 清零；②旧 EXPIRED 条目 `fire_at=end_time`（已过）会被 `due` 误判为到点重跑；③状态靠布尔组合推断、可读性差。新语义：`plan` 对 failed 条目**永不重置**，输出 `RETRY` 类别由 sync 重试一次（成功 → `archived`，失败保持 `failed`），且输出 `WARNING` 提示用户；`due` 只查 `planned` 且 `fire_at` 已到；sync/fire 爬取失败即 `mark --failed`（不再静默退出）；订阅修改 `end_time` → 重新安排（archived 也重新激活），订阅删除 → 剪除闹钟。旧表在 `_load_alarms` 读入时自动迁移（fired→archived、failed→failed、其余→planned）。验证：24 项状态流转测试全过；bash -n / py_compile 通过。
- 2026-08-11：**服务器闹钟机制（方式二专用）**——订阅条目可选填 `end_time`（比赛结束时间，ISO 格式），取代「cron 定时扫描订阅、爬平台比较时间」的轮询：不填 = 历史比赛（`sync` 立即爬取归档，不生成报告）；未来 = 写闹钟到点爬取 + 立即生成报告（精确到分钟）；已过 = `sync` 立即爬取 + 报告（闹钟失败后补漏）。新增 `crawler/scripts/alarm.py`（plan/due/mark/list）与闹钟表 `crawler/alarms.json`（gitignore，两处 .gitignore 均忽略）；`server-task.sh` 新增 `sync`/`fire`，`install` 的 cron 改为「闹钟检查每分钟 + 任务B 每日」，`status` 展示闹钟；`scheduled_task.py` 新增 `--links`（只抓指定订阅，复用 contests-only 语义），`report.py --from-crawl` 新增 `--links` 过滤（同批爬取只对过期比赛生成报告）。方式一（Actions 轮询）不读取 end_time、保持原样。失败重试最多 3 次后标记 failed，靠下次手动 sync 补（2026-08-12 重构后改为：失败即 failed、下次 sync 重试一次）。验证：alarm.py 全子命令 + 幂等/剪除/failed 计数、--links 解析互斥、report --links 过滤均通过；bash -n / py_compile 通过。
- 2026-08-11：`deploy.yml` 标记检查误触发——`check_contests` 用 `git log -1 --pretty=%B`（subject + body 完整信息）`grep '[contests-changed]'`，修复 quotepath 的那条提交 **body 里描述了 "[contests-changed] marker"** 字样，grep 匹配成功误判为应部署（实测无标记提交触发了 deploy job）。修复：改 `--pretty=%s` 只取 subject 第一行，真标记提交（subject `[auto] [contests-changed] ...`）仍匹配，body 提及不再误触发。验证：修复提交旧逻辑匹配 1、新逻辑 0；真标记提交匹配 1。推送后端到端确认：无标记提交的 Deploy run 仅跑 check_contests、deploy job 被跳过。
- 2026-08-11：修复自动提交 `[contests-changed]` 标记对**中文比赛名失效**的 bug——git 默认 `core.quotepath=true` 把非 ASCII 路径输出为带引号+八进制转义（`"contests/2026\u2026..."`），`server-task.sh` 与两个爬虫工作流的 `git diff --cached --name-only | grep '^contests/'` 匹配失败，改了 `contests/` 却走了 `[auto] Update crawler state` 分支（实测新增 411 个中文路径文件却无标记、未触发部署）。修复：三处判断统一改 `git -c core.quotepath=false diff --cached --name-only`（命令级生效不改全局配置）。验证：对误判提交旧逻辑匹配 0 个、新逻辑匹配 411 个。deploy 分支同步修复，服务器下次 cron 运行 `git pull` 自动拉到修复后的脚本。
- 2026-08-10：deploy 分支跟踪爬虫日志——`.gitignore.deploy` 不再忽略 `crawler/global.log.json` 与 `crawler/platforms/*/log.json`（`clean-log.py` 已控制大小：global 保留 20 条、平台保留 50 条），使云端 `/log` 页面可查看日志（此前日志被忽略、deploy 分支必然缺失，页面仅显示占位）。开发分支 `.gitignore` 仍忽略日志，本地日志不提交。CI 每次运行后提交日志（无 contests 变更时走 `[auto] Update crawler state` 不带部署标记，不触发部署）。
- 2026-08-10：`/log` 页面缺失日志文件时显示友好占位而非报错——日志是运行时产物（`crawler/global.log.json` 与 `crawler/platforms/*/log.json` 被 gitignore 不提交版本控制），deploy 分支 / 全新 clone 读取路径必然不存在，此前页面显示 `Error reading file: ENOENT...`（空内容在 log 类型还显示 "Invalid log format"）。`log/page.tsx` 读取失败改为返回空串，`log-page.tsx` `DisplayBox` 空内容渲染"暂无日志文件"占位（含生成路径提示）；本地跑过爬虫后日志存在即正常显示。lint + build 通过。
- 2026-08-10：静态导出空数据兜底——全部 5 个动态路由（`/[page]`、`/review/[contest]`、`/view/contests/[contest]/[file]`、`/view/contests/[contest]/problems/[problem]/[file]`、`/view/contests/[contest]/problems/[problem]/submissions/[file]`）在 `contests/` 无数据或不存在时 `generateStaticParams` 返回空数组 / `readdirSync` 抛错，`output: export` 判定动态路由无法构建而 build 失败（deploy 旧数据无 `submissions.json`/`review.md`/提交历史，或全新 clone 空 `contests/` 均触发）。统一改为：`contests/` 不存在时判空；无匹配数据时返回占位参数 `~no-data~`，页面内部渲染"暂无数据"提示；`/[page]` 兜底输出 `page1`（HomeView 渲染空列表）。数据生成后占位页自然消失。
- 2026-08-10：爬虫目录重组——`crawler/` 按职责分文件夹：平台爬虫入 `crawler/platforms/{qoj,hdu,nowcoder}/`（公共逻辑 `crawler/platforms/base.py`），DeepSeek 客户端入 `crawler/llm/`（未来可扩展多平台 API），模板入 `crawler/prompts/`，可执行脚本入 `crawler/scripts/`（`scheduled_task.py` / `report.py` / `qq_share.py` / `clean-log.py` / `new_contests.py`）；导入统一改完全限定（`from crawler.platforms.base import ...`），平台状态文件路径改为 `crawler/platforms/<platform>/{log,contests,staged-submissions}.json`（前端 log/ 页面 `global.ts` 同步）；`server-task.sh` 与 CI 工作流命令改为 `crawler/scripts/...`。各子目录补 `__init__.py` 成包。验证：ast/导入测试 + contests-only 单测全过。
- 2026-08-10：任务A 新增 **`--contests-only`** 模式——高频触发（`crawler-scheduled.yml` 每 30 分钟 / `server-task.sh run a`）只检查订阅有没有触发（新建比赛），有新建才以该场 `start_time` 为截止回填其提交，无新建则完全不碰提交；**不推进 `last-update.json`**（已有比赛增量由每日任务B负责，推进会漏抓两次任务之间的新提交）。实现：`run_platform` 改传 mode（full/contests/submissions），`crawler._contests_only = True` 后 HDU/NowCoder 的 `fetch_submissions_get_submissions` 只遍历本次新建比赛、QOJ 以最早新比赛开始时间为提交截止，`BaseCrawler.finish()` 在 contests-only 始终不推进 last-update。完整任务A（`scheduled_task.py`）保留为手动/临时模式。
- 2026-08-10：订阅配置改为目录式管理——`crawler/subscriptions/` 目录取代单文件 `crawler/subscriptions.json`，每个 `.json` 文件一份订阅列表（文件名随意，可按平台/系列/月份分组），运行时只识别 `.json` 文件、按文件名排序合并、重复 `link` 去重（保留先出现的条目）、**模板文件 `*.example.json` 跳过**；`BaseCrawler._load_subscriptions` 重写为目录扫描。旧文件数据已迁移至 `crawler/subscriptions/hdu.json` 并删除单文件。开发分支 `.gitignore` 用 `crawler/subscriptions/*` 忽略目录内容 + `!crawler/subscriptions/subscriptions.example.json` 例外保留模板（**不能忽略目录本身**，否则 `!` 规则失效）；deploy 分支 `.gitignore.deploy` 无需改动，目录默认被跟踪。模板路径 `crawler/subscriptions/subscriptions.example.json`。
- 2026-08-10：报告生成改为 `--from-crawl` 模式——任务A 结束把本次新建的比赛写入 `crawler/new-contests.json`（临时文件，gitignore），`report.py` / `qq_share.py` 加 `--from-crawl` 只对这些比赛生成 review / qq-share（幂等跳过），不再每次全量扫描；共享模块 `crawler/new_contests.py` 统一读写；工作流与 `server-task.sh` 的 report 步骤改用 `--from-crawl`（任务B 无新建比赛时自然跳过）。注意：订阅的比赛若在**进行中**被首次抓取（文件夹已建但未结束），当次不会生成报告，且后续运行不再新建该文件夹——`--from-crawl` 会漏掉这种比赛，需手动 `python3 crawler/report.py <folder>` 或全量扫描补生成。
- 2026-08-10：方式二一键管理脚本 `crawler/server-task.sh`——复刻 Action 流程（pull→爬取→报告→清理→push），子命令 run/install/uninstall/status/log；`deploy.yml` 加 `push: branches: [deploy]` 触发（仅 `[contests-changed]` 提交部署）；gitignore 忽略 `crawler/server-task.log`。README / roadmap 同步。
- 2026-08-10：部署方式确认并文档化——静态版两种部署方式（①GitHub Actions 开启 `schedule` 定时；②自建服务器 cron 跑同一套脚本，关闭 schedule、产物 push 回 deploy 分支需自行接入部署触发），动态版 v0.3.x 单列；写入 `docs/roadmap.md` §1.1 与 README「部署方式」。
- 2026-08-10：Contribution 收尾——卡片 `w-fit max-w-full` 收缩到内容宽度（原被 `w-full` 容器拉伸）；Y 轴星期标签补全 7 天（Sun–Sat，列宽 30px）。lint + 全量 build 通过。
- 2026-08-10：Dashboard 统计与 Contribution 改版——①AC 卡片替换为 Total Code（`getTotalCodeBytes` 统计 submissions/ 源码字节总和）；②绿点图布局改 flex 按周分列修复横向 gap 虚大（原 grid 隐式列被 stretch 拉伸），新增 X 轴月份 / Y 轴星期标签；③悬浮自定义 tooltip（scrollLeft 校正）。lint + 全量 build 通过。
- 2026-08-10：`/readme` 页样式与文件查看器统一——直接复用 `FileViewerMarkdown` 组件（深色容器 `bg-[#0d1117]` + 边框 + 右上角复制按钮 + `p-12` 可滚动区），移除 `Card` 包裹；README 缺失时同风格占位提示。lint + 全量 build 通过。
- 2026-08-10：链接与时间显示统一收尾——①新增历史提交查看路由 `/view/.../submissions/[file]`（`FileViewerPage` 加 `subdir`），修复复盘时间轴 Source 链接 404；②view 链接缺 `/contests/` 段的 404 修复（review/dashboard/search 四处补段）；③搜索/最近完成入口链接统一指向题面页（`statement.md` 优先），代码页以 `Code` 图标单独提供，Dashboard Recently Solved 展示代码长度（样式同首页）；④时间格式统一 `YYYY/MM/DD HH:MM`（`formatDateTime`，24h 北京时间）；⑤内容查看类链接统一新标签页；⑥lucide 图标尺寸统一。lint + 全量 build（清 `.next`/`out` 后）通过；注意 Next canary 增量构建偶发 `/_document`/`/_not-found` 报错，`rm -rf .next out` 后重跑即恢复。
- 2026-08-10：前端链接双前缀修复 + Dashboard 复盘入口改版——内部路由统一改 `next/link` **根相对路径**（`joinUrl("/", ...)` / `href="/"`），由 Link 自动添加一次 `basePath`，修复线上 `/Training-Archive/Training-Archive/...` 404（`next/link` 的 `addBasePath()` 与手动 `PREFIX_URL` 拼接叠加导致）；外部/下载类链接保留 `<a>` + `PREFIX_URL`。Dashboard 移除独立 "Contest Reviews" 板块，Review 入口移入最近比赛列表（有 `review.md` 才显示），平台分布改 `x{count}`；`public/search-index.json` 重新生成（清除已删比赛的陈旧条目）。lint + build 全通过，`out/` 无双前缀残留。
- 2026-08-10：复盘模板改为 gitignore 本地编辑 + 提交 `.example.md` 副本——`crawler/prompt.template.md` / `crawler/qq-share.template.md` 移出版本控制（本地保留可自由调整），新增 `crawler/prompt.template.example.md` / `crawler/qq-share.template.example.md` 可提交副本；`report.py` 的 `DEFAULT_TEMPLATE` 与 `qq_share.py` 的 `DEFAULT_QQ_SHARE_TEMPLATE` 兜底内容同步为与 `.example.md` 完全一致（CI 等无模板文件环境行为一致）。
- 2026-08-09：爬虫脚本模块化拆分——DeepSeek 客户端抽离为 `crawler/deepseek_client.py`（`call_deepseek` + 代理归一化 + `.env` 加载，report/qq_share 共用）；QQ 群分享简化版抽离为 `crawler/qq_share.py`（独立运行 `python3 crawler/qq_share.py [folder]`）；`report.py` 仅保留完整报告生成、串联转调 qq_share，`--qq-only` 兼容入口保留。
- 2026-08-09：复盘报告新增 **QQ 群分享简化版**——`generate_qq_share` 基于 `review.md` 再调一次 DeepSeek（更高 temperature），生成轻松幽默、带 emoji 的纯文本总结，落盘 `contests/<date> <name>/qq-share.txt`；模板 `crawler/qq-share.template.md`（git 跟踪，占位符 `{{review}}`，内置 fallback）。生成完整报告后自动串联生成简化版（幂等，`qq-share.txt` 存在则跳过）；`--qq-only` 可单独补生成（含扫描模式）。**QQ 集成尚未接入，仅完成内容生成**。
- 2026-08-09：复盘报告 prompt 模板化——`crawler/prompt.template.md`（git 跟踪，可直接编辑），占位符 `{{contest_info}}` / `{{problems}}` / `{{submissions}}`；`{{problems}}` 现含**完整题面**（`statement.md`，丢弃重复的首行标题）与 solved 状态，提交源码按剩余预算（`MAX_PROMPT_CHARS - 固定内容`）截断，题面优先保留；`report.py` 内置同名 fallback 模板（模板文件缺失时兜底）。
- 2026-08-09：HDU / NowCoder 提交记录补抓 `problem_id` 字段（此前只存 `problem_link`）。该字段在 HDU/NowCoder 存的是**题目 ID**（status 页题目列只显示 ID，如 "1006"，不是题目名），QOJ 从 `#123. Name` 同时提取 `problem_id` 与 `problem_name`（真实名）。三平台提交的题目匹配统一为三级：`problem_link` → `problem_id` → `problem_name`（`base.py` 与 `report.py` 的 `letter_for` 均支持）。
- 2026-08-09：爬虫修复补订场景——HDU/NowCoder 补订已完成比赛时提交一条都抓不到（早于全局 last-update 即停止），改为首次抓取的新比赛以 `start_time` 为截止全量回填；三平台统一"早于比赛开始时间的提交直接丢弃"（跨赛季历史提交不再进 staged）；`contests.json` 条目补充 `start_time`/`end_time` 并对旧条目按比赛文件夹回填。
- 2026-08-08：完成 v0.2.0 规划讨论，记录至 `docs/roadmap.md`（含双版本架构、功能分级、爬虫触发机制、报告生成、账号系统等决策）。选定 UI 库 **shadcn/ui**、图标库 **lucide-react**。
- 2026-08-08：文档体系完善 —— 补充 `docs/CHANGELOG.md`（v0.1.0）、重写 `README.md`、新增 `docs/architecture.md` 与 `docs/notes.md`、更新 `docs/agent-workflow.md`。
- 2026-08-08：v0.2.0 爬虫与 CI 改造完成：前端代码审查修复、订阅模型、全量提交采集、DeepSeek 复盘报告、定时任务 A/B、`.gitignore.deploy` 与双定时工作流、题目标签支持。前端 C 阶段剩余：搜索、Dashboard、复盘时间轴、UI 库迁移、收尾。
- 2026-08-08：前端 C 阶段完成：搜索（构建时 `search-index.json` + `/search` 页）、Dashboard、复盘时间轴页、UI 库迁移（shadcn/ui + lucide-react 落地）。C6 收尾完成：全局错误边界 `error.tsx`、自定义 `not-found.tsx`、全局 `loading.tsx` 骨架屏、无障碍复查。待 D 验收（readme 页仍占位）。
- 2026-08-08：`/readme` 页实现（构建时渲染仓库根 `README.md`，替换占位页）。v0.2.0 全部占位页清零。
- 2026-08-08：验收修复 4 项——根路径 `/` 404（抽 `home-view.tsx` + 根 `page.tsx`）；竞赛列表横向滚动条（容器 `overflow-hidden` 恢复 v0.1.0 右侧溢出裁切）；面包屑 Home 高亮；Markdown 样式缺失（katex/github-markdown CSS 移入根布局全局加载，review/readme/dashboard 渲染统一）。
- 2026-08-08：竞赛列表布局按用户要求恢复 v0.1.0 样式——移除 overflow 包裹（此前 overflow-hidden 导致 >L 题目列被裁、展开栏截断），表格直接渲染 `w-[calc(100%+144px)] table-fixed`，题目列延伸框右侧可见；题号列保底 17 列；移除 body overflow-x hidden。
- 2026-08-08：爬虫验收修复——跨赛季复用题目导致历史提交被误归档（E 题负时间）：`_update_submission_status` 增加提交时间窗口校验（早于 start_time 1 天以上 → 不匹配落入 staged）；前端 `getInContestTime` 早于开始时间的提交显示日期、时长负数取 0。Log 页面本地无日志文件属预期（gitignore + 未跑爬虫），路径/格式与爬虫一致未变。

## 当前状态

- 主功能（竞赛列表、文件查看、日志页）可用；爬虫双任务工作流已建（方式一 Actions：任务 A 每 30 分钟、任务 B 每日；方式二服务器：闹钟检查每分钟 + 任务 B 每日），**定时尚未启用**（未实测通过前手动触发验证），HDU / NowCoder 爬虫默认停用（由 `crawler/config.json` 的 `enabled` 字段控制，可改回 `true` 启用）。
- 方式二**闹钟机制已实现**（`crawler/scripts/alarm.py` + `crawler/server-task.sh sync/fire`）：订阅条目可选填 `end_time`，未来比赛 `sync` 写闹钟表 `crawler/alarms.json`（gitignore）、cron 每分钟 `fire` 到点爬取 + 立即生成报告；不填 = 历史比赛立即爬不生成报告；已过 = 过期比赛立即爬 + 报告。状态模型：`planned` / `pending` / `archived` / `failed`，`due` 只查 `planned`，failed 由下次 `sync` 重试一次（成功 → archived，失败保持 failed）。详见「最近更新」与 `docs/architecture.md` §4.6。
- `contests/` 数据目录为空（git 忽略），本地开发如需查看效果需准备数据或运行爬虫；deploy 分支跟踪数据与增量状态。
- **v0.2.1 开发中**：v0.2.0 发布后的修复/增强分支（deploy 标记检查、动态路由占位、quotepath 中文路径、闹钟机制等），**未完成、未创建 PR**，详细规划见 `docs/roadmap.md`。

## 待办

### v0.2.1（开发中，见 `docs/roadmap.md`）

- [x] v0.2.0 发布（含 §8 清单、爬虫数据层、前端 C 阶段全部落地）
- [x] `deploy.yml` 标记检查误触发修复（`--pretty=%s` 只取 subject）
- [x] 动态路由空数据兜底（占位参数 `~no-data~`）
- [x] quotepath 中文路径修复（`git -c core.quotepath=false` 三处统一）
- [x] 服务器闹钟机制（方式二专用）：`alarm.py`（plan/due/mark/list）+ `server-task.sh sync/fire` + `scheduled_task.py --links` + `report.py --from-crawl --links`
- [ ] 方式二服务器端到端实测（`install` cron + `fire` 真实比赛触发 + 部署链路）

### 常规

- [ ] `dashboard` 页面实现（已实现于 C3，此条可忽略）
- [x] `readme` 页面实现（构建时渲染仓库根 `README.md`）
- [ ] 清理 `platform-badge.tsx` 冗余条件（已修复于 §8，此条可忽略）
- [ ] 评估 `contest-table.tsx` 固定 17 列题号（已修复为动态自适应于 §8，此条可忽略）
- [ ] 评估是否引入前端测试（当前仅 lint）
- [x] `clang-format` 等模板残留清理确认（2026-08-08：仓库内无残留，关闭）

## 注意事项

### 已选定的技术栈

- **UI 库**：shadcn/ui（Radix + Tailwind），新增组件通过其 CLI 或手工复制引入。
- **图标库**：lucide-react；新增图标统一从 `lucide-react` 引入，**不再使用 `react-icons`**（存量迁移见 `docs/roadmap.md`）。

### 构建与运行

- 生产构建要求本地存在 `contests/`；`deploy.yml` 会先复制 `contests/` → `public/contests/` 再 `pnpm build`。
- `NODE_ENV=production` 时 `next.config.ts` 启用 `output: "export"` 与 `basePath: "/Training-Archive"`；本地开发（`pnpm dev`）使用根路径。
- `pnpm` 使用 npmmirror 源（`.npmrc`），如网络受限可临时切换回官方源。

### 爬虫

- 平台启用/禁用由 `crawler/config.json` 的 `enabled` 字段控制（**缺省 `false` 视为禁用**，配置文件缺失/解析失败时全部平台禁用）；模板见 `crawler/config.example.json`（gitignored 的 `config.json` 不会被提交，deploy 分支的 `config.json` 需显式 `enabled: true` 才会启用对应平台）。
- 订阅条目（`crawler/subscriptions/` 目录下各 `.json` 文件）的 `enabled` 为**订阅级**开关，**缺省视为启用**（与 `config.json` 平台级缺省禁用不同）。运行时只识别目录下的 `.json` 文件（文件名随意，可按平台/系列分组），按文件名排序合并、重复 `link` 去重（保留先出现条目）；单文件格式与模板 `crawler/subscriptions/subscriptions.example.json` 一致。
- **闹钟机制（方式二专用）**：订阅条目可选填 `end_time`（比赛结束时间，北京时间 ISO），由 `crawler/scripts/alarm.py` 读写闹钟表 `crawler/alarms.json`（gitignore，**不提交**，仅服务器本地状态）。状态模型 `planned`（未来等 fire）/ `pending`（sync 待立即处理）/ `archived`（已处理完，fire 忽略）/ `failed`（爬取失败，fire 忽略）。`server-task.sh sync` 先 `plan` 分类：不填 = 历史比赛立即爬取归档不生成报告；已过 = 过期比赛立即爬取 + 报告（闹钟失败后补漏场景）；未来 = 写闹钟表；**failed = 输出 `RETRY` 重试一次**（`plan` 输出 `WARNING` 提示用户）。cron 每分钟 `fire`：`due` 无到期闹钟**安静退出**（不产生提交），有则爬取（`--contests-only --links`）+ 报告（`report.py --from-crawl --links`）+ `mark --archived`；**爬取失败 `mark --failed`**（fire 只查 planned，失败后不再自动重试，下次手动 `sync` 重试一次：成功 → `archived`，失败保持 `failed`），**不做自动兜底**。`due` 只查 `planned` 且 `fire_at` 已到，pending/archived/failed 一律忽略。订阅修改 `end_time` → 重新安排（archived 也重新激活），订阅删除 → 剪除闹钟。方式一（Actions 轮询）不读取 `end_time`、保持原样。注意：`--links` 与 `--submissions-only` 互斥、无值报错；`--links` 只抓指定订阅，语义与 `--contests-only` 一致（有新建才回填其提交、不推进 last-update）。
- 登录凭据一律走环境变量（`.env` / CI secrets），`config.json` 只放非敏感运行参数（`enabled` / `base_url` / `min_wait_time` / `max_wait_time`）。**本地运行爬虫/报告脚本会自动加载仓库根 `.env`**（`crawler/scripts/scheduled_task.py` / `crawler/scripts/report.py` 顶部 `load_dotenv()`，不覆盖已有环境变量；CI 无 `.env` 静默跳过）。QOJ/HDU 用户名密码由 `login()` 读取；NowCoder 需 `NOWCODER_USERNAME`（昵称，登录态校验）+ `NOWCODER_COOKIE_NOWCODERUID` / `NOWCODER_COOKIE_T`（登录 Cookie），见 `.env.example`。
- 提交抓取截止：非首次运行按全局 `last-update.json` 增量（`_register_submission(deadline=None)`）；**首次抓取的新比赛**（本次运行 `fetch_contests` 新建文件夹，如补订已完成比赛）以该比赛 `start_time` 为截止**全量回填**（`_deadline_for`），否则 HDU/NowCoder 的 status 页第一条提交就早于全局 last-update 而被跳过、一场都抓不到。QOJ 提交走全局用户时间线，无 per-contest 概念，补订旧比赛需手动重置 `crawler/last-update.json` 该平台时间戳触发全量重抓（50 页上限内）。
- **`--contests-only` 模式**（高频触发专用）：只检查订阅有没有触发，有新建比赛才回填其提交（截止 = 该场 `start_time`），无新建完全不碰提交。**不推进 `last-update.json`**——已有比赛的增量由每日任务B负责；若在 contests-only 推进，会跳过已有比赛在两次任务之间的新提交，造成漏抓。任务A 完整模式（`crawler/scripts/scheduled_task.py`）保留为手动/临时场景。注意：若某场新建比赛的**提交回填失败**（如超时），其文件夹已存在，后续 contests-only 运行不会把它当作"新建"而跳过回填（与任务A 同样的既有限制），需手动处理（重置该平台 last-update 触发全量重抓，或跑完整任务A）。
- 早于比赛开始时间的提交**统一直接丢弃**（三平台）：`_update_submission_status` 从 link/name 候选中选"start_time 最晚且不晚于提交时间"的比赛归档，早于所有匹配比赛开始的提交（跨赛季复用同一道题的历史提交）返回 `DISCARD` 丢弃、不进 staged；staged 中此类旧提交下次运行同样被清除。`contests.json` 条目含 `start_time`/`end_time`，旧条目由 `_load_contests_with_times()` 按比赛文件夹回填。
- HDU / NowCoder 的 HTML→Markdown 依赖 **pandoc**（CI 中安装 3.6.3；本地需自行安装）。
- 爬虫驱动：CI 用 `browser-actions/setup-chrome`（Chrome 114）并通过环境变量传入路径；本地需自行准备 `crawler/chrome-linux64` 与 `crawler/chromedriver-linux64`。
- 凭据通过环境变量注入（见 `crawler.yml` 中 `secrets.*`），本地调试需自行设置对应环境变量。
- `_get_extension_name()` 语言识别为启发式映射，遇到未识别语言会 fallback 为 `.txt`。

### 前端

- Markdown 渲染在服务端完成（`file-viewer-markdown-wrapper.tsx`），HTML 通过 `dangerouslySetInnerHTML` 注入，依赖 `rehype-sanitize` 做安全过滤。
- 数学公式：`$$\n...\n$$` 在 wrapper 中改写后再走 KaTeX 流水线；修改渲染管线时注意保持该预处理。

## 命令速查

```bash
pnpm install        # 安装前端依赖
pnpm dev            # 开发模式
pnpm build          # 生产构建（NODE_ENV=production 时导出 out/）
pnpm lint           # ESLint 检查

pip install -r crawler/requirements.txt   # 爬虫依赖
python3 crawler/scripts/scheduled_task.py                # 任务A（完整）：抓订阅比赛 + 全量增量提交
python3 crawler/scripts/scheduled_task.py --contests-only     # 任务A（轻量）：只查订阅/新建比赛，有新建才回填其提交
python3 crawler/scripts/scheduled_task.py --contests-only --links "https://qoj.ac/contest/123"  # 只抓指定订阅链接（闹钟 fire/sync 内部使用）
python3 crawler/scripts/scheduled_task.py --submissions-only  # 任务B：每日增量同步提交
python3 crawler/scripts/report.py --from-crawl           # 复盘报告：只对本次爬取新建的比赛生成
python3 crawler/scripts/report.py --from-crawl --links "https://qoj.ac/contest/123"  # 只对指定链接生成（与 --links 爬取搭配）
python3 crawler/scripts/report.py                        # 补生成：扫描所有缺报告的已结束比赛

python3 crawler/scripts/alarm.py plan              # 扫描订阅：分类 HISTORY/EXPIRED/RETRY，写未来闹钟并剪除已删订阅（有 failed 重试时输出 WARNING）
python3 crawler/scripts/alarm.py due               # 列出到点的 planned 闹钟（pending/archived/failed 忽略；无则空输出）
python3 crawler/scripts/alarm.py mark <link> --archived  # 标记已处理完（attempts 清零）
python3 crawler/scripts/alarm.py mark <link> --failed    # 标记失败（attempts+1，置 failed，下次 sync 重试）
python3 crawler/scripts/alarm.py list              # 列出全部闹钟（含状态与失败计数）

crawler/server-task.sh run [a|b]   # 一键运行（方式二）
crawler/server-task.sh sync        # 手动同步订阅：历史/过期立即爬，未来写闹钟表
crawler/server-task.sh fire        # 闹钟检查：到点爬取 + 报告（cron 每分钟；无到期安静退出）
crawler/server-task.sh install     # 安装 cron（闹钟每分钟 + 任务B 每日）
crawler/server-task.sh status      # 查看 cron / 闹钟 / git / 日志
```
