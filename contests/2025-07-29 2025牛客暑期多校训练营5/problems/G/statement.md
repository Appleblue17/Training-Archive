## G. Line of Sight

### 题目描述

::: background-info
In 2024, team \"Moon Cat\" trained hundreds of hours together, walked
through a lot of places, ended with regret of loss, but experienced many
good things and memories, unpredicted and sparkling in mind as if a
dream.

SATSKY remembers, whenever the team was heading to somewhere, in the
streets or metro station or anywhere, it often occurs that laurxh
\"walks away without looking back, as if he had made some
determination\"(goes far ahead), while Genius_dream concentrates on her
phone and drops too far behind. In this case, SATSKY prefers to track
the middle point of two teammates\' locations, or at least find a place
where he can see his teammates both, especially when around the corner
and they can\'t see each other.

<div>

\

<div>

Now SATSKY transformed this into a programming geometry problem, in
commemoration of the memorable year with them, the treasure of his life.

<div>

\

Formally:
- Give you an [[$n$][[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[n]{.mord
    .mathdefault}]{.base}]{.katex-html
    aria-hidden="true"}]-sided polygon
    [[$P$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[P]{.mord .mathdefault
    style="margin-right:0.13889em;"}]{.base}]{.katex-html
    aria-hidden="true"}], of which each point
    [[$P_{1 \sim n}$][[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[P]{.mord
    .mathdefault style="margin-right:0.13889em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[[1]{.mord .mtight}[∼]{.mrel
    .mtight}[n]{.mord .mathdefault .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
    style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] is of integer coordinates and given in
    **counterclockwise order;**
- And give you two more integer points
    [[$A$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[A]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}] and
    [[$B$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[B]{.mord .mathdefault
    style="margin-right:0.05017em;"}]{.base}]{.katex-html
    aria-hidden="true"}], inside the polygon (**boundary not
    included) guaranteed;**
- Call "point [[$X$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[X]{.mord .mathdefault
    style="margin-right:0.07847em;"}]{.base}]{.katex-html
    aria-hidden="true"}] can be seen from point
    [[$Y$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[Y]{.mord .mathdefault
    style="margin-right:0.22222em;"}]{.base}]{.katex-html
    aria-hidden="true"}] (in [[$P$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[P]{.mord .mathdefault
    style="margin-right:0.13889em;"}]{.base}]{.katex-html
    aria-hidden="true"}])" **if and only if the whole segment
    connecting two points, **except two endpoints, is inside
    [[$P$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[P]{.mord .mathdefault
    style="margin-right:0.13889em;"}]{.base}]{.katex-html
    aria-hidden="true"}] strictly (and doesn't intersect with
    any of edge of [[$P$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[P]{.mord .mathdefault
    style="margin-right:0.13889em;"}]{.base}]{.katex-html
    aria-hidden="true"}] naturally) ;****
- You need to find out:
- For each point of polygon ([[$i$][[[]{.strut
        style="height:0.65952em;vertical-align:0em;"}[i]{.mord
        .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
        from [[$1$][[[]{.strut
        style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}] to [[$n$][[[]{.strut
        style="height:0.43056em;vertical-align:0em;"}[n]{.mord
        .mathdefault}]{.base}]{.katex-html
        aria-hidden="true"}]), can it
        ([[$P_{i}$][[[]{.strut
        style="height:0.83333em;vertical-align:-0.15em;"}[[P]{.mord
        .mathdefault style="margin-right:0.13889em;"}[[[[[[]{.pstrut
        style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
        style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height:0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}]) be seen from point
        [[$A$][[[]{.strut
        style="height:0.68333em;vertical-align:0em;"}[A]{.mord
        .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
        ?
- For each point of polygon ([[$i$][[[]{.strut
        style="height:0.65952em;vertical-align:0em;"}[i]{.mord
        .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
        from [[$1$][[[]{.strut
        style="height:0.64444em;vertical-align:0em;"}[1]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}] to [[$n$][[[]{.strut
        style="height:0.43056em;vertical-align:0em;"}[n]{.mord
        .mathdefault}]{.base}]{.katex-html
        aria-hidden="true"}]), can it
        ([[$P_{i}$][[[]{.strut
        style="height:0.83333em;vertical-align:-0.15em;"}[[P]{.mord
        .mathdefault style="margin-right:0.13889em;"}[[[[[[]{.pstrut
        style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
        style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height:0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}]) be seen from point
        [[$B$][[[]{.strut
        style="height:0.68333em;vertical-align:0em;"}[B]{.mord
        .mathdefault
        style="margin-right:0.05017em;"}]{.base}]{.katex-html
        aria-hidden="true"}] ?
- Is there a point [[$C$][[[]{.strut
        style="height:0.68333em;vertical-align:0em;"}[C]{.mord
        .mathdefault
        style="margin-right:0.07153em;"}]{.base}]{.katex-html
        aria-hidden="true"}] inside the polygon (**boundary not
        included) to see [[$A$][[[]{.strut
        style="height:0.68333em;vertical-align:0em;"}[A]{.mord
        .mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
        and [[$B$][[[]{.strut
        style="height:0.68333em;vertical-align:0em;"}[B]{.mord
        .mathdefault
        style="margin-right:0.05017em;"}]{.base}]{.katex-html
        aria-hidden="true"}] simultaneously ?**

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

The first line contains two integers [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]
([[$3 \leq n \leq 2 \times 10^{5}$][[[]{.strut
style="height:0.78041em;vertical-align:-0.13597em;"}[3]{.mord}[]{.mspace
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
aria-hidden="true"}]), indicating the number of points of
[[$P$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[P]{.mord .mathdefault
style="margin-right:0.13889em;"}]{.base}]{.katex-html
aria-hidden="true"}];

<div>

\

</div>

<div>

The second line contains four integers
[[$x_{A},y_{A},x_{B},y_{B}$][[[]{.strut
style="height:0.625em;vertical-align:-0.19444em;"}[[x]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[A]{.mord
.mathdefault .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.32833099999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[y]{.mord .mathdefault
style="margin-right:0.03588em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[A]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03588em;margin-right:0.05em;"}]{.vlist
style="height:0.32833099999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[x]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[B]{.mord
.mathdefault .mtight style="margin-right:0.05017em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.32833099999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[y]{.mord .mathdefault
style="margin-right:0.03588em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[B]{.mord .mathdefault .mtight
style="margin-right:0.05017em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03588em;margin-right:0.05em;"}]{.vlist
style="height:0.32833099999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] , representing the x and y coordinates of
point [[$A$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[A]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] and
[[$B$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[B]{.mord .mathdefault
style="margin-right:0.05017em;"}]{.base}]{.katex-html
aria-hidden="true"}];

</div>

<div>

\

</div>

<div>

Then following [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] lines,
the [[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th line
contains two integers [[$x_{P_{i}},y_{P_{i}}$][[[]{.strut
style="height:0.68066em;vertical-align:-0.2501em;"}[[x]{.mord
.mathdefault}[[[[[[]{.pstrut style="height:2.7em;"}[[[[P]{.mord
.mathdefault .mtight style="margin-right:0.13889em;"}[[[[[[]{.pstrut
style="height:2.5em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top:-2.357em;margin-left:-0.13889em;margin-right:0.07142857142857144em;"}]{.vlist
style="height:0.3280857142857143em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:0em;margin-right:0.05em;"}]{.vlist
style="height:0.32833099999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.2501em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right:0.16666666666666666em;"}[[y]{.mord .mathdefault
style="margin-right:0.03588em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[[[P]{.mord .mathdefault .mtight
style="margin-right:0.13889em;"}[[[[[[]{.pstrut
style="height:2.5em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top:-2.357em;margin-left:-0.13889em;margin-right:0.07142857142857144em;"}]{.vlist
style="height:0.3280857142857143em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.03588em;margin-right:0.05em;"}]{.vlist
style="height:0.32833099999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.2501em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] , representing the x and y coordinates of
point [[$P_{i}$][[[]{.strut
style="height:0.83333em;vertical-align:-0.15em;"}[[P]{.mord .mathdefault
style="margin-right:0.13889em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}].

</div>

<div>

\

</div>

<div>

It's guaranteed that:

</div>
- [[$P_{1 \sim n}$][[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[P]{.mord
    .mathdefault style="margin-right:0.13889em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[[1]{.mord .mtight}[∼]{.mrel
    .mtight}[n]{.mord .mathdefault .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
    style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] are given in **counterclockwise order
    and must form a polygon;**
- For [[$A$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[A]{.mord
    .mathdefault}]{.base}]{.katex-html
    aria-hidden="true"}],[[$B$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[B]{.mord .mathdefault
    style="margin-right:0.05017em;"}]{.base}]{.katex-html
    aria-hidden="true"}] and each point of
    [[$P$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[P]{.mord .mathdefault
    style="margin-right:0.13889em;"}]{.base}]{.katex-html
    aria-hidden="true"}]
    ([[$P_{1 \sim n}$][[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[P]{.mord
    .mathdefault style="margin-right:0.13889em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[[1]{.mord .mtight}[∼]{.mrel
    .mtight}[n]{.mord .mathdefault .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
    style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]), all the coordinates satisfy
    [[$\mid x \mid , \mid y \mid \leq 10^{9}$][[[]{.strut
    style="height:1em;vertical-align:-0.25em;"}[∣]{.mopen}[x]{.mord
    .mathdefault}[∣]{.mclose}[,]{.mpunct}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[∣]{.mopen}[y]{.mord
    .mathdefault style="margin-right:0.03588em;"}[∣]{.mclose}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height:2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6
    .size3 .mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
    style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}];
- <div>

    The sum of [[$n$][[[]{.strut
    style="height:0.43056em;vertical-align:0em;"}[n]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}] in
    each test file doesn't exceed [[$10^{6}$][[[]{.strut
    style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height:2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6
    .size3 .mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
    style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    ([[$\sum n \leq 10^{6}$][[[]{.strut
    style="height:1.00001em;vertical-align:-0.25001em;"}[∑]{.mop
    .op-symbol .small-op
    style="position:relative;top:-0.0000050000000000050004em;"}[]{.mspace
    style="margin-right:0.16666666666666666em;"}[n]{.mord
    .mathdefault}[]{.mspace
    style="margin-right:0.2777777777777778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right:0.2777777777777778em;"}]{.base}[[]{.strut
    style="height:0.8141079999999999em;vertical-align:0em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height:2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6
    .size3 .mtight}]{style="top:-3.063em;margin-right:0.05em;"}]{.vlist
    style="height:0.8141079999999999em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]).

    </div>

<div>

\

</div>

<div>

Some emphasis:

</div>
- Adjacent edges of [[$P$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[P]{.mord .mathdefault
    style="margin-right:0.13889em;"}]{.base}]{.katex-html
    aria-hidden="true"}] may be collinear, so are not adjacent
    pairs;
- Any three points within [[$A$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[A]{.mord
    .mathdefault}]{.base}]{.katex-html
    aria-hidden="true"}],[[$B$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[B]{.mord .mathdefault
    style="margin-right:0.05017em;"}]{.base}]{.katex-html
    aria-hidden="true"}] and
    [[$P_{1 \sim n}$][[[]{.strut
    style="height:0.83333em;vertical-align:-0.15em;"}[[P]{.mord
    .mathdefault style="margin-right:0.13889em;"}[[[[[[]{.pstrut
    style="height:2.7em;"}[[[1]{.mord .mtight}[∼]{.mrel
    .mtight}[n]{.mord .mathdefault .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
    style="height:0.30110799999999993em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height:0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] may be on the same straight line,
    [[$A$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[A]{.mord
    .mathdefault}]{.base}]{.katex-html aria-hidden="true"}] and
    [[$B$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[B]{.mord .mathdefault
    style="margin-right:0.05017em;"}]{.base}]{.katex-html
    aria-hidden="true"}] may even coincide;
- The coordinates of [[$C$][[[]{.strut
    style="height:0.68333em;vertical-align:0em;"}[C]{.mord .mathdefault
    style="margin-right:0.07153em;"}]{.base}]{.katex-html
    aria-hidden="true"}] you choose can be **decimals.**

### 输出描述

<div>

For each test case, answer it on three lines:

</div>

<div>

\

</div>

In the first line, output [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] integers
separated by spaces: the [[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th
integer should be 1 if [[$P_{i}$][[[]{.strut
style="height:0.83333em;vertical-align:-0.15em;"}[[P]{.mord .mathdefault
style="margin-right:0.13889em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] can be seen from point
[[$A$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[A]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}], or 0 if
it can't;

<div>

\

</div>

<div>

In the second line, output [[$n$][[[]{.strut
style="height:0.43056em;vertical-align:0em;"}[n]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}] integers
separated by spaces: the [[$i$][[[]{.strut
style="height:0.65952em;vertical-align:0em;"}[i]{.mord
.mathdefault}]{.base}]{.katex-html aria-hidden="true"}]-th
integer should be 1 if [[$P_{i}$][[[]{.strut
style="height:0.83333em;vertical-align:-0.15em;"}[[P]{.mord .mathdefault
style="margin-right:0.13889em;"}[[[[[[]{.pstrut
style="height:2.7em;"}[[i]{.mord .mathdefault .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top:-2.5500000000000003em;margin-left:-0.13889em;margin-right:0.05em;"}]{.vlist
style="height:0.31166399999999994em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height:0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] can be seen from point
[[$B$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[B]{.mord .mathdefault
style="margin-right:0.05017em;"}]{.base}]{.katex-html
aria-hidden="true"}], or 0 if it can't;

</div>

<div>

\

</div>

<div>

In the third line, if there exists a point
[[$C$][[[]{.strut
style="height:0.68333em;vertical-align:0em;"}[C]{.mord .mathdefault
style="margin-right:0.07153em;"}]{.base}]{.katex-html
aria-hidden="true"}] meeting the requirements above, output a
string "Yes" (without quotes); otherwise output a string "No" (without
quotes).

</div>

### 示例1

#### 输入

```plain
2
8
-1 1 1 -1
2 -1
2 1
1 2
-1 2
-2 1
-2 -1
-1 -2
1 -2
13
1 1 6 1
0 1
1 0
2 1
3 1
4 0
5 0
6 0
7 1
6 2
5 1
4 1
3 2
1 2
```

#### 输出

```plain
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
Yes
1 1 1 0 0 0 0 0 0 0 0 1 1
0 0 0 0 1 1 1 1 1 1 0 0 0
No
```

### 示例2

#### 输入

```plain
2
26
6 20 20 6
23 8
19 6
16 5
13 5
10 6
8 7
7 8
6 10
5 13
5 16
6 19
8 23
5 21
3 19
2 17
1 14
1 11
2 7
3 5
5 3
7 2
11 1
14 1
17 2
19 3
21 5
18
-15 20 15 20
-3 16
-6 15
-15 22
-18 13
-18 7
-21 -2
-21 -8
-18 -14
-6 -20
6 -20
18 -14
21 -8
21 -2
18 7
18 13
15 22
6 15
3 16
```

#### 输出

```plain
0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1
No
0 1 1 1 1 0 1 1 1 1 1 1 1 0 0 0 0 0
0 0 0 0 0 1 1 1 1 1 1 1 0 1 1 1 1 0
Yes
```

### 备注

<div>

Graphs of all samples are shown below in order:\
\
sample 1-1:\

</div>

<div>

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603158294/6EE7CF07BD6DC5DB395EF3937F0429AE)

</div>

<div>

sample 1-2:

</div>

<div>

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603255082/8C48DA35E654A5AFEA304DD9994C453C)\

</div>

<div>

sample 2-1:

</div>

<div>

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603262982/6C41A6E045994169B09A270749C8DDBB)\
sample 2-2:

</div>

<div>

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603272494/0DEE8CF824D43456DC0388C572D3DD13)\
sample 2-3:

</div>

<div>

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753607103004/7B6AB3489727CC25BCCF3F9D874CA47E)\

</div>

<div>

sample 2-4:

</div>

<div>

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603295708/D6CD89C950A86309B2B04CD3C9D46BEA)\
sample 3-1:

</div>

<div>

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603302675/ACB5FAE62F0B664AD09A0D33FBC69341)\
sample 3-2:

</div>

<div>

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603309509/C60733D4ABD780EE730D67973686F7B5)\

</div>

<div>

\

</div>

