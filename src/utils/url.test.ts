import { describe, expect, it } from "vitest";

import { joinUrl } from "@/utils/url";

describe("joinUrl", () => {
  it("拼接并去掉多余斜杠", () => {
    expect(joinUrl("/view/", "/contests/", "/x/")).toBe("/view/contests/x");
  });

  it("保留首段前导斜杠", () => {
    expect(joinUrl("/", "view", "contests/a", "x.md")).toBe("/view/contests/a/x.md");
  });

  it("首段无前导斜杠时不添加", () => {
    expect(joinUrl("view", "a")).toBe("view/a");
  });
});
