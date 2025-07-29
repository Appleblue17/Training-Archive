## A. Entangled Coins

### 题目描述

<div>

Given [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] coins
with two sides (facing downwards or upwards),
[[$s$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[s]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] of them
are facing upwards while the remaining are the opposite.

<div>

\

<div>

You can operate coins **any number of times (including zero)**; in each
operation, you should arbitrarily choose **exactly**
[[$k$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}] coins to flip (facing up becomes facing
down and vice versa).

<div>

\

Your goal is to change the number of coins facing up (from
[[$s$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[s]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]) to
[[$t$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] . Output
the **minimum** number of operations or report that it's impossible.

</div>

</div>

</div>

</div>

### 输入描述

<div>

The first line contains the number of test cases
[[$t$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
([[$1 \leq t \leq 2 \times 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[t]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[2]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]). The description of the test cases
follows.

</div>

<div>

\

</div>

Each test case is represented by one line, containing four integers
[[$n,k,s,t$][[[]{.strut
style="height:0.8888799999999999em;vertical-align:-0.19444em;"}[n]{.mord
.mathdefault}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[s]{.mord
.mathdefault}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
([[$1 \leq k \leq n \leq 10^{9},0 \leq s,t \leq n$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.83041em;vertical-align:-0.13597em;"}[k]{.mord
.mathdefault style="margin-right:0.03148em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[n]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:1.008548em;vertical-align:-0.19444em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[0]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8304100000000001em;vertical-align:-0.19444em;"}[s]{.mord
.mathdefault}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[t]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]) meaning
as above.

### 输出描述

<div>

For each test case, answer it on a full line:

</div>

<div>

\

</div>

<div>

if there exists a solution, output an integer representing the minimum
number of operations;or if not, output
[[$- 1$][[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] as the report for impossible.

</div>

### 示例1

#### 输入

```plain
8
8 3 4 7
9 7 1 0
16 15 1 0
4 2 3 3
6 6 2 4
7 6 2 5
98257693 98257692 24 43850682
98257693 98257692 24 43850681
```

#### 输出

```plain
1
5
15
0
1
-1
43850658
-1
```

### 备注

\

