import FileViewerMarkdown from "./file-viewer-markdown";
import renderMarkdown from "@/utils/render-markdown";

export default async function FileViewerMarkdownWrapper({
  dirPath,
  raw,
}: {
  dirPath: string;
  raw: string;
}) {
  const htmlContent = await renderMarkdown(raw, dirPath);
  return <FileViewerMarkdown raw={raw} htmlContent={htmlContent} />;
}
