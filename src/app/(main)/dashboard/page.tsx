import type { Metadata } from "next";
import { getContests, getAllSubmissions, getReviews, getTotalCodeBytes } from "@/lib/contests-data";
import {
  computeContribution,
  computeRecentContests,
  computeRecentSolved,
  computeStats,
} from "@/lib/dashboard";
import DashboardClient from "./dashboard-client";

export const metadata: Metadata = {
  title: "Dashboard",
};

/**
 * Dashboard（C3）：统计 + 最近动态 + contribution 绿点图。
 * 全部数据在构建时（服务端组件）从 contests/ 聚合，再传给客户端组件展示。
 * 复盘报告入口已并入 Recent Contests（有 review.md 的比赛展示 Review 链接）。
 */

export default async function DashboardPage() {
  // 资源保护（方案 A）：Dashboard 正常统计全部比赛（元数据公开）。
  const contests = getContests();
  const submissions = getAllSubmissions();
  const reviewFolders = new Set(getReviews().map((r) => r.contestFolder));

  return (
    <DashboardClient
      stats={computeStats(contests, submissions, getTotalCodeBytes())}
      recentContests={computeRecentContests(contests, reviewFolders)}
      recentSolved={computeRecentSolved(contests)}
      contribution={computeContribution(submissions)}
    />
  );
}
