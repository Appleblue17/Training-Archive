import "@/lib/globals.css";
import { inter } from "@public/fonts/fonts";
import { FiGithub } from "react-icons/fi";
import { REPO_URL } from "@/lib/global";

export const experimental_ppr = true;

export default function RootLayout({ children }: { children: React.ReactNode }) {
  return (
    <html lang="en" suppressHydrationWarning>
      <head>
        <meta charSet="UTF-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1" />
        <link rel="icon" type="image/png" href="archive-bot.png" />
        <title>Training Archive</title>
      </head>
      <body className={`${inter.className} antialiased`}>
        {children}
        <footer className="my-4">
          <p className="mt-0 border-t border-gray-700 pt-4 text-center text-sm text-gray-400">
            © 2025 Training Archive ·{" "}
            <a
              href={REPO_URL}
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
      </body>
    </html>
  );
}
