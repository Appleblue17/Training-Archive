import type { SearchIndexEntryType } from "@/lib/types";

/** 搜索字段，按优先级排序。 */
const SEARCH_FIELDS: (keyof SearchIndexEntryType)[] = [
  "name",
  "letter",
  "tags",
  "contest",
  "platform",
  "date",
];

/** 把一条索引记录拼成小写可搜索文本。 */
export function entryToSearchable(entry: SearchIndexEntryType): string {
  return SEARCH_FIELDS.flatMap((field) => {
    const value = entry[field];
    if (Array.isArray(value)) return value.map(String);
    return [String(value ?? "")];
  })
    .join(" ")
    .toLowerCase();
}

/** 索引中出现过的全部标签，去重并排序。 */
export function getAllTags(entries: SearchIndexEntryType[]): string[] {
  const set = new Set<string>();
  for (const entry of entries) for (const tag of entry.tags) set.add(tag);
  return Array.from(set).sort();
}

/**
 * 关键词 + 标签过滤：查询按空白拆成 token，需全部命中；标签需全部命中。
 * 逻辑与搜索页展示一致，便于单独测试。
 */
export function filterEntries(
  entries: SearchIndexEntryType[],
  query: string,
  selectedTags: string[],
): SearchIndexEntryType[] {
  const tokens = query
    .toLowerCase()
    .split(/\s+/)
    .filter((t) => t.length > 0);

  return entries.filter((entry) => {
    const haystack = entryToSearchable(entry);
    const matchesQuery = tokens.every((token) => haystack.includes(token));
    const matchesTags =
      selectedTags.length === 0 || selectedTags.every((tag) => entry.tags.includes(tag));
    return matchesQuery && matchesTags;
  });
}

/** 按每页条数切页，页码越界时钳制到有效范围。 */
export function paginate<T>(
  items: T[],
  page: number,
  perPage: number,
): { page: number; totalPages: number; items: T[] } {
  const safePerPage = Math.max(1, perPage);
  const totalPages = Math.max(1, Math.ceil(items.length / safePerPage));
  const current = Math.min(Math.max(1, Math.floor(page) || 1), totalPages);
  return {
    page: current,
    totalPages,
    items: items.slice((current - 1) * safePerPage, current * safePerPage),
  };
}
