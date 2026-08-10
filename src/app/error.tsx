"use client";

import { useEffect } from "react";
import { AlertTriangle } from "lucide-react";

import { Button } from "@/components/ui/button";

export default function GlobalError({
  error,
  reset,
}: {
  error: Error & { digest?: string };
  reset: () => void;
}) {
  useEffect(() => {
    console.error(error);
  }, [error]);

  return (
    <div className="flex min-h-[50vh] flex-col items-center justify-center gap-4 p-8 text-center">
      <AlertTriangle className="size-10 text-amber-400" aria-hidden />
      <h2 className="text-lg font-semibold text-slate-100">Something went wrong</h2>
      <p className="max-w-md text-sm text-gray-400">
        {error.message || "An unexpected error occurred while rendering this page."}
      </p>
      <Button onClick={() => reset()}>Try again</Button>
    </div>
  );
}
