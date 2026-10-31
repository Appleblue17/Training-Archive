"use client";

import { ProtectedPayloadType } from "@/lib/types";

/**
 * 资源保护（浏览器端）。
 * 用用户输入的密码派生密钥，解密服务端构建时生成的密文载荷。
 * 验证成功后把密码记在 localStorage（"输入一次后记住已验证状态"）。
 */

const STORAGE_KEY = "training-archive:resource-password";

function base64ToBytes(b64: string): Uint8Array {
  const bin = atob(b64);
  const bytes = new Uint8Array(bin.length);
  for (let i = 0; i < bin.length; i++) bytes[i] = bin.charCodeAt(i);
  return bytes;
}

async function deriveKey(
  password: string,
  salt: Uint8Array,
  iterations: number,
): Promise<CryptoKey> {
  const baseKey = await crypto.subtle.importKey(
    "raw",
    new TextEncoder().encode(password),
    "PBKDF2",
    false,
    ["deriveKey"],
  );
  return crypto.subtle.deriveKey(
    { name: "PBKDF2", salt, iterations, hash: "SHA-256" },
    baseKey,
    { name: "AES-GCM", length: 256 },
    false,
    ["decrypt"],
  );
}

/** 用密码解密载荷，返回 UTF-8 明文；密码错误时抛错。 */
export async function decryptPayload(
  payload: ProtectedPayloadType,
  password: string,
): Promise<string> {
  const key = await deriveKey(password, base64ToBytes(payload.salt), payload.iter);
  const plain = await crypto.subtle.decrypt(
    { name: "AES-GCM", iv: base64ToBytes(payload.iv), tagLength: 128 },
    key,
    base64ToBytes(payload.data),
  );
  return new TextDecoder().decode(plain);
}

export function getStoredPassword(): string | null {
  try {
    return typeof localStorage === "undefined" ? null : localStorage.getItem(STORAGE_KEY);
  } catch {
    return null;
  }
}

export function storePassword(password: string): void {
  try {
    localStorage.setItem(STORAGE_KEY, password);
  } catch {
    // 隐私模式等无法写入：忽略，本次会话内仍可查看
  }
}

export function clearStoredPassword(): void {
  try {
    localStorage.removeItem(STORAGE_KEY);
  } catch {
    // ignore
  }
}
