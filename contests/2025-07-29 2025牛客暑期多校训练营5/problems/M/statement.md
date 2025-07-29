## M. Mysterious Spacetime

### 题目描述

<div>

**The input data for this problem is large, please use a faster input
method.**

<div>

**\
**

<div>

In a mysterious spacetime, there are [[$x$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[x]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] unknown
energies, numbered from [[$1$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] to [[$x$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[x]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]. These
energies appear at specific times and positions, following these rules:

<div>

\

1\. **Spacetime Appearance Rule**:

There are [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
different time points, numbered from [[$1$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] to [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}].

<div>

At time point [[$t$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}], all
energies in the interval
[[$\lbrack l,r\rbrack$][[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[\[]{.mopen}[l]{.mord
.mathdefault style="margin-right:0.01968em;"}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[r]{.mord .mathdefault
style="margin-right:0.02778em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] will appear and disappear at time point
[[$t + 1$][[[]{.strut
style="height:0.69841em;vertical-align:-0.08333em;"}[t]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

<div>

\

<div>

2\. **Generation Rule**:

There are [[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
generators, numbered from [[$1$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] to [[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]. Each
generator [[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] requires
all energies in the interval
[[$\lbrack L_{i},R_{i}\rbrack$][[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[\[]{.mopen}[[L]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[R]{.mord .mathdefault
style="margin-right:0.00773em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.00773em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}].

If at some integer time point [[$t$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}], at
least [[$k_{i}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[[k]{.mord .mathdefault
style="margin-right:0.03148em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03148em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] energies in the interval
[[$\lbrack L_{i},R_{i}\rbrack$][[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[\[]{.mopen}[[L]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[R]{.mord .mathdefault
style="margin-right:0.00773em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.00773em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] appear simultaneously, then generator
[[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] will be
activated at time point [[$t$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}].

<div>

Each generator is activated only once at the earliest moment when
requirements are met.

<div>

\

<div>

You need to process [[$q$][[[]{.strut
style="height:0.625em;vertical-align:-0.19444em;"}[q]{.mord .mathdefault
style="margin-right:0.03588em;"}]{.base}]{.katex-html
aria-hidden="true"}] queries. Each query gives `tl tr l r`,
asking:
- Within the time range
    [[$\lbrack\text{tl},\text{tr}\rbrack$][[[]{.strut
    style="height:1em;vertical-align:-0.25em;"}[\[]{.mopen}[[tl]{.mord}]{.mord
    .text}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[[tr]{.mord}]{.mord
    .text}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}], what is the earliest time point
    [[$t$][[[]{.strut
    style="height:0.61508em;vertical-align:0em;"}[t]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}] such
    that: there exists some generator [[$i$][[[]{.strut
    style="height:0.65952em;vertical-align:0em;"}[i]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
    satisfying
    [[$l \leq L_{i} \leq R_{i} \leq r$][[[]{.strut
    style="height:0.83041em;vertical-align:-0.13597em;"}[l]{.mord
    .mathdefault style="margin-right:0.01968em;"}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[L]{.mord
    .mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
    .mathdefault .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[R]{.mord
    .mathdefault style="margin-right:0.00773em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.00773em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[r]{.mord .mathdefault
    style="margin-right:0.02778em;"}]{.base}]{.katex-html
    aria-hidden="true"}] that is activated at time point
    [[$t$][[[]{.strut
    style="height:0.61508em;vertical-align:0em;"}[t]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}].
- If no such [[$t$][[[]{.strut
    style="height:0.61508em;vertical-align:0em;"}[t]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
    exists, output [[$- 1$][[[]{.strut
    style="height:0.72777em;vertical-align:-0.08333em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}].

</div>

</div>

</div>

</div>

</div>

</div>

</div>

</div>

</div>

</div>

### 输入描述

\

<div>

The first line contains a number
[[$1 \leq T \leq 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8193em;vertical-align:-0.13597em;"}[T]{.mord
.mathdefault style="margin-right:0.13889em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}], indicating there are
[[$T$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}]{.base}]{.katex-html
aria-hidden="true"}] test cases, each in the following format:

</div>

<div>

\

</div>
- <div>

    The first line contains four integers
    [[$1 \leq n,m,x,q \leq 5 \times 10^{5}$][[[]{.strut
    style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.8304100000000001em;vertical-align:-0.19444em;"}[n]{.mord
    .mathdefault}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[m]{.mord
    .mathdefault}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[x]{.mord
    .mathdefault}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[q]{.mord .mathdefault
    style="margin-right:0.03588em;"}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.72777em;vertical-align:-0.08333em;"}[5]{.mord}[]{.mspace
    style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
    style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
    style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3 .mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
    style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}].

    </div>

    <div>

    \

    </div>
- <div>

    The next [[$n$][[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[n]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
    lines, each containing three integers
    [[$1 \leq t \leq 10^{9}$][[[]{.strut
    style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[t]{.mord
    .mathdefault}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height:2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6
    .size3 .mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
    style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}],
    [[$1 \leq l \leq r \leq x$][[[]{.strut
    style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.83041em;vertical-align:-0.13597em;"}[l]{.mord
    .mathdefault style="margin-right:0.01968em;"}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[r]{.mord
    .mathdefault style="margin-right:0.02778em;"}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[x]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
    indicating that at time point [[$t$][[[]{.strut
    style="height:0.61508em;vertical-align:0em;"}[t]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}], all
    energies in interval
    [[$\lbrack l,r\rbrack$][[[]{.strut
    style="height:1em;vertical-align:-0.25em;"}[\[]{.mopen}[l]{.mord
    .mathdefault style="margin-right:0.01968em;"}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[r]{.mord .mathdefault
    style="margin-right:0.02778em;"}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] appear. (The problem guarantees all
    time points are different)

    </div>

    <div>

    \

    </div>
- <div>

    The next [[$m$][[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[m]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
    lines, each containing three integers
    [[$1 \leq L_{i} \leq R_{i} \leq x$][[[]{.strut
    style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[L]{.mord
    .mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
    .mathdefault .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[R]{.mord
    .mathdefault style="margin-right:0.00773em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.00773em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[x]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
    [[$1 \leq k_{i} \leq R_{i} - L_{i} + 1$][[[]{.strut
    style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.84444em;vertical-align:-0.15em;"}[[k]{.mord
    .mathdefault style="margin-right:0.03148em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03148em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[R]{.mord
    .mathdefault style="margin-right:0.00773em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.00773em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
    style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[L]{.mord
    .mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
    .mathdefault .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
    style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
    style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}], describing the requirements of
    generator [[$i$][[[]{.strut
    style="height:0.65952em;vertical-align:0em;"}[i]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}].

    </div>

    <div>

    \

    </div>
- <div>

    The next [[$q$][[[]{.strut
    style="height:0.625em;vertical-align:-0.19444em;"}[q]{.mord
    .mathdefault style="margin-right:0.03588em;"}]{.base}]{.katex-html
    aria-hidden="true"}] lines, each containing four integers
    [[$1 \leq tl \leq tr \leq 10^{9}$][[[]{.strut
    style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.83041em;vertical-align:-0.13597em;"}[t]{.mord
    .mathdefault}[l]{.mord .mathdefault
    style="margin-right:0.01968em;"}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[t]{.mord
    .mathdefault}[r]{.mord .mathdefault
    style="margin-right:0.02778em;"}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height:2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6
    .size3 .mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
    style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}],
    [[$1 \leq l \leq r \leq x$][[[]{.strut
    style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.83041em;vertical-align:-0.13597em;"}[l]{.mord
    .mathdefault style="margin-right:0.01968em;"}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[r]{.mord
    .mathdefault style="margin-right:0.02778em;"}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[x]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
    representing a query.

    </div>

<div>

\

</div>

<div>

The problem guarantees
[[$\sum n,\sum m,\sum q,\sum x \leq 5 \times 10^{5}$][[[]{.strut
style="height:1.00001em;vertical-align:-0.25001em;"}[∑]{.mop .op-symbol
.small-op
style="position:relative;top:-0.0000050000000000050004em;"}[]{.mspace
style="margin-right:0.16666666666666666em;"}[n]{.mord
.mathdefault}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[∑]{.mop .op-symbol
.small-op
style="position:relative;top:-0.0000050000000000050004em;"}[]{.mspace
style="margin-right:0.16666666666666666em;"}[m]{.mord
.mathdefault}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[∑]{.mop .op-symbol
.small-op
style="position:relative;top:-0.0000050000000000050004em;"}[]{.mspace
style="margin-right:0.16666666666666666em;"}[q]{.mord .mathdefault
style="margin-right:0.03588em;"}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[∑]{.mop .op-symbol
.small-op
style="position:relative;top:-0.0000050000000000050004em;"}[]{.mspace
style="margin-right:0.16666666666666666em;"}[x]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[5]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]

</div>

### 输出描述

For each query, output one integer per line, representing the answer.

### 示例1

#### 输入

```plain
1
6 6 4 4
1 2 3
5 1 3
3 1 1
6 1 3
2 4 4
4 4 4
1 3 2
1 3 1
1 2 2
1 3 1
1 2 1
4 4 1
1 4 1 2
2 4 1 3
1 4 1 3
3 5 4 4
```

#### 输出

```plain
1
-1
1
-1
```

### 备注

\

