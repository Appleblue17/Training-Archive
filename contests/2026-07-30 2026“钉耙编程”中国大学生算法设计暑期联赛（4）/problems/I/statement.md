## I. I. Gather

### Problem Description

有 [[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个互不相同的字符，用 [[$\{ 1,2,\cdots n\}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 编号。

考虑一棵点集为 [[$\{ 1,2,\ldots,n\}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]、以点 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 为根的有标号树。 初始时，点
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
上放有一个仅包含一个字符 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的字符串。

一次「聚拢」操作按照以下方式进行：

1.  选择一个点 [[$u$][[[]{.strut
    style="height: 0.4306em;"}[u]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]；
2.  将点 [[$u$][[[]{.strut
    style="height: 0.4306em;"}[u]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    以及所有与 [[$u$][[[]{.strut
    style="height: 0.4306em;"}[u]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    相邻的点上的非空字符串，按照任意顺序拼接成一个新字符串；
3.  将新字符串放在点 [[$u$][[[]{.strut
    style="height: 0.4306em;"}[u]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    上，并清空所有与 [[$u$][[[]{.strut
    style="height: 0.4306em;"}[u]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    相邻的点上的字符串为空串。

操作序列还需要满足：
- **第一次操作必须选择根 [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；**
- 除第一次操作外，每次参与拼接的字符串中，**至少有一个字符串的长度不小于
    [[$2$][[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；**
- 最终某个点上需要得到一个长度为 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的字符串。

对于一棵树 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]，记 [[$F(T)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[F]{.mord .mathnormal
style="margin-right: 0.1389em;"}[(]{.mopen}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]
为所有合法操作序列能够得到的字典序最小字符串。

现在给定一个 [[$1,2,\ldots,n$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 的排列
[[$p_{1},p_{2},\ldots,p_{n}$][[[]{.strut
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
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，求有多少棵有标号树
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 满足

[[[$$F(T) = p_{1}p_{2}\cdots p_{n}.$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[F]{.mord .mathnormal
style="margin-right: 0.1389em;"}[(]{.mopen}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[.]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

根始终固定为点 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。两棵树只要无向边集不同，就被认为是不同的树。

答案对 [[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模。

**样例解释**

对于第一组数据，两棵合法的树的边集分别为：

``` text
{(1,2),(1,3)}
{(1,2),(2,3)}
```

对于第二组数据，唯一合法的树的边集为：

``` text
{(1,3),(2,3)}
```

**数据范围**
- [[$1 \leq T \leq 10$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
    .mathnormal style="margin-right: 0.1389em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[10]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$2 \leq n \leq 200$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[200]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 对于所有测试数据，[[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    之和不超过 [[$400$][[[]{.strut
    style="height: 0.6444em;"}[400]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
- [[$p_{1},p_{2},\ldots,p_{n}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[n]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 是
    [[$1,2,\ldots,n$][[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的排列。

### Input

输入包含多组测试数据。第一行包含一个整数
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]，表示测试数据组数。

对于每组测试数据：
- 第一行包含一个整数 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]；
- 第二行包含 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个整数 [[$p_{1},p_{2},\ldots,p_{n}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[n]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，保证它们构成
    [[$1,2,\ldots,n$][[[]{.strut
    style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的排列。

### Output

对于每组测试数据，输出一行一个整数，表示满足条件的树的数量对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的结果。

### Sample Input

```plain
3
3
1 2 3
3
1 3 2
4
1 3 4 2
```

### Sample Output

```plain
2
1
3
```

