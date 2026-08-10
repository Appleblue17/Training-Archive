import fs from "fs";
import path from "path";
import LogPage from "./log-page";
import { logFileList } from "@/lib/global";

export default function Page() {
  const fileContentList = logFileList.map((file) => {
    const filePath = path.join(process.cwd(), file.path);
    try {
      return fs.readFileSync(filePath, "utf-8");
    } catch {
      // 日志是运行时产物（被 gitignore，不提交版本控制）：
      // deploy 分支 / 全新 clone 无日志文件属预期，返回空串由前端渲染占位提示
      return "";
    }
  });

  return <LogPage fileContentList={fileContentList} />;
}
