import Breadcrumb from "./breadcrumb";

export default async function Layout({ children }: { children: React.ReactNode }) {
  return (
    <div className="mt-4 flex w-full justify-center">
      <div className="relative mx-auto w-3/5 min-w-[64rem] px-4">
        <header className="w-full rounded-lg py-4 text-slate-300">
          <h1 className="text-3xl font-semibold tracking-wide">Training Archive</h1>
        </header>
        <Breadcrumb />
        <main className="my-4">{children}</main>
      </div>
    </div>
  );
}
