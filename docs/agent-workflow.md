# Agent 工作流规范

> 本文档定义 AI Agent 在开发本项目时应遵循的工作流程、代码规范、环境配置、文档更新和汇报要求。

---

## 1. 核心原则

1. **保持文档新鲜**：修改代码前或造成更改后，及时更新相关文档
2. **代码可维护**：遵循代码规范，确保代码清晰、易读、易维护
3. **变更可追溯**：所有重要变更记录在 `docs/CHANGELOG.md`
4. **及时沟通**：遇到问题时，及时与用户沟通并寻求帮助
5. **持续集成**：确保代码质量，通过自动化测试和检查
6. **决策有记录**：重要技术决策及其理由记录在 `docs/architecture.md`，便于后续查阅

---

## 2. 环境与构建

### 前端（Next.js / TypeScript）

| 项目 | 说明 |
|------|------|
| 包管理器 | pnpm（Node.js ≥ 20，registry 使用 npmmirror，见 `.npmrc`） |
| 开发模式 | `pnpm dev`（Next.js dev server，默认 http://localhost:3000） |
| 生产构建 | `pnpm build`（`NODE_ENV=production` 时静态导出到 `out/`） |
| 代码检查 | `pnpm lint`（ESLint + `next/core-web-vitals`、`next/typescript`） |
| 格式化 | Prettier（`.prettierrc`，含 `prettier-plugin-tailwindcss`） |

> 生产构建依赖本地 `contests/` 数据目录（部署时由 `deploy.yml` 复制到 `public/contests/`）。

### 爬虫（Python）

| 项目 | 说明 |
|------|------|
| 依赖安装 | `pip install -r crawler/requirements.txt`（undetected_chromedriver、bs4） |
| 运行 | `python3 crawler/scripts/scheduled_task.py`（三种模式） |
| 凭据/环境 | 平台账号密码、浏览器路径等通过环境变量或 `crawler/config.json` 提供，见 `crawler/scripts/daemon.py` 与 `.env.example` |

### 自动化（GitHub Actions）

- `deploy.yml`：部署工作流，构建并发布到 GitHub Pages（自托管爬虫 push `[contests-changed]` 提交到 `deploy` 分支触发）

---

## 3. 文档体系

| 文档 | 职责 |
|------|------|
| `README.md` | 项目简介、快速开始、文档索引（写给用户） |
| `docs/CHANGELOG.md` | 所有重要变更日志（Keep a Changelog 格式） |
| `docs/architecture.md` | 架构设计、硬件连接、组件职责、技术决策记录（相对稳定） |
| `docs/roadmap.md` | 版本规划、功能分级、路线图与决策记录 |
| `docs/notes.md` | 开发笔记：进度、待办、注意事项（高时效，频繁更新） |
| `docs/agent-workflow.md` | Agent 工作流规范（本文档） |

---

## 4. 开发流程

### 4.1 标准工作流

1. 阅读相关文档和项目代码，理解任务需求和设计。如有不清晰或待决策的地方，及时向用户提出与讨论。
2. 将新添加或修改的功能记录更新至文档中，以便后续查阅。
3. 拟订开发计划，明确任务的开发顺序和依赖关系。
4. 按照开发计划，逐步实现功能模块，并在每个阶段完成后进行测试和汇报。
5. 同步编写单元测试和集成测试，确保代码质量和功能正确性。
6. 功能实现后，让用户进行验收和测试，确保功能符合预期。
7. 在用户验收通过后，将实际开发时进行的变更记录至文档。
8. 按用户指令进行 commit 或 branch merge，并更新 `docs/CHANGELOG.md`。

### 4.2 代码规范

#### 通用

| 项目 | 要求 |
|------|------|
| 代码检查 | 提交前必须通过 `pnpm lint`；禁止跳过 lint |
| 格式化 | 遵循 Prettier 配置（`.prettierrc`） |
| 语言 | 提交信息统一使用英文；代码内注释可使用中文 |

#### 前端（TypeScript / React / Next.js）

| 项目 | 要求 |
|------|------|
| 文件命名 | 组件/页面文件使用 PascalCase（如 `contest-table.tsx`、`file-viewer.tsx`）；工具函数文件使用 camelCase |
| 函数/变量 | camelCase（如 `getFileMetadata`、`pageNum`） |
| 常量/配置 | `UPPER_SNAKE_CASE`（如 `BASE_URL`、`ITEMS_PER_PAGE`、`allowedExtensions`） |
| 类型定义 | PascalCase 并以 `Type` 结尾，统一维护于 `src/lib/types.ts`（如 `ContestInfoType`） |
| 路径别名 | 使用 `@/` 指向 `src/`，禁止深层相对路径 |
| UI 库 | 组件优先使用 shadcn/ui（Radix + Tailwind），新增组件通过其 CLI 或按现有约定复制到 `src/components/ui/` |
| 图标库 | 统一使用 `lucide-react`；**禁止新增 `react-icons` 引入**（存量迁移见 `docs/roadmap.md`） |
| 数据来源 | 静态数据通过 `fs` 读取 `contests/` 目录与 `*.json` 元数据；URL 统一走 `src/lib/global.ts` 的 `BASE_URL` / `PREFIX_URL` |
| 组件划分 | 页面逻辑与展示组件分离（如 `(home)/[page]/page.tsx` 负责取数，`contest-table.tsx` 负责渲染） |

#### 爬虫（Python）

| 项目 | 要求 |
|------|------|
| 命名 | 函数/变量：`snake_case`；类：PascalCase；常量：`UPPER_SNAKE_CASE` |
| 模块组织 | 每个平台一个模块（`crawler/platforms/<platform>/<platform>.py`），公共逻辑放 `crawler/platforms/base.py`（`BaseCrawler`） |
| 类型注解 | 函数签名尽量标注参数与返回值类型 |
| 日志 | 统一使用 `BaseCrawler.log()`，写入平台日志与 `crawler/global.log.json` |
| 时间 | 统一使用北京时间（`crawler/platforms/base.py` 中定义的 `beijing` 时区） |
| 凭据 | 账号密码通过环境变量或 `crawler/config.json` 提供，禁止硬编码到源码 |

### 4.3 文档更新要求

| 变更类型 | 需更新的文档 |
|----------|--------------|
| 技术实现变更 | `docs/architecture.md` |
| 进度/待办/注意事项变化 | `docs/notes.md` |
| 重要变更 | `docs/CHANGELOG.md` |
| 接口/依赖变化 | `README.md`、`docs/architecture.md` |

### 4.4 Git 提交规范

```
[<type>](<optional-scope>): <subject>

[optional-body]

[optional-footer]
```

**type**：
- `feat`: 新功能
- `fix`: Bug 修复
- `docs`: 文档更新
- `test`: 测试相关
- `refactor`: 重构
- `perf`: 性能优化
- `build`: 构建系统或外部依赖变更
- `ci`: CI 配置与脚本变更
- `chore`: 杂项（工具配置、清理等）

> 历史提交中使用过 `[update]`、`[clean]`、`[optimize]`、`[feature]` 等标签，新提交统一按上述 type 归类。

**语言**：统一使用中文，除非涉及技术名词或外部依赖

**示例**：`feat(article): add publish API with review option`

> 提交由 AI Agent 生成时，需附带 `Generated with Continue` 的 co-author 信息。
