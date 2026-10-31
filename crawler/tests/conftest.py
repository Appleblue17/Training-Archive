"""crawler 测试共用配置：把仓库根加入 sys.path，使 `import crawler.*` 可用。"""

import os
import sys

REPO_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))
if REPO_ROOT not in sys.path:
    sys.path.insert(0, REPO_ROOT)
