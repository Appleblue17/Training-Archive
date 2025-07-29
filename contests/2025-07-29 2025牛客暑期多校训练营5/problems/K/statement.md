## K. Perfect Journey

### 题目描述

<div>

In a country with [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] cities,
there are [[$n - 1$][[[]{.strut
style="height:0.66666em;vertical-align:-0.08333em;"}[n]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] bidirectional roads connecting these
cities, forming a tree.You are now visiting this country, and there are
[[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] specific
roads that you definitely want to travel through.The travel agency
offers [[$k$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}] optional tour routes. Each route starts
from city [[$s_{i}$][[[]{.strut
style="height:0.58056em;vertical-align:-0.15em;"}[[s]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] and follows the shortest path to reach city
[[$t_{i}$][[[]{.strut
style="height:0.76508em;vertical-align:-0.15em;"}[[t]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

<div>

\

<div>

Your goal is to select as few routes as possible from these
[[$k$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}] tour routes, ensuring that all
[[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] key
roads are traveled at least once.

<div>

\

<div>

Please calculate the minimum number of tour routes you need to select,
and the number of possible ways to achieve this minimum, with the answer
modulo [[$998244353$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[9]{.mord}[9]{.mord}[8]{.mord}[2]{.mord}[4]{.mord}[4]{.mord}[3]{.mord}[5]{.mord}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]. A plan is defined as the set of tour
routes you choose. Two plans are considered different if and only if
there exists a tour route that is selected in one plan but not in the
other.

<div>

\

<div>

If it's impossible to travel through all the specific roads, output
[[$- 1$][[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

<div>

\

The problem guarantees that the answer is non-zero modulo
[[$998244353$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[9]{.mord}[9]{.mord}[8]{.mord}[2]{.mord}[4]{.mord}[4]{.mord}[3]{.mord}[5]{.mord}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

</div>

</div>

</div>

</div>

</div>

</div>

</div>

</div>

### 输入描述

<div>

The first line contains three integers
[[$2 \leq n \leq 2 \times 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[2]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[n]{.mord
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
aria-hidden="true"}],
[[$1 \leq m \leq 22$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[m]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[2]{.mord}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}],
[[$1 \leq k \leq 2 \times 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.83041em;vertical-align:-0.13597em;"}[k]{.mord
.mathdefault style="margin-right:0.03148em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[2]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}], representing the number of cities, the
number of specific roads, and the number of tour routes.

</div>

<div>

\

</div>

The next [[$n - 1$][[[]{.strut
style="height:0.66666em;vertical-align:-0.08333em;"}[n]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] lines each contain two integers
[[$1 \leq u_{i},v_{i} \leq n$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8304100000000001em;vertical-align:-0.19444em;"}[[u]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[v]{.mord .mathdefault
style="margin-right:0.03588em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03588em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
guaranteeing that the given graph is a tree.

<div>

\

</div>

<div>

The next line contains [[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] distinct
integers [[$1 \leq x_{i} \leq n - 1$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7859700000000001em;vertical-align:-0.15em;"}[[x]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.66666em;vertical-align:-0.08333em;"}[n]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] representing the indices of the specific
roads (according to the input order).

</div>

<div>

\

</div>

<div>

The next [[$k$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}] lines each contain two integers
[[$1 \leq s_{i},t_{i} \leq n$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8304100000000001em;vertical-align:-0.19444em;"}[[s]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[t]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
indicating that the tour route goes from
[[$s_{i}$][[[]{.strut
style="height:0.58056em;vertical-align:-0.15em;"}[[s]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] to [[$t_{i}$][[[]{.strut
style="height:0.76508em;vertical-align:-0.15em;"}[[t]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

</div>

### 输出描述

Output the minimum number of tour routes you need to select, and the
number of ways to achieve this minimum, with the answer modulo
[[$998244353$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[9]{.mord}[9]{.mord}[8]{.mord}[2]{.mord}[4]{.mord}[4]{.mord}[3]{.mord}[5]{.mord}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

<div>

\

</div>

<div>

If it's impossible to travel through all the specific roads, output
[[$- 1$][[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

</div>

### 示例1

#### 输入

```plain
3 2 2
1 2
1 3
1 2
2 3
1 2
```

#### 输出

```plain
1 1
```

### 示例2

#### 输入

```plain
7 3 3
1 2
1 3
2 4
2 5
3 6
6 7
1 3 5
1 4
2 7
2 4
```

#### 输出

```plain
2 2
```

#### 说明

<div>

<div>

we need to select at least 2 routes, and there are two possible plans:

</div>

<div>

\

</div>

<div>

<div>

Route 1 and Route 2，Route 1 covers road 1 and road 3, Route 2 covers
road 1 and road 5.

</div>

</div>

<div>

<div>

Route 2 and Route 3，Route 2 covers road 1 and road 5, Route 3 covers
road 3.

</div>

</div>

</div>

