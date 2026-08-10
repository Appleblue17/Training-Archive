## E. 摩卡数

### Problem Description

小摩卡是个天才，尤其在字符串理论方面有着异于常人的天赋。为了赞颂她的才华，人们常常将那些满足特定优美性质的字符串命名为"摩卡串"。

小摩卡上本科时，在数据结构与算法分析课程中学到了 KMP
自动机，并想出了如下构建一个字符串 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的 KMP 自动机的算法。

在算法中：
- [[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
    .mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 是长度为
    [[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的输入字符串，仅包含前 [[$\sigma$][[[]{.strut
    style="height: 0.4306em;"}[σ]{.mord .mathnormal
    style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 个小写字母。
- [[$\pi$][[[]{.strut
    style="height: 0.4306em;"}[π]{.mord .mathnormal
    style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 是 [[$S$][[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}]
    的前缀函数。[[$\pi\lbrack i\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[π]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[\[]{.mopen}[i]{.mord
    .mathnormal}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 的值是满足
    [[$k < i$][[[]{.strut
    style="height: 0.7335em; vertical-align: -0.0391em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 且
    [[$S\lbrack 1,k\rbrack = S\lbrack i - k + 1,i\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}[\]]{.mclose}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}[\[]{.mopen}[i]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[i]{.mord
    .mathnormal}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 的最大 [[$k$][[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]。若不存在这样的正整数
    [[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，则
    [[$\pi\lbrack i\rbrack = 0$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[π]{.mord .mathnormal
    style="margin-right: 0.0359em;"}[\[]{.mopen}[i]{.mord
    .mathnormal}[\]]{.mclose}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- [[$S\lbrack l,r\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}[\[]{.mopen}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 表示仅保留
    [[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
    .mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 中第 [[$l$][[[]{.strut
    style="height: 0.6944em;"}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 个到第 [[$r$][[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 个位置的字符所构成的子串。
- [[$\delta$][[[]{.strut
    style="height: 0.6944em;"}[δ]{.mord .mathnormal
    style="margin-right: 0.0379em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 是 KMP
    自动机的转移表。[[$\delta\lbrack i,j\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[δ]{.mord .mathnormal
    style="margin-right: 0.0379em;"}[\[]{.mopen}[i]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[j]{.mord .mathnormal
    style="margin-right: 0.0572em;"}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 表示如果当前状态为
    [[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    且输入字符为 [[$j$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，则新状态变为
    [[$\delta\lbrack i,j\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[δ]{.mord .mathnormal
    style="margin-right: 0.0379em;"}[\[]{.mopen}[i]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[j]{.mord .mathnormal
    style="margin-right: 0.0572em;"}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]。
- [[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 是一个计数器。

![figure](../../../data/images/C1229-1005-1new.png)

小摩卡定义，算法结束后 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的值即为字符串
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的摩卡数。请你构造一个字符串
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 并指定 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的字符集大小
[[$\sigma$][[[]{.strut
style="height: 0.4306em;"}[σ]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]，使得对字符串
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 运行该算法，所得到的摩卡数恰好为
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}]。

你需要保证构造的字符串的长度不超过 [[$10^{5}$][[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Input

第一行输入一个正整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(1 \leq T \leq 50)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[50]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示数据组数。接下来按如下格式输入
[[$T$][[[]{.strut style="height: 0.6833em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 组数据：

输入一行一个正整数 [[$k$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}]
[[$(1 \leq k \leq 10^{9})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示摩卡数的值。

### Output

对于每组数据，输出两行：
- 第一行输出两个用空格分隔的正整数
    [[$n,\sigma$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[σ]{.mord .mathnormal
    style="margin-right: 0.0359em;"}]{.base}]{.katex-html
    aria-hidden="true"}]，表示字符串的长度和字符集的大小。
- 第二行输出一行一个字符串 [[$S$][[[]{.strut
    style="height: 0.6833em;"}[S]{.mord .mathnormal
    style="margin-right: 0.0576em;"}]{.base}]{.katex-html
    aria-hidden="true"}]。

你需要保证
[[$1 \leq n \leq 10^{5},1 \leq \sigma \leq 26$][[[]{.strut
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
style="height: 0.7719em; vertical-align: -0.136em;"}[σ]{.mord
.mathnormal style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[26]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的长度为 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，且 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 仅包含前
[[$\sigma$][[[]{.strut
style="height: 0.4306em;"}[σ]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 个小写英文字母。

本题使用 Special Judge
测试，如有多个满足条件的答案，你可以输出任意一种。你**不需要**最小化字符串
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的长度或字典序。

可以证明在题目限制内，一定存在至少一组满足条件的解。

### Sample Input

```plain
2
14
697
```

### Sample Output

```plain
6 3
abcabc
21 26
cbababcbbabcbbabcbabc
```

### Hint

请注意样例输出仅表示一种可能的合法答案，并不表示该样例输出恰好对应标准程序的输出。

本题输出量可能较大，建议使用较快速的输出方式（如关闭流同步的 `cout`）。

