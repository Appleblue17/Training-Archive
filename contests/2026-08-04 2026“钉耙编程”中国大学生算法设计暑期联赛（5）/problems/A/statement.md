## A. 简单多项式问题

### Problem Description

[https://acm.hdu.edu.cn/downloads/2026杭电多校5-题目集new2.pdf](https://acm.hdu.edu.cn/downloads/2026%E6%9D%AD%E7%94%B5%E5%A4%9A%E6%A0%A15-%E9%A2%98%E7%9B%AE%E9%9B%86new2.pdf)

给定非负整数 [[$n,m,a,b,c$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[a]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[c]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。定义一列函数
[[$f_{k}\ (x)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[x]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 如下：

[[[$$f_{0}(x) = 1$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[(]{.mopen}[x]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

[[[$$f_{k}(x) = \sum\limits_{i = 0}^{x}(ai^{2} + bi + c)f_{k - 1}(i)\qquad(k \geq 1)$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[(]{.mopen}[x]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 2.9291em; vertical-align: -1.2777em;"}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[0]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.8723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∑]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}[[]{.pstrut
style="height: 3.05em;"}[[[x]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -4.3em; margin-left: 0em;"}]{.vlist
style="height: 1.6514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.2777em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[(]{.mopen}[a]{.mord .mathnormal}[[i]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8641em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[bi]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[c]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.1667em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[−]{.mbin .mtight}[1]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2083em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[(]{.mopen}[i]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 2em;"}[(]{.mopen}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≥]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]]

请你对于每个整数 [[$k \in \lbrack 0,n\rbrack$][[[]{.strut
style="height: 0.7335em; vertical-align: -0.0391em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，求出
[[$f_{k}\ (m)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[m]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 的值。

由于答案可能很大，你只需要输出它们对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的结果。

### Input

第一行输入一个数代表数据组数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]
（[[$1 \leq T \leq 10$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[10]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）。

对于每组数据，输入一行包含五个整数
[[$n,m,a,b,c$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[a]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[c]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 10^{5},1 \leq a,b,c,m < 998244353$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
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
style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[a]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[c]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）。

### Output

对于每组输入，输出一行，共 [[$n + 1$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个整数。

第 [[$k + 1$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个整数表示
[[$f_{k}\ (m)\operatorname{}998244353$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[m]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的值，其中
[[$0 \leq k \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。相邻两个整数之间用一个空格隔开。

### Sample Input

```plain
5
1 1 1 1 1
2 1 1 1 1
9 2 9 1 10
1 10 13 55 73
7 26 210 632 594
```

### Sample Output

```plain
1 4
1 4 13
1 78 4444 228312 11268976 547210848 438767526 651221129 502577246 963625864
1 8833
1 1540080 206229124 966328099 314496902 584769984 53114709 515981297
```

### Hint

已知 [[$a = b = c = 1$][[[]{.strut
style="height: 0.4306em;"}[a]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6944em;"}[b]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[c]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，所以
[[$ai^{2} + bi + c = i^{2} + i + 1$][[[]{.strut
style="height: 0.8974em; vertical-align: -0.0833em;"}[a]{.mord
.mathnormal}[[i]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[bi]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[c]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8974em; vertical-align: -0.0833em;"}[[i]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

由定义，[[$f_{0}\ (x) = 1$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[x]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，因此
[[$f_{0}\ (1) = 1$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

接下来计算
[[$f_{1}\ (1) = \sum_{i = 0}^{1}(i^{2} + i + 1)f_{0}(i)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.2537em; vertical-align: -0.2997em;"}[[∑]{.mop
.op-symbol .small-op
style="position: relative; top: 0em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[0]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.4003em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[1]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.2029em; margin-right: 0.05em;"}]{.vlist
style="height: 0.954em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2997em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[(]{.mopen}[[i]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}[[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[(]{.mopen}[i]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

由于 [[$f_{0}\ (i) = 1$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[i]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，所以
[[$f_{1}\ (1) = (0^{2} + 0 + 1) + (1^{2} + 1 + 1) = 1 + 3 = 4$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[(]{.mopen}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[(]{.mopen}[[1]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

进一步，[[$f_{2}\ (1) = \sum_{i = 0}^{1}(i^{2} + i + 1)f_{1}\ (i)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.2537em; vertical-align: -0.2997em;"}[[∑]{.mop
.op-symbol .small-op
style="position: relative; top: 0em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[0]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.4003em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[1]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.2029em; margin-right: 0.05em;"}]{.vlist
style="height: 0.954em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2997em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[(]{.mopen}[[i]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}[[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[i]{.mord
.mathnormal}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

先求出中间值：[[$f_{1}\ (0) = \sum_{i = 0}^{0}(i^{2} + i + 1)f_{0}\ (i) = 1$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[0]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.2537em; vertical-align: -0.2997em;"}[[∑]{.mop
.op-symbol .small-op
style="position: relative; top: 0em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[0]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.4003em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[0]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.2029em; margin-right: 0.05em;"}]{.vlist
style="height: 0.954em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2997em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[(]{.mopen}[[i]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}[[f]{.mord
.mathnormal style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[i]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$f_{1}\ (1) = 4$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

于是

[[[$$\begin{matrix}
{f_{2}(1)} & {= \ (0^{2} + 0 + 1) \cdot f_{1}\ (0) + \ (1^{2} + 1 + 1) \cdot f_{1}\ (1)} \ & {= 1 \cdot 1 + 3 \cdot 4} \ & {= 13}
\end{matrix}$$][[[]{.strut
style="height: 4.5241em; vertical-align: -2.0121em;"}[[[[[[[[]{.pstrut
style="height: 3em;"}[[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[(]{.mopen}[1]{.mord}[)]{.mclose}]{.mord}]{style="top: -4.6479em;"}[[]{.pstrut
style="height: 3em;"}[]{.mord}]{style="top: -3.1479em;"}[[]{.pstrut
style="height: 3em;"}[]{.mord}]{style="top: -1.6479em;"}]{.vlist
style="height: 2.5121em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 2.0121em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.col-align-r}[[[[[[]{.pstrut
style="height: 3em;"}[[]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[ ]{.mspace}[]{.mspace
style="margin-right: 0.2778em;"}[(]{.mopen}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8641em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[0]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[ ]{.mspace}[]{.mspace
style="margin-right: 0.2222em;"}[(]{.mopen}[[1]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8641em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[1]{.mord}[)]{.mclose}]{.mord}]{style="top: -4.6479em;"}[[]{.pstrut
style="height: 3em;"}[[]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[⋅]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}[4]{.mord}]{.mord}]{style="top: -3.1479em;"}[[]{.pstrut
style="height: 3em;"}[[]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}[13]{.mord}]{.mord}]{style="top: -1.6479em;"}]{.vlist
style="height: 2.5121em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 2.0121em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.col-align-l}]{.mtable}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

所以
[[$f_{0}\ (1) = 1,f_{1}\ (1) = 4,f_{2}\ (1) = 13$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[f]{.mord .mathnormal
style="margin-right: 0.1076em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1076em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[13]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

