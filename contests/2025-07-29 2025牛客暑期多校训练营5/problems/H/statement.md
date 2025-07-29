## H. VI Civilization

### 题目描述

<div>

In the game VI Civilization, the player needs to achieve a science
victory: accumulating at least [[$s$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[s]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] science
points in the science victory slot within
[[$t$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] turns.

<div>

\

<div>

There are [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
technologies in the game. Initially, only the first technology,
[[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}], is unlocked and can be completed. All
other technologies are locked. The player must complete the technologies
in a fixed sequence:
[[$\left. Tech_{1}\rightarrow Tech_{2}\rightarrow\cdots\rightarrow Tech_{n} \right.$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[→]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[→]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.36687em;vertical-align:0em;"}[⋯]{.minner}[]{.mspace
style="margin-right:0.2777777777777778em;"}[→]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[n]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.151392em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]. This order cannot be skipped or changed.
Specifically, technology [[$Tech_{i}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] is unlocked only after all preceding
technologies  ([[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] to
[[$Tech_{i - 1}$][[[]{.strut
style="height:0.902771em;vertical-align:-0.208331em;"}[T]{.mord
.mathdefault style="margin-right:0.13889em;"}[e]{.mord
.mathdefault}[c]{.mord .mathdefault}[[h]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[[i]{.mord
.mathdefault .mtight}[−]{.mbin .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.311664em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.208331em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}])  have been completed.

<div>

\

<div>

Completing each technology requires a certain amount of science points.
The player can allocate production to trigger the technology's
\"Eureka\" moment, which reduces the science points required for
completion.**Each technology's Eureka can only be triggered once**. Upon
completing a technology, the science points gained per turn will
increase.

<div>

\

<div>

Each technology [[$Tech_{i}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] has four parameters:

[[$a_{i}$][[[]{.strut
style="height:0.58056em;vertical-align:-0.15em;"}[[a]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]: The science points required to complete
this technology.

[[$k_{i}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[[k]{.mord .mathdefault
style="margin-right:0.03148em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03148em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]: The increase in science points per turn
after completion.

[[$b_{i}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[[b]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]: The production required to trigger its
Eureka.

<div>

[[$c_{i}$][[[]{.strut
style="height:0.58056em;vertical-align:-0.15em;"}[[c]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]: The reduction in required science points
after triggering the Eureka
([[$0 \leq c_{i} < a_{i}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[0]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.6891em;vertical-align:-0.15em;"}[[c]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[\<]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.58056em;vertical-align:-0.15em;"}[[a]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]).

<div>

\

<div>

VI Civilization is a turn-based game. In each turn, the player first
gains science points and production, and then allocates them. The
allocation of science points and production must be **indivisible
(cannot be split among multiple tasks)**, and the science points and
production gained in the current turn **are not saved for the next
turn**.

<div>

\

<div>

The game proceeds as follows:

At the start of each turn, the player gains:

Science points [[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] (after
completing technology [[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
[[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
permanently increases by [[$k_{i}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[[k]{.mord .mathdefault
style="margin-right:0.03148em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03148em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]).

<div>

A fixed amount of production [[$p$][[[]{.strut
style="height:0.625em;vertical-align:-0.19444em;"}[p]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] (remains
constant throughout the game).

<div>

\

<div>

Then, the player performs actions:
- **Science Point Allocation:**

    1.  Allocate the entire amount of science points
        [[$m$][[[]{.strut
        style="height:0.43056em;vertical-align:0em;"}[m]{.mord
        .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
        gained this turn to either an unlocked technology or the science
        victory slot.

    2.  When allocating to a technology, any excess points are wasted
        and do not carry over to the next technology. After completing
        technology [[$Tech_{i}$][[[]{.strut
        style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord
        .mathdefault style="margin-right:0.13889em;"}[e]{.mord
        .mathdefault}[c]{.mord .mathdefault}[[h]{.mord
        .mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
        .mathdefault .mtight}]{.sizing .reset-size6 .size3
        .mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
        style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height:0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}], [[$m$][[[]{.strut
        style="height:0.43056em;vertical-align:0em;"}[m]{.mord
        .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
        permanently increases by [[$k_{i}$][[[]{.strut
        style="height:0.84444em;vertical-align:-0.15em;"}[[k]{.mord
        .mathdefault style="margin-right:0.03148em;"}[[[[[[]{.pstrut
        style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03148em;margin-right:0.05em;"}]{.vlist
        style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height:0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}].

    3.  When allocated to the science victory slot, the points are
        directly added to its total.
- **Production Allocation:**

    1.  Allocate the entire amount of production
        [[$p$][[[]{.strut
        style="height:0.625em;vertical-align:-0.19444em;"}[p]{.mord
        .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
        gained this turn **indivisibly (cannot be split among multiple
        Eurekas)** to the Eureka of **any technology (regardless of
        whether the technology is unlocked)**.

    2.  When allocating to a Eureka, any excess production is wasted.
        After a Eureka is triggered, the science point required to
        complete the corresponding technology is reduced.

<div>

\

<div>

Find the minimum non-negative integer production
[[$p$][[[]{.strut
style="height:0.625em;vertical-align:-0.19444em;"}[p]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] such
that there exists a strategy to achieve the science victory
(accumulating [[$\geq s$][[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[≥]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[s]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] science
points in the science victory slot) within
[[$t$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] turns.
If it's impossible to win within [[$t$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] turns,
output [[$- 1$][[[]{.strut
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

</div>

</div>

</div>

</div>

</div>

</div>

</div>

### 输入描述

<div>

The first line contains three integers [[$m$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[m]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}],
[[$s$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[s]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}], and
[[$t$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
([[$1 \leq m \leq 100$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[m]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}[0]{.mord}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}],
[[$1 \leq s \leq 10^{9}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[s]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}],
[[$1 \leq t \leq 100$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[t]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}[0]{.mord}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]).

</div>

<div>

\

</div>

The second line contains an integer [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
([[$0 \leq n \leq 100$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[0]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7719400000000001em;vertical-align:-0.13597em;"}[n]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}[0]{.mord}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]).

<div>

\

</div>

<div>

The next [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] lines
each contain four integers [[$a_{i}$][[[]{.strut
style="height:0.58056em;vertical-align:-0.15em;"}[[a]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}], [[$k_{i}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[[k]{.mord .mathdefault
style="margin-right:0.03148em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03148em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}], [[$b_{i}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[[b]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}], and [[$c_{i}$][[[]{.strut
style="height:0.58056em;vertical-align:-0.15em;"}[[c]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
([[$1 \leq a_{i} \leq 10^{6}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.7859700000000001em;vertical-align:-0.15em;"}[[a]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height:2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}],
[[$0 \leq k_{i} \leq 1000$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[0]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[[k]{.mord .mathdefault
style="margin-right:0.03148em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03148em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}[0]{.mord}[0]{.mord}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}],
[[$1 \leq b_{i} \leq 10000$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[1]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[[b]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}[0]{.mord}[0]{.mord}[0]{.mord}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}],
[[$0 \leq c_{i} < a_{i}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[0]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.6891em;vertical-align:-0.15em;"}[[c]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[\<]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.58056em;vertical-align:-0.15em;"}[[a]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[i]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]).

</div>

### 输出描述

Output the minimum non-negative integer [[$p$][[[]{.strut
style="height:0.625em;vertical-align:-0.19444em;"}[p]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]. If it
is impossible to win within [[$t$][[[]{.strut
style="height:0.61508em;vertical-align:0em;"}[t]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] turns,
output [[$- 1$][[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

### 示例1

#### 输入

```plain
10 100 9
2
50 10 20 25
60 10 30 20
```

#### 输出

```plain
4
```

#### 说明

<div>

In the sample case, a valid strategy for
[[$p = 4$][[[]{.strut
style="height:0.625em;vertical-align:-0.19444em;"}[p]{.mord
.mathdefault}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[4]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] is as follows:

</div>

<div>

\

</div>

**Turn 1:** Gain 10 science and 4 production. Allocate production to
[[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]'s Eureka and science to
[[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

**Turn 2:** Gain 10 science and 4 production. Allocate production to
[[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]'s Eureka and science to
[[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

**Turn 3:** Gain 10 science and 4 production. Allocate production to
[[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]'s Eureka and science to
[[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

**Turn 4:** Gain 10 science and 4 production. Allocate production to
[[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]'s Eureka and science to the science victory
slot.

**Turn 5:** Gain 10 science and 4 production. Allocate production to
[[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]'s Eureka and science to the science victory
slot. At this turn, [[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]'s Eureka has accumulated
[[$20$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[2]{.mord}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] production, triggering the Eureka. The
science cost for [[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] is now
[[$50 - 25 = 25$][[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[5]{.mord}[0]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[−]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[2]{.mord}[5]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[2]{.mord}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]. Since [[$30$][[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[3]{.mord}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] science points have already been allocated,
[[$Tech_{1}$][[[]{.strut
style="height:0.84444em;vertical-align:-0.15em;"}[T]{.mord .mathdefault
style="margin-right:0.13889em;"}[e]{.mord .mathdefault}[c]{.mord
.mathdefault}[[h]{.mord .mathdefault}[[[[[[]{.pstrut
style="height:2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] is completed. The science per turn
increases to [[$10 + 10 = 20$][[[]{.strut
style="height:0.72777em;vertical-align:-0.08333em;"}[1]{.mord}[0]{.mord}[]{.mspace
style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}[0]{.mord}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[2]{.mord}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

**Turn 6:** Gain 20 science and 4 production. Allocate science to the
science victory slot.

**Turn 7:** Gain 20 science and 4 production. Allocate science to the
science victory slot.

**Turn 8:** Gain 20 science and 4 production. Allocate science to the
science victory slot.

<div>

**Turn 9:** Gain 20 science and 4 production. Allocate science to the
science victory slot. 

</div>

<div>

\

</div>

<div>

The science victory slot has accumulated a total of
[[$10(\text{T4}) + 10(\text{T5}) + 20(\text{T6}) + 20(\text{T7}) + 20(\text{T8}) + 20(\text{T9}) = 100$][[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[1]{.mord}[0]{.mord}[(]{.mopen}[[T4]{.mord}]{.mord
.text}[)]{.mclose}[]{.mspace
style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[1]{.mord}[0]{.mord}[(]{.mopen}[[T5]{.mord}]{.mord
.text}[)]{.mclose}[]{.mspace
style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[2]{.mord}[0]{.mord}[(]{.mopen}[[T6]{.mord}]{.mord
.text}[)]{.mclose}[]{.mspace
style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[2]{.mord}[0]{.mord}[(]{.mopen}[[T7]{.mord}]{.mord
.text}[)]{.mclose}[]{.mspace
style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[2]{.mord}[0]{.mord}[(]{.mopen}[[T8]{.mord}]{.mord
.text}[)]{.mclose}[]{.mspace
style="margin-right:0.2222222222222222em;"}[+]{.mbin}[]{.mspace
style="margin-right:0.2222222222222222em;"}]{.base}[[]{.strut
style="height:1em;vertical-align:-0.25em;"}[2]{.mord}[0]{.mord}[(]{.mopen}[[T9]{.mord}]{.mord
.text}[)]{.mclose}[]{.mspace
style="margin-right:0.2777777777777778em;"}[=]{.mrel}[]{.mspace
style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
style="height:0.64444em;vertical-align:0em;"}[1]{.mord}[0]{.mord}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] science points. Science victory is
achieved!

</div>

### 示例2

#### 输入

```plain
22 970 8
3
85 24 9 27
81 20 85 44
30 80 75 7
```

#### 输出

```plain
-1
```

