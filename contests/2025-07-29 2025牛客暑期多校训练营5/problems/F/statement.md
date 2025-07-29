## F. Grid Survival

### 题目描述

<div>

Alice and Bob are playing a game with one piece on a grid board with
[[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] rows and
[[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] columns.
The rules of the game are as follows:

<div>

\
- The grid in the [[$l$][[[]{.strut
    style="height:0.69444em;vertical-align:0em;"}[l]{.mord .mathdefault
    style="margin-right:0.01968em;"}]{.base}]{.katex-html
    aria-hidden="true"}]-th line and the
    [[$c$][[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[c]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th
    column is called of position [[$(l,c)$][[[]{.strut
    style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[l]{.mord
    .mathdefault style="margin-right:0.01968em;"}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[c]{.mord
    .mathdefault}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] , and is colored **white** when
    [[$l$][[[]{.strut
    style="height:0.69444em;vertical-align:0em;"}[l]{.mord .mathdefault
    style="margin-right:0.01968em;"}]{.base}]{.katex-html
    aria-hidden="true"}] and [[$c$][[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[c]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}] have
    the same parity and **black** when different.
- The piece must be within a certain grid at any moment; in other
    words, the position of the piece can also be represented by an
    integer pair [[$(l,c)$][[[]{.strut
    style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[l]{.mord
    .mathdefault style="margin-right:0.01968em;"}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[c]{.mord
    .mathdefault}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] , which means that the piece is in the
    grid of the [[$l$][[[]{.strut
    style="height:0.69444em;vertical-align:0em;"}[l]{.mord .mathdefault
    style="margin-right:0.01968em;"}]{.base}]{.katex-html
    aria-hidden="true"}]-th line and the
    [[$c$][[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[c]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th
    column, and
    [[$1 \leq l \leq n,1 \leq c \leq m$][[[]{.strut
    style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.83041em;vertical-align:-0.13597em;"}[l]{.mord
    .mathdefault style="margin-right:0.01968em;"}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.8388800000000001em;vertical-align:-0.19444em;"}[n]{.mord
    .mathdefault}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[1]{.mord}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[c]{.mord
    .mathdefault}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[m]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
    always holds.
- On the board there are [[$k$][[[]{.strut
    style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
    style="margin-right:0.03148em;"}]{.base}]{.katex-html
    aria-hidden="true"}] grid(s) specialized in advance, the
    [[$i$][[[]{.strut
    style="height:0.65952em;vertical-align:0em;"}[i]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th
    special grid is of position
    [[$(l_{i}^{\prime},c_{i}^{\prime})$][[[]{.strut
    style="height:1.010556em;vertical-align:-0.258664em;"}[(]{.mopen}[[l]{.mord
    .mathdefault style="margin-right:0.01968em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.441336em;margin-left:-0.01968em;margin-right:0.05em;"}[[]{.pstrut
    style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
    style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.258664em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[[c]{.mord
    .mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
    .mathdefault .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top:-2.441336em;margin-left:0em;margin-right:0.05em;"}[[]{.pstrut
    style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
    style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.258664em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] and has a positive integer value
    [[$w_{i}$][[[]{.strut
    style="height:0.58056em;vertical-align:-0.15em;"}[[w]{.mord
    .mathdefault style="margin-right:0.02691em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.02691em;margin-right:0.05em;"}]{.vlist
    style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] .
- The game lasts for a number of round(s) (starting with
    [[$1$][[[]{.strut
    style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]):
- Initially, the board is empty and the piece is not placed yet;
- In the first round, Bob chooses a color
        [[$col$][[[]{.strut
        style="height:0.69444em;vertical-align:0em;"}[c]{.mord
        .mathdefault}[o]{.mord .mathdefault}[l]{.mord .mathdefault
        style="margin-right:0.01968em;"}]{.base}]{.katex-html
        aria-hidden="true"}] either white or black, and for each
        special grid (of the [[$i$][[[]{.strut
        style="height:0.65952em;vertical-align:0em;"}[i]{.mord
        .mathdefault}]{.base}]{.katex-html
        aria-hidden="true"}]-th) , he can make it **active** at
        the cost of [[$w_{i}$][[[]{.strut
        style="height:0.58056em;vertical-align:-0.15em;"}[[w]{.mord
        .mathdefault style="margin-right:0.02691em;"}[[[[[[]{.pstrut
        style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.02691em;margin-right:0.05em;"}]{.vlist
        style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height:0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}] or **inactive** with no cost;
- In the second round, Alice chooses an arbitrary grid of color
        [[$col$][[[]{.strut
        style="height:0.69444em;vertical-align:0em;"}[c]{.mord
        .mathdefault}[o]{.mord .mathdefault}[l]{.mord .mathdefault
        style="margin-right:0.01968em;"}]{.base}]{.katex-html
        aria-hidden="true"}] to place the piece;
- In the third round and further odd rounds, Bob must move the
        piece along the line by 1 unit, from position
        [[$(l,c)$][[[]{.strut
        style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[l]{.mord
        .mathdefault
        style="margin-right:0.01968em;"}[,]{.mpunct}[]{.mspace
        style="margin-right:0.16666666666666666em;"}[c]{.mord
        .mathdefault}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}] to either
        [[$(l + 1,c)$][[[]{.strut
        style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[l]{.mord
        .mathdefault style="margin-right:0.01968em;"}[]{.mspace
        style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
        style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
        style="height:1em;vertical-align:-0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right:0.16666666666666666em;"}[c]{.mord
        .mathdefault}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}] or
        [[$(l - 1,c)$][[[]{.strut
        style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[l]{.mord
        .mathdefault style="margin-right:0.01968em;"}[]{.mspace
        style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
        style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
        style="height:1em;vertical-align:-0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right:0.16666666666666666em;"}[c]{.mord
        .mathdefault}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]. Note that after the move
        [[$1 \leq l \leq n$][[[]{.strut
        style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
        style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
        style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
        style="height:0.83041em;vertical-align:-0.13597em;"}[l]{.mord
        .mathdefault style="margin-right:0.01968em;"}[]{.mspace
        style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
        style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
        style="height:0.43056em;vertical-align:0em;"}[n]{.mord
        .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
        should still be satisfied, and Bob can\'t leave the piece not
        moved in the round.
- In the fourth round and further even rounds, Alice must move the
        piece along the column by 1 unit, from position
        [[$(l,c)$][[[]{.strut
        style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[l]{.mord
        .mathdefault
        style="margin-right:0.01968em;"}[,]{.mpunct}[]{.mspace
        style="margin-right:0.16666666666666666em;"}[c]{.mord
        .mathdefault}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}] to either
        [[$(l,c - 1)$][[[]{.strut
        style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[l]{.mord
        .mathdefault
        style="margin-right:0.01968em;"}[,]{.mpunct}[]{.mspace
        style="margin-right:0.16666666666666666em;"}[c]{.mord
        .mathdefault}[]{.mspace
        style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
        style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
        style="height:1em;vertical-align:-0.25em;"}[1]{.mord}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}] or
        [[$(l,c + 1)$][[[]{.strut
        style="height:1em;vertical-align:-0.25em;"}[(]{.mopen}[l]{.mord
        .mathdefault
        style="margin-right:0.01968em;"}[,]{.mpunct}[]{.mspace
        style="margin-right:0.16666666666666666em;"}[c]{.mord
        .mathdefault}[]{.mspace
        style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
        style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
        style="height:1em;vertical-align:-0.25em;"}[1]{.mord}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]. Similarly, after the move
        [[$1 \leq c \leq m$][[[]{.strut
        style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
        style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
        style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
        style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[c]{.mord
        .mathdefault}[]{.mspace
        style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
        style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
        style="height:0.43056em;vertical-align:0em;"}[m]{.mord
        .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
        should still be satisfied, and Alice can\'t leave the piece not
        moved in the round.
- Whenever the piece lies in any **active** grid, Alice loses and Bob
    wins; else if the game lasts for
    [[$10^{100}$][[[]{.strut
    style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height:2.7em;"}[[[1]{.mord .mtight}[0]{.mord
    .mtight}[0]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6
    .size3 .mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
    style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] rounds (or forever), Bob loses and
    Alice wins.

<div>

\

<div>

Assuming that both players are smart enough, and given the parameters of
the grid board ([[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] and
[[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]) and
special grid(s)
([[$l_{i}^{\prime},c_{i}^{\prime}$][[[]{.strut
style="height:1.010556em;vertical-align:-0.258664em;"}[[l]{.mord
.mathdefault style="margin-right:0.01968em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.441336em;margin-left:-0.01968em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.258664em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[c]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.441336em;margin-left:0em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.258664em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] and [[$w_{i}$][[[]{.strut
style="height:0.58056em;vertical-align:-0.15em;"}[[w]{.mord .mathdefault
style="margin-right:0.02691em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.02691em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]); for each chosen color, please calculate
the minimal total cost for Bob to activate some special grid(s) to win,
or report that it\'s impossible.

<div>

\

<div>

Note that you may answer multiple queries.

</div>

</div>

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

<div>

The first line contains three integers
[[$n,m,k$][[[]{.strut
style="height:0.8888799999999999em;vertical-align:-0.19444em;"}[n]{.mord
.mathdefault}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[m]{.mord
.mathdefault}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}]
([[$2 \leq n,m \leq 10^{6},0 \leq k \leq \min(2 \times 10^{5},n \times m)$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[2]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8304100000000001em;vertical-align:-0.19444em;"}[n]{.mord
.mathdefault}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[m]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:1.008548em;vertical-align:-0.19444em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[0]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.83041em;vertical-align:-0.13597em;"}[k]{.mord
.mathdefault style="margin-right:0.03148em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[min]{.mop}[(]{.mopen}[2]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1.008548em;vertical-align:-0.19444em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[n]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[m]{.mord
.mathdefault}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]) meaning as above;

</div>

<div>

\

</div>

<div>

Then following [[$k$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}] lines, the [[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th line
contains three integers
[[$l_{i}^{\prime},c_{i}^{\prime}$][[[]{.strut
style="height:1.010556em;vertical-align:-0.258664em;"}[[l]{.mord
.mathdefault style="margin-right:0.01968em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.441336em;margin-left:-0.01968em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.258664em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[c]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.441336em;margin-left:0em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.258664em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
([[$1 \leq l_{i}^{\prime} \leq n,1 \leq c_{i}^{\prime} \leq m$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:1.010556em;vertical-align:-0.258664em;"}[[l]{.mord
.mathdefault style="margin-right:0.01968em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.441336em;margin-left:-0.01968em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.258664em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8388800000000001em;vertical-align:-0.19444em;"}[n]{.mord
.mathdefault}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:1.010556em;vertical-align:-0.258664em;"}[[c]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.441336em;margin-left:0em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.258664em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]) and
[[$w_{i}$][[[]{.strut
style="height:0.58056em;vertical-align:-0.15em;"}[[w]{.mord .mathdefault
style="margin-right:0.02691em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.02691em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
([[$1 \leq w_{i} \leq 10^{9}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7859700000000001em;vertical-align:-0.15em;"}[[w]{.mord
.mathdefault style="margin-right:0.02691em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.02691em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]), representing the located row and column
and the value of the [[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th
special grid; it's guaranteed that in the same test case no two special
grids fall in the same position
([[$\left. \ \forall\ 1 \leq i < j \leq k\Rightarrow l_{i}^{\prime}\neq l_{j}^{\prime} \vee c_{i}^{\prime}\neq c_{j}^{\prime}\  \right.$][[[]{.strut
style="height:0.83041em;vertical-align:-0.13597em;"}[ ]{.mspace
.nobreak}[∀]{.mord}[ ]{.mspace .nobreak}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.69862em;vertical-align:-0.0391em;"}[i]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[\<]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.85396em;vertical-align:-0.19444em;"}[j]{.mord
.mathdefault style="margin-right:0.05724em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[⇒]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:1.010556em;vertical-align:-0.258664em;"}[[l]{.mord
.mathdefault style="margin-right:0.01968em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.441336em;margin-left:-0.01968em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.258664em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[[[[[[[[]{.pstrut
style="height:3em;"}[[]{.strut
style="height:0.8888799999999999em;vertical-align:-0.19444em;"}[[]{.mrel}]{.inner}[]{.fix}]{.rlap}]{style="top:-3em;"}]{.vlist
style="height:0.69444em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.19444em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mord}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:1.146664em;vertical-align:-0.394772em;"}[[l]{.mord
.mathdefault style="margin-right:0.01968em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[j]{.mord .mathdefault .mtight
style="margin-right:0.05724em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.441336em;margin-left:-0.01968em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.394772em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[∨]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1.010556em;vertical-align:-0.258664em;"}[[c]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.441336em;margin-left:0em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.258664em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[[[[[[[[]{.pstrut
style="height:3em;"}[[]{.strut
style="height:0.8888799999999999em;vertical-align:-0.19444em;"}[[]{.mrel}]{.inner}[]{.fix}]{.rlap}]{style="top:-3em;"}]{.vlist
style="height:0.69444em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.19444em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mord}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:1.146664em;vertical-align:-0.394772em;"}[[c]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[j]{.mord
.mathdefault .mtight style="margin-right:0.05724em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.441336em;margin-left:0em;margin-right:0.05em;"}[[]{.pstrut
style="height:2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.751892em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.394772em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace .nobreak}]{.base}]{.katex-html
aria-hidden="true"}]).

</div>

<div>

\

</div>

It's also guaranteed that the sum of [[$k$][[[]{.strut
style="height:0.69444em;vertical-align:0em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}]{.base}]{.katex-html
aria-hidden="true"}] in each test file doesn't exceed
[[$2 \times 10^{5}$][[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[2]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
([[$\sum k \leq 2 \times 10^{5}$][[[]{.strut
style="height:1.00001em;vertical-align:-0.25001em;"}[∑]{.mop .op-symbol
.small-op
style="position:relative;top:-0.0000050000000000050004em;"}[]{.mspace
style="margin-right:0.16666666666666666em;"}[k]{.mord .mathdefault
style="margin-right:0.03148em;"}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[2]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[×]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]); note that there are no restrictions with
the sum of [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] and
[[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] .

### 输出描述

For each test case, answer it on a full line, containing two integers
representing the answer for the chosen color (white or black in order):
the minimal total cost if possible, or
[[$- 1$][[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] if impossible.

### 示例1

#### 输入

```plain
7
2 3 4
1 1 52
1 2 33
2 1 47
2 2 95
2 3 2
1 2 90
1 3 30
5 5 4
4 2 30
4 4 10
2 4 40
2 2 20
6 6 4
6 2 10
6 4 10
1 3 10
1 5 10
5 6 4
5 2 10
5 4 10
1 3 10
1 5 10
11 5 5
2 1 1
2 3 1
6 3 1
10 3 1
10 5 1
2 2 0
```

#### 输出

```plain
33 33
90 90
40 30
-1 40
40 40
5 -1
-1 -1
```

