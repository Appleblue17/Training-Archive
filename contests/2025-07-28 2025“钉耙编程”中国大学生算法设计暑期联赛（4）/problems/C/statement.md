## C. 维什戴尔

### Problem Description

*"何以为我？"*

给定一棵由编号为 [[$1,2,3,\cdots,n$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的点构成的树。记集合 [[$S = \{ 0,1\}$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。记整数
[[$w_{i}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
.mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$w_{i} \in S$][[[]{.strut
style="height: 0.6891em; vertical-align: -0.15em;"}[[w]{.mord
.mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]）表示编号为
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）的点的权值。

对于第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i < n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6986em; vertical-align: -0.0391em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）条树上的边双向连接编号为
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
aria-hidden="true"}] 的点：

1.  给定 [[$x_{i}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 满足若断开第
    [[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    条边，存在整数 [[$k$][[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$k \in S$][[[]{.strut
    style="height: 0.7335em; vertical-align: -0.0391em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}]）使得此时编号为
    [[$u_{i}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[u]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的点所在的连通块中恰有
    [[$x_{i}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 个点的权值是
    [[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  给定 [[$y_{i}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 满足若断开第
    [[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    条边，存在整数 [[$k$][[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$k \in S$][[[]{.strut
    style="height: 0.7335em; vertical-align: -0.0391em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}]）使得此时编号为
    [[$v_{i}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的点所在的连通块中恰有
    [[$y_{i}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 个点的权值是
    [[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]。

出于一些原因，你不知道每个点的权值。故你需要计算有多少个不同的权值序列
[[$w_{1},w_{2},w_{3},\cdots,w_{n}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[w]{.mord
.mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 满足以上所有条件，对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
取模。**可能不存在任何权值序列满足所有条件，此时答案为
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。**

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 3 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

对于每一组测试数据，输入包含 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行。

第一行包含一个整数 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$1 \leq \sum n \leq 3 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示树上点的数量。

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
aria-hidden="true"}]）行包含四个整数
[[$u_{i},v_{i},x_{i},y_{i}$][[[]{.strut
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
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[x]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
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
aria-hidden="true"}]，[[$0 \leq x_{i},y_{i} < n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
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
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），表示第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 条树上的边。

保证输入的点构成一棵树。

### Output

对于每一组测试数据，输出包含一行一个整数表示答案对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的值。

### Sample Input

```plain
2
4
1 2 2 1
1 3 2 1
1 4 2 1
4
1 2 1 2
2 3 1 1
3 4 2 1
```

### Sample Output

```plain
8
4
```

### Hint

在样例的第一组测试数据中，以下权值序列满足条件：

1.  [[$w_{1} = 0,w_{2} = 0,w_{3} = 1,w_{4} = 1$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  [[$w_{1} = 0,w_{2} = 1,w_{3} = 0,w_{4} = 1$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
3.  [[$w_{1} = 0,w_{2} = 1,w_{3} = 1,w_{4} = 0$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
4.  [[$w_{1} = 0,w_{2} = 1,w_{3} = 1,w_{4} = 1$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
5.  [[$w_{1} = 1,w_{2} = 0,w_{3} = 0,w_{4} = 0$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
6.  [[$w_{1} = 1,w_{2} = 0,w_{3} = 0,w_{4} = 1$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
7.  [[$w_{1} = 1,w_{2} = 0,w_{3} = 1,w_{4} = 0$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
8.  [[$w_{1} = 1,w_{2} = 1,w_{3} = 0,w_{4} = 0$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

