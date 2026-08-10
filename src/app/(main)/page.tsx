import HomeView from "./(home)/home-view";

/**
 * 根路径 `/`：竞赛列表第 1 页（修复静态导出无 index.html 导致的 404）。
 */
export default function RootPage() {
  return <HomeView pageNum={1} />;
}
