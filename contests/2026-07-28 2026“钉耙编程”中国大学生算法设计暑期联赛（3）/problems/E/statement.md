## E. GCD

### Problem Description

小 H 和小 M 玩游戏。

在游戏开始，小 H 会有一个整数 [[$x$][[[]{.strut
style="height: 0.4306em;"}[x]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，小 M 每次操作会找到两个正整数
[[$a,b$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[a]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]（满足
[[$a \times b = x$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[a]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6944em;"}[b]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[x]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 且
[[$\max\{ a,b\} > 1$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[max]{.mop}[{]{.mopen}[a]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord
.mathnormal}[}]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），之后再把
[[$a,b$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[a]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 的 gcd
还给小 H。

小 M 笨笨的，她想知道这个游戏最多会进行几轮

### Input

第一行输入一个整数
[[$T\text{（}T \leq 200\text{）}$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[（]{.mord
.cjk_fallback}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[200]{.mord}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html aria-hidden="true"}]
表示数据组数。

接下来 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行一个整数
[[$x\text{（}1 \leq x \leq 10^{18}\text{）}$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[x]{.mord
.mathnormal}[（]{.mord .cjk_fallback}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[x]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[18]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]，表示最开始小
[[$H$][[[]{.strut style="height: 0.6833em;"}[H]{.mord
.mathnormal style="margin-right: 0.0813em;"}]{.base}]{.katex-html
aria-hidden="true"}] 手里的整数

### Output

[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行一个整数，表示这组数据对应的答案。

### Sample Input

```plain
3
4
5
9
```

### Sample Output

```plain
2
1
2
```

