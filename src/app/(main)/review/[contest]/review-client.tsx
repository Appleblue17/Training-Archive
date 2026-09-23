"use client";

import Link from "next/link";

import PlatformBadge from "@/components/platform-badge";
import ResourceGate from "@/components/resource-gate";
import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { joinUrl } from "@/utils/url";
import { ProtectedPayloadType } from "@/lib/types";
import ReviewTimeline from "./review-timeline";

export interface TimelineSubmissionData {
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

export interface ReviewData {
  name: string;
  date: string;
  platform: string;
  link?: string;
  contestFolder: string;
  problemCount: number;
  submissions: TimelineSubmissionData[];
  reviewHtml: string | null;
}

/**
 * 复盘页渲染。普通比赛直接渲染 data；
 * 受保护比赛由服务端构建时加密成 payload，客户端输密码解密后渲染。
 */
export default function ReviewClient({
  data,
  payload,
}: {
  data?: ReviewData;
  payload?: ProtectedPayloadType;
}) {
  if (payload) {
    return (
      <ResourceGate payload={payload}>
        {(plaintext) => <ReviewBody data={JSON.parse(plaintext) as ReviewData} />}
      </ResourceGate>
    );
  }
  if (!data) return null;
  return <ReviewBody data={data} />;
}

function ReviewBody({ data }: { data: ReviewData }) {
  const { name, date, platform, link, contestFolder, problemCount, submissions, reviewHtml } =
    data;

  return (
    <div className="w-full space-y-6">
      {/* 比赛信息 */}
      <Card className="p-4">
        <div className="flex flex-wrap items-center gap-2">
          <h1 className="text-xl font-semibold text-slate-100">{name}</h1>
          <PlatformBadge platform={platform} />
          <span className="text-sm text-gray-400">{date}</span>
          {link && (
            <a
              href={link}
              target="_blank"
              rel="noopener noreferrer"
              className="text-sm text-blue-300 hover:text-blue-200"
            >
              Contest link ↗
            </a>
          )}
        </div>
        <div className="mt-2 flex flex-wrap gap-x-4 gap-y-1 text-sm text-gray-400">
          <span>{problemCount} problems</span>
          <span>{submissions.length} submissions</span>
        </div>
      </Card>

      {/* 提交时间轴 */}
      <ReviewTimeline submissions={submissions} contestFolder={contestFolder} />

      {/* LLM 复盘报告 */}
      {reviewHtml && (
        <Card asChild>
          <section aria-label="Review report">
            <CardHeader className="pb-2">
              <CardTitle>Review Report</CardTitle>
            </CardHeader>
            <CardContent>
              <div
                className="markdown-body rounded border border-gray-700 p-4"
                dangerouslySetInnerHTML={{ __html: reviewHtml }}
              />
              <div className="mt-3 text-right">
                <Link
                  href={joinUrl("/", "view", "contests", contestFolder, "review.md")}
                  target="_blank"
                  rel="noopener noreferrer"
                  className="text-sm text-blue-300 hover:text-blue-200"
                >
                  View raw markdown ↗
                </Link>
              </div>
            </CardContent>
          </section>
        </Card>
      )}
    </div>
  );
}
