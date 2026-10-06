# 发布检查清单

> 适用于静态版预发布 / 正式发布。以 `v1.0.0-beta.1` 为例；发布前逐项勾选。

## 0. 前置：测试通过

- [ ] Linux / Windows 按 [docs/e2e-testing.md](e2e-testing.md) 测完，结果记入附录 A 与第 9 节模板
- [ ] CI 全绿：`Crawler Tests`（`pytest` + `e2e-offline`，ubuntu + windows）、`Frontend Tests`（lint + tsc + vitest）
- [ ] 本地 `pnpm build` 成功（需要 `contests/` 数据）

## 1. 版本与文档

- [ ] `docs/CHANGELOG.md`：`[Unreleased]` → `[1.0.0-beta.1] - <发布日期>`
- [ ] `package.json` 的 `version` → `1.0.0-beta.1`
- [ ] `docs/notes.md` / `docs/roadmap.md` 更新当前状态与遗留项

## 2. 清理本地测试残留（均已 gitignore，不入提交）

- [ ] `.e2e/`（E2E 沙箱与报告）
- [ ] `crawler/config.json`、`crawler/subscriptions/test-platforms.json` 等本机测试配置
- [ ] `contests/` 下的测试比赛目录（**勿动真实比赛数据**）
- [ ] `git status` 干净

## 3. 合并与打 tag

- [ ] 分支推送到 origin（HTTPS + `gh auth git-credential`；SSH 在当前沙箱不可用）
- [ ] 开 PR → review → 合并到 `master`
- [ ] 在 `master` 上打 tag `v1.0.0-beta.1` 并推送 tag

## 4. GitHub Release

- [ ] 从 `docs/CHANGELOG.md` 的 `[1.0.0-beta.1]` 段落生成 Release note
- [ ] 勾选 **Pre-release**（beta）
- [ ] 标题 `v1.0.0-beta.1`

## 5. 部署

- [ ] 同步 `deploy` 分支（合并 `master` 或推送数据）
- [ ] GitHub Actions → Deploy to GitHub Pages → Run workflow（`workflow_dispatch`），或向 `deploy` 推送带 `[contests-changed]` 的提交
- [ ] 验证线上 URL 正常

## 说明

- 静态版默认分支 `master`；`deploy` 分支托管比赛数据并触发 Pages 部署（带 `[contests-changed]` 标记的提交才触发，`workflow_dispatch` 无条件部署）。
- 自托管爬虫守护进程统一用 `.venv/bin/python crawler/scripts/daemon.py ...`；QOJ 反爬需 `xvfb-run -a env CHROME_HEADLESS=0`。
