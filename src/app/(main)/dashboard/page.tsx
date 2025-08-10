import { BASE_URL } from "@/lib/global";

export default function DashboardPage() {
  /* Not implemented yet... Show a placeholder */
  return (
    <>
      <div className="flex h-[80dvh] w-full flex-col items-center justify-center">
        <img
          src={BASE_URL + "work-in-progress.png"}
          alt="Work in progress"
          className="mb-4 h-48 w-48"
        />

        <div className="text-2xl font-semibold text-gray-400">
          Dashboard is under construction...
        </div>
      </div>
      <a
        href="https://www.flaticon.com/free-icons/under-construction"
        title="under construction icons"
        className="mt-48"
      >
        · Under construction icons created by Freepik - Flaticon
      </a>
    </>
  );
}
