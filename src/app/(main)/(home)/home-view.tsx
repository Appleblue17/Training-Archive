import Link from "next/link";

import ContestTable from "./[page]/contest-table";

import { ITEMS_PER_PAGE } from "@/lib/global";
import { getContests } from "@/lib/contests-data";

/**
 * 首页视图（服务端组件）：按页码渲染竞赛列表与分页。
 * `/`（page1）与 `/pageN` 共用。
 */
export default async function HomeView({ pageNum }: { pageNum: number }) {
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
      {/* v0.1.0 样式：表格比容器宽 144px，题目列自然延伸到框右侧（可见），不包裹 overflow 容器 */}
      <ContestTable contests={pagedContests} />
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
