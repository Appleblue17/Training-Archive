"""crawler/platforms/qoj/qoj.py 时长解析单元测试。"""

from datetime import timedelta

import pytest

from crawler.platforms.qoj.qoj import _parse_qoj_duration


@pytest.mark.parametrize("text,expected", [
    ("[2 hours]", timedelta(hours=2)),
    ("2 hours", timedelta(hours=2)),
    ("[2 hour]", timedelta(hours=2)),
    ("[2 hours 30 minutes]", timedelta(hours=2, minutes=30)),
    ("[1 hour 5 minutes]", timedelta(hours=1, minutes=5)),
    ("[90 minutes]", timedelta(minutes=90)),
    ("[45 minutes]", timedelta(minutes=45)),
    ("0 hours", timedelta(0)),
])
def test_parse_qoj_duration(text, expected):
    assert _parse_qoj_duration(text) == expected


@pytest.mark.parametrize("text", ["", "??", "N/A", "hours"])
def test_parse_qoj_duration_invalid(text):
    with pytest.raises(ValueError):
        _parse_qoj_duration(text)
