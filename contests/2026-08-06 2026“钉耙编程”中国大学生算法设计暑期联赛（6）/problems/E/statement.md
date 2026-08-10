## E. Yougou Cleansing

### Problem Description

「千枝万脉，请除祸灾。」

「...于此，宣其祓却。」
- -----------------------------------------------------------------------

雷樱乃神樱之移枝，代神樱吸纳地脉中的不净。如今，一处小祓结界内的污秽再度躁动。Index
已经取得与之对应的「镇物」；为了完成祓除，她还需要辨认并依次调整结界中用于祓祝的石座，使其与祝式相合，从而摧破结界，逼出其中的污秽化身。

结界中共有 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个依次排列的石座，每个石座上有
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}] 个纹样。Index 将第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个石座的状态记为 [[$a_{i}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，从而得到一个长度为
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的非负整数数组 [[$a_{1},a_{2},\ldots,a_{n}$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[n]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，且数组中的每个元素都严格小于
[[$2^{k}$][[[]{.strut
style="height: 0.8491em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

然而，污秽遮蔽了石座上的部分纹样。不妨将 Index
此时能够辨认的纹样记作掩码
[[$S \in \lbrack 0,2^{k} - 1\rbrack$][[[]{.strut
style="height: 0.7224em; vertical-align: -0.0391em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0991em; vertical-align: -0.25em;"}[\[]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，并定义第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个石座在这一视野下呈现的状态为
[[$A_{S}\lbrack i\rbrack = a_{i}\& S$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[A]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[S]{.mord
.mathnormal .mtight style="margin-right: 0.0576em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\[]{.mopen}[i]{.mord
.mathnormal}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[[&]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]，其中 [[$\&$][[[]{.strut
style="height: 0.6944em;"}[[&]{.mord}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示按位与运算。

Index 希望对于每个
[[$S = 0,1,\ldots,2^{k} - 1$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0435em; vertical-align: -0.1944em;"}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，找出尽可能长的一段连续石座
[[$\lbrack l,r\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，使得存在一个整数
[[$C$][[[]{.strut style="height: 0.6833em;"}[C]{.mord
.mathnormal style="margin-right: 0.0715em;"}]{.base}]{.katex-html
aria-hidden="true"}]，使得对任意
[[$i \in \lbrack l,r\rbrack$][[[]{.strut
style="height: 0.6986em; vertical-align: -0.0391em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，均有
[[$A_{S}\lbrack i\rbrack = (C - i)\& S$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[A]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[S]{.mord
.mathnormal .mtight style="margin-right: 0.0576em;"}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\[]{.mopen}[i]{.mord
.mathnormal}[\]]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[C]{.mord
.mathnormal style="margin-right: 0.0715em;"}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[i]{.mord
.mathnormal}[)]{.mclose}[]{.mspace
style="margin-right: 0.2222em;"}[[&]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]。

考虑到巨大的输出量，不妨令 [[$\text{ans}_{S}$][[[]{.strut
style="height: 0.5806em; vertical-align: -0.15em;"}[[[ans]{.mord}]{.mord
.text}[[[[[[]{.pstrut style="height: 2.7em;"}[[S]{.mord .mathnormal
.mtight style="margin-right: 0.0576em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 为 [[$S$][[[]{.strut
style="height: 0.6833em;"}[S]{.mord .mathnormal
style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]
的答案，请你输出如下哈希值，其中，[[$B = 218,105,633 = \text{0x0d000721}$][[[]{.strut
style="height: 0.6833em;"}[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[218]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[105]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[633]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6944em;"}[[0x0d000721]{.mord}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]：

[[[$$(\sum\limits_{S = 0}^{2^{k} - 1}(\text{ans}_{S} \times B^{S}\operatorname{}998244353))\operatorname{}2^{64}$$][[[]{.strut
style="height: 3.2933em; vertical-align: -1.2943em;"}[(]{.mopen}[[[[[[]{.pstrut
style="height: 3.05em;"}[[[S]{.mord .mathnormal .mtight
style="margin-right: 0.0576em;"}[=]{.mrel .mtight}[0]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.8557em; margin-left: 0em;"}[[]{.pstrut
style="height: 3.05em;"}[∑]{.mop .op-symbol
.large-op}]{style="top: -3.05em;"}[[]{.pstrut
style="height: 3.05em;"}[[[[2]{.mord .mtight}[[[[[[]{.pstrut
style="height: 2.5em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size3 .size1
.mtight}]{style="top: -2.931em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.927em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord
.mtight}[−]{.mbin .mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -4.3em; margin-left: 0em;"}]{.vlist
style="height: 1.9989em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 1.2943em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[(]{.mopen}[[[ans]{.mord}]{.mord .text}[[[[[[]{.pstrut
style="height: 2.7em;"}[[S]{.mord .mathnormal .mtight
style="margin-right: 0.0576em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3283em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8913em;"}[[B]{.mord .mathnormal
style="margin-right: 0.0502em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[S]{.mord .mathnormal .mtight
style="margin-right: 0.0576em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8913em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[998244353]{.mord}[))]{.mclose}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8641em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[64]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8641em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]]

请注意取模运算在求和内部。

### Input

第一行包含一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$T \leq 100$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[100]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示测试数据的组数。

对于每组测试数据：
- 第一行包含两个整数 [[$n,k$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq n \leq 2 \times 10^{5},1 \leq k \leq 20$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[20]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]）；
- 第二行包含 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个整数 [[$a_{1},a_{2},\ldots,a_{n}$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[...]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[n]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.1514em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$0 \leq a_{i} < 2^{k}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
    .mathnormal .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8491em;"}[[2]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]）。

保证对于所有测试数据，[[$\sum 2^{k} \leq 2^{22}$][[[]{.strut
style="height: 1.0991em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8491em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[[2]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[22]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[$\sum n \leq 5 \times 10^{5}$][[[]{.strut
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
aria-hidden="true"}]。

### Output

对于每组测试数据，输出一行一个整数，表示该组数据的答案哈希值。

### Sample Input

```plain
3
4 2
3 2 1 0
5 2
0 0 0 0 0
4 2
0 1 0 1
```

### Sample Output

```plain
1309248575
851317235
1589957732
```

### Hint

三组数据的真实答案分别是
[[$\lbrack 4,4,4,4\rbrack,\lbrack 5,1,2,1\rbrack,\lbrack 4,4,2,2\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[\[]{.mopen}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[1]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[\[]{.mopen}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

请注意 IO 效率对程序运行时间的影响。本场比赛的 Multicon
一题中下发了快速读入与输出模板，你也许希望在本题中使用它。

「与君相别离，不知何日是归期，我如朝露转瞬晞。」

