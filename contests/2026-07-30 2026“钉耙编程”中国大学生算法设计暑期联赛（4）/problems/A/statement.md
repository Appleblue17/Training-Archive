## A. A. Signal

### Problem Description

A 国和 B 国正在交战，战场是平面内的一个凸多边形
[[$P$][[[]{.strut style="height: 0.6833em;"}[P]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]。A 国的通信系统由
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个频道组成。频道 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 由平面内两个不同的点
[[$A_{i},B_{i}$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[[A]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 确定，其单位面积使用费用为
[[$w_{i}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
.mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

战场内一点 [[$p$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[p]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
能接收到频道 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的信号，当且仅当

[[[$$\overset{\rightarrow}{A_{i}B_{i}} \times \overset{\rightarrow}{A_{i}p} \geq 0,$$][[[]{.strut
style="height: 1.3553em; vertical-align: -0.15em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.mord}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjAuNTIyZW0iIHByZXNlcnZlYXNwZWN0cmF0aW89InhNYXhZTWluIHNsaWNlIiB2aWV3Ym94PSIwIDAgNDAwMDAwIDUyMiIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNMCAyNDF2NDBoMzk5ODkxYy00Ny4zIDM1LjMtODQgNzgtMTEwIDEyOAotMTYuNyAzMi0yNy43IDYzLjctMzMgOTUgMCAxLjMtLjIgMi43LS41IDQtLjMgMS4zLS41IDIuMy0uNSAzIDAgNy4zIDYuNyAxMSAyMAogMTEgOCAwIDEzLjItLjggMTUuNS0yLjUgMi4zLTEuNyA0LjItNS41IDUuNS0xMS41IDItMTMuMyA1LjctMjcgMTEtNDEgMTQuNy00NC43CiAzOS04NC41IDczLTExOS41czczLjctNjAuMiAxMTktNzUuNWM2LTIgOS01LjcgOS0xMXMtMy05LTktMTFjLTQ1LjMtMTUuMy04NQotNDAuNS0xMTktNzUuNXMtNTguMy03NC44LTczLTExOS41Yy00LjctMTQtOC4zLTI3LjMtMTEtNDAtMS4zLTYuNy0zLjItMTAuOC01LjUKLTEyLjUtMi4zLTEuNy03LjUtMi41LTE1LjUtMi41LTE0IDAtMjEgMy43LTIxIDExIDAgMiAyIDEwLjMgNiAyNSAyMC43IDgzLjMgNjcKIDE1MS43IDEzOSAyMDV6bTAgMHY0MGgzOTk5MDB2LTQweiI+PC9wYXRoPjwvc3ZnPg==)]{.hide-tail
style="height: 0.522em; min-width: 0.888em;"}]{.svg-align
style="top: -3.6833em;"}]{.vlist
style="height: 1.2053em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord
.accent}[]{.mspace style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.3998em; vertical-align: -0.1944em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[p]{.mord
.mathnormal}]{.mord}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjAuNTIyZW0iIHByZXNlcnZlYXNwZWN0cmF0aW89InhNYXhZTWluIHNsaWNlIiB2aWV3Ym94PSIwIDAgNDAwMDAwIDUyMiIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNMCAyNDF2NDBoMzk5ODkxYy00Ny4zIDM1LjMtODQgNzgtMTEwIDEyOAotMTYuNyAzMi0yNy43IDYzLjctMzMgOTUgMCAxLjMtLjIgMi43LS41IDQtLjMgMS4zLS41IDIuMy0uNSAzIDAgNy4zIDYuNyAxMSAyMAogMTEgOCAwIDEzLjItLjggMTUuNS0yLjUgMi4zLTEuNyA0LjItNS41IDUuNS0xMS41IDItMTMuMyA1LjctMjcgMTEtNDEgMTQuNy00NC43CiAzOS04NC41IDczLTExOS41czczLjctNjAuMiAxMTktNzUuNWM2LTIgOS01LjcgOS0xMXMtMy05LTktMTFjLTQ1LjMtMTUuMy04NQotNDAuNS0xMTktNzUuNXMtNTguMy03NC44LTczLTExOS41Yy00LjctMTQtOC4zLTI3LjMtMTEtNDAtMS4zLTYuNy0zLjItMTAuOC01LjUKLTEyLjUtMi4zLTEuNy03LjUtMi41LTE1LjUtMi41LTE0IDAtMjEgMy43LTIxIDExIDAgMiAyIDEwLjMgNiAyNSAyMC43IDgzLjMgNjcKIDE1MS43IDEzOSAyMDV6bTAgMHY0MGgzOTk5MDB2LTQweiI+PC9wYXRoPjwvc3ZnPg==)]{.hide-tail
style="height: 0.522em; min-width: 0.888em;"}]{.svg-align
style="top: -3.6833em;"}]{.vlist
style="height: 1.2053em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1944em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord
.accent}[]{.mspace style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}]{.base}]{.katex-html
aria-hidden="true"}]]

即 [[$p$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[p]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
位于有向直线 [[$A_{i}B_{i}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[A]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的左侧或直线上。

一次通信会恰好开启集合 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 中的所有频道。对于每个位置
[[$p$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[p]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，收集所有满足

[[[$$i \in S,\qquad\overset{\rightarrow}{A_{i}B_{i}} \times \overset{\rightarrow}{A_{i}p} \geq 0$$][[[]{.strut
style="height: 0.6986em; vertical-align: -0.0391em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.3998em; vertical-align: -0.1944em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 2em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.mord}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjAuNTIyZW0iIHByZXNlcnZlYXNwZWN0cmF0aW89InhNYXhZTWluIHNsaWNlIiB2aWV3Ym94PSIwIDAgNDAwMDAwIDUyMiIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNMCAyNDF2NDBoMzk5ODkxYy00Ny4zIDM1LjMtODQgNzgtMTEwIDEyOAotMTYuNyAzMi0yNy43IDYzLjctMzMgOTUgMCAxLjMtLjIgMi43LS41IDQtLjMgMS4zLS41IDIuMy0uNSAzIDAgNy4zIDYuNyAxMSAyMAogMTEgOCAwIDEzLjItLjggMTUuNS0yLjUgMi4zLTEuNyA0LjItNS41IDUuNS0xMS41IDItMTMuMyA1LjctMjcgMTEtNDEgMTQuNy00NC43CiAzOS04NC41IDczLTExOS41czczLjctNjAuMiAxMTktNzUuNWM2LTIgOS01LjcgOS0xMXMtMy05LTktMTFjLTQ1LjMtMTUuMy04NQotNDAuNS0xMTktNzUuNXMtNTguMy03NC44LTczLTExOS41Yy00LjctMTQtOC4zLTI3LjMtMTEtNDAtMS4zLTYuNy0zLjItMTAuOC01LjUKLTEyLjUtMi4zLTEuNy03LjUtMi41LTE1LjUtMi41LTE0IDAtMjEgMy43LTIxIDExIDAgMiAyIDEwLjMgNiAyNSAyMC43IDgzLjMgNjcKIDE1MS43IDEzOSAyMDV6bTAgMHY0MGgzOTk5MDB2LTQweiI+PC9wYXRoPjwvc3ZnPg==)]{.hide-tail
style="height: 0.522em; min-width: 0.888em;"}]{.svg-align
style="top: -3.6833em;"}]{.vlist
style="height: 1.2053em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord
.accent}[]{.mspace style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.3998em; vertical-align: -0.1944em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[p]{.mord
.mathnormal}]{.mord}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjAuNTIyZW0iIHByZXNlcnZlYXNwZWN0cmF0aW89InhNYXhZTWluIHNsaWNlIiB2aWV3Ym94PSIwIDAgNDAwMDAwIDUyMiIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNMCAyNDF2NDBoMzk5ODkxYy00Ny4zIDM1LjMtODQgNzgtMTEwIDEyOAotMTYuNyAzMi0yNy43IDYzLjctMzMgOTUgMCAxLjMtLjIgMi43LS41IDQtLjMgMS4zLS41IDIuMy0uNSAzIDAgNy4zIDYuNyAxMSAyMAogMTEgOCAwIDEzLjItLjggMTUuNS0yLjUgMi4zLTEuNyA0LjItNS41IDUuNS0xMS41IDItMTMuMyA1LjctMjcgMTEtNDEgMTQuNy00NC43CiAzOS04NC41IDczLTExOS41czczLjctNjAuMiAxMTktNzUuNWM2LTIgOS01LjcgOS0xMXMtMy05LTktMTFjLTQ1LjMtMTUuMy04NQotNDAuNS0xMTktNzUuNXMtNTguMy03NC44LTczLTExOS41Yy00LjctMTQtOC4zLTI3LjMtMTEtNDAtMS4zLTYuNy0zLjItMTAuOC01LjUKLTEyLjUtMi4zLTEuNy03LjUtMi41LTE1LjUtMi41LTE0IDAtMjEgMy43LTIxIDExIDAgMiAyIDEwLjMgNiAyNSAyMC43IDgzLjMgNjcKIDE1MS43IDEzOSAyMDV6bTAgMHY0MGgzOTk5MDB2LTQweiI+PC9wYXRoPjwvc3ZnPg==)]{.hide-tail
style="height: 0.522em; min-width: 0.888em;"}]{.svg-align
style="top: -3.6833em;"}]{.vlist
style="height: 1.2053em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1944em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord
.accent}[]{.mspace style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

的费用 [[$w_{i}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
.mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，并将它们从大到小排列。若其中至少有
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 个数，则
[[$f_{S,k}(p)$][[[]{.strut
style="height: 1.0361em; vertical-align: -0.2861em;"}[[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[S]{.mord .mathnormal .mtight
style="margin-right: 0.0576em;"}[,]{.mpunct .mtight}[k]{.mord
.mathnormal .mtight style="margin-right: 0.0315em;"}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[(]{.mopen}[p]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 是第 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 个数；否则定义
[[$f_{S,k}(p) = 0$][[[]{.strut
style="height: 1.0361em; vertical-align: -0.2861em;"}[[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[S]{.mord .mathnormal .mtight
style="margin-right: 0.0576em;"}[,]{.mpunct .mtight}[k]{.mord
.mathnormal .mtight style="margin-right: 0.0315em;"}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[(]{.mopen}[p]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。相同费用的不同频道需要分别计数。

A 国领导人想知道这次通信在整个战场上的总费用，即

[[[$${Ans}(S,k) = \int_{p \in P}f_{S,k}(p)dA.$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[Ans]{.mord
.mathrm}]{.mop}[(]{.mopen}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 2.4081em; vertical-align: -1.0481em;"}[[∫]{.mop
.op-symbol .large-op
style="margin-right: 0.4445em; position: relative; top: -0.0011em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[p]{.mord .mathnormal .mtight}[∈]{.mrel
.mtight}[P]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -1.7881em; margin-left: -0.4445em; margin-right: 0.05em;"}]{.vlist}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.0481em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[S]{.mord .mathnormal .mtight
style="margin-right: 0.0576em;"}[,]{.mpunct .mtight}[k]{.mord
.mathnormal .mtight style="margin-right: 0.0315em;"}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[(]{.mopen}[p]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.1667em;"}[d]{.mord .mathrm}[A]{.mord
.mathnormal}[.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

现在有 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 次相互独立的询问。每次询问给出集合
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 和整数 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}]，求出对应的
[[${Ans}(S,k)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[Ans]{.mord
.mathrm}]{.mop}[(]{.mopen}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

**样例解释**

频道 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 可以在
[[$x \leq 2$][[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[x]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的位置使用，频道
[[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 可以在
[[$y \geq 2$][[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的位置使用，单位面积使用费用分别为
[[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$5$][[[]{.strut
style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

对于第一组询问，[[$s = 3$][[[]{.strut
style="height: 0.4306em;"}[s]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，两个频道均被开启，且
[[$k = 1$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。正方形左上、左下、右上三个面积均为
[[$4$][[[]{.strut
style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的区域所取最大费用依次为
[[$5,3,5$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，所以答案为
[[[$$4 \times 5 + 4 \times 3 + 4 \times 5 = 52.$$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[52.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

第二组询问的 [[$k = 2$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。只有左上区域能同时接收到两个频道，其中第二大费用为
[[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，因此答案为
[[$4 \times 3 = 12$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[12]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

**数据范围**
- [[$1 \leq T \leq 5$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
    .mathnormal style="margin-right: 0.1389em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$1 \leq n \leq 18$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[18]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$3 \leq m \leq 30$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[3]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[30]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$1 \leq q \leq 2 \times 10^{5}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.1944em;"}[q]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 所有测试数据的 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    之和不超过 [[$36$][[[]{.strut
    style="height: 0.6444em;"}[36]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 所有测试数据的 [[$q$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
    .mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 之和不超过
    [[$4 \times 10^{5}$][[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[4]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 所有坐标均为整数，绝对值不超过 [[$10^{3}$][[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 对每个频道均有 [[$A_{i} \neq B_{i}$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[A]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[[[[[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
    .vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[B]{.mord
    .mathnormal style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$1 \leq w_{i} \leq 10^{6}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.786em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$0 \leq s < 2^{n}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.5782em; vertical-align: -0.0391em;"}[s]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6644em;"}[[2]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq k \leq n$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]；
- [[$P$][[[]{.strut style="height: 0.6833em;"}[P]{.mord
    .mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
    aria-hidden="true"}]
    是严格凸多边形，顶点按照逆时针顺序给出。

为了尽可能避免浮点数误差，数据还满足以下性质：将凸多边形的边界直线和所有半平面边界直线放在一起考虑，
- 任意两条边界直线要么平行，要么夹角正弦的绝对值至少为
    [[$10^{- 3}$][[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[−]{.mord .mtight}[3]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 平行的两条边界直线不会重合；
- 任意两条不平行边界直线的交点，到其他任意边界直线的距离至少为
    [[$10^{- 4}$][[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[−]{.mord .mtight}[4]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 答案\*\*绝对误差或相对误差不超过
    [[$10^{- 5}$][[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[−]{.mord .mtight}[5]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]\*\*则正确。

### Input

输入包含多组测试数据。第一行包含一个整数
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]，表示测试数据组数。

对于每组测试数据：
- 第一行包含三个整数 [[$n,m,q$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[m]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
    style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 接下来 [[$m$][[[]{.strut
    style="height: 0.4306em;"}[m]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    行，第 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    行包含两个整数 [[$x_{i},y_{i}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，表示凸多边形的第
    [[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个顶点。顶点按照逆时针顺序给出；
- 接下来 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    行，第 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    行包含五个整数
    [[$x_{i,1},y_{i,1},x_{i,2},y_{i,2},w_{i}$][[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
    .mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[2]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
    .mtight}[2]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，表示
    [[$A_{i} = (x_{i,1},y_{i,1})$][[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[A]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1.0361em; vertical-align: -0.2861em;"}[(]{.mopen}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
    .mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]、[[$B_{i} = (x_{i,2},y_{i,2})$][[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[B]{.mord
    .mathnormal style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1.0361em; vertical-align: -0.2861em;"}[(]{.mopen}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[2]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
    .mtight}[2]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 以及频道
    [[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的单位面积使用费用；
- 接下来 [[$q$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
    .mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 行，每行包含两个整数
    [[$s,k$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[s]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，表示一次询问。集合
    [[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
    .mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 使用十进制整数
    [[$s$][[[]{.strut style="height: 0.4306em;"}[s]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    编码：频道 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 属于
    [[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
    .mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，当且仅当
    [[$s$][[[]{.strut style="height: 0.4306em;"}[s]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 的第
    [[$i - 1$][[[]{.strut
    style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 个二进制位为
    [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。允许
    [[$k > \mid S\mid$][[[]{.strut
    style="height: 0.7335em; vertical-align: -0.0391em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[S]{.mord
    .mathnormal
    style="margin-right: 0.0576em;"}[∣]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，此时答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

### Output

对于每次询问，输出一行一个实数，表示对应通信的总费用。

设你的输出为 [[$x$][[[]{.strut
style="height: 0.4306em;"}[x]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，标准答案为
[[$y$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]。

### Sample Input

```plain
1
2 4 6
0 0
4 0
4 4
0 4
2 0 2 4 3
0 2 4 2 5
3 1
3 2
1 1
2 1
0 1
1 2
```

### Sample Output

```plain
52.0000000000
12.0000000000
24.0000000000
40.0000000000
0.0000000000
0.0000000000
```

