## C. 括号凸包

### Problem Description

给定二维平面上的 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]
个点，所有点互不相同，且不存在三点共线。每个点上写有一个括号，可能是左括号
[[$\texttt{(}$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[[(]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html
aria-hidden="true"}]，也可能是右括号
[[$\texttt{)}$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[[)]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html
aria-hidden="true"}]。

我们称一个字符串 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]
是一个合法括号序列，当且仅当它可以由如下递归规则生成：
- 空串是一个合法括号序列；
- 如果 [[$A$][[[]{.strut
    style="height: 0.6833em;"}[A]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    是合法括号序列，那么字符串 [[$\texttt{(}$][[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[[(]{.mord
    .texttt}]{.mord .text}]{.base}]{.katex-html
    aria-hidden="true"}] [[$A$][[[]{.strut
    style="height: 0.6833em;"}[A]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    [[$\texttt{)}$][[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[[)]{.mord
    .texttt}]{.mord .text}]{.base}]{.katex-html
    aria-hidden="true"}] 也是合法括号序列；
- 如果 [[$A$][[[]{.strut
    style="height: 0.6833em;"}[A]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 和
    [[$B$][[[]{.strut style="height: 0.6833em;"}[B]{.mord
    .mathnormal style="margin-right: 0.0502em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 都是合法括号序列，那么
    [[$AB$][[[]{.strut
    style="height: 0.6833em;"}[A]{.mord .mathnormal}[B]{.mord
    .mathnormal style="margin-right: 0.0502em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 也是合法括号序列。

例如，[[$\texttt{()}$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[[()]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html
aria-hidden="true"}],
[[$\texttt{(())}$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[[(())]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html
aria-hidden="true"}],
[[$\texttt{()()}$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[[()()]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html aria-hidden="true"}]
都是合法括号序列，而 [[$\texttt{)(}$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[[)(]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html
aria-hidden="true"}],
[[$\texttt{(()}$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[[(()]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html
aria-hidden="true"}],
[[$\texttt{())(}$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[[())(]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html aria-hidden="true"}]
不是合法括号序列。

现在，你需要从给定的点中选出若干个互不相同的点作为顶点，构成一个凸多边形。

在本题中，一个由 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个点
[[$p_{a_{1}},p_{a_{2}},\ldots,p_{a_{m}}$][[[]{.strut
style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
.mathnormal .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[1]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[[a]{.mord .mathnormal .mtight}[[[[[[]{.pstrut
style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[[a]{.mord .mathnormal .mtight}[[[[[[]{.pstrut
style="height: 2.5em;"}[[m]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.1645em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 构成的多边形被称为凸多边形，当且仅当满足：
- [[$m \geq 3$][[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 这些点按照 [[$a_{1},a_{2},\ldots,a_{m}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[m]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的顺序依次连接，并连接
    [[$a_{m}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[m]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 与 [[$a_{1}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    后，形成一个简单多边形（即多边形的边仅在相邻边的端点处相交，不相邻边互不相交）；
- 对于该多边形的每一条边，其余所有顶点都严格位于这条边所在直线的同一侧。

换句话说，所选出的点必须恰好按照它们在自身凸包上的环形顺序排列，并且所有内角都严格小于
[[$180^{\circ}$][[[]{.strut
style="height: 0.6741em;"}[18]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[∘]{.mbin .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6741em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，凸多边形上不存在三点共线。

对于一个凸多边形，任选其边界上的一个顶点作为起点，并沿着多边形边界按顺时针或逆时针方向依次遍历所有顶点，最后回到起点前停止。这样可以得到一个长度为
[[$m$][[[]{.strut style="height: 0.4306em;"}[m]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的括号序列：若当前顶点上写有左括号，则写下
[[$\texttt{(}$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[[(]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html
aria-hidden="true"}]；若当前顶点上写有右括号，则写下
[[$\texttt{)}$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[[)]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html
aria-hidden="true"}]。

你的任务是找到包含左括号的凸多边形，使得对于该多边形上的任意一个写有左括号的顶点，以它作为起点沿多边形边界并以任意方向遍历得到的括号序列都是合法括号序列。但这样的多边形数量很多，所以你决定只计算满足条件的多边形个数对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的结果。

### Input

第一行包含一个整数 [[$T$][[[]{.strut
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
aria-hidden="true"}]），表示数据组数。

每组数据的第一行包含一个整数 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 500$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[500]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示点的数量。

接下来 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含三个整数
[[$x_{i},y_{i},t_{i}$][[[]{.strut
style="height: 0.8095em; vertical-align: -0.1944em;"}[[x]{.mord
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
style="margin-right: 0.1667em;"}[[t]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$0 \leq x_{i},y_{i} \leq 10^{9},t_{i} \in \{ 0,1\}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[[x]{.mord
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
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[t]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]），表示第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个点的坐标和括号类型，其中
[[$t_{i} = 0$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[t]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
表示左括号，[[$t_{i} = 1$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[t]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示右括号。

保证每组数据中所有点互不相同，且不存在三点共线。

保证所有数据的 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 之和不超过
[[$1000$][[[]{.strut
style="height: 0.6444em;"}[1000]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每组数据，输出一行一个整数表示多边形的方案数取模后的结果

### Sample Input

```plain
5
4
1 1 0
2 4 1
3 9 0
4 16 1
5
1 1 0
2 4 0
3 9 0
4 16 1
5 25 1
6
47 58 0
30 23 0
27 34 1
35 7 1
10 30 1
1 25 1
8
10 5 0
10 16 0
1 5 0
24 9 0
6 2 0
6 12 0
7 18 1
3 13 1
1
0 0 0
```

### Sample Output

```plain
1
0
1
0
0
```

