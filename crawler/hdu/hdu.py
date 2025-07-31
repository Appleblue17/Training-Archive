import re
import sys
import os
from bs4 import BeautifulSoup as bs4
from datetime import datetime, timedelta, timezone

beijing = timezone(timedelta(hours=8))
now = datetime.now(beijing)
from urllib.parse import urljoin
from selenium.webdriver.common.by import By

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "../..")))
from crawler.base import BaseCrawler


class HDUCrawler(BaseCrawler):
    def __init__(self, local_log_path="crawler/hdu/log.json"):
        super().__init__("hdu", local_log_path)
        self.contests_path = "crawler/hdu/contests.json"
        self.submissions_path = "crawler/hdu/staged-submissions.json"
        self.input_contests_path = "crawler/hdu/input_contests.json"

    def is_logged_in(self, link):
        main_page = self.fetch_page_with_browser(link)

        # Check if login was successful
        success = self.username in main_page
        return success

    def try_login_with_password(self, link, username, password):
        if self.is_logged_in(link):
            self.log(
                "info", "Already logged in with username and password. Skipping login."
            )
            return

        self.driver.get(link)
        self._random_sleep()
        self.driver.find_element(By.NAME, "username").send_keys(username)
        self.driver.find_element(By.NAME, "password").send_keys(password)
        self.driver.find_element(By.CSS_SELECTOR, "button[type='submit']").click()
        self._random_sleep()

        if not self.is_logged_in(link):
            self.log("fatal", "Login failed with provided credentials.")
        else:
            self.log("info", "Login successful with username and password.")

    def login(self, link):
        username = os.getenv("HDU_USERNAME")
        password = os.getenv("HDU_PASSWORD")
        if not username or not password:
            self.log(
                "fatal",
                "Username or password not found in environment variables. Stopped.",
            )
            return

        self.try_login_with_password(link, username, password)

    def fetch_contests_get_contest_list(self):
        """
        Fetch the list of contests from the website, and return a list of contest information.
        Return a dictionary with the following required keys:
        - name: The name of the contest
        - date: The date of the contest in ISO format (YYYY-MM-DD)
        - platform: The platform name (in this case, "hdu")
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

            login_page = self.fetch_page_with_browser(contest_link)
            login_soup = bs4(login_page, "html.parser")

            contest_name_element = login_soup.find("div", class_="contest-info").find(
                "h2"
            )
            contest_name = contest_name_element.text.strip()

            # Contest time format example: "Jul 18, 2025 12:00:00 ~ Jul 18, 2025 17:00:00"
            # Convert it to ISO format
            contest_time_element = (
                login_soup.find("div", class_="contest-info")
                .find("div", class_="info-pair")
                .find("div", class_="info-value")
            )
            contest_time_raw = contest_time_element.text.strip()
            contest_time_parts = contest_time_raw.split(" ~ ")
            if len(contest_time_parts) != 2:
                self.log(
                    "error",
                    f"Contest time format is incorrect: {contest_time_raw}. Skipping contest {contest_name}.",
                )
                continue
            start_time_str = contest_time_parts[0].strip()
            end_time_str = contest_time_parts[1].strip()
            start_time = datetime.strptime(start_time_str, "%b %d, %Y %H:%M:%S")
            end_time = datetime.strptime(end_time_str, "%b %d, %Y %H:%M:%S")
            start_time = start_time.replace(tzinfo=beijing)
            end_time = end_time.replace(tzinfo=beijing)

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
                "platform": "hdu",
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
        self.login(contest_link)
        contest_page = self.fetch_page_with_browser(contest_link)
        soup = bs4(contest_page, "html.parser")

        problem_table = soup.find("table", class_="page-card-table").find("tbody")
        if not problem_table:
            self.log("error", f"No problem table found for contest {contest_name}.")
            return None
        problem_elements = problem_table.find_all("tr")

        problems_infos = []
        for problem in problem_elements:
            cols = problem.find_all("td")
            if len(cols) < 4:
                continue

            # Create problem folder
            # letter is calculated as the index of the problem in the list, starting from 'A'
            problem_index = len(problems_infos)
            problem_letter = chr(ord("A") + problem_index)
            problem_path = os.path.join(contest_folder, "problems", problem_letter)
            os.makedirs(problem_path, exist_ok=True)

            problem_link = urljoin(self.base_url, cols[2].find("a")["href"])
            problem_name = cols[2].text.strip()

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

        problem_soup = bs4(problem_page, "html.parser")

        sidebar_element = problem_soup.find("div", class_="problem-sidebar")
        info_pair_elements = sidebar_element.find_all("div", class_="info-pair")

        for info_pair in info_pair_elements:
            info_label = info_pair.find("div", class_="info-label").text.strip()
            info_value = info_pair.find("div", class_="info-value").text.strip()
            if "Time Limit" in info_label:
                time_limit = (
                    info_value.split("/")[1].strip()
                    if "/" in info_value
                    else info_value.strip()
                )
            if "Memory Limit" in info_label:
                memory_limit = (
                    info_value.split("/")[1].strip()
                    if "/" in info_value
                    else info_value.strip()
                )

        # Download the problem statement
        # Try to convert the HTML to markdown
        try:
            statement_elements = problem_soup.find(
                "div", class_="problem-body"
            ).find_all("div", class_="problem-detail-block")
            if not statement_elements:
                raise ValueError(f"No problem statement found for {problem_name}.")

            md_content = f"## {problem_letter}. {problem_name}\n\n"
            for element in statement_elements:
                element_label = element.find(
                    "div", class_="problem-detail-label"
                ).text.strip()
                element_content = element.find("div", class_="problem-detail-value")

                if "Sample" in element_label:
                    # For Input/Output sections, directly use the text content
                    element_content = element_content.get_text(strip=True)
                    md_content += f"### {element_label}\n\n"
                    md_content += f"```plain\n{element_content}\n```\n\n"
                else:
                    # For other sections, convert HTML to markdown
                    md_content += f"### {element_label}\n\n"
                    md_content += self._convert_html_to_markdown(str(element_content))
                    md_content += "\n\n"

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
        code = (
            code_soup.find("div", class_="problem-body")
            .find("textarea", id="code")
            .text.strip()
        )
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

            self.login(contest_link)
            status_link = contest_link.replace("problems", "status")

            stop_fetching = False
            for page in range(1, 10):
                # Assume there are at most 10 pages of submissions
                status_link_with_page = f"{status_link}&page={page}"

                status_page = self.fetch_page_with_browser(status_link_with_page)
                soup = bs4(status_page, "html.parser")

                pagination_element = soup.find("ul", class_="pagination")

                isCurrentPage = False
                if not pagination_element:
                    if page == 1:
                        isCurrentPage = True
                else:
                    current_pages = pagination_element.find_all(
                        "li", class_="page-item disabled"
                    )
                    for current_page in current_pages:
                        if current_page.text.strip() == str(page):
                            isCurrentPage = True
                            break

                if not isCurrentPage:
                    self.log(
                        "info",
                        "Reached the end of submissions or no more pages to fetch. Stopped.",
                    )
                    break

                table_body = soup.find("table", class_="page-card-table")
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
                    if len(cols) < 7:
                        self.log(
                            "warning",
                            "Found submission with less than 9 columns, skipping.",
                        )
                        continue

                    submission_id = cols[0].text.strip()
                    problem_link = urljoin(self.base_url, cols[2].find("a")["href"])
                    submission_link = urljoin(self.base_url, cols[5].find("a")["href"])

                    # Status format: "Accepted", "Wrong Answer", "Time Limit Exceeded", "Runtime Error (ACCESS_VIOLATION)", etc.
                    raw_status = cols[6].text.strip()
                    if raw_status == "Accepted":
                        status = "AC"
                    elif "Runtime Error" in raw_status:
                        status = "RE"
                    else:
                        # only preserve uppercase letters
                        status = re.sub(r"[^A-Z]", "", raw_status)

                    time = cols[3].text.strip()
                    memory = cols[4].text.strip()
                    language = cols[5].text.strip()

                    submit_time = self._convert_iso_to_beijing(cols[1].text.strip())

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
    crawler = HDUCrawler()

    try:
        crawler.log(
            "important", "hdu Crawler started at " + datetime.now(beijing).isoformat()
        )
        crawler.fetch_contests()
        crawler.log("info", "Contests fetched successfully.")
        crawler.fetch_submissions()
        crawler.log("info", "Submissions fetched successfully.")
        crawler.log(
            "important",
            "hdu Crawler finished successfully at " + datetime.now(beijing).isoformat(),
        )
    except Exception as e:
        crawler.log("fatal", f"An error occurred: {e}")
    finally:
        crawler.deinit_driver()
