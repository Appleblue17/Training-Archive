"""crawler/platforms/nowcoder/nowcoder.py 登录态判断单元测试。"""

from crawler.platforms.nowcoder.nowcoder import _looks_logged_in


def test_looks_logged_in_with_username():
    html = "<html>欢迎，team0943</html>"
    assert _looks_logged_in(html, "team0943") is True
    assert _looks_logged_in(html, "someone_else") is False


def test_looks_logged_in_without_username_uses_page_features():
    """回归：未配置昵称时不能用 `"" in html`（恒真）误报登录成功。"""
    logged_in = '<a href="/acm/user/123">我的主页</a><a>退出</a>'
    logged_out = '<a>登录</a><a>注册</a>'
    assert _looks_logged_in(logged_in) is True
    assert _looks_logged_in(logged_out) is False


def test_looks_logged_in_empty_html():
    assert _looks_logged_in("") is False
    assert _looks_logged_in(None) is False
