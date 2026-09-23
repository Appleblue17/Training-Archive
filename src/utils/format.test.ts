import { describe, expect, it } from "vitest";

import { formatDate, formatDateTime, formatKey, formatSize } from "@/utils/format";

describe("formatKey", () => {
  it("下划线转空格并首字母大写", () => {
    expect(formatKey("solve_time")).toBe("Solve Time");
    expect(formatKey("name")).toBe("Name");
  });
});

describe("formatSize", () => {
  it("按大小分级输出单位", () => {
    expect(formatSize(0)).toBe("0 B");
    expect(formatSize(512)).toBe("512 B");
    expect(formatSize(2048)).toBe("2.000 KB (2048 B)");
    expect(formatSize(1024 * 100)).toBe("100.00 KB");
    expect(formatSize(1024 * 1024 * 2)).toBe("2.00 MB");
  });
});

describe("formatDate / formatDateTime", () => {
  it("按北京时间输出（UTC 跨日）", () => {
    // 2026-01-01T00:00:00Z = 北京时间 2026/01/01 08:00
    expect(formatDateTime("2026-01-01T00:00:00Z")).toBe("2026/01/01 08:00");
    // 2026-01-01T16:30:00Z = 北京时间 2026/01/02 00:30
    expect(formatDateTime("2026-01-01T16:30:00Z")).toBe("2026/01/02 00:30");
  });

  it("formatDate 带秒", () => {
    expect(formatDate("2026-01-01T00:00:00Z")).toBe("2026/01/01 08:00:00");
  });

  it("非法值原样返回", () => {
    expect(formatDate("not-a-date")).toBe("not-a-date");
    expect(formatDateTime("")).toBe("");
  });
});
