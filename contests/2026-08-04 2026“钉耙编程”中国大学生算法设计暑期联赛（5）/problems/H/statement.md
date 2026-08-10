## H. 病毒片段

### Problem Description

随着网络攻击手段的演变，新型计算机病毒往往具有复杂的变体结构。为了应对这一威胁，某网络安全实验室构建了一个庞大的病毒特征库。库中包含了
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个已知的病毒代码特征片段，每个片段在内存地址空间中可视为一段连续的区间
[[$\lbrack l_{i},r_{i}\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
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
.vlist-t2}]{.msupsub}]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，代表该病毒特征出现的内存起止位置。

为了提高检测效率，实验室开发了一款新型的「区间扫描引擎」。该引擎并不对整个内存进行全量扫描，而是针对可疑的内存区域进行定向分析。

现在，引擎接收到了 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]
次扫描任务。每次任务给出一个待检测的内存区间
[[$\lbrack L,R\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[L]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。为了确保检测的准确性，引擎需要在特征库中寻找一条特征片段
[[$j$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
aria-hidden="true"}]，满足以下条件：

1.  该特征片段必须**完全包含**在待检测区间内，即
    [[$L \leq l_{j}$][[[]{.strut
    style="height: 0.8193em; vertical-align: -0.136em;"}[L]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.9805em; vertical-align: -0.2861em;"}[[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 且
    [[$r_{j} \leq R$][[[]{.strut
    style="height: 0.9221em; vertical-align: -0.2861em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6833em;"}[R]{.mord .mathnormal
    style="margin-right: 0.0077em;"}]{.base}]{.katex-html
    aria-hidden="true"}]。
2.  在所有满足条件 1
    的特征片段中，选择**长度最长**的一个。定义一个片段的长度为
    [[$r_{j} - l_{j} + 1$][[[]{.strut
    style="height: 0.8694em; vertical-align: -0.2861em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.9805em; vertical-align: -0.2861em;"}[[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

对于每次扫描任务，请输出能够匹配到的最长特征片段的长度。如果在该区域内没有任何完整的特征片段，则判定为安全，输出
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Input

第一行输入一个整数 T ([[$1 \leq T \leq 20$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[20]{.mord}]{.base}]{.katex-html
aria-hidden="true"}])，表示数据组数。

对于每组数据，第一行包含两个整数 [[$n,q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n,q \leq 2 \times 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[n]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），分别表示特征库中特征片段的数量和扫描任务的次数。

接下来 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含两个整数
[[$l_{i},r_{i}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
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
aria-hidden="true"}]（[[$1 \leq l_{i} \leq r_{i} \leq 10^{9}$][[[]{.strut
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
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个特征片段的内存区间。

接下来 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含两个整数
[[$L,R$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[L]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq L \leq R \leq 10^{9}$][[[]{.strut
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
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示一次扫描任务的待检测区间。

### Output

对于每次询问，输出一行一个整数，表示在区间
[[$\lbrack L,R\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[L]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]
内完全包含的最长特征片段的长度。若不存在，输出
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Sample Input

```plain
1
5 3
1 5
2 4
3 3
6 8
7 10
1 5
2 6
7 12
```

### Sample Output

```plain
5
3
4
```

### Hint

询问 [[$\lbrack 1,5\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]：
- 片段 1 ([[$\lbrack 1,5\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[5]{.mord}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]) 满足
    [[$1 \leq 1$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 且
    [[$5 \leq 5$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[5]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，包含在内。
- 片段 2 ([[$\lbrack 2,4\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[4]{.mord}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]) 满足
    [[$1 \leq 2$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 且
    [[$4 \leq 5$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[4]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，包含在内。
- 片段 3 ([[$\lbrack 3,3\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[3]{.mord}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]) 满足
    [[$1 \leq 3$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 且
    [[$3 \leq 5$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[3]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，包含在内。
- 最长长度为 [[$\max(5,3,1) = 5$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[max]{.mop}[(]{.mopen}[5]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}[)]{.mclose}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

询问 [[$\lbrack 2,6\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[6]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]：
- 片段 1 ([[$\lbrack 1,5\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[5]{.mord}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]) 不满足，因为
    [[$l_{1} = 1  R = 6$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6835em; vertical-align: -0.0391em;"}[8]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6833em;"}[R]{.mord .mathnormal
    style="margin-right: 0.0077em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[6]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 最长长度为 [[$3$][[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

询问 [[$\lbrack 7,12\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[7]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[12]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]：
- 片段 5 ([[$\lbrack 7,10\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[7]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[10]{.mord}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]) 满足，长度 4。
- 最长长度为 [[$4$][[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

