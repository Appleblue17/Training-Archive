"use client";

import { Download, FileText, Home } from "lucide-react";
import Link from "next/link";
import { useEffect, useState } from "react";

import FileViewerPDF from "./file-viewer-pdf";
import FileViewerSource from "./file-viewer-source";
import FileViewerMarkdown from "./file-viewer-markdown";
import MetaDataDisplay from "@/components/metadata-display";
import ResourceGate from "@/components/resource-gate";
import {
  ProtectedContentType,
  ProtectedFilePageDataType,
  ProtectedPayloadType,
} from "@/lib/types";

type ProtectedFileViewerPageProps = {
  contest: string;
  file: string;
  problem?: string;
  fileMetadataBanner?: string[];
  /** 题目目录下的子目录，如 "submissions" */
  subdir?: string;
  /** 加密后的 { content, fileMetadata, contestMetadata, problemMetadata } */
  payload: ProtectedPayloadType;
};

function base64ToBytes(b64: string): Uint8Array {
  const bin = atob(b64);
  const bytes = new Uint8Array(bin.length);
  for (let i = 0; i < bin.length; i++) bytes[i] = bin.charCodeAt(i);
  return bytes;
}

function contentToBlob(content: ProtectedContentType): Blob {
  if (content.kind === "pdf" || content.kind === "other") {
    return new Blob([base64ToBytes(content.base64 ?? "")], {
      type: content.mime ?? "application/octet-stream",
    });
  }
  return new Blob([content.raw ?? ""], { type: "text/plain;charset=utf-8" });
}

function ProtectedFileBody({
  contest,
  file,
  problem,
  fileMetadataBanner,
  subdir,
  data,
}: ProtectedFileViewerPageProps & { data: ProtectedFilePageDataType }) {
  const { content, fileMetadata, contestMetadata, problemMetadata } = data;
  const ext = "." + (file.split(".").pop() ?? "");
  // 客户端生成 Blob URL（SSR 阶段没有 URL.createObjectURL，放到 effect 里）
  const [blobUrl, setBlobUrl] = useState<string | null>(null);
  useEffect(() => {
    const url = URL.createObjectURL(contentToBlob(content));
    setBlobUrl(url);
    return () => URL.revokeObjectURL(url);
  }, [content]);

  let viewer = null;
  if (content.kind === "markdown") {
    viewer = <FileViewerMarkdown raw={content.raw ?? ""} htmlContent={content.html ?? ""} />;
  } else if (content.kind === "source") {
    viewer = <FileViewerSource code={content.raw ?? ""} ext={ext} />;
  } else if (content.kind === "pdf") {
    viewer = blobUrl ? (
      <FileViewerPDF pdfPath={blobUrl} />
    ) : (
      <p className="text-gray-400">加载中…</p>
    );
  }

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
                {subdir && (
                  <>
                    <span className="px-2 text-lg text-slate-300">/</span>
                    {subdir}
                  </>
                )}
              </>
            )}
            <span className="px-2 text-lg text-slate-300">/</span>
            {file}
          </p>
          <div className="absolute right-8 top-2 flex items-center gap-2">
            {blobUrl && (
              <>
                <a
                  href={blobUrl}
                  download={file}
                  className="rounded bg-gray-700 px-3 py-1 text-sm text-white hover:bg-gray-600"
                >
                  <Download className="mr-2 inline-block size-4" />
                  Download
                </a>
                <a
                  href={blobUrl}
                  target="_blank"
                  rel="noopener noreferrer"
                  className="rounded bg-gray-700 px-3 py-1 text-sm text-white hover:bg-gray-600"
                >
                  <FileText className="mr-2 inline-block size-4" />
                  Raw File
                </a>
              </>
            )}
          </div>
        </header>
        <main className="mt-4 flex w-full items-start justify-center gap-4">
          <div className="flex-grow">
            {content.kind === "other" ? (
              <div className="relative flex h-[85dvh] w-full min-w-0 max-w-full items-center justify-center rounded border-2 border-gray-600 bg-zinc-800">
                <div className="flex flex-col items-center">
                  <p className="text-xl text-gray-400">
                    This file type is not supported for viewing.
                  </p>
                  {blobUrl && (
                    <div className="mt-4 flex items-center justify-center gap-4">
                      <a
                        href={blobUrl}
                        download={file}
                        className="rounded bg-gray-700 px-3 py-1 text-base text-white hover:bg-gray-600"
                      >
                        <Download className="mr-2 inline-block size-4" />
                        Download
                      </a>
                      <a
                        href={blobUrl}
                        target="_blank"
                        rel="noopener noreferrer"
                        className="rounded bg-gray-700 px-3 py-1 text-base text-white hover:bg-gray-600"
                      >
                        <FileText className="mr-2 inline-block size-4" />
                        Raw File
                      </a>
                    </div>
                  )}
                </div>
              </div>
            ) : (
              viewer
            )}
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

export default function ProtectedFileViewerPage(props: ProtectedFileViewerPageProps) {
  return (
    <ResourceGate payload={props.payload}>
      {(plaintext) => (
        <ProtectedFileBody {...props} data={JSON.parse(plaintext) as ProtectedFilePageDataType} />
      )}
    </ResourceGate>
  );
}
