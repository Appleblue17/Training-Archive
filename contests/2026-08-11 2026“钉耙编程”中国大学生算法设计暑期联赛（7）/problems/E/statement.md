## E. 今晚吃鸡扒

### Problem Description

农场主有 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个农场，编号为
[[$1 \sim n$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∼]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。

农场主一直苦于它的农场连通性不好，于是请你来重新设计农场之间的超空间通道。

你知道每一个农场都需要恰好向外连接 [[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
个超空间通道才能保持农场的稳定，而两个农场之间最多只能有一条超空间通道，一条超空间通道必须连接两个不同的农场。

农场主想让你对于 [[$k = 0 \sim K$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∼]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[K]{.mord .mathnormal
style="margin-right: 0.0715em;"}]{.base}]{.katex-html
aria-hidden="true"}]
求出，有多少种不同的设计农场之间超空间通道的方案，使得恰有
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 个无序三元组
[[$1 \leq x < y < z \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5782em; vertical-align: -0.0391em;"}[x]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[z]{.mord
.mathnormal style="margin-right: 0.044em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，满足编号为
[[$x,y,z$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[x]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[z]{.mord .mathnormal
style="margin-right: 0.044em;"}]{.base}]{.katex-html
aria-hidden="true"}]
的农场之间两两存在一条超空间通道。由于数量可能很多，你需要将答案对
[[$\operatorname{}$][[[]{.strut
style="height: 0.6944em;"}[]{.mspace
style="margin-right: 0.0556em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mord}[]{.mspace
style="margin-right: 0.0556em;"}]{.base}]{.katex-html
aria-hidden="true"}] 取模。

如果你能解决这个问题，农场主今晚会杀掉两只农场里的火鸡，请你吃它的拿手好菜：火鸡扒。

**形式化地**，对于 [[$k = 0 \sim K$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∼]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[K]{.mord .mathnormal
style="margin-right: 0.0715em;"}]{.base}]{.katex-html
aria-hidden="true"}]，求满足以下条件的
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个点的有标号简单无向图数量，对
[[$\operatorname{}$][[[]{.strut
style="height: 0.6944em;"}[]{.mspace
style="margin-right: 0.0556em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mord}[]{.mspace
style="margin-right: 0.0556em;"}]{.base}]{.katex-html
aria-hidden="true"}] 取模：
- 所有点的度数均为 [[$3$][[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 恰有 [[$k$][[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 个三元环。

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 30$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[30]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

接下来对于每一组测试数据：

输入的唯一一行包含三个整数
[[$n,K,\operatorname{}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[K]{.mord .mathnormal
style="margin-right: 0.0715em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mord}[]{.mspace
style="margin-right: 0.0556em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 10^{3}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$0 \leq K \leq \frac{n(n + 1)}{2}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[K]{.mord
.mathnormal style="margin-right: 0.0715em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.355em; vertical-align: -0.345em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[2]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[n]{.mord .mathnormal .mtight}[(]{.mopen
.mtight}[n]{.mord .mathnormal .mtight}[+]{.mbin .mtight}[1]{.mord
.mtight}[)]{.mclose .mtight}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -3.485em;"}]{.vlist
style="height: 1.01em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$2 \leq \operatorname{} \leq 10^{9} + 7$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mord}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8974em; vertical-align: -0.0833em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[7]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示农场主的农场数量，[[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的上限与模数。

保证所有测试数据的 [[$n^{2}$][[[]{.strut
style="height: 0.8141em;"}[[n]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 之和不超过
[[$3 \times 10^{6}$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每一组测试数据，输出包含一行 [[$K + 1$][[[]{.strut
style="height: 0.7667em; vertical-align: -0.0833em;"}[K]{.mord
.mathnormal style="margin-right: 0.0715em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个非负整数表示
[[$k = 0 \sim K$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∼]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[K]{.mord .mathnormal
style="margin-right: 0.0715em;"}]{.base}]{.katex-html
aria-hidden="true"}] 时的答案。

### Sample Input

```plain
2
4 4 998244353
10 3 1964
```

### Sample Output

```plain
0 0 0 0 1
1036 1348 296 1684
```

