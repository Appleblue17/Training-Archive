## G. 今晚吃老歌

### Problem Description

许嵩第九张全创作专辑《安泊猜想》于 2026 年 6 月 16
日陆续释出。专辑第四首歌曲名为《老歌》。歌词里写道：

*我惊觉老歌里的细节，可惜已然时隔多年；**唱歌的人早已退隐，没等到红遍；**我懂了老歌扣人心弦，因为来自你的长夜......*

一首老歌之所以动人，往往不仅仅是因为旋律本身有多么抓耳，更是因为它与你生命中的某段时光产生了共鸣。现在，请你想象一个长度为
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的音乐时间轴。有些时间段可能被某些歌曲"覆盖"，意味着在这个时间段你与这些歌曲产生了共鸣。这些覆盖可能彼此交错、堆叠。

你需要处理这个时间轴上的三种操作：
- 操作 1：加入一首歌曲，并将对应的时间段覆盖；
- 操作 2：遗忘某一首覆盖对应时间段的歌曲 ------
    若有多首歌曲覆盖相同的时间段，只遗忘其中一首；
- 操作
    3：给定一段区间，查询假如只保留那些完整落在此区间内的歌曲，那么区间内有多少个时间点恰好被一首歌曲覆盖？

那些"恰好被一首歌曲覆盖"的瞬间，永远留在了我们的长夜里。

**形式化地**，你需要维护一个可重集合
[[$\mathcal{S}$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathcal
style="margin-right: 0.075em;"}]{.base}]{.katex-html
aria-hidden="true"}]，其中每个元素是一个区间
[[$\lbrack L,R\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[L]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq L \leq R \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
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
aria-hidden="true"}]）。初始
[[$\mathcal{S} = \varnothing$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathcal
style="margin-right: 0.075em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6633em; vertical-align: -0.0817em;"}[∅]{.mord
.amsrm}]{.base}]{.katex-html
aria-hidden="true"}]。你需要编写程序处理
[[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 次操作，每次操作给定整数
[[$op,l,r$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[o]{.mord
.mathnormal}[p]{.mord .mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}]。根据 [[$op$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[o]{.mord
.mathnormal}[p]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的值，你需要处理下列三种操作：
- [[$op = 1$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[o]{.mord
    .mathnormal}[p]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（操作 1）：向
    [[$\mathcal{S}$][[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathcal
    style="margin-right: 0.075em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 中加入一个区间
    [[$\lbrack l,r\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]。
- [[$op = 2$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[o]{.mord
    .mathnormal}[p]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（操作 2）：从
    [[$\mathcal{S}$][[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathcal
    style="margin-right: 0.075em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 中删除一个区间
    [[$\lbrack l,r\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]。若有多个这样的区间，只删除其中一个。
- [[$op = 3$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[o]{.mord
    .mathnormal}[p]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（操作 3）：计算，若只保留
    [[$\mathcal{S}$][[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathcal
    style="margin-right: 0.075em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 中满足
    [[$l \leq L \leq R \leq r$][[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
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
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 的区间
    [[$\lbrack L,R\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[L]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
    style="margin-right: 0.0077em;"}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，有多少整数
    [[$l \leq k \leq r$][[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，使得 [[$k$][[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}] **恰好**被一个保留的区间覆盖？

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 3$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

接下来对于每一组测试数据：

第一行包含两个整数 [[$n,q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n,q \leq 5 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
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
aria-hidden="true"}]，[[$\sum n,\sum q \leq 1.5 \times 10^{6}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[∑]{.mop .op-symbol .small-op
style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[1.5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示时间轴的长度与操作数。

接下来 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，第 [[$i + 1$][[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
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
[[$op_{i},l_{i},r_{i}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[o]{.mord
.mathnormal}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq op_{i} \leq 3$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[o]{.mord
.mathnormal}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$1 \leq l_{i} \leq r_{i} \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.786em; vertical-align: -0.15em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），表示第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 次操作。

保证对于每一次操作 2，均存在一首覆盖给定时间段的歌曲。

### Output

对于每一组测试数据，对于每一次操作 3，输出包含一行一个整数表示答案。

### Sample Input

```plain
1
10 11
1 1 8
1 2 6
1 1 8
1 1 3
3 2 5
1 7 10
3 2 8
3 1 10
2 1 8
2 2 6
3 1 10
```

### Sample Output

```plain
0
5
2
5
```

### Hint

对于样例测试数据：
- 对于第一次操作 3，没有被该区间完全包含的歌曲，答案为
    [[$0$][[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 对于第二次操作 3，保留歌曲对应的时间段为
    [[$\lbrack 2,6\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[6]{.mord}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，时间点
    [[$2,3,4,5,6$][[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[6]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 恰好被一首歌曲覆盖，答案为
    [[$5$][[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 对于第三次操作 3，保留歌曲对应的时间段为
    [[$\lbrack 1,8\rbrack,\lbrack 1,8\rbrack,\lbrack 1,3\rbrack,\lbrack 7,10\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[8]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[8]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[3]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[\[]{.mopen}[7]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[10]{.mord}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，时间点
    [[$9,10$][[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[9]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[10]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 恰好被一首歌曲覆盖，答案为
    [[$2$][[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 对于第四次操作 3，保留歌曲对应的时间段为
    [[$\lbrack 1,8\rbrack,\lbrack 1,3\rbrack,\lbrack 7,10\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[8]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[3]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[\[]{.mopen}[7]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[10]{.mord}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，时间点
    [[$4,5,6,9,10$][[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[6]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[9]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[10]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 恰好被一首歌曲覆盖，答案为
    [[$5$][[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

