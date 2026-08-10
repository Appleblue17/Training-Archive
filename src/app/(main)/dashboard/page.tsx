import { getContests, getAllSubmissions, getReviews, getTotalCodeBytes } from "@/lib/contests-data";
import DashboardClient from "./dashboard-client";

/**
 * Dashboard（C3）：统计 + 最近动态 + contribution 绿点图。
 * 全部数据在构建时（服务端组件）从 contests/ 聚合，再传给客户端组件展示。
 * 复盘报告入口已并入 Recent Contests（有 review.md 的比赛展示 Review 链接）。
 */

export default async function DashboardPage() {
  const contests = getContests();
  const submissions = getAllSubmissions();

  // ---- 统计 ----
  const problemCount = contests.reduce((sum, c) => sum + c.problems.length, 0);
  const solvedProblemCount = contests.reduce(
    (sum, c) => sum + c.problems.filter((p) => p.solved).length,
    0,
  );
  const platformCounts: Record<string, number> = {};
  for (const c of contests) {
    platformCounts[c.platform] = (platformCounts[c.platform] ?? 0) + 1;
  }
  const totalCodeBytes = getTotalCodeBytes();

  // ---- 最近完成的题目（按 solve_time 降序）----
  const recentSolved = contests
    .flatMap((c) =>
      c.problems
        .filter((p) => p.solve_time)
        .map((p) => {
          const files = p.files;
          // 题面文件优先（statement.md / statement.pdf），搜索/最近完成等入口的链接目标
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
    .slice(0, 8);

  // ---- 最近比赛（按日期降序）----
  const reviewFolders = new Set(getReviews().map((r) => r.contestFolder));
  const recentContests = [...contests]
    .sort((a, b) => `${b.date} ${b.name}`.localeCompare(`${a.date} ${a.name}`))
    .slice(0, 5)
    .map((c) => ({
      name: c.name,
      date: c.date,
      platform: c.platform,
      link: c.link,
      relPath: c.rel_path,
      contestFolder: c.rel_path.split("/")[1] ?? "",
      hasReview: reviewFolders.has(c.rel_path.split("/")[1] ?? ""),
      problemCount: c.problems.length,
    }));

  // ---- contribution：按本地日期聚合提交数 ----
  const contribution: Record<string, number> = {};
  for (const sub of submissions) {
    if (!sub.submit_time) continue;
    const d = new Date(sub.submit_time);
    if (isNaN(d.getTime())) continue;
    const key = `${d.getFullYear()}-${String(d.getMonth() + 1).padStart(2, "0")}-${String(
      d.getDate(),
    ).padStart(2, "0")}`;
    contribution[key] = (contribution[key] ?? 0) + 1;
  }

  return (
    <DashboardClient
      stats={{
        contestCount: contests.length,
        problemCount,
        solvedProblemCount,
        submissionCount: submissions.length,
        totalCodeBytes,
        platformCounts,
      }}
      recentContests={recentContests}
      recentSolved={recentSolved}
      contribution={contribution}
    />
  );
}
