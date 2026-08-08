// 格式化工具函数：元数据展示与各处共用

export function formatKey(key: string) {
  return key.replace(/_/g, " ").replace(/\b\w/g, (c) => c.toUpperCase());
}

export function formatSize(size: number) {
  if (size < 1024) return `${size} B`;
  if (size < 1024 * 10) return `${(size / 1024).toFixed(3)} KB (${size} B)`;
  if (size < 1024 * 1024) return `${(size / 1024).toFixed(2)} KB`;
  return `${(size / 1024 / 1024).toFixed(2)} MB`;
}

export function formatDate(val: unknown) {
  const d = typeof val === "string" ? new Date(val) : val;
  if (d instanceof Date && !isNaN(d.getTime())) {
    return d
      .toLocaleString("zh-CN", {
        year: "numeric",
        month: "2-digit",
        day: "2-digit",
        hour: "2-digit",
        minute: "2-digit",
        second: "2-digit",
        hour12: false,
        timeZone: "Asia/Shanghai",
      })
      .replace(/-/g, "/");
  }
  return String(val);
}
