import { render, screen } from "@testing-library/react";
import { describe, expect, it } from "vitest";

import MetaDataDisplay from "@/components/metadata-display";
import { CONTEST_METADATA_BANNER, FILE_METADATA_BANNER } from "@/lib/metadata-fields";
import type { ContestInfoType } from "@/lib/types";

describe("MetaDataDisplay", () => {
  it("跳过 banner 中的内部字段（回归：受保护比赛不显示 [ProtectedData]）", () => {
    const metadata = {
      name: "Contest A",
      date: "2026-01-01",
      rel_path: "contests/2026-01-01 Contest A",
      protected: true,
      // 历史 bug：加密载荷被挂到比赛对象上并被面板当普通字段渲染
      protectedData: { v: 1, data: "cipher" },
      protectionMisconfigured: false,
    } as unknown as ContestInfoType;

    render(<MetaDataDisplay metadata={metadata} metadataBanner={CONTEST_METADATA_BANNER} />);

    expect(screen.getByText("[Name]")).toBeInTheDocument();
    expect(screen.getByText("[Date]")).toBeInTheDocument();
    expect(screen.queryByText(/ProtectedData/i)).toBeNull();
    expect(screen.queryByText(/ProtectionMisconfigured/i)).toBeNull();
    expect(screen.queryByText("[Rel Path]")).toBeNull();
  });

  it("banner 外的字段正常渲染", () => {
    render(
      <MetaDataDisplay
        metadata={{ name: "code.cpp", size: 2048, link: "https://example.com" }}
        metadataBanner={FILE_METADATA_BANNER}
      />,
    );
    expect(screen.getByText("[Name]")).toBeInTheDocument();
    expect(screen.getByText("[Size]")).toBeInTheDocument();
    expect(screen.queryByText("[Link]")).toBeNull();
  });
});
