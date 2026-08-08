import fs from "fs";
import path from "path";
import Link from "next/link";

import { safeParseJson } from "@/lib/contests-data";
import renderMarkdown from "@/utils/render-markdown";
import { PREFIX_URL } from "@/lib/global";
import { joinUrl } from "@/utils/url";
import PlatformBadge from "@/components/platform-badge";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import ReviewTimeline from "./review-timeline";

interface ContestData {
  folder: string;
  contest: Record<string, unknown>;
  submissions: Record<string, unknown>[];
  problems: Record<string, { letter: string; problem: Record<string, unknown> }>;
  reviewContent: string | null;
  reviewHtml: string | null;
}

function readContest(folder: string): ContestData | null {
  const contestPath = path.join(process.cwd(), "contests", folder);
  if (!fs.existsSync(contestPath)) return null;

  const contest = safeParseJson(path.join(contestPath, "contest.json")) ?? {};

  const submissionsPath = path.join(contestPath, "submissions.json");
  const submissions = fs.existsSync(submissionsPath)
    ? (safeParseJson(submissionsPath) as Record<string, unknown>[] | null) ?? []
    : [];

  // problems/<letter>/problem.json
  const problems: ContestData["problems"] = {};
  const problemsDir = path.join(contestPath, "problems");
  if (fs.existsSync(problemsDir)) {
    for (const letter of fs.readdirSync(problemsDir)) {
      const problemPath = path.join(problemsDir, letter);
      if (!fs.statSync(problemPath).isDirectory()) continue;
      const problem = safeParseJson(path.join(problemPath, "problem.json"));
      if (problem) problems[letter] = { letter, problem };
    }
  }

  // review.md
  const reviewPath = path.join(contestPath, "review.md");
  let reviewContent: string | null = null;
  try {
    if (fs.existsSync(reviewPath)) reviewContent = fs.readFileSync(reviewPath, "utf-8");
  } catch {
    reviewContent = null;
  }

  return {
    folder,
    contest,
    submissions,
    problems,
    reviewContent,
    reviewHtml: null,
  };
}

export async function generateStaticParams() {
  const contestsDir = path.join(process.cwd(), "contests");
  if (!fs.existsSync(contestsDir)) return [];
  return fs
    .readdirSync(contestsDir)
    .filter((folder) => {
      const p = path.join(contestsDir, folder);
      if (!fs.statSync(p).isDirectory()) return false;
      return (
        fs.existsSync(path.join(p, "submissions.json")) ||
        fs.existsSync(path.join(p, "review.md"))
      );
    })
    .map((folder) => ({ contest: folder }));
}

export default async function ReviewPage(props: {
  params: Promise<{ contest: string }>;
}) {
  const params = await props.params;
  const contestFolder = decodeURIComponent(params.contest);
  const data = readContest(contestFolder);
  if (!data) {
    return <p className="py-8 text-center text-gray-400">Contest not found.</p>;
  }

  const contest = data.contest;
  const name = (contest.name as string) || contestFolder;
  const date = (contest.date as string) || "";
  const platform = (contest.platform as string) || "";
  const link = contest.link as string | undefined;

  // letter 映射：优先按 problem_link，其次按 problem_name
  const letterByLink = new Map<string, string>();
  const letterByName = new Map<string, string>();
  for (const { letter, problem } of Object.values(data.problems)) {
    if (problem.link) letterByLink.set(String(problem.link).replace(/\/+$/, ""), letter);
    if (problem.name) letterByName.set(String(problem.name), letter);
  }
  const letterFor = (sub: Record<string, unknown>): string => {
    const subLink = String(sub.problem_link ?? "").replace(/\/+$/, "");
    if (letterByLink.has(subLink)) return letterByLink.get(subLink)!;
    const byName = letterByName.get(String(sub.problem_name ?? ""));
    return byName ?? "?";
  };

  // 提交按时间升序
  const sortedSubmissions = [...data.submissions].sort((a, b) =>
    String(a.submit_time ?? "").localeCompare(String(b.submit_time ?? "")),
  );

  // 每条提交对应的源码文件（problems/<letter>/submissions/<id>.<ext>）
  const sourceFor = (letter: string, submissionId: string): string | null => {
    const dir = path.join(
      process.cwd(),
      "contests",
      contestFolder,
      "problems",
      letter,
      "submissions",
    );
    if (!fs.existsSync(dir)) return null;
    try {
      return (
        fs.readdirSync(dir).find((f) => path.parse(f).name === submissionId) ?? null
      );
    } catch {
      return null;
    }
  };

  const reviewHtml = data.reviewContent
    ? await renderMarkdown(data.reviewContent, path.join(process.cwd(), "contests", contestFolder))
    : null;

  return (
    <div className="w-full space-y-6">
      {/* 比赛信息 */}
      <Card className="p-4">
        <div className="flex flex-wrap items-center gap-2">
          <h1 className="text-xl font-semibold text-slate-100">{name}</h1>
          <PlatformBadge platform={platform} />
          <span className="text-sm text-gray-400">{date}</span>
          {link && (
            <a
              href={link}
              target="_blank"
              rel="noopener noreferrer"
              className="text-sm text-blue-300 hover:text-blue-200"
            >
              Contest link ↗
            </a>
          )}
        </div>
        <div className="mt-2 flex flex-wrap gap-x-4 gap-y-1 text-sm text-gray-400">
          <span>{Object.keys(data.problems).length} problems</span>
          <span>{sortedSubmissions.length} submissions</span>
        </div>
      </Card>

      {/* 提交时间轴 */}
      <ReviewTimeline
        submissions={sortedSubmissions.map((sub) => ({
          submissionId: String(sub.submission_id ?? ""),
          problemLetter: letterFor(sub),
          problemName: String(sub.problem_name ?? ""),
          status: String(sub.status ?? ""),
          language: String(sub.language ?? ""),
          time: sub.time != null ? String(sub.time) : null,
          memory: sub.memory != null ? String(sub.memory) : null,
          submitTime: String(sub.submit_time ?? ""),
          submissionLink: sub.submission_link ? String(sub.submission_link) : null,
          sourceFile: sourceFor(letterFor(sub), String(sub.submission_id ?? "")),
        }))}
        contestFolder={contestFolder}
      />

      {/* LLM 复盘报告 */}
      {reviewHtml && (
        <Card asChild>
          <section aria-label="Review report">
            <CardHeader className="pb-2">
              <CardTitle>Review Report</CardTitle>
            </CardHeader>
            <CardContent>
              <div
                className="markdown-body rounded border border-gray-700 p-4"
                dangerouslySetInnerHTML={{ __html: reviewHtml }}
              />
              <div className="mt-3 text-right">
                <Link
                  href={joinUrl(PREFIX_URL, "view", contestFolder, "review.md")}
                  className="text-sm text-blue-300 hover:text-blue-200"
                >
                  View raw markdown ↗
                </Link>
              </div>
            </CardContent>
          </section>
        </Card>
      )}
    </div>
  );
}
