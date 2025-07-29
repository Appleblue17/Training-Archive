## E. Mysterious XOR Operation

### 题目描述

<div>

We define a special mysterious XOR operation
[[$\oplus_{m}$][[[]{.strut
style="height:0.73333em;vertical-align:-0.15em;"}[[⊕]{.mbin}[[[[[[]{.pstrut
style="height:2.7em;"}[[[m]{.mord .mathdefault .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.151392em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] with the following rules:

<div>

\

<div>

For two numbers [[$a$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[a]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] and
[[$b$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[b]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}], first
compute their regular XOR result
[[$c = a \oplus b$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[c]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.66666em;vertical-align:-0.08333em;"}[a]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[⊕]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[b]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]. Then
process [[$c$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[c]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]'s binary
representation as follows:

<div>

\

Scan [[$c$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[c]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]'s binary
representation from the least significant bit to the most significant
bit

<div>

\

Initialize a counter [[$count = 0$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[c]{.mord
.mathdefault}[o]{.mord .mathdefault}[u]{.mord .mathdefault}[n]{.mord
.mathdefault}[t]{.mord .mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]

<div>

\

<div>

For each bit:

If the bit is 1:
- Increment [[$count$][[[]{.strut
    style="height:0.61508em;vertical-align:0em;"}[c]{.mord
    .mathdefault}[o]{.mord .mathdefault}[u]{.mord .mathdefault}[n]{.mord
    .mathdefault}[t]{.mord .mathdefault}]{.base}]{.katex-html
    aria-hidden="true"}] by 1
- If [[$count$][[[]{.strut
    style="height:0.61508em;vertical-align:0em;"}[c]{.mord
    .mathdefault}[o]{.mord .mathdefault}[u]{.mord .mathdefault}[n]{.mord
    .mathdefault}[t]{.mord .mathdefault}]{.base}]{.katex-html
    aria-hidden="true"}] is odd, keep the bit
- If [[$count$][[[]{.strut
    style="height:0.61508em;vertical-align:0em;"}[c]{.mord
    .mathdefault}[o]{.mord .mathdefault}[u]{.mord .mathdefault}[n]{.mord
    .mathdefault}[t]{.mord .mathdefault}]{.base}]{.katex-html
    aria-hidden="true"}] is even, clear the bit (set to 0)

<div>

If the bit is 0, leave it unchanged

<div>

\

<div>

Example:
[[$(101001)_{2} \oplus_{m}(10010)_{2} = (101001)_{2}$][[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[1]{.mord}[0]{.mord}[1]{.mord}[0]{.mord}[0]{.mord}[1]{.mord}[[)]{.mclose}[[[[[[]{.pstrut
style="height:2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mclose}[]{.mspace
style="margin-right:0.2222222222222222em;"}[[⊕]{.mbin}[[[[[[]{.pstrut
style="height:2.7em;"}[[[m]{.mord .mathdefault .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.151392em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[1]{.mord}[0]{.mord}[0]{.mord}[1]{.mord}[0]{.mord}[[)]{.mclose}[[[[[[]{.pstrut
style="height:2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mclose}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[1]{.mord}[0]{.mord}[1]{.mord}[0]{.mord}[0]{.mord}[1]{.mord}[[)]{.mclose}[[[[[[]{.pstrut
style="height:2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]

<div>

\

Given an array [[$A$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[A]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] of
length [[$N$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[N]{.mord .mathdefault
style="margin-right:0.10903em;"}]{.base}]{.katex-html
aria-hidden="true"}], compute the sum of the mysterious XOR of
[[$A_{i}$][[[]{.strut
style="height:0.83333em;vertical-align:-0.15em;"}[[A]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] and [[$A_{j}$][[[]{.strut
style="height:0.969438em;vertical-align:-0.286108em;"}[[A]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[j]{.mord
.mathdefault .mtight style="margin-right:0.05724em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.311664em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.286108em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] for all unordered pairs
[[$(i,j)$][[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[i]{.mord
.mathdefault}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[j]{.mord .mathdefault
style="margin-right:0.05724em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] where
[[$i\neq j$][[[]{.strut
style="height:0.8888799999999999em;vertical-align:-0.19444em;"}[i]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[[[[[[[[]{.pstrut
style="height:3em;"}[[]{.strut
style="height:0.8888799999999999em;vertical-align:-0.19444em;"}[[]{.mrel}]{.inner}[]{.fix}]{.rlap}]{style="top:-3em;"}]{.vlist
style="height:0.69444em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.19444em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mord}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.85396em;vertical-align:-0.19444em;"}[j]{.mord
.mathdefault style="margin-right:0.05724em;"}]{.base}]{.katex-html
aria-hidden="true"}].Formally, this can be expressed
as [[$\sum_{i}^{N}\sum_{j > i}^{N}$][[[]{.strut
style="height:1.417049em;vertical-align:-0.43581800000000004em;"}[[∑]{.mop
.op-symbol .small-op
style="position:relative;top:-0.0000050000000000050004em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.40029em;margin-left:0em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[N]{.mord .mathdefault .mtight
style="margin-right:0.10903em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.2029em;margin-right:0.05em;"}]{.vlist
style="height:0.981231em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.29971000000000003em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[∑]{.mop .op-symbol
.small-op
style="position:relative;top:-0.0000050000000000050004em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[[j]{.mord .mathdefault .mtight
style="margin-right:0.05724em;"}[\>]{.mrel .mtight}[i]{.mord
.mathdefault .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.40029em;margin-left:0em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[N]{.mord .mathdefault .mtight
style="margin-right:0.10903em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.2029em;margin-right:0.05em;"}]{.vlist
style="height:0.981231em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.43581800000000004em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}]{.base}]{.katex-html
aria-hidden="true"}][[$A_{i} \oplus_{m}A_{j}$][[[]{.strut
style="height:0.83333em;vertical-align:-0.15em;"}[[A]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[[⊕]{.mbin}[[[[[[]{.pstrut
style="height:2.7em;"}[[m]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.151392em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.969438em;vertical-align:-0.286108em;"}[[A]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[j]{.mord
.mathdefault .mtight style="margin-right:0.05724em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.311664em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.286108em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
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

</div>

### 输入描述

<div>

The first line contains an integer [[$N$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[N]{.mord .mathdefault
style="margin-right:0.10903em;"}]{.base}]{.katex-html
aria-hidden="true"}]
([[$2 \leq N \leq 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[2]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8193em;vertical-align:-0.13597em;"}[N]{.mord
.mathdefault style="margin-right:0.10903em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]).

</div>

<div>

\

</div>

The second line contains [[$N$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[N]{.mord .mathdefault
style="margin-right:0.10903em;"}]{.base}]{.katex-html
aria-hidden="true"}] integers
[[$A_{i}$][[[]{.strut
style="height:0.83333em;vertical-align:-0.15em;"}[[A]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
([[$0 \leq A_{i} \leq 10^{8}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[0]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.83333em;vertical-align:-0.15em;"}[[A]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[8]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]).

### 输出描述

Output a single integer representing the sum of mysterious XOR results
for all unordered pairs.

### 示例1

#### 输入

```plain
3
5 3 9
```

#### 输出

```plain
8
```

#### 说明

[[$5 \oplus_{m}3 = 2$][[[]{.strut
style="height:0.79444em;vertical-align:-0.15em;"}[5]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[[⊕]{.mbin}[[[[[[]{.pstrut
style="height:2.7em;"}[[[m]{.mord .mathdefault .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.151392em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[3]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]\
\
[[$5 \oplus_{m}9 = 4$][[[]{.strut
style="height:0.79444em;vertical-align:-0.15em;"}[5]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[[⊕]{.mbin}[[[[[[]{.pstrut
style="height:2.7em;"}[[[m]{.mord .mathdefault .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.151392em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[9]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[4]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]\
\
[[$3 \oplus_{m}9 = 2$][[[]{.strut
style="height:0.79444em;vertical-align:-0.15em;"}[3]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[[⊕]{.mbin}[[[[[[]{.pstrut
style="height:2.7em;"}[[[m]{.mord .mathdefault .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.151392em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[9]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]\
\
So the answer equals [[$4 + 2 + 2 = 8$][[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[4]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[2]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[2]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[8]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]

