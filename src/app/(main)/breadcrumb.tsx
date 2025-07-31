import Link from "next/link";
import { FiBarChart2, FiEdit3, FiHome, FiInfo } from "react-icons/fi";

export default function Breadcrumb() {
  return (
    <nav className="flex w-full items-center rounded-lg bg-gray-700 px-4 py-2 shadow">
      <div className="flex items-center space-x-10 px-3 text-sm">
        <Link
          href="/"
          className="flex items-center text-base font-medium text-blue-200 transition-colors hover:text-indigo-300"
        >
          <FiHome className="mr-2 size-5" />
          Home
        </Link>
        <Link
          href="/dashboard"
          className="flex cursor-not-allowed items-center text-base font-medium text-gray-400/60"
        >
          <FiBarChart2 className="mr-2 size-5" />
          Dashboard
        </Link>
        <Link
          href="/log"
          className="flex cursor-not-allowed items-center text-base font-medium text-gray-400/60"
        >
          <FiEdit3 className="mr-2 size-5" />
          Log
        </Link>
        <Link
          href="/readme"
          className="flex cursor-not-allowed items-center text-base font-medium text-gray-400/60"
        >
          <FiInfo className="mr-2 size-5" />
          README.md
        </Link>
      </div>
    </nav>
  );
}
