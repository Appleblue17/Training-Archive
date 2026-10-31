import { ShieldAlert } from "lucide-react";

/** 受保护资源存在但构建环境未配置 RESOURCE_PASSWORD 时的提示（不渲染任何内容）。 */
export default function ProtectionNotConfigured() {
  return (
    <div className="flex min-h-[50vh] items-center justify-center py-8">
      <div className="max-w-lg rounded-lg border border-amber-700/60 bg-amber-950/30 p-6 text-center">
        <ShieldAlert className="mx-auto mb-3 size-8 text-amber-400" />
        <h2 className="text-lg font-semibold text-amber-200">受保护资源未配置密码</h2>
        <p className="mt-2 text-sm text-amber-100/80">
          该比赛受资源保护，但构建环境未设置 <code>RESOURCE_PASSWORD</code>，因此不会渲染其内容。
          请在 <code>.env</code> 或 CI secret 中配置后重新构建。
        </p>
      </div>
    </div>
  );
}
