## J. Fastest Coverage Problem

### 题目描述

<div>

Given an [[$n \times m$][[[]{.strut
style="height:0.66666em;vertical-align:-0.08333em;"}[n]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] binary
matrix where [[$1$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] represents a black cell and
[[$0$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] represents a white cell. Every second, each
black cell will convert its four neighboring white cells (top, bottom,
left, right) to black.

<div>

\

You may change **at most** one white cell to black (convert
[[$0$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] to [[$1$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]) to minimize the time required for the
entire matrix to become completely black. Find this minimum time.

</div>

</div>

### 输入描述

<div>

The first line contains two integers [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] and
[[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
([[$1 \leq n \times m \leq 2 \times 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.66666em;vertical-align:-0.08333em;"}[n]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
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
aria-hidden="true"}]), representing the number of rows and
columns of the matrix.

</div>

<div>

\

</div>

The next [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] lines
each contain [[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] digits
([[$0$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] or [[$1$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]), representing the initial state of the
matrix.

### 输出描述

Output a single integer representing the minimum time required to turn
the entire matrix black after adding one black cell.

### 示例1

#### 输入

```plain
3 3
0 0 0
0 0 0
0 0 1
```

#### 输出

```plain
2
```

#### 说明

You can choose position (1,1).\
\
Matrix at second 0:\
1 0 0\
0 0 0\
0 0 1\
\
Matrix at second 1:\
1 1 0\
1 0 1\
0 1 1\
\
Matrix at second 2:\
1 1 1\
1 1 1\
1 1 1

### 示例2

#### 输入

```plain
2 2
1 0
0 0
```

#### 输出

```plain
1
```

### 示例3

#### 输入

```plain
1 5
0 1 0 0 0
```

#### 输出

```plain
1
```

