import { Download, FileText, Home } from "lucide-react";
import path from "path";
import Link from "next/link";
import FileViewer from "./file-viewer";
import { FileMetadataType } from "@/lib/types";
import MetaDataDisplay from "@/components/metadata-display";
import { PREFIX_URL } from "@/lib/global";
import { joinUrl } from "@/utils/url";

type FileViewerPageProps = {
  contest: string;
  contestMetadata: FileMetadataType;
  file: string;
  fileMetadata: FileMetadataType;
  problem?: string;
  problemMetadata?: FileMetadataType;
  fileMetadataBanner?: string[];
};

/**
 * 竞赛级 / 题目级文件查看页的公共渲染组件。
 * 两个路由页面（[contest]/[file] 与 [problem]/[file]）仅负责静态参数生成与元数据读取，
 * 渲染逻辑统一在此。
 */
export default function FileViewerPage({
  contest,
  contestMetadata,
  file,
  fileMetadata,
  problem,
  problemMetadata,
  fileMetadataBanner,
}: FileViewerPageProps) {
  const dirPath = problem
    ? path.join("contests", contest, "problems", problem)
    : path.join("contests", contest);
  const rawFilePath = joinUrl(
    PREFIX_URL,
    "contests",
    contest,
    problem ? path.join("problems", problem) : "",
    file,
  );

  return (
    <div className="flex min-h-screen justify-center py-4">
      <div className="mx-auto w-4/5">
        <header className="relative w-full rounded-lg py-2 text-slate-300">
          <Link href="/">
            <Home className="absolute -left-10 top-3 size-6 transition-colors hover:text-gray-400" />
          </Link>
          <h1 className="text-2xl font-semibold tracking-wide">File Viewer</h1>
          <p className="ml-4 mt-2 text-base text-gray-400">
            <span className="px-2 text-lg text-gray-200">/</span>
            {contest}
            {problem && (
              <>
                <span className="px-2 text-lg text-slate-300">/</span>
                {problem}
              </>
            )}
            <span className="px-2 text-lg text-slate-300">/</span>
            {file}
          </p>
          <div className="absolute right-8 top-2 flex items-center gap-2">
            <a
              href={rawFilePath}
              download
              className="rounded bg-gray-700 px-3 py-1 text-sm text-white hover:bg-gray-600"
            >
              <Download className="mr-2 inline-block text-base" />
              Download
            </a>
            <a
              href={rawFilePath}
              target="_blank"
              rel="noopener noreferrer"
              className="rounded bg-gray-700 px-3 py-1 text-sm text-white hover:bg-gray-600"
            >
              <FileText className="mr-2 inline-block text-base" />
              Raw File
            </a>
          </div>
        </header>
        <main className="mt-4 flex w-full items-start justify-center gap-4">
          <div className="flex-grow">
            <FileViewer dirPath={dirPath} fileName={file} />
          </div>
          <div className="flex-shrink-0 basis-1/5 space-y-2 overflow-auto">
            <MetaDataDisplay
              name={"File"}
              metadata={fileMetadata}
              metadataBanner={fileMetadataBanner}
            />
            {problemMetadata && <MetaDataDisplay name={"Problem"} metadata={problemMetadata} />}
            <MetaDataDisplay name={"Contest"} metadata={contestMetadata} />
          </div>
        </main>
      </div>
    </div>
  );
}
