## F. 开关灯

### Problem Description

小 D 很喜欢随机性。

他面前有一排 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 盏灯，从左到右编号为
[[$1,2,\ldots,n$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]，第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
盏灯的权值为 [[$a_{i}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。一开始，所有灯都是关闭的。

小 D 随机选择一个 [[$1 \sim n$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∼]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的排列，并按照这个排列依次打开所有灯。

每打开一盏灯后，所有亮着的灯会形成若干个极大连续段。若当前共有
[[$c$][[[]{.strut style="height: 0.4306em;"}[c]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个连续段，并且这次打开的是第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 盏灯，那么小 D 会获得
[[$a_{i} \cdot c$][[[]{.strut
style="height: 0.5945em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[c]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 分。

小 D 想知道，最终总得分的期望是多少？答案对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[244]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模。

### Input

本题有多组测试数据。第一行输入一个正整数
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(1 \leq T \leq 2 \times 10^{5})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示测试数据组数。

接下来输入 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 组测试数据。每组测试数据包含两行：

第一行一个整数
[[$n(1 \leq n \leq 2 \times 10^{5})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

第二行 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个整数
[[$a_{1},a_{2},\ldots,a_{n}(0 \leq a_{i} < 998244353)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[a]{.mord
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
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[998]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[244]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[353]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

保证单个测试点内所有测试数据的 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 之和不超过
[[$2 \times 10^{6}$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

输出一个整数，表示小 D 最终总得分的期望值对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[244]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的结果。

可以证明答案是一个分母不被 [[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[244]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 整除的有理数。若答案最简表示为
[[$\frac{x}{y}$][[[]{.strut
style="height: 1.1765em; vertical-align: -0.4811em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[y]{.mord
.mathnormal .mtight style="margin-right: 0.0359em;"}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[x]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.6954em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.4811em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，你需要输出
[[$x \times y^{- 1}\operatorname{}998244353$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[x]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[−]{.mord .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[998]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[244]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，其中
[[$y^{- 1}$][[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[−]{.mord .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示 [[$y$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 在模
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[244]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 意义下的乘法逆元。

### Sample Input

```plain
2
1
10
3
1 2 3
```

### Sample Output

```plain
10
665496242
```

### Hint

本题输入量较大，建议使用较快速的输入方式（如关闭流同步的 `cin`）。

