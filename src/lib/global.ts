const isProd = process.env.NODE_ENV === "production";

// fork 部署参数（构建时环境变量可覆盖，默认 appleblue17 部署值）：
//   NEXT_PUBLIC_REPO_URL   仓库地址（页脚、README 页、Actions 链接）
//   NEXT_PUBLIC_SITE_URL   站点根域名（GitHub Pages 为 https://<user>.github.io）
//   NEXT_PUBLIC_BASE_PATH  仓库子路径（GitHub Pages project site 为 /<repo>，根部署留空）
export const REPO_URL =
  process.env.NEXT_PUBLIC_REPO_URL ??
  "https://github.com/appleblue17/Training-Archive/";

export const SITE_URL =
  process.env.NEXT_PUBLIC_SITE_URL ?? "https://appleblue17.github.io";

const basePath = (
  process.env.NEXT_PUBLIC_BASE_PATH ?? "/Training-Archive"
).replace(/^\/+|\/+$/g, "");
export const BASE_PATH = basePath;

export const BASE_URL = isProd
  ? `${SITE_URL}${basePath ? "/" + basePath : ""}/`
  : "http://localhost:3000/";

export const PREFIX_URL = isProd ? (basePath ? "/" + basePath : "/") : "/";

export const ITEMS_PER_PAGE = 20;

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
    path: "crawler/platforms/qoj/log.json",
    type: "log",
    category: "qoj",
  },
  {
    name: "Staged Submissions",
    path: "crawler/platforms/qoj/staged-submissions.json",
    type: "json",
    category: "qoj",
  },
  {
    name: "Log",
    path: "crawler/platforms/hdu/log.json",
    type: "log",
    category: "hdu",
  },
  {
    name: "Staged Submissions",
    path: "crawler/platforms/hdu/staged-submissions.json",
    type: "json",
    category: "hdu",
  },
  {
    name: "Log",
    path: "crawler/platforms/nowcoder/log.json",
    type: "log",
    category: "nowcoder",
  },
  {
    name: "Staged Submissions",
    path: "crawler/platforms/nowcoder/staged-submissions.json",
    type: "json",
    category: "nowcoder",
  },
];
