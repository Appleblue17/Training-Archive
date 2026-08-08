# 开发笔记

> 高时效文档：记录当前进度、待办事项与注意事项，随开发频繁更新。

---

## 最近更新

- 2026-08-08：完成 v0.2.0 规划讨论，记录至 `docs/roadmap.md`（含双版本架构、功能分级、爬虫触发机制、报告生成、账号系统等决策）。选定 UI 库 **shadcn/ui**、图标库 **lucide-react**。
- 2026-08-08：文档体系完善 —— 补充 `docs/CHANGELOG.md`（v0.1.0）、重写 `README.md`、新增 `docs/architecture.md` 与 `docs/notes.md`、更新 `docs/agent-workflow.md`。
- 2026-08-08：v0.2.0 爬虫与 CI 改造完成：前端代码审查修复、订阅模型、全量提交采集、DeepSeek 复盘报告、定时任务 A/B、`.gitignore.deploy` 与双定时工作流、题目标签支持。前端 C 阶段剩余：搜索、Dashboard、复盘时间轴、UI 库迁移、收尾。

## 当前状态

- 主功能（竞赛列表、文件查看、日志页）可用；爬虫改为双任务定时运行（任务 A 每 30 分钟，任务 B 每日），HDU / NowCoder 爬虫停用（代码保留）。
- `contests/` 数据目录为空（git 忽略），本地开发如需查看效果需准备数据或运行爬虫；deploy 分支跟踪数据与增量状态。
- **v0.2.0 开发中**：爬虫/CI 部分完成，前端 C 阶段进行中，详细规划见 `docs/roadmap.md`。

## 待办

### v0.2.0（开发中，见 `docs/roadmap.md`）

- [x] 代码质量/健壮性修复清单（`docs/roadmap.md` §8）
- [x] 爬虫数据层：订阅模型、任务 A/B、全量提交采集、报告生成模块
- [x] CI 工作流：`.gitignore.deploy`、`crawler-scheduled.yml`（任务 A）、`crawler.yml`（任务 B）、`deploy.yml` 触发扩展
- [x] 题目标签支持（problem.json `tags` + 前端徽章渲染）
- [ ] 搜索（`search-index.json` + 搜索页）
- [ ] Dashboard（最近动态 + 统计 + contribution 绿点图 + 复盘报告区）
- [ ] 复盘时间轴页
- [ ] UI 库迁移到 shadcn/ui；图标库迁移到 lucide-react
- [ ] 响应式与可访问性改造
- [ ] 验收：`pnpm lint` + `pnpm build` 全通过

### 常规

- [ ] `dashboard` 页面实现（当前占位，v0.2.0 范畴）
- [ ] `readme` 页面实现（当前占位，可考虑渲染仓库根 README）
- [ ] 清理 `platform-badge.tsx` 冗余条件（fallback 分支误用 `platform === "codeforces"`）
- [ ] 评估 `contest-table.tsx` 固定 17 列题号（A–Q）的横向自适应方案
- [ ] 评估是否引入前端测试（当前仅 lint）
- [ ] 文档工作流中提及的 `clang-format` 等模板残留是否彻底清理

## 注意事项

### 已选定的技术栈

- **UI 库**：shadcn/ui（Radix + Tailwind），新增组件通过其 CLI 或手工复制引入。
- **图标库**：lucide-react；新增图标统一从 `lucide-react` 引入，**不再使用 `react-icons`**（存量迁移见 `docs/roadmap.md`）。

### 构建与运行

- 生产构建要求本地存在 `contests/`；`deploy.yml` 会先复制 `contests/` → `public/contests/` 再 `pnpm build`。
- `NODE_ENV=production` 时 `next.config.ts` 启用 `output: "export"` 与 `basePath: "/Training-Archive"`；本地开发（`pnpm dev`）使用根路径。
- `pnpm` 使用 npmmirror 源（`.npmrc`），如网络受限可临时切换回官方源。

### 爬虫

- HDU / NowCoder 的 HTML→Markdown 依赖 **pandoc**（CI 中安装 3.6.3；本地需自行安装）。
- 爬虫驱动：CI 用 `browser-actions/setup-chrome`（Chrome 114）并通过环境变量传入路径；本地需自行准备 `crawler/chrome-linux` 与 `crawler/chromedriver_linux64`。
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
python3 crawler/qoj/qoj.py                # 运行 QOJ 爬虫
```
