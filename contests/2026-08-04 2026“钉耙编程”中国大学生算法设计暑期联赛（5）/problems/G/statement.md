## G. 反弹小球

### Problem Description

在一个 [[$n \times m$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的二维整数格点矩形区域内（格点坐标范围为
[[$1 \leq x \leq n,1 \leq y \leq m$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[x]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），依次放入
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 个小球。

每个小球 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的初始状态由初始位置
([[$x_{i},y_{i}$][[[]{.strut
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
aria-hidden="true"}]) 和初始速度向量
([[$v_{x_{i}},v_{y_{i}}$][[[]{.strut
style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[[x]{.mord .mathnormal .mtight}[[[[[[]{.pstrut
style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: -0.0359em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]) 定义，其中
[[$v_{x_{i}},v_{y_{i}} \in \{ - 1,1\}$][[[]{.strut
style="height: 0.8252em; vertical-align: -0.2861em;"}[[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[[x]{.mord .mathnormal .mtight}[[[[[[]{.pstrut
style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[[y]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: -0.0359em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[−]{.mord}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。小球在离散的时间步中运动。在每一个时间步中，小球尝试根据当前速度移动到下一个位置，具体的移动逻辑如下：

1.  **碰撞判定**：对于每一个维度，独立判断在该维度上是否即将运动到台球桌外。
- 如果 [[$1 \leq x + v_{x} \leq n$][[[]{.strut
        style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
        style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 0.6667em; vertical-align: -0.0833em;"}[x]{.mord
        .mathnormal}[]{.mspace
        style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
        style="margin-right: 0.2222em;"}]{.base}[[]{.strut
        style="height: 0.786em; vertical-align: -0.15em;"}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[x]{.mord .mathnormal .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
        style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 0.4306em;"}[n]{.mord
        .mathnormal}]{.base}]{.katex-html
        aria-hidden="true"}]，则水平速度
        [[$v_{x}$][[[]{.strut
        style="height: 0.5806em; vertical-align: -0.15em;"}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[x]{.mord .mathnormal .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}] 保持不变。
- 如果 [[$x + v_{x}  n$][[[]{.strut
        style="height: 0.6667em; vertical-align: -0.0833em;"}[x]{.mord
        .mathnormal}[]{.mspace
        style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
        style="margin-right: 0.2222em;"}]{.base}[[]{.strut
        style="height: 0.6891em; vertical-align: -0.15em;"}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[x]{.mord .mathnormal .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
        style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 0.4306em;"}[n]{.mord
        .mathnormal}]{.base}]{.katex-html
        aria-hidden="true"}]，则该维度的方向发生改变，即
        [[$\left. v_{x}\leftarrow - v_{x} \right.$][[[]{.strut
        style="height: 0.5806em; vertical-align: -0.15em;"}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[x]{.mord .mathnormal .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
        style="margin-right: 0.2778em;"}[←]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 0.7333em; vertical-align: -0.15em;"}[−]{.mord}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[x]{.mord .mathnormal .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}]。
- 垂直维度 [[$y$][[[]{.strut
        style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
        .mathnormal
        style="margin-right: 0.0359em;"}]{.base}]{.katex-html
        aria-hidden="true"}] 同理：如果
        [[$y + v_{y}  m$][[[]{.strut
        style="height: 0.7778em; vertical-align: -0.1944em;"}[y]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[]{.mspace
        style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
        style="margin-right: 0.2222em;"}]{.base}[[]{.strut
        style="height: 0.8252em; vertical-align: -0.2861em;"}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[y]{.mord .mathnormal .mtight
        style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
        style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 0.4306em;"}[m]{.mord
        .mathnormal}]{.base}]{.katex-html
        aria-hidden="true"}]，则
        [[$\left. v_{y}\leftarrow - v_{y} \right.$][[[]{.strut
        style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[y]{.mord .mathnormal .mtight
        style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
        style="margin-right: 0.2778em;"}[←]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 0.8694em; vertical-align: -0.2861em;"}[−]{.mord}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[y]{.mord .mathnormal .mtight
        style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}]。
2.  **位置更新**：在确定了最终的速度方向后，小球移动到新位置
    [[$x + v_{x},y + v_{y})$][[[]{.strut
    style="height: 0.6667em; vertical-align: -0.0833em;"}[x]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7778em; vertical-align: -0.1944em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[x]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1.0361em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[y]{.mord .mathnormal .mtight
    style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]。

**可以前往样例解释以进一步理解具体的运动逻辑。**

不同小球之间相互独立，即使处于同一位置也不会发生碰撞。小球会无限运动下去。对于每个
[[$i \in \{ 1,2,\ldots,k\}$][[[]{.strut
style="height: 0.6986em; vertical-align: -0.0391em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，请你求出：在第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个小球放下后，在无限时间里，至少被一个小球经过的格点数量总和

### Input

第一行包含一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 10^{4}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示测试数据的组数。

对于每组测试数据：
- 第一行包含三个整数 [[$n,m,k$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[m]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$2 \leq n,m \leq 5 \times 10^{5},1 \leq k \leq 5 \times 10^{5}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[m]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]），分别表示网格的宽度、高度和小球的数量。
- 接下来 [[$k$][[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 行，第 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    行包含四个整数
    [[$x_{i},y_{i},v_{x_{i}},v_{y_{i}}$][[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[x]{.mord
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
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[[x]{.mord .mathnormal
    .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[[y]{.mord .mathnormal .mtight
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: -0.0359em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq x_{i} \leq n,1 \leq y_{i} \leq m,v_{x_{i}},v_{y_{i}} \in \{ - 1,1\}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
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
    style="height: 0.8389em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.1944em;"}[[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8252em; vertical-align: -0.2861em;"}[m]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[[x]{.mord .mathnormal
    .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[[y]{.mord .mathnormal .mtight
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: -0.0359em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[−]{.mord}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}[}]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]），表示第
    [[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个小球的初始位置和速度方向。

数据保证所有测试数据的
[[$\sum n,\sum m,\sum k$][[[]{.strut
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
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 均不超过
[[$5 \times 10^{6}$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每组测试数据，输出一行 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 个整数，第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个整数表示加入前
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个小球后，被经过的格点总数。

### Sample Input

```plain
1
3 3 3
2 1 1 1
1 1 1 1
3 1 1 -1
```

### Sample Output

```plain
4 7 9
```

### Hint

在 [[$3 \times 3$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的网格中：

1.  **第 1 个球**从 ([[$2,1$][[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]) 出发，速度为
    ([[$1,1$][[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}])：
- [[$\left. 2,1)\rightarrow 3,2) \right.$][[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}[]{.mspace
        style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]
        （撞右墙，[[$v_{x}$][[[]{.strut
        style="height: 0.5806em; vertical-align: -0.15em;"}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[x]{.mord .mathnormal .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}] 变为
        [[$- 1$][[[]{.strut
        style="height: 0.7278em; vertical-align: -0.0833em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}]）
        [[$\left. \rightarrow 2,3) \right.$][[[]{.strut
        style="height: 0.3669em;"}[→]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]
        （撞上墙，[[$v_{y}$][[[]{.strut
        style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[y]{.mord .mathnormal .mtight
        style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}] 变为
        [[$- 1$][[[]{.strut
        style="height: 0.7278em; vertical-align: -0.0833em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}]）
        [[$\left. \rightarrow 1,2) \right.$][[[]{.strut
        style="height: 0.3669em;"}[→]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]
        （撞左墙，[[$v_{x}$][[[]{.strut
        style="height: 0.5806em; vertical-align: -0.15em;"}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[x]{.mord .mathnormal .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}] 变为
        [[$1$][[[]{.strut
        style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}]）
        [[$\left. \rightarrow 2,1) \right.$][[[]{.strut
        style="height: 0.3669em;"}[→]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]。
- 轨迹点集：[[$\{ 2,1),3,2),2,3),1,2)\}$][[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)}]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]，共 **4** 个点。
2.  **第 2 个球**从 [[$1,1)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 出发，速度为
    [[$1,1)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：
- [[$\left. 1,1)\rightarrow 2,2)\rightarrow 3,3) \right.$][[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}[]{.mspace
        style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[]{.mspace
        style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]
        （双向撞墙，[[$v_{x},v_{y}$][[[]{.strut
        style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
        .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[x]{.mord .mathnormal .mtight}]{.sizing
        .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[[v]{.mord .mathnormal
        style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
        style="height: 2.7em;"}[[y]{.mord .mathnormal .mtight
        style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
        .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
        style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
        style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
        .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
        aria-hidden="true"}] 均取反）
        [[$\left. \rightarrow 2,2)\ldots \right.$][[[]{.strut
        style="height: 0.3669em;"}[→]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[]{.mspace
        style="margin-right: 0.1667em;"}[...]{.minner}]{.base}]{.katex-html
        aria-hidden="true"}]
- 轨迹点集：[[$\{ 1,1),2,2),3,3)\}$][[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[)}]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]。
- 前两个球的并集为
        [[$\{ 2,1),3,2),2,3),1,2),1,1),2,2),3,3)\}$][[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[)}]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]，共 **7** 个点。
3.  **第 3 个球**从 [[$3,1)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 出发，速度为
    [[$1, - 1)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[−]{.mord}[1]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：
- [[$\left. 3,1)\rightarrow 2,2)\rightarrow 1,3)\rightarrow 2,2)\ldots \right.$][[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}[]{.mspace
        style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[]{.mspace
        style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[)]{.mclose}[]{.mspace
        style="margin-right: 0.2778em;"}[→]{.mrel}[]{.mspace
        style="margin-right: 0.2778em;"}]{.base}[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[]{.mspace
        style="margin-right: 0.1667em;"}[...]{.minner}]{.base}]{.katex-html
        aria-hidden="true"}]
- 轨迹点集：[[$\{ 3,1),2,2),1,3)\}$][[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[3]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[3]{.mord}[)}]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}]。注意
        [[$2,2)$][[[]{.strut
        style="height: 1em; vertical-align: -0.25em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
        style="margin-right: 0.1667em;"}[2]{.mord}[)]{.mclose}]{.base}]{.katex-html
        aria-hidden="true"}] 之前已被小球 2 经过。
- 前三个球的并集包含网格内所有 **9** 个格点。

