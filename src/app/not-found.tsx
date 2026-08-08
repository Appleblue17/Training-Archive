import Link from "next/link";
import { SearchX } from "lucide-react";

import { Button } from "@/components/ui/button";
import { PREFIX_URL } from "@/lib/global";
import { joinUrl } from "@/utils/url";

export default function NotFound() {
  return (
    <div className="flex min-h-[50vh] flex-col items-center justify-center gap-4 p-8 text-center">
      <SearchX className="size-10 text-gray-500" aria-hidden />
      <h2 className="text-lg font-semibold text-slate-100">Page not found</h2>
      <p className="max-w-md text-sm text-gray-400">
        The page you are looking for does not exist or has been moved.
      </p>
      <Button asChild>
        <Link href={joinUrl(PREFIX_URL, "")}>Back to contest list</Link>
      </Button>
    </div>
  );
}
