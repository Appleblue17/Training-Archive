# 开发笔记

> 高时效文档：记录当前进度、待办事项与注意事项，随开发频繁更新。

---

## 最近更新

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

- 平台启用/禁用由 `crawler/config.json` 的 `enabled` 字段控制（缺省 `true`）；模板见 `crawler/config.example.json`（gitignored 的 `config.json` 不会被提交，deploy 分支的 `config.json` 需自行添加 `enabled` 字段才会真正禁用对应平台）。
- 登录凭据一律走环境变量（`.env` / CI secrets），`config.json` 只放非敏感运行参数（`enabled` / `base_url` / `min_wait_time` / `max_wait_time`）。QOJ/HDU 用户名密码、NowCoder Cookie 由各平台 `login()` 读取，见 `.env.example`。
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
