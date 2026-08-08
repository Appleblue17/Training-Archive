export default function Loading() {
  return (
    <div className="w-full space-y-6 p-8" role="status" aria-label="Loading">
      <span className="sr-only">Loading...</span>
      <div className="h-8 w-48 animate-pulse rounded bg-gray-800" />
      <div className="space-y-3">
        <div className="h-16 animate-pulse rounded-lg border border-gray-700 bg-gray-800/60" />
        <div className="h-16 animate-pulse rounded-lg border border-gray-700 bg-gray-800/60" />
        <div className="h-16 animate-pulse rounded-lg border border-gray-700 bg-gray-800/60" />
      </div>
      <div className="flex gap-2">
        <div className="h-9 w-24 animate-pulse rounded-md bg-gray-800" />
        <div className="h-9 w-24 animate-pulse rounded-md bg-gray-800" />
      </div>
    </div>
  );
}
