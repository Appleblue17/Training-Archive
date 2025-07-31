import Breadcrumb from "./breadcrumb";
import fs from "fs";
import path from "path";
import { FiAlertTriangle, FiCheck, FiGlobe } from "react-icons/fi";

import { REPO_URL } from "@/lib/global";

function getTimeDiffString(date: Date) {
  const now = new Date();
  const diffMs = now.getTime() - date.getTime();
  const diffMin = Math.floor(diffMs / 60000);
  const diffHour = Math.floor(diffMin / 60);
  const diffDay = Math.floor(diffHour / 24);
  if (diffDay > 1) return `${diffDay} days`;
  else if (diffDay === 1) return "1 day";
  else if (diffHour > 1) return `${diffHour} hours`;
  else if (diffHour === 1) return "1 hour";
  else if (diffMin > 1) return `${diffMin} minutes`;
  else return "Just now";
}

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

  let statusTime: string = "Unknown";
  let isUpToDate: boolean = false;

  if (minTime) {
    statusTime = getTimeDiffString(minTime);
    isUpToDate = minTime.getTime() > Date.now() - 1000 * 60 * 60 * 24; // 24 hours
  }
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
          {minTime ? (
            isUpToDate ? (
              <span className="text-green-400">
                Updated {statusTime} ago
                <FiCheck className="ml-2 inline size-5" />
              </span>
            ) : (
              <span className="text-yellow-400">
                Updated {statusTime} ago
                <FiAlertTriangle className="ml-2 inline size-5" />
              </span>
            )
          ) : (
            <span className="text-red-400">
              Last update time not available
              <FiAlertTriangle className="ml-2 inline size-5" />
            </span>
          )}
        </a>
        <Breadcrumb />
        <main className="my-4">{children}</main>
      </div>
    </div>
  );
}
