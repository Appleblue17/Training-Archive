const isProd = process.env.NODE_ENV === "production";

export const REPO_URL = "https://github.com/appleblue17/Training-Archive/";

export const BASE_URL = isProd
  ? "https://appleblue17.github.io/Training-Archive/"
  : "http://localhost:3000/";

export const PREFIX_URL = isProd ? "/Training-Archive" : "/";

export const allowedExtensions = [
  ".pdf",
  ".md",
  ".txt",
  ".js",
  ".ts",
  ".tsx",
  ".jsx",
  ".py",
  ".cpp",
  ".c",
  ".h",
  ".hpp",
  ".java",
  ".json",
  ".yml",
  ".yaml",
  ".sh",
  ".bat",
  ".go",
  ".rs",
  ".cs",
  ".html",
  ".css",
  ".xml",
];

export const logFileList = [
  {
    name: "Global Log",
    path: "crawler/global.log.json",
    type: "log",
    category: "global",
  },
  {
    name: "Last Update",
    path: "crawler/last-update.json",
    type: "json",
    category: "global",
  },
  {
    name: "Log",
    path: "crawler/qoj/log.json",
    type: "log",
    category: "qoj",
  },
  {
    name: "Staged Submissions",
    path: "crawler/qoj/staged-submissions.json",
    type: "json",
    category: "qoj",
  },
  {
    name: "Log",
    path: "crawler/hdu/log.json",
    type: "log",
    category: "hdu",
  },
  {
    name: "Staged Submissions",
    path: "crawler/hdu/staged-submissions.json",
    type: "json",
    category: "hdu",
  },
  {
    name: "Log",
    path: "crawler/nowcoder/log.json",
    type: "log",
    category: "nowcoder",
  },
  {
    name: "Staged Submissions",
    path: "crawler/nowcoder/staged-submissions.json",
    type: "json",
    category: "nowcoder",
  },
];
