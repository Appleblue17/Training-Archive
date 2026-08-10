## K. 树形广播

### Problem Description

一座大型研究基地铺设了一套树形通信网络。网络中有
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个中继节点，编号为 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 到 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，任意两个节点之间都存在唯一的通信路径。每个节点都带有一块状态显示屏，开机时显示值均为
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

令 [[${dist}(u,v)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[dist]{.mord
.mathrm}]{.mop}[(]{.mopen}[u]{.mord .mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 表示节点 [[$u$][[[]{.strut
style="height: 0.4306em;"}[u]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 与节点 [[$v$][[[]{.strut
style="height: 0.4306em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]
之间唯一通信路径上的边数，也就是它们之间的跳数。调度中心可以从某个节点发出「分层广播」：处在不同距离的节点，会根据距离得到不同的显示值。

你需要处理 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 次操作：
- [[$\texttt{1}\ \texttt{v}\ \texttt{l}\ \texttt{r}\ \texttt{k}$][[[]{.strut
    style="height: 0.6111em;"}[[1 v l r k]{.mord .texttt}]{.mord
    .text}]{.base}]{.katex-html aria-hidden="true"}]
    [[$w_{0}\ w_{1}\ \ldots\ w_{k}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[ ]{.mspace}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] \-\-- 从节点
    [[$v$][[[]{.strut style="height: 0.4306em;"}[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 发出一次广播。对于每个满足
    [[[$$l \leq {dist}(u,v) \leq r$$][[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[dist]{.mord
    .mathrm}]{.mop}[(]{.mopen}[u]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[)]{.mclose}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}]] 的节点
    [[$u$][[[]{.strut style="height: 0.4306em;"}[u]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]，令
    [[$d = {dist}(u,v)$][[[]{.strut
    style="height: 0.6944em;"}[d]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[dist]{.mord
    .mathrm}]{.mop}[(]{.mopen}[u]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，并将其显示值覆盖为
    [[[$$\left( \sum\limits_{i = 0}^{k}w_{i}d^{i} \right)\operatorname{}998244353.$$][[[]{.strut
    style="height: 3.1138em; vertical-align: -1.2777em;"}[[[(]{.delimsizing
    .size4}]{.mopen .delimcenter style="top: 0em;"}[[[[[[]{.pstrut
    style="height: 3.05em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
    .mtight}[0]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -1.8723em; margin-left: 0em;"}[[]{.pstrut
    style="height: 3.05em;"}[∑]{.mop .op-symbol
    .large-op}]{style="top: -3.05em;"}[[]{.pstrut
    style="height: 3.05em;"}[[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -4.3em; margin-left: 0em;"}]{.vlist
    style="height: 1.8361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 1.2777em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
    .op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[[d]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8747em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[[)]{.delimsizing
    .size4}]{.mclose .delimcenter style="top: 0em;"}]{.minner}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[[[mod]{.mord
    .mathrm}]{.mord}]{.mbin}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[998244353.]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]] 多项式次数满足
    [[$0 \leq k \leq 10$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[10]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
    系数按照次数从低到高的顺序给出：[[$w_{0}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    是常数项系数，一般地，[[$w_{i}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 是 [[$d^{i}$][[[]{.strut
    style="height: 0.8247em;"}[[d]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8247em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的系数。
    公式中的所有运算（包括乘方、乘法与求和）都在模
    [[$998244353$][[[]{.strut
    style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 意义下进行。
- [[$\texttt{2}\ \texttt{x}$][[[]{.strut
    style="height: 0.6111em;"}[[2 x]{.mord .texttt}]{.mord
    .text}]{.base}]{.katex-html aria-hidden="true"}] \-\--
    查看节点 [[$x$][[[]{.strut
    style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的当前显示值。

显示屏不会把新结果与旧结果相加。每次广播都会直接**覆盖**范围内节点原有的显示值。因此，如果多次广播都能影响同一个节点，只有时间最晚的那一次决定它当前显示的内容。

节点是否受到一次广播影响，只由它与广播中心的跳数决定。范围外的节点保持不变；若不存在跳数位于
[[$\lbrack l,r\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 内的节点，则该次广播不会改变任何显示值。

### Input

第一行包含一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 10$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[10]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示这个单一输入文件中包含的测试场景组数。

每组场景的第一行包含两个整数 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n,q \leq 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），分别表示中继节点数和操作数。

接下来 [[$n - 1$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含两个整数
[[$a$][[[]{.strut style="height: 0.4306em;"}[a]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 和
[[$b$][[[]{.strut style="height: 0.6944em;"}[b]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq a,b \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[a]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，[[$a \neq b$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[a]{.mord
.mathnormal}[]{.mspace style="margin-right: 0.2778em;"}[[[[[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
.vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6944em;"}[b]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），表示节点
[[$a$][[[]{.strut style="height: 0.4306em;"}[a]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 与节点
[[$b$][[[]{.strut style="height: 0.6944em;"}[b]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
之间有一条双向通信线路。给出的所有线路构成一棵树。

接下来 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行按照以下格式之一描述一次操作：
- [[$\texttt{1}\ \texttt{v}\ \texttt{l}\ \texttt{r}\ \texttt{k}$][[[]{.strut
    style="height: 0.6111em;"}[[1 v l r k]{.mord .texttt}]{.mord
    .text}]{.base}]{.katex-html aria-hidden="true"}]
    [[$w_{0}\ w_{1}\ \ldots\ w_{k}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[ ]{.mspace}[]{.mspace
    style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
    style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq v \leq n$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$0 \leq l \leq r \leq n - 1$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
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
    style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$0 \leq k \leq 10$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[10]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$0 \leq w_{i} < 998244353$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6891em; vertical-align: -0.15em;"}[[w]{.mord
    .mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]）\-\-- 从节点
    [[$v$][[[]{.strut style="height: 0.4306em;"}[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 发出一次分层广播。 该操作中恰好给出
    [[$k + 1$][[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 个系数。
- [[$\texttt{2}\ \texttt{x}$][[[]{.strut
    style="height: 0.6111em;"}[[2 x]{.mord .texttt}]{.mord
    .text}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq x \leq n$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[x]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]）\-\-- 查看节点
    [[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的当前显示值。

保证所有测试场景的 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 之和不超过
[[$10^{6}$][[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 之和不超过
[[$10^{6}$][[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每组测试场景中每次类型为 [[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
的操作，单独输出一行一个整数，表示所查询节点显示屏上的当前数值。

答案按照输入中的操作顺序连续输出，不要在两组测试场景之间输出空行。

### Sample Input

```plain
2
5 9
1 2
2 3
2 4
4 5
2 3
1 2 1 2 0 7
2 2
2 5
1 5 1 3 1 2 3
2 4
2 3
2 1
2 5
6 9
1 2
1 3
3 4
3 5
5 6
1 3 0 2 2 1 2 3
2 6
1 1 1 1 0 0
2 3
2 4
1 2 2 4 10 1 0 0 0 0 0 0 0 0 0 1
2 3
2 6
2 2
```

### Sample Output

```plain
0
0
7
5
11
11
7
17
0
6
1025
1048577
0
```

