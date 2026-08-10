## I. 数组

### Problem Description

给定长为 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的序列
[[$A = (a_{1},a_{2},\ldots,a_{n})$][[[]{.strut
style="height: 0.6833em;"}[A]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 和长为 [[$2^{w}$][[[]{.strut
style="height: 0.6644em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[w]{.mord .mathnormal .mtight
style="margin-right: 0.0269em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的数组
[[$H\left\lbrack 0..2^{w} - 1 \right\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[H]{.mord .mathnormal
style="margin-right: 0.0813em;"}[]{.mspace
style="margin-right: -0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[\[]{.mopen .delimcenter
style="top: 0em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[..]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[w]{.mord .mathnormal .mtight
style="margin-right: 0.0269em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[1]{.mord}[\]]{.mclose .delimcenter
style="top: 0em;"}]{.minner}]{.base}]{.katex-html
aria-hidden="true"}]。对于
[[$1 \leq i \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，定义
[[[$$C_{i} = \sum\limits_{1 \leq b_{1},b_{2},\ldots,b_{m} \leq n}H\left\lbrack \left( \sum\limits_{j = 1}^{m}a_{b_{j}} \right)\operatorname{}2^{w} \right\rbrack \cdot \left( \sum\limits_{j = 1}^{m}\lbrack b_{j} = i\rbrack \right)^{k}.$$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[C]{.mord
.mathnormal style="margin-right: 0.0715em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0715em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 3.1882em; vertical-align: -1.4382em;"}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[1]{.mord .mtight}[≤]{.mrel .mtight}[[b]{.mord
.mathnormal .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[1]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}[,]{.mpunct .mtight}[[b]{.mord
.mathnormal .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[2]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}[,]{.mpunct .mtight}[...]{.minner
.mtight}[,]{.mpunct .mtight}[[b]{.mord .mathnormal
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[m]{.mord .mathnormal
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.1645em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}[≤]{.mrel .mtight}[n]{.mord
.mathnormal .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.8479em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∑]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}]{.vlist
style="height: 1.05em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.4382em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[H]{.mord
.mathnormal style="margin-right: 0.0813em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[[\[]{.delimsizing .size4}]{.mopen
.delimcenter style="top: 0em;"}[[[(]{.delimsizing .size4}]{.mopen
.delimcenter style="top: 0em;"}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}[=]{.mrel .mtight}[1]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.8723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∑]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}[[]{.pstrut
style="height: 3.05em;"}[[[m]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -4.3em; margin-left: 0em;"}]{.vlist
style="height: 1.6514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.4138em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[b]{.mord
.mathnormal .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[j]{.mord
.mathnormal .mtight style="margin-right: 0.0572em;"}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2819em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3473em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[[)]{.delimsizing .size4}]{.mclose
.delimcenter style="top: 0em;"}]{.minner}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[w]{.mord .mathnormal .mtight
style="margin-right: 0.0269em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7144em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}\{.delimsizing
.size4}]{.mclose .delimcenter style="top: 0em;"}]{.minner}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 3.4028em; vertical-align: -1.4138em;"}[[[[(]{.delimsizing
.size4}]{.mopen .delimcenter style="top: 0em;"}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}[=]{.mrel .mtight}[1]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.8723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∑]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}[[]{.pstrut
style="height: 3.05em;"}[[[m]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -4.3em; margin-left: 0em;"}]{.vlist
style="height: 1.6514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.4138em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[\[]{.mopen}[[b]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}[i]{.mord
.mathnormal}[\]]{.mclose}[[)]{.delimsizing .size4}]{.mclose .delimcenter
style="top: 0em;"}]{.minner}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -4.2029em; margin-right: 0.05em;"}]{.vlist
style="height: 1.989em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]] 其中，外层求和遍历所有
[[$B = (b_{1},b_{2},\ldots,b_{m})(1 \leq b_{j} \leq n)$][[[]{.strut
style="height: 0.6833em;"}[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[[b]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[b]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[b]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[m]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.9805em; vertical-align: -0.2861em;"}[[b]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[j]{.mord
.mathnormal .mtight style="margin-right: 0.0572em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[n]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，[[$\lbrack \cdot \rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[⋅]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 为艾弗森括号。

求 [[$C_{1},C_{2},\ldots,C_{n}$][[[]{.strut
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
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[C]{.mord .mathnormal
style="margin-right: 0.0715em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0715em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 对 [[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[244]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模的结果。

### Input

第一行输入一个正整数 [[$T(1 \leq T \leq 35)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[35]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示数据组数。接下来按如下格式输入
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 组数据：

第一行输入四个整数
[[$n,w,m,k(1 \leq n \leq 5 \times 10^{5},0 \leq w \leq 19,1 \leq m \leq 10^{9},1 \leq k \leq 20)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[w]{.mord .mathnormal
style="margin-right: 0.0269em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[w]{.mord
.mathnormal style="margin-right: 0.0269em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[19]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[20]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

第二行输入 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个整数表示
[[$A = (a_{1},a_{2},\cdots,a_{n})(0 \leq a_{i} < 2^{w})$][[[]{.strut
style="height: 0.6833em;"}[A]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[w]{.mord .mathnormal .mtight
style="margin-right: 0.0269em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

第三行输入 [[$2^{w}$][[[]{.strut
style="height: 0.6644em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[w]{.mord .mathnormal .mtight
style="margin-right: 0.0269em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个整数表示
[[$H\left\lbrack 0..2^{w} - 1 \right\rbrack(0 \leq h_{i} < 2^{w})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[H]{.mord .mathnormal
style="margin-right: 0.0813em;"}[]{.mspace
style="margin-right: -0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[\[]{.mopen .delimcenter
style="top: 0em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[..]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[w]{.mord .mathnormal .mtight
style="margin-right: 0.0269em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[1]{.mord}[\]]{.mclose .delimcenter
style="top: 0em;"}]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[(]{.mopen}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[h]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[w]{.mord .mathnormal .mtight
style="margin-right: 0.0269em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

保证输入数据中 [[$\sum n,\sum 2^{w}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[∑]{.mop .op-symbol .small-op
style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[w]{.mord .mathnormal .mtight
style="margin-right: 0.0269em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 均不超过
[[$10^{6}$][[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

共 [[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，对于每组数据，输出
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个整数，表示每个数得到的贡献。

### Sample Input

```plain
2
2 2 2 1
0 1
1 1 2 2
4 2 1 1
0 1 2 3
3 3 2 0
```

### Sample Output

```plain
4 6
3 3 2 0
```

### Hint

本题输入输出量较大，建议使用较快速的输入输出方式（如关闭流同步的 `cin` /
`cout`）。

请注意常数因子对程序效率的影响。

