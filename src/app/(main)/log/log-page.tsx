"use client";
import React, { useState } from "react";
import clsx from "clsx";
import { logFileList } from "@/lib/global";
import PlatformBadge from "@/components/platform-badge";
import { FiCopy, FiX } from "react-icons/fi";
import SyntaxHighlighter from "react-syntax-highlighter";
import { atomOneDark } from "react-syntax-highlighter/dist/esm/styles/hljs";

function SideBar({
  selectedLogIdx,
  setSelectedLogIdx,
}: {
  selectedLogIdx: number;
  setSelectedLogIdx: (idx: number) => void;
}) {
  const categoryOrder = ["global", "qoj", "hdu", "nowcoder"];

  return (
    <div className="flex h-full flex-col gap-6 rounded-lg bg-zinc-800/60 p-4">
      {categoryOrder.map((cat) => (
        <div key={cat}>
          <div className="mb-2 text-xs font-bold uppercase tracking-wide text-gray-400">{cat}</div>
          <div className="flex flex-col gap-1">
            {logFileList
              .filter((item) => item.category === cat)
              .map((file) => {
                // Get the real index in logFileList
                const realIdx = logFileList.findIndex((f) => f.path === file.path);
                return (
                  <button
                    key={file.path}
                    className={clsx(
                      "w-full rounded px-4 py-1 text-left text-sm transition-colors",
                      realIdx === selectedLogIdx
                        ? "bg-indigo-800/80 font-semibold text-white"
                        : "text-gray-200 hover:bg-zinc-700",
                    )}
                    onClick={() => setSelectedLogIdx(realIdx)}
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
type LogObject = {
  platform: string;
  time: string;
  level: string;
  msg: string;
  // add other fields as needed
};

function DisplayBox({
  item,
  content,
}: {
  item: {
    name: string;
    type: string;
  };
  content: string;
}) {
  if (item.type === "log") {
    let logArr: LogObject[] = [];
    try {
      const parsed = typeof content === "string" ? JSON.parse(content) : content;
      logArr = Array.isArray(parsed) ? parsed : [parsed];
    } catch {
      return <div className="p-8 text-red-400">Invalid log format.</div>;
    }
    return (
      <div className="relative flex flex-col bg-zinc-800/80 py-4 pl-12">
        {logArr.map((logObj, idx) => (
          <div key={idx} className="relative rounded-lg p-2">
            <span className="absolute -left-8 top-2 w-8 text-right font-mono text-base text-white">
              #{idx + 1}
            </span>
            <div className="mb-2 flex flex-wrap items-center gap-1 text-xs text-gray-400">
              <PlatformBadge platform={logObj.platform} />
              <span>{logObj.time}</span>
            </div>
            <div className="relative whitespace-pre-line font-mono text-base text-gray-100">
              {(logObj.level === "error" || logObj.level === "fatal") && (
                <FiX className="absolute -left-7 -top-0.5 inline-block text-2xl text-red-500" />
              )}
              <span
                className={clsx("mr-2 font-medium uppercase", {
                  "text-green-300": logObj.level === "info",
                  "text-sky-300": logObj.level === "important",
                  "text-yellow-300": logObj.level === "warning",
                  "text-red-300": logObj.level === "error",
                  "text-red-600": logObj.level === "fatal",
                })}
              >
                [{logObj.level}]
              </span>

              <span>{logObj.msg}</span>
            </div>
          </div>
        ))}
      </div>
    );
  } else {
    let jsonStr = "";
    try {
      jsonStr = JSON.stringify(
        typeof content === "string" ? JSON.parse(content) : content,
        null,
        2,
      );
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
}

export default function LogPage({ fileContentList }: { fileContentList: string[] }) {
  const [selectedLogIdx, setSelectedLogIdx] = useState(0);

  const item = logFileList[selectedLogIdx];
  const content = fileContentList[selectedLogIdx];

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
        <FiCopy className="mr-1 inline-block" />
        {copyMessage}
      </button>
      <div className="w-52">
        <SideBar selectedLogIdx={selectedLogIdx} setSelectedLogIdx={setSelectedLogIdx} />
      </div>
      <div className="flex-1 overflow-auto">
        <DisplayBox item={item} content={content} />
      </div>
    </div>
  );
}
