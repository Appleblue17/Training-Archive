## D. 今晚吃转转

### Problem Description

*即便是最细小的枝桠也能孕育无限可能。*

*地脉正在颤动，世界树岌岌可危。* 原本的世界树可以被看作一棵包含
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 个点与
[[$n - 1$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 条边的无根树
[[$Y$][[[]{.strut style="height: 0.6833em;"}[Y]{.mord
.mathnormal style="margin-right: 0.2222em;"}]{.base}]{.katex-html
aria-hidden="true"}]
被绘制在平面上。[[$Y$][[[]{.strut
style="height: 0.6833em;"}[Y]{.mord .mathnormal
style="margin-right: 0.2222em;"}]{.base}]{.katex-html
aria-hidden="true"}] 中的第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）个点在坐标
[[$(x_{i},y_{i})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[[x]{.mord
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
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]（[[$x_{i},y_{i} \in \mathbb{R}$][[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[[x]{.mord
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
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6889em;"}[R]{.mord .mathbb}]{.base}]{.katex-html
aria-hidden="true"}]）处，点的坐标两两不同。[[$Y$][[[]{.strut
style="height: 0.6833em;"}[Y]{.mord .mathnormal
style="margin-right: 0.2222em;"}]{.base}]{.katex-html
aria-hidden="true"}]
的每条边都是连接两个端点的线段，连接后平面上的图形就被称为
[[$Y$][[[]{.strut style="height: 0.6833em;"}[Y]{.mord
.mathnormal style="margin-right: 0.2222em;"}]{.base}]{.katex-html
aria-hidden="true"}]
的**图像**。注意，图像不能进行平移，缩放，旋转，轴对称等任何操作。

*由于地脉紊乱，世界树被迫旋转。* 现在，平面中出现了一个紊乱点
[[$(p,q)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[p]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]（[[$p,q \in \mathbb{R}$][[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[p]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6889em;"}[R]{.mord .mathbb}]{.base}]{.katex-html
aria-hidden="true"}]），使得世界树
[[$Y$][[[]{.strut style="height: 0.6833em;"}[Y]{.mord
.mathnormal style="margin-right: 0.2222em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的图像以
[[$(p,q)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[p]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 为中心顺时针旋转了
[[$\frac{2\pi}{k}$][[[]{.strut
style="height: 1.1901em; vertical-align: -0.345em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[k]{.mord
.mathnormal .mtight style="margin-right: 0.0315em;"}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[2]{.mord .mtight}[π]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 弧度，其中 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}]
是一个正整数。注意紊乱点坐标是任意的，可以与世界树某一个点重合，也可以落在世界树某一条边上。

作为新生的小吉祥草王，纳西妲只知道世界树
[[$Y$][[[]{.strut style="height: 0.6833em;"}[Y]{.mord
.mathnormal style="margin-right: 0.2222em;"}]{.base}]{.katex-html
aria-hidden="true"}]
的形态而不知道它的图像。纳西妲想要知道，对于哪些正整数
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}]，存在一个为
[[$Y$][[[]{.strut style="height: 0.6833em;"}[Y]{.mord
.mathnormal style="margin-right: 0.2222em;"}]{.base}]{.katex-html
aria-hidden="true"}]
中每个点赋予两两不同的坐标以及选取紊乱点坐标的方式，使得：
- [[$Y$][[[]{.strut style="height: 0.6833em;"}[Y]{.mord
    .mathnormal style="margin-right: 0.2222em;"}]{.base}]{.katex-html
    aria-hidden="true"}]
    的图像中，任意两条边对应的线段除公共端点外不相交（包括某一条边的端点落在另一条边上的情况）。
- [[$Y$][[[]{.strut style="height: 0.6833em;"}[Y]{.mord
    .mathnormal style="margin-right: 0.2222em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 的图像旋转后与其旋转前完全重合。

注意，判断重合时不能进行平移，缩放，旋转，轴对称等任何操作。

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 10^{3}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

接下来对于每一组测试数据：

第一行包含一个整数 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$2 \leq n \leq 2 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$\sum n \leq 10^{6}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示世界树的大小。

接下来 [[$n - 1$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 行，第 [[$i + 1$][[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i < n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6986em; vertical-align: -0.0391em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）行包含两个整数
[[$u_{i},v_{i}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[u]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq u_{i},v_{i} \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[[u]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），表示第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 条边连接的两个端点。

### Output

对于每一组测试数据：

第一行包含一个整数 [[$c$][[[]{.strut
style="height: 0.4306em;"}[c]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，表示满足条件的正整数
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的个数。

第二行包含 [[$c$][[[]{.strut
style="height: 0.4306em;"}[c]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个整数
[[$k_{1},k_{2},k_{3},\cdots,k_{c}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[c]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq k_{1} < k_{2} < k_{3} < \cdots < k_{c}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5782em; vertical-align: -0.0391em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[c]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示每个满足条件的正整数
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}]。

### Sample Input

```plain
2
10
1 2
2 3
3 4
4 5
2 7
4 6
3 8
8 9
8 10
8
1 2
1 3
1 4
1 5
1 6
1 7
2 8
```

### Sample Output

```plain
2
1 3
4
1 2 3 6
```

### Hint

以第一组测试数据为例，一个 [[$k = 3$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的合法点坐标为（按照编号顺序）：

[[$(6,4),\ (5,4),\ (3,4),\ (2,4 + \sqrt{3}),\ \left( \frac{3}{2},4 + \frac{3\sqrt{3}}{2} \right),$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[6]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[)]{.mclose}[,]{.mpunct}[ ]{.mspace}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[)]{.mclose}[,]{.mpunct}[ ]{.mspace}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[)]{.mclose}[,]{.mpunct}[ ]{.mspace}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.8em; vertical-align: -0.65em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[3]{.mord}]{.mord
style="padding-left: 0.833em;"}]{.svg-align
style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuMDhlbSIgcHJlc2VydmVhc3BlY3RyYXRpbz0ieE1pbllNaW4gc2xpY2UiIHZpZXdib3g9IjAgMCA0MDAwMDAgMTA4MCIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNOTUsNzAyCmMtMi43LDAsLTcuMTcsLTIuNywtMTMuNSwtOGMtNS44LC01LjMsLTkuNSwtMTAsLTkuNSwtMTQKYzAsLTIsMC4zLC0zLjMsMSwtNGMxLjMsLTIuNywyMy44MywtMjAuNyw2Ny41LC01NApjNDQuMiwtMzMuMyw2NS44LC01MC4zLDY2LjUsLTUxYzEuMywtMS4zLDMsLTIsNSwtMmM0LjcsMCw4LjcsMy4zLDEyLDEwCnMxNzMsMzc4LDE3MywzNzhjMC43LDAsMzUuMywtNzEsMTA0LC0yMTNjNjguNywtMTQyLDEzNy41LC0yODUsMjA2LjUsLTQyOQpjNjksLTE0NCwxMDQuNSwtMjE3LjcsMTA2LjUsLTIyMQpsMCAtMApjNS4zLC05LjMsMTIsLTE0LDIwLC0xNApINDAwMDAwdjQwSDg0NS4yNzI0CnMtMjI1LjI3Miw0NjcsLTIyNS4yNzIsNDY3cy0yMzUsNDg2LC0yMzUsNDg2Yy0yLjcsNC43LC05LDcsLTE5LDcKYy02LDAsLTEwLC0xLC0xMiwtM3MtMTk0LC00MjIsLTE5NCwtNDIycy02NSw0NywtNjUsNDd6Ck04MzQgODBoNDAwMDAwdjQwaC00MDAwMDB6Ij48L3BhdGg+PC9zdmc+)]{.hide-tail
style="min-width: 0.853em; height: 1.08em;"}]{style="top: -2.8672em;"}]{.vlist
style="height: 0.9072em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1328em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord
.sqrt}[)]{.mclose}[,]{.mpunct}[ ]{.mspace}[]{.mspace
style="margin-right: 0.1667em;"}[[[(]{.delimsizing .size2}]{.mopen
.delimcenter style="top: 0em;"}[[]{.mopen .nulldelimiter}[[[[[[]{.pstrut
style="height: 3em;"}[[[2]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[3]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[2]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[3]{.mord .mtight}[[[[[[]{.pstrut
style="height: 3em;"}[[3]{.mord .mtight}]{.mord .mtight
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
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[[)]{.delimsizing
.size2}]{.mclose .delimcenter style="top: 0em;"}]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}]{.base}]{.katex-html
aria-hidden="true"}]

[[$\left( 3 - \frac{5\sqrt{3}}{4},\frac{21}{4} \right),\ \left( 3 + \frac{5\sqrt{3}}{4},\frac{21}{4} \right),\ (2,4 - \sqrt{3}),\ \left( \frac{3}{2},4 - \frac{3\sqrt{3}}{2} \right),\ \left( 3,\frac{3}{2} \right)$][[[]{.strut
style="height: 1.8em; vertical-align: -0.65em;"}[[[(]{.delimsizing
.size2}]{.mopen .delimcenter style="top: 0em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[4]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[5]{.mord .mtight}[[[[[[]{.pstrut
style="height: 3em;"}[[3]{.mord .mtight}]{.mord .mtight
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
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[4]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[21]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[[)]{.delimsizing
.size2}]{.mclose .delimcenter style="top: 0em;"}]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[ ]{.mspace}[]{.mspace
style="margin-right: 0.1667em;"}[[[(]{.delimsizing .size2}]{.mopen
.delimcenter style="top: 0em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[4]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[5]{.mord .mtight}[[[[[[]{.pstrut
style="height: 3em;"}[[3]{.mord .mtight}]{.mord .mtight
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
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[4]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[21]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[[)]{.delimsizing
.size2}]{.mclose .delimcenter style="top: 0em;"}]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[ ]{.mspace}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.8em; vertical-align: -0.65em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[3]{.mord}]{.mord
style="padding-left: 0.833em;"}]{.svg-align
style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuMDhlbSIgcHJlc2VydmVhc3BlY3RyYXRpbz0ieE1pbllNaW4gc2xpY2UiIHZpZXdib3g9IjAgMCA0MDAwMDAgMTA4MCIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNOTUsNzAyCmMtMi43LDAsLTcuMTcsLTIuNywtMTMuNSwtOGMtNS44LC01LjMsLTkuNSwtMTAsLTkuNSwtMTQKYzAsLTIsMC4zLC0zLjMsMSwtNGMxLjMsLTIuNywyMy44MywtMjAuNyw2Ny41LC01NApjNDQuMiwtMzMuMyw2NS44LC01MC4zLDY2LjUsLTUxYzEuMywtMS4zLDMsLTIsNSwtMmM0LjcsMCw4LjcsMy4zLDEyLDEwCnMxNzMsMzc4LDE3MywzNzhjMC43LDAsMzUuMywtNzEsMTA0LC0yMTNjNjguNywtMTQyLDEzNy41LC0yODUsMjA2LjUsLTQyOQpjNjksLTE0NCwxMDQuNSwtMjE3LjcsMTA2LjUsLTIyMQpsMCAtMApjNS4zLC05LjMsMTIsLTE0LDIwLC0xNApINDAwMDAwdjQwSDg0NS4yNzI0CnMtMjI1LjI3Miw0NjcsLTIyNS4yNzIsNDY3cy0yMzUsNDg2LC0yMzUsNDg2Yy0yLjcsNC43LC05LDcsLTE5LDcKYy02LDAsLTEwLC0xLC0xMiwtM3MtMTk0LC00MjIsLTE5NCwtNDIycy02NSw0NywtNjUsNDd6Ck04MzQgODBoNDAwMDAwdjQwaC00MDAwMDB6Ij48L3BhdGg+PC9zdmc+)]{.hide-tail
style="min-width: 0.853em; height: 1.08em;"}]{style="top: -2.8672em;"}]{.vlist
style="height: 0.9072em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1328em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord
.sqrt}[)]{.mclose}[,]{.mpunct}[ ]{.mspace}[]{.mspace
style="margin-right: 0.1667em;"}[[[(]{.delimsizing .size2}]{.mopen
.delimcenter style="top: 0em;"}[[]{.mopen .nulldelimiter}[[[[[[]{.pstrut
style="height: 3em;"}[[[2]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[3]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[2]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[3]{.mord .mtight}[[[[[[]{.pstrut
style="height: 3em;"}[[3]{.mord .mtight}]{.mord .mtight
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
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[[)]{.delimsizing
.size2}]{.mclose .delimcenter style="top: 0em;"}]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[ ]{.mspace}[]{.mspace
style="margin-right: 0.1667em;"}[[[(]{.delimsizing .size1}]{.mopen
.delimcenter style="top: 0em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[2]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[3]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[[)]{.delimsizing
.size1}]{.mclose .delimcenter
style="top: 0em;"}]{.minner}]{.base}]{.katex-html
aria-hidden="true"}]

紊乱点为 [[$(3,4)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。此时旋转后图像与原本图像完全重合，图像如图所示：

![figure](https://files.seeusercontent.com/2026/08/08/u7sA/hint-D3.png)

