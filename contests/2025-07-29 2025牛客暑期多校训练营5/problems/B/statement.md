## B. Extra Training

### 题目描述

<div>

Pigeon aspires to become a string master. Every day he trains extra-hard
on string problems.

<div>

\

<div>

Today he is solving a problem that goes like this:

<div>

\

<div>

Given a string [[$S$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[S]{.mord .mathdefault
style="margin-right:0.05764em;"}]{.base}]{.katex-html
aria-hidden="true"}] of length [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]. You
need to perform the following operation exactly
[[$k$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}] times:

<div>

\

1.  For the i-th operation
    [[$(1 \leq i \leq k)$][[[]{.strut
    style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.79549em;vertical-align:-0.13597em;"}[i]{.mord
    .mathdefault}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:1em;vertical-align:-0.25em;"}[k]{.mord .mathdefault
    style="margin-right:0.03148em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，Choose a substring of
    [[$S$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[S]{.mord .mathdefault
    style="margin-right:0.05764em;"}]{.base}]{.katex-html
    aria-hidden="true"}] as [[$S_{i}$][[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[S]{.mord
    .mathdefault style="margin-right:0.05764em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.05764em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}].[[$S\lbrack l_{i},r_{i}\rbrack$][[[]{.strut
    style="height:1em;vertical-align:-0.25em;"}[S]{.mord .mathdefault
    style="margin-right:0.05764em;"}[\[]{.mopen}[[l]{.mord .mathdefault
    style="margin-right:0.01968em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.01968em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[[r]{.mord .mathdefault
    style="margin-right:0.02778em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.02778em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] is substring of
    [[$S$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[S]{.mord .mathdefault
    style="margin-right:0.05764em;"}]{.base}]{.katex-html
    aria-hidden="true"}]. (i.e., the contiguous substring of
    [[$S$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[S]{.mord .mathdefault
    style="margin-right:0.05764em;"}]{.base}]{.katex-html
    aria-hidden="true"}] starting at position
    [[$l_{i}$][[[]{.strut
    style="height:0.84444em;vertical-align:-0.15em;"}[[l]{.mord
    .mathdefault style="margin-right:0.01968em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.01968em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] and ending at position
    [[$r_{i}$][[[]{.strut
    style="height:0.58056em;vertical-align:-0.15em;"}[[r]{.mord
    .mathdefault style="margin-right:0.02778em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.02778em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] , where
    [[$1 \leq l_{i} \leq r_{i} \leq n$][[[]{.strut
    style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.84444em;vertical-align:-0.15em;"}[[l]{.mord
    .mathdefault style="margin-right:0.01968em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.01968em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.7859700000000001em;vertical-align:-0.15em;"}[[r]{.mord
    .mathdefault style="margin-right:0.02778em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.02778em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[n]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]). In
    additonal, the empty string is also a substring of
    [[$S$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[S]{.mord .mathdefault
    style="margin-right:0.05764em;"}]{.base}]{.katex-html
    aria-hidden="true"}].
2.  Concatenate the chosen substrings
    [[$S_{i}(1 \leq i \leq k)$][[[]{.strut
    style="height:1em;vertical-align:-0.25em;"}[[S]{.mord .mathdefault
    style="margin-right:0.05764em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.05764em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[(]{.mopen}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.79549em;vertical-align:-0.13597em;"}[i]{.mord
    .mathdefault}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:1em;vertical-align:-0.25em;"}[k]{.mord .mathdefault
    style="margin-right:0.03148em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] in order to form a new string
    [[$S_{1} + S_{2} + ... + S_{k}$][[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[S]{.mord
    .mathdefault style="margin-right:0.05764em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.05764em;margin-right:0.05em;"}]{.vlist
    style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
    style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[S]{.mord
    .mathdefault style="margin-right:0.05764em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.05764em;margin-right:0.05em;"}]{.vlist
    style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
    style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
    style="height:0.66666em;vertical-align:-0.08333em;"}[.]{.mord}[.]{.mord}[.]{.mord}[]{.mspace
    style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
    style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[S]{.mord
    .mathdefault style="margin-right:0.05764em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[k]{.mord .mathdefault .mtight
    style="margin-right:0.03148em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.05764em;margin-right:0.05em;"}]{.vlist
    style="height:0.33610799999999996em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}].

<div>

\

Let [[$X$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[X]{.mord .mathdefault
style="margin-right:0.07847em;"}]{.base}]{.katex-html
aria-hidden="true"}] be the number of distinct strings that can
be formed by concatenating [[$k$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}] substrings in this way.
Output [[$X$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[X]{.mord .mathdefault
style="margin-right:0.07847em;"}]{.base}]{.katex-html
aria-hidden="true"}] mod 998244353.

</div>

</div>

</div>

</div>

</div>

</div>

</div>

### 输入描述

<div>

The first line contains two integers [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html
aria-hidden="true"}] and [[$k$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}] ([[$1 \leq n \leq 5 \times 10^{5},1 \leq k \leq 10^{9}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[n]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[5]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1.008548em;vertical-align:-0.19444em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.83041em;vertical-align:-0.13597em;"}[k]{.mord
.mathdefault style="margin-right:0.03148em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]).

</div>

<div>

\

</div>

The second line contains a string [[$S$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[S]{.mord .mathdefault
style="margin-right:0.05764em;"}]{.base}]{.katex-html
aria-hidden="true"}] of length [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}], only
consisting of both uppercase and lowercase English letters.

<div>

\

</div>

<div>

Note that uppercase and lowercase letters are treated as distinct.

</div>

### 输出描述

Output a single integer, the number of distinct strings that can be
formed by concatenating [[$k$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}] substrings (selected in order from the 1st
to the k-th operation) modulo 998244353.

### 示例1

#### 输入

```plain
2 2
ab
```

#### 输出

```plain
12
```

#### 说明

For the first sample, the substrings of \"ab\" are: \"\" (empty string),
\"a\", \"b\", and \"ab\".

\(1\) \"\" + \"\" = \"\"

\(2\) \"\" + \"a\" = \"a\"

\(3\) \"\" + \"b\" = \"b\"

\(4\) \"\" + \"ab\" = \"ab\"

\(5\) \"a\" + \"\" = \"a\"

\(6\) \"a\" + \"a\" = \"aa\"

\(7\) \"a\" + \"b\" = \"ab\"

\(8\) \"a\" + \"ab\" = \"aab\"

\(9\) \"b\" + \"\" = \"b\"

\(10\) \"b\" + \"a\" = \"ba\"

\(11\) \"b\" + \"b\" = \"bb\"

\(12\) \"b\" + \"bab\" = \"bab\"

\(13\) \"ab\" + \"\" = \"ab\"

\(14\) \"ab\" + \"a\" = \"aba\"

\(15\) \"ab\" + \"b\" = \"abb\"

\(16\) \"ab\" + \"ab\" = \"abab\"

Among the sixteen strings above, only twelve are
distinct：\"\",\"a\",\"b\",\"ab\",\"aa\",\"aab\",\"ba\",\"bb\",\"bab\",\"aba\",\"abb\",\"abab\"

### 示例2

#### 输入

```plain
3 3
abb
```

#### 输出

```plain
96
```

### 示例3

#### 输入

```plain
2 10
Aa
```

#### 输出

```plain
28656
```

### 示例4

#### 输入

```plain
9 6
IcePigeon
```

#### 输出

```plain
811212467
```

### 备注

\

