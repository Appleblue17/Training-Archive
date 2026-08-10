## L. 最后一次相遇

### Problem Description

河灵有一条无限长的数轴。初始时，数轴上有
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个小球，第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个小球的初始坐标为
[[$x_{i}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，速度为
[[$v_{i}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

从时刻 [[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
开始，所有小球同时出发，并始终做匀速直线运动。也就是说，一个初始坐标为
[[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 速度为
[[$v$][[[]{.strut style="height: 0.4306em;"}[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的小球，在时刻
[[$t$][[[]{.strut style="height: 0.6151em;"}[t]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
([[$t \geq 0$][[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[t]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]) 的坐标为
[[$x + v \cdot t$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[x]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.4445em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6151em;"}[t]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。

若两个不同的小球在某个时刻 [[$t$][[[]{.strut
style="height: 0.6151em;"}[t]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] ([[$t \geq 0$][[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[t]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]) 位于同一坐标，则认为它们在时刻
[[$t$][[[]{.strut style="height: 0.6151em;"}[t]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
相遇。小球之间的运动相互独立，即使两个小球在某一时刻相遇，它们之后仍会保持原来的速度继续运动。

河灵明白，相遇即是缘分，所以他想请你回答
[[$Q$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[Q]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
次询问。每次询问相互独立，形式如下：
- `l r a b`：加入一个初始坐标为 [[$a$][[[]{.strut
    style="height: 0.4306em;"}[a]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    速度为 [[$b$][[[]{.strut
    style="height: 0.6944em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的临时小球，该小球同样从时刻 [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    开始始终做匀速直线运动。**求临时小球与编号在
    [[$\lbrack l,r\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]
    内的小球发生相遇的所有时刻中的最大值**。特别地，若临时小球与编号在
    [[$\lbrack l,r\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 内的小球均没有相遇，则输出 `-1`。

每次询问结束后，临时小球将会被移除，不会影响其他询问。

**保证不会出现两个初始坐标与速度均相同的小球**，所以任意两个小球至多只会相遇一次。

### Input

每个测试点中包含多组测试数据。输入的第一行包含一个正整数
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]
([[$1 \leq T \leq 5 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}])，表示数据组数。对于每组测试数据：

第一行两个正整数 [[$n,Q$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[Q]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
([[$1 \leq n,Q \leq 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[Q]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}])，表示初始小球的个数以及询问的个数。

接下来 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行两个整数
[[$x_{i},v_{i}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
([[$- 10^{9} \leq x_{i},v_{i} \leq 10^{9}$][[[]{.strut
style="height: 0.9501em; vertical-align: -0.136em;"}[−]{.mord}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}])，表示第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个小球的初始坐标与速度。

接下来 [[$Q$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[Q]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
行，每行四个整数 [[$l,r,a,b$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[a]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
([[$1 \leq l \leq r \leq n, - 10^{9} \leq a,b \leq 10^{9}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[−]{.mord}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[a]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}])，表示一次询问。

**保证不会出现两个初始坐标与速度均相同的小球**。具体地：
- 不存在 [[$1 \leq i < j \leq n$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6986em; vertical-align: -0.0391em;"}[i]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 满足
    [[$x_{i} = x_{j}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[j]{.mord
    .mathnormal .mtight style="margin-right: 0.0572em;"}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 且
    [[$v_{i} = v_{j}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 对于所有询问 [[$l,r,a,b$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[a]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]，不存在
    [[$1 \leq i \leq n$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 满足
    [[$x_{i} = a$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[a]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 且
    [[$v_{i} = b$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6944em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]。

保证所有测试数据中 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 之和与 [[$Q$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[Q]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
之和均不超过 [[$5 \times 10^{5}$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每组测试数据：输出共 [[$Q$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[Q]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 行，第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 行表示第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
次询问的答案。对于每次询问：

若临时小球与编号在 [[$\lbrack l,r\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 内的小球均没有相遇，则输出一个 `-1`。

否则，可以证明答案是一个有理数。你需要输出一个既约分数
[[$x/y$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[x]{.mord
.mathnormal}[/]{.mord}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]，满足 [[$y > 0$][[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 且
[[$\gcd(x,y) = 1$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[g]{style="margin-right: 0.0139em;"}cd]{.mop}[(]{.mopen}[x]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Sample Input

```plain
2
5 4
0 1
10 -1
5 0
-4 2
3 3
1 5 0 0
1 3 20 1
2 5 3 1
1 4 -2 4
10 10
17 -3
-7 11
-7 -18
13 -10
-2 18
-18 8
4 -18
19 19
-16 3
-8 16
3 8 -1 -18
1 3 -8 20
8 10 1 4
2 6 2 -7
4 4 -9 -7
4 5 13 13
3 6 -14 6
8 8 2 4
3 8 18 -13
3 9 -11 16
```

### Sample Output

```plain
10/1
-1
7/1
12/5
17/26
25/23
3/4
11/3
22/3
3/1
2/1
-1
12/7
12/13
```

### Hint

对于第一组测试数据：使用 [[$- 1$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示未相遇。
- 询问 1 的临时小球初始坐标为 [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 速度为 [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，与小球
    [[$1 \sim 5$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[∼]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的相遇时间分别为
    [[$0,10, - 1,2, - 1$][[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[10]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[−]{.mord}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，故答案为 `10/1`。
- 询问 2 的临时小球初始坐标为 [[$20$][[[]{.strut
    style="height: 0.6444em;"}[20]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 速度为 [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，与小球
    [[$1 \sim 3$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[∼]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 均没有相遇，故答案为 `-1`。
- 询问 3 的临时小球初始坐标为 [[$3$][[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 速度为 [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，与小球
    [[$2 \sim 5$][[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[∼]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的相遇时间分别为
    [[$\frac{7}{2},2,7,0$][[[]{.strut
    style="height: 1.1901em; vertical-align: -0.345em;"}[[]{.mopen
    .nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[2]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.655em;"}[[]{.pstrut
    style="height: 3em;"}[]{.frac-line
    style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
    style="height: 3em;"}[[[7]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
    style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.mfrac}[]{.mclose
    .nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[7]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，故答案为 `7/1`。
- 询问 4 的临时小球初始坐标为 [[$- 2$][[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[−]{.mord}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 速度为 [[$4$][[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，与小球
    [[$1 \sim 4$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[∼]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的相遇时间分别为
    [[$\frac{2}{3},\frac{12}{5},\frac{7}{4}, - 1$][[[]{.strut
    style="height: 1.1901em; vertical-align: -0.345em;"}[[]{.mopen
    .nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[3]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.655em;"}[[]{.pstrut
    style="height: 3em;"}[]{.frac-line
    style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
    style="height: 3em;"}[[[2]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
    style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.mfrac}[]{.mclose
    .nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[]{.mopen
    .nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[5]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.655em;"}[[]{.pstrut
    style="height: 3em;"}[]{.frac-line
    style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
    style="height: 3em;"}[[[12]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
    style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.mfrac}[]{.mclose
    .nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[]{.mopen
    .nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[4]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.655em;"}[[]{.pstrut
    style="height: 3em;"}[]{.frac-line
    style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
    style="height: 3em;"}[[[7]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
    style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.mfrac}[]{.mclose
    .nulldelimiter}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，故答案为 `12/5`。

