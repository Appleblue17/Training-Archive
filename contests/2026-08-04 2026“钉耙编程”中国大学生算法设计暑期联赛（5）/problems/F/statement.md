## F. 三串共鸣

### Problem Description

给定三个仅由小写英文字母组成的字符串 [[$a$][[[]{.strut
style="height: 0.4306em;"}[a]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，[[$b$][[[]{.strut
style="height: 0.6944em;"}[b]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$c$][[[]{.strut
style="height: 0.4306em;"}[c]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。所有字符串的下标均从
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 开始，我们用
[[$\mid S\mid$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[S]{.mord
.mathnormal
style="margin-right: 0.0576em;"}[∣]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示字符串 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]
的长度，[[$S\lbrack x..y\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[\[]{.mopen}[x]{.mord
.mathnormal}[..]{.mord}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 表示字符串 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}] 从下标 [[$x$][[[]{.strut
style="height: 0.4306em;"}[x]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 到下标 [[$y$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的连续子串，区间两端均包含在内。

你需要统计有多少个三元组 ([[$i,j,l)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[i]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[j]{.mord .mathnormal
style="margin-right: 0.0572em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 满足以下条件：

1.  [[$0 \leq l < \mid a\mid$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7335em; vertical-align: -0.0391em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[a]{.mord
    .mathnormal}[∣]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$0 \leq i < \mid b\mid$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6986em; vertical-align: -0.0391em;"}[i]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[b]{.mord
    .mathnormal}[∣]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$l \leq j < \mid c\mid$][[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[c]{.mord
    .mathnormal}[∣]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；
2.  在字符串 [[$b$][[[]{.strut
    style="height: 0.6944em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 中
    **至少存在一个** 起始位置 [[$k$][[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$0 \leq k$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 且
    [[$k + l < b$][[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7335em; vertical-align: -0.0391em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6944em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]），满足
    [[$a\lbrack 0..l\rbrack = b\lbrack k..k + l\rbrack = c\lbrack j - l..j\rbrack$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[a]{.mord
    .mathnormal}[\[]{.mopen}[0..]{.mord}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[\]]{.mclose}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[b]{.mord
    .mathnormal}[\[]{.mopen}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}[..]{.mord}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[\]]{.mclose}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[c]{.mord
    .mathnormal}[\[]{.mopen}[j]{.mord .mathnormal
    style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[..]{.mord}[j]{.mord .mathnormal
    style="margin-right: 0.0572em;"}[\]]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 且位置 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    被这个匹配子串覆盖，即
    [[$k \leq i \leq k + l$][[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6944em;"}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}]{.base}]{.katex-html
    aria-hidden="true"}]。

换句话说，对于每个 [[$l$][[[]{.strut
style="height: 0.6944em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$j$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
aria-hidden="true"}]，如果 [[$a$][[[]{.strut
style="height: 0.4306em;"}[a]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的长度为
[[$l + 1$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的前缀等于 [[$c$][[[]{.strut
style="height: 0.4306em;"}[c]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 中以 [[$j$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
aria-hidden="true"}] 结尾、长度为
[[$l + 1$][[[]{.strut
style="height: 0.7778em; vertical-align: -0.0833em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
的子串，那么我们记这个字符串为目标串。接着在
[[$b$][[[]{.strut style="height: 0.6944em;"}[b]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
中寻找所有等于该目标串的子串，并统计这些子串覆盖到的不同位置
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 的数量。

注意，[[$b$][[[]{.strut
style="height: 0.6944em;"}[b]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]
中可能存在多个相同的匹配子串。如果它们覆盖了同一个位置
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，那么对于当前固定的（[[$j,l$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}]{.base}]{.katex-html
aria-hidden="true"}]），这个位置
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
只能贡献一次。

### Input

第一行一个正整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 10^{4}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示数据组数。

对于每组数据，第一行三个整数
[[$n_{a},n_{b},n_{c}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[n]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[a]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[n]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[b]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[n]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[c]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n_{a},n_{b},n_{c} \leq 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[[n]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[a]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[n]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[b]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[n]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[c]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），分别表示三个字符串的长度。

接下来三行，每行一个仅由小写英文字母构成的字符串，分别表示给定的字符串
[[$a$][[[]{.strut style="height: 0.4306em;"}[a]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，[[$b$][[[]{.strut
style="height: 0.6944em;"}[b]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 和 [[$c$][[[]{.strut
style="height: 0.4306em;"}[c]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。

对于所有数据，保证
[[$\sum(n_{a} + n_{b} + n_{c}) \leq 3 \times 10^{6}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[(]{.mopen}[[n]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[a]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7333em; vertical-align: -0.15em;"}[[n]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[b]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[n]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[c]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每组数据，输出一行一个整数，表示满足条件的三元组的总数。

### Sample Input

```plain
2
2 3 3
ab
bab
abc
4 5 6
aaaa
aaaaa
aaaaaa
```

### Sample Output

```plain
3
90
```

### Hint

对于第一组样例，满足条件的三个三元组分别为：([[$1,0,0$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}])，([[$1,1,1$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]) 和 ([[$2,1,1$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}])。

