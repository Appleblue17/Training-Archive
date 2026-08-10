## K. K. Union MEX

### Problem Description

**题目描述**

给定一棵包含 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个点的树 [[$G$][[[]{.strut
style="height: 0.6833em;"}[G]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，第 [[$u$][[[]{.strut
style="height: 0.4306em;"}[u]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个点有点权
[[$a_{u} \in \{ 0,1\}$][[[]{.strut
style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[u]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

有 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 次询问。每次询问给出一个点
[[$r$][[[]{.strut style="height: 0.4306em;"}[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}]。

对于这次询问，考虑所有满足以下条件的点集
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]：
- [[$r \in S$][[[]{.strut
    style="height: 0.5782em; vertical-align: -0.0391em;"}[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
    .mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 连通。

记所有这些点集的点权和组成的集合为：

[[[$$V_{r} = \left\{ \sum\limits_{u \in S}a_{u} \middle| r \in S,\ S\text{~连通} \right\}.$$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[V]{.mord
.mathnormal style="margin-right: 0.2222em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[r]{.mord .mathnormal .mtight
style="margin-right: 0.0278em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.2222em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 3.0837em; vertical-align: -1.3217em;"}[[[{]{.delimsizing
.size4}]{.mopen .delimcenter style="top: 0em;"}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[u]{.mord .mathnormal .mtight}[∈]{.mrel
.mtight}[S]{.mord .mathnormal .mtight
style="margin-right: 0.0576em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -1.8557em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∑]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}]{.vlist
style="height: 1.05em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.3217em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[u]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[[[[[[]{.pstrut
style="height: 3.816em;"}[∣]{.delimsizinginner
.delim-size1}]{style="top: -2.566em;"}[[]{.pstrut
style="height: 3.816em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuODE2ZW0iIHByZXNlcnZlYXNwZWN0cmF0aW89InhNaW5ZTWluIiBzdHlsZT0id2lkdGg6MC4zMzMzZW0iIHZpZXdib3g9IjAgMCAzMzMuMzMwMDAwMDAwMDAwMDQgMTgxNiIgd2lkdGg9IjAuMzMzM2VtIj48cGF0aCBkPSJNMTQ1IDAgSDE4OCBWMTgxNiBIMTQ1eiBNMTQ1IDAgSDE4OCBWMTgxNiBIMTQ1eiI+PC9wYXRoPjwvc3ZnPg==)]{style="height: 1.816em; width: 0.3333em;"}]{style="top: -3.164em;"}[[]{.pstrut
style="height: 3.816em;"}[∣]{.delimsizinginner
.delim-size1}]{style="top: -4.972em;"}]{.vlist
style="height: 1.762em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.25em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.delimsizing
.mult}[]{.mspace style="margin-right: 0.2778em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[,]{.mpunct}[ ]{.mspace}[]{.mspace
style="margin-right: 0.1667em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[ ]{.mord}[连通]{.mord
.cjk_fallback}]{.mord .text}[[}]{.delimsizing .size4}]{.mclose
.delimcenter style="top: 0em;"}]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

求：

[[[$${mex}V_{r}.$$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[mex]{.mord
.mathrm}]{.mop}[]{.mspace style="margin-right: 0.1667em;"}[[V]{.mord
.mathnormal style="margin-right: 0.2222em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[r]{.mord .mathnormal .mtight
style="margin-right: 0.0278em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.2222em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

一个非负整数集合的 [[$mex$][[[]{.strut
style="height: 0.4306em;"}[[mex]{.mord
.mathrm}]{.mop}]{.base}]{.katex-html aria-hidden="true"}]
是没有出现在集合中的最小非负整数。例如，集合[[$\{ 0,1,3\}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 的 [[$mex$][[[]{.strut
style="height: 0.4306em;"}[[mex]{.mord
.mathrm}]{.mop}]{.base}]{.katex-html aria-hidden="true"}] 为
[[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

**数据范围**
- [[$1 \leq T \leq 3$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
    .mathnormal style="margin-right: 0.1389em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
- [[$1 \leq n,q \leq 10^{5}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
- [[$a_{u} \in \{ 0,1\}$][[[]{.strut
    style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[u]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}[}]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]
- [[$1 \leq r \leq n$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
- 输入图是一棵树

### Input

输入包含多组测试数据。第一行包含一个整数
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 3$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示测试数据组数。

对于每组测试数据：

第一行包含两个整数 [[$n,q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n,q \leq 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）。

第二行包含 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个整数
[[$a_{1},a_{2},\ldots,a_{n}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$a_{u} \in \{ 0,1\}$][[[]{.strut
style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[u]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]）。

接下来 [[$n - 1$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含两个整数
[[$u,v$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[u]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq u,v \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[u]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），表示树上的一条边。

接下来 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含一个整数
[[$r$][[[]{.strut style="height: 0.4306em;"}[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq r \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），表示一次询问。

保证给出的图是一棵树。

### Output

对于每次询问，输出一行一个整数，表示答案。

### Sample Input

```plain
1
5 5
1 0 1 0 0
1 2
1 3
3 4
3 5
1
2
3
4
5
```

### Sample Output

```plain
0
3
0
3
3
```

