## I. Imperfect Permutation

### Problem Description

有一棵深度为 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的满二叉树（根节点深度为
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）。初始时，从左到右第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个叶子节点的标号为 [[$i - 1$][[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

你可以进行以下操作任意多次（可以不操作）：选择一个非叶子节点，交换它的左右子树。

所有操作结束后，从左到右读出叶子标号，得到长度为
[[$2^{n}$][[[]{.strut
style="height: 0.6644em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的序列 [[$a$][[[]{.strut
style="height: 0.4306em;"}[a]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。给定一个
[[$0,1,\ldots,2^{n} - 1$][[[]{.strut
style="height: 0.8588em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的排列 [[$p$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[p]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]，求
[[$a_{i} = p_{i}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的位置数量的最大值。

### Input

第一行包含一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 32$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[32]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示测试数据组数。

接下来依次输入每组测试数据。每组测试数据包含两行：
- 第一行包含一个整数 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq n \leq 18$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[18]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]）；
- 第二行包含 [[$2^{n}$][[[]{.strut
    style="height: 0.6644em;"}[[2]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 个整数
    [[$p_{0},p_{1},\ldots,p_{2^{n} - 1}$][[[]{.strut
    style="height: 0.6389em; vertical-align: -0.2083em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[0]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[2]{.mord
    .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[n]{.mord
    .mathnormal .mtight}]{.sizing .reset-size3 .size1
    .mtight}]{style="top: -2.786em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.5935em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
    .mtight}[−]{.mbin .mtight}[1]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2083em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

保证对于所有测试数据，[[$\sum 2^{n} \leq 2^{22}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[22]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，且 [[$p$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[p]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 是
[[$0,1,\ldots,2^{n} - 1$][[[]{.strut
style="height: 0.8588em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的排列。

### Output

对于每组测试数据，输出一行一个整数，表示最大重合位置数。

### Sample Input

```plain
3
3
0 1 2 3 7 6 5 4
3
5 7 4 3 1 0 6 2
4
9 11 13 7 5 14 8 4 6 0 12 15 1 3 10 2
```

### Sample Output

```plain
8
5
5
```

### Hint

对于第一组数据，可以与给定排列完全匹配，因此答案为
[[$8$][[[]{.strut
style="height: 0.6444em;"}[8]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

对于第二组数据，一种最优结果为
[[$\lbrack 6,7,4,5,1,0,3,2\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[6]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[7]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，共有 [[$5$][[[]{.strut
style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个位置匹配。

对于第三组数据，一种最优结果为
[[$\lbrack 10,11,8,9,15,14,13,12,6,7,5,4,1,0,3,2\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[10]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[11]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[8]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[9]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[15]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[14]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[13]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[12]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[6]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[7]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，共有 [[$5$][[[]{.strut
style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个位置匹配。

