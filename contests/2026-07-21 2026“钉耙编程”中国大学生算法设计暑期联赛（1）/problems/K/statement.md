## K. 森林

### Problem Description

设有 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个点的完全图为
[[$K_{n} = (V,E)$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[K]{.mord
.mathnormal style="margin-right: 0.0715em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0715em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[V]{.mord
.mathnormal style="margin-right: 0.2222em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[E]{.mord .mathnormal
style="margin-right: 0.0576em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

给出 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 个 [[$K_{n}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[K]{.mord
.mathnormal style="margin-right: 0.0715em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0715em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的子图
[[$G_{1} = (V,E_{1}),G_{2} = (V,E_{2}),\ldots,G_{k} = (V,E_{k})$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[G]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[V]{.mord
.mathnormal style="margin-right: 0.2222em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[E]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[V]{.mord
.mathnormal style="margin-right: 0.2222em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[E]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[V]{.mord
.mathnormal style="margin-right: 0.2222em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[E]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，满足：
- [[$G_{1},G_{2},\ldots,G_{k}$][[[]{.strut
    style="height: 0.8778em; vertical-align: -0.1944em;"}[[G]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[G]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[G]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[k]{.mord
    .mathnormal .mtight style="margin-right: 0.0315em;"}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 均无环。
- [[$E_{1},E_{2},\ldots,E_{k}$][[[]{.strut
    style="height: 0.8778em; vertical-align: -0.1944em;"}[[E]{.mord
    .mathnormal style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[E]{.mord .mathnormal
    style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[E]{.mord .mathnormal
    style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的大小均为
    [[$m$][[[]{.strut style="height: 0.4306em;"}[m]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]。

记第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个子图 [[$G_{i}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[G]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的第 [[$j$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
aria-hidden="true"}] 条边为
[[$e_{i,j}$][[[]{.strut
style="height: 0.7167em; vertical-align: -0.2861em;"}[[e]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
.mathnormal .mtight}[,]{.mpunct .mtight}[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

定义边集 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 是好的，当且仅当：
- 存在集合 [[$X_{1},X_{2},\ldots,X_{m}$][[[]{.strut
    style="height: 0.8778em; vertical-align: -0.1944em;"}[[X]{.mord
    .mathnormal style="margin-right: 0.0785em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0785em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0785em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[m]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0785em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，满足
    [[$X_{i} \subseteq \bigcup_{j = 1}^{k}\{ e_{j,i}\}$][[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[X]{.mord
    .mathnormal style="margin-right: 0.0785em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0785em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[⊆]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1.4248em; vertical-align: -0.4358em;"}[[⋃]{.mop
    .op-symbol .small-op
    style="position: relative; top: 0em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}[=]{.mrel .mtight}[1]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.4003em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
    style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.2029em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.989em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.4358em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mop}[{]{.mopen}[[e]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[j]{.mord
    .mathnormal .mtight style="margin-right: 0.0572em;"}[,]{.mpunct
    .mtight}[i]{.mord .mathnormal .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[}]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 且
    [[$1 \leq \mid X_{i}\mid \leq C_{i}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[[X]{.mord
    .mathnormal style="margin-right: 0.0785em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0785em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[∣]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[C]{.mord
    .mathnormal style="margin-right: 0.0715em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0715em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，使得
    [[$S = \bigcup_{i = 1}^{m}X_{i}$][[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1.104em; vertical-align: -0.2997em;"}[[⋃]{.mop
    .op-symbol .small-op
    style="position: relative; top: 0em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
    .mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.4003em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
    style="height: 2.7em;"}[[m]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -3.2029em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8043em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2997em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mop}[]{.mspace
    style="margin-right: 0.1667em;"}[[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0785em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 边集 [[$S$][[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 导出的图
    [[$G_{S} = (V,S)$][[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[G]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[S]{.mord
    .mathnormal .mtight style="margin-right: 0.0576em;"}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[V]{.mord
    .mathnormal style="margin-right: 0.2222em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 无环。

求最大的集合 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的大小。

### Input

第一行输入一个正整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(1 \leq T \leq 100)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[100]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示数据组数。接下来输入
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 组数据：

第一行输入三个整数 [[$n,m,k$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(1 \leq n,m,k \leq 100)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[100]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

第二行输入 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个整数表示
[[$C_{1},C_{2},\cdots,C_{m}$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[[C]{.mord
.mathnormal style="margin-right: 0.0715em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0715em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[C]{.mord .mathnormal
style="margin-right: 0.0715em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0715em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[C]{.mord .mathnormal
style="margin-right: 0.0715em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[m]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0715em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(1 \leq C_{i} \leq k)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[C]{.mord
.mathnormal style="margin-right: 0.0715em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0715em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

接下来 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行输入 [[$2m$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}[m]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 个整数
[[$u_{i,1},v_{i,1},\ldots,u_{i,m},v_{i,m}$][[[]{.strut
style="height: 0.7167em; vertical-align: -0.2861em;"}[[u]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
.mathnormal .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[u]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[m]{.mord .mathnormal .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[m]{.mord .mathnormal .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示子图 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的所有 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 条边。

保证所有数据中，[[$\sum n,\sum m,\sum k \leq 200$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[∑]{.mop .op-symbol .small-op
style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[∑]{.mop .op-symbol .small-op
style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[200]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，且
[[$1 \leq u_{i,j},v_{i,j} \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.9221em; vertical-align: -0.2861em;"}[[u]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
.mathnormal .mtight}[,]{.mpunct .mtight}[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

共输出 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行。

对于每组数据，输出一个整数表示答案。

### Sample Input

```plain
2
2 1 1
1
1 2
5 1 3
3
4 1
1 3
1 3
```

### Sample Output

```plain
1
2
```

