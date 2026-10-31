import Link from "next/link";

import ContestTable from "./[page]/contest-table";

import { ITEMS_PER_PAGE } from "@/lib/global";
import { getContests } from "@/lib/contests-data";
import { isProtectedContestFolder } from "@/lib/resource-protection";

/**
 * 首页视图（服务端组件）：按页码渲染竞赛列表与分页。
 * `/`（page1）与 `/pageN` 共用。
 */
export default async function HomeView({ pageNum }: { pageNum: number }) {
  // 显式按日期降序排序（最新在前），不依赖 readdir 的目录顺序。
  // 资源保护（方案 A：只保护文件内容）：元数据（比赛名/题目/状态）正常公开，
  // 只给受保护比赛打一个锁标记；点进文件查看页/复盘页时才需要密码。
  const contests = getContests()
    .sort((a, b) => `${b.date} ${b.name}`.localeCompare(`${a.date} ${a.name}`))
    .map((contest) => {
      const folder = contest.rel_path.split("/")[1] ?? "";
      return isProtectedContestFolder(folder) ? { ...contest, protected: true } : contest;
    });
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
