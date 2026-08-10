import fs from "fs";
import path from "path";

import renderMarkdown from "@/utils/render-markdown";
import FileViewerMarkdown from "@/components/file-viewer/file-viewer-markdown";

export default async function ReadmePage() {
  const readmePath = path.join(process.cwd(), "README.md");
  let readme: string | null = null;
  try {
    if (fs.existsSync(readmePath)) readme = fs.readFileSync(readmePath, "utf-8");
  } catch {
    readme = null;
  }

  const html = readme ? await renderMarkdown(readme) : null;

  if (!readme || !html) {
    return (
      <div className="flex h-[85dvh] items-center justify-center rounded border-2 border-gray-600 bg-[#0d1117]">
        <p className="text-center text-gray-400">README.md not found.</p>
      </div>
    );
  }

  return <FileViewerMarkdown raw={readme} htmlContent={html} />;
}
