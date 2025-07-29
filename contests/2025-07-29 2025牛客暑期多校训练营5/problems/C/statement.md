## C. Array Deletion Game

### 题目描述

<div>

Alice and Bob play a game on an array [[$A$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[A]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] of
length [[$N$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[N]{.mord .mathdefault
style="margin-right:0.10903em;"}]{.base}]{.katex-html
aria-hidden="true"}], where all elements are positive integers.
The rules are as follows:

<div>

\

1.  Players take turns, with Alice going first.

2.  On each turn, a player can:
- Remove the leftmost element of the array, or
- Remove the rightmost element of the array.

3.  If after a player's move, the sum of the remaining elements
    [[$\leq s$][[[]{.strut
    style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[s]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
    that player loses the game.

<div>

\

Given the initial array, you need to process
[[$Q$][[[]{.strut
style="height:0.8777699999999999em;vertical-align:-0.19444em;"}[Q]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] queries.
For each query with a different [[$s$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[s]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
determine whether Alice has a winning strategy.

</div>

</div>

</div>

### 输入描述

<div>

The first line contains an integer [[$N$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[N]{.mord .mathdefault
style="margin-right:0.10903em;"}]{.base}]{.katex-html
aria-hidden="true"}]
([[$1 \leq N \leq 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
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
aria-hidden="true"}]), the length of the array.

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
([[$1 \leq A_{i} \leq 10000$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
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
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}[0]{.mord}[0]{.mord}[0]{.mord}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]), the elements of the array.

<div>

\

</div>

<div>

The third line contains an integer [[$Q$][[[]{.strut
style="height:0.8777699999999999em;vertical-align:-0.19444em;"}[Q]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
([[$1 \leq Q \leq 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8777699999999999em;vertical-align:-0.19444em;"}[Q]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]), the number of queries.

</div>

<div>

\

</div>

<div>

The next [[$Q$][[[]{.strut
style="height:0.8777699999999999em;vertical-align:-0.19444em;"}[Q]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] lines
each contain an integer [[$s$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[s]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
([[$1 \leq s < \sum A$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.5782em;vertical-align:-0.0391em;"}[s]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[\<]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:1.00001em;vertical-align:-0.25001em;"}[∑]{.mop .op-symbol
.small-op
style="position:relative;top:-0.0000050000000000050004em;"}[]{.mspace
style="margin-right:0.16666666666666666em;"}[A]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]), the
threshold for the current query.

</div>

### 输出描述

<div>

For each query [[$s$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[s]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}], output
one line:

</div>

<div>

\

</div>
- If Alice has a winning strategy, output "Alice".
- Otherwise, output "Bob".

### 示例1

#### 输入

```plain
5
1 3 5 7 9
3
10
15
20
```

#### 输出

```plain
Alice
Alice
Bob
```

