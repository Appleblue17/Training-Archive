## B. Mon2tr

### Problem Description

**请注意本题特殊的空间限制。**

*"生命野蛮蓬勃，大地千变万化。人造机器轰鸣运作，源石能的光辉照亮了暗影。人们挣扎在暗处，向往光明，在辉煌时轻视阴影，如是反复。"*

给定一棵由编号为 [[$1,2,3,\cdots,n$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的点构成的有根树。记 [[$d_{i}$][[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[d]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示编号为 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）的点到树根的唯一简单路径上的
**点数**（对于树根本身，这个值为 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）。

现在有 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 次询问。第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq q$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]）次询问给定整数
[[$x_{i},y_{i},z_{i}$][[[]{.strut
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
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。对于整数 [[$j$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq j \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），定义
[[$v_{j} = d_{\text{LCA}(j,x_{i})}$][[[]{.strut
style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0496em; vertical-align: -0.3552em;"}[[d]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[LCA]{.mord
.mtight}]{.mord .text .mtight}[(]{.mopen .mtight}[j]{.mord .mathnormal
.mtight style="margin-right: 0.0572em;"}[,]{.mpunct .mtight}[[x]{.mord
.mathnormal .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}[)]{.mclose .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.5198em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3448em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3552em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，其中
[[$\text{LCA}(u,v)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[LCA]{.mord}]{.mord
.text}[(]{.mopen}[u]{.mord .mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 表示编号分别为
[[$u,v$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[u]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的点的最近公共祖先的编号。

对于第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq q$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]）次询问，求满足
[[$j - v_{j} \leq y_{i} \leq j \leq j + v_{j} \leq z_{i}$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.9221em; vertical-align: -0.2861em;"}[[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
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
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.9221em; vertical-align: -0.2861em;"}[[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[z]{.mord
.mathnormal style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的整数 [[$j$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq j \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）中，[[$j + v_{j}$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的最大值。如果
[[$y_{i} > z_{i}$][[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[z]{.mord
.mathnormal style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 或者不存在符合条件的整数，答案为
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Input

**本题包含多组测试数据。**

**来自 Kal\'tsit
的温馨提示：本题输入输出量较大，请使用合适的输入输出方式。你可以使用下面链接中给出的输入输出模板。同时请选手注意代码的时间和空间常数消耗，常数过大，例如滥用
C++ STL 容器的代码不保证能够通过。**

<https://www.luogu.me/paste/y4lm88ha>

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 3.5 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[3.5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

对于每一组测试数据，输入包含 [[$q + 2$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 行。

第一行包含两个整数 [[$n,q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 8 \times 10^{4},1 \leq q \leq 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[8]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$1 \leq \sum n \leq 3.5 \times 10^{5},1 \leq \sum q \leq 5 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[3.5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），分别表示树上点的数量和询问的次数。

第二行包含 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个整数
[[$fa_{1},fa_{2},fa_{3},\cdots,fa_{n}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$0 \leq fa_{1},fa_{2},fa_{3},\cdots,fa_{n} \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）表示每个点的父亲编号。若
[[$fa_{i} = 0$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）则表示编号为
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的点为树根。

接下来 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，第 [[$i + 2$][[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq q$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]）行包含三个整数
[[$x_{i}^{\prime},y_{i}^{\prime},z_{i}^{\prime}$][[[]{.strut
style="height: 1.0106em; vertical-align: -0.2587em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.4413em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.4413em; margin-left: -0.0359em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.4413em; margin-left: -0.044em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$0 \leq x_{i}^{\prime},y_{i}^{\prime},z_{i}^{\prime} < 10^{9}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0106em; vertical-align: -0.2587em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.4413em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.4413em; margin-left: -0.0359em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.4413em; margin-left: -0.044em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示与第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
次询问的参数有关的三个数。

对于第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq q$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]）次询问，你需要通过以下操作得到
[[$x_{i},y_{i},z_{i}$][[[]{.strut
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
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]：

1.  记 [[$lans$][[[]{.strut
    style="height: 0.6944em;"}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[an]{.mord .mathnormal}[s]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    表示第 [[$i - 1$][[[]{.strut
    style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 次询问的答案。若
    [[$i = 1$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，则令
    [[$lans = 0$][[[]{.strut
    style="height: 0.6944em;"}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[an]{.mord .mathnormal}[s]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  [[$x_{i} = \lbrack(x_{i}^{\prime} + lans)\operatorname{}n\rbrack + 1$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1.0106em; vertical-align: -0.2587em;"}[\[(]{.mopen}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.4413em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
    style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[an]{.mord .mathnormal}[s]{.mord
    .mathnormal}[)]{.mclose}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[[[mod]{.mord
    .mathrm}]{.mord}]{.mbin}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[n]{.mord
    .mathnormal}[\]]{.mclose}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$y_{i} = \lbrack(y_{i}^{\prime} + lans)\operatorname{}(2n - 1)\rbrack - (n - 1)$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1.0106em; vertical-align: -0.2587em;"}[\[(]{.mopen}[[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.4413em; margin-left: -0.0359em; margin-right: 0.05em;"}[[]{.pstrut
    style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[an]{.mord .mathnormal}[s]{.mord
    .mathnormal}[)]{.mclose}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[[[mod]{.mord
    .mathrm}]{.mord}]{.mbin}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[2]{.mord}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)\]]{.mclose}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$z_{i} = \lbrack(z_{i}^{\prime} + lans)\operatorname{}(2n - 1)\rbrack + 1$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[z]{.mord
    .mathnormal style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1.0106em; vertical-align: -0.2587em;"}[\[(]{.mopen}[[z]{.mord
    .mathnormal style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.4413em; margin-left: -0.044em; margin-right: 0.05em;"}[[]{.pstrut
    style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[an]{.mord .mathnormal}[s]{.mord
    .mathnormal}[)]{.mclose}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[[[mod]{.mord
    .mathrm}]{.mord}]{.mbin}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[2]{.mord}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)\]]{.mclose}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，其中
    [[$\operatorname{}$][[[]{.strut
    style="height: 0.6944em;"}[]{.mspace
    style="margin-right: 0.0556em;"}[[[mod]{.mord
    .mathrm}]{.mord}]{.mord}[]{.mspace
    style="margin-right: 0.0556em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 表示取模，例如
    [[$3\operatorname{}2 = 1,( - 7)\operatorname{}3 = 2$][[[]{.strut
    style="height: 0.6944em;"}[3]{.mord}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[[[mod]{.mord
    .mathrm}]{.mord}]{.mbin}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[(]{.mopen}[−]{.mord}[7]{.mord}[)]{.mclose}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[[[mod]{.mord
    .mathrm}]{.mord}]{.mbin}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

保证输入的是一棵有根树。

### Output

对于每一组测试数据，输出包含 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行。

第 [[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq q$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]）行包含一个整数表示第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
次询问的答案。

### Sample Input

```plain
5
5 5
2 3 4 5 0 
3 428538 54277
3 417360 4017
3 892741 445551
4 964351 433610
4 472928 556419
5 5
2 0 5 3 1 
2 145658 137247
5 616008 743457
3 236233 341788
5 338103 325826
2 722091 315410
5 5
5 0 4 2 3 
1 904355 654626
2 418807 822821
4 45452 454729
5 4372 624796
3 138698 133893
5 5
2 0 1 5 2 
1 698219 122911
5 682494 893039
3 293682 893575
1 804585 301494
5 634397 319946
15 15
5 4 4 9 3 7 9 15 0 3 12 6 9 3 9 
2 305062 35660
3 843437 749658
11 170333 369270
1 311572 416623
8 860851 743360
4 16581 926304
5 369493 824555
6 517688 889937
8 710314 148564
7 21922 973381
13 790964 3688
7 989786 105365
1 359041 27784
6 623431 2814
6 678899 377943
```

### Sample Output

```plain
3
6
0
0
3
0
3
2
0
3
0
0
5
0
0
6
0
0
0
5
0
0
4
0
3
13
7
8
0
17
0
4
0
0
0
```

### Hint

在样例的第一组测试数据中，树的结构如下图所示。

![figure](https://s2.loli.net/2025/07/23/1nl8oH37mUFpzbh.png)

这组测试数据共有 [[$5$][[[]{.strut
style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 次询问。

在第 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
次询问中，[[$x_{1} = 4,y_{1} = - 1,z_{1} = 8$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[−]{.mord}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
style="margin-right: 0.044em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[8]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

1.  若 [[$j = 1$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，则
    [[$j - v_{j} = - 1,j + v_{j} = 3$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[−]{.mord}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[j]{.mord .mathnormal
    style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，满足
    [[$j - v_{j} \leq y_{1} \leq j \leq j + v_{j} \leq z_{1}$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.9221em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.1944em;"}[[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.9221em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[z]{.mord
    .mathnormal style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  若 [[$j = 2$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，则
    [[$j - v_{j} = 0,j + v_{j} = 4$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[j]{.mord .mathnormal
    style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，不满足题意。
3.  若 [[$j = 3$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，则
    [[$j - v_{j} = 1,j + v_{j} = 5$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[j]{.mord .mathnormal
    style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，不满足题意。
4.  若 [[$j = 4$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，则
    [[$j - v_{j} = 2,j + v_{j} = 6$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[j]{.mord .mathnormal
    style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[6]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，不满足题意。
5.  若 [[$j = 5$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，则
    [[$j - v_{j} = 4,j + v_{j} = 6$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[j]{.mord .mathnormal
    style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[v]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[6]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，不满足题意。

因此，答案为 [[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

2.  在第 [[$2$][[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{2} = 2,y_{2} = 2,z_{2} = 7$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[7]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。取
    [[$j = 2/3/4$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[2/3/4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，答案为
    [[$6$][[[]{.strut
    style="height: 0.6444em;"}[6]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
3.  在第 [[$3$][[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{3} = 5,y_{3} = - 3,z_{3} = 4$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[3]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[−]{.mord}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
4.  在第 [[$4$][[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{4} = 5,y_{4} = - 3,z_{4} = 9$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[4]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[−]{.mord}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[9]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
5.  在第 [[$5$][[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{5} = 5,y_{5} = 1,z_{5} = 4$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[5]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。取
    [[$j = 2$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，答案为
    [[$3$][[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

在样例的第五组测试数据中，树的结构如下图所示。

![figure](https://s2.loli.net/2025/07/23/nbq6T7JVsKIuLUp.png)

这组测试数据共有 [[$15$][[[]{.strut
style="height: 0.6444em;"}[15]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 次询问。

1.  在第 [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{1} = 3,y_{1} = - 3,z_{1} = 20$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[−]{.mord}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[20]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  在第 [[$2$][[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{2} = 4,y_{2} = - 13,z_{2} = 9$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[−]{.mord}[13]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[9]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
3.  在第 [[$3$][[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{3} = 12,y_{3} = 2,z_{3} = 14$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[3]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[12]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[14]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。取
    [[$j = 3$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，答案为
    [[$4$][[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
4.  在第 [[$4$][[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{4} = 6,y_{4} = - 14,z_{4} = 14$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[4]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[6]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[−]{.mord}[14]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[14]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
5.  在第 [[$5$][[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{5} = 9,y_{5} = 1,z_{5} = 4$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[5]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[9]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。取
    [[$j = 2$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，答案为
    [[$3$][[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
6.  在第 [[$6$][[[]{.strut
    style="height: 0.6444em;"}[6]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{6} = 8,y_{6} = 11,z_{6} = 19$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[6]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[8]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[11]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[19]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。取
    [[$j = 12$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[12]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，答案为
    [[$13$][[[]{.strut
    style="height: 0.6444em;"}[13]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
7.  在第 [[$7$][[[]{.strut
    style="height: 0.6444em;"}[7]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{7} = 4,y_{7} = 3,z_{7} = 12$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[7]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[7]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[7]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[12]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。取
    [[$j = 5$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，答案为
    [[$7$][[[]{.strut
    style="height: 0.6444em;"}[7]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
8.  在第 [[$8$][[[]{.strut
    style="height: 0.6444em;"}[8]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{8} = 14,y_{8} = 2,z_{8} = 22$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[8]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[14]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[8]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[8]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[22]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。取
    [[$j = 5$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，答案为
    [[$8$][[[]{.strut
    style="height: 0.6444em;"}[8]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
9.  在第 [[$9$][[[]{.strut
    style="height: 0.6444em;"}[9]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{9} = 2,y_{9} = 11,z_{9} = 6$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[9]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[11]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[6]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
10. 在第 [[$10$][[[]{.strut
    style="height: 0.6444em;"}[10]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{10} = 8,y_{10} = 13,z_{10} = 26$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[10]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[8]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[10]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[13]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[10]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[26]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。取
    [[$j = 15$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[15]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，答案为
    [[$17$][[[]{.strut
    style="height: 0.6444em;"}[17]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
11. 在第 [[$11$][[[]{.strut
    style="height: 0.6444em;"}[11]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{11} = 1,y_{11} = - 8,z_{11} = 23$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[11]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[11]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[−]{.mord}[8]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[11]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[23]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
12. 在第 [[$12$][[[]{.strut
    style="height: 0.6444em;"}[12]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{12} = 8,y_{12} = 2,z_{12} = 9$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[12]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[8]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[12]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[12]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[9]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。取
    [[$j = 3$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，答案为
    [[$4$][[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
13. 在第 [[$13$][[[]{.strut
    style="height: 0.6444em;"}[13]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{13} = 6,y_{13} = 11,z_{13} = 7$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[13]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[6]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[13]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[11]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[13]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[7]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
14. 在第 [[$14$][[[]{.strut
    style="height: 0.6444em;"}[14]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{14} = 7,y_{14} = 4,z_{14} = 2$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[14]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[7]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[14]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[14]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
15. 在第 [[$15$][[[]{.strut
    style="height: 0.6444em;"}[15]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    次询问中，[[$x_{15} = 7,y_{15} = - 5,z_{15} = 16$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[15]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[7]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[15]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[−]{.mord}[5]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[z]{.mord .mathnormal
    style="margin-right: 0.044em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[15]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.044em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[16]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

