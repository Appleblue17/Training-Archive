import fs from "fs";
import path from "path";

import renderMarkdown from "@/utils/render-markdown";
import { Card, CardContent } from "@/components/ui/card";

export default async function ReadmePage() {
  const readmePath = path.join(process.cwd(), "README.md");
  let readme: string | null = null;
  try {
    if (fs.existsSync(readmePath)) readme = fs.readFileSync(readmePath, "utf-8");
  } catch {
    readme = null;
  }

  const html = readme ? await renderMarkdown(readme) : null;

  return (
    <Card>
      <CardContent className="p-4">
        {html ? (
          <div
            className="markdown-body"
            dangerouslySetInnerHTML={{ __html: html }}
          />
        ) : (
          <p className="py-8 text-center text-gray-400">README.md not found.</p>
        )}
      </CardContent>
    </Card>
  );
}
