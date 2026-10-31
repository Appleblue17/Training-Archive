// 元数据面板要跳过的内部字段（不展示给用户）。
// 见 contest-table.tsx：受保护比赛的加密载荷等内部字段绝不能出现在面板里
// （历史 bug：首页展开详情曾显示 [ProtectedData]）。

export const FILE_METADATA_BANNER = ["link"];

export const PROBLEM_METADATA_BANNER = ["rel_path", "files", "link"];

export const CONTEST_METADATA_BANNER = [
  "rel_path",
  "problems",
  "files",
  "link",
  "protected",
  "protectedData",
  "protectionMisconfigured",
];
