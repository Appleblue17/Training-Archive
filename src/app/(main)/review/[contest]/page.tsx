import fs from "fs";
import path from "path";
import type { Metadata } from "next";

import { safeParseJson } from "@/lib/contests-data";
import renderMarkdown from "@/utils/render-markdown";
import ProtectionNotConfigured from "@/components/protection-not-configured";
import {
  encryptResource,
  isProtectedContestFolder,
  isProtectionConfigured,
} from "@/lib/resource-protection";
import ReviewClient, { ReviewData } from "./review-client";

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

/** 无可用数据时的占位参数，保证 output: export 下动态路由可构建。 */
const PLACEHOLDER = "~no-data~";

export async function generateMetadata(props: {
  params: Promise<{ contest: string }>;
}): Promise<Metadata> {
  const { contest } = await props.params;
  const contestFolder = decodeURIComponent(contest);
  if (contestFolder === PLACEHOLDER) {
    return { title: "Review" };
  }
  const data = readContest(contestFolder);
  const name = String(data?.contest?.name ?? "") || contestFolder;
  return { title: `${name} · Review` };
}

export async function generateStaticParams() {
  const contestsDir = path.join(process.cwd(), "contests");
  if (!fs.existsSync(contestsDir)) return [{ contest: PLACEHOLDER }];
  const params = fs
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

  // output: export 要求动态路由至少有一个静态参数；无数据时用占位参数，
  // 页面内部渲染"Contest not found"提示（数据由爬虫生成后占位页自然消失）。
  if (params.length === 0) {
    return [{ contest: PLACEHOLDER }];
  }
  return params;
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

  const reviewData: ReviewData = {
    name,
    date,
    platform,
    link,
    contestFolder,
    problemCount: Object.keys(data.problems).length,
    submissions: sortedSubmissions.map((sub) => ({
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
    })),
    reviewHtml,
  };

  // 资源保护：受保护比赛的复盘数据整体加密，客户端验证密码后渲染。
  if (isProtectedContestFolder(contestFolder)) {
    if (!isProtectionConfigured()) return <ProtectionNotConfigured />;
    return <ReviewClient payload={encryptResource(JSON.stringify(reviewData))} />;
  }

  return <ReviewClient data={reviewData} />;
}
