import base64
import glob
import json
import random
import shutil
import re
import time
from datetime import datetime, timedelta, timezone

import os
import sys
import undetected_chromedriver as uc
from bs4 import BeautifulSoup

# 北京时间（UTC+8）。所有时间统一使用该时区。
# 注意：不要在模块导入时缓存 now，长任务跨午夜会用到过期时间，需实时获取。
beijing = timezone(timedelta(hours=8))

# _update_submission_status 返回值语义：
#   True     已归档到比赛文件夹（该提交从 staged 移除）
#   False    未匹配到任何比赛，保留在 staged-submissions.json
#   DISCARD  匹配到比赛但提交早于其开始时间（跨赛季复用历史提交），直接丢弃
DISCARD = "discard"


def load_subscriptions_dir(subscriptions_dir, platform=None, log=None):
    """从 crawler/subscriptions/ 目录加载订阅配置（模块级，供爬虫与 alarm.py 共用）。

    crawler/subscriptions/ 目录是统一的比赛订阅源。目录下每个 *.json 文件都是
    一份订阅列表，文件名随意（可按平台 / 系列 / 月份等分组管理）：
        [
          {"platform": "hdu", "link": "https://...", "comments": "可选",
           "end_time": "可选，比赛结束时间", "enabled": true}
        ]
    - 运行时只识别 .json 文件：按文件名排序后逐文件读取，合并为一个列表，
      重复 link 去重（保留先出现的条目）；非 .json 文件忽略。
    - 模板文件 *.example.json 跳过（示例比赛不是真实订阅，只在目录里供参考）。
    - 文件缺失 / 解析失败 / 非列表时记录日志并跳过，不阻断其他文件。
    - platform 为 None：返回全部条目（**含 enabled: false 的条目**，供 alarm.py
      自行过滤）。
    - platform 指定时：仅返回该平台且 enabled != false 的订阅（爬虫用）。
    - enabled 缺省视为启用（订阅级默认开启）；"comments" 仅为用户备注，代码不读取。
    - "end_time" 为可选字段：不写 = 历史比赛（sync 立即爬取，不生成报告）；
      未来时间 = 服务器闹钟机制（方式二）到点触发爬取并生成报告；已过时间 =
      sync 立即爬取并生成报告（补漏）。方式一（GitHub Actions 轮询）不读取该字段。

    链接由用户维护（开发分支被 gitignore，不随仓库同步；deploy 分支纳入版本控制）。
    """
    def _log(level, msg):
        if log:
            log(level, msg)

    subs = []
    seen_links = set()
    if not os.path.isdir(subscriptions_dir):
        _log(
            "warning",
            f"Subscriptions directory {subscriptions_dir} does not exist; "
            "no subscriptions.",
        )
        return []
    for filename in sorted(os.listdir(subscriptions_dir)):
        if not filename.endswith(".json"):
            continue
        # 跳过模板文件（*.example.json），避免示例比赛被当作真实订阅抓取
        if filename.endswith(".example.json"):
            continue
        path = os.path.join(subscriptions_dir, filename)
        try:
            with open(path, "r", encoding="utf-8") as f:
                entries = json.load(f)
        except Exception as e:
            _log("error", f"Failed to parse subscriptions file {path}: {e}")
            continue
        if not isinstance(entries, list):
            _log("warning", f"Subscriptions file {path} is not a list; skipped.")
            continue
        for entry in entries:
            link = str(entry.get("link") or "").rstrip("/")
            if not link:
                _log("warning", f"Subscription entry in {path} has no link; skipped.")
                continue
            if link in seen_links:
                _log(
                    "warning",
                    f"Duplicate subscription link {link} (seen in an earlier file); "
                    "keeping the first entry.",
                )
                continue
            seen_links.add(link)
            subs.append(entry)

    if platform is not None:
        return [
            s for s in subs
            if s.get("platform") == platform and s.get("enabled", True)
        ]
    return subs


class BaseCrawler:
    def __init__(self, platform_name, local_log_path):
        self.platform_name = platform_name
        self.repo_dir = "contests"
        self.download_dir = "crawler/downloads"
        self.local_log_path = local_log_path
        self.global_log_path = "crawler/global.log.json"
        self.config_path = "crawler/config.json"
        self.last_update_path = "crawler/last-update.json"
        self.subscriptions_dir = "crawler/subscriptions"
        self.driver = None

        # Load configuration（enabled 仅供 scheduled_task 过滤平台，不注入爬虫实例）
        config = self._load_file(self.config_path, default={})
        for key, value in config.get(platform_name, {}).items():
            if key == "enabled":
                continue
            setattr(self, key, value)

        # If download directory does not exist, create it
        if not os.path.exists(self.download_dir):
            self.log("warning", f"Download directory does not exist, creating it.")
            os.makedirs(self.download_dir)

        # 提交抓取是否完整结束（只有完整抓取才推进 last-update，避免静默丢提交）
        self._submissions_fetch_complete = False

        # 本次运行新建的比赛（contest_link -> start_time ISO 字符串）。
        # 首次抓取该比赛时（补订已完成比赛），提交抓取以比赛开始时间为截止全量回填，
        # 否则 status 页第一条提交就早于全局 last-update 而被跳过，一场都抓不到。
        self._new_contests = {}

        # 本次运行新建的比赛文件夹（相对仓库根，如 "contests/2026-07-21 xxx"）。
        # 供 scheduled_task.py 汇总写入 new-contests.json，
        # report.py / qq_share.py 以 --from-crawl 只对这些比赛生成报告。
        self._new_contest_folders = []

        # contests-only 模式（--contests-only）：只回填本次新建比赛的提交，
        # 不回填已有比赛的增量（由每日任务B负责），finish() 不推进 last-update。
        self._contests_only = False

        # --links：只抓指定订阅链接的比赛（服务器闹钟 fire / sync 补抓用）。
        # 为 None 时抓全部订阅；三平台 fetch_contests_get_contest_list 据此过滤。
        self._only_links = None

        self.init_driver()

    def _random_sleep(self, min_wait_time=None, max_wait_time=None):
        if min_wait_time is None:
            min_wait_time = self.min_wait_time
        if max_wait_time is None:
            max_wait_time = self.max_wait_time
        sleep_time = random.uniform(min_wait_time, max_wait_time)
        time.sleep(sleep_time)

    def _get_extension_name(self, language):
        language = language.lower()
        if (
            "c++" in language
            or "cpp" in language
            or "gcc" in language
            or "g++" in language
        ):
            return "cpp"
        if "go" in language:
            return "go"
        if "java" in language:
            return "java"
        if "kotlin" in language:
            return "kt"
        if "pascal" in language:
            return "pas"
        if "python" in language:
            return "py"
        if "rust" in language:
            return "rs"
        if language.startswith("c"):
            return "c"
        if language.startswith("d"):
            return "d"
        # fallback
        return "txt"

    # Convert to beijing time
    def _convert_to_beijing_time(self, dt):
        # 约定：naive（无时区）datetime 按北京时间墙钟时间解释（replace），
        # aware datetime 则做真正的时区转换（astimezone）。
        if dt.tzinfo is None:
            dt = dt.replace(tzinfo=beijing)
        dt = dt.astimezone(beijing)
        return dt

    # From ISO format to beijing time
    def _convert_iso_to_beijing(self, iso_str):
        iso_str = str(iso_str).strip()
        # Python < 3.11 的 fromisoformat 不接受 'Z'，统一替换为 +00:00
        if iso_str.endswith("Z") or iso_str.endswith("z"):
            iso_str = iso_str[:-1] + "+00:00"
        dt = datetime.fromisoformat(iso_str)
        return self._convert_to_beijing_time(dt)

    def _clean_pandoc_markdown(self, md: str) -> str:
        # 0. Block-level formula container ::: katex-display ... ::: -> $$...$$
        # 需在删纯 ::: 行之前处理（闭合行会被第 1 步删掉）。
        # 内容（pandoc 输出）形如 [[$\frac{a+b}{2}$]{.katex-mathml}]{.katex}，
        # 删属性后剥掉 [[ ] 与 $ 包裹，还原为块级 LaTeX。
        def _block_math(m):
            inner = m.group(1)
            inner = re.sub(r"\{\.katex-mathml\}", "", inner)
            inner = re.sub(r"\{\.katex\}", "", inner)
            inner = re.sub(r"\{\.katex-display\}", "", inner)
            inner = re.sub(r"\{\.katex-html\}", "", inner)
            inner = re.sub(r"^\[+\s*", "", inner)
            inner = re.sub(r"\s*\]+$", "", inner)
            inner = inner.strip().strip("$").strip()
            return f"\n$$\n{inner}\n$$\n"

        md = re.sub(
            r"^::+\s*katex-display\s*\n(.*?)^::+\s*$",
            _block_math,
            md,
            flags=re.MULTILINE | re.DOTALL,
        )

        # 1. Remove ::: block with attributes（支持多冒号：空 <div> 会输出 :::::
        #    等变长容器，pandoc 3.1.x 与 3.7 都有）
        md = re.sub(r"^::+\s*\{[^\}]*\}\s*$", "", md, flags=re.MULTILINE)
        md = re.sub(r"^::+\s*$", "", md, flags=re.MULTILINE)

        # 2. Remove { .katex-mathml } { .katex } { .katex-display } { .katex-html }
        md = re.sub(r"\{\.katex-mathml\}", "", md)
        md = re.sub(r"\{\.katex\}", "", md)
        md = re.sub(r"\{\.katex-display\}", "", md)
        md = re.sub(r"\{\.katex-html\}", "", md)

        # 3. Extract and replace math formulas
        # Block-level [[[...]]] -> $$...$$
        md = re.sub(
            r"\[\[\[\s*(.*?)\s*\]\]\]",
            lambda m: f"\n{m.group(1)}\n",
            md,
            flags=re.DOTALL,
        )

        # Inline [[...]] -> $...$
        md = re.sub(r"\[\[\s*(.*?)\s*\]\]", lambda m: f"{m.group(1)}", md)

        # Remove endline before $...$ if it's at the beginning of a line
        md = re.sub(r"\n\s*(\$[^\$]+\$)", r" \1", md)

        # Remove endline after $...$ if it's at the end of a line
        md = re.sub(r"\s*(\$[^\$]+\$)\n", r"\1 ", md)

        # Remove `\` at the end of a line
        md = re.sub(r"\\\n", "", md)

        # Remove html tags
        md = re.sub(r"<[^>]+>", "", md)

        # 4. Remove extra blank lines
        md = re.sub(r"\n{3,}", "\n\n", md)

        # 5. Fix list dash space
        md = re.sub(r"^\s*-\s*(\S)", r"- \1", md, flags=re.MULTILINE)

        return md.strip()

    def _convert_html_to_markdown(self, html):
        """
        Convert HTML to Markdown using pandoc. Return the Markdown content.
        Supports KaTeX by replacing <span class="katex">...</span> with <span class="math">...</span>.
        Requires pandoc to be installed.
        """
        import subprocess
        import tempfile
        import os

        # --- 0. 预处理：删除 KaTeX 视觉 HTML（span.katex-html / span.katex-error）---
        # KaTeX 数学由两部分组成：<span class="katex-mathml"> 内含 MathML 与
        # <annotation>（TeX 源码），以及 <span class="katex-html" aria-hidden="true">
        # 的视觉 HTML（浏览器渲染用）。pandoc 3.7+ 会自动忽略视觉部分，但
        # 3.1.x（Debian stable 的 apt 版本）会把 aria-hidden 的视觉 span 当普通
        # 内容输出，产生 [[$x$][[[]{.strut...}{.katex-html...}]] 嵌套乱码。
        # 统一在转换前删除视觉 span，只保留 mathml（TeX 源码在 annotation 里），
        # 使新旧 pandoc 输出一致，且 TeX 内容不受影响。
        try:
            soup = BeautifulSoup(html, "html.parser")
            for node in soup.select("span.katex-html, span.katex-error"):
                node.decompose()
            html = str(soup)
        except Exception as e:
            self.log("warning", f"KaTeX preprocess failed (fallback to raw html): {e}")

        # --- 1. Write to temporary HTML file ---
        with tempfile.NamedTemporaryFile(
            mode="w",
            suffix=".html",
            dir=self.download_dir,
            delete=False,
            encoding="utf-8",
        ) as html_file:
            html_file.write(html)
            html_path = html_file.name

        # --- 2. Generate temporary Markdown file path ---
        with tempfile.NamedTemporaryFile(
            mode="w+",
            suffix=".md",
            dir=self.download_dir,
            delete=False,
            encoding="utf-8",
        ) as tmp_md_file:
            tmp_md_path = tmp_md_file.name

        # --- 3. Call pandoc conversion ---
        md_clean = ""
        try:
            subprocess.run(
                [
                    "pandoc",
                    html_path,
                    "-f",
                    "html",
                    "-t",
                    "markdown",
                    "-o",
                    tmp_md_path,
                ],
                check=True,
            )
            # Read temporary md file and clean
            with open(tmp_md_path, "r", encoding="utf-8") as f:
                md_content = f.read()
            md_clean = self._clean_pandoc_markdown(md_content)
        except Exception as e:
            self.log("error", f"Pandoc conversion failed: {e}")
        finally:
            # Clean up temporary files
            if os.path.exists(html_path):
                os.remove(html_path)
            if os.path.exists(tmp_md_path):
                os.remove(tmp_md_path)
        return md_clean

    def _load_file(self, path, default=None):
        if default is None:
            default = []
        if not os.path.exists(path):
            self.log("warning", f"File {path} does not exist, creating a new one.")
            with open(path, "w", encoding="utf-8") as f:
                json.dump(default, f)
        with open(path, "r", encoding="utf-8") as f:
            try:
                return json.load(f)
            except Exception:
                return default

    def _load_subscriptions(self, platform=None):
        """加载订阅配置（复用模块级 load_subscriptions_dir，见其文档字符串）。"""
        return load_subscriptions_dir(
            self.subscriptions_dir, platform=platform, log=self.log
        )

    def _deadline_for(self, contest_link):
        """首次抓取的新比赛：返回比赛开始时间作为提交抓取截止（全量回填该场比赛）。

        非首次（本次运行未新建该比赛）返回 None，沿用全局 last_update_time 增量截止。
        """
        start_time = self._new_contests.get(contest_link)
        if not start_time:
            return None
        try:
            return self._convert_iso_to_beijing(start_time)
        except Exception as e:
            self.log(
                "warning",
                f"Invalid start_time {start_time!r} for {contest_link}: {e}; "
                "falling back to incremental.",
            )
            return None

    def _contests_only_deadline(self):
        """contests-only（--contests-only）：最早的新比赛开始时间作为提交抓取截止。

        只回填本次新建比赛的提交区间；非 contests-only / 无新比赛 / 全部缺
        start_time 时返回 None，由调用方回退到全局 last_update_time 增量截止。
        """
        if not getattr(self, "_contests_only", False) or not self._new_contests:
            return None
        starts = [
            self._convert_iso_to_beijing(v)
            for v in self._new_contests.values()
            if v
        ]
        return min(starts) if starts else None

    def _problem_id_from_link(self, link):
        """从 problem_link 提取平台题目 ID。

        HDU/NowCoder：https://.../problem?cid=123&pid=1006  → "1006"
        QOJ：https://.../problem/123                          → "123"
        提取失败返回 None。
        """
        if not link:
            return None
        m = re.search(r"[?&]pid=(\d+)", link)
        if m:
            return m.group(1)
        m = re.search(r"/problem/(\d+)/?$", link)
        if m:
            return m.group(1)
        return None

    def _load_contests_with_times(self):
        """加载 contests.json，并为缺 start_time 的旧条目回填比赛文件夹里的时间。

        旧条目（本改动前写入）没有 start_time，跨赛季时间窗口判断会退化为全部匹配，
        导致早于比赛开始的提交无法被丢弃。这里按比赛文件夹 contest.json 回填一次。
        """
        contests = self._load_file(self.contests_path)
        changed = False
        for contest in contests:
            if contest.get("start_time"):
                continue
            folder = os.path.join(
                self.repo_dir, f"{contest['date']} {contest['name']}"
            )
            info_path = os.path.join(folder, "contest.json")
            if not os.path.exists(info_path):
                continue
            try:
                with open(info_path, "r", encoding="utf-8") as f:
                    info = json.load(f)
            except Exception:
                continue
            if info.get("start_time"):
                contest["start_time"] = info["start_time"]
                contest["end_time"] = info.get("end_time")
                changed = True
        if changed:
            self._write_file(self.contests_path, contests)
        return contests

    def _write_file(self, path, entry):
        # ensure file exists and is a json object
        if not os.path.exists(path):
            with open(path, "w", encoding="utf-8") as f:
                json.dump({}, f)
        with open(path, "w", encoding="utf-8") as f:
            json.dump(entry, f, indent=2)

    def _append_file(self, path, entry):
        # ensure file exists and is a json array
        if not os.path.exists(path):
            with open(path, "w", encoding="utf-8") as f:
                json.dump([], f)
        with open(path, "r+", encoding="utf-8") as f:
            try:
                lists = json.load(f)
            except Exception:
                lists = []
            lists.append(entry)
            f.seek(0)
            json.dump(lists, f, indent=2)
            f.truncate()

    def _resolve_driver_paths(self):
        """按平台解析 Chrome 与 chromedriver 路径。

        环境变量（CHROME_BINARY / CHROMEDRIVER_PATH）优先，缺省按平台回落：
        - Linux:   crawler/chrome-linux64/chrome + crawler/chromedriver-linux64/chromedriver
        - Windows: crawler/chrome-win64/chrome.exe + crawler/chromedriver-win64/chromedriver.exe
        - macOS:   系统安装的 Google Chrome + crawler/chromedriver-mac*/chromedriver
          （glob 匹配版本目录；未找到时返回 None，交给 undetected_chromedriver 自动查找）
        """
        sys_platform = sys.platform
        if sys_platform.startswith("win"):
            chrome_default = os.path.abspath("crawler/chrome-win64/chrome.exe")
            driver_default = os.path.abspath(
                "crawler/chromedriver-win64/chromedriver.exe"
            )
        elif sys_platform == "darwin":
            chrome_default = (
                "/Applications/Google Chrome.app/Contents/MacOS/Google Chrome"
            )
            matches = sorted(glob.glob("crawler/chromedriver-mac*/chromedriver"))
            driver_default = os.path.abspath(matches[0]) if matches else None
        else:  # linux 及未知平台，保持 v0.2.x 约定
            chrome_default = os.path.abspath("crawler/chrome-linux64/chrome")
            driver_default = os.path.abspath(
                "crawler/chromedriver-linux64/chromedriver"
            )

        chrome_binary = os.environ.get("CHROME_BINARY") or chrome_default
        chromedriver_path = os.environ.get("CHROMEDRIVER_PATH") or driver_default
        return chrome_binary, chromedriver_path

    def init_driver(self):
        options = uc.ChromeOptions()
        chrome_binary, chromedriver_path = self._resolve_driver_paths()
        if chrome_binary:
            options.binary_location = chrome_binary

        # Set preferences
        prefs = {
            "download.prompt_for_download": False,
            "download.directory_upgrade": True,
            "download.default_directory": os.path.abspath(self.download_dir),
            "plugins.always_open_pdf_externally": True,
            "safebrowsing.enabled": False,
        }
        options.add_experimental_option("prefs", prefs)

        options.add_argument("--headless")  # Uncomment for headless mode
        driver_kwargs = {"options": options}
        if chromedriver_path:
            driver_kwargs["driver_executable_path"] = chromedriver_path
        try:
            self.driver = uc.Chrome(**driver_kwargs)
        except Exception as e:
            self.log("fatal", f"Failed to start Chromium: {e}")

    def deinit_driver(self):
        if self.driver:
            self.driver.quit()
            self.driver = None

    def fetch_page_with_browser(self, url, wait_time=0):
        try:
            self.driver.get(url)
            if wait_time > 0:
                time.sleep(wait_time)
            else:
                self._random_sleep()
        except Exception as e:
            self.log("error", f"Failed to fetch page {url}: {str(e)}")
            return ""

        html = self.driver.page_source
        return html

    def _wait_for_download(self, timeout=30):
        for _ in range(timeout):
            files = glob.glob(os.path.join(self.download_dir, "*"))
            finished = [f for f in files if not f.endswith(".crdownload")]
            if finished:
                return finished[0]
            time.sleep(1)
        return None

    def download_file_with_browser(self, url, filename, target_folder):
        # Check if the target folder exists, create it if not
        if not os.path.exists(target_folder):
            self.log(
                "warning", f"Target folder {target_folder} does not exist, creating it."
            )
            os.makedirs(target_folder)

        # Clean up any existing files in the download_dir
        for file in os.listdir(self.download_dir):
            file_path = os.path.join(self.download_dir, file)
            os.remove(file_path)

        self.driver.get(url)
        time.sleep(3)  # Wait for the download to begin

        # Check if download_dir is empty
        if not os.listdir(self.download_dir):
            return False

        downloaded_path = self._wait_for_download()
        if downloaded_path:
            target_path = os.path.join(target_folder, filename)
            shutil.move(downloaded_path, target_path)
            return True
        else:
            self.log("error", f"Timeout waiting for {filename} to download.")
            return False

    def print_to_pdf_with_browser(self, url, filename, target_folder):
        if not os.path.exists(target_folder):
            self.log(
                "warning", f"Target folder {target_folder} does not exist, creating it."
            )
            os.makedirs(target_folder)

        self.driver.get(url)
        self._random_sleep()
        pdf = self.driver.execute_cdp_cmd(
            "Page.printToPDF", {"printBackground": True, "landscape": False}
        )
        with open(os.path.join(target_folder, filename), "wb") as f:
            f.write(base64.b64decode(pdf["data"]))

    def log(self, level, msg):
        """
        level: 'info', 'warning', 'important', 'error'
        info/warning -> only local log
        important/error -> local + global log
        """
        log_entry = {
            "time": datetime.now(beijing).isoformat(),
            "level": level,
            "platform": self.platform_name,
            "msg": msg,
        }
        print(
            f"[{log_entry['time']}] [{log_entry['level'].upper()}] {log_entry['msg']}"
        )
        # write local log
        self._append_file(self.local_log_path, log_entry)
        # write global log (only for important/error)
        if level in ("important", "error", "fatal"):
            self._append_file(self.global_log_path, log_entry)
        if level == "fatal":
            raise Exception(f"Fatal error in {self.platform_name} crawler: {msg}")

    def login(self):
        raise NotImplementedError

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
        raise NotImplementedError

    def fetch_contests_get_problem_list(self, contest_info, contest_folder):
        """
        Fetch the list of problems in a contest. You can also perform other operations like downloading the contest attachments.
        Return a dictionary with the following required keys:
        - letter: The letter of the problem (e.g., "A", "B", "C", etc.)
        - name: The name of the problem
        - link: The link to the problem page
        """
        raise NotImplementedError

    def fetch_contests_get_problem_details(
        self, problem_info, contest_folder, problem_path
    ):
        """
        Fetch the details of a problem in a contest. This includes downloading the problem statement PDF and extracting time/memory limits.
        Return a dictionary based on the problem_info. No additional keys are required.
        """
        raise NotImplementedError

    def fetch_contests(self):
        # First read local contests file
        self.contests = self._load_file(self.contests_path)

        # Then fetch contests from the website
        contest_list = self.fetch_contests_get_contest_list()
        if not contest_list:
            self.log("info", "Contest list is empty, no contests to fetch. Exiting.")
            return

        for contest_info in contest_list:
            contest_name = contest_info["name"]
            contest_date = contest_info["date"]
            contest_link = contest_info["link"]

            self.log(
                "info",
                f"Start fetching contest: {contest_name} ({contest_date})",
            )

            # Create contest folder
            contest_folder = os.path.join(
                self.repo_dir, f"{contest_date} {contest_name}"
            )
            if os.path.exists(contest_folder):
                self.log(
                    "warning",
                    f"Contest folder already exists: {contest_folder}. Skipped.",
                )
                continue
            else:
                os.makedirs(contest_folder)
                self.log("info", f"Created contest folder: {contest_folder}")
                # 记录本次运行新建的比赛：提交抓取时强制全量回填（见 _deadline_for）
                self._new_contests[contest_link] = contest_info.get("start_time")
                # 记录文件夹，供 report.py --from-crawl 只对本次预订的比赛生成报告
                self._new_contest_folders.append(contest_folder)

            self._write_file(
                os.path.join(contest_folder, "contest.json"),
                contest_info,
            )

            """
            Process the contest problems
            """
            # Create problems folder
            problems_folder = os.path.join(contest_folder, "problems")
            os.makedirs(problems_folder)

            problem_list = self.fetch_contests_get_problem_list(
                contest_info, contest_folder
            )
            if not problem_list:
                self.log(
                    "error",
                    f"Failed to fetch problem list for contest {contest_name}. Skipping.",
                )
                continue

            problems = []
            for problem_info in problem_list:
                # Create problem folder
                problem_letter = problem_info["letter"]
                problem_path = os.path.join(contest_folder, "problems", problem_letter)
                os.makedirs(problem_path, exist_ok=True)

                problem_link = problem_info["link"]
                problem_name = problem_info["name"]

                problem_entry = self.fetch_contests_get_problem_details(
                    problem_info, contest_folder, problem_path
                )
                if not problem_entry:
                    self.log(
                        "error",
                        f"Failed to fetch problem details for {problem_name} in {contest_name}.",
                    )
                    continue
                problem_entry["solved"] = False

                problems.append(
                    {
                        "letter": problem_letter,
                        "name": problem_name,
                        "link": problem_link,
                    }
                )
                # Write problem.json
                self._write_file(
                    os.path.join(problem_path, "problem.json"), problem_entry
                )

            # Create contest entry
            contest_entry = {
                "name": contest_name,
                "date": contest_date,
                "link": contest_link,
                "start_time": contest_info.get("start_time"),
                "end_time": contest_info.get("end_time"),
                "problems": problems,
            }
            self.contests.append(contest_entry)

            # Write the contest entry to the local file
            self._write_file(self.contests_path, self.contests)

            self.log(
                "info",
                f"Finished fetching contest: {contest_name} ({contest_date})",
            )

    def fetch_submissions_fetch_source_code(self, entry):
        raise NotImplementedError

    def fetch_submissions_get_submissions(self):
        raise NotImplementedError

    def _update_submission_status(self, entry):
        """把一份提交归档到对应的比赛/题目（三平台统一）。

        返回：
          - True    已归档到比赛文件夹（该提交从 staged 移除）
          - False   未匹配到任何比赛，保留在 staged-submissions.json
          - DISCARD 匹配到比赛但提交早于其开始时间（跨赛季复用历史提交），直接丢弃

        匹配规则：先按 problem_link、再按 problem_id（从 link 提取）、最后按
        problem_name 收集候选比赛；从候选中选出提交所属的那一场（start_time
        最晚且不晚于提交时间）。跨赛季复用同一道题时，提交属于其发生的那个
        赛季；早于所有匹配比赛开始的提交（如 QOJ 全局提交时间线里的上一赛季
        历史提交）直接丢弃。
        """
        ext = self._get_extension_name(entry["language"])
        filename = f"code.{ext}"
        submit_time = self._convert_iso_to_beijing(entry["submit_time"])
        entry_link = entry.get("problem_link", "")
        entry_id = entry.get("problem_id") or self._problem_id_from_link(entry_link)
        entry_name = entry.get("problem_name", "")

        # 收集 link / id / name 匹配到的 (contest, prob)
        link_candidates = []
        id_candidates = []
        name_candidates = []
        for contest in self.contests:
            for prob in contest.get("problems", []):
                prob_link = prob["link"]
                prob_id = self._problem_id_from_link(prob_link)
                if entry_link and prob_link == entry_link:
                    link_candidates.append((contest, prob))
                elif entry_id and prob_id and entry_id == prob_id:
                    id_candidates.append((contest, prob))
                elif entry_name and prob.get("name") == entry_name:
                    name_candidates.append((contest, prob))

        def pick_best(candidates):
            best = None
            for contest, prob in candidates:
                start = self._convert_iso_to_beijing(
                    contest.get("start_time", "1970-01-01T00:00:00")
                )
                if start <= submit_time and (best is None or start > best[0]):
                    best = (start, contest, prob)
            return best

        match = (
            pick_best(link_candidates)
            or pick_best(id_candidates)
            or pick_best(name_candidates)
        )
        if match is None:
            if link_candidates or id_candidates or name_candidates:
                # 匹配到比赛但提交早于其开始时间：跨赛季历史提交，直接丢弃
                self.log(
                    "info",
                    f"Submission {entry.get('submission_id')} at "
                    f"{entry['submit_time']} is before the matched contest start; "
                    "discarded.",
                )
                return DISCARD
            # 未匹配到任何比赛，交给 staged 流程处理
            for staged_entry in self.staged_submissions:
                if staged_entry.get("problem_link", "staged not found") == entry.get(
                    "problem_link", "entry not found"
                ) or staged_entry.get("problem_id", "staged not found") == entry.get(
                    "problem_id", "entry not found"
                ) or staged_entry.get(
                    "problem_name", "staged not found"
                ) == entry.get(
                    "problem_name", "entry not found"
                ):
                    if (
                        entry["status"] == "AC"
                        or not staged_entry.get("status") == "AC"
                    ):
                        # Update the existing entry with the new submission
                        staged_entry.update(entry)
                    break
            else:
                self.staged_submissions.append(entry)
                self._write_file(self.submissions_path, self.staged_submissions)
            return False

        _, contest, prob = match
        problem_folder = os.path.join(
            self.repo_dir,
            f"{contest['date']} {contest['name']}",
            "problems",
            prob["letter"],
        )
        # Get if the problem is solved
        problem_json_path = os.path.join(problem_folder, "problem.json")
        if not os.path.exists(problem_json_path):
            self.log(
                "error",
                f"Problem JSON not found for {prob['name']} in {problem_folder}.",
            )
            return False

        with open(problem_json_path, "r", encoding="utf-8") as f:
            problem_json = json.load(f)
        problem_solved = problem_json.get("solved", False)

        # 全量提交归档：submissions.json + problems/<letter>/submissions/<id>.<ext>
        # 每次提交都抓取源码并落盘（供复盘报告使用）。源码抓取失败不阻断元数据流程。
        try:
            code = self.fetch_submissions_fetch_source_code(entry)
        except Exception as e:
            self.log(
                "error",
                f"Failed to fetch source code for submission {entry.get('submission_id')}: {e}",
            )
            code = None
        self._archive_submission(contest, prob, entry, ext, code)

        # Update "submit_time" and code file
        is_newer = self._convert_iso_to_beijing(
            entry["submit_time"]
        ) > self._convert_iso_to_beijing(
            problem_json.get("submit_time", "1970-01-01T00:00:00")
        )
        if code is not None and not (entry["status"] != "AC" and problem_solved) and (
            is_newer or (entry.get("status") == "AC" and not problem_solved)
        ):
            problem_json["submit_time"] = entry["submit_time"]

            # Update source code file
            os.makedirs(problem_folder, exist_ok=True)
            file_path = os.path.join(problem_folder, filename)
            with open(file_path, "w", encoding="utf-8") as f:
                f.write(code)

            # Update code.{ext}.json
            self._write_file(
                os.path.join(problem_folder, f"code.{ext}.json"),
                entry,
            )

        # Update problem.json "solved" and "solve_time"
        if entry["status"] == "AC":
            problem_json["solved"] = True

            # If problem_json["solve_time"] is not set or later than entry["submit_time"], update it

            if "solve_time" not in problem_json or self._convert_iso_to_beijing(
                entry["submit_time"]
            ) < self._convert_iso_to_beijing(
                problem_json.get("solve_time", "1970-01-01T00:00:00")
            ):
                problem_json["solve_time"] = entry["submit_time"]

        self._write_file(problem_json_path, problem_json)
        return True

    def _archive_submission(self, contest, prob, entry, ext, code):
        """把一份提交完整归档（幂等，按 submission_id 去重）。

        - 元数据追加到 contests/<date> <name>/submissions.json
        - 源码写入 problems/<letter>/submissions/<id>.<ext>
        源码抓取失败不阻断元数据记录（完整性问题由 last-update 机制兜底）。
        """
        contest_folder = os.path.join(
            self.repo_dir, f"{contest['date']} {contest['name']}"
        )
        os.makedirs(contest_folder, exist_ok=True)
        submissions_path = os.path.join(contest_folder, "submissions.json")
        submissions = self._load_file(submissions_path, default=[])
        if any(
            s.get("submission_id") == entry.get("submission_id") for s in submissions
        ):
            return

        if code is not None:
            submissions_dir = os.path.join(
                contest_folder, "problems", prob["letter"], "submissions"
            )
            os.makedirs(submissions_dir, exist_ok=True)
            submission_file = os.path.join(
                submissions_dir, f"{entry['submission_id']}.{ext}"
            )
            with open(submission_file, "w", encoding="utf-8") as f:
                f.write(code)

        submissions.append(entry)
        self._write_file(submissions_path, submissions)

    def _register_submission(self, submission_entry, deadline=None):
        """
        Register a submission entry. This method is called after fetching each submission.
        Return a boolean indicating whether to stop fetching submissions.

        deadline: 本次抓取的截止时间（早于该时间的提交停止抓取）。
                  None 时使用全局 last_update_time（增量截止）；
                  首次抓取的新比赛传比赛 start_time，强制全量回填（见 _deadline_for）。
        """
        submit_time = self._convert_iso_to_beijing(submission_entry["submit_time"])
        submission_id = submission_entry["submission_id"]

        if deadline is None:
            deadline = self.last_update_time
        if submit_time < deadline:
            if deadline is self.last_update_time:
                self.log(
                    "info",
                    f"Reached last update (Submission {submission_id}), stopping.",
                )
            else:
                self.log(
                    "info",
                    f"Reached contest start (Submission {submission_id}), stopping.",
                )
            return True

        self._update_submission_status(submission_entry)
        return False

    def fetch_submissions(self):
        # Load last update time and staged submissions
        self.last_update = self._load_file(self.last_update_path, default={})
        last_update_time_str = self.last_update.get(
            self.platform_name, "1970-01-01T00:00:00"
        )
        self.last_update_time = self._convert_iso_to_beijing(last_update_time_str)

        # 加载比赛列表（旧条目缺 start_time 时按比赛文件夹回填）
        self.contests = self._load_contests_with_times()
        self.staged_submissions = self._load_file(self.submissions_path)

        # First try updating existing staged submissions
        self.log("info", "Start updating staged submissions...")
        new_staged = []
        # 遍历快照：_update_submission_status 对未匹配提交会 append 回
        # self.staged_submissions（供增量抓取路径入 staged），若直接遍历原列表
        # 会边遍历边增长导致无限循环。
        for entry in list(self.staged_submissions):
            result = self._update_submission_status(entry)
            if result == DISCARD:
                # 早于匹配比赛开始的 staged 提交（跨赛季历史遗留）直接丢弃
                self.log(
                    "info",
                    f"Staged submission {entry.get('submission_id')} is before the "
                    "matched contest start; discarded.",
                )
                continue
            if not result:
                new_staged.append(entry)
        self.staged_submissions = new_staged
        self._write_file(self.submissions_path, self.staged_submissions)

        # Fetch new submissions
        self.log("info", "Start fetching new submissions...")
        self.fetch_submissions_get_submissions()

    def _mark_submissions_complete(self):
        """标记提交抓取已完整结束（到达 last-update 或遍历完所有页）。

        仅在确认完整时调用；任何异常 break / 提前退出都不得调用，
        否则 last-update 被提前推进会导致提交永久漏抓。
        """
        self._submissions_fetch_complete = True

    def finish(self):
        self.deinit_driver()
        if not self._submissions_fetch_complete:
            self.log(
                "warning",
                "Submissions fetch was not marked complete; last-update not advanced.",
            )
            return
        if self._contests_only:
            # contests-only：只回填新建比赛的提交（可能完整也可能不完整），
            # 不推进全局 last-update——否则会跳过已有比赛在两次任务之间
            # 的新提交（已有比赛的增量同步由每日任务B --submissions-only 负责）。
            self.log(
                "info",
                "Contests-only run; last-update not advanced "
                "(incremental sync is handled by task B).",
            )
            return
        self.last_update = self._load_file(self.last_update_path, default={})
        self.last_update[self.platform_name] = datetime.now(beijing).isoformat()
        self._write_file(self.last_update_path, self.last_update)
