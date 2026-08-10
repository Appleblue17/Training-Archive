## D. D. EERT

### Problem Description

给定一棵包含 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个原始结点的无根树。结点
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
有一个整数权值 [[$a_{i}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

你可以执行任意次以下两种操作：

1.  选择一个满足 [[$a_{i} > 1$][[[]{.strut
    style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的原始结点
    [[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]，支付
    [[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的代价，新建 [[$a_{i} - 1$][[[]{.strut
    style="height: 0.7333em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 个权值为
    [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的结点，并将它们分别作为叶子连接到
    [[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]，随后令
    [[$a_{i} = 1$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
2.  选择两个相邻的原始结点 [[$i,j$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[i]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[j]{.mord .mathnormal
    style="margin-right: 0.0572em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，再选择一个满足
    [[$1 \leq t \leq a_{i} - 1$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[t]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7333em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的整数 [[$t$][[[]{.strut
    style="height: 0.6151em;"}[t]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]。支付
    [[$y$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 的代价，并令

[[[$$\left. a_{i}\leftarrow a_{i} - t,\qquad a_{j}\leftarrow a_{j} + t. \right.$$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[←]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7333em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.9012em; vertical-align: -0.2861em;"}[t]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace style="margin-right: 2em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[←]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8694em; vertical-align: -0.2861em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[j]{.mord
.mathnormal .mtight style="margin-right: 0.0572em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6151em;"}[t]{.mord
.mathnormal}[.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

**新建的叶子不能参与第二种操作。**

树的直径定义为树上两点之间路径所含边数的最大值。求使最终树的直径至少为
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 所需的最小总代价。如果无法做到，输出
[[$- 1$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

**样例解释**

第一组数据中原树直径已经为 [[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，不需要执行操作。

第二组数据中，可以花费 [[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 将结点 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的一个单位权值运输到任意叶子，再花费
[[$7$][[[]{.strut
style="height: 0.6444em;"}[7]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 挂出新叶子，总代价为
[[$10$][[[]{.strut
style="height: 0.6444em;"}[10]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

第三组数据中，将结点 [[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的两个单位分别运输到结点
[[$1,5$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，需要使用四条原树边。随后在两个端点各挂一次叶子，总代价为

[[[$$4 \times 2 + 2 \times 5 = 18.$$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[18.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

第五组数据只有一个原始结点。一次操作可以同时挂出两个叶子，因此答案为
[[$11$][[[]{.strut
style="height: 0.6444em;"}[11]{.mord}]{.base}]{.katex-html
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
- [[$1 \leq n \leq 2 \times 10^{5}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
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
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$1 \leq k \leq 10^{9}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$1 \leq a_{i} \leq 10^{9}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.786em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$0 \leq x,y \leq 10^{9}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.1944em;"}[x]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 输入的边构成一棵树。
- 所有测试数据的 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    之和不超过 [[$4 \times 10^{5}$][[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[4]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

### Input

输入包含多组测试数据。第一行包含一个整数
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]，表示测试数据组数。

对于每组测试数据：
- 第一行包含四个整数 [[$n,k,x,y$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[x]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 第二行包含 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个整数 [[$a_{1},a_{2},\ldots,a_{n}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[n]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 接下来 [[$n - 1$][[[]{.strut
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
    aria-hidden="true"}]，表示原树中的一条边。

### Output

对于每组测试数据，输出一行一个整数，表示最小总代价；如果无解，输出
[[$- 1$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Sample Input

```plain
5
4 3 10 2
1 1 1 1
1 2
2 3
3 4
5 3 7 3
2 1 1 1 1
1 2
1 3
1 4
1 5
5 6 5 2
1 1 3 1 1
1 2
2 3
3 4
4 5
3 4 5 7
1 2 1
1 2
2 3
1 2 11 100
3
```

### Sample Output

```plain
0
10
18
-1
11
```

