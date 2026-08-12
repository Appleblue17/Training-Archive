import type { NextConfig } from "next";
const isProd = process.env.NODE_ENV === "production";

// fork 部署参数：仓库子路径（GitHub Pages project site 为 /<repo>，根域名部署留空）。
// 构建时可用 NEXT_PUBLIC_BASE_PATH 覆盖，默认 /Training-Archive（appleblue17 部署值）。
const basePath = (process.env.NEXT_PUBLIC_BASE_PATH ?? "/Training-Archive").replace(
  /^\/+|\/+$/g,
  "",
);
const prefix = basePath ? `/${basePath}` : "";

const nextConfig: NextConfig = {
  /* config options here */
  ...(isProd && {
    output: "export",
    ...(prefix ? { basePath: prefix, assetPrefix: `${prefix}/` } : {}),
  }),
};

export default nextConfig;
