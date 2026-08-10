## A. runs

### Problem Description

你知道吗，中文里拼音为 \"run\" 的常用字只有 \"润\"，\"闰\"
字多数人只有在鲁迅的文章里以名字的方式见到过。

没了。

定义一个字符串是重串，当前仅当它可以被表示为
[[$u^{k}(k \geq 2)$][[[]{.strut
style="height: 1.0991em; vertical-align: -0.25em;"}[[u]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[k]{.mord
.mathnormal .mtight style="margin-right: 0.0315em;"}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[(]{.mopen}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[2]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 的形式，即将字符串
[[$u$][[[]{.strut style="height: 0.4306em;"}[u]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 连续拼接
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 次。

定义一个字符串 [[$s$][[[]{.strut
style="height: 0.4306em;"}[s]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的划分为一个集合
[[$\{ l_{k},r_{k}\}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，满足
[[$l_{1} = 1,r_{k} = \mid s\mid,l_{i} = r_{i - 1} + 1,l_{i} \leq r_{i}$][[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[s]{.mord
.mathnormal}[∣]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7917em; vertical-align: -0.2083em;"}[[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[−]{.mbin
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2083em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}],
[[$s = s\lbrack l_{1},r_{1}\rbrack + s\lbrack l_{2},r_{2}\rbrack + \cdots + s\lbrack l_{k},r_{k}\rbrack$][[[]{.strut
style="height: 0.4306em;"}[s]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[s]{.mord
.mathnormal}[\[]{.mopen}[[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[s]{.mord
.mathnormal}[\[]{.mopen}[[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[s]{.mord
.mathnormal}[\[]{.mopen}[[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

定义一个字符串 [[$s$][[[]{.strut
style="height: 0.4306em;"}[s]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的一个划分
[[$\{ l_{k},r_{k}\}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 是好的，当且仅当
[[$\forall i,s\lbrack l_{i},r_{i}\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∀]{.mord}[i]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[s]{.mord
.mathnormal}[\[]{.mopen}[[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 不是重串。

给出一个 01 串，求它的好的划分的数量，对 `998244353` 取模。

### Input

第一行一个整数 [[$T\text{（}$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[（]{.mord
.cjk_fallback}]{.base}]{.katex-html aria-hidden="true"}]T\\leq
100[[$\text{）}$][[[]{.strut
style="height: 0.6833em;"}[）]{.mord .cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]，表示数据组数。

接下来 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行一个 01 串，表示询问的字符串
[[$s\text{（}\mid s\mid \leq 10^{6},\sum\mid s\mid \leq 9 \times 10^{6}\text{，}s\lbrack i\rbrack \in \{ 0,1\}\text{）}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[s]{.mord
.mathnormal}[（]{.mord .cjk_fallback}[∣]{.mord}[s]{.mord
.mathnormal}[∣]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[6]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[∑]{.mop .op-symbol .small-op
style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[∣]{.mord}[s]{.mord
.mathnormal}[∣]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[9]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[6]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[，]{.mord
.cjk_fallback}[s]{.mord .mathnormal}[\[]{.mopen}[i]{.mord
.mathnormal}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[}]{.mclose}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html aria-hidden="true"}]。

### Output

对于每组测试数据，输出一行一个整数表示答案

### Sample Input

```plain
5
1
01
001
000100011
1010101010
```

### Sample Output

```plain
1
2
3
71
345
```

