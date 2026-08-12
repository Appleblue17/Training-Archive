# 开发笔记

> 短期 temp 文档：只记录当前进度、待办与注意事项，不保留历史。历史变更见 `docs/CHANGELOG.md`。

---

## 当前状态

- 主功能可用（竞赛列表、文件查看、日志、搜索、Dashboard、复盘时间轴）；爬虫双模式已建（`--contests-only` + `--submissions-only`），由自托管守护进程调度（`daemon.py`：`fire` / `sync` / `incremental`，表达式在 `crawler/config.json` 的 `scheduled` 块）。**定时尚未启用**（未实测通过前手动触发验证）。
- **v0.3.0 进行中（部署方式重构）**：静态版统一为自托管爬虫 + GitHub Pages（已删除 Actions 爬虫链路）；跨平台守护进程 `daemon.py` 替代 `server-task.sh`；fork 部署参数化（basePath / URL 常量 env 化）。
- HDU / NowCoder 爬虫默认停用（`crawler/config.json` 的 `enabled` 字段控制）。
- 闹钟机制已实现（`crawler/scripts/alarm.py` + `crawler/scripts/daemon.py sync/fire`）：订阅条目可选填 `end_time`，未来比赛写闹钟表 `crawler/alarms.json`（gitignore），到点由 `fire` 爬取 + 立即生成报告；状态模型 `planned` / `pending` / `archived` / `failed`。
- `contests/` 数据目录为空（git 忽略），本地开发需先准备数据或运行爬虫；deploy 分支跟踪数据与增量状态。
- **v0.2.1 已发布（2026-08-12）**。下一版本 **v0.3.0 = 部署方式重构**：跨平台守护进程 `daemon.py` 替代 `server-task.sh`、删除 Actions 爬虫链路（方式一）、fork 部署参数化（basePath / URL 常量 env 化）。

## 待办

### v0.3.0（部署方式重构）

- [x] `daemon.py` 跨平台守护进程（替代 `server-task.sh`；已实现 commit `e502c2bb`）
- [x] 删除 Actions 爬虫链路（`crawler-scheduled.yml` / `crawler.yml` 已删；`deploy.yml` 已去掉 `workflow_run` 监听，保留 `push` 触发）
- [x] fork 部署参数化（`next.config.ts` basePath、`global.ts` URL 常量 env 化：`NEXT_PUBLIC_BASE_PATH` / `NEXT_PUBLIC_SITE_URL` / `NEXT_PUBLIC_REPO_URL`）
- [x] 部署指引文档（README：Chrome 环境准备按平台 + fork 参数化说明）
- [ ] 端到端实测（v0.3.0 改造完成后统一验证：`install` 自启 + `fire` 真实比赛触发 + 部署链路；用户已做过初步测试）

### 常规

- [ ] 评估是否引入前端测试（当前仅 lint）
- [ ] 复盘报告内容细节：是否含每道题 AC 时间线/WA 次数（数据已全量采集，倾向包含）

## 注意事项

### 已选定的技术栈

- **UI 库**：shadcn/ui（Radix + Tailwind），新增组件通过其 CLI 或手工复制引入。
- **图标库**：lucide-react；**禁止新增 `react-icons`**。

### 构建与运行

- 生产构建要求本地存在 `contests/`；`deploy.yml` 会先复制 `contests/` → `public/contests/` 再 `pnpm build`。
- `NODE_ENV=production` 时启用 `output: "export"` 与 `basePath: "/Training-Archive"`；本地开发（`pnpm dev`）使用根路径。

### 爬虫

- **平台启用/禁用**：`crawler/config.json` 的 `enabled` 字段（缺省 `false` 视为禁用，配置文件缺失/解析失败时全部禁用）；模板 `crawler/config.example.json`。
- **订阅条目**（`crawler/subscriptions/` 下各 `.json`）：`enabled` 为订阅级开关（缺省启用，与平台级缺省禁用不同）；按文件名排序合并、重复 `link` 去重、模板文件 `*.example.json` 跳过。
- **闹钟机制（静态版专用）**：订阅条目可选填 `end_time`（北京时间 ISO）。`daemon.py sync` 先 `plan` 分类：不填 = 历史比赛立即爬不生成报告；已过 = 立即爬 + 报告；未来 = 写闹钟表；`failed` = 输出 `RETRY` 重试一次（成功 → `archived`，失败保持 `failed`，`plan` 输出 `WARNING`）。`fire`：`due` 无到期闹钟安静退出，有则爬取（`--contests-only --links`）+ 报告 + `mark --archived`；**爬取失败 `mark --failed`**（fire 只查 `planned`，失败后不再自动重试，靠自动 `sync` 兜底）。订阅修改 `end_time` → 重新安排，订阅删除 → 剪除闹钟。注意：`--links` 与 `--submissions-only` 互斥、无值报错。
- **凭据**：一律走环境变量（`.env` / CI secrets），`config.json` 只放非敏感参数。本地运行爬虫/报告脚本自动加载根目录 `.env`（`load_dotenv()`，不覆盖已有变量）。
- **提交抓取截止**：非首次按全局 `last-update.json` 增量；首次抓取的新比赛以 `start_time` 为截止全量回填。QOJ 补订旧比赛需手动重置该平台 last-update 触发全量重抓。
- **`--contests-only`**：只检查订阅有没有触发，有新建比赛才回填其提交；**不推进 `last-update.json`**（已有比赛增量由每日 `--submissions-only` 负责）。若新建比赛提交回填失败（如超时），文件夹已存在，后续运行不会当新建重试，需手动处理。
- 早于比赛开始时间的提交统一丢弃（跨赛季复用题目）；staged 中此类旧提交下次运行清除。
- HDU / NowCoder 的 HTML→Markdown 依赖 **pandoc**（CI 安装 3.6.3；本地需自行安装）。
- 爬虫驱动：CI 用 `browser-actions/setup-chrome` 并通过环境变量传路径；本地需准备 `crawler/chrome-linux64` 与 `crawler/chromedriver-linux64`。
- `_get_extension_name()` 语言识别为启发式映射，未识别语言 fallback `.txt`。

### 前端

- Markdown 渲染在服务端完成（`file-viewer-markdown-wrapper.tsx`），HTML 通过 `dangerouslySetInnerHTML` 注入，依赖 `rehype-sanitize` 安全过滤。
- 数学公式：`$$\n...\n$$` 在 wrapper 中改写后再走 KaTeX 流水线；修改渲染管线时注意保持该预处理。

## 命令速查

```bash
pnpm install        # 安装前端依赖
pnpm dev            # 开发模式
pnpm build          # 生产构建（NODE_ENV=production 时导出 out/）
pnpm lint           # ESLint 检查

pip install -r crawler/requirements.txt   # 爬虫依赖
python3 crawler/scripts/scheduled_task.py                # 默认模式：抓订阅比赛 + 全量增量提交（手动/临时）
python3 crawler/scripts/scheduled_task.py --contests-only     # 只查订阅/新建比赛（高频触发）
python3 crawler/scripts/scheduled_task.py --contests-only --links "https://qoj.ac/contest/123"  # 只抓指定订阅链接
python3 crawler/scripts/scheduled_task.py --submissions-only  # 提交增量模式（每日）
python3 crawler/scripts/report.py --from-crawl           # 复盘报告：只对本次爬取新建的比赛生成
python3 crawler/scripts/report.py                        # 补生成：扫描所有缺报告的已结束比赛

python3 crawler/scripts/alarm.py plan              # 扫描订阅：分类 HISTORY/EXPIRED/RETRY，写未来闹钟
python3 crawler/scripts/alarm.py due               # 列出到点的 planned 闹钟（无则空输出）
python3 crawler/scripts/alarm.py mark <link> --archived  # 标记已处理完
python3 crawler/scripts/alarm.py mark <link> --failed    # 标记失败（下次 sync 重试）
python3 crawler/scripts/alarm.py list              # 列出全部闹钟

python3 crawler/scripts/daemon.py run             # 主循环（前台运行；安装为服务后由系统拉起）
python3 crawler/scripts/daemon.py sync            # 同步订阅：历史/过期立即爬，未来写闹钟表（自动 + 可手动）
python3 crawler/scripts/daemon.py fire            # 闹钟到点触发（无到期安静退出）
python3 crawler/scripts/daemon.py incremental     # 提交增量同步（--submissions-only；每日）
python3 crawler/scripts/daemon.py install         # 注册开机自启（Linux systemd / macOS launchd / Windows schtasks）
python3 crawler/scripts/daemon.py uninstall       # 注销开机自启
python3 crawler/scripts/daemon.py status          # 查看状态 / 闹钟 / git / 日志
```
