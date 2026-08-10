import fs from "fs";
import path from "path";

import { ProblemInfoType, ContestInfoType } from "@/lib/types";
import getFileMetadata from "@/utils/get-file-metadata";
import { allowedExtensions } from "@/lib/global";

/**
 * 服务端数据读取模块。
 * 只允许被服务端组件 / 服务端模块 import（使用 Node fs/path）。
 */

export function safeParseJson(filePath: string): Record<string, unknown> | null {
  try {
    return JSON.parse(fs.readFileSync(filePath, "utf-8"));
  } catch (e) {
    console.warn(`Failed to parse JSON metadata: ${filePath}`, e);
    return null;
  }
}

function getFilesInfo(directory: string) {
  const files = fs.readdirSync(directory);
  return files
    .filter((file) => {
      const fullPath = path.join(directory, file);
      const ext = path.extname(file).toLowerCase();
      return fs.statSync(fullPath).isFile() && allowedExtensions.includes(ext) && ext !== ".json";
    })
    .map((file) => {
      return getFileMetadata(path.join(directory, file), path.join(directory, file + ".json"));
    })
    .filter((file) => file !== null);
}

export function getProblemInfo(problemPath: string, relProblemPath: string): ProblemInfoType {
  const problemInfo: ProblemInfoType = {
    rel_path: relProblemPath,
    files: getFilesInfo(problemPath),
  };

  if (fs.existsSync(problemPath)) {
    const jsonPath = path.join(problemPath, "problem.json");
    if (fs.existsSync(jsonPath)) {
      const json = safeParseJson(jsonPath);
      if (json) Object.assign(problemInfo, json);
    }
  }
  return problemInfo;
}

export function getContests(): ContestInfoType[] {
  const contestsDir = path.join(process.cwd(), "contests");
  if (!fs.existsSync(contestsDir)) return [];

  const contestFolders = fs.readdirSync(contestsDir);

  const contests: ContestInfoType[] = [];
  for (const contest of contestFolders) {
    const contestPath = path.join(contestsDir, contest);

    const contestInfo: ContestInfoType = {
      rel_path: path.join("contests", contest),
      date: "??-??-????",
      name: "???",
      platform: "unknown",
      problems: [],
      files: getFilesInfo(contestPath),
    };

    const jsonPath = path.join(contestPath, "contest.json");
    if (fs.existsSync(jsonPath)) {
      const json = safeParseJson(jsonPath);
      if (json) Object.assign(contestInfo, json);
    }

    const problemsPath = path.join(contestPath, "problems");
    if (fs.existsSync(problemsPath)) {
      const problemFolders = fs.readdirSync(problemsPath);
      for (const folder of problemFolders) {
        const problemInfo = getProblemInfo(
          path.join(problemsPath, folder),
          path.join("contests", contest, "problems", folder),
        );
        contestInfo.problems.push(problemInfo);
      }
    }
    contests.push(contestInfo);
  }
  return contests;
}

export interface SubmissionRecord {
  submission_id?: string;
  problem_name?: string;
  problem_link?: string;
  status?: string;
  time?: string;
  memory?: string;
  language?: string;
  submit_time?: string;
  [key: string]: unknown;
}

export interface SubmissionWithContest extends SubmissionRecord {
  contestName: string;
  contestDate: string;
  platform: string;
  contestFolder: string;
  problemLetter: string;
}

/**
 * 读取全部比赛的 submissions.json，返回带比赛上下文的提交记录。
 * 用于 Dashboard 统计 / contribution 绿点图聚合。
 */
export function getAllSubmissions(): SubmissionWithContest[] {
  const contestsDir = path.join(process.cwd(), "contests");
  if (!fs.existsSync(contestsDir)) return [];

  const result: SubmissionWithContest[] = [];
  for (const contestFolder of fs.readdirSync(contestsDir)) {
    const contestPath = path.join(contestsDir, contestFolder);
    if (!fs.statSync(contestPath).isDirectory()) continue;

    const contestJson = safeParseJson(path.join(contestPath, "contest.json")) || {};
    const submissionsPath = path.join(contestPath, "submissions.json");
    if (!fs.existsSync(submissionsPath)) continue;

    const raw = safeParseJson(submissionsPath);
    if (!Array.isArray(raw)) continue;

    for (const sub of raw as SubmissionRecord[]) {
      result.push({
        ...sub,
        contestName: (contestJson.name as string) || contestFolder,
        contestDate: (contestJson.date as string) || "",
        platform: (contestJson.platform as string) || "",
        contestFolder,
        problemLetter: "",
      });
    }
  }
  return result;
}

/**
 * 总码量：所有题目已归档提交记录源码（problems/<letter>/submissions/）的字节数总和。
 * 用于 Dashboard 统计卡片（Total Code）。
 */
export function getTotalCodeBytes(): number {
  const contestsDir = path.join(process.cwd(), "contests");
  if (!fs.existsSync(contestsDir)) return 0;

  let total = 0;
  for (const contestFolder of fs.readdirSync(contestsDir)) {
    const problemsPath = path.join(contestsDir, contestFolder, "problems");
    if (!fs.existsSync(problemsPath)) continue;

    for (const problemFolder of fs.readdirSync(problemsPath)) {
      const submissionsPath = path.join(problemsPath, problemFolder, "submissions");
      if (!fs.existsSync(submissionsPath)) continue;

      for (const file of fs.readdirSync(submissionsPath)) {
        const fullPath = path.join(submissionsPath, file);
        try {
          if (fs.statSync(fullPath).isFile()) total += fs.statSync(fullPath).size;
        } catch {
          // 忽略无法 stat 的文件（如断链）
        }
      }
    }
  }
  return total;
}

export interface ReviewInfo {
  contestFolder: string;
  contestName: string;
  date: string;
  platform: string;
  path: string; // abs path to review.md
  relPath: string; // contests/<folder>/review.md
  content: string;
}

/** 扫描所有比赛的 review.md（LLM 复盘报告），按日期降序。 */
export function getReviews(): ReviewInfo[] {
  const contestsDir = path.join(process.cwd(), "contests");
  if (!fs.existsSync(contestsDir)) return [];

  const reviews: ReviewInfo[] = [];
  for (const contestFolder of fs.readdirSync(contestsDir)) {
    const contestPath = path.join(contestsDir, contestFolder);
    if (!fs.statSync(contestPath).isDirectory()) continue;

    const reviewPath = path.join(contestPath, "review.md");
    if (!fs.existsSync(reviewPath)) continue;

    const contestJson = safeParseJson(path.join(contestPath, "contest.json")) || {};
    let content = "";
    try {
      content = fs.readFileSync(reviewPath, "utf-8");
    } catch {
      continue;
    }

    reviews.push({
      contestFolder,
      contestName: (contestJson.name as string) || contestFolder,
      date: (contestJson.date as string) || "",
      platform: (contestJson.platform as string) || "",
      path: reviewPath,
      relPath: path.join("contests", contestFolder, "review.md"),
      content,
    });
  }

  return reviews.sort((a, b) => b.date.localeCompare(a.date));
}
