## G. G. Perfect Palindrome

### Problem Description

给定一个长度为 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的小写字母字符串
[[$A$][[[]{.strut style="height: 0.6833em;"}[A]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，以及一个非负整数
[[$d$][[[]{.strut style="height: 0.6944em;"}[d]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]。

定义 [[$f(A,x)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[(]{.mopen}[A]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[x]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 表示将字符串
[[$A$][[[]{.strut style="height: 0.6833em;"}[A]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 循环左移
[[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
位后得到的字符串。例如，若
[[$A = \texttt{"abcde"}$][[[]{.strut
style="height: 0.6833em;"}[A]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6111em;"}[[\"abcde\"]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html
aria-hidden="true"}]，[[$f(A,2) = \texttt{"cdeab"}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[(]{.mopen}[A]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6111em;"}[[\"cdeab\"]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]。

如果对于所有非负整数 [[$k \geq 0$][[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，字符串
[[$f(A,kd)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[(]{.mopen}[A]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[d]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 都是回文串，则称
[[$A$][[[]{.strut style="height: 0.6833em;"}[A]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 是一个
**[[$d$][[[]{.strut style="height: 0.6944em;"}[d]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]-完美回文串**。

回文串是指正着读和反着读都一样的字符串。

现在你可以进行若干次操作，每次操作将 [[$A$][[[]{.strut
style="height: 0.6833em;"}[A]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]
中的一个字符修改为任意一个小写英文字母。求将
[[$A$][[[]{.strut style="height: 0.6833em;"}[A]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 变为
[[$d$][[[]{.strut style="height: 0.6944em;"}[d]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]-完美回文串所需的最少操作次数。

**样例解释**

对于样例字符串
`abcaabda`，要满足题意，需要让所有会互相对应的位置字符一致。

其中一组对应位置上的字符已经都是
`a`，不需要修改；另一组对应位置上的字符是 `b, c, b, d`，可以保留两个
`b`，把 `c` 和 `d` 改成 `b`。

这样总共修改 2 次，得到例如 `abbaabba` 的合法字符串，因此答案是 `2`。

**数据范围**
- [[$1 \leq T \leq 10$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
    .mathnormal style="margin-right: 0.1389em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[10]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
- [[$1 \leq n \leq 10^{5}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
- [[$0 \leq d < n$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7335em; vertical-align: -0.0391em;"}[d]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
- 字符串 [[$A$][[[]{.strut
    style="height: 0.6833em;"}[A]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    仅包含小写字母。
- 所有测试数据的 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    之和不超过 [[$2 \times 10^{5}$][[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
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
aria-hidden="true"}]（[[$1 \leq T \leq 10$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[10]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示测试数据组数。

对于每组测试数据： 第一行包含两个整数 [[$n,d$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[d]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 10^{5},0 \leq d < n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7335em; vertical-align: -0.0391em;"}[d]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）。 第二行包含一个长度为
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的小写字母字符串 [[$A$][[[]{.strut
style="height: 0.6833em;"}[A]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每组数据，输出一个整数，表示最少修改次数。

### Sample Input

```plain
1
8 2
abcaabda
```

### Sample Output

```plain
2
```

