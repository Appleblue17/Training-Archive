import re
import sys
import os
from bs4 import BeautifulSoup as bs4, Tag
from datetime import datetime, timedelta, timezone

beijing = timezone(timedelta(hours=8))
now = datetime.now(beijing)
from urllib.parse import urljoin
from selenium.webdriver.common.by import By

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "../..")))
from crawler.base import BaseCrawler


class NOWCODERCrawler(BaseCrawler):
    def __init__(self, local_log_path="crawler/nowcoder/log.json"):
        super().__init__("nowcoder", local_log_path)
        self.contests_path = "crawler/nowcoder/contests.json"
        self.submissions_path = "crawler/nowcoder/staged-submissions.json"
        self.input_contests_path = "crawler/nowcoder/input_contests.json"

    def is_logged_in(self, link):
        main_page = self.fetch_page_with_browser(link)

        # Check if login was successful
        success = self.username in main_page
        return success

    def try_login_with_cookie(self, cookies):
        link = "https://ac.nowcoder.com/"

        self.driver.get(link)
        for cookie_name, cookie_value in cookies.items():
            self.driver.add_cookie({"name": cookie_name, "value": cookie_value})
        self.driver.refresh()
        self._random_sleep()

        if not self.is_logged_in(link):
            self.log("fatal", "Login failed with provided credentials.")
        else:
            self.log("info", "Login successful with cookies.")

    def login(self):
        cookies = {
            "NOWCODERUID": os.getenv("NEWCODER_COOKIE_NOWCODERUID"),
            "t": os.getenv("NEWCODER_COOKIE_T"),
        }

        self.try_login_with_cookie(cookies)

    def fetch_contests_get_contest_list(self):
        """
        Fetch the list of contests from the website, and return a list of contest information.
        Return a dictionary with the following required keys:
        - name: The name of the contest
        - date: The date of the contest in ISO format (YYYY-MM-DD)
        - platform: The platform name (in this case, "nowcoder")
        - start_time: The start time of the contest in ISO format (YYYY-MM-DDTHH:MM:SS)
        - end_time: The end time of the contest in ISO format (YYYY-MM-DDTHH:MM:SS)
        - link: The link to the contest
        """

        input_contest_list = self._load_file(self.input_contests_path)
        contest_infos = []
        for input_contest in input_contest_list:
            if "link" not in input_contest:
                self.log("error", "Input contest does not have a link.")
                continue
            contest_link = input_contest["link"]

            contest_page = self.fetch_page_with_browser(contest_link)
            soup = bs4(contest_page, "html.parser")

            contest_name_element = (
                soup.find("div", class_="topic-banner").find("h1").find("span")
            )
            contest_name = contest_name_element.text.strip()

            # Contest time format example: "2025-07-15 12:00:00 至 2025-07-15 17:00:00"
            # Convert it to ISO format
            contest_time_element = soup.find("p", class_="match-time").find("span")
            contest_time_raw = contest_time_element.text.strip()
            contest_time_parts = contest_time_raw.split(" 至 ")
            if len(contest_time_parts) != 2:
                self.log(
                    "error",
                    f"Contest time format is incorrect: {contest_time_raw}. Skipping contest {contest_name}.",
                )
                continue
            start_time_str = contest_time_parts[0].strip()
            end_time_str = contest_time_parts[1].strip()
            start_time = self._convert_iso_to_beijing(start_time_str)
            end_time = self._convert_iso_to_beijing(end_time_str)

            contest_date = start_time.date().isoformat()

            if start_time > now:
                # Contest is in the future, skip it
                self.log(
                    "info",
                    f"Contest {contest_name} has not started yet. Skipping.",
                )
                continue

            contest_info = {
                "name": contest_name,
                "date": contest_date,
                "platform": "nowcoder",
                "start_time": start_time.isoformat(),
                "end_time": end_time.isoformat(),
                "link": contest_link,
            }
            contest_infos.append(contest_info)

        return contest_infos

    def fetch_contests_get_problem_list(self, contest_info, contest_folder):
        """
        Fetch the list of problems in a contest. You can also perform other operations like downloading the contest attachments.
        Return a dictionary with the following required keys:
        - letter: The letter of the problem (e.g., "A", "B", "C", etc.)
        - name: The name of the problem
        - link: The link to the problem page
        """
        contest_name = contest_info["name"]
        contest_link = contest_info["link"]

        # Go into the contest page to fetch more details
        contest_page = self.fetch_page_with_browser(contest_link)
        soup = bs4(contest_page, "html.parser")

        problem_table = (
            soup.find("div", class_="nk-main")
            .find("div", class_="module-box")
            .find("table", class_="table-hover")
            .find("tbody")
        )
        if not problem_table:
            self.log("error", f"No problem table found for contest {contest_name}.")
            return None
        problem_elements = problem_table.find_all("tr")

        problems_infos = []
        for problem in problem_elements:
            cols = problem.find_all("td")
            if len(cols) < 5:
                continue

            # Create problem folder
            problem_letter = cols[0].text.strip()
            problem_path = os.path.join(contest_folder, "problems", problem_letter)
            os.makedirs(problem_path, exist_ok=True)

            problem_link = urljoin(self.base_url, cols[1].find("a")["href"])
            problem_name = cols[1].text.strip()

            problem_info = {
                "letter": problem_letter,
                "name": problem_name,
                "link": problem_link,
            }
            problems_infos.append(problem_info)
        return problems_infos

    def fetch_contests_get_problem_details(
        self, problem_info, contest_folder, problem_path
    ):
        """
        Fetch the details of a problem in a contest. This includes downloading the problem statement PDF and extracting time/memory limits.
        Return a dictionary based on the problem_info. No additional keys are required.
        """
        problem_letter = problem_info["letter"]
        problem_link = problem_info["link"]
        problem_name = problem_info["name"]

        problem_page = self.fetch_page_with_browser(problem_link)
        if not problem_page:
            self.log(
                "error",
                f"Failed to fetch problem page {problem_link}.",
            )
            return None

        problem_soup = (
            bs4(problem_page, "html.parser")
            .find("div", class_="nk-acm-container")
            .find("div", class_="question-module")
        )

        info_element = problem_soup.find("div", class_="question-intr").find(
            "div", class_="subject-item-wrap"
        )
        info_elements = info_element.find_all("span")

        for info_pair in info_elements:
            info_content = info_pair.text.strip()
            if "时间限制" in info_content:
                # Format example: "时间限制：C/C++/Rust/Pascal 6秒，其他语言12秒"
                # Extract to: "6 s"
                match = re.search(r"(\d+)\s*秒", info_content)
                if match:
                    time_limit = f"{match.group(1)} s"
                else:
                    self.log(
                        "warning",
                        f"Time limit not found in {info_content} for problem {problem_name}.",
                    )
            if "内存限制" in info_content:
                # Format example: "内存限制：C/C++/Rust/Pascal 256 M，其他语言512 M"
                # Extract to: "256 MB"
                match = re.search(r"(\d+)\s*M", info_content)
                if match:
                    memory_limit = f"{match.group(1)} MB"
                else:
                    self.log(
                        "warning",
                        f"Memory limit not found in {info_content} for problem {problem_name}.",
                    )

        # Download the problem statement

        # Try to convert the HTML to markdown
        try:
            statement_container = problem_soup.find("div", class_="subject-describe")
            statement_elements = list(statement_container.children)

            if not statement_elements:
                raise ValueError(f"No problem statement found for {problem_name}.")

            md_content = f"## {problem_letter}. {problem_name}\n\n"
            for element in statement_elements:
                if not isinstance(element, Tag):
                    continue  # skip text nodes
                element_type = element.name
                element_class = element.get("class", [])

                if element_type == "div" and "subject-question" in element_class:
                    # This is the main problem statement section
                    md_content += f"### 题目描述\n\n"
                    element_cleaned = (
                        str(element)
                        .replace('<div class="subject-question">', "")
                        .replace("</div>", "")
                    )
                    md_content += (
                        self._convert_html_to_markdown(element_cleaned) + "\n\n"
                    )
                elif element_type == "h2":
                    # This is a section header
                    # Remove ":" at the end of the header
                    section_title = element.text.strip().rstrip(":")
                    md_content += f"### {section_title}\n\n"
                elif element_type == "pre":
                    element_cleaned = (
                        str(element).replace("<pre>", "").replace("</pre>", "")
                    )
                    md_content += (
                        self._convert_html_to_markdown(element_cleaned) + "\n\n"
                    )
                elif element_type == "div" and "question-oi" in element_class:
                    oi_header = element.find("div", class_="question-oi-hd")
                    if oi_header:
                        oi_title = oi_header.text.strip()
                        md_content += f"### {oi_title}\n\n"

                    oi_mods = element.find_all("div", class_="question-oi-mod")
                    for oi_mod in oi_mods:
                        oi_mod_title = oi_mod.find("h2")
                        if oi_mod_title:
                            md_content += f"#### {oi_mod_title.text.strip()}\n\n"

                        oi_mod_textarea = oi_mod.find("textarea")
                        if oi_mod_textarea:
                            oi_mod_content = oi_mod_textarea.text.strip()
                            md_content += f"```plain\n{oi_mod_content}\n```\n\n"
                            continue

                        oi_mod_pre = oi_mod.find("pre")
                        if oi_mod_pre:
                            element_cleaned = (
                                str(oi_mod_pre)
                                .replace("<pre>", "")
                                .replace("</pre>", "")
                            )
                            md_content += (
                                self._convert_html_to_markdown(element_cleaned) + "\n\n"
                            )
                            continue

            md_path = os.path.join(problem_path, "statement.md")
            with open(md_path, "w", encoding="utf-8") as f:
                f.write(md_content)

        except ValueError as e:
            self.log(
                "error",
                f"Failed to convert problem statement to markdown for {problem_name}: {e}",
            )
            return None

        problem_entry = {
            "link": problem_link,
            "name": problem_name,
        }
        if "time_limit" in locals():
            problem_entry["time_limit"] = time_limit
        if "memory_limit" in locals():
            problem_entry["memory_limit"] = memory_limit
        return problem_entry

    def fetch_submissions_fetch_source_code(self, entry):
        """
        Fetch the source code of a submission. This method is called in `_update_submission_status`.
        """

        code_page = self.fetch_page_with_browser(entry["submission_link"])
        code_soup = bs4(code_page, "html.parser")
        code_element = (
            code_soup.find("div", class_="result-subject-item")
            .find("td", class_="code")
            .find("div", class_="container")
        )

        code = ""
        code_lines = code_element.find_all("div", class_="line")
        for line in code_lines:
            code += line.get_text().replace("\xa0", " ") + "\n"
        return code

    def fetch_submissions_get_submissions(self):
        """
        Fetch the submissions from the website.
        After fetching each submission, call the `_register_submission` method to register the submission. If the return value is True, stop fetching submissions and exit immediately.
        The submission entry should contain the following keys:
        - submission_id: The ID of the submission
        - problem_name (optional): The name of the problem
        - problem_link (optional): The link to the problem page
        - submit_time: The time when the submission was made, in ISO format (YYYY-MM-DDTHH:MM:SS)

        Either `problem_name` or `problem_link` is required.
        """

        input_contest_list = self._load_file(self.input_contests_path)
        for input_contest in input_contest_list:

            if "link" not in input_contest:
                self.log("error", "Input contest does not have a link.")
                continue
            contest_link = input_contest["link"]
            self.log(
                "info",
                f"Start fetching submissions from {contest_link}.",
            )

            status_link = f'{contest_link}#submit/"onlyMyStatusFilter"%3Atrue'

            stop_fetching = False
            for page in range(1, 20):
                # Assume there are at most 20 pages of submissions
                status_link_with_page = f'{status_link}%2C"page"%3A{page}'

                status_page = self.fetch_page_with_browser(status_link_with_page, 2)
                soup = bs4(status_page, "html.parser")

                current_page = soup.find("div", class_="pagination")
                if not current_page:
                    current_page_number = 1
                else:
                    current_page_number = int(
                        current_page.find("li", class_="active").text.strip()
                    )

                if current_page_number != page:
                    self.log(
                        "info",
                        "Reached the end of submissions or no more pages to fetch. Stopped.",
                    )
                    break

                table_body = soup.find("div", class_="module-box").find(
                    "table", class_="table-hover"
                )
                if not table_body:
                    self.log(
                        "warning",
                        "No submissions found on this page. Probably the contest has not started yet.",
                    )
                    break
                table_body = table_body.find("tbody")
                submission_elements = table_body.find_all("tr")

                for submission in submission_elements:
                    cols = submission.find_all("td")
                    if len(cols) < 9:
                        self.log(
                            "warning",
                            "Found submission with less than 9 columns, skipping.",
                        )
                        continue

                    submission_id = cols[0].text.strip()
                    problem_link = urljoin(self.base_url, cols[2].find("a")["href"])
                    submission_link = urljoin(self.base_url, cols[0].find("a")["href"])

                    # Status format: "Accepted", "Wrong Answer", "Time Limit Exceeded", "Runtime Error (ACCESS_VIOLATION)", etc.
                    raw_status = cols[3].text.strip()
                    if raw_status == "答案正确":
                        status = "AC"
                    elif "答案错误" in raw_status:
                        status = "WA"
                    elif "运行超时" in raw_status:
                        status = "TLE"
                    elif "运行错误" in raw_status:
                        status = "RE"
                    elif "编译错误" in raw_status:
                        status = "CE"
                    elif "空间" in raw_status:
                        status = "MLE"
                    else:
                        status = "UKE"

                    time = cols[4].text.strip() + " ms"
                    memory = cols[5].text.strip() + " KB"
                    language = cols[7].text.strip()

                    submit_time = self._convert_iso_to_beijing(cols[8].text.strip())

                    submission_entry = {
                        "submission_id": submission_id,
                        "status": status,
                        "time": time,
                        "memory": memory,
                        "language": language,
                        "submit_time": submit_time.isoformat(),
                        "problem_link": problem_link,
                        "submission_link": submission_link,
                    }
                    stop_fetching = self._register_submission(submission_entry)
                    if stop_fetching:
                        break

                self.log(
                    "info",
                    f"Fetched {len(submission_elements)} submissions from {contest_link}, page {page}.",
                )
                if stop_fetching:
                    break


if __name__ == "__main__":
    crawler = NOWCODERCrawler()
    crawler.log("info", "Nowcoder Crawler is disabled.")
    crawler.finish()
    raise RuntimeError("Nowcoder Crawler is disabled.")

    # try:
    #     crawler.log(
    #         "important",
    #         "nowcoder Crawler started at " + datetime.now(beijing).isoformat(),
    #     )
    #     crawler.login()

    #     crawler.fetch_contests()
    #     crawler.log("info", "Contests fetched successfully.")
    #     crawler.fetch_submissions()
    #     crawler.log("info", "Submissions fetched successfully.")
    #     crawler.log(
    #         "important",
    #         "nowcoder Crawler finished successfully at "
    #         + datetime.now(beijing).isoformat(),
    #     )
    #     crawler.finish()
    # except Exception as e:
    #     crawler.log("fatal", f"An error occurred: {e}")
    #     crawler.deinit_driver()
