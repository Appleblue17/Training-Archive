## I. 量子弹弓

### Problem Description

帝国控制着 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个脉冲星系，编号为
[[$1,2,3,\cdots,n$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，并给每个星系中安装了一个
**量子弹弓**，编号为 [[$i$][[[]{.strut
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
aria-hidden="true"}]）的星系中的量子弹弓强度为非负整数
[[$p_{i}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。为了增强星系之间的联络，总督希望用
[[$n - 1$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 条 **虫洞通道**
连接这些星系使得它们连通（其中每条虫洞通道的两端连接两个星系），也就是形成一棵树的结构。

量子弹弓可以让飞船由宇宙空间从一个星系穿梭到另一个星系，但有一个重要的前提。具体地，处在编号为
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）的星系中的量子弹弓可以让飞船从该星系
**穿梭** 到编号为 [[$j$][[[]{.strut
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
aria-hidden="true"}]，[[$i\operatorname{=\not{}}j$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[i]{.mord
.mathnormal}[]{.mspace style="margin-right: 0.2778em;"}[[[[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
.vbox}]{.mrel}]{.base}[[]{.strut
style="height: 0.3669em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
aria-hidden="true"}]）的星系，当且仅当在这两个星系之间由虫洞通道构成的唯一简单路径中，虫洞通道的数量不超过这个量子弹弓的强度。

总督现在要求你制定星系间交通联络的方案。你需要构造这样一种建立虫洞通道的方式，和星系间的一个包含每个星系恰好一次的回路，使得飞船从回路上的任意一个星系开始，都能一直穿梭到回路中当前所处星系的后一个星系，最终回到初始所在星系。

由于总督下午就要去参加听证会，他只希望知道是否存在这样的构造。

**形式化地**，你需要判断是否存在一棵由编号为
[[$1,2,3,\cdots,n$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的点构成的树 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 和一个
[[$\lbrack 1,n\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 的排列 [[$a$][[[]{.strut
style="height: 0.4306em;"}[a]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，使得对于所有整数
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），[[$\text{dis}(a_{i},a_{(i\operatorname{}n) + 1}) \leq p_{a_{i}}$][[[]{.strut
style="height: 1.1052em; vertical-align: -0.3552em;"}[[dis]{.mord}]{.mord
.text}[(]{.mopen}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[(]{.mopen .mtight}[i]{.mord .mathnormal
.mtight}[]{.mspace .mtight style="margin-right: 0.3253em;"}[[[mod]{.mord
.mathrm .mtight}]{.mord .mtight}]{.mbin .mtight}[]{.mspace .mtight
style="margin-right: 0.3253em;"}[n]{.mord .mathnormal
.mtight}[)]{.mclose .mtight}[+]{.mbin .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.5198em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3448em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3552em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
.mathnormal .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，其中
[[$\text{dis}(u,v)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[dis]{.mord}]{.mord
.text}[(]{.mopen}[u]{.mord .mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 表示编号为
[[$u,v$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[u]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[v]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的两点在 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]
上的唯一简单路径的边数，[[$\operatorname{}$][[[]{.strut
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

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 10^{6}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

对于每一组测试数据，输入包含两行。

第一行包含一个整数 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$2 \leq n \leq 10^{5},2 \leq \sum n \leq 10^{6}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示脉冲星系数量。

第二行包含 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个整数
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
aria-hidden="true"}]（[[$0 \leq p_{1},p_{2},p_{3},\cdots,p_{n} < n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7335em; vertical-align: -0.1944em;"}[[p]{.mord
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
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）表示每个星系中量子弹弓的强度。

### Output

对于每一组测试数据，输出包含一行。

若不存在满足题意的建立虫洞通道的方式与星系间的一个回路，输出一行包含一个字符串
NO。若存在，输出一行包含一个字符串 YES。

### Sample Input

```plain
5
4
2 1 2 2
5
4 1 1 1 1
5
0 2 0 2 4
6
1 3 1 2 1 1
6
2 2 2 2 1 1
```

### Sample Output

```plain
YES
YES
NO
NO
YES
```

### Hint

这个样例共有五组测试数据。

在第一组测试数据中，可以构造以下的建立虫洞通道的方式以及星系回路
[[$a = \lbrack 1,2,3,4\rbrack$][[[]{.strut
style="height: 0.4306em;"}[a]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

![figure](https://s2.loli.net/2025/07/22/1n46gC7zjGk3cA8.png)

此时：

1.  编号为 [[$a_{1} = 1,a_{2} = 2$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    的星系之间由虫洞通道构成的唯一简单路径中，虫洞通道的数量为
    [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq p_{a_{1}} = 2$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
    .mathnormal .mtight}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[1]{.mord .mtight}]{.sizing .reset-size3
    .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  编号为 [[$a_{2} = 2,a_{3} = 3$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[3]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    的星系之间由虫洞通道构成的唯一简单路径中，虫洞通道的数量为
    [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq p_{a_{2}} = 1$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
    .mathnormal .mtight}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3
    .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
3.  编号为 [[$a_{3} = 3,a_{4} = 4$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[3]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[4]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    的星系之间由虫洞通道构成的唯一简单路径中，虫洞通道的数量为
    [[$2$][[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$2 \leq p_{a_{3}} = 2$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
    .mathnormal .mtight}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[3]{.mord .mtight}]{.sizing .reset-size3
    .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
4.  编号为 [[$a_{4} = 4,a_{1} = 1$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[4]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    的星系之间由虫洞通道构成的唯一简单路径中，虫洞通道的数量为
    [[$2$][[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$2 \leq p_{a_{4}} = 2$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
    .mathnormal .mtight}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[4]{.mord .mtight}]{.sizing .reset-size3
    .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

在第二组测试数据中，可以构造以下的建立虫洞通道的方式以及星系回路
[[$a = \lbrack 2,3,4,5,1\rbrack$][[[]{.strut
style="height: 0.4306em;"}[a]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

![figure](https://s2.loli.net/2025/07/22/RMTBovtPe4yqkan.png)

此时：

1.  编号为 [[$a_{1} = 2,a_{2} = 3$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    的星系之间由虫洞通道构成的唯一简单路径中，虫洞通道的数量为
    [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq p_{a_{1}} = 1$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
    .mathnormal .mtight}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[1]{.mord .mtight}]{.sizing .reset-size3
    .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  编号为 [[$a_{2} = 3,a_{3} = 4$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[3]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    的星系之间由虫洞通道构成的唯一简单路径中，虫洞通道的数量为
    [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq p_{a_{2}} = 1$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
    .mathnormal .mtight}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[2]{.mord .mtight}]{.sizing .reset-size3
    .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
3.  编号为 [[$a_{3} = 4,a_{4} = 5$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[3]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[4]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    的星系之间由虫洞通道构成的唯一简单路径中，虫洞通道的数量为
    [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq p_{a_{3}} = 1$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
    .mathnormal .mtight}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[3]{.mord .mtight}]{.sizing .reset-size3
    .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
4.  编号为 [[$a_{4} = 5,a_{5} = 1$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[4]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[5]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    的星系之间由虫洞通道构成的唯一简单路径中，虫洞通道的数量为
    [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq p_{a_{4}} = 1$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
    .mathnormal .mtight}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[4]{.mord .mtight}]{.sizing .reset-size3
    .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
5.  编号为 [[$a_{5} = 1,a_{1} = 2$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[5]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    的星系之间由虫洞通道构成的唯一简单路径中，虫洞通道的数量为
    [[$4$][[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$4 \leq p_{a_{5}} = 4$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[4]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6807em; vertical-align: -0.2501em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[a]{.mord
    .mathnormal .mtight}[[[[[[]{.pstrut
    style="height: 2.5em;"}[[5]{.mord .mtight}]{.sizing .reset-size3
    .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3173em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2501em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

可以证明，在第三、四组测试数据中，不存在满足题意的建立虫洞通道的方式与星系间的一个回路；在第五组测试数据中，存在满足题意的建立虫洞通道的方式与星系间的一个回路。

