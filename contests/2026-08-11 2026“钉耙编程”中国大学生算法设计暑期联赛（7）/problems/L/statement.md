## L. 今晚吃 TopTree

### Problem Description

**题目背景和题意无关，可以跳过。**

Rake 和 Compress 是两种重要的合并操作。考虑将一棵树每次将两条边进行 R/C
让树越来越小的过程，并根据此过程建立重构树，称这棵树为 Top Tree。

现在在 Top Tree 上取出所有极大的不超过 [[$B$][[[]{.strut
style="height: 0.6833em;"}[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的簇，就构成了一个合法 的 Top Cluster
分解。只不过这样的簇个数没有保证。

考虑按照全局平衡二叉树的方式构建。先将其改为二叉树：每个点向轻儿子连的边也按照子树大小带权平衡一下，然后每个点直接合并两个儿子簇即可。

Top Tree
能维护的范围是能用簇信息表出的范围。实际上，大多数树上范围都能如此表出。可以说
Top Tree 在几乎所有情况下都是最优分治结构。

但是全局平衡二叉树在结构上并不是最优的，在常数优化场景中，需要保证合并簇的总次数尽可能小。此时可以将它形式化为如下问题：

**题目描述**：给定一棵以顶点 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 为根、包含 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]
个顶点的有根树。输入中的顶点称为**原始顶点**。根的深度为
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，其他顶点的深度为其到根的边数；树的高度为所有顶点深度的最大值。

你可以任意次执行以下操作：
- 选择当前树中的一个顶点 [[$u$][[[]{.strut
    style="height: 0.4306em;"}[u]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    及其两个不同的儿子 [[$v,w$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 新建一个顶点 [[$r$][[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，令 [[$r$][[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 成为 [[$u$][[[]{.strut
    style="height: 0.4306em;"}[u]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的儿子，并令 [[$v,w$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 改为 [[$r$][[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 的儿子。顶点
    [[$v,w$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 原有的子树均保持不变。

你需要通过上述操作，使最终树中的每个顶点至多有两个儿子。

分别求出以下两个量的最小值：
- 最终树的高度；
- 所有 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个原始顶点在最终树中的深度之和。新建顶点的深度不计入这个和。

两个最小值互相独立，可以由两种不同的操作方案取得。

定义路径长度为边数，则深度为某顶点到根的路径长度，而高度为深度最大的顶点深度。

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 10^{6}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

接下来对于每一组测试数据：

第一行包含一个整数 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 10^{6}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示原始顶点数。

接下来，如果 [[$n \geq 2$][[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，那么在第二行输入
[[$n - 1$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个整数
[[$p_{2},p_{3},\cdots,p_{n}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq p_{i} < i$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），其中
[[$p_{i}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示顶点 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的父亲。

数据保证所有测试数据的 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 之和不超过
[[$10^{6}$][[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每一组数据，输出包含一行两个整数，依次表示最终树的最小高度和原始顶点的最小深度和。

### Sample Input

```plain
3
1
4
1 1 1
13
1 2 2 3 3 4 4 1 9 10 11 1
```

### Sample Output

```plain
0 0
2 5
4 33
```

### Hint

在第二组数据中，根有三个儿子。将其中两个儿子放到同一个新建顶点下，可以得到高度
[[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]；三个原始儿子的深度分别为
[[$1,2,2$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，深度和为 [[$5$][[[]{.strut
style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

题目背景由白井黑子撰写。

