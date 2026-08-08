import fs from "fs";
import path from "path";
import ContestTable from "./contest-table";
import Link from "next/link";

import { ITEMS_PER_PAGE } from "@/lib/global";
import { getContests } from "@/lib/contests-data";

export async function generateStaticParams() {
  const contestsDir = path.join(process.cwd(), "contests");
  const contestFolders = fs.readdirSync(contestsDir);
  const totalPages = Math.ceil(contestFolders.length / ITEMS_PER_PAGE);

  return Array.from({ length: totalPages }, (_, i) => ({
    page: `page${i + 1}`,
  }));
}

export default async function HomePage(props: { params: Promise<{ page: string }> }) {
  const params = await props.params;
  const pageParam = params.page;

  // 解析页码：page1 -> 1；非法/0 值回退到 1
  const pageNum = Math.max(1, parseInt(pageParam.replace("page", ""), 10) || 1);
  // 显式按日期降序排序（最新在前），不依赖 readdir 的目录顺序
  const contests = getContests().sort((a, b) =>
    `${b.date} ${b.name}`.localeCompare(`${a.date} ${a.name}`),
  );
  const totalPages = Math.ceil(contests.length / ITEMS_PER_PAGE);

  const start = (pageNum - 1) * ITEMS_PER_PAGE;
  const end = start + ITEMS_PER_PAGE;
  const pagedContests = contests.slice(start, end);

  return (
    <>
      <div className="overflow-x-auto">
        <ContestTable contests={pagedContests} />
      </div>
      <div className="mt-6 flex justify-center">
        <nav className="inline-flex items-center space-x-2">
          <Link
            href={`/page${pageNum - 1}`}
            className={`rounded-l bg-slate-700 px-4 py-2 text-white hover:bg-gray-600 ${
              pageNum === 1 ? "pointer-events-none opacity-50" : ""
            }`}
            aria-disabled={pageNum === 1}
          >
            Previous
          </Link>
          {Array.from({ length: totalPages }, (_, i) => (
            <Link
              key={i + 1}
              href={`/page${i + 1}`}
              className={`px-4 py-2 text-white hover:bg-gray-600 ${
                pageNum === i + 1 ? "bg-blue-800" : "bg-slate-700"
              }`}
            >
              {i + 1}
            </Link>
          ))}
          <Link
            href={`/page${pageNum + 1}`}
            className={`rounded-r bg-slate-700 px-4 py-2 text-white hover:bg-gray-600 ${
              pageNum === totalPages ? "pointer-events-none opacity-50" : ""
            }`}
            aria-disabled={pageNum === totalPages}
          >
            Next
          </Link>
        </nav>
      </div>
    </>
  );
}
