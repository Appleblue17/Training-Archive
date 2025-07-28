import { FiGithub } from "react-icons/fi";
import Breadcrumb from "./breadcrumb";

export default async function Layout({ children }: { children: React.ReactNode }) {
  return (
    <div className="mt-4 flex min-h-screen min-w-[1600px] justify-center">
      <div className="mx-auto w-3/4 -translate-x-10">
        <header className="w-full rounded-lg py-4 text-slate-300">
          <h1 className="text-3xl font-semibold tracking-wide">Training Archive</h1>
        </header>
        <Breadcrumb />
        <main className="my-4">{children}</main>
        <footer className="my-4">
          <p className="mt-8 border-t border-gray-700 pt-4 text-center text-sm text-gray-400">
            © 2025 Training Archive ·{" "}
            <a
              href="https://github.com/Appleblue17/Training-Archive"
              target="_blank"
              rel="noopener noreferrer"
              className="hover:text-blue-300"
            >
              <FiGithub className="mr-1 inline" />
              GitHub
            </a>{" "}
            · MIT License
          </p>
          <p className="mt-2 text-center text-sm text-gray-400">
            Designed and developed by
            <a
              href="https://github.com/Appleblue17"
              target="_blank"
              rel="noopener noreferrer"
              className="px-1 text-blue-400 hover:text-blue-300"
            >
              Appleblue17
            </a>
          </p>
          <p className="mt-2 text-center text-xs text-gray-500">
            Disclaimer: This project is for educational purposes only. Use at your own risk.
          </p>
        </footer>
      </div>
    </div>
  );
}
