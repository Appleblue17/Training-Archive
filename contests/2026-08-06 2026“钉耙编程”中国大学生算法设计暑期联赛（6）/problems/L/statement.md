## L. P2P

### Problem Description

月一不小心下了一款大型开放风险软件。

（此处需要一张图）
- -----------------------------------------------------------------------

给定一个大小为 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的有根树，根节点为
[[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。记 [[$f_{i}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 节点的父亲，其中满足
[[$i \in \lbrack 2,n\rbrack$][[[]{.strut
style="height: 0.6986em; vertical-align: -0.0391em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。初始每个点有两个权值
[[$A_{i},B_{i}$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[[A]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。[[$A_{i}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[A]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
初始给出，[[$B_{i}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[B]{.mord
.mathnormal style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 初始为 [[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。现在执行以下操作
[[$998^{244^{353}}$][[[]{.strut
style="height: 0.9869em;"}[99]{.mord}[[8]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[24]{.mord .mtight}[[4]{.mord
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[[353]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.931em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.8913em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.9869em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 次：
- **依次考虑** [[$2 \sim n$][[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[∼]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]，令
    [[$\left. B_{f_{i}}\leftarrow B_{f_{i}} + B_{i} + A_{i} \right.$][[[]{.strut
    style="height: 0.9694em; vertical-align: -0.2861em;"}[[B]{.mord
    .mathnormal style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[[f]{.mord .mathnormal .mtight
    style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: -0.1076em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[←]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.9694em; vertical-align: -0.2861em;"}[[B]{.mord
    .mathnormal style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[[f]{.mord .mathnormal .mtight
    style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: -0.1076em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[B]{.mord
    .mathnormal style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[A]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$\left. B_{i}\leftarrow 0 \right.$][[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[B]{.mord
    .mathnormal style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[←]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

求操作完 [[$998^{244^{353}}$][[[]{.strut
style="height: 0.9869em;"}[99]{.mord}[[8]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[24]{.mord .mtight}[[4]{.mord
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[[353]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.931em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.8913em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.9869em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 次后的
[[${sgn}(B_{1})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[sgn]{.mord
.mathrm}]{.mop}[(]{.mopen}[[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。其中
[[${sgn}(x)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[sgn]{.mord
.mathrm}]{.mop}[(]{.mopen}[x]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 表示 [[$x$][[[]{.strut
style="height: 0.4306em;"}[x]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的符号。若
[[$x = 0$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，则
[[${sgn}(x) = 0$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[sgn]{.mord
.mathrm}]{.mop}[(]{.mopen}[x]{.mord .mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]；否则
[[${sgn}(x) = \frac{\mid x\mid}{x}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[sgn]{.mord
.mathrm}]{.mop}[(]{.mopen}[x]{.mord .mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 2.113em; vertical-align: -0.686em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[x]{.mord
.mathnormal}]{.mord}]{style="top: -2.314em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[∣]{.mord}[x]{.mord
.mathnormal}[∣]{.mord}]{.mord}]{style="top: -3.677em;"}]{.vlist
style="height: 1.427em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.686em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Input

第一行一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 20$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[20]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

对于每组测试数据：
- 第一行包含一个整数 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$2 \leq n \leq 2 \times 10^{5}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]）。
- 第二行包含 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个整数，表示 [[$A_{i}$][[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[A]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（[[${\mid A_{i}\mid} \leq 10^{9}$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[∣]{.mopen
    .delimcenter style="top: 0em;"}[[A]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[∣]{.mclose .delimcenter
    style="top: 0em;"}]{.minner}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]）。
- 第三行包含 [[$n - 1$][[[]{.strut
    style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 个整数，第
    [[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个表示 [[$f_{i + 1}$][[[]{.strut
    style="height: 0.9028em; vertical-align: -0.2083em;"}[[f]{.mord
    .mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[+]{.mbin
    .mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2083em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq f_{i} \leq n$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[f]{.mord
    .mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 且
    [[$f_{i} \neq i$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[f]{.mord
    .mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[[[[[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
    .vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]）。

对于所有测试数据，保证给定的树以 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 为根。

### Output

对于每组测试数据，输出一行一个整数，表示操作完
[[$998^{244^{353}}$][[[]{.strut
style="height: 0.9869em;"}[99]{.mord}[[8]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[24]{.mord .mtight}[[4]{.mord
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[[353]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.931em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.8913em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.9869em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 次操作后的
[[${sgn}(B_{1})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[sgn]{.mord
.mathrm}]{.mop}[(]{.mopen}[[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0502em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

### Sample Input

```plain
3
5
-5 -1 -1 -2 -7
1 1 5 3
5
5 5 5 9 8
1 1 5 3
5
-1 -2 3 -5 4
1 1 5 3
```

### Sample Output

```plain
-1
1
1
```

