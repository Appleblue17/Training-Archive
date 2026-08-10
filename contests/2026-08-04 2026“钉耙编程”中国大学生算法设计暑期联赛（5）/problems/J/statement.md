## J. 链上 Nim

### Problem Description

在一片古老遗迹的深处，两位旅人发现了一排排风化的石块，相邻的石块之间用生锈的金属环连接。每一排都形成一条**链**，而墙上模糊的刻文将这种游戏称为「链上
Nim」。

一条长度为 [[$L$][[[]{.strut
style="height: 0.6833em;"}[L]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的链包含 [[$L$][[[]{.strut
style="height: 0.6833em;"}[L]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个顶点和
[[$L - 1$][[[]{.strut
style="height: 0.7667em; vertical-align: -0.0833em;"}[L]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 条连边。玩家
[[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
先手，之后两位玩家轮流行动。在每一回合，当前玩家选择一条链，并按照固定的游戏规则在其中进行一次合法操作。这是一个**公平组合游戏**：可以选择的操作只取决于当前局面，而与轮到了哪位玩家无关。无法继续行动的玩家判负。

可惜，刻文中记载具体操作规则的部分已经损坏。两位旅人只知道，根据
Sprague\--Grundy 定理，每条链仍然有唯一的非负整数 **SG
值**。对于每个可能的链长 [[$L$][[[]{.strut
style="height: 0.6833em;"}[L]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，记一条该长度链的 SG 值为
[[$G_{L}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[G]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[L]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

一场游戏可以在若干条非空、彼此独立的链上同时进行。每次行动只会影响玩家选中的那一条链。因此，若一个局面中各条链的长度为
[[$L_{1},L_{2},\ldots,L_{C}$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[[L]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[L]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[L]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[C]{.mord .mathnormal .mtight
style="margin-right: 0.0715em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，那么整个局面的 SG 值等于各条链 SG 值的
**Nim 和**，也就是按位异或和：

[[[$$G_{L_{1}}\operatorname{}G_{L_{2}}\operatorname{}\cdots\operatorname{}G_{L_{C}}.$$][[[]{.strut
style="height: 0.9334em; vertical-align: -0.2501em;"}[[G]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[L]{.mord
.mathnormal .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[1]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[[[xor]{.mord
.mathtt}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.9334em; vertical-align: -0.2501em;"}[[G]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[L]{.mord
.mathnormal .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[2]{.mord
.mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[[[xor]{.mord
.mathtt}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.2222em;"}[[[xor]{.mord
.mathtt}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.9336em; vertical-align: -0.2503em;"}[[G]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[L]{.mord
.mathnormal .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[C]{.mord
.mathnormal .mtight style="margin-right: 0.0715em;"}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.3567em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3448em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1433em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2503em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

一位新人曾经旁观了 [[$K$][[[]{.strut
style="height: 0.6833em;"}[K]{.mord .mathnormal
style="margin-right: 0.0715em;"}]{.base}]{.katex-html
aria-hidden="true"}]
个历史局面。对于每场过去的游戏，他记下了局面中所有链的长度，并向熟悉游戏的玩家询问了整个局面的
SG 值。然而，他并不知道每个 [[$G_{L}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[G]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[L]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 分别是多少。

现在，他又遇到了 [[$Q$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[Q]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个新局面，并想知道：

**「只使用笔记中的历史记录，能否唯一确定这个局面的 SG 值？」**

如果根据历史记录能够唯一确定这个局面的 SG
值，就输出这个值；如果无法确定，就输出
[[$- 1$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[−]{.mord}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

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
aria-hidden="true"}]），表示测试用例的数量。

接下来依次描述 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 组测试用例。对于每组测试用例：

第一行包含一个整数 [[$K$][[[]{.strut
style="height: 0.6833em;"}[K]{.mord .mathnormal
style="margin-right: 0.0715em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq K \leq 100$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[K]{.mord
.mathnormal style="margin-right: 0.0715em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[100]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示历史局面数量。

接下来的 [[$K$][[[]{.strut
style="height: 0.6833em;"}[K]{.mord .mathnormal
style="margin-right: 0.0715em;"}]{.base}]{.katex-html
aria-hidden="true"}] 个历史局面均恰好用两行描述：
- 第一行包含两个整数 [[$C$][[[]{.strut
    style="height: 0.6833em;"}[C]{.mord .mathnormal
    style="margin-right: 0.0715em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 和 [[$S$][[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq C \leq 100$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8193em; vertical-align: -0.136em;"}[C]{.mord
    .mathnormal style="margin-right: 0.0715em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[100]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$0 \leq S \leq 10^{4}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8193em; vertical-align: -0.136em;"}[S]{.mord
    .mathnormal style="margin-right: 0.0576em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]），分别表示链的数量和该局面的已知 SG
    值。
- 第二行恰好包含 [[$C$][[[]{.strut
    style="height: 0.6833em;"}[C]{.mord .mathnormal
    style="margin-right: 0.0715em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 个整数
    [[$L_{1},L_{2},\ldots,L_{C}$][[[]{.strut
    style="height: 0.8778em; vertical-align: -0.1944em;"}[[L]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[L]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[L]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[C]{.mord
    .mathnormal .mtight style="margin-right: 0.0715em;"}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq L_{i} \leq 100$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[L]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[100]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]），表示以顶点数计算的各条链的长度。

接下来一行包含一个整数 [[$Q$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[Q]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq Q \leq 100$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[Q]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[100]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示询问数量。

接下来的 [[$Q$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[Q]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个询问均恰好用两行描述：
- 第一行包含一个整数 [[$D$][[[]{.strut
    style="height: 0.6833em;"}[D]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq D \leq 100$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8193em; vertical-align: -0.136em;"}[D]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[100]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]），表示链的数量。
- 第二行恰好包含 [[$D$][[[]{.strut
    style="height: 0.6833em;"}[D]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 个整数
    [[$R_{1},R_{2},\ldots,R_{D}$][[[]{.strut
    style="height: 0.8778em; vertical-align: -0.1944em;"}[[R]{.mord
    .mathnormal style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[R]{.mord .mathnormal
    style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[R]{.mord .mathnormal
    style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[D]{.mord .mathnormal .mtight
    style="margin-right: 0.0278em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq R_{i} \leq 100$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8333em; vertical-align: -0.15em;"}[[R]{.mord
    .mathnormal style="margin-right: 0.0077em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0077em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[100]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]），表示以顶点数计算的各条链的长度。

链长可以以任意顺序给出，也可以重复。所有被描述的局面都不为空。

### Output

对于每组测试用例中的每个询问，输出一行一个整数。

### Sample Input

```plain
1
2
2 5
1 2
2 6
2 3
5
2
1 2
2
1 3
1
1
2
4 4
1
4
```

### Sample Output

```plain
5
3
-1
0
-1
```

