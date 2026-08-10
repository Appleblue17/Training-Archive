## B. 画树

### Problem Description

众所周知，Arisa 是盆栽大王。今天，Arisa 希望在画布上画出利根川的结构。

利根川是一棵有 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个节点的有根二叉树，根的编号固定为
1，保证对于所有节点 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的父结点
[[$f_{i}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 有 [[$f_{i} < i$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。设节点 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的左儿子和右儿子分别为
[[$L_{i}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[L]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$R_{i}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

Arisa 需要给每个节点分配一个**整数坐标**
[[$U_{i} = (x_{i},y_{i}),\left( \mid x_{i}\mid,\mid y_{i}\mid \leq 10^{8} \right)$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[U]{.mord
.mathnormal style="margin-right: 0.109em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.109em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.2em; vertical-align: -0.35em;"}[(]{.mopen}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[(]{.delimsizing
.size1}]{.mord}[∣]{.mord}[[x]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[∣]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[∣]{.mord}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[∣]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.2em; vertical-align: -0.35em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[8]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[[)]{.delimsizing
.size1}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，满足：
- 对于任意两个节点，分配的坐标不能相同；
- 对于所有二叉树中的边 [[$(u,v)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[u]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] [[$(u < v)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[u]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，满足
    [[$y_{u} < y_{v}$][[[]{.strut
    style="height: 0.7335em; vertical-align: -0.1944em;"}[[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[u]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[v]{.mord .mathnormal .mtight
    style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 对于二叉树中任意两条边 [[$(a,b),(c,d)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[a]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[b]{.mord
    .mathnormal}[)]{.mclose}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[(]{.mopen}[c]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[d]{.mord
    .mathnormal}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，线段
    [[$U_{a}U_{b}$][[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[U]{.mord
    .mathnormal style="margin-right: 0.109em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[a]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.109em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[[U]{.mord .mathnormal
    style="margin-right: 0.109em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[b]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.109em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 和
    [[$U_{c}U_{d}$][[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[U]{.mord
    .mathnormal style="margin-right: 0.109em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[c]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.109em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[[U]{.mord .mathnormal
    style="margin-right: 0.109em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[d]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.109em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 不允许相交或重合，但允许共用端点；
- 对于二叉树中任意节点 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的左儿子（若存在）的 [[$x$][[[]{.strut
    style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    坐标必须不大于 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 的
    [[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    坐标；且 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的右儿子（若存在）的 [[$x$][[[]{.strut
    style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    坐标必须不小于 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 的
    [[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    坐标。即
    [[$x_{L_{i}} \leq x_{i} \leq x_{R_{i}}$][[[]{.strut
    style="height: 0.8861em; vertical-align: -0.2501em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[L]{.mord
    .mathnormal .mtight}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.786em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6807em; vertical-align: -0.2501em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[R]{.mord
    .mathnormal .mtight style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: -0.0077em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

然而，画布的大小是有限的。Arisa 使用的画布大小不能超过
**66666666**。即：

[[[$$\left( \underset{i = 1}{\overset{n}{\max}}x_{i} - \underset{i = 1}{\overset{n}{\min}}x_{i} \right) \times \left( \underset{i = 1}{\overset{n}{\max}}y_{i} - \underset{i = 1}{\overset{n}{\min}}y_{i} \right) \leq 66666666$$][[[]{.strut
style="height: 2.4em; vertical-align: -0.95em;"}[[[(]{.delimsizing
.size3}]{.mopen .delimcenter style="top: 0em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.3723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3em;"}[max]{.mop}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.6306em; margin-left: 0em;"}]{.vlist
style="height: 1.032em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.7277em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.3723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3em;"}[min]{.mop}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.8679em; margin-left: 0em;"}]{.vlist
style="height: 1.2693em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.7277em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[[)]{.delimsizing .size3}]{.mclose
.delimcenter style="top: 0em;"}]{.minner}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 2.4em; vertical-align: -0.95em;"}[[[(]{.delimsizing
.size3}]{.mopen .delimcenter style="top: 0em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.3723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3em;"}[max]{.mop}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.6306em; margin-left: 0em;"}]{.vlist
style="height: 1.032em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.7277em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.3723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3em;"}[min]{.mop}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.8679em; margin-left: 0em;"}]{.vlist
style="height: 1.2693em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.7277em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[[)]{.delimsizing .size3}]{.mclose
.delimcenter style="top: 0em;"}]{.minner}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[66666666]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

你需要帮助 Arisa 找到一个坐标分配方案，使得上述所有限制都被满足。

可以证明，在题目给定的数据范围内，对于任意二叉树都一定存在至少一种满足上述所有条件的分配方案。

### Input

本题单个测试点内有多组测试数据。

第一行输入一个正整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(1 \leq T \leq 50)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[50]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示数据组数。

接下来按如下格式输入 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 组数据：

第一行输入一个正整数 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(1 \leq n \leq 10^{5})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示二叉树的节点个数。

接下来输入 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，其中第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行输入两个整数
[[$L_{i}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[L]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
.mathnormal .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$R_{i}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(0 \leq L_{i},R_{i} \leq n)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[[L]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[n]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示节点 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的左儿子和右儿子。若节点
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
没有左儿子，则 [[$L_{i} = 0$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[L]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]；若节点 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 没有右儿子，则
[[$R_{i} = 0$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

保证输入的树是一棵以 1 为根的二叉树。

### Output

对于每组数据：

输出 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，其中第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行输出两个用空格分隔的整数
[[$x_{i},y_{i}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，表示分配给节点
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 的坐标。

你需要保证
[[$\mid x_{i}\mid,\mid y_{i}\mid \leq 10^{8}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[∣]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[∣]{.mord}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[∣]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[8]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

本题使用 Special Judge
进行评测。如有多种满足所有条件的坐标分配方案，你可以输出其中的任意一种。

### Sample Input

```plain
2
7
2 3
4 5
6 7
0 0
0 0
0 0
0 0
4
2 0
0 3
4 0
0 0
```

### Sample Output

```plain
4 0
2 1
6 1
1 2
3 2
5 2
7 2
-1 -1
-1 0
-1 1
-1 2
```

### Hint

下图绘制了样例数据中的两组坐标分配方案。其中第 1 组数据占用的面积为
[[$(7 - 1) \times (2 - 0) = 12$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[7]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[0]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[12]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，第 2 组数据占用的面积为
[[$( - 1 - ( - 1)) \times (2 - ( - 1)) = 0$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[−]{.mord}[1]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[−]{.mord}[1]{.mord}[))]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[−]{.mord}[1]{.mord}[))]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

![](../../../data/images/C1229-1002-1new.jpg)

样例输出仅表示一种可能的答案，并不表示该样例输出恰好对应标准程序的输出。

本题输入输出量较大，建议使用较快速的输入输出方式（如关闭流同步的 `cin` /
`cout`）。

