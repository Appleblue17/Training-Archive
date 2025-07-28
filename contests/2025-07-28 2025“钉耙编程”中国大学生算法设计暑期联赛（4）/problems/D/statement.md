## D. 取石子游戏

### Problem Description

由于 Serika 是今天的值日生，需要协助老师完成工作，因此现在 Abydos
Countermeasure Committee 的活动室里只有四个人。Ayane 和 Nonomi
制作了一个颇为有趣的取石子游戏，并邀请 Shiroko 和 Hoshino 来体验。

游戏开始前有一个非空正整数 **不可重集合**
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]。桌面上将会摆放
[[$\mid S\mid$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[S]{.mord
.mathnormal
style="margin-right: 0.0576em;"}[∣]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 堆石堆，[[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 中的每一个元素
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
都对应着一堆石子数量为 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的石堆。在游戏中 Shiroko 和 Hoshino
需要交替做出以下操作：

1.  操作者任意选择一堆石堆（设其中石子数量为
    [[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]）与一个正整数
    [[$y$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 满足
    [[$x \geq y$][[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[x]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 且 [[$x$][[[]{.strut
    style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 与
    [[$y$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 的最大公约数为
    [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  从选择的石堆中取出 [[$y$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}]
    个石子（若石堆中的石子此时被取光，也就是
    [[$x = y$][[[]{.strut
    style="height: 0.4306em;"}[x]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，则这堆石堆将不复存在）。

游戏由 Shiroko
先手。若轮到某人操作时桌面上不存在任何石堆，那么此人落败，另一人获胜。

为了增加难度，Ayane 和 Nonomi 制订了一些额外规则。Ayane 给定了一个
**有特殊性质** 的大整数 [[$N$][[[]{.strut
style="height: 0.6833em;"}[N]{.mord .mathnormal
style="margin-right: 0.109em;"}]{.base}]{.katex-html
aria-hidden="true"}]，Nonomi 给定了一个 **有特殊性质**
的正整数集合 [[$R$][[[]{.strut
style="height: 0.6833em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}]{.base}]{.katex-html
aria-hidden="true"}]。具体性质见 输入/输出格式。她们希望
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 满足其中的所有元素均大于
[[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 且它们的乘积为
[[$N$][[[]{.strut style="height: 0.6833em;"}[N]{.mord
.mathnormal style="margin-right: 0.109em;"}]{.base}]{.katex-html
aria-hidden="true"}]，并且
[[$S \cap R = \varnothing$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[]{.mspace
style="margin-right: 0.2222em;"}[∩]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6633em; vertical-align: -0.0817em;"}[∅]{.mord
.amsrm}]{.base}]{.katex-html aria-hidden="true"}]。

假设 Shiroko 和 Hoshino
总是按照最优策略玩游戏。现在，你需要计算分别有多少个满足上述条件的
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 使得在游戏中 Shiroko 和 Hoshino
各自必胜，答案对 [[$1000000007$][[[]{.strut
style="height: 0.6444em;"}[1000000007]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模。

### Input

**本题包含多组测试数据。**

**来自 Ayane 和 Nonomi 的温馨提示：本题输入输出量较大，对于使用 C++
语言参加竞赛的选手，强烈建议使用关闭同步流的 cin 和 cout
完成输入输出。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
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

对于每一组测试数据，输入包含四行。

第一行包含一个整数 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 18$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[18]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示 [[$N$][[[]{.strut
style="height: 0.6833em;"}[N]{.mord .mathnormal
style="margin-right: 0.109em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的质因子个数。

第二行包含 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个质数
[[$p_{1},p_{2},p_{3},\cdots,p_{n}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$2 \leq p_{1} < p_{2} < p_{3} < \cdots < p_{n} \leq 10^{7}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[3]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5782em; vertical-align: -0.0391em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[n]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[7]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示 [[$N$][[[]{.strut
style="height: 0.6833em;"}[N]{.mord .mathnormal
style="margin-right: 0.109em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的质因子序列。

第三行包含一个整数 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$0 \leq m \leq 2^{n}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6644em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示集合
[[$R$][[[]{.strut style="height: 0.6833em;"}[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的大小。

第四行包含 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个整数
[[$a_{1},a_{2},a_{3},\cdots,a_{m}$][[[]{.strut
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
style="height: 2.7em;"}[[m]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$0 \leq a_{1} < a_{2} < a_{3} < \cdots < a_{m} < 2^{n}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[3]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5782em; vertical-align: -0.0391em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[m]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6644em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.6644em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示集合
[[$R$][[[]{.strut style="height: 0.6833em;"}[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}]{.base}]{.katex-html
aria-hidden="true"}] 每个元素的特殊表示。

**特殊性质：[[$N$][[[]{.strut
style="height: 0.6833em;"}[N]{.mord .mathnormal
style="margin-right: 0.109em;"}]{.base}]{.katex-html
aria-hidden="true"}] 为若干不同质数之积，且集合
[[$R$][[[]{.strut style="height: 0.6833em;"}[R]{.mord
.mathnormal style="margin-right: 0.0077em;"}]{.base}]{.katex-html
aria-hidden="true"}] 中的所有元素均是
[[$N$][[[]{.strut style="height: 0.6833em;"}[N]{.mord
.mathnormal style="margin-right: 0.109em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的因数。**你需要通过以下等式计算
[[$N$][[[]{.strut style="height: 0.6833em;"}[N]{.mord
.mathnormal style="margin-right: 0.109em;"}]{.base}]{.katex-html
aria-hidden="true"}] 与集合 [[$R$][[[]{.strut
style="height: 0.6833em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}]{.base}]{.katex-html
aria-hidden="true"}] 中的元素
[[$x_{i}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq m$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）的值：
[[[$$N = \prod\limits_{j = 1}^{n}p_{j}$$][[[]{.strut
style="height: 0.6833em;"}[N]{.mord .mathnormal
style="margin-right: 0.109em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 3.0652em; vertical-align: -1.4138em;"}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}[=]{.mrel .mtight}[1]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.8723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∏]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}[[]{.pstrut
style="height: 3.05em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -4.3em; margin-left: 0em;"}]{.vlist
style="height: 1.6514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.4138em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[j]{.mord
.mathnormal .mtight style="margin-right: 0.0572em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]
[[[$$x_{i} = \prod\limits_{j = 1}^{n}p_{j}^{\lbrack(a_{i}\text{~bitand~}2^{j - 1}) > 0\rbrack}$$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 3.0652em; vertical-align: -1.4138em;"}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}[=]{.mrel .mtight}[1]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.8723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∏]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}[[]{.pstrut
style="height: 3.05em;"}[[[n]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -4.3em; margin-left: 0em;"}]{.vlist
style="height: 1.6514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.4138em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[j]{.mord
.mathnormal .mtight style="margin-right: 0.0572em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.4231em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[\[(]{.mopen .mtight}[[a]{.mord .mathnormal
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[i]{.mord .mathnormal
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}[[ ]{.mtight}]{.mspace
.mtight}[[bitand]{.mord .mtight}]{.mord .text
.mtight}[[ ]{.mtight}]{.mspace .mtight}[[2]{.mord
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[[j]{.mord .mathnormal
.mtight style="margin-right: 0.0572em;"}[−]{.mbin .mtight}[1]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.931em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.9021em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[)]{.mclose .mtight}[\>]{.mrel .mtight}[0]{.mord
.mtight}[\]]{.mclose .mtight}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -3.2198em; margin-right: 0.05em;"}]{.vlist
style="height: 1.1513em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.413em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]] 其中
[[$\text{bitand}$][[[]{.strut
style="height: 0.6944em;"}[[bitand]{.mord}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]
表示二进制按位与，[[$\lbrack P\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[P]{.mord
.mathnormal
style="margin-right: 0.1389em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 的值根据条件
[[$P$][[[]{.strut style="height: 0.6833em;"}[P]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的真假决定，若
[[$P$][[[]{.strut style="height: 0.6833em;"}[P]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 为真，则
[[$\lbrack P\rbrack = 1$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[P]{.mord
.mathnormal style="margin-right: 0.1389em;"}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，否则
[[$\lbrack P\rbrack = 0$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[P]{.mord
.mathnormal style="margin-right: 0.1389em;"}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每一组测试数据，输出包含一行两个整数表示使得在游戏中 Shiroko 和
Hoshino 各自必胜的 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的数量对
[[$1000000007$][[[]{.strut
style="height: 0.6444em;"}[1000000007]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的值。

### Sample Input

```plain
2
5
2 5 7 13 19
0

9
2 3 5 7 11 13 17 19 23
2
4 6
```

### Sample Output

```plain
51 1
14749 1381
```

### Hint

在样例的第一组测试数据中，使得在游戏中 Hoshino 必胜的
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 仅有一个，满足
[[$S = \{ 17290\}$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[17290]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。而剩余的 [[$51$][[[]{.strut
style="height: 0.6444em;"}[51]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个满足条件的
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 均会使得在游戏中 Shiroko 必胜。

**请注意代码的常数。**

