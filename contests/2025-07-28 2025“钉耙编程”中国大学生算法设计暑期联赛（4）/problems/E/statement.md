## E. 美好的梦境（一）

### Problem Description

本题与 美好的梦境（二）的区别将使用【全角中括号】标注。
- -----------------------------------------------------------------------

又是空虚的一天，老师已经不知道这是第几次了。看着眼前作为值日生的
Serika，他始终无法忘记她上一次的遭遇。千千万万不要重蹈上一位的覆辙，老师自思道。Serika
注意到了老师的心思，她决定通过美好的梦境来帮助他重整旗鼓。

老师有 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个关于学生的梦境，编号为
[[$1,2,3,\cdots,n$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。它们作为节点构成了一棵有根树。编号为
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）的梦境拥有
[[$k_{i}$][[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个儿子梦境，编号分别为
[[$p_{i,1},p_{i,2},p_{i,3},\cdots,p_{i,k_{i}}$][[[]{.strut
style="height: 0.7167em; vertical-align: -0.2861em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
.mathnormal .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[2]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[3]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: -0.0315em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

【现在，对于每个编号为 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）的梦境，老师均会从所有
[[$\lbrack 1,k_{i}\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 的排列中 **等概率随机** 选择一个，记为
[[$a_{i,1},a_{i,2},a_{i,3},\cdots,a_{i,k_{i}}$][[[]{.strut
style="height: 0.7167em; vertical-align: -0.2861em;"}[[a]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
.mathnormal .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[2]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[3]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: -0.0315em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。】

老师认为：

1.  编号为 [[$p_{i,a_{i,j}}$][[[]{.strut
    style="height: 0.7779em; vertical-align: -0.3473em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[[a]{.mord .mathnormal
    .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[j]{.mord .mathnormal
    .mtight style="margin-right: 0.0572em;"}]{.mord .mtight}]{.sizing
    .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2819em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.3473em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq j \leq k_{i}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8444em; vertical-align: -0.15em;"}[[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]）的非根梦境的 **左梦境** 为编号为
    [[$p_{i,a_{i,\max(j - 1,1)}}$][[[]{.strut
    style="height: 0.8392em; vertical-align: -0.4086em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[[a]{.mord .mathnormal
    .mtight}[[[[[[]{.pstrut style="height: 2.5357em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct
    .mtight}[[m]{.mtight}[a]{.mtight}[x]{.mtight}]{.mop
    .mtight}[(]{.mopen .mtight}[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}[−]{.mbin .mtight}[1]{.mord
    .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}[)]{.mclose
    .mtight}]{.mord .mtight}]{.sizing .reset-size3 .size1
    .mtight}]{style="top: -2.3448em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3448em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.3695em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.4086em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的梦境，**右梦境** 为编号为
    [[$p_{i,a_{i,\min(j + 1,k_{i})}}$][[[]{.strut
    style="height: 0.8716em; vertical-align: -0.441em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[[a]{.mord .mathnormal
    .mtight}[[[[[[]{.pstrut style="height: 2.5357em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct
    .mtight}[[m]{.mtight}[i]{.mtight}[n]{.mtight}]{.mop
    .mtight}[(]{.mopen .mtight}[j]{.mord .mathnormal .mtight
    style="margin-right: 0.0572em;"}[+]{.mbin .mtight}[1]{.mord
    .mtight}[,]{.mpunct .mtight}[[k]{.mord .mathnormal .mtight
    style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
    style="height: 2.6595em;"}[i]{.mord .mathnormal
    .mtight}]{style="top: -2.3448em; margin-left: -0.0315em; margin-right: 0.1em;"}]{.vlist
    style="height: 0.3448em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.3147em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}[)]{.mclose .mtight}]{.mord
    .mtight}]{.sizing .reset-size3 .size1
    .mtight}]{style="top: -2.3448em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3448em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.4157em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.441em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]
    的梦境。（根据定义，一个非根梦境的左梦境或右梦境均可以是它本身）
2.  编号为 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]）的非叶子梦境的 **真儿子梦境** 为编号为
    [[$p_{i,a_{i,1}}$][[[]{.strut
    style="height: 0.7779em; vertical-align: -0.3473em;"}[[p]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[[a]{.mord .mathnormal
    .mtight}[[[[[[]{.pstrut style="height: 2.5em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size3 .size1
    .mtight}]{style="top: -2.357em; margin-left: 0em; margin-right: 0.0714em;"}]{.vlist
    style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2819em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.3473em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的梦境。

为了帮助老师重新品味这些梦境，Serika 从 Koyuki 手里购买了三种 Millennium
Science School 监制的梦境转移器，分别记作 ←、→ 和
↓。通过阅读说明书，老师得知了执行这三种梦境转移器所产生的效果：

1.  转移器 ←
    的效果是：若当前所处梦境是根梦境，**不移动**，否则移动至它的左梦境。
2.  转移器 →
    的效果是：若当前所处梦境是根梦境，**不移动**，否则移动至它的右梦境。
3.  转移器 ↓
    的效果是：若当前所处梦境是叶子梦境，**不移动**，否则移动至它的真儿子梦境。

【老师现在处于根梦境，他会依照某种顺序执行这些转移器。这个顺序将以字符串的形式给出，具体内容见
输入/输出格式。他找来了你帮忙计算他最终移动到的梦境编号的期望值，对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模。】

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
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
aria-hidden="true"}]）表示测试数据组数。

对于每一组测试数据，输入包含 [[$n + 2$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 行。

第一行包含一个整数 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq n \leq 300$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[300]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示梦境的数量。

第二行包含一个仅出现 L、R、D 字符的字符串
[[$S$][[[]{.strut style="height: 0.6833em;"}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq \mid S\mid \leq 300$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∣]{.mord}[S]{.mord
.mathnormal style="margin-right: 0.0576em;"}[∣]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[300]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示转移器执行的顺序。字符 L
表示此时执行转移器 ←，字符 R 表示此时执行转移器 →，字符 D
表示此时执行转移器 ↓。

接下来 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，第 [[$i + 2$][[[]{.strut
style="height: 0.7429em; vertical-align: -0.0833em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq i \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7955em; vertical-align: -0.136em;"}[i]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）行首先包含一个整数
[[$k_{i}$][[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$0 \leq k_{i} < n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[\<]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]）表示梦境 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的儿子梦境个数。接下来包含
[[$k_{i}$][[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0315em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个整数
[[$p_{i,1},p_{i,2},p_{i,3},\cdots,p_{i,k_{i}}$][[[]{.strut
style="height: 0.7167em; vertical-align: -0.2861em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
.mathnormal .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[2]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[3]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: -0.0315em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq p_{i,1},p_{i,2},p_{i,3},\cdots,p_{i,k_{i}} \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.9221em; vertical-align: -0.2861em;"}[[p]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
.mathnormal .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[2]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[3]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
style="margin-right: 0.1667em;"}[]{.mspace
style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[p]{.mord .mathnormal}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[i]{.mord .mathnormal .mtight}[,]{.mpunct
.mtight}[[k]{.mord .mathnormal .mtight
style="margin-right: 0.0315em;"}[[[[[[]{.pstrut
style="height: 2.5em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size3 .size1
.mtight}]{style="top: -2.357em; margin-left: -0.0315em; margin-right: 0.0714em;"}]{.vlist
style="height: 0.3281em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.143em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]），表示梦境
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
的儿子梦境。

保证输入的梦境构成一棵有根树。

### Output

对于每一组测试数据，输出包含一行一个整数表示期望值对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后的值。

### Sample Input

```plain
2
4
DLRLDR
2 2 3
0
1 4
0
10
LRLLDLRRLLDLDDDLLRLD
3 2 3 4
0
0
2 5 6
2 8 9
1 7
0
0
1 10
0
```

### Sample Output

```plain
499122180
332748122
```

### Hint

在样例的第一组测试数据中，讨论以下两种情况：

1.  [[$a_{1,1} = 1,a_{1,2} = 2$][[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[1]{.mord
    .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.9305em; vertical-align: -0.2861em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[1]{.mord
    .mtight}[,]{.mpunct .mtight}[2]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，此时最终移动到编号为
    [[$3$][[[]{.strut
    style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的梦境。
2.  [[$a_{1,1} = 2,a_{1,2} = 1$][[[]{.strut
    style="height: 0.7167em; vertical-align: -0.2861em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[1]{.mord
    .mtight}[,]{.mpunct .mtight}[1]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.9305em; vertical-align: -0.2861em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[1]{.mord
    .mtight}[,]{.mpunct .mtight}[2]{.mord .mtight}]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，此时最终移动到编号为
    [[$4$][[[]{.strut
    style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 的梦境。

综上，答案为 [[$\frac{7}{2}$][[[]{.strut
style="height: 1.1901em; vertical-align: -0.345em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[2]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[7]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后为
[[$499122180$][[[]{.strut
style="height: 0.6444em;"}[499122180]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

样例的第二组测试数据的答案为 [[$\frac{13}{3}$][[[]{.strut
style="height: 1.1901em; vertical-align: -0.345em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[[3]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.655em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[[13]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3 .mtight}]{style="top: -3.394em;"}]{.vlist
style="height: 0.8451em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.345em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose
.nulldelimiter}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，对
[[$998244353$][[[]{.strut
style="height: 0.6444em;"}[998244353]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 取模后为
[[$332748122$][[[]{.strut
style="height: 0.6444em;"}[332748122]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

