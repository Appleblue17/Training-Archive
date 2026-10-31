"""下载等待逻辑测试。"""

from crawler.platforms.base import BaseCrawler


def _crawler(tmp_path):
    c = BaseCrawler.__new__(BaseCrawler)
    c.download_dir = str(tmp_path)
    return c


def test_wait_for_download_returns_finished_file(tmp_path):
    (tmp_path / "statement.pdf").write_bytes(b"x")
    assert _crawler(tmp_path)._wait_for_download(timeout=2).endswith("statement.pdf")


def test_wait_for_download_ignores_partial(tmp_path, monkeypatch):
    (tmp_path / "statement.pdf.crdownload").write_bytes(b"x")
    monkeypatch.setattr("crawler.platforms.base.time.sleep", lambda _s: None)
    assert _crawler(tmp_path)._wait_for_download(timeout=2) is None
