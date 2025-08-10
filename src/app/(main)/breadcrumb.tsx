"use client";
import Link from "next/link";
import { FiBarChart2, FiEdit3, FiHome, FiInfo } from "react-icons/fi";
import { usePathname } from "next/navigation";
import clsx from "clsx";

const links = [
  {
    title: "Home",
    name: "home",
    href: "/",
    icon: FiHome,
  },
  {
    title: "Dashboard",
    name: "dashboard",
    href: "/dashboard",
    icon: FiBarChart2,
  },
  {
    title: "Log",
    name: "log",
    href: "/log",
    icon: FiEdit3,
  },
  {
    title: "README.md",
    name: "readme",
    href: "/readme",
    icon: FiInfo,
  },
];

export default function Breadcrumb() {
  const pathname: string = usePathname();
  // const [isHovered, setIsHovered] = useState<{ [key: string]: boolean }>({
  //   home: false,
  //   dashboard: false,
  //   log: false,
  //   readme: false,
  // });
  console.log(pathname);

  return (
    <nav className="flex h-12 w-full items-center space-x-4 overflow-y-visible rounded-lg bg-gray-700 px-6 py-2 text-sm shadow">
      {links.map((link) => {
        const isActive =
          pathname === link.href || (link.name !== "home" && pathname.startsWith(link.href));
        return (
          <button
            className={clsx("border-b-1 flex flex-none justify-center px-4 py-1", {
              "relative h-14 rounded-lg bg-gray-600 text-white": isActive,
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
