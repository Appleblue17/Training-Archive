import * as React from "react";
import { cva, type VariantProps } from "class-variance-authority";

import { cn } from "@/lib/utils";

const badgeVariants = cva(
  "inline-flex items-center gap-1 rounded-lg px-2 py-0.5 text-xs font-normal transition-colors",
  {
    variants: {
      variant: {
        default: "bg-blue-800 text-slate-100",
        secondary: "bg-gray-700 text-slate-200",
        success: "bg-green-800 text-slate-100",
        warning: "bg-yellow-800 text-slate-100",
        destructive: "bg-red-800 text-slate-100",
        info: "bg-indigo-800 text-slate-100",
        outline: "border border-gray-600 text-slate-200",
      },
    },
    defaultVariants: {
      variant: "default",
    },
  },
);

export interface BadgeProps
  extends React.HTMLAttributes<HTMLSpanElement>,
    VariantProps<typeof badgeVariants> {}

function Badge({ className, variant, ...props }: BadgeProps) {
  return <span className={cn(badgeVariants({ variant }), className)} {...props} />;
}

export { Badge, badgeVariants };
