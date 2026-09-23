import fs from "fs";
import path from "path";
import type { Metadata } from "next";
import SearchClient from "./search-client";
import { SearchIndexEntryType } from "@/lib/types";

export const metadata: Metadata = {
  title: "Search",
};

// search-index.json is generated at build time by
// scripts/generate-search-index.mjs (part of `pnpm build`).
// Fall back to an empty index so the page never crashes in dev.
function readSearchIndex(): SearchIndexEntryType[] {
  const indexPath = path.join(process.cwd(), "public", "search-index.json");
  try {
    const raw = JSON.parse(fs.readFileSync(indexPath, "utf-8"));
    if (Array.isArray(raw.entries)) return raw.entries as SearchIndexEntryType[];
    return [];
  } catch {
    return [];
  }
}

export default function SearchPage() {
  const entries = readSearchIndex();

  return (
    <div className="w-full">
      <SearchClient entries={entries} />
    </div>
  );
}
