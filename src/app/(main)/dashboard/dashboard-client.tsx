"use client";
import { useMemo } from "react";
import Link from "next/link";
import clsx from "clsx";
import {
  FiActivity,
  FiAward,
  FiBarChart2,
  FiCheckCircle,
  FiClock,
  FiFileText,
} from "react-icons/fi";

import { PREFIX_URL } from "@/lib/global";
import { joinUrl } from "@/utils/url";
import PlatformBadge from "@/components/platform-badge";

interface RecentContest {
  name: string;
  date: string;
  platform: string;
  link?: string;
  relPath: string;
  problemCount: number;
}

interface RecentSolved {
  contestName: string;
  contestDate: string;
  contestFolder: string;
  letter: string;
  name: string;
  solveTime: string;
  viewFile: string;
}

interface ReviewMeta {
  contestFolder: string;
  contestName: string;
  date: string;
  platform: string;
}

export interface DashboardClientProps {
  stats: {
    contestCount: number;
    problemCount: number;
    solvedProblemCount: number;
    submissionCount: number;
    acCount: number;
    platformCounts: Record<string, number>;
  };
  recentContests: RecentContest[];
  recentSolved: RecentSolved[];
  contribution: Record<string, number>;
  reviews: ReviewMeta[];
  currentReviewHtml: string | null;
  currentReview: ReviewMeta;
}

// ---- contribution 绿点图 ----
const CONTRIB_WEEKS = 52;

function getContributionCells(contribution: Record<string, number>) {
  // 从今天往前推 CONTRIB_WEEKS*7 天，按周排成 7 行（周日…周六）* N 列
  const today = new Date();
  today.setHours(0, 0, 0, 0);
  const start = new Date(today);
  start.setDate(start.getDate() - (CONTRIB_WEEKS * 7 - 1));
  // 对齐到周起始（周日），保证第一列完整
  start.setDate(start.getDate() - start.getDay());

  const cells: { date: Date; count: number; key: string }[] = [];
  const end = new Date(start);
  end.setDate(end.getDate() + CONTRIB_WEEKS * 7);
  for (let d = new Date(start); d < end; d.setDate(d.getDate() + 1)) {
    const key = `${d.getFullYear()}-${String(d.getMonth() + 1).padStart(2, "0")}-${String(
      d.getDate(),
    ).padStart(2, "0")}`;
    cells.push({ date: new Date(d), count: contribution[key] ?? 0, key });
  }
  return cells;
}

function contributionColor(count: number): string {
  if (count === 0) return "bg-zinc-800";
  if (count < 2) return "bg-emerald-900";
  if (count < 4) return "bg-emerald-700";
  if (count < 8) return "bg-emerald-500";
  return "bg-emerald-400";
}

function ContributionGraph({ contribution }: { contribution: Record<string, number> }) {
  const cells = useMemo(() => getContributionCells(contribution), [contribution]);
  const totalActive = Object.keys(contribution).length;
  const totalCount = Object.values(contribution).reduce((a, b) => a + b, 0);

  return (
    <div className="rounded-lg border border-gray-700 bg-gray-800/60 p-4">
      <div className="mb-3 flex items-center justify-between">
        <h2 className="flex items-center gap-2 text-base font-semibold text-slate-200">
          <FiActivity className="size-4 text-emerald-400" />
          Contribution
        </h2>
        <span className="text-xs text-gray-400">
          {totalActive} active days · {totalCount} submissions
        </span>
      </div>
      <div className="overflow-x-auto">
        <div className="grid grid-flow-col grid-rows-7 gap-[3px]" style={{ minWidth: "max-content" }}>
          {cells.map((cell) => {
            const isFuture = cell.date > new Date();
            return (
              <div
                key={cell.key}
                className={clsx(
                  "size-2.5 rounded-[3px]",
                  isFuture ? "bg-zinc-900" : contributionColor(cell.count),
                )}
                title={`${cell.key}: ${cell.count} submission${cell.count === 1 ? "" : "s"}`}
                aria-label={`${cell.key}: ${cell.count} submissions`}
              />
            );
          })}
        </div>
      </div>
      <div className="mt-2 flex items-center gap-1 text-xs text-gray-500">
        <span>Less</span>
        {[0, 1, 2, 4, 8].map((c) => (
          <span key={c} className={clsx("size-2.5 rounded-[3px]", contributionColor(c))} />
        ))}
        <span>More</span>
      </div>
    </div>
  );
}

function StatCard({
  label,
  value,
  icon,
  accent,
}: {
  label: string;
  value: number | string;
  icon: React.ReactNode;
  accent: string;
}) {
  return (
    <div className="flex items-center gap-3 rounded-lg border border-gray-700 bg-gray-800/60 px-4 py-3">
      <div className={clsx("flex size-9 items-center justify-center rounded-lg", accent)}>
        {icon}
      </div>
      <div>
        <div className="text-xl font-semibold text-slate-100">{value}</div>
        <div className="text-xs text-gray-400">{label}</div>
      </div>
    </div>
  );
}

export default function DashboardClient(props: DashboardClientProps) {
  const { stats, recentContests, recentSolved, contribution, reviews, currentReviewHtml } = props;

  return (
    <div className="w-full space-y-6">
      {/* 统计卡片 */}
      <section aria-label="Statistics">
        <h1 className="mb-3 text-2xl font-semibold text-slate-200">Dashboard</h1>
        <div className="grid grid-cols-2 gap-3 sm:grid-cols-3 lg:grid-cols-5">
          <StatCard
            label="Contests"
            value={stats.contestCount}
            icon={<FiAward className="size-5 text-yellow-400" />}
            accent="bg-yellow-900/40"
          />
          <StatCard
            label="Problems"
            value={stats.problemCount}
            icon={<FiFileText className="size-5 text-blue-400" />}
            accent="bg-blue-900/40"
          />
          <StatCard
            label="Solved"
            value={stats.solvedProblemCount}
            icon={<FiCheckCircle className="size-5 text-green-400" />}
            accent="bg-green-900/40"
          />
          <StatCard
            label="Submissions"
            value={stats.submissionCount}
            icon={<FiClock className="size-5 text-purple-400" />}
            accent="bg-purple-900/40"
          />
          <StatCard
            label="AC"
            value={stats.acCount}
            icon={<FiBarChart2 className="size-5 text-emerald-400" />}
            accent="bg-emerald-900/40"
          />
        </div>
        {Object.keys(stats.platformCounts).length > 0 && (
          <div className="mt-3 flex flex-wrap items-center gap-2 text-sm text-gray-400">
            <span className="text-xs">Platforms:</span>
            {Object.entries(stats.platformCounts).map(([platform, count]) => (
              <span key={platform} className="inline-flex items-center gap-1.5">
                <PlatformBadge platform={platform} />
                <span className="text-xs">{count}</span>
              </span>
            ))}
          </div>
        )}
      </section>

      {/* contribution 绿点图 */}
      <ContributionGraph contribution={contribution} />

      {/* 最近动态 */}
      <section aria-label="Recent activity" className="grid gap-4 lg:grid-cols-2">
        {/* 最近比赛 */}
        <div className="rounded-lg border border-gray-700 bg-gray-800/60 p-4">
          <h2 className="mb-3 text-base font-semibold text-slate-200">Recent Contests</h2>
          {recentContests.length === 0 ? (
            <p className="py-4 text-center text-sm text-gray-500">No contests yet.</p>
          ) : (
            <ul className="space-y-2">
              {recentContests.map((c) => (
                <li key={c.relPath} className="flex items-center justify-between gap-2">
                  <div className="min-w-0">
                    {c.link ? (
                      <a
                        href={c.link}
                        target="_blank"
                        rel="noopener noreferrer"
                        className="truncate text-sm text-slate-100 hover:text-blue-300"
                      >
                        {c.name}
                      </a>
                    ) : (
                      <span className="truncate text-sm text-slate-100">{c.name}</span>
                    )}
                    <div className="text-xs text-gray-500">
                      {c.date} · {c.problemCount} problems
                    </div>
                  </div>
                  <PlatformBadge platform={c.platform} />
                </li>
              ))}
            </ul>
          )}
        </div>

        {/* 最近完成的题目 */}
        <div className="rounded-lg border border-gray-700 bg-gray-800/60 p-4">
          <h2 className="mb-3 text-base font-semibold text-slate-200">Recently Solved</h2>
          {recentSolved.length === 0 ? (
            <p className="py-4 text-center text-sm text-gray-500">Nothing solved yet.</p>
          ) : (
            <ul className="space-y-2">
              {recentSolved.map((p) => {
                const href = p.viewFile
                  ? joinUrl(
                      PREFIX_URL,
                      "view",
                      p.contestFolder,
                      "problems",
                      p.letter,
                      p.viewFile,
                    )
                  : "#";
                return (
                  <li key={p.contestFolder + "/" + p.letter} className="flex items-center justify-between gap-2">
                    <div className="min-w-0">
                      <Link
                        href={href}
                        className="truncate text-sm text-slate-100 hover:text-blue-300"
                      >
                        {p.letter}. {p.name}
                      </Link>
                      <div className="truncate text-xs text-gray-500">
                        {p.contestName} · {p.contestDate}
                      </div>
                    </div>
                    <span className="shrink-0 text-xs text-gray-400">
                      {new Date(p.solveTime).toLocaleDateString()}
                    </span>
                  </li>
                );
              })}
            </ul>
          )}
        </div>
      </section>

      {/* 复盘报告区 */}
      <section aria-label="Contest reviews" className="rounded-lg border border-gray-700 bg-gray-800/60 p-4">
        <h2 className="mb-3 text-base font-semibold text-slate-200">Contest Reviews</h2>
        {!currentReviewHtml ? (
          <p className="py-4 text-center text-sm text-gray-500">
            No reviews yet. Reviews are generated by the crawler task A after each contest ends.
          </p>
        ) : (
          <>
            <div className="mb-4 flex flex-wrap items-center gap-2">
              <span className="text-sm text-slate-100">{props.currentReview.contestName}</span>
              <span className="text-xs text-gray-500">{props.currentReview.date}</span>
              <PlatformBadge platform={props.currentReview.platform} />
              <Link
                href={joinUrl(PREFIX_URL, "review", props.currentReview.contestFolder)}
                className="ml-auto text-sm text-blue-300 hover:text-blue-200"
              >
                View timeline →
              </Link>
            </div>
            <div
              className="markdown-body rounded border border-gray-700 p-4"
              dangerouslySetInnerHTML={{ __html: currentReviewHtml }}
            />
            {reviews.length > 1 && (
              <div className="mt-4 border-t border-gray-700 pt-3">
                <div className="mb-2 text-xs font-bold uppercase tracking-wide text-gray-500">
                  Past reviews
                </div>
                <ul className="space-y-1">
                  {reviews.slice(1).map((r) => (
                    <li key={r.contestFolder}>
                      <Link
                        href={joinUrl(PREFIX_URL, "review", r.contestFolder)}
                        className="text-sm text-slate-300 hover:text-blue-300"
                      >
                        {r.contestName} · {r.date}
                      </Link>
                    </li>
                  ))}
                </ul>
              </div>
            )}
          </>
        )}
      </section>
    </div>
  );
}
