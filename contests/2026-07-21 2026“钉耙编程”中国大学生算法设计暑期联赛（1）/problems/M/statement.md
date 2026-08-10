## M. 彩色匹配

### Problem Description

给定一个二分图 [[$G = (L,R,E)$][[[]{.strut
style="height: 0.6833em;"}[G]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[L]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[E]{.mord .mathnormal
style="margin-right: 0.0576em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，其左右两部各有
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个点，之间有 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 条边，每条边被染成蓝色或红色。

一个完美匹配是 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]
条两两没有公共端点的边，使得每个左部点和每个右部点都恰好被匹配一次。

请你找出一组完美匹配，使得其中恰好有 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 条红边。

### Input

本题有多组测试数据。

第一行输入一个整数 [[$T(1 \leq T \leq 60)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[60]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示测试数据组数。

接下来按如下格式输入 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 组数据：

第一行输入三个整数
[[$n,m,k(1 \leq n \leq 120,0 \leq m \leq n^{2},0 \leq k \leq n)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[120]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[[n]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[n]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示二分图左右两部各自的点数、图的总边数，以及完美匹配中要求的红边数。

随后 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行输入三个整数
[[$u,v,c(1 \leq u,v \leq n,c \in \{ 0,1\})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[u]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[c]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[u]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[c]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[})]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示左部点
[[$L_{u}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[L]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[u]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 与右部点
[[$R_{v}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[v]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 之间有一条边。
- [[$c = 0$][[[]{.strut
    style="height: 0.4306em;"}[c]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 表示蓝边；
- [[$c = 1$][[[]{.strut
    style="height: 0.4306em;"}[c]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 表示红边。

保证同一组数据中不会出现 [[$u,v$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[u]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 均相同的两条边，至多
[[$10$][[[]{.strut
style="height: 0.6444em;"}[10]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 组数据
[[$n > 50$][[[]{.strut
style="height: 0.5782em; vertical-align: -0.0391em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[50]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

本题使用 Special Judge 进行评测。

对于每组数据，输出一行。

如果不存在红边数恰好为 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的完美匹配，输出 `-1`。

否则，输出 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个用空格分隔的整数
[[$p_{1},p_{2},\ldots,p_{n}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，其中 [[$p_{i}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示左部点
[[$L_{i}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[L]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 与右部点
[[$R_{p_{i}}$][[[]{.strut
style="height: 0.9694em; vertical-align: -0.2861em;"}[[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[[p]{.mord .mathnormal .mtight}[[[[[[]{.pstrut
style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 匹配。

输出必须满足：
- [[$p_{i}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 均为 [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 到 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    之间的整数，且两两不同。
- 对于所有 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]，边
    [[$(L_{i},R_{p_{i}})$][[[]{.strut
    style="height: 1.0361em; vertical-align: -0.2861em;"}[(]{.mopen}[[L]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[R]{.mord .mathnormal
    style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[[p]{.mord .mathnormal
    .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 存在。
- 恰好有 [[$k$][[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 条被选中的边为红边。

### Sample Input

```plain
3
2 4 1
1 1 1
1 2 0
2 1 0
2 2 0
2 2 2
1 1 1
2 2 1
2 2 1
1 1 0
2 2 0
```

### Sample Output

```plain
1 2
1 2
-1
```

