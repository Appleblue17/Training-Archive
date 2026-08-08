import { clsx, type ClassValue } from "clsx";
import { twMerge } from "tailwind-merge";

/** shadcn/ui 标准 cn 工具：clsx + tailwind-merge 去重冲突类。 */
export function cn(...inputs: ClassValue[]) {
  return twMerge(clsx(inputs));
}
