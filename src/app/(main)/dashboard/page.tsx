import { getContests, getAllSubmissions, getReviews } from "@/lib/contests-data";
import renderMarkdown from "@/utils/render-markdown";
import DashboardClient from "./dashboard-client";

/**
 * Dashboard（C3）：统计 + 最近动态 + contribution 绿点图 + 复盘报告区。
 * 全部数据在构建时（服务端组件）从 contests/ 聚合，再传给客户端组件展示。
 */

export default async function DashboardPage() {
  const contests = getContests();
  const submissions = getAllSubmissions();
  const reviews = getReviews();

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
  const acCount = submissions.filter((s) => s.status === "AC").length;

  // ---- 最近完成的题目（按 solve_time 降序）----
  const recentSolved = contests
    .flatMap((c) =>
      c.problems
        .filter((p) => p.solve_time)
        .map((p) => ({
          contestName: c.name,
          contestDate: c.date,
          contestFolder: c.rel_path.split("/")[1] ?? "",
          letter: p.rel_path.split("/").pop() ?? "",
          name: p.name ?? "",
          solveTime: String(p.solve_time),
          viewFile: p.files[0]?.name ?? "",
        })),
    )
    .sort((a, b) => new Date(b.solveTime).getTime() - new Date(a.solveTime).getTime())
    .slice(0, 8);

  // ---- 最近比赛（按日期降序）----
  const recentContests = [...contests]
    .sort((a, b) => `${b.date} ${b.name}`.localeCompare(`${a.date} ${a.name}`))
    .slice(0, 5)
    .map((c) => ({
      name: c.name,
      date: c.date,
      platform: c.platform,
      link: c.link,
      relPath: c.rel_path,
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

  // ---- 复盘报告区 ----
  const currentReview = reviews[0] ?? null;
  const currentReviewHtml = currentReview
    ? await renderMarkdown(currentReview.content, currentReview.path)
    : null;

  return (
    <DashboardClient
      stats={{
        contestCount: contests.length,
        problemCount,
        solvedProblemCount,
        submissionCount: submissions.length,
        acCount,
        platformCounts,
      }}
      recentContests={recentContests}
      recentSolved={recentSolved}
      contribution={contribution}
      reviews={reviews.map((r) => ({
        contestFolder: r.contestFolder,
        contestName: r.contestName,
        date: r.date,
        platform: r.platform,
      }))}
      currentReviewHtml={currentReviewHtml}
      currentReview={{
        contestFolder: currentReview?.contestFolder ?? "",
        contestName: currentReview?.contestName ?? "",
        date: currentReview?.date ?? "",
        platform: currentReview?.platform ?? "",
      }}
    />
  );
}
