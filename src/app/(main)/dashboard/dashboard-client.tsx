"use client";
import {
  Activity,
  ArrowUpRight,
  Award,
  CheckCircle2,
  Clock,
  Code,
  FileCode,
  FileText,
} from "lucide-react";
import { useMemo, useState } from "react";
import Link from "next/link";
import clsx from "clsx";

import { joinUrl } from "@/utils/url";
import { formatDateTime, formatSize } from "@/utils/format";
import PlatformBadge from "@/components/platform-badge";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";

interface RecentContest {
  name: string;
  date: string;
  platform: string;
  link?: string;
  relPath: string;
  contestFolder: string;
  hasReview: boolean;
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
  codeFile: string;
  codeSize: number | null;
}

export interface DashboardClientProps {
  stats: {
    contestCount: number;
    problemCount: number;
    solvedProblemCount: number;
    submissionCount: number;
    totalCodeBytes: number;
    platformCounts: Record<string, number>;
  };
  recentContests: RecentContest[];
  recentSolved: RecentSolved[];
  contribution: Record<string, number>;
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

// ---- contribution 绿点图 ----
const CELL_SIZE = 10; // px，size-2.5
const CELL_GAP = 3; // px，gap-[3px]
const PITCH = CELL_SIZE + CELL_GAP; // 每列/行间距
const Y_LABEL_WIDTH = 30; // px，Y 轴星期标签列宽
const MONTH_ROW_HEIGHT = 16; // px，X 轴月份标签行高（h-4）

function ContributionGraph({ contribution }: { contribution: Record<string, number> }) {
  const cells = useMemo(() => getContributionCells(contribution), [contribution]);
  const [hover, setHover] = useState<{
    x: number;
    y: number;
    row: number;
    count: number;
    dateStr: string;
  } | null>(null);
  const totalActive = Object.keys(contribution).length;
  const totalCount = Object.values(contribution).reduce((a, b) => a + b, 0);

  const today = new Date();
  today.setHours(0, 0, 0, 0);

  // 按周分块（每 7 天一组，从周日开始）——每列固定 10px，横向 gap 与纵向一致
  const weeks: { key: string; days: typeof cells }[] = [];
  for (let i = 0; i < cells.length; i += 7) {
    weeks.push({ key: cells[i].key, days: cells.slice(i, i + 7) });
  }

  // X 轴月份标签：锚定到该月第一天所在的周列
  const months: { label: string; week: number }[] = [];
  let lastMonthKey = "";
  cells.forEach((cell, i) => {
    const key = `${cell.date.getFullYear()}-${cell.date.getMonth()}`;
    if (key !== lastMonthKey) {
      lastMonthKey = key;
      months.push({
        label: cell.date.toLocaleString("en-US", { month: "short" }),
        week: Math.floor(i / 7),
      });
    }
  });

  return (
    <Card className="w-fit max-w-full">
      <CardHeader className="flex-row items-center justify-between space-y-0 py-3">
        <CardTitle className="flex items-center gap-2 text-base">
          <Activity className="size-4 text-emerald-400" />
          Contribution
        </CardTitle>
        <span className="text-xs text-gray-400">
          {totalActive} active days · {totalCount} submissions
        </span>
      </CardHeader>
      <CardContent>
        <div className="relative">
          <div className="overflow-x-auto">
            <div className="flex gap-[3px]">
              {/* Y 轴：星期标签（与 7 行方格对齐） */}
              <div
                className="flex flex-col gap-[3px] text-[9px] leading-none text-gray-500"
                style={{ width: Y_LABEL_WIDTH, paddingTop: MONTH_ROW_HEIGHT + CELL_GAP }}
              >
                {["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"].map((label, i) => (
                  <div key={i} className="flex h-2.5 items-center">
                    {label}
                  </div>
                ))}
              </div>

              {/* X 轴月份 + 方格 */}
              <div className="flex flex-col gap-[3px]">
                <div className="relative h-4">
                  {months.map((m) => (
                    <div
                      key={`${m.label}-${m.week}`}
                      className="absolute top-0 whitespace-nowrap text-[10px] leading-none text-gray-500"
                      style={{ left: m.week * PITCH }}
                    >
                      {m.label}
                    </div>
                  ))}
                </div>
                <div className="flex gap-[3px]">
                  {weeks.map((week, wi) => (
                    <div key={week.key} className="flex flex-col gap-[3px]">
                      {week.days.map((cell, ri) => {
                        const isFuture = cell.date > today;
                        return (
                          <div
                            key={cell.key}
                            role="img"
                            aria-label={`${cell.key}: ${cell.count} submission${cell.count === 1 ? "" : "s"}`}
                            onMouseEnter={(e) => {
                              if (isFuture) return;
                              const scroller = e.currentTarget.closest(".overflow-x-auto");
                              const scrollLeft = scroller ? scroller.scrollLeft : 0;
                              setHover({
                                x:
                                  Y_LABEL_WIDTH +
                                  CELL_GAP +
                                  wi * PITCH +
                                  CELL_SIZE / 2 -
                                  scrollLeft,
                                y: MONTH_ROW_HEIGHT + CELL_GAP + ri * PITCH + CELL_SIZE / 2,
                                row: ri,
                                count: cell.count,
                                dateStr: cell.key.replace(/-/g, "/"),
                              });
                            }}
                            onMouseLeave={() => setHover(null)}
                            className={clsx(
                              "size-2.5 rounded-[3px]",
                              isFuture ? "bg-zinc-900" : contributionColor(cell.count),
                            )}
                          />
                        );
                      })}
                    </div>
                  ))}
                </div>
              </div>
            </div>
          </div>

          {/* 悬浮提示：当日提交数 */}
          {hover && (
            <div
              className="pointer-events-none absolute z-20 whitespace-nowrap rounded-md border border-gray-600 bg-gray-800 px-2.5 py-1.5 text-xs shadow-lg"
              style={{
                left: hover.x,
                top: hover.y,
                transform:
                  hover.row === 0
                    ? "translate(-50%, 8px)"
                    : "translate(-50%, calc(-100% - 8px))",
              }}
            >
              <span className="font-semibold text-slate-100">
                {hover.count} submission{hover.count === 1 ? "" : "s"}
              </span>
              <span className="text-gray-400"> · {hover.dateStr}</span>
            </div>
          )}
        </div>
        <div className="mt-2 flex items-center gap-1 text-xs text-gray-500">
          <span>Less</span>
          {[0, 1, 2, 4, 8].map((c) => (
            <span key={c} className={clsx("size-2.5 rounded-[3px]", contributionColor(c))} />
          ))}
          <span>More</span>
        </div>
      </CardContent>
    </Card>
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
  const { stats, recentContests, recentSolved, contribution } = props;

  return (
    <div className="w-full space-y-6">
      {/* 统计卡片 */}
      <section aria-label="Statistics">
        <div className="grid grid-cols-2 gap-3 py-2 sm:grid-cols-3 lg:grid-cols-5">
          <StatCard
            label="Contests"
            value={stats.contestCount}
            icon={<Award className="size-5 text-yellow-400" />}
            accent="bg-yellow-900/40"
          />
          <StatCard
            label="Problems"
            value={stats.problemCount}
            icon={<FileText className="size-5 text-blue-400" />}
            accent="bg-blue-900/40"
          />
          <StatCard
            label="Solved"
            value={stats.solvedProblemCount}
            icon={<CheckCircle2 className="size-5 text-green-400" />}
            accent="bg-green-900/40"
          />
          <StatCard
            label="Submissions"
            value={stats.submissionCount}
            icon={<Clock className="size-5 text-purple-400" />}
            accent="bg-purple-900/40"
          />
          <StatCard
            label="Total Code"
            value={formatSize(stats.totalCodeBytes)}
            icon={<FileCode className="size-5 text-cyan-400" />}
            accent="bg-cyan-900/40"
          />
        </div>
        {Object.keys(stats.platformCounts).length > 0 && (
          <div className="mt-3 flex flex-wrap items-center gap-2 text-sm text-gray-400">
            <span className="text-sm font-semibold">Platforms:</span>
            {Object.entries(stats.platformCounts).map(([platform, count]) => (
              <span key={platform} className="inline-flex items-center">
                <PlatformBadge platform={platform} />
                <span className="text-xs text-gray-400">x{count}</span>
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
        <Card>
          <CardHeader className="py-3">
            <CardTitle>Recent Contests</CardTitle>
          </CardHeader>
          <CardContent>
            {recentContests.length === 0 ? (
              <p className="py-4 text-center text-sm text-gray-500">No contests yet.</p>
            ) : (
              <ul className="space-y-2">
                {recentContests.map((c) => (
                  <li key={c.relPath} className="flex items-center justify-between gap-2">
                    <div className="min-w-0 space-x-1">
                      <PlatformBadge platform={c.platform} />
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
                    <div className="flex shrink-0 items-center gap-2">
                      {c.hasReview && (
                        <Link
                          href={joinUrl("/", "review", c.contestFolder)}
                          className="inline-flex items-center gap-1 text-sm text-blue-300 hover:text-blue-200"
                          aria-label={`Review for ${c.name}`}
                        >
                          Review
                          <ArrowUpRight className="size-4" />
                        </Link>
                      )}
                    </div>
                  </li>
                ))}
              </ul>
            )}
          </CardContent>
        </Card>

        {/* 最近完成的题目 */}
        <Card>
          <CardHeader className="py-3">
            <CardTitle>Recently Solved</CardTitle>
          </CardHeader>
          <CardContent>
            {recentSolved.length === 0 ? (
              <p className="py-4 text-center text-sm text-gray-500">Nothing solved yet</p>
            ) : (
              <ul className="space-y-2">
                {recentSolved.map((p) => {
                  const baseView = ["/", "view", "contests", p.contestFolder, "problems", p.letter];
                  const viewHref = p.viewFile
                    ? joinUrl(...baseView, p.viewFile)
                    : p.codeFile
                      ? joinUrl(...baseView, p.codeFile)
                      : "#";
                  const codeHref = p.codeFile ? joinUrl(...baseView, p.codeFile) : "#";
                  return (
                    <li
                      key={p.contestFolder + "/" + p.letter}
                      className="flex items-center justify-between gap-2"
                    >
                      <div className="min-w-0">
                        <div className="flex items-center gap-2">
                          <Link
                            href={viewHref}
                            target="_blank"
                            rel="noopener noreferrer"
                            title={p.viewFile ? `View statement (${p.viewFile})` : "View"}
                            className="truncate text-sm text-slate-100 hover:text-blue-300"
                          >
                            {p.letter}. {p.name}
                          </Link>
                          {p.codeFile && (
                            <Link
                              href={codeHref}
                              target="_blank"
                              rel="noopener noreferrer"
                              title={`View code (${p.codeFile})`}
                              aria-label={`View code for ${p.letter}. ${p.name}`}
                              className="shrink-0 text-gray-400 transition-colors hover:text-blue-300"
                            >
                              <Code className="inline-block size-4" />
                            </Link>
                          )}
                        </div>
                        <div className="truncate text-xs text-gray-500">
                          {p.contestName} · {p.contestDate}
                        </div>
                      </div>
                      <span className="shrink-0 whitespace-nowrap text-xs text-gray-400">
                        {p.codeSize != null && (
                          <span className="font-mono">
                            <span className="inline-block min-w-10 text-right align-middle">
                              {p.codeSize}
                            </span>
                            <span className="ml-1 text-gray-400">B</span>
                            <span className="mx-1.5 text-gray-600">·</span>
                          </span>
                        )}
                        {formatDateTime(p.solveTime)}
                      </span>
                    </li>
                  );
                })}
              </ul>
            )}
          </CardContent>
        </Card>
      </section>
    </div>
  );
}
