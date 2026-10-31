import { describe, expect, it } from "vitest";

import { filterEntries, getAllTags, paginate } from "@/lib/search";
import type { SearchIndexEntryType } from "@/lib/types";

function entry(overrides: Partial<SearchIndexEntryType> = {}): SearchIndexEntryType {
  return {
    type: "problem",
    contest: "Contest A",
    date: "2026-01-01",
    platform: "qoj",
    letter: "A",
    name: "Two Sum",
    tags: [],
    viewFile: "statement.pdf",
    contestFolder: "2026-01-01 Contest A",
    contestPath: "contests/2026-01-01 Contest A",
    relPath: "contests/2026-01-01 Contest A/problems/A",
    ...overrides,
  };
}

describe("getAllTags", () => {
  it("去重并排序", () => {
    const tags = getAllTags([
      entry({ tags: ["math", "dp"] }),
      entry({ tags: ["dp", "greedy"] }),
      entry({ tags: [] }),
    ]);
    expect(tags).toEqual(["dp", "greedy", "math"]);
  });
});

describe("filterEntries", () => {
  it("空查询返回全部", () => {
    const entries = [entry(), entry({ name: "Three Sum" })];
    expect(filterEntries(entries, "  ", [])).toHaveLength(2);
  });

  it("关键词大小写不敏感且多 token 全部命中", () => {
    const entries = [
      entry({ name: "Two Sum", contest: "Contest A" }),
      entry({ name: "Two Products", contest: "Contest B" }),
    ];
    expect(filterEntries(entries, "TWO sum", [])).toHaveLength(1);
    expect(filterEntries(entries, "two contest b", []).map((e) => e.name)).toEqual([
      "Two Products",
    ]);
  });

  it("标签过滤要求全部命中", () => {
    const entries = [
      entry({ name: "P1", tags: ["math", "dp"] }),
      entry({ name: "P2", tags: ["math"] }),
      entry({ name: "P3", tags: ["greedy"] }),
    ];
    expect(filterEntries(entries, "", ["math"]).map((e) => e.name)).toEqual(["P1", "P2"]);
    expect(filterEntries(entries, "", ["math", "dp"]).map((e) => e.name)).toEqual(["P1"]);
  });
});

describe("paginate", () => {
  const items = Array.from({ length: 25 }, (_, i) => i);

  it("切页与总页数", () => {
    const first = paginate(items, 1, 20);
    expect(first.page).toBe(1);
    expect(first.totalPages).toBe(2);
    expect(first.items).toEqual(items.slice(0, 20));

    const second = paginate(items, 2, 20);
    expect(second.page).toBe(2);
    expect(second.items).toEqual(items.slice(20));
  });

  it("页码越界钳制", () => {
    expect(paginate(items, 99, 20).page).toBe(2);
    expect(paginate(items, 0, 20).page).toBe(1);
    expect(paginate(items, -3, 20).page).toBe(1);
  });

  it("空列表仍有一页", () => {
    const r = paginate([], 1, 20);
    expect(r.totalPages).toBe(1);
    expect(r.items).toEqual([]);
  });
});
