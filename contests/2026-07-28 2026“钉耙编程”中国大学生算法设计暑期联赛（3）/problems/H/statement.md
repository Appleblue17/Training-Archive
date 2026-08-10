## H. FWT

### Problem Description

现在有 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个数字，其中
[[$\forall i \in \lbrack 1,n\rbrack\text{，}x_{1}\& x_{i} = x_{i},x_{i}\& x_{n} = x_{n}$][[[]{.strut
style="height: 0.7335em; vertical-align: -0.0391em;"}[∀]{.mord}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}[\]]{.mclose}[，]{.mord .cjk_fallback}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[&]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[x]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[&]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[n]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[n]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

现在再给定 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个条件 [[$a,b$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[a]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]，表示
[[$x_{a}\& x_{b} = x_{b}$][[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[a]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[&]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[b]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[b]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

现在在给定两个整数 [[$l,r$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}]，所有 [[$x$][[[]{.strut
style="height: 0.4306em;"}[x]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 在
[[$\lbrack l,r\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 范围内。现在想求合法
[[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 数量。

现在很善变，他会多次询问，每次反转 [[$l$][[[]{.strut
style="height: 0.6944em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}]{.base}]{.katex-html
aria-hidden="true"}] 或者 [[$r$][[[]{.strut
style="height: 0.4306em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的某一位，他想在每次修改后再次得到答案。

现在是谁。

### Input

第一行输入一个正整数
[[$T\text{（}1 \leq T \leq 5\text{）}$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[（]{.mord
.cjk_fallback}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[5]{.mord}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]，表示数据组数。

对于每组数据，数据第一行三个正整数
[[$n,m,t\text{（}3 \leq n \leq 20,0 \leq m \leq \text{（}n - 2\text{）} \times \text{（}n - 3\text{）},1 \leq t \leq 10^{5}\text{）}$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[m]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[t]{.mord .mathnormal}[（]{.mord
.cjk_fallback}[3]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[20]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7667em; vertical-align: -0.0833em;"}[（]{.mord
.cjk_fallback}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7667em; vertical-align: -0.0833em;"}[2]{.mord}[）]{.mord
.cjk_fallback}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7667em; vertical-align: -0.0833em;"}[（]{.mord
.cjk_fallback}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[3]{.mord}[）]{.mord
.cjk_fallback}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[t]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html aria-hidden="true"}]。

接下来 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 组
[[$\text{（}a,b\text{）}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[（]{.mord
.cjk_fallback}[a]{.mord .mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[b]{.mord .mathnormal}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html aria-hidden="true"}]。

接下来两行，每行一个正整数，分别表示
[[$l,r\text{（}1 \leq l \leq r \leq 2^{100000}\text{）}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[（]{.mord
.cjk_fallback}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[100000]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html aria-hidden="true"}]
的二进制形式，

接下来 [[$t$][[[]{.strut
style="height: 0.6151em;"}[t]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，给出
[[$op,i$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[o]{.mord
.mathnormal}[p]{.mord .mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，[[$op = 0$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[o]{.mord
.mathnormal}[p]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 时表示反转 [[$l$][[[]{.strut
style="height: 0.6944em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的二进制从左到右第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
位（最高位为第一位）；[[$op = 1$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[o]{.mord
.mathnormal}[p]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 时反转 [[$r$][[[]{.strut
style="height: 0.4306em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}].

### Output

每组数据输出 [[$t + 1$][[[]{.strut
style="height: 0.6984em; vertical-align: -0.0833em;"}[t]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 行，第一行输出没有修改时候的答案，接下来
[[$t$][[[]{.strut style="height: 0.6151em;"}[t]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
行分别输出每次修改后的答案。答案对 998244353 取模。

### Sample Input

```plain
1
3 1 2
1 2
10
110
0 1
1 2
```

### Sample Output

```plain
13
37
19
```

### Hint

对于样例，在没有修改的情况下，所有的合法对是（2,2,2）,（3,2,2）,（3,3,2）,（3,3,3）,（4,4,4）,
（5,4,4）, （5,5,4）,（5,5,5）, （6,2,2）, （6,4,4）, （6,6,2）,
（6,6,4）, （6,6,6）。

