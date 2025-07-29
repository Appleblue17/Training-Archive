## I. Block Combination Minimal Perimeter

### 题目描述

<div>

Given [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
rectangular blocks, where the [[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th block
has dimensions [[$1 \times i$][[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]. You
need to combine **all** blocks to form a solid rectangle (no overlaps or
empty spaces allowed). Find the minimal perimeter of the resulting
rectangle.

<div>

\

<div>

It is guaranteed that you can always form [a solid
rectangle ]{style="text-wrap-mode:wrap;"}under the problem constraints.\

</div>

</div>

</div>

### 输入描述

The first line contains an integer [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
([[$1 \leq n \leq 2 \times 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
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
aria-hidden="true"}]), representing the number of blocks.

### 输出描述

Output a single integer representing the minimal perimeter of the formed
rectangle.

### 示例1

#### 输入

```plain
1
```

#### 输出

```plain
4
```

### 示例2

#### 输入

```plain
6
```

#### 输出

```plain
20
```

### 示例3

#### 输入

```plain
10
```

#### 输出

```plain
32
```

