import fs from "fs";
import path from "path";
import type { Metadata } from "next";

import HomeView from "../home-view";

import { ITEMS_PER_PAGE } from "@/lib/global";

export async function generateStaticParams() {
  const contestsDir = path.join(process.cwd(), "contests");
  // contests/ 不存在或为空时也输出 page1（HomeView 渲染空列表），
  // 保证 output: export 下动态路由可构建。
  if (!fs.existsSync(contestsDir)) return [{ page: "page1" }];
  const contestFolders = fs.readdirSync(contestsDir);
  const totalPages = Math.max(1, Math.ceil(contestFolders.length / ITEMS_PER_PAGE));

  return Array.from({ length: totalPages }, (_, i) => ({
    page: `page${i + 1}`,
  }));
}

export async function generateMetadata(props: {
  params: Promise<{ page: string }>;
}): Promise<Metadata> {
  const { page } = await props.params;
  const pageNum = Math.max(1, parseInt(page.replace("page", ""), 10) || 1);
  return { title: `Page ${pageNum}` };
}

export default async function HomePage(props: { params: Promise<{ page: string }> }) {
  const params = await props.params;
  const pageParam = params.page;

  // 解析页码：page1 -> 1；非法/0 值回退到 1
  const pageNum = Math.max(1, parseInt(pageParam.replace("page", ""), 10) || 1);

  return <HomeView pageNum={pageNum} />;
}
