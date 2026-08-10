## H. CuteSafari

### Problem Description

称 [[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的一次变换为把
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 分割成若干长度
[[$\geq k$][[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的子串，每个子串的开头末尾交换。

现在给你长度为 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的字符串 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]。问 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 可不可以通过若干次变换得到
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]，或者报告无解。

### Input

第一行包含一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示测试数据组数。

对于每组测试数据：
- 第一行包含两个整数 [[$n,k$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq k \leq n \leq 10^{7}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[7]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]）。
- 第二行包含一个字符串 [[$S$][[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 第三行包含一个字符串 [[$T$][[[]{.strut
    style="height: 0.6833em;"}[T]{.mord .mathnormal
    style="margin-right: 0.1389em;"}]{.base}]{.katex-html
    aria-hidden="true"}]。

保证对于所有测试数据，输入的字符串中只有小写英文字母，且
[[$1 \leq \sum n \leq 10^{7}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[7]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每组测试数据，输出一行一个字符串 `Yes` 或 `No` 表示答案。

### Sample Input

```plain
4
3 3
abc
cba
10 2
cutesafari
eutcasafir
3 1
aab
abb
10 3
safaricute
eutcasafir
```

### Sample Output

```plain
Yes
Yes
No
No
```

