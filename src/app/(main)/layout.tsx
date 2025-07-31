import Breadcrumb from "./breadcrumb";
import fs from "fs";
import path from "path";
import { FiGlobe } from "react-icons/fi";

import { REPO_URL } from "@/lib/global";
import CrawlerStatus from "./crawler-status";

export default async function Layout({ children }: { children: React.ReactNode }) {
  const updateTimeDir = path.join(process.cwd(), "crawler", "last-update.json");
  const updateTime = fs.existsSync(updateTimeDir)
    ? JSON.parse(fs.readFileSync(updateTimeDir, "utf-8"))
    : null;

  let minTime: Date | null = null;
  if (updateTime) {
    const times = Object.values(updateTime)
      .map((t) => new Date(t as string))
      .filter((d) => !isNaN(d.getTime()));
    if (times.length > 0) {
      minTime = times.reduce((a, b) => (a < b ? a : b));
    }
  }

  const minTimeISO = minTime?.toISOString() ?? null;
  const actionURL = path.join(REPO_URL, "actions");

  return (
    <div className="mt-4 flex min-h-screen min-w-[1600px] justify-center">
      <div className="relative mx-auto w-3/4 -translate-x-10">
        <header className="w-full rounded-lg py-4 text-slate-300">
          <h1 className="text-3xl font-semibold tracking-wide">Training Archive</h1>
        </header>
        {/* Crawler status */}
        <a
          href={actionURL}
          target="_blank"
          rel="noopener noreferrer"
          className="absolute right-0 top-4 flex items-center gap-3 rounded-lg bg-zinc-700/80 px-4 py-2 text-sm transition-colors duration-150 hover:bg-zinc-600/80"
        >
          <FiGlobe className="size-5 text-stone-400" />
          <CrawlerStatus minTimeISO={minTimeISO} />
        </a>
        <Breadcrumb />
        <main className="my-4">{children}</main>
      </div>
    </div>
  );
}
