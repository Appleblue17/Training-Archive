import { FileMetadataType } from "@/lib/types";
import { formatKey, formatSize, formatDate } from "@/utils/format";

export default function MetaDataDisplay({
  name,
  metadata,
  metadataBanner = [],
}: {
  name?: string;
  metadata: FileMetadataType;
  metadataBanner?: string[];
}) {
  if (!metadata) return null;

  return (
    <div className="overflow-auto">
      {name && <h2 className="px-1 py-1 text-sm font-medium text-gray-300">{name}</h2>}
      <div className="rounded border-2 border-gray-400 bg-black/80 px-2 py-3 font-mono text-sm text-green-300">
        {Object.entries(metadata).map(([key, value]) => {
          if (metadataBanner.includes(key)) {
            return null; // Skip keys in the banner
          }
          const keyDisplay = <span className="text-blue-400">[{formatKey(key)}]</span>;
          let valueDisplay;
          if (key === "size" && typeof value === "number") {
            valueDisplay = <span className="text-yellow-400">{formatSize(value)}</span>;
          } else if (key.includes("time_limit") || key === "time") {
            if (typeof value === "number")
              valueDisplay = <span className="text-yellow-400">{value} s</span>;
            else valueDisplay = <span className="text-yellow-400">{String(value)}</span>;
          } else if (key.includes("memory_limit") || key === "memory") {
            if (typeof value === "number")
              valueDisplay = <span className="text-yellow-400">{value} MB</span>;
            else valueDisplay = <span className="text-yellow-400">{String(value)}</span>;
          } else if (key.includes("time")) {
            valueDisplay = <span className="text-pink-400">{formatDate(value)}</span>;
          } else if (
            (key.includes("date") || key.includes("duration")) &&
            typeof value === "string"
          ) {
            valueDisplay = <span className="text-pink-400">{value}</span>;
          } else if (key === "tags" && Array.isArray(value)) {
            valueDisplay = (
              <span className="inline-flex flex-wrap gap-1">
                {value.map((tag) => (
                  <span
                    key={String(tag)}
                    className="rounded bg-indigo-900/60 px-1.5 py-0.5 text-xs text-indigo-200"
                  >
                    {String(tag)}
                  </span>
                ))}
              </span>
            );
          } else if (key.includes("link") && typeof value === "string") {
            valueDisplay = (
              <a
                href={value}
                target="_blank"
                rel="noopener noreferrer"
                className="text-indigo-400 underline hover:text-indigo-200"
              >
                {value}
              </a>
            );
          } else if (typeof value === "number") {
            valueDisplay = <span className="text-yellow-300">{value}</span>;
          } else if (typeof value === "boolean") {
            valueDisplay = <span className="text-cyan-400">{value ? "true" : "false"}</span>;
          } else if (typeof value === "object" && value !== null) {
            valueDisplay = <span className="text-gray-400">{JSON.stringify(value)}</span>;
          } else {
            valueDisplay = <span className="text-green-200">{String(value)}</span>;
          }
          return (
            <div
              key={key}
              className="mb-1 break-all"
              style={{ textIndent: "-1.2em", paddingLeft: "1.2em" }}
            >
              {keyDisplay} {valueDisplay}
            </div>
          );
        })}
      </div>
    </div>
  );
}
