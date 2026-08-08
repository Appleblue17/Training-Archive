import rehypeKatex from "rehype-katex";
import rehypeSanitize from "rehype-sanitize";
import rehypeStringify from "rehype-stringify";
import rehypeFormat from "rehype-format";
import remarkMath from "remark-math";
import remarkGfm from "remark-gfm";
import remarkParse from "remark-parse";
import remarkRehype from "remark-rehype";
import rehypeHighlight from "rehype-highlight";
import remarkImgLinks from "@pondorasti/remark-img-links";

import { unified } from "unified";

/**
 * 服务端 Markdown → HTML 渲染（unified 流水线）。
 * 与文件查看器共用同一管线：remark-parse → remark-math → remark-gfm →
 * remark-img-links → remark-rehype → rehype-sanitize → rehype-highlight →
 * rehype-katex → rehype-format → rehype-stringify。
 *
 * 数学公式预处理：`$$\n...\n$$` 改写为 `$$$$\n...\n$$$$` 以适配 KaTeX 流水线。
 */
export default async function renderMarkdown(
  raw: string,
  dirPath?: string,
): Promise<string> {
  const mathRegex = /\$\$([^$\n]*)\$\$/g;
  const rawWithMath = raw.replace(mathRegex, "$$$$\n$1\n$$$$\n");

  const file = await unified()
    .use(remarkParse)
    .use(remarkMath)
    .use(remarkGfm)
    .use(remarkImgLinks, { absolutePath: (dirPath ?? "") + "/" })
    .use(remarkRehype)
    .use(rehypeSanitize)
    .use(rehypeHighlight, { detect: true })
    .use(rehypeKatex)
    .use(rehypeFormat)
    .use(rehypeStringify)
    .process(rawWithMath);

  return String(file.value);
}
