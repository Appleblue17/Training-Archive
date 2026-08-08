"use client";
import { BarChart2, Edit3, Home, Info, Search } from "lucide-react";
import Link from "next/link";
import { usePathname } from "next/navigation";
import clsx from "clsx";

const links = [
  {
    title: "Home",
    name: "home",
    href: "/",
    icon: Home,
  },
  {
    title: "Dashboard",
    name: "dashboard",
    href: "/dashboard",
    icon: BarChart2,
  },
  {
    title: "Search",
    name: "search",
    href: "/search",
    icon: Search,
  },
  {
    title: "Log",
    name: "log",
    href: "/log",
    icon: Edit3,
  },
  {
    title: "README.md",
    name: "readme",
    href: "/readme",
    icon: Info,
  },
];

export default function Breadcrumb() {
  const pathname: string = usePathname();

  return (
    <nav className="flex h-10 w-full items-center space-x-4 overflow-y-visible rounded-lg bg-gray-700 px-6 py-2 text-sm shadow">
      {links.map((link) => {
        // Home 命中 `/` 及所有 `/pageN`；其余按前缀匹配
        const isActive =
          link.name === "home"
            ? pathname === "/" || pathname.startsWith("/page")
            : pathname === link.href || pathname.startsWith(link.href);
        return (
          <button
            className={clsx("border-b-1 flex flex-none justify-center px-4 py-1", {
              "relative h-12 rounded-lg bg-gray-600 text-white": isActive,
            })}
            key={link.title}
          >
            <Link
              href={link.href}
              className="flex items-center text-base font-medium text-gray-200 transition-colors hover:text-blue-400"
            >
              <link.icon className="mr-2 size-5" />
              {link.title}
            </Link>
          </button>
        );
      })}
    </nav>
  );
}
