import "@testing-library/jest-dom/vitest";
import { webcrypto } from "node:crypto";
import { vi } from "vitest";

// jsdom 的 crypto 缺少 subtle；资源保护端到端解密需要 WebCrypto。
vi.stubGlobal("crypto", webcrypto);
