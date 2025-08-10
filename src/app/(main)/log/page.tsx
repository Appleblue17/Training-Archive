import fs from "fs";
import path from "path";
import LogPage from "./log-page";
import { logFileList } from "@/lib/global";

export default function Page() {
  const fileContentList = logFileList.map((file) => {
    const filePath = path.join(process.cwd(), file.path);
    let content = "";
    try {
      content = fs.readFileSync(filePath, "utf-8");
    } catch (err) {
      content = `Error reading file: ${err}`;
    }
    return content;
  });

  return <LogPage fileContentList={fileContentList} />;
}
