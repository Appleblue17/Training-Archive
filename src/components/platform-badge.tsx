import clsx from "clsx";

export default function PlatformBadge({ platform }: { platform: string }) {
  if (!platform) return null;
  return (
    <span
      className={clsx(
        "mr-1 select-none rounded-lg px-2 py-0.5 text-xs font-normal text-gray-200 opacity-90",
        {
          "bg-indigo-800": platform === "qoj",
          "bg-amber-800": platform === "hdu",
          "bg-emerald-800": platform === "nowcoder",
          "bg-lime-800": platform === "codeforces",
          "bg-gray-600":
            platform !== "qoj" &&
            platform !== "hdu" &&
            platform !== "nowcoder" &&
            platform === "codeforces",
        },
      )}
    >
      {platform}
    </span>
  );
}
