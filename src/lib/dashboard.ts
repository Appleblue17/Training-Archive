import type { ContestInfoType } from "@/lib/types";

/** Dashboard 统计卡片数据。 */
export interface DashboardStats {
  contestCount: number;
  problemCount: number;
  solvedProblemCount: number;
  submissionCount: number;
  totalCodeBytes: number;
  platformCounts: Record<string, number>;
}

export interface RecentContest {
  name: string;
  date: string;
  platform: string;
  link?: string;
  relPath: string;
  contestFolder: string;
  hasReview: boolean;
  problemCount: number;
}

export interface RecentSolved {
  contestName: string;
  contestDate: string;
  contestFolder: string;
  letter: string;
  name: string;
  solveTime: string;
  viewFile: string;
  codeFile: string;
  codeSize: number | null;
}

/** submissions.json 条目里聚合用到的字段。 */
export interface SubmissionLike {
  submit_time?: unknown;
}

function toDateKey(value: unknown): string | null {
  if (!value) return null;
  const d = value instanceof Date ? value : new Date(String(value));
  if (isNaN(d.getTime())) return null;
  return `${d.getFullYear()}-${String(d.getMonth() + 1).padStart(2, "0")}-${String(
    d.getDate(),
  ).padStart(2, "0")}`;
}

/** 统计：比赛 / 题目 / 已解决 / 提交数、代码体积、平台分布。 */
export function computeStats(
  contests: ContestInfoType[],
  submissions: readonly unknown[],
  totalCodeBytes: number,
): DashboardStats {
  let problemCount = 0;
  let solvedProblemCount = 0;
  const platformCounts: Record<string, number> = {};
  for (const c of contests) {
    problemCount += c.problems.length;
    solvedProblemCount += c.problems.filter((p) => p.solved).length;
    platformCounts[c.platform] = (platformCounts[c.platform] ?? 0) + 1;
  }
  return {
    contestCount: contests.length,
    problemCount,
    solvedProblemCount,
    submissionCount: submissions.length,
    totalCodeBytes,
    platformCounts,
  };
}

/** 最近完成的题目（按 solve_time 降序），题面文件优先作为查看目标。 */
export function computeRecentSolved(
  contests: ContestInfoType[],
  limit = 8,
): RecentSolved[] {
  return contests
    .flatMap((c) =>
      c.problems
        .filter((p) => p.solve_time)
        .map((p) => {
          const files = p.files;
          const statementFile =
            files.find((f) => f.name?.toLowerCase() === "statement.md")?.name ??
            files.find((f) => f.name?.toLowerCase() === "statement.pdf")?.name ??
            files.find((f) => f.name && !f.name.toLowerCase().startsWith("code"))?.name ??
            "";
          const codeFile = files.find((f) => f.name?.toLowerCase().startsWith("code"));
          return {
            contestName: c.name,
            contestDate: c.date,
            contestFolder: c.rel_path.split("/")[1] ?? "",
            letter: p.rel_path.split("/").pop() ?? "",
            name: p.name ?? "",
            solveTime: String(p.solve_time),
            viewFile: statementFile,
            codeFile: codeFile?.name ?? "",
            codeSize: typeof codeFile?.size === "number" ? codeFile.size : null,
          };
        }),
    )
    .sort((a, b) => new Date(b.solveTime).getTime() - new Date(a.solveTime).getTime())
    .slice(0, limit);
}

/** 最近比赛（按日期 + 名称降序）。 */
export function computeRecentContests(
  contests: ContestInfoType[],
  reviewFolders: Set<string>,
  limit = 5,
): RecentContest[] {
  const folder = (c: ContestInfoType) => c.rel_path.split("/")[1] ?? "";
  return [...contests]
    .sort((a, b) => `${b.date} ${b.name}`.localeCompare(`${a.date} ${a.name}`))
    .slice(0, limit)
    .map((c) => ({
      name: c.name,
      date: c.date,
      platform: c.platform,
      link: c.link,
      relPath: c.rel_path,
      contestFolder: folder(c),
      hasReview: reviewFolders.has(folder(c)),
      problemCount: c.problems.length,
    }));
}

/** contribution：按本地日期聚合提交数。 */
export function computeContribution(
  submissions: readonly SubmissionLike[],
): Record<string, number> {
  const contribution: Record<string, number> = {};
  for (const sub of submissions) {
    const key = toDateKey(sub.submit_time);
    if (!key) continue;
    contribution[key] = (contribution[key] ?? 0) + 1;
  }
  return contribution;
}
