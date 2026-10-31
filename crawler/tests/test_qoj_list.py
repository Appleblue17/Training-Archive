"""QOJ 比赛列表解析：table-default 行也必须识别。"""

from crawler.platforms.qoj.qoj import QOJCrawler

HTML = """
<html><body><table><tbody>
<tr class="table-default">
  <td><a href="/contest/123">Test Contest</a></td>
  <td><a>2026-01-01 10:00:00</a></td>
  <td>[5 hours]</td>
  <td>?</td>
</tr>
</tbody></table></body></html>
"""


def test_contest_list_accepts_table_default():
    c = QOJCrawler.__new__(QOJCrawler)
    c.base_url = "https://qoj.ac"
    c.platform_name = "qoj"
    c.contests = []
    c._only_links = {"https://qoj.ac/contest/123"}
    c.log = lambda *a, **k: None
    c.fetch_page_with_browser = lambda url: HTML
    c._load_subscriptions = lambda platform: [{"link": "https://qoj.ac/contest/123"}]
    infos = c.fetch_contests_get_contest_list()
    assert len(infos) == 1
    assert infos[0]["link"] == "https://qoj.ac/contest/123"
    assert infos[0]["name"] == "Test Contest"


def test_contest_list_falls_back_to_cache(tmp_path):
    c = QOJCrawler.__new__(QOJCrawler)
    c.base_url = "https://qoj.ac"
    c.platform_name = "qoj"
    c.repo_dir = str(tmp_path)
    c.contests = [{
        "name": "Cached",
        "date": "2026-05-01",
        "link": "https://qoj.ac/contest/9",
        "start_time": "2026-05-01T09:00:00+08:00",
        "end_time": "2026-05-01T14:00:00+08:00",
    }]
    c._only_links = {"https://qoj.ac/contest/9"}
    c.log = lambda *a, **k: None
    c.fetch_page_with_browser = lambda url: "<html></html>"
    c._load_subscriptions = lambda platform: [{"link": "https://qoj.ac/contest/9"}]
    infos = c.fetch_contests_get_contest_list()
    assert len(infos) == 1
    assert infos[0]["link"] == "https://qoj.ac/contest/9"
