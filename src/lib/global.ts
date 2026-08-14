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

// /status 页面展示的状态文件（deploy 分支入库跟踪，可被前端展示）：
// config / last-update / 各平台 staged-submissions / subscriptions 目录。
// 日志与临时产物（global.log.json、platforms/*/log.json 等）不入库、不展示。
export const statusFileList = [
  {
    name: "Last Update",
    path: "crawler/last-update.json",
    type: "json",
    category: "global",
  },
  {
    name: "Config",
    path: "crawler/config.json",
    type: "json",
    category: "global",
  },
  {
    name: "Subscriptions",
    path: "crawler/subscriptions",
    type: "dir",
    category: "global",
  },
  {
    name: "Staged Submissions",
    path: "crawler/platforms/qoj/staged-submissions.json",
    type: "json",
    category: "qoj",
  },
  {
    name: "Staged Submissions",
    path: "crawler/platforms/hdu/staged-submissions.json",
    type: "json",
    category: "hdu",
  },
  {
    name: "Staged Submissions",
    path: "crawler/platforms/nowcoder/staged-submissions.json",
    type: "json",
    category: "nowcoder",
  },
];

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
