## J. 今晚吃黑子

### Problem Description

白井黑子喜欢下棋。

她在桌上将 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]
枚棋子（黑子或白子）排成一列，从左到右依次编号为
[[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 到 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。

定义一次操作为：选择一个棋子 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，满足
[[$1 < i < n$][[[]{.strut
style="height: 0.6835em; vertical-align: -0.0391em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6986em; vertical-align: -0.0391em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 且 [[$i - 1$][[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$i + 1$][[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 处的棋子颜色不同。她会将
[[$i - 1$][[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$i + 1$][[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
处的棋子吃掉，然后移动棋子将空位填上，形成新的一列棋子，并重新从
[[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 开始编号。[[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 也被重新设定为现在棋子序列的长度。

白井黑子可以进行任意（可以为零）次这样的操作。现在，她想让你求出最后可能得到的棋子序列的个数。两个棋子序列不同，当且仅当它们长度不同，或者某个位置棋子的颜色不同。

由于答案可能很大，请输出其对 [[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[244]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的结果。

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 10^{4}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

接下来对于每一组测试数据：

输入的唯一一行包含一个 01 字符串 [[$A$][[[]{.strut
style="height: 0.6833em;"}[A]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq \mid A\mid \leq 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[A]{.mord
.mathnormal}[∣]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），代表初始的棋子颜色，其中**黑子是 0**。

保证所有测试数据输入的字符串 [[$A$][[[]{.strut
style="height: 0.6833em;"}[A]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的长度之和不超过
[[$10^{6}$][[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每一组测试数据，输出一行一个数，表示可以得到的不同棋子序列的数量对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[244]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模的值。

### Sample Input

```plain
2
1101
0100110
```

### Sample Output

```plain
2
7
```

### Hint

对于第一组测试数据，白井黑子可以选择棋子
[[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，并吃掉棋子
[[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 与 [[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，得到棋子序列 `11`，加上原序列本身，答案为
[[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

对于第二组测试数据，白井黑子首先选择棋子
[[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，序列变为 `00110`；再选择此时的棋子
[[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，序列变为
`010`。因此这两个序列都应该被统计到答案。

