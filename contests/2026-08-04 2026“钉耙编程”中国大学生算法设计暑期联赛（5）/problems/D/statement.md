## D. 探索宝物

### Problem Description

玩家准备探索一个神秘房间，最多可以进行 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 次探索。每次探索会消耗
[[$c$][[[]{.strut style="height: 0.4306em;"}[c]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个金币，并随机生成一个宝物。宝物的价值是
[[$\lbrack 1,m\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 中的一个整数。对于价值为
[[$v$][[[]{.strut style="height: 0.4306em;"}[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的宝物，其出现概率为
[[$P_{v}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[P]{.mord
.mathnormal style="margin-right: 0.1389em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[v]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1389em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

一开始，玩家身上没有宝物。每次探索后，玩家会看到新生成宝物的价值。此时玩家可以选择：
- 替换当前宝物，即丢弃旧宝物，拿走新宝物；
- 保留当前宝物，即丢弃新宝物。

之后，玩家可以继续消耗金币进行下一次探索，也可以立即结束探险，带着当前身上的宝物离开。

玩家的最终收益定义为最终带走的宝物价值减去探索消耗的金币总数。玩家也可以在尚未进行任何探索时直接结束探险，此时收益为
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

请你求出在最优策略下，玩家最终收益的期望最大值。

### Input

第一行一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 200$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[200]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示数据组数。

对于每组数据，第一行包含三个整数 [[$n,m,c$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[c]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 10^{9},1 \leq m \leq 10^{5},0 \leq c \leq 10^{9}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
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
style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[c]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），分别表示最多探索次数、宝物价值上限、每次探索消耗的金币数。

第二行包含 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个非负整数
[[$w_{1},w_{2},\ldots,w_{m}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[w]{.mord
.mathnormal style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[m]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$0 \leq w_{v} \leq 10^{9}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.786em; vertical-align: -0.15em;"}[[w]{.mord .mathnormal
style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[v]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）。其中价值为
[[$v$][[[]{.strut style="height: 0.4306em;"}[v]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]
的宝物出现概率为：[[$P_{v} = \frac{w_{v}}{\sum_{i = 1}^{m}w_{i}}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[P]{.mord
.mathnormal style="margin-right: 0.1389em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[v]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1389em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.2815em; vertical-align: -0.57em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[[∑]{.mop
.op-symbol .small-op .mtight
style="position: relative; top: 0em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.1786em; margin-left: 0em; margin-right: 0.0714em;"}[[]{.pstrut
style="height: 2.5em;"}[[[m]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.8971em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.7047em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3214em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop .mtight}[]{.mspace .mtight
style="margin-right: 0.1952em;"}[[w]{.mord .mathnormal .mtight
style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: -0.0269em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[[w]{.mord .mathnormal .mtight
style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[v]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: -0.0269em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.1645em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -3.4101em;"}]{.vlist
style="height: 0.7115em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.57em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。保证
[[$\sum_{i = 1}^{m}w_{i}\operatorname{}(10^{9} + 7) \neq 0$][[[]{.strut
style="height: 1.104em; vertical-align: -0.2997em;"}[[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.4003em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[m]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.2029em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8043em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2997em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[[w]{.mord .mathnormal
style="margin-right: 0.0269em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0269em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[7]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[[[[[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
.vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

对于所有数据，满足 [[$\sum m \leq 10^{6}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

输出一个整数，表示在最优策略下，玩家最终收益的期望最大值对
[[$10^{9} + 7$][[[]{.strut
style="height: 0.8974em; vertical-align: -0.0833em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[7]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
取模后的结果。可以证明这个最大值是一个有理数，设为
[[$\frac{p}{q}$][[[]{.strut
style="height: 1.2286em; vertical-align: -0.4811em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[q]{.mord
.mathnormal .mtight style="margin-right: 0.0359em;"}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[p]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.4461em;"}]{.vlist
style="height: 0.7475em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.4811em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，你需要输出
[[$p \cdot q^{- 1}\operatorname{}(10^{9} + 7)$][[[]{.strut
style="height: 0.6389em; vertical-align: -0.1944em;"}[p]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[−]{.mord .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[7]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，其中
[[$q^{- 1}$][[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[−]{.mord .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 在模
[[$10^{9} + 7$][[[]{.strut
style="height: 0.8974em; vertical-align: -0.0833em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[7]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 意义下的逆元。

### Sample Input

```plain
2
2 3 0
1 1 1
2 6 1
1 1 1 1 1 1
```

### Sample Output

```plain
444444450
861111120
```

