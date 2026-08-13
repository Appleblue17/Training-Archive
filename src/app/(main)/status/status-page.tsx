"use client";
import { Copy } from "lucide-react";
import React, { useState } from "react";
import clsx from "clsx";
import { statusFileList } from "@/lib/global";
import SyntaxHighlighter from "react-syntax-highlighter";
import { atomOneDark } from "react-syntax-highlighter/dist/esm/styles/hljs";

function SideBar({
  selectedIdx,
  setSelectedIdx,
}: {
  selectedIdx: number;
  setSelectedIdx: (idx: number) => void;
}) {
  const categoryOrder = ["global", "qoj", "hdu", "nowcoder"];

  return (
    <div className="flex h-full flex-col gap-6 rounded-lg bg-zinc-800/60 p-4">
      {categoryOrder.map((cat) => (
        <div key={cat}>
          <div className="mb-2 text-xs font-bold uppercase tracking-wide text-gray-400">{cat}</div>
          <div className="flex flex-col gap-1">
            {statusFileList
              .filter((item) => item.category === cat)
              .map((file) => {
                // Get the real index in statusFileList
                const realIdx = statusFileList.findIndex((f) => f.path === file.path);
                return (
                  <button
                    key={file.path}
                    className={clsx(
                      "w-full rounded px-4 py-1 text-left text-sm transition-colors",
                      realIdx === selectedIdx
                        ? "bg-indigo-800/80 font-semibold text-white"
                        : "text-gray-200 hover:bg-zinc-700",
                    )}
                    onClick={() => setSelectedIdx(realIdx)}
                  >
                    {file.name}
                  </button>
                );
              })}
          </div>
        </div>
      ))}
    </div>
  );
}

function DisplayBox({ content }: { content: string }) {
  if (!content || !content.trim()) {
    return (
      <div className="flex h-full items-center justify-center p-8 text-gray-400">
        <div className="text-center">
          <div className="text-sm">暂无状态文件</div>
          <div className="mt-1 text-xs text-gray-500">
            状态文件为爬虫运行产物（deploy 分支入库跟踪），本地开发运行爬虫后生成：
            <span className="font-mono">crawler/config.json</span> /{" "}
            <span className="font-mono">crawler/last-update.json</span> /{" "}
            <span className="font-mono">crawler/platforms/*/staged-submissions.json</span>
          </div>
        </div>
      </div>
    );
  }
  let jsonStr = "";
  try {
    jsonStr = JSON.stringify(JSON.parse(content), null, 2);
  } catch {
    jsonStr = String(content);
  }
  return (
    <pre className="relative rounded bg-zinc-900 py-4">
      <SyntaxHighlighter
        language={"json"}
        style={atomOneDark}
        showLineNumbers
        customStyle={{
          background: "transparent",
        }}
        lineNumberStyle={{
          paddingRight: "10px",
          marginRight: "15px",
          color: "#888",
          borderRight: "1px solid #444",
        }}
      >
        {jsonStr}
      </SyntaxHighlighter>
    </pre>
  );
}

export default function StatusPage({ fileContentList }: { fileContentList: string[] }) {
  const [selectedIdx, setSelectedIdx] = useState(0);

  const content = fileContentList[selectedIdx];

  const [copyMessage, setCopyMessage] = useState("Copy");
  const handleCopy = async () => {
    if (typeof navigator !== "undefined" && navigator.clipboard) {
      await navigator.clipboard.writeText(content);
      setCopyMessage("Copied!");
      setTimeout(() => setCopyMessage("Copy"), 1200);
    } else {
      setCopyMessage("Clipboard API unavailable");
      setTimeout(() => setCopyMessage("Copy"), 2000);
    }
  };

  return (
    <div className="relative flex h-[80dvh] justify-center gap-2">
      <button
        onClick={handleCopy}
        className="absolute right-6 top-4 z-10 rounded bg-gray-700 px-3 py-1 font-sans text-sm text-white hover:bg-gray-600"
      >
        <Copy className="mr-1 inline-block size-4" />
        {copyMessage}
      </button>
      <div className="w-52">
        <SideBar selectedIdx={selectedIdx} setSelectedIdx={setSelectedIdx} />
      </div>
      <div className="flex-1 overflow-auto">
        <DisplayBox content={content} />
      </div>
    </div>
  );
}
