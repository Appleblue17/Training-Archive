// 轻量 URL 拼接工具。
// 客户端组件不能依赖 Node 的 path 模块（仅靠 Next 的 polyfill），统一用此函数。
export function joinUrl(...parts: string[]): string {
  const joined = parts
    .map((p) => p.replace(/^\/+|\/+$/g, ""))
    .filter((p) => p.length > 0)
    .join("/");
  // 若第一个段以 "/" 开头（如 PREFIX_URL 为 "/"），保留根路径前缀
  return parts.length > 0 && parts[0].startsWith("/") ? "/" + joined : joined;
}
