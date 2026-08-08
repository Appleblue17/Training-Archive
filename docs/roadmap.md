# 开发规划（Roadmap）

> 本文档记录 v0.2.0 / v0.3.0 的规划讨论结论与路线图。所有内容来自 2026-08-08 与用户的系列讨论。

---

## 1. 总体方向：双版本架构

网站目前是纯静态导出并部署在 GitHub Pages，限制了一些功能。计划分为两个版本，**单一代码库 + 构建开关**，不维护两套前端：

| 版本 | 部署形态 | 适用场景 |
|------|----------|----------|
| **静态版（v0.2.0）** | GitHub Pages（`output: "export"`，现状不变） | 公开只读内容，零运维 |
| **动态版（v0.3.0）** | 服务器 / Docker（同代码库加 API routes 或独立 service） | 账号、个人数据、正式资源保护、实时能力 |

构建开关建议：环境变量（如 `NEXT_PUBLIC_DEPLOY_MODE=static|dynamic`）区分构建模式。数据流上保留「文件为事实来源」：爬虫不变，动态版在服务端把 `contests/` 数据灌入 DB 供 API 查询。

---

## 2. 功能分级：静态版 / 动态版

| 功能 | 静态版 | 动态版 | 存储方案 / 说明 |
|------|:---:|:---:|------|
| 题目标签（队内共享） | ✅ | ✅ | 写入 `problem.json` 的 `tags` 字段，随 git 同步（用户已确认：不区分人、可持久化到文件跨设备同步） |
| 个人收藏 / 稍后再做 | ⚠️ 仅 localStorage 降级 | ✅ | DB 按 user 存储（用户已确认：收藏/稍后再做应区分每个人） |
| 题目搜索 | ✅ | ✅ | 构建时生成 `search-index.json`（标题/比赛/标签/平台/日期），前端过滤 |
| 资源保护 | ⚠️ 仅客户端加密（过渡，非正式） | ✅ | 动态版账号鉴权为正式方案；受保护资源不进公开仓库 |
| Dashboard 统计 / 最近动态 | ✅ | ✅ | 构建时从 `solve_time`/`submit_time` 聚合写 JSON |
| contribution 绿点图 | ✅ | ✅ | 纯 SVG/CSS，按提交/解决时间聚合 |
| 「我的收藏 vs 队内收藏」 | ❌ | ✅ | 依赖账号系统 |
| 账号系统 | ❌ | ✅ | GitHub OAuth + httpOnly session cookie |
| 比赛复盘 + LLM 报告 | ✅（CI 预生成） | ✅（可按需重新生成） | 报告存为 `review.md` 进仓库 / DB |
| 预订比赛 / 触发 | ✅（Actions 模拟一次性任务） | ✅（精确到分钟） | 见 §3 |
| 订阅管理 UI | ❌（编辑 JSON 提交） | ✅（网站内操作） | 动态版加分项 |

---

## 3. 爬虫触发机制：两个独立任务（用户已确认拆分）

**预订比赛 ≠ 周期同步**，两者是独立的机制：

### 任务 A：预订比赛抓取 + 复盘（一次性任务）
- 语义：某场**预订**的比赛结束后 → 抓取整场比赛数据 → 立即生成复盘报告。
- 调度：
  - 动态版：APScheduler / `at` 按 `end_time` 排一次性 job，**精确到分钟**，跑完即删。
  - 静态版（GitHub Actions）：Actions 无原生单次调度，用 **cron 每 15~30 分钟轮询**「到点且未跑过的预订比赛」模拟一次性执行（平台限制，非设计上的轮询）。用户已确认可接受此延迟。
- 幂等：每场比赛记录「已抓取 / 已生成报告」状态标记，重跑只补未完成的。
- 只抓该场次数据，与任务 B 无耦合。

### 任务 B：提交记录周期同步
- 每天一次（cron），对所有已开始/进行中的比赛做**增量**提交抓取。
- 沿用现有 `last-update.json` 增量机制。

### 订阅配置
- 统一 `crawler/subscriptions.json`（含 `link`/`platform`/`enabled`），取代三平台零散的 `input_contests.json`。
- 初期从空模板开始，链接由用户填充。

---

## 4. 数据模型变更（复盘数据源）

### 全量提交采集（用户已确认）
- **不再只保留每题最后一次提交**，需要记录每一份提交：
  - `contests/<date> <name>/submissions.json`：全部提交元数据数组（`submission_id`、`problem`、`status`、`language`、`submit_time`、`time`、`memory`）
  - `problems/<letter>/submissions/<id>.<ext>`：**每一份提交的源码**（只存本队提交，量级小）
- 分页抓取加**完整性校验**：抓不完整标记失败，**不得静默推进 `last-update`**（否则会永久漏掉提交）。

### 报告生成（用户已确认）
- 读取 `submissions.json`，**不做任何预处理**，原始提交序列（含代码与时间戳）直接送 LLM 分析。
- 每场一份报告，输出 `contests/<date> <name>/review.md`。
- LLM：**DeepSeek API**，OpenAI 兼容接口（`base_url=https://api.deepseek.com`，模型 `deepseek-chat`），密钥放 CI secret（静态版）/ 服务器环境变量（动态版）。token 用量很小，不考虑成本。
- 已生成则跳过（`review.md` 存在即跳过），避免重复消耗。

---

## 5. 账号系统（动态版专属）

- **GitHub OAuth + httpOnly session cookie**（可保持登录状态，刷新/换标签页不掉线）。
- **登录 = 队员，不做管理员/队员区分**（用户已确认）；未在 GitHub allowlist 的账号拒绝登录。
- 所有登录用户均可访问受保护资源、收藏、稍后再做。
- 不预留本地账号（用户已确认 GitHub 足够）。

---

## 6. 资源保护决策

- **静态版**：客户端加密（口令派生密钥 PBKDF2 → AES-GCM，`.enc` 文件随仓库发布，浏览器 WebCrypto 解密）只能作为**过渡方案**，无法区分访问者、无法单独吊销；元数据（竞赛名/日期）默认仍公开。
- **动态版（正式）**：账号鉴权，受保护资源**不进公开仓库**。
- **决策：v0.2.0 默认不做资源保护**，放 v0.3.0 动态版正式实现（用户确认与「动态版必须账号系统」一致）。

---

## 7. 前端增强（v0.2.0 静态版）

1. **标签**：`problem.json` 增 `tags`，竞赛列表页与题目页显示标记。
2. **搜索**：构建索引 + 前端过滤（不引搜索库，数据量小；必要时加 Fuse.js）。
3. **Dashboard**：
   - 最近动态（最近比赛、最近完成的题目）
   - 统计信息（总题目数等）
   - contribution 绿点图
   - **复盘报告区：当前报告 + 往期报告列表**（扫描各 `review.md` 渲染/链接，用户已确认）
4. **复盘时间轴页**：按 `submit_time` 展示每次提交序列，附 LLM 报告。
5. **UI 库与图标库**（用户授权先行选定）：
   - **UI 库：shadcn/ui**（基于 Radix + Tailwind，与现有 Tailwind 体系一致，深色主题友好，静态导出兼容，组件可复制引入）。
   - **图标库：lucide-react**，替换现有杂乱的 `react-icons`（Feather/VSCode 混用）。
6. **质量与体验**：评审清单修复（见 §8）+ 响应式 + 可访问性。

---

## 8. 代码评审修复清单（v0.2.0 前置）

### 前端（已在 08c3f721 全部修复）
- [x] `platform-badge.tsx` fallback 分支误用 `platform === "codeforces"`，导致未知平台无背景色
- [x] `contest-table.tsx` 固定 17 列题号（A–Q）与魔法数 `colSpan={19}`
- [x] 竞赛列表未显式排序（依赖 `readdirSync` 顺序）；`page0` 等分页边界脆弱
- [x] 客户端组件 `import path` 依赖 polyfill，统一用 `src/utils/url.ts` 的 `joinUrl`
- [x] `metadata-display.tsx` 纯工具函数抽到 `src/utils/format.ts`
- [x] 两个文件查看页逻辑重复，抽公共组件 `file-viewer-page.tsx`
- [x] `JSON.parse` 无运行时校验（首页 `safeParseJson` 保护）
- [x] `(main)/layout.tsx` 强制 `min-w-[1600px]`，无响应式
- [x] 可访问性：整行可键盘操作（Enter/Space）、题目格 `title`/`aria-label`、表格 `aria-label`

### 爬虫（已在 4253f1b1 修复）
- [x] HDU 时间解析 `%b` 依赖英文 locale，非英文环境抛异常
- [x] 时区约定需明确：naive 时间按北京时间墙钟解释；带时区后缀（`Z`/`+08:00`）的来源应正确转换
- [x] `now = datetime.now(beijing)` 模块导入时求值，长任务跨午夜过期
- [x] `finish()` 无条件推进 `last-update`，抓取不完整会永久丢提交（与 §4 完整性校验联动）
- [x] `init_driver()` 忽略 `CHROMEDRIVER_PATH` 环境变量，硬编码本地路径（CI 脆弱）
- [x] `_convert_html_to_markdown` 失败返回 `None`，HDU/NowCoder 拼接 `None` 抛 TypeError
- [x] QOJ 数字状态（如 80）与字符串状态混用，前端类型不一致
- [x] NowCoder cookie 未校验非空
- [x] `_load_file(default=[])` 可变默认参数反模式
- [x] 分页上限硬编码（50/10/20 页）：已由完整性保护兜底（到上限未遇终止条件则标记不完整，不推进 last-update，下次重跑），不再静默丢数据

---

## 9. 路线图

```
v0.2.0（静态版增强 + 爬虫数据层升级，分支 dev/v0.2.0）
├─ A. 代码质量/健壮性修复（§8 清单，含时区/驱动路径/pandoc/分页完整性）
├─ B. 爬虫数据层：订阅模型 + 任务A/B + 全量提交采集 + 报告生成模块
├─ C. 前端：标签、搜索、Dashboard(+报告区+contribution)、复盘时间轴页、UI/图标库迁移、响应式与可访问性
└─ D. 可选：静态版客户端加密资源保护（默认不做）

v0.3.0（动态版）
├─ 同代码库 API routes / Docker 部署骨架
├─ GitHub OAuth + session（登录=队员）
├─ 个人收藏 / 稍后再做（DB）
├─ 正式资源保护（账号鉴权，受保护资源不进公开仓库）
├─ 订阅管理 UI + 精确到分钟的按 end_time 一次性调度
└─ 报告按需重新生成
```

---

## 10. 已确认决策记录（讨论结论速查）

| # | 决策 | 结论 |
|---|------|------|
| 1 | 双版本架构 | 单一代码库 + 构建开关，静态版与动态版并存 |
| 2 | 题目标签 | 队内共享，写 `problem.json`，随 git 同步 |
| 3 | 收藏/稍后再做 | 区分每个人，动态版 DB 实现 |
| 4 | 预订比赛 | 一次性任务（比赛结束→抓整场→生成报告），与提交周期任务分离 |
| 5 | 提交记录周期任务 | 每天一次增量同步 |
| 6 | 全量提交采集 | 每份提交的代码 + 时间戳都保存，供复盘 |
| 7 | LLM 报告 | 每场一份，不做预处理直接给 LLM，DeepSeek（OpenAI 兼容） |
| 8 | 报告展示 | 放 Dashboard，支持查看往期报告 |
| 9 | 账号系统 | GitHub OAuth + session，登录=队员，不区分管理员 |
| 10 | 资源保护 | v0.2.0 不做；v0.3.0 动态版账号鉴权为正式方案 |
| 11 | UI 库 | shadcn/ui |
| 12 | 图标库 | lucide-react（替换 react-icons） |
| 13 | CI secret | `DEEPSEEK_API_KEY` |

## 11. 遗留 / 待定

- [ ] Dashboard 占位页、README 页（v0.2.0 顺带实现或评估）
- [ ] 复盘报告内容细节：是否含每道题 AC 时间线/WA 次数（数据已全量采集，倾向包含）
- [ ] 前端测试策略评估
- [ ] `clang-format` 等模板残留清理确认
