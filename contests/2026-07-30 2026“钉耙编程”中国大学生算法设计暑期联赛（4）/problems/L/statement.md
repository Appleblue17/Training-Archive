## L. L. Yet Another Suffix Array Problem

### Problem Description

**题目描述**

给定一个长度为 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的小写字母字符串
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]，以及 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 次询问。

每次询问给出两个整数 [[$l,r$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}]。令：

[[[$$T = S_{l}S_{l + 1}\cdots S_{r},$$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8917em; vertical-align: -0.2083em;"}[[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[l]{.mord .mathnormal .mtight
style="margin-right: 0.0197em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[l]{.mord .mathnormal .mtight
style="margin-right: 0.0197em;"}[+]{.mbin .mtight}[1]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2083em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[r]{.mord .mathnormal .mtight
style="margin-right: 0.0278em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0576em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}]{.base}]{.katex-html
aria-hidden="true"}]]

并记 [[$q = r - l + 1$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

考虑 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的所有非空后缀。令
[[$SA_{T}\lbrack 1\rbrack,SA_{T}\lbrack 2\rbrack,\ldots,SA_{T}\lbrack q\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\[]{.mopen}[1]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\[]{.mopen}[2]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\[]{.mopen}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]
表示这些后缀按字典序从小到大排列后的起点，其中起点按照
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 内从 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
开始的编号。如果一个字符串是另一个字符串的前缀，较短的字符串字典序更小。

定义 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的 `height` 数组：

[[[$${height}_{T}\lbrack 1\rbrack = 0,$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[[height]{.mord
.mathrm}]{.mop}[[[[[[]{.pstrut style="height: 2.7em;"}[[T]{.mord
.mathnormal .mtight style="margin-right: 0.1389em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.4559em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2342em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2441em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[\[]{.mopen}[1]{.mord}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}]{.base}]{.katex-html
aria-hidden="true"}]]

对于每个 [[$2 \leq i \leq q$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]：

[[[$$height_{T}\lbrack i\rbrack = LCP\lbrack T_{SA_{T}\lbrack i - 1\rbrack}\cdots T_{q},T_{SA_{T}\lbrack i\rbrack}\cdots T_{q}\rbrack.$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[h]{.mord
.mathnormal}[e]{.mord .mathnormal}[i]{.mord .mathnormal}[g]{.mord
.mathnormal style="margin-right: 0.0359em;"}[h]{.mord
.mathnormal}[[t]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\[]{.mopen}[i]{.mord
.mathnormal}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.1052em; vertical-align: -0.3552em;"}[L]{.mord
.mathnormal}[CP]{.mord .mathnormal
style="margin-right: 0.1389em;"}[\[]{.mopen}[[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[S]{.mord .mathnormal .mtight
style="margin-right: 0.0576em;"}[[A]{.mord .mathnormal
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[T]{.mord .mathnormal
.mtight style="margin-right: 0.1389em;"}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.3567em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3448em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1433em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}[\[]{.mopen .mtight}[i]{.mord
.mathnormal .mtight}[−]{.mbin .mtight}[1]{.mord .mtight}[\]]{.mclose
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.5198em; margin-left: -0.1389em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3448em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3552em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[q]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1389em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[S]{.mord .mathnormal .mtight
style="margin-right: 0.0576em;"}[[A]{.mord .mathnormal
.mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[T]{.mord .mathnormal
.mtight style="margin-right: 0.1389em;"}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.3567em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3448em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1433em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}[\[]{.mopen .mtight}[i]{.mord
.mathnormal .mtight}[\]]{.mclose .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.5198em; margin-left: -0.1389em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3448em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.3552em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[q]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1389em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\]]{.mclose}[.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

其中 [[$LCP$][[[]{.strut
style="height: 0.6833em;"}[[LCP]{.mord
.mathrm}]{.mop}]{.base}]{.katex-html aria-hidden="true"}]
表示两个字符串的最长公共前缀长度。

令：

[[[$$H = \underset{2 \leq i \leq q}{\max}{height}_{T}\lbrack i\rbrack.$$][[[]{.strut
style="height: 0.6833em;"}[H]{.mord .mathnormal
style="margin-right: 0.0813em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.6138em; vertical-align: -0.8638em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[2]{.mord .mtight}[≤]{.mrel .mtight}[i]{.mord
.mathnormal .mtight}[≤]{.mrel .mtight}[q]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -2.3723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3em;"}[max]{.mop}]{style="top: -3em;"}]{.vlist
style="height: 0.4306em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.8638em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[[height]{.mord
.mathrm}]{.mop}[[[[[[]{.pstrut style="height: 2.7em;"}[[T]{.mord
.mathnormal .mtight style="margin-right: 0.1389em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.4559em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2342em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2441em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[\[]{.mopen}[i]{.mord
.mathnormal}[\]]{.mclose}[.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

如果有多个下标 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 满足
[[${height}_{T}\lbrack i\rbrack = H$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[[height]{.mord
.mathrm}]{.mop}[[[[[[]{.pstrut style="height: 2.7em;"}[[T]{.mord
.mathnormal .mtight style="margin-right: 0.1389em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.4559em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2342em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2441em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[\[]{.mopen}[i]{.mord
.mathnormal}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[H]{.mord .mathnormal
style="margin-right: 0.0813em;"}]{.base}]{.katex-html
aria-hidden="true"}]，取其中最小的
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]。

对于每次询问，求 [[$H$][[[]{.strut
style="height: 0.6833em;"}[H]{.mord .mathnormal
style="margin-right: 0.0813em;"}]{.base}]{.katex-html
aria-hidden="true"}]，以及
[[$SA_{T}\lbrack i - 1\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\[]{.mopen}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 和
[[$SA_{T}\lbrack i\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\[]{.mopen}[i]{.mord
.mathnormal}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 对应的两个后缀在原字符串
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 中的起点。**两个起点的输出顺序必须与
[[$SA_{T}$][[[]{.strut
style="height: 0.8333em; vertical-align: -0.15em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 中的顺序相同。**每次询问保证
[[$H > 0$][[[]{.strut
style="height: 0.7224em; vertical-align: -0.0391em;"}[H]{.mord
.mathnormal style="margin-right: 0.0813em;"}[]{.mspace
style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

**样例解释**

对于第一次询问，[[$T = \texttt{banana}$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6111em;"}[[banana]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html
aria-hidden="true"}]。其后缀数组中的原串起点依次为：

[[[$$6,4,2,1,5,3,$$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[6]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}]{.base}]{.katex-html
aria-hidden="true"}]]

对应的 `height` 数组为：

[[[$$0,1,3,0,0,2.$$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

最大值为 [[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，最早在起点
[[$4$][[[]{.strut
style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 和起点 [[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 对应的相邻后缀之间取得。

第二次询问中，[[$T = \texttt{banan}$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6111em;"}[[banan]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]。后缀 `an`
是后缀 `anan` 的前缀，因此起点 [[$4$][[[]{.strut
style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 排在起点 [[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 之前，答案为 `2 4 2`。

**数据范围**
- [[$1 \leq T \leq 5$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
    .mathnormal style="margin-right: 0.1389em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
- [[$2 \leq n \leq 2 \times 10^{5}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
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
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
- [[$1 \leq m \leq 2 \times 10^{5}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
- [[$1 \leq l  0$][[[]{.strut
    style="height: 0.7224em; vertical-align: -0.0391em;"}[H]{.mord
    .mathnormal style="margin-right: 0.0813em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
- 所有测试数据的 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    之和不超过 [[$4 \times 10^{5}$][[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[4]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
- 所有测试数据的 [[$m$][[[]{.strut
    style="height: 0.4306em;"}[m]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    之和不超过 [[$4 \times 10^{5}$][[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[4]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]

### Input

输入包含多组测试数据。第一行包含一个整数
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 5$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示测试数据组数。

对于每组测试数据：

第一行包含两个整数 [[$n,m$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$2 \leq n \leq 2 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
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
aria-hidden="true"}]，[[$1 \leq m \leq 2 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
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
aria-hidden="true"}]）。

第二行包含一个长度为 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的小写字母字符串
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]。

接下来 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含两个整数
[[$l,r$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq l < r \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7335em; vertical-align: -0.0391em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），表示一次询问。

保证每个询问子串中至少有一个字符出现两次。

### Output

对于每次询问，输出一行三个整数：

[[[$$H,\quad l + SA_{T}\lbrack i - 1\rbrack - 1,\quad l + SA_{T}\lbrack i\rbrack - 1.$$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[H]{.mord
.mathnormal style="margin-right: 0.0813em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 1em;"}[]{.mspace
style="margin-right: 0.1667em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\[]{.mopen}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 1em;"}[]{.mspace
style="margin-right: 0.1667em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[[A]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\[]{.mopen}[i]{.mord
.mathnormal}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

其中 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 是满足
[[${height}_{T}\lbrack i\rbrack = H$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[[height]{.mord
.mathrm}]{.mop}[[[[[[]{.pstrut style="height: 2.7em;"}[[T]{.mord
.mathnormal .mtight style="margin-right: 0.1389em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.4559em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2342em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2441em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[\[]{.mopen}[i]{.mord
.mathnormal}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[H]{.mord .mathnormal
style="margin-right: 0.0813em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的最小下标。

### Sample Input

```plain
1
6 3
banana
1 6
1 5
2 4
```

### Sample Output

```plain
3 4 2
2 4 2
1 4 2
```

