/**
 * 构建脚本共用的「受保护比赛」判定（与 src/lib/resource-protection.ts 保持一致）。
 * 来源（并集）：contest.json 的 protected: true，或仓库根 protected-contests.json 清单。
 */
import fs from "node:fs";
import path from "node:path";

const CONFIG_FILE = "protected-contests.json";

export function getCentralProtectedFolders(repoRoot) {
  const result = new Set();
  try {
    const raw = JSON.parse(fs.readFileSync(path.join(repoRoot, CONFIG_FILE), "utf-8"));
    const list = Array.isArray(raw) ? raw : Array.isArray(raw?.protected) ? raw.protected : [];
    for (const item of list) if (typeof item === "string") result.add(item);
  } catch {
    // 文件缺失或解析失败：视为无中央清单
  }
  return result;
}

export function isProtectedContestFolder(repoRoot, folder) {
  if (getCentralProtectedFolders(repoRoot).has(folder)) return true;
  try {
    const json = JSON.parse(
      fs.readFileSync(path.join(repoRoot, "contests", folder, "contest.json"), "utf-8"),
    );
    return json?.protected === true;
  } catch {
    return false;
  }
}

/** 扫描 contests/，返回所有受保护比赛文件夹名。 */
export function getProtectedContestFolders(repoRoot) {
  const contestsDir = path.join(repoRoot, "contests");
  const result = new Set();
  if (!fs.existsSync(contestsDir)) return result;
  for (const folder of fs.readdirSync(contestsDir)) {
    const p = path.join(contestsDir, folder);
    if (!fs.statSync(p).isDirectory()) continue;
    if (isProtectedContestFolder(repoRoot, folder)) result.add(folder);
  }
  return result;
}
