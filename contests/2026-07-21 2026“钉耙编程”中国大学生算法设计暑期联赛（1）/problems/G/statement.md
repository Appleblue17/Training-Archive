## G. 简单几何题

### Problem Description

小 D
生活在被无尽海洋覆盖的星球上。由于行星所处的恒星系统引力极其混沌，它的自转轴和公转轨道处于极度的不稳定状态。这导致太阳光直射的方向都是完全随机的。

行星的表面可以被视作三维欧几里得空间中的单位球面
[[$S^{2} = \{(x,y,z) \in \mathbb{R}^{3}:x^{2} + y^{2} + z^{2} = 1\}$][[[]{.strut
style="height: 0.8141em;"}[[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{(]{.mopen}[x]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[z]{.mord .mathnormal
style="margin-right: 0.044em;"}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[[R]{.mord .mathbb}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[:]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8974em; vertical-align: -0.0833em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[[z]{.mord .mathnormal
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。连接球面上任意两点（不为对跖点）的大圆上的劣弧，被称为短大圆弧。

![figure](../../../data/images/C1229-1007-1new.jpg)

这颗星球上仅有一块古老且连续的大陆 [[$P$][[[]{.strut
style="height: 0.6833em;"}[P]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]，[[$P$][[[]{.strut
style="height: 0.6833em;"}[P]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 是一个球面简单多边形。它是由
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
条短大圆弧首尾相连构成的闭合区域，其边界不自交。同时，这块大陆整体被严格包含在某个开半球之内。

当太阳光在星球上的直射点为 [[$s$][[[]{.strut
style="height: 0.4306em;"}[s]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 时，星球上处于白天的区域被定义为
[[$H_{s} = \{ x \in S^{2}:s \cdot x > 0\}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[H]{.mord
.mathnormal style="margin-right: 0.0813em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[s]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0813em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[x]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[:]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4445em;"}[s]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.5782em; vertical-align: -0.0391em;"}[x]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[0]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。界定白天与黑夜的大圆
[[$s \cdot x = 0$][[[]{.strut
style="height: 0.4445em;"}[s]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[x]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 称为晨昏线。

为了在变幻莫测的气候中生存，小 D 致力于建立精确的行星气象模型。小 D
的核心任务是：在给定大陆形状与任意太阳直射点
[[$s$][[[]{.strut style="height: 0.4306em;"}[s]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
时，计算这块大陆有多少比例的面积恰好沐浴在阳光之中。即求出以下百分比：

[[[$$\frac{\textsf{Area}(P \cap H_{s})}{\textsf{Area}(P)} \cdot 100\%$$][[[]{.strut
style="height: 2.363em; vertical-align: -0.936em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[Area]{.mord
.textsf}]{.mord .text}[(]{.mopen}[P]{.mord .mathnormal
style="margin-right: 0.1389em;"}[)]{.mclose}]{.mord}]{style="top: -2.314em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[Area]{.mord .textsf}]{.mord
.text}[(]{.mopen}[P]{.mord .mathnormal
style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2222em;"}[∩]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[[H]{.mord .mathnormal
style="margin-right: 0.0813em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[s]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0813em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.mord}]{style="top: -3.677em;"}]{.vlist
style="height: 1.427em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.936em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8056em; vertical-align: -0.0556em;"}[100%]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

**球面面积**：[[$\textsf{Area}(P)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[Area]{.mord
.textsf}]{.mord .text}[(]{.mopen}[P]{.mord .mathnormal
style="margin-right: 0.1389em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]
指区域在单位球面上的表面积。在单位球上，一个边界大圆平面之间的二面角分别为
[[$\alpha,\beta,\gamma$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[α]{.mord
.mathnormal style="margin-right: 0.0037em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[β]{.mord .mathnormal
style="margin-right: 0.0528em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[γ]{.mord .mathnormal
style="margin-right: 0.0556em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的球面三角形，其球面面积等于
[[$\alpha + \beta + \gamma - \pi$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[α]{.mord
.mathnormal style="margin-right: 0.0037em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[β]{.mord
.mathnormal style="margin-right: 0.0528em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7778em; vertical-align: -0.1944em;"}[γ]{.mord
.mathnormal style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[π]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]，可结合上图理解。

### Input

输入包含多组测试数据。第一行包含一个整数
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(1 \leq T \leq 500)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[500]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示测试数据的组数。

对于每组测试数据：

第一行包含两个整数 [[$n,q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(3 \leq n \leq 500,1 \leq q \leq 500)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[3]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[500]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[500]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，分别表示大陆多边形的顶点数和查询的太阳方向数。

接下来的 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含三个整数
[[$x,y,z$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[x]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[z]{.mord .mathnormal
style="margin-right: 0.044em;"}]{.base}]{.katex-html
aria-hidden="true"}]，表示多边形的顶点。第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个顶点对应的实际球面坐标为
[[$\left( \frac{x}{\sqrt{x^{2} + y^{2} + z^{2}}},\frac{y}{\sqrt{x^{2} + y^{2} + z^{2}}},\frac{z}{\sqrt{x^{2} + y^{2} + z^{2}}} \right)$][[[]{.strut
style="height: 2.4em; vertical-align: -0.95em;"}[[[(]{.delimsizing
.size3}]{.mopen .delimcenter style="top: 0em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[[[[[[]{.pstrut
style="height: 3.4286em;"}[[[x]{.mord .mathnormal
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[2]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[z]{.mord .mathnormal .mtight
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight style="padding-left: 1.19em;"}]{.svg-align
style="top: -3.4286em;"}[[]{.pstrut
style="height: 3.4286em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuNTQyOWVtIiBwcmVzZXJ2ZWFzcGVjdHJhdGlvPSJ4TWluWU1pbiBzbGljZSIgdmlld2JveD0iMCAwIDQwMDAwMCAxMDgwIiB3aWR0aD0iNDAwZW0iPjxwYXRoIGQ9Ik05NSw3MDIKYy0yLjcsMCwtNy4xNywtMi43LC0xMy41LC04Yy01LjgsLTUuMywtOS41LC0xMCwtOS41LC0xNApjMCwtMiwwLjMsLTMuMywxLC00YzEuMywtMi43LDIzLjgzLC0yMC43LDY3LjUsLTU0CmM0NC4yLC0zMy4zLDY1LjgsLTUwLjMsNjYuNSwtNTFjMS4zLC0xLjMsMywtMiw1LC0yYzQuNywwLDguNywzLjMsMTIsMTAKczE3MywzNzgsMTczLDM3OGMwLjcsMCwzNS4zLC03MSwxMDQsLTIxM2M2OC43LC0xNDIsMTM3LjUsLTI4NSwyMDYuNSwtNDI5CmM2OSwtMTQ0LDEwNC41LC0yMTcuNywxMDYuNSwtMjIxCmwwIC0wCmM1LjMsLTkuMywxMiwtMTQsMjAsLTE0Ckg0MDAwMDB2NDBIODQ1LjI3MjQKcy0yMjUuMjcyLDQ2NywtMjI1LjI3Miw0NjdzLTIzNSw0ODYsLTIzNSw0ODZjLTIuNyw0LjcsLTksNywtMTksNwpjLTYsMCwtMTAsLTEsLTEyLC0zcy0xOTQsLTQyMiwtMTk0LC00MjJzLTY1LDQ3LC02NSw0N3oKTTgzNCA4MGg0MDAwMDB2NDBoLTQwMDAwMHoiPjwvcGF0aD48L3N2Zz4=)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.5429em;"}]{style="top: -3.0348em;"}]{.vlist
style="height: 1.0628em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3937em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.446em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[x]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.6954em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.8296em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[[[[[[]{.pstrut
style="height: 3.4286em;"}[[[x]{.mord .mathnormal
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[2]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[z]{.mord .mathnormal .mtight
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight style="padding-left: 1.19em;"}]{.svg-align
style="top: -3.4286em;"}[[]{.pstrut
style="height: 3.4286em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuNTQyOWVtIiBwcmVzZXJ2ZWFzcGVjdHJhdGlvPSJ4TWluWU1pbiBzbGljZSIgdmlld2JveD0iMCAwIDQwMDAwMCAxMDgwIiB3aWR0aD0iNDAwZW0iPjxwYXRoIGQ9Ik05NSw3MDIKYy0yLjcsMCwtNy4xNywtMi43LC0xMy41LC04Yy01LjgsLTUuMywtOS41LC0xMCwtOS41LC0xNApjMCwtMiwwLjMsLTMuMywxLC00YzEuMywtMi43LDIzLjgzLC0yMC43LDY3LjUsLTU0CmM0NC4yLC0zMy4zLDY1LjgsLTUwLjMsNjYuNSwtNTFjMS4zLC0xLjMsMywtMiw1LC0yYzQuNywwLDguNywzLjMsMTIsMTAKczE3MywzNzgsMTczLDM3OGMwLjcsMCwzNS4zLC03MSwxMDQsLTIxM2M2OC43LC0xNDIsMTM3LjUsLTI4NSwyMDYuNSwtNDI5CmM2OSwtMTQ0LDEwNC41LC0yMTcuNywxMDYuNSwtMjIxCmwwIC0wCmM1LjMsLTkuMywxMiwtMTQsMjAsLTE0Ckg0MDAwMDB2NDBIODQ1LjI3MjQKcy0yMjUuMjcyLDQ2NywtMjI1LjI3Miw0NjdzLTIzNSw0ODYsLTIzNSw0ODZjLTIuNyw0LjcsLTksNywtMTksNwpjLTYsMCwtMTAsLTEsLTEyLC0zcy0xOTQsLTQyMiwtMTk0LC00MjJzLTY1LDQ3LC02NSw0N3oKTTgzNCA4MGg0MDAwMDB2NDBoLTQwMDAwMHoiPjwvcGF0aD48L3N2Zz4=)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.5429em;"}]{style="top: -3.0348em;"}]{.vlist
style="height: 1.0628em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3937em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.446em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -3.4461em;"}]{.vlist
style="height: 0.7475em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.8296em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[[[[[[]{.pstrut
style="height: 3.4286em;"}[[[x]{.mord .mathnormal
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[2]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[z]{.mord .mathnormal .mtight
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight style="padding-left: 1.19em;"}]{.svg-align
style="top: -3.4286em;"}[[]{.pstrut
style="height: 3.4286em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuNTQyOWVtIiBwcmVzZXJ2ZWFzcGVjdHJhdGlvPSJ4TWluWU1pbiBzbGljZSIgdmlld2JveD0iMCAwIDQwMDAwMCAxMDgwIiB3aWR0aD0iNDAwZW0iPjxwYXRoIGQ9Ik05NSw3MDIKYy0yLjcsMCwtNy4xNywtMi43LC0xMy41LC04Yy01LjgsLTUuMywtOS41LC0xMCwtOS41LC0xNApjMCwtMiwwLjMsLTMuMywxLC00YzEuMywtMi43LDIzLjgzLC0yMC43LDY3LjUsLTU0CmM0NC4yLC0zMy4zLDY1LjgsLTUwLjMsNjYuNSwtNTFjMS4zLC0xLjMsMywtMiw1LC0yYzQuNywwLDguNywzLjMsMTIsMTAKczE3MywzNzgsMTczLDM3OGMwLjcsMCwzNS4zLC03MSwxMDQsLTIxM2M2OC43LC0xNDIsMTM3LjUsLTI4NSwyMDYuNSwtNDI5CmM2OSwtMTQ0LDEwNC41LC0yMTcuNywxMDYuNSwtMjIxCmwwIC0wCmM1LjMsLTkuMywxMiwtMTQsMjAsLTE0Ckg0MDAwMDB2NDBIODQ1LjI3MjQKcy0yMjUuMjcyLDQ2NywtMjI1LjI3Miw0NjdzLTIzNSw0ODYsLTIzNSw0ODZjLTIuNyw0LjcsLTksNywtMTksNwpjLTYsMCwtMTAsLTEsLTEyLC0zcy0xOTQsLTQyMiwtMTk0LC00MjJzLTY1LDQ3LC02NSw0N3oKTTgzNCA4MGg0MDAwMDB2NDBoLTQwMDAwMHoiPjwvcGF0aD48L3N2Zz4=)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.5429em;"}]{style="top: -3.0348em;"}]{.vlist
style="height: 1.0628em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3937em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.446em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[z]{.mord .mathnormal .mtight
style="margin-right: 0.044em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.6954em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.8296em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[[)]{.delimsizing
.size3}]{.mclose .delimcenter
style="top: 0em;"}]{.minner}]{.base}]{.katex-html
aria-hidden="true"}]。顶点按相对于球体外侧的逆时针顺序给出。

接下来的 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含三个整数
[[$x,y,z$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[x]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[z]{.mord .mathnormal
style="margin-right: 0.044em;"}]{.base}]{.katex-html
aria-hidden="true"}]，表示一个查询的太阳直射点。对应的实际方向向量
[[$s$][[[]{.strut style="height: 0.4306em;"}[s]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 为
[[$\left( \frac{x}{\sqrt{x^{2} + y^{2} + z^{2}}},\frac{y}{\sqrt{x^{2} + y^{2} + z^{2}}},\frac{z}{\sqrt{x^{2} + y^{2} + z^{2}}} \right)$][[[]{.strut
style="height: 2.4em; vertical-align: -0.95em;"}[[[(]{.delimsizing
.size3}]{.mopen .delimcenter style="top: 0em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[[[[[[]{.pstrut
style="height: 3.4286em;"}[[[x]{.mord .mathnormal
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[2]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[z]{.mord .mathnormal .mtight
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight style="padding-left: 1.19em;"}]{.svg-align
style="top: -3.4286em;"}[[]{.pstrut
style="height: 3.4286em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuNTQyOWVtIiBwcmVzZXJ2ZWFzcGVjdHJhdGlvPSJ4TWluWU1pbiBzbGljZSIgdmlld2JveD0iMCAwIDQwMDAwMCAxMDgwIiB3aWR0aD0iNDAwZW0iPjxwYXRoIGQ9Ik05NSw3MDIKYy0yLjcsMCwtNy4xNywtMi43LC0xMy41LC04Yy01LjgsLTUuMywtOS41LC0xMCwtOS41LC0xNApjMCwtMiwwLjMsLTMuMywxLC00YzEuMywtMi43LDIzLjgzLC0yMC43LDY3LjUsLTU0CmM0NC4yLC0zMy4zLDY1LjgsLTUwLjMsNjYuNSwtNTFjMS4zLC0xLjMsMywtMiw1LC0yYzQuNywwLDguNywzLjMsMTIsMTAKczE3MywzNzgsMTczLDM3OGMwLjcsMCwzNS4zLC03MSwxMDQsLTIxM2M2OC43LC0xNDIsMTM3LjUsLTI4NSwyMDYuNSwtNDI5CmM2OSwtMTQ0LDEwNC41LC0yMTcuNywxMDYuNSwtMjIxCmwwIC0wCmM1LjMsLTkuMywxMiwtMTQsMjAsLTE0Ckg0MDAwMDB2NDBIODQ1LjI3MjQKcy0yMjUuMjcyLDQ2NywtMjI1LjI3Miw0NjdzLTIzNSw0ODYsLTIzNSw0ODZjLTIuNyw0LjcsLTksNywtMTksNwpjLTYsMCwtMTAsLTEsLTEyLC0zcy0xOTQsLTQyMiwtMTk0LC00MjJzLTY1LDQ3LC02NSw0N3oKTTgzNCA4MGg0MDAwMDB2NDBoLTQwMDAwMHoiPjwvcGF0aD48L3N2Zz4=)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.5429em;"}]{style="top: -3.0348em;"}]{.vlist
style="height: 1.0628em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3937em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.446em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[x]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.6954em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.8296em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[[[[[[]{.pstrut
style="height: 3.4286em;"}[[[x]{.mord .mathnormal
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[2]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[z]{.mord .mathnormal .mtight
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight style="padding-left: 1.19em;"}]{.svg-align
style="top: -3.4286em;"}[[]{.pstrut
style="height: 3.4286em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuNTQyOWVtIiBwcmVzZXJ2ZWFzcGVjdHJhdGlvPSJ4TWluWU1pbiBzbGljZSIgdmlld2JveD0iMCAwIDQwMDAwMCAxMDgwIiB3aWR0aD0iNDAwZW0iPjxwYXRoIGQ9Ik05NSw3MDIKYy0yLjcsMCwtNy4xNywtMi43LC0xMy41LC04Yy01LjgsLTUuMywtOS41LC0xMCwtOS41LC0xNApjMCwtMiwwLjMsLTMuMywxLC00YzEuMywtMi43LDIzLjgzLC0yMC43LDY3LjUsLTU0CmM0NC4yLC0zMy4zLDY1LjgsLTUwLjMsNjYuNSwtNTFjMS4zLC0xLjMsMywtMiw1LC0yYzQuNywwLDguNywzLjMsMTIsMTAKczE3MywzNzgsMTczLDM3OGMwLjcsMCwzNS4zLC03MSwxMDQsLTIxM2M2OC43LC0xNDIsMTM3LjUsLTI4NSwyMDYuNSwtNDI5CmM2OSwtMTQ0LDEwNC41LC0yMTcuNywxMDYuNSwtMjIxCmwwIC0wCmM1LjMsLTkuMywxMiwtMTQsMjAsLTE0Ckg0MDAwMDB2NDBIODQ1LjI3MjQKcy0yMjUuMjcyLDQ2NywtMjI1LjI3Miw0NjdzLTIzNSw0ODYsLTIzNSw0ODZjLTIuNyw0LjcsLTksNywtMTksNwpjLTYsMCwtMTAsLTEsLTEyLC0zcy0xOTQsLTQyMiwtMTk0LC00MjJzLTY1LDQ3LC02NSw0N3oKTTgzNCA4MGg0MDAwMDB2NDBoLTQwMDAwMHoiPjwvcGF0aD48L3N2Zz4=)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.5429em;"}]{style="top: -3.0348em;"}]{.vlist
style="height: 1.0628em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3937em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.446em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -3.4461em;"}]{.vlist
style="height: 0.7475em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.8296em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[[[[[[]{.pstrut
style="height: 3.4286em;"}[[[x]{.mord .mathnormal
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[2]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[+]{.mbin .mtight}[[z]{.mord .mathnormal .mtight
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7463em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight style="padding-left: 1.19em;"}]{.svg-align
style="top: -3.4286em;"}[[]{.pstrut
style="height: 3.4286em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuNTQyOWVtIiBwcmVzZXJ2ZWFzcGVjdHJhdGlvPSJ4TWluWU1pbiBzbGljZSIgdmlld2JveD0iMCAwIDQwMDAwMCAxMDgwIiB3aWR0aD0iNDAwZW0iPjxwYXRoIGQ9Ik05NSw3MDIKYy0yLjcsMCwtNy4xNywtMi43LC0xMy41LC04Yy01LjgsLTUuMywtOS41LC0xMCwtOS41LC0xNApjMCwtMiwwLjMsLTMuMywxLC00YzEuMywtMi43LDIzLjgzLC0yMC43LDY3LjUsLTU0CmM0NC4yLC0zMy4zLDY1LjgsLTUwLjMsNjYuNSwtNTFjMS4zLC0xLjMsMywtMiw1LC0yYzQuNywwLDguNywzLjMsMTIsMTAKczE3MywzNzgsMTczLDM3OGMwLjcsMCwzNS4zLC03MSwxMDQsLTIxM2M2OC43LC0xNDIsMTM3LjUsLTI4NSwyMDYuNSwtNDI5CmM2OSwtMTQ0LDEwNC41LC0yMTcuNywxMDYuNSwtMjIxCmwwIC0wCmM1LjMsLTkuMywxMiwtMTQsMjAsLTE0Ckg0MDAwMDB2NDBIODQ1LjI3MjQKcy0yMjUuMjcyLDQ2NywtMjI1LjI3Miw0NjdzLTIzNSw0ODYsLTIzNSw0ODZjLTIuNyw0LjcsLTksNywtMTksNwpjLTYsMCwtMTAsLTEsLTEyLC0zcy0xOTQsLTQyMiwtMTk0LC00MjJzLTY1LDQ3LC02NSw0N3oKTTgzNCA4MGg0MDAwMDB2NDBoLTQwMDAwMHoiPjwvcGF0aD48L3N2Zz4=)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.5429em;"}]{style="top: -3.0348em;"}]{.vlist
style="height: 1.0628em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3937em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.446em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[z]{.mord .mathnormal .mtight
style="margin-right: 0.044em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.6954em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.8296em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[[)]{.delimsizing
.size3}]{.mclose .delimcenter
style="top: 0em;"}]{.minner}]{.base}]{.katex-html
aria-hidden="true"}]。

**额外保证：**

1.  所有测试数据的
    [[$\sum nq \leq 5 \times 10^{6}$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
    .small-op style="position: relative; top: 0em;"}[]{.mspace
    style="margin-right: 0.1667em;"}[n]{.mord .mathnormal}[q]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  输入的所有坐标均满足
    [[$- 10^{5} \leq x,y,z \leq 10^{5}$][[[]{.strut
    style="height: 0.9501em; vertical-align: -0.136em;"}[−]{.mord}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.1944em;"}[x]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 且
    [[$(x,y,z) \neq (0,0,0)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[x]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[)]{.mclose}[]{.mspace
    style="margin-right: 0.2778em;"}[[[[[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
    .vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[0]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]。
3.  令 [[$\gamma = 10^{- 6}\ \textsf{rad}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[γ]{.mord
    .mathnormal style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[−]{.mord .mtight}[6]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[ ]{.mspace}[[rad]{.mord
    .textsf}]{.mord .text}]{.base}]{.katex-html
    aria-hidden="true"}]。对于多边形任意两个不同顶点
    [[$u,v$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[u]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，它们之间的球面距离
    [[$d(u,v)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[d]{.mord
    .mathnormal}[(]{.mopen}[u]{.mord .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 满足
    [[$\gamma \leq d(u,v) \leq \pi - \gamma$][[[]{.strut
    style="height: 0.8304em; vertical-align: -0.1944em;"}[γ]{.mord
    .mathnormal style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[d]{.mord
    .mathnormal}[(]{.mopen}[u]{.mord .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[)]{.mclose}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6667em; vertical-align: -0.0833em;"}[π]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[γ]{.mord
    .mathnormal style="margin-right: 0.0556em;"}]{.base}]{.katex-html
    aria-hidden="true"}]。
4.  多边形边界不自交；相邻三点不共大圆；多边形总面积保证
    [[$\textsf{Area}(P) \geq 10^{- 3}$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[Area]{.mord
    .textsf}]{.mord .text}[(]{.mopen}[P]{.mord .mathnormal
    style="margin-right: 0.1389em;"}[)]{.mclose}[]{.mspace
    style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[−]{.mord .mtight}[3]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
5.  对于任意给定的直射点 [[$s$][[[]{.strut
    style="height: 0.4306em;"}[s]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    和任意顶点 [[$p_{i}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，保证点积
    [[$s \cdot p_{i} \neq 0$][[[]{.strut
    style="height: 0.4445em;"}[s]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[p]{.mord
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
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，即晨昏线不会穿过任何一个多边形顶点。
6.  存在向量 [[$v$][[[]{.strut
    style="height: 0.4306em;"}[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 使得对任意
    [[$p_{i}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 满足
    [[$v \cdot p_{i} > 0$][[[]{.strut
    style="height: 0.4445em;"}[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7335em; vertical-align: -0.1944em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，即多边形整体被包含在某个开半球之内。

### Output

本题使用 Special Judge 进行评测。

对于每个查询，输出一行包含一个实数
[[$r \in \lbrack 0,100\rbrack$][[[]{.strut
style="height: 0.5782em; vertical-align: -0.0391em;"}[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[100]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示白天部分占总面积的百分比。如果你的输出为
[[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，标准答案为
[[$y$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]，当且仅当满足
[[$\frac{\mid x - y\mid}{\max(1,\mid y\mid)} \leq 10^{- 6}$][[[]{.strut
style="height: 1.53em; vertical-align: -0.52em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut
style="height: 3em;"}[[[[m]{.mtight}[a]{.mtight}[x]{.mtight}]{.mop
.mtight}[(]{.mopen .mtight}[1]{.mord .mtight}[,]{.mpunct
.mtight}[∣]{.mord .mtight}[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}[∣]{.mord .mtight}[)]{.mclose
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[∣]{.mord .mtight}[x]{.mord .mathnormal
.mtight}[−]{.mbin .mtight}[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}[∣]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.485em;"}]{.vlist
style="height: 1.01em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.52em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[−]{.mord .mtight}[6]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 时，你的答案将被视为正确。

### Sample Input

```plain
1
4 2
10 0 10
0 10 10
-10 0 10
0 5 10
0 -10 3
0 10 -3
```

### Sample Output

```plain
16.37693771831994469373
83.62306228168005500789
```

### Hint

下图为样例的俯视示意图，青色分界线为晨昏线（两次查询的方向恰好相反）。其中，深色区域为第一次查询对应的白天部分，而浅色区域为第二次查询对应的白天部分。

![figure](../../../data/images/C1229-1007-2new2.jpg)

该多边形总面积的精确形式为
[[$4\arctan\left( \frac{\sqrt{2}}{10 + 3\sqrt{10}} \right)$][[[]{.strut
style="height: 1.8em; vertical-align: -0.65em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[arctan]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[[[(]{.delimsizing .size2}]{.mopen
.delimcenter style="top: 0em;"}[[]{.mopen .nulldelimiter}[[[[[[]{.pstrut
style="height: 3em;"}[[[10]{.mord .mtight}[+]{.mbin .mtight}[3]{.mord
.mtight}[[[[[[]{.pstrut style="height: 3em;"}[[10]{.mord .mtight}]{.mord
.mtight style="padding-left: 0.833em;"}]{.svg-align
style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuMDhlbSIgcHJlc2VydmVhc3BlY3RyYXRpbz0ieE1pbllNaW4gc2xpY2UiIHZpZXdib3g9IjAgMCA0MDAwMDAgMTA4MCIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNOTUsNzAyCmMtMi43LDAsLTcuMTcsLTIuNywtMTMuNSwtOGMtNS44LC01LjMsLTkuNSwtMTAsLTkuNSwtMTQKYzAsLTIsMC4zLC0zLjMsMSwtNGMxLjMsLTIuNywyMy44MywtMjAuNyw2Ny41LC01NApjNDQuMiwtMzMuMyw2NS44LC01MC4zLDY2LjUsLTUxYzEuMywtMS4zLDMsLTIsNSwtMmM0LjcsMCw4LjcsMy4zLDEyLDEwCnMxNzMsMzc4LDE3MywzNzhjMC43LDAsMzUuMywtNzEsMTA0LC0yMTNjNjguNywtMTQyLDEzNy41LC0yODUsMjA2LjUsLTQyOQpjNjksLTE0NCwxMDQuNSwtMjE3LjcsMTA2LjUsLTIyMQpsMCAtMApjNS4zLC05LjMsMTIsLTE0LDIwLC0xNApINDAwMDAwdjQwSDg0NS4yNzI0CnMtMjI1LjI3Miw0NjcsLTIyNS4yNzIsNDY3cy0yMzUsNDg2LC0yMzUsNDg2Yy0yLjcsNC43LC05LDcsLTE5LDcKYy02LDAsLTEwLC0xLC0xMiwtM3MtMTk0LC00MjIsLTE5NCwtNDIycy02NSw0NywtNjUsNDd6Ck04MzQgODBoNDAwMDAwdjQwaC00MDAwMDB6Ij48L3BhdGg+PC9zdmc+)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.08em;"}]{style="top: -2.8728em;"}]{.vlist
style="height: 0.9128em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1272em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.551em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[[[[[[]{.pstrut style="height: 3em;"}[[2]{.mord
.mtight}]{.mord .mtight style="padding-left: 0.833em;"}]{.svg-align
style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuMDhlbSIgcHJlc2VydmVhc3BlY3RyYXRpbz0ieE1pbllNaW4gc2xpY2UiIHZpZXdib3g9IjAgMCA0MDAwMDAgMTA4MCIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNOTUsNzAyCmMtMi43LDAsLTcuMTcsLTIuNywtMTMuNSwtOGMtNS44LC01LjMsLTkuNSwtMTAsLTkuNSwtMTQKYzAsLTIsMC4zLC0zLjMsMSwtNGMxLjMsLTIuNywyMy44MywtMjAuNyw2Ny41LC01NApjNDQuMiwtMzMuMyw2NS44LC01MC4zLDY2LjUsLTUxYzEuMywtMS4zLDMsLTIsNSwtMmM0LjcsMCw4LjcsMy4zLDEyLDEwCnMxNzMsMzc4LDE3MywzNzhjMC43LDAsMzUuMywtNzEsMTA0LC0yMTNjNjguNywtMTQyLDEzNy41LC0yODUsMjA2LjUsLTQyOQpjNjksLTE0NCwxMDQuNSwtMjE3LjcsMTA2LjUsLTIyMQpsMCAtMApjNS4zLC05LjMsMTIsLTE0LDIwLC0xNApINDAwMDAwdjQwSDg0NS4yNzI0CnMtMjI1LjI3Miw0NjcsLTIyNS4yNzIsNDY3cy0yMzUsNDg2LC0yMzUsNDg2Yy0yLjcsNC43LC05LDcsLTE5LDcKYy02LDAsLTEwLC0xLC0xMiwtM3MtMTk0LC00MjIsLTE5NCwtNDIycy02NSw0NywtNjUsNDd6Ck04MzQgODBoNDAwMDAwdjQwaC00MDAwMDB6Ij48L3BhdGg+PC9zdmc+)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.08em;"}]{style="top: -2.8728em;"}]{.vlist
style="height: 0.9128em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1272em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.399em;"}]{.vlist
style="height: 1.038em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.538em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[[)]{.delimsizing
.size2}]{.mclose .delimcenter
style="top: 0em;"}]{.minner}]{.base}]{.katex-html
aria-hidden="true"}]。

第一次询问所对应的区域面积的精确形式为
[[$4\arctan\left( \frac{9\sqrt{2}}{274 + 85\sqrt{10} + 28\sqrt{79} + 10\sqrt{790}} \right)$][[[]{.strut
style="height: 1.8em; vertical-align: -0.65em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[arctan]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[[[(]{.delimsizing .size2}]{.mopen
.delimcenter style="top: 0em;"}[[]{.mopen .nulldelimiter}[[[[[[]{.pstrut
style="height: 3em;"}[[[274]{.mord .mtight}[+]{.mbin .mtight}[85]{.mord
.mtight}[[[[[[]{.pstrut style="height: 3em;"}[[10]{.mord .mtight}]{.mord
.mtight style="padding-left: 0.833em;"}]{.svg-align
style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuMDhlbSIgcHJlc2VydmVhc3BlY3RyYXRpbz0ieE1pbllNaW4gc2xpY2UiIHZpZXdib3g9IjAgMCA0MDAwMDAgMTA4MCIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNOTUsNzAyCmMtMi43LDAsLTcuMTcsLTIuNywtMTMuNSwtOGMtNS44LC01LjMsLTkuNSwtMTAsLTkuNSwtMTQKYzAsLTIsMC4zLC0zLjMsMSwtNGMxLjMsLTIuNywyMy44MywtMjAuNyw2Ny41LC01NApjNDQuMiwtMzMuMyw2NS44LC01MC4zLDY2LjUsLTUxYzEuMywtMS4zLDMsLTIsNSwtMmM0LjcsMCw4LjcsMy4zLDEyLDEwCnMxNzMsMzc4LDE3MywzNzhjMC43LDAsMzUuMywtNzEsMTA0LC0yMTNjNjguNywtMTQyLDEzNy41LC0yODUsMjA2LjUsLTQyOQpjNjksLTE0NCwxMDQuNSwtMjE3LjcsMTA2LjUsLTIyMQpsMCAtMApjNS4zLC05LjMsMTIsLTE0LDIwLC0xNApINDAwMDAwdjQwSDg0NS4yNzI0CnMtMjI1LjI3Miw0NjcsLTIyNS4yNzIsNDY3cy0yMzUsNDg2LC0yMzUsNDg2Yy0yLjcsNC43LC05LDcsLTE5LDcKYy02LDAsLTEwLC0xLC0xMiwtM3MtMTk0LC00MjIsLTE5NCwtNDIycy02NSw0NywtNjUsNDd6Ck04MzQgODBoNDAwMDAwdjQwaC00MDAwMDB6Ij48L3BhdGg+PC9zdmc+)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.08em;"}]{style="top: -2.8728em;"}]{.vlist
style="height: 0.9128em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1272em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}[+]{.mbin .mtight}[28]{.mord .mtight}[[[[[[]{.pstrut
style="height: 3em;"}[[79]{.mord .mtight}]{.mord .mtight
style="padding-left: 0.833em;"}]{.svg-align
style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuMDhlbSIgcHJlc2VydmVhc3BlY3RyYXRpbz0ieE1pbllNaW4gc2xpY2UiIHZpZXdib3g9IjAgMCA0MDAwMDAgMTA4MCIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNOTUsNzAyCmMtMi43LDAsLTcuMTcsLTIuNywtMTMuNSwtOGMtNS44LC01LjMsLTkuNSwtMTAsLTkuNSwtMTQKYzAsLTIsMC4zLC0zLjMsMSwtNGMxLjMsLTIuNywyMy44MywtMjAuNyw2Ny41LC01NApjNDQuMiwtMzMuMyw2NS44LC01MC4zLDY2LjUsLTUxYzEuMywtMS4zLDMsLTIsNSwtMmM0LjcsMCw4LjcsMy4zLDEyLDEwCnMxNzMsMzc4LDE3MywzNzhjMC43LDAsMzUuMywtNzEsMTA0LC0yMTNjNjguNywtMTQyLDEzNy41LC0yODUsMjA2LjUsLTQyOQpjNjksLTE0NCwxMDQuNSwtMjE3LjcsMTA2LjUsLTIyMQpsMCAtMApjNS4zLC05LjMsMTIsLTE0LDIwLC0xNApINDAwMDAwdjQwSDg0NS4yNzI0CnMtMjI1LjI3Miw0NjcsLTIyNS4yNzIsNDY3cy0yMzUsNDg2LC0yMzUsNDg2Yy0yLjcsNC43LC05LDcsLTE5LDcKYy02LDAsLTEwLC0xLC0xMiwtM3MtMTk0LC00MjIsLTE5NCwtNDIycy02NSw0NywtNjUsNDd6Ck04MzQgODBoNDAwMDAwdjQwaC00MDAwMDB6Ij48L3BhdGg+PC9zdmc+)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.08em;"}]{style="top: -2.8728em;"}]{.vlist
style="height: 0.9128em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1272em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}[+]{.mbin .mtight}[10]{.mord .mtight}[[[[[[]{.pstrut
style="height: 3em;"}[[790]{.mord .mtight}]{.mord .mtight
style="padding-left: 0.833em;"}]{.svg-align
style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuMDhlbSIgcHJlc2VydmVhc3BlY3RyYXRpbz0ieE1pbllNaW4gc2xpY2UiIHZpZXdib3g9IjAgMCA0MDAwMDAgMTA4MCIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNOTUsNzAyCmMtMi43LDAsLTcuMTcsLTIuNywtMTMuNSwtOGMtNS44LC01LjMsLTkuNSwtMTAsLTkuNSwtMTQKYzAsLTIsMC4zLC0zLjMsMSwtNGMxLjMsLTIuNywyMy44MywtMjAuNyw2Ny41LC01NApjNDQuMiwtMzMuMyw2NS44LC01MC4zLDY2LjUsLTUxYzEuMywtMS4zLDMsLTIsNSwtMmM0LjcsMCw4LjcsMy4zLDEyLDEwCnMxNzMsMzc4LDE3MywzNzhjMC43LDAsMzUuMywtNzEsMTA0LC0yMTNjNjguNywtMTQyLDEzNy41LC0yODUsMjA2LjUsLTQyOQpjNjksLTE0NCwxMDQuNSwtMjE3LjcsMTA2LjUsLTIyMQpsMCAtMApjNS4zLC05LjMsMTIsLTE0LDIwLC0xNApINDAwMDAwdjQwSDg0NS4yNzI0CnMtMjI1LjI3Miw0NjcsLTIyNS4yNzIsNDY3cy0yMzUsNDg2LC0yMzUsNDg2Yy0yLjcsNC43LC05LDcsLTE5LDcKYy02LDAsLTEwLC0xLC0xMiwtM3MtMTk0LC00MjIsLTE5NCwtNDIycy02NSw0NywtNjUsNDd6Ck04MzQgODBoNDAwMDAwdjQwaC00MDAwMDB6Ij48L3BhdGg+PC9zdmc+)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.08em;"}]{style="top: -2.8728em;"}]{.vlist
style="height: 0.9128em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1272em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.551em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[9]{.mord .mtight}[[[[[[]{.pstrut
style="height: 3em;"}[[2]{.mord .mtight}]{.mord .mtight
style="padding-left: 0.833em;"}]{.svg-align
style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuMDhlbSIgcHJlc2VydmVhc3BlY3RyYXRpbz0ieE1pbllNaW4gc2xpY2UiIHZpZXdib3g9IjAgMCA0MDAwMDAgMTA4MCIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNOTUsNzAyCmMtMi43LDAsLTcuMTcsLTIuNywtMTMuNSwtOGMtNS44LC01LjMsLTkuNSwtMTAsLTkuNSwtMTQKYzAsLTIsMC4zLC0zLjMsMSwtNGMxLjMsLTIuNywyMy44MywtMjAuNyw2Ny41LC01NApjNDQuMiwtMzMuMyw2NS44LC01MC4zLDY2LjUsLTUxYzEuMywtMS4zLDMsLTIsNSwtMmM0LjcsMCw4LjcsMy4zLDEyLDEwCnMxNzMsMzc4LDE3MywzNzhjMC43LDAsMzUuMywtNzEsMTA0LC0yMTNjNjguNywtMTQyLDEzNy41LC0yODUsMjA2LjUsLTQyOQpjNjksLTE0NCwxMDQuNSwtMjE3LjcsMTA2LjUsLTIyMQpsMCAtMApjNS4zLC05LjMsMTIsLTE0LDIwLC0xNApINDAwMDAwdjQwSDg0NS4yNzI0CnMtMjI1LjI3Miw0NjcsLTIyNS4yNzIsNDY3cy0yMzUsNDg2LC0yMzUsNDg2Yy0yLjcsNC43LC05LDcsLTE5LDcKYy02LDAsLTEwLC0xLC0xMiwtM3MtMTk0LC00MjIsLTE5NCwtNDIycy02NSw0NywtNjUsNDd6Ck04MzQgODBoNDAwMDAwdjQwaC00MDAwMDB6Ij48L3BhdGg+PC9zdmc+)]{.hide-tail
.mtight
style="min-width: 0.853em; height: 1.08em;"}]{style="top: -2.8728em;"}]{.vlist
style="height: 0.9128em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1272em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord .sqrt
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.399em;"}]{.vlist
style="height: 1.038em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.538em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[[)]{.delimsizing
.size2}]{.mclose .delimcenter
style="top: 0em;"}]{.minner}]{.base}]{.katex-html
aria-hidden="true"}]。

