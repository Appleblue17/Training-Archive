import fs from "fs";
import path from "path";
import crypto from "crypto";

import { allowedExtensions } from "@/lib/global";
import renderMarkdown from "@/utils/render-markdown";
import { ProtectedContentType, ProtectedPayloadType } from "@/lib/types";

/**
 * 资源保护（服务端，仅构建时/SSR 使用）。
 *
 * 静态站没有运行时服务端，因此这里在**构建时**用全站统一密码派生 AES-256-GCM 密钥，
 * 把受保护比赛的资源加密成密文载荷，由客户端组件解密后展示（见 resource-protection-client.ts）。
 *
 * 是否受保护有两种来源（取并集）：
 *   1. contest.json 的 "protected": true（推荐；爬虫只在新建比赛时写 contest.json，之后不会覆盖）
 *   2. 仓库根目录 protected-contests.json 的中央清单
 *
 * 密码来自环境变量 RESOURCE_PASSWORD（.env / CI secret），不会进入前端产物。
 */

const CONFIG_FILE = "protected-contests.json";
const PASSWORD_ENV = "RESOURCE_PASSWORD";
const ITERATIONS = 100_000;
const KEY_LEN = 32;
const SALT_LEN = 16;
const IV_LEN = 12;

let centralCache: Set<string> | null = null;

/** 中央清单：接受字符串数组或 { "protected": [...] }。 */
export function getCentralProtectedFolders(): Set<string> {
  if (centralCache) return centralCache;
  const result = new Set<string>();
  try {
    const raw = JSON.parse(
      fs.readFileSync(path.join(process.cwd(), CONFIG_FILE), "utf-8"),
    ) as unknown;
    const list = Array.isArray(raw)
      ? raw
      : Array.isArray((raw as { protected?: unknown } | null)?.protected)
        ? ((raw as { protected: unknown[] }).protected as unknown[])
        : [];
    for (const item of list) if (typeof item === "string") result.add(item);
  } catch {
    // 文件缺失或解析失败：视为无中央清单
  }
  centralCache = result;
  return result;
}

/** 单场比赛是否受保护：中央清单 或 contest.json 的 protected: true。 */
export function isProtectedContestFolder(folder: string): boolean {
  if (getCentralProtectedFolders().has(folder)) return true;
  try {
    const p = path.join(process.cwd(), "contests", folder, "contest.json");
    const json = JSON.parse(fs.readFileSync(p, "utf-8")) as { protected?: unknown };
    return json?.protected === true;
  } catch {
    return false;
  }
}

/** 是否配置了全站密码；未配置时受保护页面只显示提示、不渲染内容。 */
export function isProtectionConfigured(): boolean {
  return !!process.env[PASSWORD_ENV];
}

let cachedKey: { password: string; salt: Buffer; key: Buffer } | null = null;

function getDerivedKey(password: string): { salt: Buffer; key: Buffer } {
  if (cachedKey && cachedKey.password === password) return cachedKey;
  const salt = crypto.randomBytes(SALT_LEN);
  const key = crypto.pbkdf2Sync(password, salt, ITERATIONS, KEY_LEN, "sha256");
  cachedKey = { password, salt, key };
  return cachedKey;
}

/** AES-256-GCM 加密文本，返回可直接序列化给客户端的 base64 载荷。 */
export function encryptResource(plaintext: string): ProtectedPayloadType {
  const password = process.env[PASSWORD_ENV];
  if (!password) {
    throw new Error(`${PASSWORD_ENV} 未配置，无法加密受保护资源`);
  }
  const { salt, key } = getDerivedKey(password);
  const iv = crypto.randomBytes(IV_LEN);
  const cipher = crypto.createCipheriv("aes-256-gcm", key, iv);
  const ciphertext = Buffer.concat([cipher.update(plaintext, "utf8"), cipher.final()]);
  const tag = cipher.getAuthTag();
  return {
    v: 1,
    alg: "AES-256-GCM",
    iter: ITERATIONS,
    salt: salt.toString("base64"),
    iv: iv.toString("base64"),
    // WebCrypto 约定：密文 || tag
    data: Buffer.concat([ciphertext, tag]).toString("base64"),
  };
}

const MIME_BY_EXT: Record<string, string> = {
  ".pdf": "application/pdf",
  ".txt": "text/plain;charset=utf-8",
  ".json": "application/json",
  ".html": "text/html;charset=utf-8",
  ".css": "text/css;charset=utf-8",
  ".xml": "application/xml",
};

/**
 * 读取文件并构造受保护内容。markdown 在构建时预渲染为 HTML，
 * 客户端解密后直接注入，无需把 unified 流水线打包进浏览器。
 */
export async function buildProtectedContent(
  filePath: string,
  dirPathForMarkdown: string,
): Promise<ProtectedContentType> {
  const ext = path.extname(filePath).toLowerCase();
  if (ext === ".md") {
    const raw = fs.readFileSync(filePath, "utf-8");
    const html = await renderMarkdown(raw, dirPathForMarkdown);
    return { kind: "markdown", raw, html };
  }
  if (ext === ".pdf") {
    return {
      kind: "pdf",
      base64: fs.readFileSync(filePath).toString("base64"),
      mime: "application/pdf",
    };
  }
  if (allowedExtensions.includes(ext)) {
    return { kind: "source", raw: fs.readFileSync(filePath, "utf-8") };
  }
  return {
    kind: "other",
    base64: fs.readFileSync(filePath).toString("base64"),
    mime: MIME_BY_EXT[ext] ?? "application/octet-stream",
  };
}
