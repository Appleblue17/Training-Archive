import re
import sys
import os
from bs4 import BeautifulSoup as bs4
from datetime import datetime, timedelta, timezone

beijing = timezone(timedelta(hours=8))
from urllib.parse import urljoin
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), "../../..")))
from crawler.platforms.base import BaseCrawler


# QOJ 比赛时长展示形如 "[2 hours]"/"[2 hours 30 minutes]"/"[90 minutes]"/"[2 hour]"。
# 不能简单 split("hours")：单数 "hour"、纯分钟（无 hours）、空串都会解析失败或
# 抛 ValueError 中断整场抓取。用正则分别取小时/分钟，任一缺失按 0 处理。
_QOJ_HOURS_RE = re.compile(r"(\d+)\s*hours?", re.IGNORECASE)
_QOJ_MINUTES_RE = re.compile(r"(\d+)\s*minutes?", re.IGNORECASE)


def _parse_qoj_duration(text):
    """解析 QOJ 时长文本为 timedelta。无法识别任何数字时抛 ValueError。"""
    text = (text or "").strip()
    hours_m = _QOJ_HOURS_RE.search(text)
    minutes_m = _QOJ_MINUTES_RE.search(text)
    if not hours_m and not minutes_m:
        raise ValueError(f"Unexpected QOJ duration format: {text!r}")
    hours = int(hours_m.group(1)) if hours_m else 0
    minutes = int(minutes_m.group(1)) if minutes_m else 0
    return timedelta(hours=hours, minutes=minutes)


def _extract_source_code(html):
    """从 QOJ 提交页 HTML 提取源码文本；找不到代码块返回 None。

    偶发情况下页面是 Cloudflare 挑战页（"Just a moment..."）或空白，此时没有
    `pre.sh_sourceCode`；调用方据此重试，而不是让 AttributeError 冒泡。
    """
    soup = bs4(html or "", "html.parser")
    pre = soup.find("pre", class_="sh_sourceCode")
    if pre is None:
        return None
    code = pre.find("code")
    return code.get_text() if code is not None else None


class QOJCrawler(BaseCrawler):
    def __init__(self, local_log_path="crawler/platforms/qoj/log.json"):
        super().__init__("qoj", local_log_path)
        self.contests_path = "crawler/platforms/qoj/contests.json"
        self.submissions_path = "crawler/platforms/qoj/staged-submissions.json"

    def is_logged_in(self):
        main_page = self.fetch_page_with_browser("https://qoj.ac/")

        # Check if login was successful
        success = self.username in main_page
        return success

    def try_login_with_password(self, username, password):
        self.driver.get("https://qoj.ac/login")
        
        wait = WebDriverWait(self.driver, 30)
        
        username_input = wait.until(EC.presence_of_element_located((By.NAME, "username")))
        username_input.send_keys(username)
        self._random_sleep(0.5, 1)
        
        password_input = wait.until(EC.presence_of_element_located((By.NAME, "password")))
        password_input.send_keys(password)
        self._random_sleep(0.5, 1)

        submit_button = wait.until(EC.element_to_be_clickable((By.ID, "button-submit")))
        submit_button.click()
        self._random_sleep()

        if not self.is_logged_in():
            self.log("fatal", "Login failed with provided credentials.")
        else:
            self.log("info", "Login successful with username and password.")

    def login(self):
        username = os.getenv("QOJ_USERNAME")
        password = os.getenv("QOJ_PASSWORD")
        if not username or not password:
            self.log(
                "fatal",
                "Username or password not found in environment variables. Stopped.",
            )
            return

        self.username = username
        self.try_login_with_password(username, password)

    def fetch_contests_get_contest_list(self):
        """
        Fetch the list of contests from the website, and return a list of contest information.
        Return a dictionary with the following required keys:
        - name: The name of the contest
        - date: The date of the contest in ISO format (YYYY-MM-DD)
        - platform: The platform name (in this case, "QOJ")
        - start_time: The start time of the contest in ISO format (YYYY-MM-DDTHH:MM:SS)
        - end_time: The end time of the contest in ISO format (YYYY-MM-DDTHH:MM:SS)
        - link: The link to the contest
        """
        contest_page = self.fetch_page_with_browser("https://qoj.ac/contests")

        # 订阅驱动：只抓取 crawler/subscriptions/ 目录中启用的 QOJ 比赛
        subs = self._load_subscriptions(self.platform_name)
        only_links = getattr(self, "_only_links", None)
        if only_links:
            # --links：只抓指定订阅链接（服务器闹钟 fire / sync 补抓用）
            subs = [s for s in subs if s.get("link", "").rstrip("/") in only_links]
        subscribed_links = {
            s.get("link", "").rstrip("/") for s in subs
        }
        if not subscribed_links:
            self.log("info", "No subscribed QOJ contests, skipping contest list fetch.")
            return []

        soup = bs4(contest_page, "html.parser")
        contest_elements = soup.find_all("tr", class_="table-success")

        contest_infos = []
        for contest in contest_elements:
            cols = contest.find_all("td")
            if len(cols) < 4:
                self.log("warning", "Found contest with less than 4 columns, skipping.")
                continue

            # Contest link is the first href in cols[0]
            contest_link = urljoin(self.base_url, cols[0].find("a")["href"])
            contest_name = cols[0].find("a").text.strip()

            # 未订阅的比赛跳过
            if contest_link.rstrip("/") not in subscribed_links:
                self.log("info", f"Contest {contest_name} is not subscribed, skipping.")
                continue

            # If the contest already exists, skip it
            if any(c["link"] == contest_link for c in self.contests):
                continue

            # Contest start time is in cols[1]
            # Format: YYYY-MM-DD HH:MM:SS
            contest_start_time = cols[1].find("a").text.strip()
            start_time = self._convert_iso_to_beijing(contest_start_time)
            date = start_time.date()

            if start_time > datetime.now(beijing):
                # Contest is in the future, skip it
                self.log(
                    "info",
                    f"Contest {contest_name} has not started yet. Skipping.",
                )
                continue

            # Contest duration is in cols[2]
            # Format: [X hours] or [X hours Y minutes]
            contest_duration = cols[2].text.strip()
            try:
                duration = _parse_qoj_duration(contest_duration)
            except ValueError as e:
                self.log(
                    "error",
                    f"Failed to parse contest duration {contest_duration!r} for "
                    f"{contest_name}: {e}. Skipping contest.",
                )
                continue
            # Calculate the end time
            end_time = start_time + duration

            # Difficulty is in cols[3]
            # Format: [?] or [★★★★★] or [★★★☆]; ★=1, ☆=0.5
            difficulty_text = cols[3].text.strip()
            if difficulty_text == "?":
                difficulty = None
            else:
                difficulty = 0
                for char in difficulty_text:
                    if char == "★":
                        difficulty += 1
                    elif char == "☆":
                        difficulty += 0.5

            contest_info = {
                "name": contest_name,
                "date": date.isoformat(),
                "platform": self.platform_name,
                "start_time": start_time.isoformat(),
                "end_time": end_time.isoformat(),
                "link": contest_link,
            }
            if difficulty is not None:
                contest_info["difficulty"] = difficulty

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

        # Download attachments of the contest
        attachment_block = soup.find("div", class_="card border-success top-buffer-lg")
        if attachment_block:
            attachment_elements = attachment_block.find_all("a")
            for attachment in attachment_elements:
                attachment_link = urljoin(contest_link, attachment["href"])
                attachment_name = attachment.text.strip()

                # Save the attachment to contest_folder
                attachment_path = urljoin(contest_folder, attachment_name)
                if not self.download_file_with_browser(
                    attachment_link, attachment_name + ".pdf", contest_folder
                ):
                    # If download failed or the link is not a download link, print it to pdf
                    self.print_to_pdf_with_browser(
                        attachment_link, attachment_name + ".pdf", contest_folder
                    )

        problem_table = soup.find("table", class_="table").find("tbody")
        if not problem_table:
            self.log("error", f"No problem table found for contest {contest_name}.")
            return None
        problem_elements = problem_table.find_all("tr")

        problems_infos = []
        for problem in problem_elements:
            cols = problem.find_all("td")
            if len(cols) < 2:
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

        badge_elements = problem_soup.find("div", class_="uoj-content").find_all(
            "span", class_="badge"
        )
        for badge in badge_elements:
            badge_content = badge.text.strip()
            if "Time Limit" in badge_content:
                time_limit = badge_content.split(":")[1].strip()
            if "Memory Limit" in badge_content:
                memory_limit = badge_content.split(":")[1].strip()

        # Best-effort tag extraction; non-fatal if the page has no tags.
        tags = self._extract_problem_tags(problem_soup)

        problem_pdf = problem_soup.find("iframe", id="statements-pdf")
        if not problem_pdf:
            self.log(
                "error",
                f"Did not find pdf in {problem_link}.",
            )
            return None

        problem_pdf_link = urljoin(self.base_url, problem_pdf["src"].strip())
        if not self.download_file_with_browser(
            problem_pdf_link, "statement.pdf", problem_path
        ):
            self.log(
                "error",
                f"Failed to download pdf from {problem_pdf_link}.",
            )

        problem_entry = {
            "link": problem_link,
            "name": problem_name,
        }
        if tags:
            problem_entry["tags"] = tags
        if "time_limit" in locals():
            problem_entry["time_limit"] = time_limit
        if "memory_limit" in locals():
            problem_entry["memory_limit"] = memory_limit
        return problem_entry

    def _extract_problem_tags(self, problem_soup):
        """
        Extract tags from a UOJ/QOJ-style problem page.

        Best-effort: returns [] if the structure is unexpected, so a tag
        parsing failure never blocks contest fetching. On QOJ tags live in a
        panel whose heading contains "Tags"/"标签", each tag being a link with
        "tag=" in its href.
        """
        tags = []
        try:
            for panel in problem_soup.select("div.panel"):
                title_el = panel.select_one(".panel-heading .panel-title")
                if not title_el:
                    continue
                if "tag" not in title_el.get_text(strip=True).lower():
                    continue
                for a in panel.select("a[href]"):
                    if "tag" not in a["href"].lower():
                        continue
                    text = a.get_text(strip=True)
                    if text:
                        tags.append(text)
                if tags:
                    break
        except Exception:
            self.log("warning", "Failed to parse problem tags; continuing without tags.")
        return tags

    def fetch_submissions_fetch_source_code(self, entry):
        """
        Fetch the source code of a submission. This method is called in `_update_submission_status`.
        """

        link = entry["submission_link"]
        for attempt in (1, 2):
            code_page = self.fetch_page_with_browser(link)
            code = _extract_source_code(code_page)
            if code is not None:
                return code
            if attempt == 1:
                # 可能是 Cloudflare 挑战页 / 偶发空白页：退避后重试一次
                self.log(
                    "warning",
                    f"Source code block not found (attempt {attempt}) at {link}; retrying.",
                )
                self._random_sleep(2, 4)
        raise ValueError(
            f"Source code block not found at {link} "
            "(possibly a Cloudflare challenge page)."
        )

    def fetch_submissions_get_submissions(self):
        """
        Fetch the submissions from the website.
        After fetching each submission, call the `_register_submission` method to register the submission. If the return value is True, stop fetching submissions and exit immediately.
        The submission entry should contain the following keys:
        - submission_id: The ID of the submission
        - problem_name: The name of the problem
        - problem_link: The link to the problem page
        - submit_time: The time when the submission was made, in ISO format (YYYY-MM-DDTHH:MM:SS)
        """

        username = self.username
        if not username:
            self.log(
                "fatal",
                "Username not found in environment variables. Cannot fetch submissions.",
            )
            return

        # 增量截止：
        #   contests-only（--contests-only）→ 最早的新比赛开始时间，只回填
        #     新比赛提交区间；已有比赛的增量由每日任务B负责
        #   否则 → None，沿用全局 last-update 增量截止
        deadline = self._contests_only_deadline()

        # Assuming there are not more than 50 pages of submissions
        for page in range(1, 50):
            self.log("info", f"Start fetching submissions from page {page}.")
            submissions_page = self.fetch_page_with_browser(
                urljoin(self.base_url, f"submissions?submitter={username}&page={page}")
            )
            if not submissions_page:
                self.log("error", f"Failed to fetch submissions page {page}.")
                break

            soup = bs4(submissions_page, "html.parser")
            active_li = soup.find("li", class_="page-item active")
            active_link = active_li.find("a") if active_li else None
            if active_link is None:
                # 页面结构缺失：无法判断当前页，安全停止且不推进 last-update
                self.log(
                    "error",
                    f"Cannot determine current submissions page {page}; "
                    "stopping without advancing last-update.",
                )
                break
            current_page = active_link.text.strip()
            if current_page != str(page):
                self.log(
                    "info", f"Reached the end of submissions at page {current_page}."
                )
                self._mark_submissions_complete()
                break

            table_body = soup.find("table", class_="table").find("tbody")
            if not table_body:
                self.log("error", "No submissions found on this page.")
                break
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
                submission_link = urljoin(self.base_url, cols[0].find("a")["href"])

                problem_name = cols[1].text.strip()
                # To extract pure name, re `^#\d+\. (.*)`
                problem_match = re.match(r"^#(\d+)\. (.*)", problem_name)
                if problem_match:
                    problem_id = problem_match.group(1)
                    problem_name_pure = problem_match.group(2)
                else:
                    problem_id = ""
                    problem_name_pure = problem_name
                problem_link = urljoin(self.base_url, cols[1].find("a")["href"])

                # Status format: [number] or [AC ✓] or [status]
                raw_status = cols[3].text.replace(" ✓", "").strip()
                if raw_status.isdigit():
                    # 数字状态统一为字符串（100 表示 AC），与前端字符串比对保持一致
                    status = "AC" if int(raw_status) == 100 else raw_status
                else:
                    # only preserve uppercase letters
                    status = "".join(c for c in raw_status if c.isupper())

                time = cols[4].text.strip()
                memory = cols[5].text.strip()
                language = cols[6].text.strip()

                submit_time = self._convert_iso_to_beijing(cols[8].text.strip())

                submission_entry = {
                    "submission_id": submission_id,
                    "problem_id": problem_id,
                    "problem_name": problem_name_pure,
                    "status": status,
                    "time": time,
                    "memory": memory,
                    "language": language,
                    "submit_time": submit_time.isoformat(),
                    "problem_link": problem_link,
                    "submission_link": submission_link,
                }
                stop_fetching = self._register_submission(
                    submission_entry, deadline=deadline
                )
                if stop_fetching:
                    self._mark_submissions_complete()
                    return

            self.log(
                "info",
                f"Fetched {len(submission_elements)} submissions from page {page}.",
            )
