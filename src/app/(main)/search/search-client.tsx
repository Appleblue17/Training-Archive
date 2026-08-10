"use client";
import { Search } from "lucide-react";
import { useMemo, useState } from "react";
import Link from "next/link";

import { SearchIndexEntryType } from "@/lib/types";
import { joinUrl } from "@/utils/url";
import { cn } from "@/lib/utils";
import PlatformBadge from "@/components/platform-badge";
import { Input } from "@/components/ui/input";

// Fields that are searched, in priority order.
const SEARCH_FIELDS: (keyof SearchIndexEntryType)[] = [
  "name",
  "letter",
  "tags",
  "contest",
  "platform",
  "date",
];

function entryToSearchable(entry: SearchIndexEntryType): string {
  return SEARCH_FIELDS.flatMap((field) => {
    const value = entry[field];
    if (Array.isArray(value)) return value.map(String);
    return [String(value ?? "")];
  })
    .join(" ")
    .toLowerCase();
}

export default function SearchClient({ entries }: { entries: SearchIndexEntryType[] }) {
  const [query, setQuery] = useState("");
  const [selectedTags, setSelectedTags] = useState<string[]>([]);

  // All tags present in the index, for tag-based filtering.
  const allTags = useMemo(() => {
    const set = new Set<string>();
    for (const entry of entries) for (const tag of entry.tags) set.add(tag);
    return Array.from(set).sort();
  }, [entries]);

  const results = useMemo(() => {
    const tokens = query
      .toLowerCase()
      .split(/\s+/)
      .filter((t) => t.length > 0);

    return entries.filter((entry) => {
      const haystack = entryToSearchable(entry);
      const matchesQuery = tokens.every((token) => haystack.includes(token));
      const matchesTags =
        selectedTags.length === 0 ||
        selectedTags.every((tag) => entry.tags.includes(tag));
      return matchesQuery && matchesTags;
    });
  }, [entries, query, selectedTags]);

  const totalMatches = results.length;
  const hasQueryOrTags = query.trim().length > 0 || selectedTags.length > 0;

  return (
    <div className="w-full">
      <h1 className="mb-4 text-2xl font-semibold text-slate-200">Search</h1>

      {/* Search input */}
      <div className="relative mb-4">
        <Search className="pointer-events-none absolute left-3 top-1/2 size-5 -translate-y-1/2 text-gray-400" />
        <Input
          type="search"
          value={query}
          onChange={(e) => setQuery(e.target.value)}
          placeholder="Search problems, contests, tags, platforms..."
          aria-label="Search problems"
          className="pl-10"
        />
      </div>

      {/* Tag filter */}
      {allTags.length > 0 && (
        <div className="mb-4 flex flex-wrap items-center gap-1.5" role="group" aria-label="Filter by tag">
          <span className="mr-1 text-sm text-gray-400">Tags:</span>
          {allTags.map((tag) => {
            const active = selectedTags.includes(tag);
            return (
              <button
                key={tag}
                onClick={() =>
                  setSelectedTags((prev) =>
                    active ? prev.filter((t) => t !== tag) : [...prev, tag],
                  )
                }
                className={cn(
                  "rounded-full px-2.5 py-0.5 text-xs transition-colors",
                  active
                    ? "bg-indigo-600 text-white"
                    : "bg-gray-700 text-indigo-200 hover:bg-gray-600",
                )}
                aria-pressed={active}
              >
                {tag}
              </button>
            );
          })}
        </div>
      )}

      {/* Result count */}
      <p className="mb-4 text-sm text-gray-400" aria-live="polite">
        {hasQueryOrTags ? `${totalMatches} result${totalMatches === 1 ? "" : "s"}` : `${entries.length} problems indexed`}
      </p>

      {/* Results */}
      {hasQueryOrTags && results.length === 0 ? (
        <p className="py-8 text-center text-gray-400">
          No results. Try fewer keywords or clear the tag filter.
        </p>
      ) : (
        <ul className="space-y-1">
          {results.map((entry) => {
            const href = entry.viewFile
              ? joinUrl(
                  "/",
                  "view",
                  entry.contestFolder,
                  "problems",
                  entry.letter,
                  entry.viewFile,
                )
              : entry.link || entry.contestLink || "#";
            const isExternal = !entry.viewFile;
            return (
              <li
                key={entry.contestFolder + "/" + entry.letter}
                className=" border border-gray-700 bg-gray-800/60 px-4 py-2 transition-colors hover:border-gray-500 hover:bg-gray-800"
              >
                <div className="flex flex-wrap items-center gap-x-3 gap-y-1">
                  <Link
                    href={href}
                    {...(isExternal
                      ? { target: "_blank", rel: "noopener noreferrer" }
                      : {})}
                    className="text-base font-medium text-slate-100 hover:text-blue-300"
                  >
                    {entry.letter}. {entry.name}
                  </Link>
                  <PlatformBadge platform={entry.platform} />
                  <span className="text-sm text-gray-400">{entry.contest}</span>
                  <span className="text-xs text-gray-500">{entry.date}</span>
                </div>
                {entry.tags.length > 0 && (
                  <div className="mt-1.5 flex flex-wrap gap-1.5">
                    {entry.tags.map((tag) => (
                      <span
                        key={tag}
                        className="rounded bg-indigo-900/60 px-1.5 py-0.5 text-xs text-indigo-200"
                      >
                        {tag}
                      </span>
                    ))}
                  </div>
                )}
              </li>
            );
          })}
        </ul>
      )}
    </div>
  );
}
