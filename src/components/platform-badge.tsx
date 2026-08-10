import clsx from "clsx";

// 已知平台颜色；未知平台统一使用灰色 fallback
const PLATFORM_COLORS: Record<string, string> = {
  qoj: "bg-indigo-800",
  hdu: "bg-amber-800",
  nowcoder: "bg-emerald-800",
  codeforces: "bg-lime-800",
};

export default function PlatformBadge({ platform }: { platform: string }) {
  if (!platform) return null;
  return (
    <span
      className={clsx(
        "mr-1 select-none rounded-lg px-2 py-0.5 text-xs font-normal text-gray-200 opacity-90",
        PLATFORM_COLORS[platform] ?? "bg-gray-600",
      )}
    >
      {platform}
    </span>
  );
}
