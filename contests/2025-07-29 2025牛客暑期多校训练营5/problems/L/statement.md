## L. Float

### 题目描述

<div>

There are [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] levels,
the [[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th level
allows one traveling from point [[$i - 1$][[[]{.strut
style="height:0.74285em;vertical-align:-0.08333em;"}[i]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] to point [[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] ; you
start at point [[$0$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] , and want to pass through each level
sequentially to reach point [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]. Each
time you attempt a level, you have a probability
[[$p$][[[]{.strut
style="height:0.625em;vertical-align:-0.19444em;"}[p]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] of
passing and a probability [[$(1 - p)$][[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[p]{.mord
.mathdefault}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] of failing.

<div>

\

<div>

Initially you have some number of coins, if you fail and have at least
one coin, you will stay at the current level and retry by consuming one
coin (you won't leave it unused even if you are at point
[[$0$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]); and if you fail and have no coins left,
you will be kicked back to the starting point (point
[[$0$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]) .

<div>

\

Given [[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
calculate the expected number of steps to reach the endpoint for every
possible initial number of coins from [[$0$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] to [[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}], modulo
[[$998244353$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[9]{.mord}[9]{.mord}[8]{.mord}[2]{.mord}[4]{.mord}[4]{.mord}[3]{.mord}[5]{.mord}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

</div>

</div>

</div>

</div>

### 输入描述

The first line contains three integers [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
[[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}], and
[[$p$][[[]{.strut
style="height:0.625em;vertical-align:-0.19444em;"}[p]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
([[$1 \leq n \leq 10^{9}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[n]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$1 \leq m \leq 2 \times 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[m]{.mord
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
aria-hidden="true"}]，[[$0 < p < 998244353$][[[]{.strut
style="height:0.68354em;vertical-align:-0.0391em;"}[0]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[\<]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7335400000000001em;vertical-align:-0.19444em;"}[p]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[\<]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[9]{.mord}[9]{.mord}[8]{.mord}[2]{.mord}[4]{.mord}[4]{.mord}[3]{.mord}[5]{.mord}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]), representing the number of levels, the
maximum number of coins, and the probability of passing a level.

### 输出描述

A single line containing [[$m + 1$][[[]{.strut
style="height:0.66666em;vertical-align:-0.08333em;"}[m]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] integers, where the
[[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th
number represents the expected number of steps to reach the endpoint
when starting with [[$i - 1$][[[]{.strut
style="height:0.74285em;vertical-align:-0.08333em;"}[i]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] coins.

### 示例1

#### 输入

```plain
2 2 499122177
```

#### 输出

```plain
6 499122182 5
```

#### 说明

\

### 示例2

#### 输入

```plain
1 3 332748118
```

#### 输出

```plain
3 3 3 3
```

#### 说明

Under modulo [[$998244353$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[9]{.mord}[9]{.mord}[8]{.mord}[2]{.mord}[4]{.mord}[4]{.mord}[3]{.mord}[5]{.mord}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}], the value
[[$332748118$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[3]{.mord}[3]{.mord}[2]{.mord}[7]{.mord}[4]{.mord}[8]{.mord}[1]{.mord}[1]{.mord}[8]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] corresponds to a probability of
[[$\frac{1}{3}$][[[]{.strut
style="height:1.190108em;vertical-align:-0.345em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height:3em;"}[[[3]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.6550000000000002em;"}[[]{.pstrut
style="height:3em;"}[]{.frac-line
style="border-bottom-width:0.04em;"}]{style="top:-3.23em;"}[[]{.pstrut
style="height:3em;"}[[[1]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top:-3.394em;"}]{.vlist
style="height:0.845108em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

In this scenario, the result is independent of
[[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}], because
regardless of whether coins are available or not, failure always results
in returning to the starting point.

