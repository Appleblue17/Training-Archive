"use client";
import { FiAlertTriangle } from "react-icons/fi";
import { useEffect, useState } from "react";

function getTimeDiffString(date: Date) {
  const now = new Date();
  const diffMs = now.getTime() - date.getTime();
  const diffMin = Math.floor(diffMs / 60000);
  const diffHour = Math.floor(diffMin / 60);
  const diffDay = Math.floor(diffHour / 24);

  if (diffDay >= 1) {
    const remainHour = diffHour % 24;
    const dayStr = diffDay === 1 ? "day" : "days";
    const hourStr = remainHour === 1 ? "hour" : "hours";
    if (remainHour > 0) {
      return `${diffDay} ${dayStr} ${remainHour} ${hourStr}`;
    } else return `${diffDay} ${dayStr}`;
  } else if (diffHour >= 1) {
    const hourStr = diffHour === 1 ? "hour" : "hours";
    return `${diffHour} ${hourStr}`;
  } else if (diffMin >= 1) {
    const minStr = diffMin === 1 ? "minute" : "minutes";
    return `${diffMin} ${minStr}`;
  } else {
    return "Just now";
  }
}

export default function CrawlerStatus({ minTimeISO }: { minTimeISO: string | null }) {
  const [statusTime, setStatusTime] = useState<string>("Unknown");
  const [isUpToDate, setIsUpToDate] = useState<boolean>(false);

  useEffect(() => {
    if (!minTimeISO) return;
    const update = () => {
      const d = new Date(minTimeISO);
      setStatusTime(getTimeDiffString(d));
      setIsUpToDate(d.getTime() > Date.now() - 1000 * 60 * 60 * 24);
    };
    update();
    const timer = setInterval(update, 60 * 1000); // Update every minute
    return () => clearInterval(timer);
  }, [minTimeISO]);

  if (!minTimeISO) {
    return (
      <span className="text-red-400">
        Last update time not available
        <FiAlertTriangle className="ml-2 inline size-5" />
      </span>
    );
  }
  return isUpToDate ? (
    <span className="text-green-400" title={minTimeISO}>
      Updated {statusTime} ago
    </span>
  ) : (
    <span className="text-gray-300" title={minTimeISO}>
      Updated {statusTime} ago
    </span>
  );
}
