"use client";

import { Lock, LockOpen } from "lucide-react";
import { FormEvent, ReactNode, useEffect, useState } from "react";

import { ProtectedPayloadType } from "@/lib/types";
import {
  clearStoredPassword,
  decryptPayload,
  getStoredPassword,
  storePassword,
} from "@/lib/resource-protection-client";

/**
 * 受保护资源门禁：先尝试用 localStorage 里记住的密码自动解密（"已验证过"状态），
 * 失败或没有则显示密码输入框；验证成功后存下密码并渲染内容。
 */
export default function ResourceGate({
  payload,
  children,
}: {
  payload: ProtectedPayloadType;
  /** 解密成功后的明文（通常是 JSON 字符串），由调用方解析并渲染。 */
  children: (plaintext: string) => ReactNode;
}) {
  const [status, setStatus] = useState<"checking" | "locked" | "unlocked">("checking");
  const [plaintext, setPlaintext] = useState<string | null>(null);
  const [password, setPassword] = useState("");
  const [error, setError] = useState<string | null>(null);
  const [submitting, setSubmitting] = useState(false);

  useEffect(() => {
    let cancelled = false;
    const stored = getStoredPassword();
    if (!stored) {
      setStatus("locked");
      return;
    }
    decryptPayload(payload, stored)
      .then((text) => {
        if (cancelled) return;
        setPlaintext(text);
        setStatus("unlocked");
      })
      .catch(() => {
        if (cancelled) return;
        // 记住的密码已失效（例如全站密码已更换）
        clearStoredPassword();
        setStatus("locked");
      });
    return () => {
      cancelled = true;
    };
  }, [payload]);

  async function handleSubmit(e: FormEvent<HTMLFormElement>) {
    e.preventDefault();
    if (!password || submitting) return;
    setSubmitting(true);
    setError(null);
    try {
      const text = await decryptPayload(payload, password);
      storePassword(password);
      setPlaintext(text);
      setStatus("unlocked");
    } catch {
      setError("密码错误，请重试。");
    } finally {
      setSubmitting(false);
    }
  }

  if (status === "checking") {
    return (
      <div className="flex min-h-[50vh] items-center justify-center text-gray-400">
        正在验证…
      </div>
    );
  }

  if (status === "unlocked" && plaintext !== null) {
    return (
      <>
        {children(plaintext)}
        <button
          type="button"
          onClick={() => {
            clearStoredPassword();
            window.location.reload();
          }}
          className="fixed bottom-4 right-4 z-50 inline-flex items-center gap-1 rounded-full border border-gray-600 bg-gray-800/90 px-3 py-1.5 text-xs text-gray-300 shadow-lg transition-colors hover:bg-gray-700"
          title="清除本浏览器记住的密码"
        >
          <LockOpen className="size-3.5" />
          锁定
        </button>
      </>
    );
  }

  return (
    <div className="flex min-h-[60vh] items-center justify-center py-8">
      <form
        onSubmit={handleSubmit}
        className="w-full max-w-md rounded-lg border border-gray-700 bg-gray-800/60 p-6"
      >
        <div className="mb-3 flex items-center gap-2 text-slate-100">
          <Lock className="size-5" />
          <h2 className="text-lg font-semibold">受保护内容</h2>
        </div>
        <p className="mb-4 text-sm text-gray-400">
          该比赛资源需要密码才能查看。验证一次后，本浏览器会记住已验证状态。
        </p>
        <label className="mb-1 block text-sm text-gray-300" htmlFor="resource-password">
          全站密码
        </label>
        <input
          id="resource-password"
          type="password"
          autoFocus
          value={password}
          onChange={(e) => setPassword(e.target.value)}
          className="w-full rounded border border-gray-600 bg-gray-900 px-3 py-2 text-slate-100 outline-none focus:border-blue-500"
          placeholder="请输入密码"
        />
        {error && <p className="mt-2 text-sm text-red-400">{error}</p>}
        <button
          type="submit"
          disabled={submitting || !password}
          className="mt-4 w-full rounded bg-blue-700 px-3 py-2 text-white transition-colors hover:bg-blue-600 disabled:pointer-events-none disabled:opacity-50"
        >
          {submitting ? "验证中…" : "解锁"}
        </button>
      </form>
    </div>
  );
}
