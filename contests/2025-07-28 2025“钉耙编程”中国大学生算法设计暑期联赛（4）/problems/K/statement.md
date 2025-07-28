## K. 统计强连通

### Problem Description

给定一张 **简单有向图** [[$G$][[[]{.strut
style="height: 0.6833em;"}[G]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 包含编号为
[[$1,2,3,\cdots,n$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的点。此图包含 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 条边，编号为
[[$1,2,3,\cdots,m$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]，其中第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq m$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）条边为
[[$\left. u_{i}\rightarrow v_{i} \right.$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[u]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

定义有向图 [[$G^{0}$][[[]{.strut
style="height: 0.8141em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 是一张包含两个编号分别为
[[$1,2$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的点与一条边
[[$\left. 1\rightarrow 2 \right.$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的图。对于整数
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$k \geq 1$][[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），定义有向图
[[$G^{k}$][[[]{.strut
style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 是将
[[$G^{k - 1}$][[[]{.strut
style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[−]{.mbin .mtight}[1]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 中的每一条边使用
[[$G$][[[]{.strut style="height: 0.6833em;"}[G]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
同时替换所得到的图（可见 样例解释 中的参考图）。替换时将
[[$G^{k - 1}$][[[]{.strut
style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[−]{.mbin .mtight}[1]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 中的每一条边的起点视为
[[$G$][[[]{.strut style="height: 0.6833em;"}[G]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 中编号为
[[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的点，终点视为
[[$G$][[[]{.strut style="height: 0.6833em;"}[G]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 中编号为
[[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的点。

具体地，对于正整数 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}]，按下面的方式构造有向图
[[$G^{k}$][[[]{.strut
style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]：

1.  首先使 [[$G^{k}$][[[]{.strut
    style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 中包含与
    [[$G^{k - 1}$][[[]{.strut
    style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}[−]{.mbin .mtight}[1]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 相同数目的点，并给它们分配与
    [[$G^{k - 1}$][[[]{.strut
    style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}[−]{.mbin .mtight}[1]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 相同的编号。此时
    [[$G^{k}$][[[]{.strut
    style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 中不包含任何边。
2.  对于 [[$G^{k - 1}$][[[]{.strut
    style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}[−]{.mbin .mtight}[1]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 中的每条有向边，轮流执行一次添加操作。
3.  给 [[$G^{k}$][[[]{.strut
    style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 中的点重新分配连续正整数编号。

一次对 [[$G^{k - 1}$][[[]{.strut
style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[−]{.mbin .mtight}[1]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 中的有向边
[[$\left. u\rightarrow v \right.$][[[]{.strut
style="height: 0.4306em;"}[u]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的添加操作如下：

1.  在 [[$G^{k}$][[[]{.strut
    style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 中加入 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个新点，并按照图 [[$G$][[[]{.strut
    style="height: 0.6833em;"}[G]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的方式在这 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个新点之间连接 [[$m$][[[]{.strut
    style="height: 0.4306em;"}[m]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    条有向边。设这 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个新点中，与图 [[$G$][[[]{.strut
    style="height: 0.6833em;"}[G]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    中编号为 [[$1,2$][[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的点对应的点的编号分别是
    [[$x,y$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[x]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  在 [[$G^{k}$][[[]{.strut
    style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 中找到编号为
    [[$u,v$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[u]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 的点。合并编号为
    [[$u,x$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[u]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的点、编号为 [[$v,y$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 的点。合并编号为
    [[$a,b$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[a]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的点时，把所有形如
    [[$\left. b\rightarrow\gamma \right.$][[[]{.strut
    style="height: 0.6944em;"}[b]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[γ]{.mord
    .mathnormal style="margin-right: 0.0556em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 的边修改为
    [[$\left. a\rightarrow\gamma \right.$][[[]{.strut
    style="height: 0.4306em;"}[a]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[γ]{.mord
    .mathnormal style="margin-right: 0.0556em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，把所有形如
    [[$\left. \gamma\rightarrow b \right.$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[γ]{.mord
    .mathnormal style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6944em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的边修改为
    [[$\left. \gamma\rightarrow a \right.$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[γ]{.mord
    .mathnormal style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[a]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]。由于不可能出现
    [[$\left. a\rightarrow b \right.$][[[]{.strut
    style="height: 0.4306em;"}[a]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6944em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 与
    [[$\left. b\rightarrow a \right.$][[[]{.strut
    style="height: 0.6944em;"}[b]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[a]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]，所以不需要考虑。允许出现重边。

如果你还是不理解这个过程，可以参考 样例解释 的伪代码。

给定图 [[$G$][[[]{.strut
style="height: 0.6833em;"}[G]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 和非负整数
[[$k^{\prime}$][[[]{.strut
style="height: 0.7519em;"}[[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，计算
[[$G^{k^{\prime}}$][[[]{.strut
style="height: 0.9425em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.931em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.8278em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.9425em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 中的强连通分量的个数。对
[[$1000000007$][[[]{.strut
style="height: 0.6444em;"}[1000000007]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模。

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 100$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[100]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

对于每一组测试数据，输入包含 [[$m + 1$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[m]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 行。

第一行包含三个整数 [[$n,m,k^{\prime}$][[[]{.strut
style="height: 0.9463em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$2 \leq n \leq 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$2 \leq \sum n \leq 3 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$0 \leq m \leq \sum m \leq 10^{6}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$0 \leq k^{\prime} \leq 10^{18}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8879em; vertical-align: -0.136em;"}[[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[18]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），分别表示
[[$G$][[[]{.strut style="height: 0.6833em;"}[G]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
中点与边的数量，以及与计算答案有关的参数。

接下来 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，第 [[$i + 1$][[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq m$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）行包含两个整数
[[$u_{i},v_{i}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[u]{.mord
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
aria-hidden="true"}]（[[$1 \leq u_{i},v_{i} \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[[u]{.mord
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
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）表示一条 [[$G$][[[]{.strut
style="height: 0.6833em;"}[G]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 中的边
[[$\left. u_{i}\rightarrow v_{i} \right.$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[u]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

保证输入的点与边构成一张简单有向图。（即无重边与自环）

### Output

对于每一组测试数据，输出包含一行一个整数表示
[[$G^{k^{\prime}}$][[[]{.strut
style="height: 0.9425em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.931em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.8278em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.9425em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 中强连通分量个数对
[[$1000000007$][[[]{.strut
style="height: 0.6444em;"}[1000000007]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的值。

### Sample Input

```plain
3
3 3 1919810
1 2
2 3
3 1
5 5 2
1 5
1 3
3 4
4 2
2 3
4 4 5
1 3
2 3
3 4
4 3
```

### Sample Output

```plain
1
8
428
```

### Hint

在样例的第二组测试数据中，将 [[$G^{1}$][[[]{.strut
style="height: 0.8141em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 中的每一条边使用
[[$G$][[[]{.strut style="height: 0.6833em;"}[G]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
同时替换的过程如下图所示（其中黑色虚线边表示
[[$G^{1}$][[[]{.strut
style="height: 0.8141em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 中的边
[[$\left. u^{\prime}\rightarrow v^{\prime} \right.$][[[]{.strut
style="height: 0.7519em;"}[[u]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7519em;"}[[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，这条边仅作指示作用，在
[[$G^{2}$][[[]{.strut
style="height: 0.8141em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
中不存在，**仅一部分图中绘制了黑色虚线边**）：

![figure](https://s2.loli.net/2025/07/25/HjYGyMcfSPlnCtA.png)

答案为 [[$8$][[[]{.strut
style="height: 0.6444em;"}[8]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

在这里给出伪代码，伪代码以图 [[$G$][[[]{.strut
style="height: 0.6833em;"}[G]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 和整数 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 作为输入，返回图
[[$G^{k}$][[[]{.strut
style="height: 0.8491em;"}[[G]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]：

![figure](https://s2.loli.net/2025/07/28/cWbgGI5FsfxKmBz.png)

