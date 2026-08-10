#!/usr/bin/env node
/**
 * Build-time search index generator (C2).
 *
 * Scans `contests/` and writes a problem-level search index to
 * `public/search-index.json`. The index is a plain JSON array so the
 * search page can be fully static: it reads the file at build time and
 * passes it to a client component for filtering.
 *
 * Run before `next build` (see package.json). Also safe to run
 * standalone, e.g. for a dev build or debugging.
 */
import fs from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";

const repoRoot = path.resolve(path.dirname(fileURLToPath(import.meta.url)), "..");
const contestsDir = path.join(repoRoot, "contests");
const outFile = path.join(repoRoot, "public", "search-index.json");

function safeReadJson(filePath) {
  try {
    return JSON.parse(fs.readFileSync(filePath, "utf-8"));
  } catch (err) {
    console.warn(`[search-index] failed to parse ${filePath}: ${err.message}`);
    return null;
  }
}

/**
 * Build the search index.
 * Each entry describes one problem plus its contest context, so a single
 * query can match problem name, tags, contest name, platform and date.
 *
 * @returns {Array<object>}
 */
export function buildSearchIndex() {
  const entries = [];

  if (!fs.existsSync(contestsDir)) {
    console.warn(`[search-index] ${contestsDir} does not exist; index is empty.`);
    return entries;
  }

  for (const contestFolder of fs.readdirSync(contestsDir)) {
    const contestPath = path.join(contestsDir, contestFolder);
    if (!fs.statSync(contestPath).isDirectory()) continue;

    const contestJson = safeReadJson(path.join(contestPath, "contest.json"));
    const contestName = contestJson?.name ?? contestFolder;
    const date = contestJson?.date ?? "";
    const platform = contestJson?.platform ?? "";
    const contestLink = contestJson?.link ?? "";

    const problemsDir = path.join(contestPath, "problems");
    if (!fs.existsSync(problemsDir)) continue;

    for (const letter of fs.readdirSync(problemsDir)) {
      const problemPath = path.join(problemsDir, letter);
      if (!fs.statSync(problemPath).isDirectory()) continue;

      const problemJson = safeReadJson(path.join(problemPath, "problem.json"));
      const name = problemJson?.name ?? "";
      const link = problemJson?.link ?? "";
      const tags = Array.isArray(problemJson?.tags) ? problemJson.tags : [];

      // File used to deep-link search results into the file viewer page.
      // Prefer the problem statement (statement.md/pdf); fall back to the
      // first other viewable non-JSON file (e.g. code.cpp).
      let viewFile = "";
      try {
        const files = fs
          .readdirSync(problemPath)
          .filter(
            (f) =>
              !f.endsWith(".json") && fs.statSync(path.join(problemPath, f)).isFile(),
          );
        viewFile =
          files.find((f) => f.toLowerCase() === "statement.md") ??
          files.find((f) => f.toLowerCase() === "statement.pdf") ??
          files[0] ??
          "";
      } catch {
        /* no viewable files */
      }

      entries.push({
        type: "problem",
        contest: contestName,
        date,
        platform,
        contestLink,
        letter,
        name,
        link,
        tags,
        viewFile,
        contestFolder,
        contestPath: path.join("contests", contestFolder),
        relPath: path.join("contests", contestFolder, "problems", letter),
      });
    }
  }

  return entries;
}

function main() {
  const entries = buildSearchIndex();
  const index = {
    version: 1,
    generatedAt: new Date().toISOString(),
    entries,
  };

  if (!fs.existsSync(path.dirname(outFile))) {
    fs.mkdirSync(path.dirname(outFile), { recursive: true });
  }
  fs.writeFileSync(outFile, JSON.stringify(index, null, 2));
  console.log(`[search-index] wrote ${entries.length} entries to ${path.relative(repoRoot, outFile)}`);
}

// Run directly (CLI) when this file is executed, not when imported.
if (process.argv[1] && path.resolve(process.argv[1]) === fileURLToPath(import.meta.url)) {
  main();
}
