#!/usr/bin/env bash
# ==============================================================================
# server-task.sh — 自建服务器爬虫任务管理脚本（部署方式二）
#
# 复刻 GitHub Actions（crawler-scheduled.yml / crawler.yml）的完整流程：
#   git pull deploy 分支 → 运行爬虫任务 → 生成复盘报告 → 清理日志 →
#   提交推送（[contests-changed] 规则）→ GitHub Actions 的 deploy.yml 自动部署 Pages
#
# 用法:
#   server-task.sh run [a|b]    手动运行一次任务（a=任务A查订阅/新建比赛[默认]，b=任务B仅提交同步）
#   server-task.sh install      安装 cron 定时（任务A 每 30 分钟 + 任务B 每日）
#   server-task.sh uninstall    卸载 cron 定时
#   server-task.sh status       查看 cron / git / 最近日志
#   server-task.sh log [N]      查看最近 N 行运行日志（默认 50）
#   server-task.sh --help       显示本帮助
#
# 环境要求:
#   - 已 clone 本仓库，脚本会强制切到 deploy 分支并 pull
#   - 仓库根目录存在 .env（凭据；已被 gitignore，不会提交）
#   - Python 依赖已安装（pip install -r crawler/requirements.txt）
#   - Chrome / Chromedriver 位于 crawler/chrome-linux64/ 与
#     crawler/chromedriver-linux64/（crawler/platforms/base.py 本地模式的默认路径）
#   - push 到 GitHub 的凭据已配置（SSH key 或 token）
# ==============================================================================
set -euo pipefail

# cron 环境下 PATH 精简，补充常见路径
export PATH="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(dirname "$SCRIPT_DIR")"
LOG_FILE="$SCRIPT_DIR/server-task.log"
LOCK_FILE="/tmp/training-archive-server-task.lock"
DEPLOY_BRANCH="deploy"

# cron 按服务器本地时区执行。
# 任务 B 对应 action 的每日 0:20 UTC（北京时间 4:00）；install 时会按
# 服务器时区自动调整：UTC → 0 20 * * *，其他（如 CST）→ 0 4 * * *。
CRON_A='*/30 * * * *'
CRON_B='0 4 * * *'

log() { echo "[$(date '+%Y-%m-%d %H:%M:%S')] $*" | tee -a "$LOG_FILE"; }

pick_python() {
  for p in \
    "$REPO_ROOT/.venv/bin/python3" "$REPO_ROOT/venv/bin/python3" \
    "$REPO_ROOT/.venv/bin/python" "$REPO_ROOT/venv/bin/python"; do
    [ -x "$p" ] && { echo "$p"; return; }
  done
  command -v python3 || command -v python
}

# 提交并推送（复刻 action 的提交逻辑：contests/ 变化带 [contests-changed] 标记）
commit_and_push() {
  git config user.name  >/dev/null 2>&1 || git config user.name  "server-task[bot]"
  git config user.email >/dev/null 2>&1 || git config user.email "server-task[bot]@users.noreply.github.com"

  # deploy 分支使用专用 gitignore：contests/ 与爬虫增量状态纳入版本控制，
  # 保证增量同步跨运行生效。
  cp .gitignore.deploy .gitignore
  git add .gitignore crawler contests
  git reset HEAD crawler/chromedriver-linux64/chromedriver 2>/dev/null || true
  git diff --cached --stat | tee -a "$LOG_FILE"

  if git diff --cached --quiet; then
    log "No changes to commit."
    return 0
  fi

  if git diff --cached --name-only | grep -q '^contests/'; then
    git commit -m "[auto] [contests-changed] Update contest and submission data"
  else
    # 只有爬虫状态变化（如 last-update 推进）时也提交，但不带标记，
    # 避免触发 deploy。
    git commit -m "[auto] Update crawler state"
  fi
  git push origin "$DEPLOY_BRANCH"
  log "Pushed to $DEPLOY_BRANCH."
}

# ---------------------------------------------------------------------------
# 子命令：run
# ---------------------------------------------------------------------------
cmd_run() {
  local mode="${1:-a}"
  exec 9>"$LOCK_FILE"
  if ! flock -n 9; then
    log "Another task is already running, skip this run." >&2
    exit 1
  fi

  log "=== run (task ${mode}) ==="
  cd "$REPO_ROOT"

  # 1. 同步 deploy 分支
  if ! git rev-parse --verify "$DEPLOY_BRANCH" >/dev/null 2>&1; then
    log "Branch '$DEPLOY_BRANCH' not found. Create it first (e.g. from main)." >&2
    exit 1
  fi
  git checkout "$DEPLOY_BRANCH" >/dev/null 2>&1 || { log "Failed to checkout $DEPLOY_BRANCH." >&2; exit 1; }
  git pull --ff-only origin "$DEPLOY_BRANCH" 2>&1 | tee -a "$LOG_FILE" || true

  # 2. 环境：加载 .env 凭据（cron 不继承 shell 环境）
  if [ -f .env ]; then
    set -a; source .env; set +a
  else
    log "[WARN] .env not found; platform logins may fail." >&2
  fi
  export TZ=Asia/Shanghai PYTHONUNBUFFERED=1
  local PY
  PY="$(pick_python)"
  log "Using python: $PY"
  if ! "$PY" -c "import undetected_chromedriver" >/dev/null 2>&1; then
    log "Missing Python dependencies. Run: pip install -r crawler/requirements.txt" >&2
    exit 1
  fi

  # 3. 运行爬虫任务（与 action 一致：失败即中止，不提交推送）
  #    a=--contests-only：只查订阅/新建比赛，有新建才回填其提交（高频触发保持轻量）
  #    b=--submissions-only：每日增量提交同步
  if [ "$mode" = "b" ]; then
    "$PY" crawler/scripts/scheduled_task.py --submissions-only
  else
    "$PY" crawler/scripts/scheduled_task.py --contests-only
  fi

  # 4. 复盘报告（独立于爬虫；只对本次爬取新建的比赛生成，失败仅告警，不阻断数据上线）
  "$PY" crawler/scripts/report.py --from-crawl || log "[WARN] report.py failed (skipped review generation)."

  # 5. 清理日志
  "$PY" crawler/scripts/clean-log.py || true

  # 6. 提交推送
  commit_and_push

  log "=== done (task ${mode}) ==="
}

# ---------------------------------------------------------------------------
# 子命令：install / uninstall（cron 定时）
# ---------------------------------------------------------------------------
cmd_install() {
  local tz
  tz="$(date +%Z)"
  if [ "$tz" = "UTC" ]; then
    CRON_B='0 20 * * *'
  fi
  cmd_uninstall >/dev/null 2>&1 || true
  (
    crontab -l 2>/dev/null || true
    echo "$CRON_A cd $REPO_ROOT && $SCRIPT_DIR/server-task.sh run a >> $LOG_FILE 2>&1"
    echo "$CRON_B cd $REPO_ROOT && $SCRIPT_DIR/server-task.sh run b >> $LOG_FILE 2>&1"
  ) | crontab -
  log "Installed cron (server TZ=$tz):"
  crontab -l | grep 'server-task.sh'
}

cmd_uninstall() {
  crontab -l 2>/dev/null | grep -v 'server-task.sh' | crontab - || true
  log "Removed server-task cron entries."
}

# ---------------------------------------------------------------------------
# 子命令：status / log
# ---------------------------------------------------------------------------
cmd_status() {
  echo "== cron =="
  crontab -l 2>/dev/null | grep 'server-task.sh' || echo "(none)"
  echo
  echo "== git =="
  git -C "$REPO_ROOT" branch --show-current
  git -C "$REPO_ROOT" status -sb | head -3
  echo
  echo "== last runs =="
  tail -n 20 "$LOG_FILE" 2>/dev/null || echo "(no log yet)"
}

cmd_log() {
  if [ -f "$LOG_FILE" ]; then
    tail -n "${1:-50}" "$LOG_FILE"
  else
    echo "(no log yet)"
  fi
}

cmd_help() {
  sed -n '2,20p' "$0" | sed 's/^# \{0,1\}//'
}

# ---------------------------------------------------------------------------
case "${1:-}" in
  run)        cmd_run "${2:-a}" ;;
  install)    cmd_install ;;
  uninstall)  cmd_uninstall ;;
  status)     cmd_status ;;
  log)        cmd_log "${2:-50}" ;;
  --help|-h)  cmd_help ;;
  *)          echo "Usage: $0 {run [a|b]|install|uninstall|status|log [N]|--help}" >&2; exit 1 ;;
esac
