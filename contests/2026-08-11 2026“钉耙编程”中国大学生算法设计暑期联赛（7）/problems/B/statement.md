## B. 今晚吃……

### Problem Description

今天的比赛结束了！疲惫的 Hare
翻了翻她发布的帖子。"去尝尝这几个月才开门的
[[$s$][[[]{.strut style="height: 0.4306em;"}[s]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
餐厅吧！"看到某参赛选手发布的评论，Hare 决定去探一探这家
[[$s$][[[]{.strut style="height: 0.4306em;"}[s]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
餐厅。她打开地图搜索，却惊奇地发现没有任何一家餐厅的名字和其相匹配。

现在，为了寻找匹配的餐厅，Hare 需要选取 01 字符串
[[$s$][[[]{.strut style="height: 0.4306em;"}[s]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的一个**子序列**并将其拼成字符串
[[$s_{\text{sub}}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[s]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[sub]{.mord
.mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，使得
[[$s_{\text{sub}}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[s]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[sub]{.mord
.mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表达的信息与
[[$s$][[[]{.strut style="height: 0.4306em;"}[s]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
一致。你需要帮助 Hare 计算这个子序列长度的最小可能值。

在本题中，一个 01 字符串 [[$t$][[[]{.strut
style="height: 0.6151em;"}[t]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的信息是指全集
[[$U = \{$][[[]{.strut
style="height: 0.6833em;"}[U]{.mord .mathnormal
style="margin-right: 0.109em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}]{.base}]{.katex-html
aria-hidden="true"}]`00`，`01`，`10`，`11`[[$\}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 的子集 [[$E_{t}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[E]{.mord
.mathnormal style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[t]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2806em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，使得所有
[[$E_{t}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[E]{.mord
.mathnormal style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[t]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2806em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 中的元素都是
[[$t$][[[]{.strut style="height: 0.6151em;"}[t]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的子串，所有 [[$U \smallsetminus E_{t}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[U]{.mord .mathnormal
style="margin-right: 0.109em;"}[]{.mspace
style="margin-right: 0.2222em;"}[∖]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[[E]{.mord
.mathnormal style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[t]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2806em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 中的元素都不是
[[$t$][[[]{.strut style="height: 0.6151em;"}[t]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 的子串。

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 7 \times 10^{4}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[7]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

接下来对于每一组测试数据：

输入的唯一一行包含一个 01 字符串 [[$s$][[[]{.strut
style="height: 0.4306em;"}[s]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$2 \leq \mid s\mid$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[s]{.mord
.mathnormal}[∣]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）。

保证所有测试数据输入的 01 字符串长度之和不超过
[[$3 \times 10^{6}$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每一组测试数据，输出包含一行一个整数表示子序列长度的最小可能值。

### Sample Input

```plain
2
1010100
00011101011010
```

### Sample Output

```plain
4
5
```

### Hint

![figure](https://files.seeusercontent.com/2026/08/08/l2Vs/hint-B.png)

对于第一组测试数据，由上图可知，[[$s_{sub} =$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[s]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[sub]{.mord
.mathrm .mtight}]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}]{.base}]{.katex-html
aria-hidden="true"}] `1001`
是满足条件的子序列。可以证明该情况的长度最小。

