## A. 电子带负电

### Problem Description

*2025/7/27
经过激烈的讨论，我们认为电子应当带负电。因此，给此题中的序列添加 负数
的提案被严肃驳回，因为这些负号被电子夺走了。电子好闪，拜谢电子！*

给定一个长度为 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的 **非负整数** 序列
[[$a_{1},a_{2},a_{3},\cdots,a_{n}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[a]{.mord
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
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
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
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

定义函数 [[$f\ (l,r,L,R)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[ ]{.mspace}[(]{.mopen}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[L]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，其中
[[$l,r,L,R$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[L]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}]{.base}]{.katex-html
aria-hidden="true"}]
均为整数，[[$1 \leq l \leq r \leq n$][[[]{.strut
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
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，[[$- n \leq L \leq R \leq n$][[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[−]{.mord}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[L]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。其值根据以下方法得到：

1.  将所有满足 [[$l \leq i \leq r$][[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    是整数）且 [[$L \leq a_{i} \leq R$][[[]{.strut
    style="height: 0.8193em; vertical-align: -0.136em;"}[L]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.786em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6833em;"}[R]{.mord .mathnormal
    style="margin-right: 0.0077em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 的 [[$a_{i}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 依照它们在
    [[$a_{1},a_{2},a_{3},\cdots,a_{n}$][[[]{.strut
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
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[3]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[n]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 中的顺序取出，组成一个新序列
    [[$b_{1},b_{2},b_{3},\cdots,b_{x}$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[b]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[b]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[b]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[3]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[b]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[x]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，其中 [[$x$][[[]{.strut
    style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    为新序列的长度。
2.  若 [[$x > 0$][[[]{.strut
    style="height: 0.5782em; vertical-align: -0.0391em;"}[x]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，则
    [[$f\ (l,r,L,R)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[f]{.mord .mathnormal
    style="margin-right: 0.1076em;"}[ ]{.mspace}[(]{.mopen}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[L]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
    style="margin-right: 0.0077em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 的值为 [[$b$][[[]{.strut
    style="height: 0.6944em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的最大子段和，否则
    [[$f\ (l,r,L,R) = - \infty$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[f]{.mord .mathnormal
    style="margin-right: 0.1076em;"}[ ]{.mspace}[(]{.mopen}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[L]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
    style="margin-right: 0.0077em;"}[)]{.mclose}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6667em; vertical-align: -0.0833em;"}[−]{.mord}[∞]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

求出函数 [[$f$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}]{.base}]{.katex-html
aria-hidden="true"}]
的最大值。同时求出达到这个最大值的不同函数参数的组数对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的值。

### Input

**本题包含多组测试数据。**

**来自电子的温馨提示：本题输入输出量较大，对于使用 C++
语言参加竞赛的选手，强烈建议使用关闭同步流的 cin 和 cout
完成输入输出。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
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
aria-hidden="true"}]）表示测试数据组数。

对于每一组测试数据，输入包含两行。

第一行包含一个整数 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 2 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
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
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示序列的长度。

第二行包含 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个整数
[[$a_{1},a_{2},a_{3},\cdots,a_{n}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[a]{.mord
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
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
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
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$0 \leq a_{1},a_{2},a_{3},\cdots,a_{n} \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[[a]{.mord
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
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
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
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）表示序列的元素。

### Output

对于每一组测试数据，输出包含一行两个整数表示初始时函数的最大值和达到它的不同函数参数组数对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的值。

**注意：输出函数最大值时不应当进行取模。**对于每一组测试数据，可以证明函数
[[$f$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的最大值均为非负整数。

### Sample Input

```plain
2
3
0 2 1
5
0 0 0 0 0
```

### Sample Output

```plain
3 20
0 540
```

### Hint

在样例的第一组测试数据中，最大值为 [[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。满足
[[$l \leq 2$][[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$r = 3$][[[]{.strut
style="height: 0.4306em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$L \leq 1$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[L]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$R \geq 2$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
的函数参数均可达到最大值，结合函数的定义域可得组数为
[[$2 \times 1 \times 5 \times 2 = 20$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[20]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

在样例的第二组测试数据中，最大值为 [[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。满足
[[$L \leq 0$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[L]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$R \geq 0$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
的函数参数均可达到最大值，结合函数的定义域可得组数为
[[$15 \times 6 \times 6 = 540$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[15]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[6]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[6]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[540]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

