## D. Prime XOR Permutation

### 题目描述

Given an integer [[$N$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[N]{.mord .mathdefault
style="margin-right:0.10903em;"}]{.base}]{.katex-html
aria-hidden="true"}], you need to construct a permutation
[[$P$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[P]{.mord .mathdefault
style="margin-right:0.13889em;"}]{.base}]{.katex-html
aria-hidden="true"}] of integers from
[[$0$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] to [[$N - 1$][[[]{.strut
style="height:0.76666em;vertical-align:-0.08333em;"}[N]{.mord
.mathdefault style="margin-right:0.10903em;"}[]{.mspace
style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] such that for all
[[$1 \leq i < N$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.69862em;vertical-align:-0.0391em;"}[i]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[\<]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[N]{.mord .mathdefault
style="margin-right:0.10903em;"}]{.base}]{.katex-html
aria-hidden="true"}],
[[$P_{i} \oplus P_{i + 1}$][[[]{.strut
style="height:0.83333em;vertical-align:-0.15em;"}[[P]{.mord .mathdefault
style="margin-right:0.13889em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[⊕]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.891661em;vertical-align:-0.208331em;"}[[P]{.mord
.mathdefault style="margin-right:0.13889em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[[i]{.mord .mathdefault .mtight}[+]{.mbin
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
style="height:0.311664em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.208331em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] is a prime number. Here,
[[$\oplus$][[[]{.strut
style="height:0.66666em;vertical-align:-0.08333em;"}[⊕]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] denotes the bitwise XOR operation.

### 输入描述

<div>

The first line contains an integer [[$T$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}]{.base}]{.katex-html
aria-hidden="true"}]
([[$1 \leq T \leq 2 \times 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8193em;vertical-align:-0.13597em;"}[T]{.mord
.mathdefault style="margin-right:0.13889em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[2]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]), the number of test cases.

</div>

<div>

\

</div>

For each test case, there is a single integer
[[$N$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[N]{.mord .mathdefault
style="margin-right:0.10903em;"}]{.base}]{.katex-html
aria-hidden="true"}]
([[$1 \leq N \leq 10^{6}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8193em;vertical-align:-0.13597em;"}[N]{.mord
.mathdefault style="margin-right:0.10903em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]).

<div>

\

</div>

<div>

It is guaranteed that the sum of [[$N$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[N]{.mord .mathdefault
style="margin-right:0.10903em;"}]{.base}]{.katex-html
aria-hidden="true"}] across all test cases does not exceed
[[$10^{6}$][[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

</div>

### 输出描述

<div>

For each test case:

</div>

<div>

\

</div>
- <div>

    If a valid permutation exists, output a single line containing
    [[$N$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[N]{.mord .mathdefault
    style="margin-right:0.10903em;"}]{.base}]{.katex-html
    aria-hidden="true"}] space-separated integers representing
    the permutation [[$P$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[P]{.mord .mathdefault
    style="margin-right:0.13889em;"}]{.base}]{.katex-html
    aria-hidden="true"}].

    </div>
- If no such permutation exists, output
    [[$- 1$][[[]{.strut
    style="height:0.72777em;vertical-align:-0.08333em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}].

### 示例1

#### 输入

```plain
2
4
5
```

#### 输出

```plain
3 1 2 0
4 1 3 0 2
```

