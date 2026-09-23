export interface FileMetadataType {
  name?: string;
  modified_time?: Date;
  size?: number; // Size in bytes, optional for directories
  [key: string]: unknown; // Allow additional properties
}

export interface CodeFileType extends FileMetadataType {
  status?: "AC" | "WA" | "TLE" | "RE" | "CE";
  solve_time?: Date; // Time when the problem was first solved
  submit_time?: Date; // Time when the code was submitted
}

export interface ProblemInfoType {
  rel_path: string;
  name?: string;
  link?: string;
  solved?: boolean;
  submit_time?: Date;
  solve_time?: Date;
  tags?: string[]; // Problem tags (e.g. from QOJ), optional
  files: FileMetadataType[];
  [key: string]: unknown; // Allow additional properties
}

export interface ContestInfoType {
  rel_path: string;
  link?: string;
  date: string;
  name: string;
  start_time?: Date;
  end_time?: Date;
  platform: string;
  problems: ProblemInfoType[];
  files: FileMetadataType[];
  /** 资源保护：仅用于列表显示锁标记；元数据公开，文件内容在查看页需密码。 */
  protected?: boolean;
  [key: string]: unknown; // Allow additional properties
}

// One entry in the build-time search index (scripts/generate-search-index.mjs).
export interface SearchIndexEntryType {
  type: "problem";
  contest: string;
  date: string;
  platform: string;
  contestLink?: string;
  letter: string;
  name: string;
  link?: string;
  tags: string[];
  viewFile: string;
  contestFolder: string;
  contestPath: string;
  relPath: string;
}

// ---- 资源保护（静态版：构建时加密、浏览器端解密）----

/** 构建时由服务端生成、传给客户端解密的密文载荷。 */
export interface ProtectedPayloadType {
  v: 1;
  alg: "AES-256-GCM";
  /** PBKDF2 迭代次数 */
  iter: number;
  /** base64 盐（本轮构建内复用） */
  salt: string;
  /** base64 初始向量 */
  iv: string;
  /** base64 密文 + GCM tag */
  data: string;
}

/** 受保护文件查看页整体加密的数据：内容 + 元数据（避免题目名/标签等泄露）。 */
export interface ProtectedFilePageDataType {
  content: ProtectedContentType;
  fileMetadata: FileMetadataType;
  contestMetadata: FileMetadataType;
  problemMetadata?: FileMetadataType;
}

/** 解密后的受保护文件内容（JSON 序列化前的形状）。 */
export interface ProtectedContentType {
  kind: "markdown" | "source" | "pdf" | "other";
  /** markdown / source 的原始文本 */
  raw?: string;
  /** markdown 服务端预渲染的 HTML */
  html?: string;
  /** pdf / other 的原始字节（base64） */
  base64?: string;
  mime?: string;
}
