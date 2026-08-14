import Image from "next/image";
import Breadcrumb from "./breadcrumb";
import { BASE_URL } from "@/lib/global";

export default async function Layout({ children }: { children: React.ReactNode }) {
  return (
    <div className="mt-4 flex w-full justify-center">
      <div className="relative mx-auto w-3/5 min-w-[64rem] px-4">
        <header className="relative w-full rounded-lg py-4 text-slate-300">
          {/* logo 绝对定位突出到主栏左侧对齐线的左边；文字与下边主栏左缘对齐 */}
          <Image
            src={BASE_URL + "archive-bot.png"}
            alt=""
            width={60}
            height={60}
            className="absolute -left-14 top-1/2 h-10 w-10 -translate-y-1/2 select-none"
            unoptimized
            priority
          />
          <h1 className="text-3xl font-semibold tracking-wide">Training Archive</h1>
        </header>
        <Breadcrumb />
        <main className="my-4">{children}</main>
      </div>
    </div>
  );
}
