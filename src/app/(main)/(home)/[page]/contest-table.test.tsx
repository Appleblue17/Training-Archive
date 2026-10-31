import { render, screen } from "@testing-library/react";
import userEvent from "@testing-library/user-event";
import type { ReactNode } from "react";
import { describe, expect, it, vi } from "vitest";

import ContestTable from "@/app/(main)/(home)/[page]/contest-table";
import type { ContestInfoType } from "@/lib/types";

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

function makeContest(overrides: Partial<ContestInfoType> = {}): ContestInfoType {
  return {
    rel_path: "contests/2026-01-01 Contest A",
    date: "2026-01-01",
    name: "Contest A",
    platform: "qoj",
    link: "https://qoj.ac/contest/1",
    problems: [
      {
        rel_path: "contests/2026-01-01 Contest A/problems/A",
        name: "Two Sum",
        letter: "A",
        files: [],
        solved: true,
        solve_time: new Date("2026-01-01T02:00:00Z"),
      },
    ],
    files: [],
    ...overrides,
  };
}

describe("ContestTable", () => {
  it("受保护比赛显示锁标记与无障碍标签", () => {
    render(<ContestTable contests={[makeContest({ protected: true })]} />);
    expect(screen.getByText("Protected")).toBeInTheDocument();
    expect(screen.getByLabelText(/受保护/)).toBeInTheDocument();
  });

  it("普通比赛不显示锁标记", () => {
    render(<ContestTable contests={[makeContest()]} />);
    expect(screen.queryByText("Protected")).toBeNull();
  });

  it("展开详情不渲染内部字段（[ProtectedData] 回归）", async () => {
    const user = userEvent.setup();
    const contest = makeContest({ protected: true });
    // 模拟历史 bug：把加密载荷/内部标记挂到比赛对象上
    (contest as Record<string, unknown>).protectedData = { v: 1, data: "cipher" };
    (contest as Record<string, unknown>).protectionMisconfigured = true;

    render(<ContestTable contests={[contest]} />);
    await user.click(screen.getByRole("button", { name: /Contest A/ }));

    expect(await screen.findByRole("heading", { name: "Contest" })).toBeInTheDocument();
    expect(screen.queryByText(/ProtectedData/i)).toBeNull();
    expect(screen.queryByText(/ProtectionMisconfigured/i)).toBeNull();
  });
});
