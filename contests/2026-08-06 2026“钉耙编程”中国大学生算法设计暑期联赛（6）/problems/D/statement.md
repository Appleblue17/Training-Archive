## D. Three Colors

### Problem Description

小 C 在便利店购物，店内共有三种类型的物品，分别记为
[[$\texttt{A},\texttt{B},\texttt{C}$][[[]{.strut
style="height: 0.8055em; vertical-align: -0.1944em;"}[[A]{.mord
.texttt}]{.mord .text}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[B]{.mord .texttt}]{.mord
.text}[,]{.mpunct}[]{.mspace style="margin-right: 0.1667em;"}[[C]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html
aria-hidden="true"}]。商店中的商品按顺序摆放，形成一个长度为
[[$n$][[[]{.strut style="height: 0.4306em;"}[n]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 的字符串
[[$s$][[[]{.strut style="height: 0.4306em;"}[s]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]，其中
[[$s_{i} \in {\texttt{A},\texttt{B},\texttt{C}}$][[[]{.strut
style="height: 0.6891em; vertical-align: -0.15em;"}[[s]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[∈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8055em; vertical-align: -0.1944em;"}[[[A]{.mord
.texttt}]{.mord .text}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[B]{.mord .texttt}]{.mord
.text}[,]{.mpunct}[]{.mspace style="margin-right: 0.1667em;"}[[C]{.mord
.texttt}]{.mord .text}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 件商品的类型。

小 C 想从指定的一段商品中挑选一段 **连续** 的商品送给小 X。

现在有 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 次询问，每次给出一个区间
[[$\lbrack l,r\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。你需要在区间
[[$\lbrack l,r\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}] 内选择一个连续子区间
[[$\lbrack l^{\prime},r^{\prime}\rbrack$][[[]{.strut
style="height: 1.0019em; vertical-align: -0.25em;"}[\[]{.mopen}[[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]（满足
[[$l \leq l^{\prime} \leq r^{\prime} \leq r$][[[]{.strut
style="height: 0.8304em; vertical-align: -0.136em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8879em; vertical-align: -0.136em;"}[[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8879em; vertical-align: -0.136em;"}[[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}]）。

设该子区间内三种商品出现次数分别为
[[${cnt}_{\texttt{A}},{cnt}_{\texttt{B}},{cnt}_{\texttt{C}}$][[[]{.strut
style="height: 0.8095em; vertical-align: -0.1944em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[A]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[B]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[C]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，其中未出现的商品类型出现次数视为
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。要求三种商品的出现次数两两不同，即
[[${cnt}_{\texttt{A}} \neq {cnt}_{\texttt{B}}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[A]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[[[[[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
.vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[B]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 且
[[${cnt}_{\texttt{A}} \neq {cnt}_{\texttt{C}}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[A]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[[[[[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
.vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[C]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 且
[[${cnt}_{\texttt{B}} \neq {cnt}_{\texttt{C}}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[B]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[[[[[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
.vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[C]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

对于每次询问，输出一个满足条件且长度最大的子区间
[[$\lbrack l^{\prime},r^{\prime}\rbrack$][[[]{.strut
style="height: 1.0019em; vertical-align: -0.25em;"}[\[]{.mopen}[[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。若存在多个长度最大的答案，输出任意一个即可；若不存在满足条件的子区间，则输出
`0 0`。

### Input

**本题强制在线。**

第一行包含一个整数
[[$n\ (1 \leq n \leq 2 \times 10^{6})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[n]{.mord
.mathnormal}[ ]{.mspace}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示商品的数量。

第二行包含一个长度为 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 的字符串 [[$s$][[[]{.strut
style="height: 0.4306em;"}[s]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]，保证仅由大写字母
[[$\texttt{A},\texttt{B},\texttt{C}$][[[]{.strut
style="height: 0.8055em; vertical-align: -0.1944em;"}[[A]{.mord
.texttt}]{.mord .text}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[B]{.mord .texttt}]{.mord
.text}[,]{.mpunct}[]{.mspace style="margin-right: 0.1667em;"}[[C]{.mord
.texttt}]{.mord .text}]{.base}]{.katex-html aria-hidden="true"}]
组成。

第三行包含一个整数
[[$q\ (1 \leq q \leq 10^{6})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[q]{.mord .mathnormal
style="margin-right: 0.0359em;"}[ ]{.mspace}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示询问的次数。

接下来 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含两个整数
[[$x^{\prime},y^{\prime}\ (0 \leq x^{\prime},y^{\prime} \leq 10^{9})$][[[]{.strut
style="height: 1.0019em; vertical-align: -0.25em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[′]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[ ]{.mspace}[(]{.mopen}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.9463em; vertical-align: -0.1944em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[′]{.mord
.mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。你需要通过以下规则解密得到真实的查询区间
[[$\lbrack l,r\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]：

设 [[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 和
[[$y$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 为解密后的临时端点，则：
- [[$x = ((x^{\prime} \oplus \text{last\_ans}) - 1)\operatorname{}n + 1$][[[]{.strut
    style="height: 0.4306em;"}[x]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1.0019em; vertical-align: -0.25em;"}[((]{.mopen}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[′]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[⊕]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1.06em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
    .text}[)]{.mclose}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[[[mod]{.mord
    .mathrm}]{.mord}]{.mbin}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，
- [[$y = ((y^{\prime} \oplus \text{last\_ans}) - 1)\operatorname{}n + 1$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1.0019em; vertical-align: -0.25em;"}[((]{.mopen}[[y]{.mord
    .mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[⊕]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1.06em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
    .text}[)]{.mclose}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[[[mod]{.mord
    .mathrm}]{.mord}]{.mbin}[]{.mspace
    style="margin-right: 0.0556em;"}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

其中 [[$\oplus$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[⊕]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 表示按位异或操作。此处约定
[[$( - 1)\operatorname{}n = n - 1$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[(]{.mopen}[−]{.mord}[1]{.mord}[)]{.mclose}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}[[[mod]{.mord
.mathrm}]{.mord}]{.mbin}[]{.mspace
style="margin-right: 0.0556em;"}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

最终真实的查询区间端点为 [[$l = \min(x,y)$][[[]{.strut
style="height: 0.6944em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[min]{.mop}[(]{.mopen}[x]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，[[$r = \max(x,y)$][[[]{.strut
style="height: 0.4306em;"}[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[max]{.mop}[(]{.mopen}[x]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

变量 [[$\text{last\_ans}$][[[]{.strut
style="height: 1.0044em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}] 初始值为
[[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。在每次询问后，[[$\text{last\_ans}$][[[]{.strut
style="height: 1.0044em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]
将被更新为**本次输出的满足条件的最大子区间长度**，即
[[$\text{last\_ans} = r^{\prime} - l^{\prime} + 1$][[[]{.strut
style="height: 1.0044em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
.text}[]{.mspace style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8352em; vertical-align: -0.0833em;"}[[r]{.mord
.mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8352em; vertical-align: -0.0833em;"}[[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。若不存在满足条件的子区间（即输出为
`0 0`），则视长度为 [[$0$][[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，即
[[$\text{last\_ans} = 0$][[[]{.strut
style="height: 1.0044em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
.text}[]{.mspace style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

保证解密后的真实区间满足
[[$1 \leq l \leq r \leq n$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
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
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

输出共 [[$q$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[q]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行。

对于每次询问，输出两个用空格分隔的整数
[[$l^{\prime}$][[[]{.strut
style="height: 0.7519em;"}[[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 和
[[$r^{\prime}$][[[]{.strut
style="height: 0.7519em;"}[[r]{.mord .mathnormal
style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，表示你选择的满足条件且长度最大的连续子区间的左右端点。若有多个长度相同的合法答案，输出任意一个；若无解，请输出
`0 0`。

### Sample Input

```plain
8
BCAABCCC
4
1 8
6 2
7 4
2 0
```

### Sample Output

```plain
2 8
2 4
5 7
0 0
```

### Hint

初始 [[$\text{last\_ans} = 0$][[[]{.strut
style="height: 1.0044em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
.text}[]{.mspace style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

**第一次询问**：[[$L = 1,R = 8$][[[]{.strut
style="height: 0.6833em;"}[L]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[8]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 异或后得
[[$\lbrack 1,8\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[8]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，子串
[[$\texttt{BCAABCCC}$][[[]{.strut
style="height: 0.6111em;"}[[BCAABCCC]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]。最长合法区间为
[[$\lbrack 2,8\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[8]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，其中
[[${cnt}_{\texttt{A}} = 2$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[A]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[${cnt}_{\texttt{B}} = 1$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[B]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[${cnt}_{\texttt{C}} = 4$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[C]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，输出
`2 8`，[[$\text{last\_ans} = 7$][[[]{.strut
style="height: 1.0044em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
.text}[]{.mspace style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[7]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

**第二次询问**：[[$L = 6,R = 2$][[[]{.strut
style="height: 0.6833em;"}[L]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[6]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 异或后得
[[$\lbrack 1,5\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，子串
[[$\texttt{BCAAB}$][[[]{.strut
style="height: 0.6111em;"}[[BCAAB]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html
aria-hidden="true"}]。最长合法区间长度为 3，可取
[[$\lbrack 2,4\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]（或
[[$\lbrack 3,5\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]），其中
[[${cnt}_{\texttt{A}} = 2$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[A]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[${cnt}_{\texttt{B}} = 0$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[B]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[${cnt}_{\texttt{C}} = 1$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[C]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，输出
`2 4`，[[$\text{last\_ans} = 3$][[[]{.strut
style="height: 1.0044em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
.text}[]{.mspace style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

**第三次询问**：[[$L = 7,R = 4$][[[]{.strut
style="height: 0.6833em;"}[L]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[7]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[4]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 异或后得
[[$\lbrack 4,7\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[7]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，子串
[[$\texttt{ABCC}$][[[]{.strut
style="height: 0.6111em;"}[[ABCC]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]。最长合法区间为
[[$\lbrack 5,7\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[7]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，其中
[[${cnt}_{\texttt{A}} = 0$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[A]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[${cnt}_{\texttt{B}} = 1$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[B]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[${cnt}_{\texttt{C}} = 2$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[C]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，输出
`5 7`，[[$\text{last\_ans} = 3$][[[]{.strut
style="height: 1.0044em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
.text}[]{.mspace style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

**第四次询问**：[[$L = 2,R = 0$][[[]{.strut
style="height: 0.6833em;"}[L]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[R]{.mord .mathnormal
style="margin-right: 0.0077em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 异或后得
[[$\lbrack 1,3\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，子串
[[$\texttt{BCA}$][[[]{.strut
style="height: 0.6111em;"}[[BCA]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]。不存在满足
[[${cnt}_{\texttt{A}}$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[A]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[${cnt}_{\texttt{B}}$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[B]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，[[${cnt}_{\texttt{C}}$][[[]{.strut
style="height: 0.7651em; vertical-align: -0.15em;"}[[[cnt]{.mord
.mathrm}]{.mord}[[[[[[]{.pstrut style="height: 2.7em;"}[[[[C]{.mord
.texttt .mtight}]{.mord .text .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-right: 0.05em;"}]{.vlist
style="height: 0.2778em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 两两不同的子区间，输出
`0 0`，[[$\text{last\_ans} = 0$][[[]{.strut
style="height: 1.0044em; vertical-align: -0.31em;"}[[last_ans]{.mord}]{.mord
.text}[]{.mspace style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[0]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

真实区间依次为
[[$\lbrack 1,8\rbrack,\lbrack 1,5\rbrack,\lbrack 4,7\rbrack,\lbrack 1,3\rbrack$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[8]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[\[]{.mopen}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[7]{.mord}[\]]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[\[]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[\]]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

