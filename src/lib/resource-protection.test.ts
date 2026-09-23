// @vitest-environment node
import { afterEach, describe, expect, it, vi } from "vitest";

// 避免加载完整 unified 渲染流水线（resource-protection 仅为构建 markdown 而 import）。
vi.mock("@/utils/render-markdown", () => ({ default: async () => "" }));

import { encryptResource, isProtectionConfigured } from "@/lib/resource-protection";
import { decryptPayload } from "@/lib/resource-protection-client";

const ORIGINAL = process.env.RESOURCE_PASSWORD;

afterEach(() => {
  if (ORIGINAL === undefined) delete process.env.RESOURCE_PASSWORD;
  else process.env.RESOURCE_PASSWORD = ORIGINAL;
});

describe("resource-protection", () => {
  it("服务端加密的载荷可被客户端 WebCrypto 解密（往返一致）", async () => {
    process.env.RESOURCE_PASSWORD = "correct horse battery staple";
    const plaintext = JSON.stringify({ hello: "世界", n: 42 });
    const payload = encryptResource(plaintext);
    expect(payload.alg).toBe("AES-256-GCM");
    expect(payload.v).toBe(1);
    await expect(decryptPayload(payload, "correct horse battery staple")).resolves.toBe(plaintext);
  });

  it("错误密码解密失败", async () => {
    process.env.RESOURCE_PASSWORD = "pw";
    const payload = encryptResource("secret");
    await expect(decryptPayload(payload, "wrong")).rejects.toThrow();
  });

  it("未配置密码时不视为已配置且加密抛错", () => {
    delete process.env.RESOURCE_PASSWORD;
    expect(isProtectionConfigured()).toBe(false);
    expect(() => encryptResource("x")).toThrow(/RESOURCE_PASSWORD/);
  });
});
