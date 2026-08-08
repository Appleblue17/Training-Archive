"use client";
import { Check, Code, X } from "lucide-react";
import clsx from "clsx";

import { PREFIX_URL } from "@/lib/global";
import { joinUrl } from "@/utils/url";
import { Badge } from "@/components/ui/badge";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";

interface TimelineSubmission {
  submissionId: string;
  problemLetter: string;
  problemName: string;
  status: string;
  language: string;
  time: string | null;
  memory: string | null;
  submitTime: string;
  submissionLink: string | null;
  sourceFile: string | null;
}

function statusColor(status: string): { text: string; dot: string } {
  switch (status) {
    case "AC":
      return { text: "text-green-400", dot: "bg-green-400" };
    case "WA":
      return { text: "text-red-400", dot: "bg-red-400" };
    case "TLE":
    case "TL":
      return { text: "text-yellow-400", dot: "bg-yellow-400" };
    case "RE":
    case "MLE":
      return { text: "text-purple-400", dot: "bg-purple-400" };
    case "CE":
      return { text: "text-orange-400", dot: "bg-orange-400" };
    default:
      return { text: "text-gray-400", dot: "bg-gray-400" };
  }
}

export default function ReviewTimeline({
  submissions,
  contestFolder,
}: {
  submissions: TimelineSubmission[];
  contestFolder: string;
}) {
  if (submissions.length === 0) {
    return (
      <Card>
        <CardHeader className="py-3">
          <CardTitle>Submission Timeline</CardTitle>
        </CardHeader>
        <CardContent>
          <p className="py-4 text-center text-sm text-gray-500">No submissions for this contest.</p>
        </CardContent>
      </Card>
    );
  }

  const sourceHref = (letter: string, file: string) =>
    joinUrl(PREFIX_URL, "view", contestFolder, "problems", letter, file);

  return (
    <Card>
      <CardHeader className="py-3">
        <CardTitle>
          Submission Timeline
          <span className="ml-2 text-xs font-normal text-gray-500">
            {submissions.length} submissions · chronological
          </span>
        </CardTitle>
      </CardHeader>
      <CardContent>
      <ol className="relative ml-2 border-l-2 border-gray-700 pl-6">
        {submissions.map((sub) => {
          const sc = statusColor(sub.status);
          const isAC = sub.status === "AC";
          return (
            <li key={sub.submissionId} className="relative pb-5 last:pb-0">
              {/* 时间线圆点 */}
              <span
                className={clsx(
                  "absolute -left-[31px] top-1 size-3 rounded-full ring-4 ring-gray-800/60",
                  sc.dot,
                )}
                aria-hidden
              />
              <div className="flex flex-wrap items-center gap-x-3 gap-y-1">
                <span className="font-mono text-xs text-gray-500">
                  {new Date(sub.submitTime).toLocaleString()}
                </span>
                <span className="text-sm font-medium text-slate-100">
                  {sub.problemLetter}. {sub.problemName}
                </span>
                <span className={clsx("inline-flex items-center gap-1 text-sm font-medium", sc.text)}>
                  {isAC ? <Check className="size-4" /> : <X className="size-4" />}
                  {sub.status || "UKN"}
                </span>
                {sub.language && (
                  <Badge variant="secondary">{sub.language}</Badge>
                )}
                {sub.time && (
                  <span className="text-xs text-gray-500">{sub.time} ms</span>
                )}
                {sub.memory && (
                  <span className="text-xs text-gray-500">{sub.memory} MB</span>
                )}
                <span className="ml-auto flex items-center gap-2">
                  {sub.sourceFile && (
                    <a
                      href={sourceHref(sub.problemLetter, sub.sourceFile)}
                      className="inline-flex items-center gap-1 text-sm text-blue-300 hover:text-blue-200"
                      title={`View source (${sub.sourceFile})`}
                    >
                      <Code className="size-4" />
                      Source
                    </a>
                  )}
                  {sub.submissionLink && (
                    <a
                      href={sub.submissionLink}
                      target="_blank"
                      rel="noopener noreferrer"
                      className="text-xs text-gray-400 hover:text-gray-200"
                    >
                      ↗
                    </a>
                  )}
                </span>
              </div>
            </li>
          );
        })}
      </ol>
      </CardContent>
    </Card>
  );
}
