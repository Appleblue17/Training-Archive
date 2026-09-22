#!/usr/bin/env node
/**
 * 把 contests/ 复制到 public/contests/，但**排除受保护比赛**：
 * 受保护资源在构建时加密进页面，不发布明文原始文件（Raw File/Download 改走客户端解密 Blob）。
 *
 * 供 pnpm build / pnpm dev 之前调用，替代原先 deploy.yml 里的 cp -r。
 */
import fs from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";

import { getProtectedContestFolders } from "./lib/protected-contests.mjs";

const repoRoot = path.resolve(path.dirname(fileURLToPath(import.meta.url)), "..");
const contestsDir = path.join(repoRoot, "contests");
const publicDir = path.join(repoRoot, "public", "contests");

const protectedFolders = getProtectedContestFolders(repoRoot);

// public/contests 是构建产物（已 gitignore），每次重建，避免残留旧明文。
fs.rmSync(publicDir, { recursive: true, force: true });
fs.mkdirSync(publicDir, { recursive: true });

let copied = 0;
if (fs.existsSync(contestsDir)) {
  for (const entry of fs.readdirSync(contestsDir)) {
    const src = path.join(contestsDir, entry);
    if (!fs.statSync(src).isDirectory()) continue;
    if (protectedFolders.has(entry)) {
      console.log(`[public-contests] skip protected: ${entry}`);
      continue;
    }
    fs.cpSync(src, path.join(publicDir, entry), { recursive: true });
    copied += 1;
  }
}

console.log(
  `[public-contests] copied ${copied} contests (protected skipped: ${protectedFolders.size})`,
);
