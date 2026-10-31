import { render, screen } from "@testing-library/react";
import userEvent from "@testing-library/user-event";
import { afterEach, beforeEach, describe, expect, it } from "vitest";

import ResourceGate from "@/components/resource-gate";
import { storePassword } from "@/lib/resource-protection-client";
import type { ProtectedPayloadType } from "@/lib/types";

const PASSWORD = "correct horse battery staple";

/** 用 Node 加密构造与构建时相同格式的载荷，避免依赖服务端模块。 */
async function makePayload(plaintext: string, password: string): Promise<ProtectedPayloadType> {
  const { createCipheriv, pbkdf2Sync, randomBytes } = await import("node:crypto");
  const salt = randomBytes(16);
  const iv = randomBytes(12);
  const key = pbkdf2Sync(password, salt, 100_000, 32, "sha256");
  const cipher = createCipheriv("aes-256-gcm", key, iv);
  const ciphertext = Buffer.concat([cipher.update(plaintext, "utf8"), cipher.final()]);
  return {
    v: 1,
    alg: "AES-256-GCM",
    iter: 100_000,
    salt: salt.toString("base64"),
    iv: iv.toString("base64"),
    data: Buffer.concat([ciphertext, cipher.getAuthTag()]).toString("base64"),
  };
}

beforeEach(() => localStorage.clear());
afterEach(() => localStorage.clear());

describe("ResourceGate", () => {
  it("未记住密码时显示密码输入框", async () => {
    const payload = await makePayload("hello", PASSWORD);
    render(<ResourceGate payload={payload}>{() => <p>SECRET</p>}</ResourceGate>);
    expect(await screen.findByText("受保护内容")).toBeInTheDocument();
    expect(screen.queryByText("SECRET")).toBeNull();
  });

  it("记住的密码正确时自动解锁", async () => {
    const payload = await makePayload("hello", PASSWORD);
    storePassword(PASSWORD);
    render(<ResourceGate payload={payload}>{() => <p>SECRET</p>}</ResourceGate>);
    expect(await screen.findByText("SECRET")).toBeInTheDocument();
    expect(screen.queryByText("受保护内容")).toBeNull();
  });

  it("密码错误时提示重试", async () => {
    const user = userEvent.setup();
    const payload = await makePayload("hello", PASSWORD);
    render(<ResourceGate payload={payload}>{() => <p>SECRET</p>}</ResourceGate>);
    await screen.findByText("受保护内容");

    await user.type(screen.getByLabelText("全站密码"), "wrong-password");
    await user.click(screen.getByRole("button", { name: "解锁" }));

    expect(await screen.findByText("密码错误，请重试。")).toBeInTheDocument();
    expect(screen.queryByText("SECRET")).toBeNull();
  });
});
