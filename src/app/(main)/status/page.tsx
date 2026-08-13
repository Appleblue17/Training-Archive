import fs from "fs";
import path from "path";
import StatusPage from "./status-page";
import { statusFileList } from "@/lib/global";

export default function Page() {
  const fileContentList = statusFileList.map((file) => {
    const filePath = path.join(process.cwd(), file.path);
    try {
      if (file.type === "dir") {
        // 目录：读取所有非 example 的 .json 订阅文件，按文件名合并展示
        const files = fs
          .readdirSync(filePath)
          .filter((f) => f.endsWith(".json") && !f.includes(".example."))
          .sort();
        const merged: Record<string, unknown> = {};
        for (const f of files) {
          const key = f.replace(/\.json$/, "");
          try {
            merged[key] = JSON.parse(fs.readFileSync(path.join(filePath, f), "utf-8"));
          } catch {
            merged[key] = "(parse error)";
          }
        }
        return JSON.stringify(merged, null, 2);
      }
      return fs.readFileSync(filePath, "utf-8");
    } catch {
      // 状态文件是爬虫运行产物：deploy 分支入库；本地开发 / 全新 clone
      // 无状态文件属预期，返回空串由前端渲染占位提示
      return "";
    }
  });

  return <StatusPage fileContentList={fileContentList} />;
}
