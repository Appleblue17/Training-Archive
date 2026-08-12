# 开发规划（Roadmap）

> 本文档记录 v0.2.0 / v0.3.0 的规划讨论结论与路线图。

---

## 1. 总体方向：双版本架构

网站目前是纯静态导出并部署在 GitHub Pages，限制了一些功能。计划分为两个版本，**单一代码库 + 构建开关**，不维护两套前端：

| 版本 | 部署形态 | 适用场景 |
|------|----------|----------|
| **静态版（v0.2.x → v0.3.0）** | GitHub Pages（`output: "export"`） | 公开只读内容 |
| **动态版（v0.4.0）** | 服务器 / Docker（同代码库加 API routes 或独立 service） | 账号、个人数据、正式资源保护、实时能力 |

构建开关建议：环境变量（如 `NEXT_PUBLIC_DEPLOY_MODE=static|dynamic`）区分构建模式。数据流上保留「文件为事实来源」：爬虫不变，动态版在服务端把 `contests/` 数据灌入 DB 供 API 查询。

### 1.1 部署方式演进（2026-08-12 确认 v0.3.0 格局）

**v0.2.x**：静态版有两种部署方式（方式一 Actions 轮询 / 方式二自建服务器 cron + 闹钟）。
**v0.3.0 起**：静态版统一为**一种部署方式**——自托管爬虫（跨平台守护进程）+ GitHub Pages 部署；删除方式一（Actions 爬虫链路）。动态版顺延 **v0.4.0**。

| # | 部署形态 | 自动任务（爬取/总结） | 版本 | 操作 |
|---|----------|----------------------|------|------|
| 1 | GitHub Pages（静态导出） | **自托管守护进程**（`crawler/scripts/daemon.py`，Win / Mac / Linux） | v0.3.0 | `daemon.py install` 注册自启 + `run` 主循环；产物 push 回 `deploy` 分支触发部署 |
| 2 | 自建服务器（Next.js 动态） | 服务器内 APScheduler / `at`（精确到分钟） | v0.4.0 | 见 §3，需 API routes / Docker |

> **删除方式一的理由（2026-08-12 确认）**：Actions 轮询无法表达「比赛结束精确触发」的语义——方式一 `--contests-only` 在比赛**开始**时建目录回填提交，但报告只对**已结束**比赛生成，导致预订的未来比赛在轮询下报告永远不自动生成（目录已存在后跳过）；且频繁触发 Action 不经济。统一为守护进程后，闹钟 `due`（`fire_at <= now`）天然表达精确触发。代价是零运维入口消失，fork 使用者需自备运行环境（服务器或个人电脑）。

#### 方案 1（唯一，v0.3.0 起）：自托管守护进程 + GitHub Pages 部署

- 提供跨平台守护进程 **`crawler/scripts/daemon.py`**（替代 v0.2.x 的 `crawler/server-task.sh`，逻辑搬迁：git 流程、闹钟分类、失败标记、提交规则原样保留）：
  ```bash
  python3 crawler/scripts/daemon.py run            # 主循环（前台运行，按需安装为系统服务）
  python3 crawler/scripts/daemon.py sync           # 同步订阅：历史/过期立即爬，未来比赛写入闹钟
  python3 crawler/scripts/daemon.py fire           # 闹钟到点触发（无到期安静退出）
  python3 crawler/scripts/daemon.py incremental    # 提交增量同步（--submissions-only）
  python3 crawler/scripts/daemon.py install        # 注册开机自启（按 OS：systemd user / launchd / schtasks）
  python3 crawler/scripts/daemon.py status         # 查看状态 / 日志
  ```
- **主循环调度**：croniter 解析 `config.json` 的 `scheduled` 块（三个表达式，语义与 v0.2.x 完全一致）+ 闹钟表 `fire_at`；睡眠恢复后每个任务**只补跑一次**（不追赶历史，靠任务自身增量/幂等覆盖错过时段）。
- **自启注册**：默认「登录时启动」（个人电脑语义）；服务器可选系统级服务（开机即跑）。
- **预订比赛用闹钟机制**：订阅条目可选填 `end_time`（不填 = 历史比赛立即爬取归档不生成报告；已过 = 过期比赛立即爬取 + 报告），`sync` 把未来比赛写入闹钟表 `crawler/alarms.json`（gitignore，不提交）并标记 `planned`，到点 `fire` 爬取并立即生成报告。状态模型 `planned` / `pending` / `archived` / `failed`：**爬取失败即 `failed`（fire 不再自动重试），自动 `sync` 重试一次（成功 → `archived`，失败保持 `failed`）**；订阅修改 `end_time` 或删除条目时 `sync` 相应重新安排/剪除闹钟。
- **部署触发**：`deploy.yml` 保留 `on: push: branches: [deploy]`——带 `[contests-changed]` 标记的提交才部署，仅状态变化的提交跳过（push 事件免日期校验；`workflow_dispatch` 仍无条件部署）。
- **fork 部署参数化**：`next.config.ts` 的 `basePath` / `assetPrefix` 与 `global.ts` 的 `REPO_URL` / `BASE_URL` / `PREFIX_URL` 改为 env 可覆盖（默认值保持现状）。
- 优点：调度精确（闹钟 + 到点执行，替代轮询）、不消耗 Actions 配额、支持个人电脑（Win / Mac / Linux）；缺点：需自备运行环境与 Chrome/Chromedriver（README 部署指引写明）。

> **历史方案（v0.3.0 已删除）**：方式一 GitHub Actions 自动任务（`crawler-scheduled.yml` + `crawler.yml` 定时轮询）。因无法精确表达「比赛结束触发」且频繁触发 Action 不经济，v0.3.0 起删除，静态版统一为方案 1。

#### 方案 2（v0.4.0）：动态版
- 自建服务器 / Docker，Next.js API routes 或独立 service。
- 数据流：爬虫不变，服务端把 `contests/` 灌入 DB 供 API 查询；账号系统、个人收藏、正式资源保护见 §5 / §6。
- 调度：APScheduler / `at` 按 `end_time` 排一次性任务，精确到分钟，跑完即删（见 §3）。

---

## 2. 功能分级：静态版 / 动态版

| 功能 | 静态版 | 动态版 | 存储方案 / 说明 |
|------|:---:|:---:|------|
| 题目标签（队内共享） | ✅ | ✅ | 写入 `problem.json` 的 `tags` 字段，随 git 同步（不区分人、可持久化到文件跨设备同步） |
| 个人收藏 / 稍后再做 | ⚠️ 仅 localStorage 降级 | ✅ | DB 按 user 存储（区分每个人） |
| 题目搜索 | ✅ | ✅ | 构建时生成 `search-index.json`（标题/比赛/标签/平台/日期），前端过滤 |
| 资源保护 | ⚠️ 仅客户端加密（过渡，非正式） | ✅ | 动态版账号鉴权为正式方案；受保护资源不进公开仓库 |
| Dashboard 统计 / 最近动态 | ✅ | ✅ | 构建时从 `solve_time`/`submit_time` 聚合写 JSON |
| contribution 绿点图 | ✅ | ✅ | 纯 SVG/CSS，按提交/解决时间聚合 |
| 「我的收藏 vs 队内收藏」 | ❌ | ✅ | 依赖账号系统 |
| 账号系统 | ❌ | ✅ | GitHub OAuth + httpOnly session cookie |
| 比赛复盘 + LLM 报告 | ✅（守护进程预生成） | ✅（可按需重新生成） | 报告存为 `review.md` 进仓库 / DB |
| 预订比赛 / 触发 | ✅（守护进程闹钟精确触发） | ✅（精确到分钟） | 见 §3 |
| 订阅管理 UI | ❌（编辑 JSON 提交） | ✅（网站内操作） | 动态版加分项 |

---

## 3. 爬虫触发机制：预订比赛抓取与提交增量同步（用户已确认拆分）

**预订比赛 ≠ 周期同步**，两者是独立的机制：

### 预订比赛抓取 + 复盘（一次性任务）
- 语义：某场**预订**的比赛结束后 → 抓取整场比赛数据 → 立即生成复盘报告。
- 调度：
  - 动态版（v0.4.0）：APScheduler / `at` 按 `end_time` 排一次性 job，**精确到分钟**，跑完即删。
  - 静态版（v0.3.0 起唯一方式）：订阅条目填 `end_time`（不填 = 历史比赛，`sync` 立即爬取归档不生成报告；已过 = 过期比赛，立即爬取 + 报告），`sync` 把未来比赛写入闹钟表，守护进程按 `scheduled` 块间隔检查、`fire` 到点爬取 + 立即生成报告；状态模型 `planned`/`pending`/`archived`/`failed`，**失败即 `failed`（fire 不再自动重试），自动 `sync` 重试一次（成功 → `archived`，失败保持 `failed`）**。
- 幂等：每场比赛记录「已抓取 / 已生成报告」状态标记，重跑只补未完成的。
- 只抓该场次数据，与提交增量同步无耦合。

### 提交记录周期同步（--submissions-only）
- 每天一次（cron），对所有已开始/进行中的比赛做**增量**提交抓取。
- 沿用现有 `last-update.json` 增量机制。

### 订阅配置
- 统一 `crawler/subscriptions/` 目录（每个 `.json` 文件一份订阅列表，文件名随意，按 `link` 去重合并），模板 `crawler/subscriptions/subscriptions.example.json`。
- 条目含 `link` / `platform` / `enabled`（订阅级开关，缺省启用）；可选填 `end_time`（比赛结束时间，仅静态版守护进程闹钟机制读取）。
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
- LLM：**DeepSeek API**，OpenAI 兼容接口（`base_url=https://api.deepseek.com`，模型 `deepseek-chat`），密钥放 CI secret（静态版）/ 服务器环境变量（动态版）。
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
- **决策：v0.2.0 默认不做资源保护**，放 v0.3.0 动态版正式实现。

---

## 7. 前端增强（v0.2.0 静态版）

1. **标签**：`problem.json` 增 `tags`，竞赛列表页与题目页显示标记。
2. **搜索**：构建索引 + 前端过滤（不引搜索库，数据量小；必要时加 Fuse.js）。
3. **Dashboard**：最近动态、统计信息、contribution 绿点图、复盘报告区（当前报告 + 往期列表）。
4. **复盘时间轴页**：按 `submit_time` 展示每次提交序列，附 LLM 报告。
5. **UI 库与图标库**（用户授权先行选定）：UI 库 **shadcn/ui**（Radix + Tailwind，与现有体系一致，深色主题友好，静态导出兼容）；图标库 **lucide-react**（替换 `react-icons`）。
6. **质量与体验**：评审清单修复（见 §8）+ 响应式 + 可访问性。

---

## 8. 代码评审修复清单（v0.2.0 前置）

### 前端（已在 08c3f721 全部修复）
- [x] `platform-badge.tsx` fallback 分支误用 `platform === "codeforces"`，导致未知平台无背景色
- [x] `contest-table.tsx` 固定 17 列题号（A–Q）与魔法数 `colSpan={19}`
- [x] 竞赛列表未显式排序（依赖 `readdirSync` 顺序）；分页边界脆弱
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
├─ B. 爬虫数据层：订阅模型 + 比赛抓取/提交增量模式 + 全量提交采集 + 报告生成模块
├─ C. 前端：标签、搜索、Dashboard(+报告区+contribution)、复盘时间轴页、UI/图标库迁移、响应式与可访问性
└─ D. 可选：静态版客户端加密资源保护（默认不做）

v0.3.0（部署方式重构：静态版统一为自托管守护进程 + GitHub Pages）
├─ 跨平台守护进程 `crawler/scripts/daemon.py`（替代 `server-task.sh`：run 主循环 + install 自启 + sync/fire/incremental）
├─ `base.py` 驱动路径按 `platform.system()` 分发（Linux 保留 repo 自带二进制兜底；macOS / Windows 优先系统 Chrome）
├─ 删除 Actions 爬虫链路（`crawler-scheduled.yml` / `crawler.yml`；`deploy.yml` 清理 `workflow_run`）
├─ fork 部署参数化（`next.config.ts` basePath / `global.ts` URL 常量 env 化）
├─ 部署指引文档（Win / Mac / Linux + Chrome 环境准备）
└─ 方式二端到端实测（`install` 自启 + `fire` 真实比赛触发 + 部署链路）

v0.4.0（动态版）
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
| 4 | 预订比赛 | 一次性任务（比赛结束→抓整场→生成报告），与提交增量同步分离 |
| 5 | 提交记录周期同步 | 每天一次增量同步（`--submissions-only`） |
| 6 | 全量提交采集 | 每份提交的代码 + 时间戳都保存，供复盘 |
| 7 | LLM 报告 | 每场一份，不做预处理直接给 LLM，DeepSeek（OpenAI 兼容） |
| 8 | 报告展示 | 放 Dashboard，支持查看往期报告 |
| 9 | 账号系统 | GitHub OAuth + session，登录=队员，不区分管理员 |
| 10 | 资源保护 | v0.2.0 不做；v0.3.0 动态版账号鉴权为正式方案 |
| 11 | UI 库 | shadcn/ui |
| 12 | 图标库 | lucide-react（替换 react-icons） |
| 13 | CI secret | `DEEPSEEK_API_KEY` |
| 14 | 方式二预订比赛调度（2026-08-11，2026-08-12 重构状态模型 + cron 配置外置） | 闹钟机制：订阅填 `end_time`，`sync` 写闹钟表、cron 按 `config.json` 的 `scheduled` 块间隔 `fire` 到点爬取 + 立即生成报告；状态模型 `planned`/`pending`/`archived`/`failed`，**失败即 `failed`（fire 不再自动重试），自动 `sync` 重试一次（成功 → `archived`，失败保持 `failed`）**；订阅修改 `end_time`/删除条目时 `sync` 相应重新安排/剪除；方式一（Actions 轮询）不读取 `end_time` |
| 15 | 静态版部署方式统一（2026-08-12） | 删除方式一（Actions 爬虫链路），静态版统一为「自托管守护进程爬虫 + GitHub Pages 部署」；动态版顺延 v0.4.0 |
| 16 | Actions 爬虫 workflow（2026-08-12） | 彻底删除 `crawler-scheduled.yml` / `crawler.yml`；`deploy.yml` 去掉 `workflow_run` 监听，保留 `push` 触发 |
| 17 | 个人电脑模式（2026-08-12） | 支持跨平台守护进程 `daemon.py`（Win / Mac / Linux）：`run` 主循环按 config `scheduled` 块 + 闹钟到点执行、睡眠恢复只补跑一次；`install` 按 OS 注册登录自启（systemd user / launchd / schtasks ONLOGON） |
| 18 | 服务对象（2026-08-12） | 别人 fork 自己部署自己的站；fork 需参数化 basePath / URL 常量（env 覆盖，默认保持现状） |

## 11. 遗留 / 待定

- [ ] 复盘报告内容细节：是否含每道题 AC 时间线/WA 次数（数据已全量采集，倾向包含）
- [ ] 前端测试策略评估
