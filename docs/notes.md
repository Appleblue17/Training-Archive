# 开发笔记

> 高时效文档：记录当前进度、待办事项与注意事项，随开发频繁更新。

---

## 最近更新

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

- 主功能（竞赛列表、文件查看、日志页）可用；爬虫双任务工作流已建（任务 A 每 30 分钟、任务 B 每日），**定时尚未启用**（未实测通过前手动触发验证），HDU / NowCoder 爬虫默认停用（由 `crawler/config.json` 的 `enabled` 字段控制，可改回 `true` 启用）。
- `contests/` 数据目录为空（git 忽略），本地开发如需查看效果需准备数据或运行爬虫；deploy 分支跟踪数据与增量状态。
- **v0.2.0 开发中**：爬虫/CI 部分完成，前端 C 阶段进行中，详细规划见 `docs/roadmap.md`。

## 待办

### v0.2.0（开发中，见 `docs/roadmap.md`）

- [x] 代码质量/健壮性修复清单（`docs/roadmap.md` §8）
- [x] 爬虫数据层：订阅模型、任务 A/B、全量提交采集、报告生成模块
- [x] CI 工作流：`.gitignore.deploy`、`crawler-scheduled.yml`（任务 A）、`crawler.yml`（任务 B）、`deploy.yml` 触发扩展
- [x] 题目标签支持（problem.json `tags` + 前端徽章渲染）
- [x] 搜索（构建时 `search-index.json` + `/search` 页，关键词 + 标签过滤）
- [x] Dashboard（统计 + 最近动态 + contribution 绿点图 + 复盘报告区，构建时聚合）
- [x] 复盘时间轴页（`/review/[contest]`：提交时间轴 + LLM 报告）
- [x] UI 库迁移到 shadcn/ui；图标库迁移到 lucide-react
- [x] C6 收尾：错误边界（`error.tsx`）、骨架屏（`loading.tsx`）、自定义 404（`not-found.tsx`）、无障碍复查（readme 页仍占位）
- [x] 响应式与可访问性改造（`docs/roadmap.md` §8 已覆盖：布局响应式、表格键盘操作、`aria-label`/`aria-expanded`）
- [x] 验收：`pnpm lint` + `pnpm build` 全通过（2026-08-08，仅 readme 占位页存在已知 img 警告）

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
- 订阅条目（`crawler/subscriptions.json`）的 `enabled` 为**订阅级**开关，**缺省视为启用**（与 `config.json` 平台级缺省禁用不同）。
- 登录凭据一律走环境变量（`.env` / CI secrets），`config.json` 只放非敏感运行参数（`enabled` / `base_url` / `min_wait_time` / `max_wait_time`）。**本地运行爬虫/报告脚本会自动加载仓库根 `.env`**（`scheduled_task.py` / `report.py` 顶部 `load_dotenv()`，不覆盖已有环境变量；CI 无 `.env` 静默跳过）。QOJ/HDU 用户名密码由 `login()` 读取；NowCoder 需 `NOWCODER_USERNAME`（昵称，登录态校验）+ `NOWCODER_COOKIE_NOWCODERUID` / `NOWCODER_COOKIE_T`（登录 Cookie），见 `.env.example`。
- 提交抓取截止：非首次运行按全局 `last-update.json` 增量（`_register_submission(deadline=None)`）；**首次抓取的新比赛**（本次运行 `fetch_contests` 新建文件夹，如补订已完成比赛）以该比赛 `start_time` 为截止**全量回填**（`_deadline_for`），否则 HDU/NowCoder 的 status 页第一条提交就早于全局 last-update 而被跳过、一场都抓不到。QOJ 提交走全局用户时间线，无 per-contest 概念，补订旧比赛需手动重置 `crawler/last-update.json` 该平台时间戳触发全量重抓（50 页上限内）。
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
python3 crawler/scheduled_task.py                # 任务A：抓订阅比赛 + 增量同步提交
python3 crawler/scheduled_task.py --submissions-only  # 任务B：每日增量同步提交
python3 crawler/report.py                        # 复盘报告（独立于爬虫）
```
