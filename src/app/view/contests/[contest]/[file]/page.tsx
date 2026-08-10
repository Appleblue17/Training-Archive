import fs from "fs";
import path from "path";
import FileViewerPage from "@/components/file-viewer/file-viewer-page";

import getFileMetadata from "@/utils/get-file-metadata";

export async function generateStaticParams() {
  const contestsDir = path.join(process.cwd(), "contests");
  const contests = fs.readdirSync(contestsDir);

  const params = [];
  for (const contest of contests) {
    const contestDir = path.join(contestsDir, contest);
    if (!fs.existsSync(contestDir)) continue;
    const files = fs.readdirSync(contestDir);
    for (const file of files) {
      // Skip directories and contest metadata files
      const filePath = path.join(contestDir, file);
      if (fs.statSync(filePath).isDirectory() || file.endsWith(".json")) continue;
      params.push({
        contest,
        file,
      });
    }
  }
  return params;
}

export default async function FilePage(props: {
  params: Promise<{ contest: string; file: string }>;
}) {
  const params = await props.params;
  const contest = decodeURIComponent(params.contest);
  const file = decodeURIComponent(params.file);

  const contestMetadata = getFileMetadata(
    path.join(process.cwd(), "contests", contest),
    path.join(process.cwd(), "contests", contest, "contest.json"),
  );

  const fileMetadata = getFileMetadata(
    path.join(process.cwd(), "contests", contest, file),
    path.join(process.cwd(), "contests", contest, file + ".json"),
  );

  return (
    <FileViewerPage
      contest={contest}
      contestMetadata={contestMetadata}
      file={file}
      fileMetadata={fileMetadata}
    />
  );
}
