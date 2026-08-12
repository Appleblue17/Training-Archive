# 开发笔记

> 短期 temp 文档：只记录当前进度、待办与注意事项，不保留历史。历史变更见 `docs/CHANGELOG.md`。

---

## 当前状态

- 主功能可用（竞赛列表、文件查看、日志、搜索、Dashboard、复盘时间轴）；爬虫双模式已建（`--contests-only` + `--submissions-only`），由自托管守护进程调度（`daemon.py`：`fire` / `sync` / `incremental`，表达式在 `crawler/config.json` 的 `scheduled` 块）。
- **v0.3.0 已发布（2026-08-12，部署方式重构）**：静态版统一为自托管爬虫 + GitHub Pages（已删除 Actions 爬虫链路）；跨平台守护进程 `daemon.py` 替代 `server-task.sh`；fork 部署参数化（basePath / URL 常量 env 化）。服务器 + 本地 Linux 已端到端实测通过（`install` 自启 + `sync`/`fire` + 部署链路）；Windows / macOS 测试留待后续。
- HDU / NowCoder 爬虫默认停用（`crawler/config.json` 的 `enabled` 字段控制）。
- 闹钟机制已实现（`crawler/scripts/alarm.py` + `crawler/scripts/daemon.py sync/fire`）：订阅条目可选填 `end_time`，未来比赛写闹钟表 `crawler/alarms.json`（gitignore），到点由 `fire` 爬取 + 立即生成报告；状态模型 `planned` / `pending` / `archived` / `failed`。
- `contests/` 数据目录为空（git 忽略），本地开发需先准备数据或运行爬虫；deploy 分支跟踪数据与增量状态。
- **下一版本 v0.4.0 = 动态版**（服务器 / Docker，账号系统、正式资源保护），见 `docs/roadmap.md`。

## 待办

### v0.4.0（动态版）

- [ ] 同代码库 API routes / Docker 部署骨架
- [ ] GitHub OAuth + session（登录=队员）
- [ ] 个人收藏 / 稍后再做（DB）
- [ ] 正式资源保护（账号鉴权，受保护资源不进公开仓库）
- [ ] 订阅管理 UI + 精确到分钟的按 end_time 一次性调度
- [ ] 报告按需重新生成

### 后续

- [ ] Windows / macOS 守护进程实测（`daemon.py` install / run；v0.3.0 已在 Linux 实测通过）
- [ ] 评估是否引入前端测试（当前仅 lint）
- [ ] 复盘报告内容细节：是否含每道题 AC 时间线/WA 次数（数据已全量采集，倾向包含）

## 注意事项

### 已选定的技术栈

- **UI 库**：shadcn/ui（Radix + Tailwind），新增组件通过其 CLI 或手工复制引入。
- **图标库**：lucide-react；**禁止新增 `react-icons`**。

### 构建与运行

- 生产构建要求本地存在 `contests/`；`deploy.yml` 会先复制 `contests/` → `public/contests/` 再 `pnpm build`。
- `NODE_ENV=production` 时启用 `output: "export"` 与 `basePath: "/Training-Archive"`；本地开发（`pnpm dev`）使用根路径。
- **daemon 用 venv 运行**：系统 `python3` 可能缺 `dotenv`/`croniter`/`filelock`，统一用 `.venv/bin/python crawler/scripts/daemon.py ...`（`python3 -m venv .venv && .venv/bin/pip install -r crawler/requirements.txt`）。`install`/`install --system` 会把「执行 install 的 python」写进服务启动命令，务必用 `.venv/bin/python` 执行。
- **无头服务器**：user unit（默认 install）依赖登录会话；服务器用 `install --system`（系统级 systemd，`WantedBy=multi-user.target`，开机即启动，需 sudo）。

### 爬虫

- **平台启用/禁用**：`crawler/config.json` 的 `enabled` 字段（缺省 `false` 视为禁用，配置文件缺失/解析失败时全部禁用）；模板 `crawler/config.example.json`。
- **订阅条目**（`crawler/subscriptions/` 下各 `.json`）：`enabled` 为订阅级开关（缺省启用，与平台级缺省禁用不同）；按文件名排序合并、重复 `link` 去重、模板文件 `*.example.json` 跳过。
- **闹钟机制（静态版专用）**：订阅条目可选填 `end_time`（北京时间 ISO）。`daemon.py sync` 先 `plan` 分类：不填 = 历史比赛立即爬不生成报告；已过 = 立即爬 + 报告；未来 = 写闹钟表；`failed` = 输出 `RETRY` 重试一次（成功 → `archived`，失败保持 `failed`，`plan` 输出 `WARNING`；`RETRY` 第 3 列为原任务的 `end_time`，**重试成功后仅当原任务填了 `end_time` 才生成报告**）。`fire`：`due` 无到期闹钟安静退出，有则爬取（`--contests-only --links`）+ 报告 + `mark --archived`；**爬取失败 `mark --failed`**（fire 只查 `planned`，失败后不再自动重试，靠自动 `sync` 兜底）。报告条件 = 订阅填了 `end_time`（EXPIRED / RETRY / fire due），按链接反查生成（`report.py --links`），与"本次是否新建"无关。订阅修改 `end_time` → 重新安排，订阅删除 → 剪除闹钟。注意：`--links` 与 `--submissions-only` 互斥、无值报错。
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
python3 crawler/scripts/report.py --links "https://qoj.ac/contest/123,https://qoj.ac/contest/456"  # 按订阅链接反查生成（daemon sync/fire 用；报告条件 = 订阅填了 end_time：EXPIRED/RETRY/fire due）
python3 crawler/scripts/report.py --from-crawl           # 手动：只对本次爬取新建的比赛生成
python3 crawler/scripts/report.py --from-crawl --links "https://qoj.ac/contest/123"  # 手动：只对本次新建中指定链接生成
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
sudo .venv/bin/python crawler/scripts/daemon.py install --system  # 仅 Linux：系统级服务（开机即启动、无需登录；需 root）
python3 crawler/scripts/daemon.py uninstall       # 注销开机自启
python3 crawler/scripts/daemon.py status          # 查看状态 / 闹钟 / git / 日志
```
