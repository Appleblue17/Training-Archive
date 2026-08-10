import fs from "fs";
import path from "path";
import FileViewerPage from "@/components/file-viewer/file-viewer-page";

import getFileMetadata from "@/utils/get-file-metadata";

export async function generateStaticParams() {
  const contestsDir = path.join(process.cwd(), "contests");
  if (!fs.existsSync(contestsDir)) return [];
  const contests = fs.readdirSync(contestsDir);

  const params = [];
  for (const contest of contests) {
    const problemsDir = path.join(contestsDir, contest, "problems");
    if (!fs.existsSync(problemsDir)) continue;
    const problems = fs.readdirSync(problemsDir);
    for (const problem of problems) {
      const submissionsDir = path.join(problemsDir, problem, "submissions");
      if (!fs.existsSync(submissionsDir)) continue;
      const files = fs.readdirSync(submissionsDir);
      for (const file of files) {
        const filePath = path.join(submissionsDir, file);
        if (fs.statSync(filePath).isDirectory()) continue;
        params.push({
          contest,
          problem,
          file,
        });
      }
    }
  }
  return params;
}

export default async function SubmissionFilePage(props: {
  params: Promise<{ contest: string; problem: string; file: string }>;
}) {
  const params = await props.params;
  const contest = decodeURIComponent(params.contest);
  const problem = decodeURIComponent(params.problem);
  const file = decodeURIComponent(params.file);

  const contestMetadata = getFileMetadata(
    path.join(process.cwd(), "contests", contest),
    path.join(process.cwd(), "contests", contest, "contest.json"),
  );

  const problemMetadata = getFileMetadata(
    path.join(process.cwd(), "contests", contest, "problems", problem),
    path.join(process.cwd(), "contests", contest, "problems", problem, "problem.json"),
  );

  const fileMetadata = getFileMetadata(
    path.join(process.cwd(), "contests", contest, "problems", problem, "submissions", file),
    path.join(
      process.cwd(),
      "contests",
      contest,
      "problems",
      problem,
      "submissions",
      file + ".json",
    ),
  );

  return (
    <FileViewerPage
      contest={contest}
      contestMetadata={contestMetadata}
      file={file}
      fileMetadata={fileMetadata}
      problem={problem}
      problemMetadata={problemMetadata}
      fileMetadataBanner={["problem_link"]}
      subdir="submissions"
    />
  );
}
