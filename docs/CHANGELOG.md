# Changelog

> 记录会影响用户、开发者或贡献者体验的重要变更。面向人类阅读，应随版本发布更新。
> 格式参考 [Keep a Changelog](https://keepachangelog.com/)。
> [备忘] 变更类型：Added（新增）、Changed（变更）、Deprecated（弃用）、Removed（移除）、Fixed（修复）、Security（安全）。

> [注意] 本文档是项目历史的单一事实来源，应随项目演进保持更新。
> [注意] 本文档不是所有变更的完整清单；只记录重要变更并保持简洁易读。完整变更见版本控制系统（如 Git）历史。

## [Unreleased]

> 本段为 v1.0.0-beta.1（静态版稳定版）发布准备。实测通过后改标题为
> `[1.0.0-beta.1] - <发布日期>`，并同步 `package.json` 版本号；发布检查清单见
> `docs/release-checklist.md`。

### Added

- **跨平台端到端测试脚本**（`crawler/scripts/e2e_test.py`）：`check` / `unit` / `offline` /
  `live` / `service` / `events`；所有写操作在 `.e2e/` 隔离沙箱（本地裸 origin）内执行，
  不污染真实仓库、不向 GitHub 推送、不改真实订阅。`offline` 覆盖编排逻辑与特殊情况
  （锁、状态损坏自愈、赛前提醒等 20 项）；`live` 对真实链接跑完整抓取 / 复盘 / 推送
- **端到端测试手册**（`docs/e2e-testing.md`）：Linux / Windows 全链路步骤，以及
  睡眠 / 休眠 / 关机重启 / 断网 / 进程被杀 / 断电 / 双实例 / 时区 / 长时运行等
  特殊情况的操作、预期、验证与通过标准
- **前端测试 CI**（`.github/workflows/frontend-tests.yml`）：lint + `tsc --noEmit` + vitest，
  此前前端测试只在 deploy 分支的部署流程里运行
- **爬虫测试 CI 增强**：`crawler-tests.yml` 去掉写死的分支过滤并新增 `windows-latest`
  矩阵与 `e2e-offline` job（测试脚本本身也在 ubuntu + windows 上运行）

### Changed

- **`daemon.log` 大小轮转**（`daemon.py`）：日志原会无上限增长；单文件达到 10MB 时
  轮转为 `daemon.log.1`（只保留一份历史，避免占满磁盘）。两个 `.gitignore` 均忽略
  `daemon.log.1`
- **`install --xvfb`（仅 Linux，可选）**（`daemon.py`）：以
  `xvfb-run -a env CHROME_HEADLESS=0` 包裹 systemd 服务命令，使服务方式也能抓取 QOJ 等
  需要非无头 + 显示的反爬站点（需装 `xvfb`）；缺省行为不变
- **CI Node 20 → 22**（`deploy.yml` / `frontend-tests.yml`）：jsdom 30 / undici 8 在
  Node 20 下 vitest forks worker 启动失败
- **deploy 的 Next 构建缓存 key 改用 `pnpm-lock.yaml`**：原用 `package-lock.json`，
  缓存永不随依赖失效

### Fixed

- **`computeContribution` 按北京时间日期聚合**（`src/lib/dashboard.ts`）：原用运行环境
  本地时区的日期，导致同一份数据在 UTC 的 CI 与 UTC+8 浏览器上落到不同日期
- **子进程强制 UTF-8 编码**（`daemon.py` / `qq_bot.py` / `e2e_test.py`）：Windows 中文区域
  （cp936）下按 locale 解码 UTF-8 的中文比赛名 / 路径会 `UnicodeDecodeError`
- **入口脚本 stdout 切 UTF-8**（`daemon.py` / `e2e_test.py`）：Windows cp1252 控制台打印
  中文结果时 `UnicodeEncodeError` 导致进程退出
- **`NO_PROXY` 含带括号 IPv6 导致复盘生成失败**（`crawler/llm/deepseek_client.py`）：
  `NO_PROXY` / `no_proxy` 含 `[::1]` 时 httpx 将其当成 URL 解析，在端口处抛
  `InvalidURL: Invalid port ':1]'`，OpenAI 客户端无法创建，`report.py` 生成失败并
  阻断 daemon sync（不归档、不部署）；`normalize_proxy_env()` 统一去掉方括号
- **运行时状态文件非原子写入**（`daemon.py` / `alarm.py`）：`daemon-state.json` /
  `alarms.json` 原直接以 `"w"` 覆盖写，断电或写入中途被杀会留下截断 JSON
  （后者会让 `alarm.py plan` 直接中止）；新增 `crawler/scripts/jsonio.py` 的
  `write_json_atomic`（同目录临时文件 + fsync + `os.replace`）

## [0.3.3] - 2026-10-06

### Added

- **爬虫测试套件（pytest，`crawler/tests/`，189 条用例）**：纯逻辑单元测试覆盖时间解析（HDU / QOJ / ISO）、订阅加载与去重、报告 prompt 构建、闹钟分类与状态迁移、qq-bot 指令匹配 / `/subs add` 解析 / 同秒游标、qq-share 文本清洗与已发送标记、daemon plan 解析与调度判断、clean-log、NowCoder 登录态判断、QOJ 源码提取；新增 `crawler/requirements-dev.txt` / `crawler/pytest.ini`，运行 `.venv/bin/python -m pytest crawler/tests`
- **爬虫测试 CI**（`.github/workflows/crawler-tests.yml`）：`crawler/**` 变更时自动安装依赖并运行 pytest

### Changed

- **QQ 群分享只发送 `review.md` 文件**（`qq_share.py`）：移除文案生成与群发（`qq-share.txt`、DeepSeek 简化版模板、`qq.send_mode` / `--file-only`）。发送成功后在比赛文件夹写入 `qq-share.sent` 已发送标记（两个 `.gitignore` 均忽略），补发扫描跳过已发送与无 review 的比赛；同时删除不再使用的 `crawler/prompts/qq-share.template.example.md`

- **Chrome 无头模式可通过 `CHROME_HEADLESS=0` 关闭**（`platforms/base.py`）：默认仍为无头；QOJ 等站点对 headless 有 Cloudflare Turnstile 检测，在 Xvfb / 有显示器的环境用 `xvfb-run -a env CHROME_HEADLESS=0 ...` 跑非 headless 可通过（本机三平台实测即用此方式）

### Fixed

- **QQ 分享在 `file_only` 下永不触发 / 部分成功不回补**（`qq_share.py`）：`send_contest_shares_for_all` 依赖 `qq-share.txt` 判定未发送，而 `file_only` 模式不产生该文件 → 永不触发；且文字成功、文件失败时会删除 `qq-share.txt`，文件不再重试。随文案移除改为 `qq-share.sent` 标记
- **qq-bot 同秒消息可能漏处理**（`qq_bot.py`）：增量游标 `time > last_time` 精度到秒，同一秒内、两次轮询之间到达的消息会被跳过；现对边界秒用 message_id 去重补足（`bot-state.json` 新增 `seen_ids`）
- **last-update 水位改用抓取开始时间**（`platforms/base.py`）：`finish()` 原写抓取**结束**时间，会漏掉抓取期间新产生、但在下次抓取开始时已早于水位的提交；改为记录抓取开始时间，并保证水位单调不回退
- **抓取中途异常不再推进 last-update**（`platforms/base.py`）：多场比赛时若前一场已标记完成、后一场抛异常，原逻辑仍会推进全局水位，导致失败比赛早于水位的提交被永久跳过；异常时作废本次完整性标记
- **空 `--links` 退化为全量扫描**（`report.py` / `qq_share.py`）：`--links` 存在但解析为空时会命中"扫描全部比赛"分支，report 会静默对全部缺报告比赛调用 DeepSeek、qq_share 可能群发全部待发比赛；现返回非零并拒绝扫描
- **空 / None 复盘输出写坏 `review.md`**（`report.py`）：模型返回空内容时写出 0 字节 `review.md`，之后因"文件已存在"被永久跳过；现判定为失败且不落盘，写入改为临时文件 + `os.replace` 原子替换
- **配置不可读时剪除全部闹钟**（`alarm.py`）：`config.json` 缺失 / 损坏时 `_load_enabled_platforms` 返回空列表，plan 的剪除逻辑会把全部闹钟（含 archived 历史）删除；现返回 None 并中止 plan
- **单平台构造失败中断其余平台**（`scheduled_task.py`）：`crawler_for()` 构造在 `try` 之外，缺依赖 / 驱动初始化失败会抛出中断 main 循环；现移入 `try`，失败仅影响该平台
- **daemon 主循环健壮性**（`daemon.py`）：`_is_due` 遇到损坏的 `last_run`（非字符串）抛 `TypeError` 会杀死 daemon；现捕获所有异常，主循环每轮包裹异常处理并继续；`ensure_deploy_branch` 的 `git checkout` 失败改为中止，避免在错误分支上提交推送
- **QOJ 比赛时长解析**（`platforms/qoj/qoj.py`）：原 `split("hours")` 无法处理 `[90 minutes]` / `[2 hour]` / 空串（`ValueError` 中断整场抓取）；改为正则解析，无法识别时记录并跳过该比赛；提交页无法定位当前页时不再抛 `AttributeError`
- **qq-bot 自然语言关键词按最长匹配**（`qq_bot.py`）：`历史比赛` 曾先命中更早注册的短关键词 `比赛`（`/upcoming`）；现最长关键词优先
- **NowCoder 登录态误报**（`platforms/nowcoder/nowcoder.py`）：`NOWCODER_USERNAME` 未配置时 `self.username in html` 恒为真，无效 Cookie 也被当作"登录成功"；现无昵称时改用页面特征（有「退出」入口 / 用户主页链接）校验，并在缺昵称时告警
- **QOJ 提交源码偶发抓取失败**（`platforms/qoj/qoj.py`）：长任务中 Cloudflare 偶发返回挑战页（无 `pre.sh_sourceCode`）时原代码抛 `AttributeError`、源码静默缺失；现提取失败退避后重试一次，仍失败给出明确错误
- **部分平台失败时仍返回 0**（`scheduled_task.py`）：构造失败改为只影响该平台后，`main` 仍会在其他平台成功时返回 0，daemon sync/fire 据此把失败平台未真正抓取的链接也 `mark --archived`（不生成报告、不再重试）；现任一平台失败即返回非零
- **平台块畸形时 alarm plan 崩溃**（`alarm.py`）：原仅校验顶层是 JSON 对象，`{"qoj": null}` 仍会在 `.get("enabled")` 抛 `AttributeError`；现校验每个平台块，畸形时返回 None 中止 plan
- **`last_run` 非对象时 daemon 崩溃**（`daemon.py`）：`{"last_run": 123}` 时 `.get(task)` 在 `try` 之外抛 `AttributeError`；现 `load_state` 归一化 `last_run`，且 `_is_due` 的查询也纳入 `try`
- **已发送标记写盘失败谎报成功**（`qq_share.py`）：`_mark_sent` 吞掉 `OSError` 后 `send_contest_share` 仍返回 True，下次补发会重复上传同一份 review；现标记写入失败返回 False

## [0.3.2] - 2026-09-22

### Added

- **archive-bot logo**（`(main)/layout.tsx`）：主标题左侧放置 logo（`next/image` + `unoptimized` + `priority`，适配静态导出）
- **浏览器 tab 标题细化**（各页面 `metadata`）：根 layout 使用 `title.template`（`%s · Training Archive`）；`/pageN` → `Page N`，`/dashboard` → `Dashboard`，`/search` → `Search`，`/readme` → `README`，`/status` → `Status`，`/review/<比赛>` → `<比赛名> · Review`，文件查看页 → `<文件> · <比赛名>`（题目/提交页含题名；无数据占位页回退 `File` / `Submission`）
- **`/search` 分页**（`search-client.tsx`）：搜索结果按 `ITEMS_PER_PAGE`（20）分页并新增页码导航；输入或标签变化时回到第 1 页（此前全部题目堆在同一页）
- **资源保护（静态版客户端加密）**：可把某场比赛标记为受保护，其题目 / 源码 / PDF / 附件 / 复盘需要全站统一密码才能查看
  - 标记（并集）：`contests/<文件夹>/contest.json` 的 `"protected": true`（推荐；爬虫只在新建比赛时写 `contest.json`，之后不会覆盖），或仓库根 `protected-contests.json` 的 `protected` 数组
  - 密码取构建时环境变量 `RESOURCE_PASSWORD`（`.env` / GitHub Actions secret，**非** `NEXT_PUBLIC_`），服务端 PBKDF2-SHA256（100k）+ AES-256-GCM 加密，产物只含密文
  - 浏览器端 WebCrypto 解密（`resource-gate.tsx`），验证成功后把密码记入 `localStorage`，下次自动解锁；密码错误重新提示
  - 覆盖面（方案 A：只保护文件内容）：文件查看器三条路由（内容 + 元数据整体加密，Download/Raw 改 Blob）与复盘页；比赛名 / 题目 / 标签 / 统计等元数据公开，首页 / 搜索 / Dashboard 正常展示（首页带锁标记），`public/contests` 不复制受保护比赛原始文件
  - 未配置 `RESOURCE_PASSWORD` 时受保护页面只显示提示、不渲染内容（不泄露明文）
- **前端组件/单元测试**（Vitest + React Testing Library，jsdom）：`pnpm test` 运行 33 条用例，覆盖格式化/URL 工具、搜索过滤与分页、Dashboard 聚合、元数据面板内部字段跳过（`[ProtectedData]` 回归）、资源保护加解密往返与 `ResourceGate`、`ContestTable` 锁标记、搜索分页导航；为可测性把搜索过滤/分页抽到 `src/lib/search.ts`、Dashboard 聚合抽到 `src/lib/dashboard.ts`、元数据 banner 常量抽到 `src/lib/metadata-fields.ts`

### Changed

- **构建流程**：`pnpm build` / `pnpm dev` 先执行 `scripts/prepare-public-contests.mjs`（复制 `contests/ → public/contests` 时排除受保护比赛）；`deploy.yml` 不再直接 `cp -r`，构建步骤注入 `RESOURCE_PASSWORD` secret
- **升级 Next.js**：`15.4.2-canary.5` → `15.5.25`（`eslint-config-next` 同步）。canary 的 webpack 生产构建在冷缓存下会卡死并堆溢出（`Creating an optimized production build` 阶段），稳定版可正常完成构建

### Fixed

- **首页受保护比赛展开详情显示 `[ProtectedData]` 字段**：加密载荷曾挂在比赛对象上、被元数据面板当普通字段渲染。方案 A 下不再把加密载荷挂到比赛对象；元数据面板同时跳过 `protected` / `protectedData` / `protectionMisconfigured` 等内部字段

### Security

- 受保护比赛的**文件内容**与原始文件不进入公开静态产物；元数据（比赛名 / 题目 / 标签 / 统计）仍公开。未验证者只能拿到 AES-GCM 密文。静态版客户端加密 + `localStorage` 存密码仍属过渡方案（无访问者区分 / 无法单独吊销 / XSS 风险），正式方案为 v0.4.0 动态版账号鉴权

## [0.3.1] - 2026-08-13

### Added

- **QQ 群分享（share AI task，`crawler/scripts/qq_share.py`）**：将比赛复盘（`review.md`）改写成轻松随性的纯文本（`qq-share.txt`，DeepSeek 独立调用、更高 temperature），并通过 NapCat（OneBot 11 正向 WebSocket，Bearer token 鉴权）发送到 QQ 群——群发文字（`send_group_msg`，CQ 码转义 + Markdown 清洗）+ 上传 `review.md` 文件（`upload_group_file`）；发送成功后删除 `qq-share.txt`（临时产物，不入 git）
  - 文字缺失（生成失败/为空）：记 log，跳过文字直接发 review 文件
  - `review.md` 不存在：跳过（share 依赖 report 生成的完整报告，不自行生成）
  - NapCat 未配置 / 连接失败 / 发送失败：仅告警不阻断 daemon（`qq-share.txt` 保留供下次重试）
  - 新增 `ai_tasks.share.enabled` 配置开关（显式开启才调用；缺省 `false`）与 `qq` 块（`napcat_ws_url` / `napcat_token` / `group_id`）；`config.example.json` 已更新
  - 新增依赖 `websocket-client`（`crawler/requirements.txt`）
- **QQ 群机器人（`crawler/scripts/qq_bot.py`）**：常驻轮询 NapCat 群消息记录增量拉取（无需修改上报配置），在群里 **@机器人** 发指令即可查询 daemon 状态 / 即将开始的比赛 / 闹钟概览 / 已归档比赛与复盘状态 / 今日运势（`/status` `/upcoming` `/alarms` `/contests` `/fortune` `/help` + 自然语言关键词）；`daemon.py` 新增 `install-qqbot` / `uninstall-qqbot` 独立自启服务
- **qq-bot 新指令**（`qq_bot.py`）：
  - `/review`（`/rv`）复盘查询：无参数返回最近有复盘的比赛，带关键词搜索并返回摘要（截断 400 字符）
  - `/subs` 订阅管理：列出全部订阅；`/subs add <link> [end=时间] [start=时间] [备注]` 新增（platform 自动推断，写入 `crawler/subscriptions/qqbot.json`；`end=`/`start=` 可选键值，顺序任意，其余 token 拼为备注，时间格式 `ISO 8601 北京时间`）；`/subs del <link>` 删除（从所有订阅文件移除）；改动后后台触发一次 `daemon.py sync` 并在群里回复结果
  - `/subs add` 裸时间自动识别（`qq_bot.py`）：**恰好一个可解析为时间的裸 token**（未带 `end=` 前缀）自动作为 `end_time`——如 `@机器人 /subs add <link> 2026-08-13-20:00:00+08:00` 可省略 `end=`（Python `fromisoformat` 接受 `-` 分隔的 ISO 时间）；多个裸 token 一律当备注、已有 `end=` 时裸 token 不覆盖
  - `/sync` 手动触发一次完整同步（后台执行，完成后群里回复结果）
  - `/subs` 与 `/sync` 仅 `deploy` 分支工作区生效（`PROD_BRANCH` 保护，防止在非生产分支误改订阅）
- **今日运势确定性**（`qq_bot.py`）：`/fortune` 从随机改为按「user_id + 北京日期 + salt」确定性选择（同一天同一人结果一致，跨天变化），新增幸运数字；salt 可配 `config.json` 的 `qq.fortune_salt`（缺省固定值）
- **赛前提醒（`alarm.py remind` + `daemon.py remind`）**：planned 闹钟在比赛开始前 `qq.remind_before_minutes` 分钟（缺省 15）向 QQ 群发【赛前提醒】🏁，发送成功后 `mark --reminded`（失败下轮重试）；订阅可填 `start_time`（未填回退 `end_time - 5h`）；`scheduled` 块新增 `remind`（缺省 `*/5 * * * *`）；`/upcoming` 改用 `start_time` 排序、闹钟显示名优先取 `comments`

### Changed

- **report 与 share 解耦**（`report.py` / `daemon.py`）：`report.py` 不再串联生成 `qq-share.txt`；由 daemon 的 sync/fire 在 report 全部成功后按 `ai_tasks.share.enabled` 单独调用 `qq_share.py --links`
- **review 生成失败阻断归档**（`daemon.py` + `report.py`）：`report.py --links` 任一应生成报告的比赛的 review 生成失败 → 返回非零；sync/fire 据此中止（不 `mark --archived`、不提交推送，下次 sync 重试），避免「已归档但缺复盘」
- **`qq-share.txt` 不进 git**：`.gitignore` / `.gitignore.deploy` 忽略 `contests/*/qq-share.txt`；deploy 分支 `git rm --cached` 清理已跟踪的遗留文件
- **前端 `/log` 日志页弃用删除，改为 `/status` 状态页**（`src/app/(main)/status/`）：日志为运行时噪音（不入库），不再上网页展示；`/status` 展示 deploy 分支入库跟踪的**状态数据**——`crawler/config.json`（平台启用 / 调度 / QQ 配置）、`crawler/last-update.json`（各平台最后更新时间）、各平台 `staged-submissions.json`（待回填提交）、`crawler/subscriptions/` 订阅列表（JSON 渲染 + 复制按钮）。面包屑导航 "Log" → "Status"（图标 `Activity`）；`global.ts` 的 `logFileList` → `statusFileList`
- **移除顶部爬虫状态徽章**（`layout.tsx` + `crawler-status.tsx`）：原右上角 "Updated X ago" + 链接 GitHub Actions 的徽章删除，不再跳外站；更新时间改在 `/status` 页面的 `last-update.json` 中查看
- **gitignore 保持 dev/deploy 双机制**：`.gitignore.deploy` 保留（deploy 分支专用），daemon 提交前 `cp .gitignore.deploy .gitignore` 覆盖；deploy 分支跟踪 `contests/`、`config.json`、`last-update.json`、`platforms/*/contests.json`、`staged-submissions.json`、`subscriptions/`（供 `/status` 展示与 CI 增量同步），仅忽略 log 与运行时临时产物（`daemon.log` / `global.log.json` / `platforms/*/log.json` / `qq-bot.log` / `bot-state.json` / `daemon-state.json` / `alarms.json` / `new-contests.json` / `server-task.log` / `input_*.json` / `qq-share.txt` / chromedriver / `public/contests`）
- **sync 结果摘要回复**（`qq_bot.py`）：`/subs add` / `/subs del` / `/sync` 后台同步完成后，群里回复由「原始日志尾部 8 行」改为**结构化摘要**——待处理分类（历史/过期/重试）、爬取结果（新建/已存在/未开始，未开始给出比赛名）、复盘与分享数、推送状态；失败时给出中止原因（订阅时间格式错误 / 订阅文件格式 / 爬取出错 / 复盘生成失败）与修复提示，不再把原始日志刷到群里（详情仍在服务器 daemon 日志）

### Fixed

- **时间非法的订阅条目不剪除既有闹钟**（`alarm.py`）：`plan` 的时间格式校验跳过条目时未加入 `active_links`，剪除逻辑把该链接的既有闹钟（含 archived / planned）一并删除——用户填错 `end_time`/`start_time` 时虽然 sync 中止不爬取，但闹钟表已被破坏（archived 丢失，修复后该比赛会重爬）。修复：只要订阅里存在该 link 就加入 `active_links`，时间非法仅影响本次分类
- **`alarms.json` 损坏时 plan 中止而非静默重建**（`alarm.py`）：`_load_alarms` 读取失败原返回空 dict，plan 继续把所有闹钟当空表重建——全部 archived 状态丢失、已归档比赛全部重爬。修复：损坏返回 `None`，`cmd_plan` 据此返回非零中止（daemon sync 不爬取不提交），`due`/`remind` 安静跳过、`mark` 报错退出、`list` 提示
- **`cmd_due` 对 fire_at 损坏条目不再当作到期触发**（`alarm.py`）：原 `dt is None or dt <= now` 会把 fire_at 无法解析的 planned 条目当到期触发爬取。修复：解析失败跳过（不触发）；`plan` 在 planned 条目未变时发现 `fire_at != end_time` 顺手修正，避免损坏的 fire_at 永不触发或提前触发
- **移除已跟踪的运行时文件**（`daemon.log` / `daemon-state.json` / `global.log.json` / `platforms/hdu/log.json`）：这些文件在 `.gitignore` / `.gitignore.deploy` 中本就列入忽略，但 deploy 分支早期提交把它们**跟踪**了——gitignore 对已跟踪文件无效，`git add crawler` 会把其改动一起暂存，导致每次 `[auto] [contests-changed]` 提交都夹带运行时日志噪音（其他分支 master/v0.2.x/v0.3.0 均未跟踪）。修复：`git rm --cached` 一次性移除跟踪（工作区文件保留），与 dev 分支行为统一，gitignore 规则此后真正生效；`commit_and_push` 不再需要手动 reset 排除
- **EXPIRED 订阅每次 sync 重爬**（`alarm.py`）：过期比赛（`end_time` 已过）建闹钟条目时未存 `start_time`（null），而 `plan` 的「订阅未变化」比较用 `_effective_start_time(s)`（`end_time - 5h`）——`null != 计算值` 恒成立，archived 条目每次都被重新分类为 EXPIRED，导致同一场比赛每次 sync 都重爬（爬取/报告/分享重复执行）。修复：HISTORY / EXPIRED 分支统一存 `start_time=_effective_start_time(s)`（与 planned 一致），archived 后不再重复触发
- **`commit_and_push` 跳过提交时遗留暂存文件**（`daemon.py`）：`git add .gitignore crawler contests` 会把 crawler 运行时文件（`daemon.log` / `log.json` / 订阅文件等）暂存，发现 contests/ 无变化决定不提交时只 `reset` 了 chromedriver、其余文件留在 index——下一次手动 `git commit` 会把这些运行时文件一并提交。修复：跳过提交前 `git reset` 取消全部暂存
- **daemon 自动提交覆盖开发者 git 身份**（`daemon.py`）：`commit_and_push` 用 `git config` 把 `server-task[bot]` 身份持久写进 `.git/config`，覆盖开发者在仓库配置的 `user.name` / `user.email`——daemon 跑过一次后，后续手动提交全部变成 bot 身份（v0.3.1 的提交即因此显示为 server-task[bot]）。修复：commit 改用 `git -c user.name=... -c user.email=...` 临时指定 bot 身份（仅对单次提交生效），不再写 `.git/config`，开发者身份保持不变
- **订阅时间格式校验**（`qq_bot.py` + `alarm.py` + `daemon.py`）：`/subs add` 的 `end=`/`start=` 时间格式错误 → 终止不写入并提示（给出 `ISO 8601 北京时间` 示例）；手动 `sync` 时 `alarm.py plan` 发现订阅条目时间字段存在但解析失败 → 跳过该条目并输出 `[alarm] ERROR`（汇总行追加 `N invalid time`），`daemon.py sync` 收到非零返回即中止（不爬取不提交），避免把填错时间当 HISTORY 立即爬掉
- **qq-bot 增量游标改用消息 `time`**（`qq_bot.py`）：NapCat 的 `message_seq` / `message_id` 并非全局递增，用作游标会把新消息永久挡掉；改为按非自己消息的 `time` 推进
- **未配置 `QQ_BOT_UID` 时 bot 刷屏**（`qq_bot.py`）：`bot_uid` 为空时无法识别 @，原实现退化为处理所有非自己消息——群聊每条普通消息都会触发「收到！可用 /help」逐条回复，且含关键词（比赛/报告/状态/订阅/运势等）的闲聊会误执行指令。修复：未配置 `bot_uid` 时**只响应明确以 `/` 开头的指令**、未匹配指令静默跳过（普通聊天完全忽略）；`process_once` 按 60s 节流告警提示配置 `.env QQ_BOT_UID`，`process_force` 单次提示

### Removed

- **`report.py --qq-only` 兼容入口**：转调 qq_share.py 的入口已由 qq_share.py 直接提供（`--links` / `--from-crawl` / `<folder>` / 全量扫描）

## [0.3.0] - 2026-08-12

### Added

- **跨平台守护进程 `crawler/scripts/daemon.py`**（替代 v0.2.x 的 `crawler/server-task.sh`）：
  - 子命令 `run` / `sync` / `fire` / `incremental` / `install` / `uninstall` / `status` / `log`；`run` 主循环用 croniter 解析 `config.json` 的 `scheduled` 块调度任务，睡眠/关机恢复后每个任务只补跑一次
  - `install` 按操作系统注册开机自启：Linux systemd user unit、macOS launchd、Windows schtasks（默认「登录时启动」）
  - `install --system`（仅 Linux）：注册系统级 systemd service（`/etc/systemd/system/`，`WantedBy=multi-user.target`），开机即启动、无需登录会话（适合无头服务器）；服务以实际用户身份运行（`User=<owner>`，sudo 时取 `SUDO_USER`），需 root 执行
  - 跨平台串行锁改用 filelock（替代 flock），新增依赖 `croniter` / `filelock`（`crawler/requirements.txt`）
- **fork 部署参数化**：`next.config.ts` 的 `basePath` / `assetPrefix` 与 `global.ts` 的 `REPO_URL` / `BASE_URL` / `PREFIX_URL` 支持 env 覆盖（`NEXT_PUBLIC_BASE_PATH` / `NEXT_PUBLIC_SITE_URL` / `NEXT_PUBLIC_REPO_URL`，默认值不变）

### Changed

- **浏览器驱动路径按平台解析**（`base.py`）：`CHROME_BINARY` / `CHROMEDRIVER_PATH` env 优先，缺省按 `sys.platform` 回落——Linux 用 `crawler/chrome-linux64`、Windows 用 `crawler/chrome-win64`、macOS 用系统 Google Chrome + `crawler/chromedriver-mac*`（glob 匹配）
- **仅 contests/ 有实质更新才提交推送**（`daemon.py`）：无新比赛 / 新提交 / 新报告时不再发 `[auto] Update crawler state` 提交（crawler 状态与日志已在本地文件系统持久化，无需同步远端）；只有 contests/ 变化才提交 `[contests-changed]` 触发部署

### Removed

- **Actions 爬虫链路**：删除 `crawler-scheduled.yml` / `crawler.yml`；`deploy.yml` 去掉 `workflow_run` 监听（保留 `push` 触发）。静态版部署统一为「自托管爬虫 + GitHub Pages」（详见 `docs/roadmap.md` §1.1）。
- **`crawler/server-task.sh`**：由 `crawler/scripts/daemon.py` 替代（cron/`flock` 依赖 Linux 环境，改为跨平台守护进程 + 跨平台自启）。

### Fixed

- **复盘报告触发条件改为订阅 `end_time`**（`daemon.py` 的 sync/fire）：报告条件从「本次爬取新建比赛」（`report.py --from-crawl` + `new-contests.json`）改为「订阅填了 `end_time`」（EXPIRED / RETRY / fire due），按订阅链接反查 `contests/` 生成（`report.py --links`）——比赛此前已归档过（非本次新建）也要生成，避免漏掉复盘。RETRY 按原任务 `end_time` 判断：空 = 原 HISTORY 不生成报告，非空 = 原 EXPIRED/planned 生成报告
- **HTML→Markdown 公式乱码（pandoc 版本差异）**：pandoc 3.1.x（Debian apt 版）会把 KaTeX 视觉 HTML（`span.katex-html`，`aria-hidden`）当普通内容输出，产生 `[[$x$][[[]{.strut...}...]]` 嵌套乱码，而 3.7+ 自动忽略。修复：转换前用 BeautifulSoup 删除 `span.katex-html` / `span.katex-error`（TeX 源码在 `span.katex-mathml` 的 `<annotation>` 里，保留不受影响），使新旧 pandoc 输出一致；顺带修复空 `<div>` 产生的多冒号 `:::::` 容器残留，与 `::: katex-display` 块级公式容器被压成单行的问题
- **`sync` / `fire` 日志不再「爬完才一次性输出」**（`daemon.py`）：两层修复——`run_py` 改为流式转发子进程输出（`Popen` + 逐行 `log_raw`，stderr 并入同一管道避免双管道死锁）；**关键**是给子进程注入 `PYTHONUNBUFFERED=1`（stdout 被重定向到管道时 Python 默认块缓冲，子进程 `print()` 不带 flush 的日志会攒到进程结束才 flush，daemon 流式读取也读不到）——强制无缓冲后每行日志立即到达管道实时转发；`log` / `log_raw` 的 `print` 加 `flush=True`，systemd/journald 场景下实时落盘
- **订阅文件格式有问题时 sync 立刻提示**（`alarm.py` + `daemon.py`）：`plan` 读取订阅时接住 `load_subscriptions_dir` 的 error/warning 诊断（此前 `log=None` 静默跳过），输出 `[alarm] ERROR/WARNING` 与汇总行计数（`subscription diag: N errors, M warnings`），坏文件条目不会同步；`daemon.py` 的 `sync` 转发所有 `[alarm]` 行到日志，用户无需翻日志文件也能在终端/systemd journal 立刻看到

## [0.2.1] - 2026-08-12

### Added

- **服务器闹钟机制（部署方式二专用）**：订阅条目可选填 `end_time`，未来比赛写入闹钟表 `crawler/alarms.json`（gitignore），到点由 `fire` 触发爬取并立即生成复盘报告；方式一（GitHub Actions 轮询）不读取该字段
  - 新增 `crawler/scripts/alarm.py`（`plan` / `due` / `mark` / `list`）与闹钟状态模型 `planned` / `pending` / `archived` / `failed`；爬取失败即 `failed`，由自动 `sync` 重试一次（成功 → `archived`，失败保持 `failed`）
  - `crawler/server-task.sh` 新增 `sync` / `fire` 子命令；`scheduled_task.py` 新增 `--links`（只抓指定订阅链接）；`report.py --from-crawl` 新增 `--links` 过滤

### Changed

- **cron 配置外置到 `crawler/config.json` 的 `scheduled` 块**：`server-task.sh install` 从该块读取表达式生成 crontab（缺失/非法回落默认值），删除硬编码 cron 与时区自动调整逻辑
- **去除「任务A/B」别名**，统一以 `scheduled_task.py` 模式指代：`server-task.sh` 删除 `run [a|b]`，新增 `incremental`（内部调用 `--submissions-only`）

### Fixed

- `deploy.yml` 标记检查误触发（`--pretty=%s` 只取 subject 第一行）
- 自动提交 `[contests-changed]` 标记对中文路径失效（`git -c core.quotepath=false` 三处统一）
- `/log` 页面在日志文件缺失时显示占位提示而非报错
- 静态导出在无可用数据时失败（动态路由统一判空 + 占位参数兜底）

## [0.2.0] - 2026-08-10

### Added

- 平台启用/禁用：`crawler/config.json` 的 `enabled` 字段（缺省禁用），HDU/NowCoder 默认停用
- 爬虫订阅模型：`crawler/subscriptions/` 目录式订阅配置（取代单文件与各平台 `input_contests.json`）
- 全量提交采集：每份提交归档到 `submissions.json` + `problems/<letter>/submissions/<id>.<ext>`，供复盘使用
- 复盘报告：`report.py` 调用 DeepSeek 生成 `review.md`（幂等，存在即跳过）；QQ 群分享简化版 `qq-share.txt`
- 定时任务入口：`scheduled_task.py` 三种模式（默认 / `--contests-only` / `--submissions-only`）；`finish()` 仅在完整同步时推进 `last-update.json`
- deploy 分支专用 `.gitignore.deploy`（竞赛数据与爬虫增量状态纳入版本控制）
- 双定时工作流：`crawler-scheduled.yml` + `crawler.yml`，提交时用 `.gitignore.deploy` 覆盖 `.gitignore`
- 前端：题目标签、搜索页（构建时索引 + 前端过滤）、Dashboard（统计 / 最近动态 / contribution 绿点图 / 复盘报告区）、复盘时间轴页、全局错误边界与加载骨架屏、README 页、历史提交查看路由
- UI 库 shadcn/ui + 图标库 lucide-react（替换 react-icons）
- 新增 `.env.example`（凭据模板）与 `docs/roadmap.md`

### Changed

- 爬虫目录按职责重组（`platforms/`、`scripts/`、`llm/`、`prompts/`），导入统一为完全限定
- 订阅配置改为目录式管理：`crawler/subscriptions/` 下每个 `.json` 一份列表，按文件名合并、重复 `link` 去重、模板文件跳过
- 复盘报告改为 `--from-crawl` 模式（只对本次新建比赛生成）；爬虫与报告解耦（爬虫失败不生成报告，报告失败不阻断部署）
- NowCoder 环境变量统一 `NOWCODER_*`（`NOWCODER_USERNAME` + Cookie）
- 前端：内部路由统一根相对路径 + `next/link`（修复双前缀 404）；URL/格式化工具抽离；文件查看器重构为公共组件；竞赛表格题号动态自适应；响应式布局
- 时间显示统一 `YYYY/MM/DD HH:MM`（北京时间）；内容查看类链接统一新标签页
- 部署方式确认与文档化（方式一 Actions / 方式二自建服务器 / 方式三动态版规划中）

### Fixed

- HDU/NowCoder 提交记录补抓 `problem_id` 字段；补订已完成比赛以 `start_time` 为截止全量回填
- 跨赛季复用题目导致历史提交误归档（提交时间窗口校验，早于比赛开始的提交丢弃）
- 本地爬虫读不到 `.env` 凭据（脚本顶部 `load_dotenv()`）
- `is_logged_in()` 的 `self.username` 无赋值来源；NowCoder 未迁移订阅模型
- 根路径 `/` 404、竞赛列表表格布局、面包屑 Home 不高亮、Markdown 样式缺失（移入根布局全局加载）
- 线上链接双前缀 `/Training-Archive/Training-Archive/...` 404、复盘时间轴 Source 链接 404
- 搜索/最近完成入口误链到代码页（改 `statement.md`/`statement.pdf` 优先）

## [0.1.0] - 2026-01-04

### Added

- 初始化 Next.js 项目与全局布局（导航、页脚、面包屑）
- contest 列表首页（分页、平台徽章、题目状态）、多级文件查看路由、文件查看器（Markdown / PDF / 源码）、日志页面
- QOJ / HDU / NowCoder 三平台爬虫与 `BaseCrawler` 基类、日志清理脚本
- GitHub Actions 工作流：`crawler.yml`（定时抓取自动提交）、`deploy.yml`（构建部署 Pages）

### Changed

- contest / 题目元数据结构重构，统一由 `contest.json` / `problem.json` 描述
- 时间处理统一北京时间；提交耗时改为 `solve_time - start_time`
- 多处样式与布局优化（响应式、悬停效果、平台徽章颜色等）

### Fixed

- 数学公式分隔符正则全局匹配、提交抓取无提交时死循环、分页边界、爬虫退出清理
- 部署工作流 CI 问题（日期格式、pnpm 安装顺序、Node 版本、缓存）

### Removed

- 停止跟踪 contest 数据文件（`contests/`、staged submissions、log、config 等改为运行时生成），移至 deploy 分支跟踪
