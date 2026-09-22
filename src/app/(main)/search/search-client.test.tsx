import { render, screen } from "@testing-library/react";
import userEvent from "@testing-library/user-event";
import type { ReactNode } from "react";
import { describe, expect, it, vi } from "vitest";

import SearchClient from "@/app/(main)/search/search-client";
import type { SearchIndexEntryType } from "@/lib/types";

vi.mock("next/link", () => ({
  default: ({
    href,
    children,
    className,
    target,
    rel,
  }: {
    href?: unknown;
    children?: ReactNode;
    className?: string;
    target?: string;
    rel?: string;
  }) => (
    <a
      href={typeof href === "string" ? href : "#"}
      className={className}
      target={target}
      rel={rel}
    >
      {children}
    </a>
  ),
}));

function entries(n: number): SearchIndexEntryType[] {
  return Array.from({ length: n }, (_, i) => ({
    type: "problem" as const,
    contest: "Contest A",
    date: "2026-01-01",
    platform: "qoj",
    letter: String.fromCharCode(65 + (i % 26)),
    name: `Problem ${i}`,
    tags: i % 2 === 0 ? ["math"] : [],
    viewFile: "statement.pdf",
    contestFolder: "2026-01-01 Contest A",
    contestPath: "contests/2026-01-01 Contest A",
    relPath: `contests/2026-01-01 Contest A/problems/${i}`,
  }));
}

describe("SearchClient 分页", () => {
  it("每页 20 条，翻页显示剩余条目", async () => {
    const user = userEvent.setup();
    render(<SearchClient entries={entries(25)} />);

    expect(screen.getByText(/25 problems indexed/)).toBeInTheDocument();
    expect(screen.getByRole("navigation", { name: /pagination/i })).toBeInTheDocument();
    expect(screen.queryByText(/Problem 24/)).toBeNull();

    await user.click(screen.getByRole("button", { name: "Next" }));
    expect(screen.getByText(/Problem 24/)).toBeInTheDocument();
    expect(screen.queryByText(/Problem 0/)).toBeNull();
  });

  it("输入查询后回到第 1 页", async () => {
    const user = userEvent.setup();
    render(<SearchClient entries={entries(25)} />);

    await user.click(screen.getByRole("button", { name: "Next" }));
    expect(screen.getByText(/Problem 24/)).toBeInTheDocument();

    await user.type(screen.getByLabelText("Search problems"), "Problem");
    expect(screen.getByText(/page 1\/2/)).toBeInTheDocument();
  });
});
