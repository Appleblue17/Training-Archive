import { describe, expect, it } from "vitest";

import {
  computeContribution,
  computeRecentContests,
  computeRecentSolved,
  computeStats,
} from "@/lib/dashboard";
import type { ContestInfoType, ProblemInfoType } from "@/lib/types";

function problem(overrides: Partial<ProblemInfoType> = {}): ProblemInfoType {
  return {
    rel_path: "contests/2026-01-01 Contest A/problems/A",
    name: "Two Sum",
    files: [],
    ...overrides,
  };
}

function contest(overrides: Partial<ContestInfoType> = {}): ContestInfoType {
  return {
    rel_path: "contests/2026-01-01 Contest A",
    date: "2026-01-01",
    name: "Contest A",
    platform: "qoj",
    problems: [],
    files: [],
    ...overrides,
  };
}

describe("computeStats", () => {
  it("统计比赛 / 题目 / 已解决 / 提交 / 平台", () => {
    const contests = [
      contest({ platform: "qoj", problems: [problem({ solved: true }), problem({ solved: false })] }),
      contest({ rel_path: "contests/2026-02-01 Contest B", platform: "hdu", problems: [] }),
    ];
    const stats = computeStats(contests, [{}, {}, {}], 12345);
    expect(stats).toMatchObject({
      contestCount: 2,
      problemCount: 2,
      solvedProblemCount: 1,
      submissionCount: 3,
      totalCodeBytes: 12345,
      platformCounts: { qoj: 1, hdu: 1 },
    });
  });
});

describe("computeRecentSolved", () => {
  it("题面文件优先、按 solve_time 降序、限制条数", () => {
    const contests = [
      contest({
        problems: [
          problem({
            rel_path: "contests/2026-01-01 Contest A/problems/A",
            solve_time: new Date("2026-01-01T01:00:00Z"),
            files: [{ name: "code.cpp", size: 100 }],
          }),
          problem({
            rel_path: "contests/2026-01-01 Contest A/problems/B",
            name: "Later",
            solve_time: new Date("2026-01-01T03:00:00Z"),
            files: [
              { name: "code.cpp", size: 200 },
              { name: "statement.pdf", size: 50 },
            ],
          }),
        ],
      }),
    ];
    const recent = computeRecentSolved(contests, 8);
    expect(recent.map((r) => r.letter)).toEqual(["B", "A"]);
    expect(recent[0]).toMatchObject({
      contestFolder: "2026-01-01 Contest A",
      viewFile: "statement.pdf",
      codeFile: "code.cpp",
      codeSize: 200,
    });
    // 只有 code 文件、没有题面时，viewFile 为空（调用方回退到 codeFile）
    expect(recent[1].viewFile).toBe("");
  });

  it("limit 生效", () => {
    const contests = [
      contest({
        problems: Array.from({ length: 5 }, (_, i) =>
          problem({
            rel_path: `contests/2026-01-01 Contest A/problems/${String.fromCharCode(65 + i)}`,
            solve_time: new Date(2026, 0, 1, i),
          }),
        ),
      }),
    ];
    expect(computeRecentSolved(contests, 3)).toHaveLength(3);
  });
});

describe("computeRecentContests", () => {
  it("按日期降序并在有复盘时标记", () => {
    const contests = [
      contest({ rel_path: "contests/2026-01-01 Contest A", date: "2026-01-01", name: "A" }),
      contest({ rel_path: "contests/2026-03-01 Contest C", date: "2026-03-01", name: "C" }),
      contest({ rel_path: "contests/2026-02-01 Contest B", date: "2026-02-01", name: "B" }),
    ];
    const reviewFolders = new Set(["2026-03-01 Contest C"]);
    const recent = computeRecentContests(contests, reviewFolders, 2);
    expect(recent.map((r) => r.name)).toEqual(["C", "B"]);
    expect(recent[0].hasReview).toBe(true);
    expect(recent[1].hasReview).toBe(false);
  });
});

describe("computeContribution", () => {
  it("按本地日期聚合、跳过无效时间", () => {
    const contribution = computeContribution([
      { submit_time: "2026-01-01T10:00:00+08:00" },
      { submit_time: "2026-01-01T23:30:00+08:00" },
      { submit_time: "2026-01-02T00:30:00+08:00" },
      { submit_time: "" },
      { submit_time: "not-a-date" },
      {},
    ]);
    expect(contribution["2026-01-01"]).toBe(2);
    expect(contribution["2026-01-02"]).toBe(1);
    expect(Object.keys(contribution)).toHaveLength(2);
  });
});
