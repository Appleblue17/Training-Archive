## F. Gcd Master

### Problem Description

给定 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，求

[[[$$\sum\limits_{i = 1}^{n}\sum\limits_{j = i}^{n}\sum\limits_{k = i}^{j}\gcd(i,k)\gcd(j,k)\left( \frac{j}{k} \right)$$][[[]{.strut
style="height: 3.2726em; vertical-align: -1.4138em;"}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.8723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∑]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}[[]{.pstrut
style="height: 3.05em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -4.3em; margin-left: 0em;"}]{.vlist
style="height: 1.6514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.2777em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}[=]{.mrel .mtight}[i]{.mord .mathnormal
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.8723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∑]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}[[]{.pstrut
style="height: 3.05em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -4.3em; margin-left: 0em;"}]{.vlist
style="height: 1.6514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.4138em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[=]{.mrel .mtight}[i]{.mord .mathnormal
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.8479em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∑]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}[[]{.pstrut
style="height: 3.05em;"}[[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -4.3471em; margin-left: 0em;"}]{.vlist
style="height: 1.8588em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.3021em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace
style="margin-right: 0.1667em;"}[[g]{style="margin-right: 0.0139em;"}cd]{.mop}[(]{.mopen}[i]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[)]{.mclose}[]{.mspace
style="margin-right: 0.1667em;"}[[g]{style="margin-right: 0.0139em;"}cd]{.mop}[(]{.mopen}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[)]{.mclose}[[[[(]{.delimsizing
.size3}]{.mopen .delimcenter style="top: 0em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.mord}]{style="top: -2.314em;"}[[]{.pstrut
style="height: 3em;"}[[j]{.mord .mathnormal
style="margin-right: 0.0572em;"}]{.mord}]{style="top: -3.677em;"}]{.vlist
style="height: 1.3365em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.686em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[[)]{.delimsizing .size3}]{.mclose .delimcenter
style="top: 0em;"}]{.mord}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

对 [[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模的结果。

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
aria-hidden="true"}]），表示测试数据的组数。

之后 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含一个整数
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq \sum n \leq 5 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）。

### Output

对于每组测试数据，输出一行一个整数，表示答案。

### Sample Input

```plain
1
5
```

### Sample Output

```plain
298
```

