## C. 今晚吃春天

### Problem Description

**提示：本题中的斗地主游戏可能与实际情况不同，请参赛选手务必仔细阅读题目描述。**

"四人斗地主"是普通斗地主游戏的变体。玩家一共有四人，其中一人是地主，其余三人是农民，记为一、二、三号农民。四人共持有总计
[[$108$][[[]{.strut
style="height: 0.6444em;"}[108]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 张扑克牌。这
[[$108$][[[]{.strut
style="height: 0.6444em;"}[108]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 张牌由两张"大王"、两张"小王"和
[[$104$][[[]{.strut
style="height: 0.6444em;"}[104]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 张点数牌组成。每张点数牌拥有一个不超过
[[$13$][[[]{.strut
style="height: 0.6444em;"}[13]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的正整数，称为点数，从小到大依次用字符
`3456789TJQKA2` 表示，例如 `3` 对应的点数是
[[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，`T` 对应的点数是
[[$8$][[[]{.strut
style="height: 0.6444em;"}[8]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，`2` 对应的点数是
[[$13$][[[]{.strut
style="height: 0.6444em;"}[13]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。每种点数牌各有
[[$8$][[[]{.strut
style="height: 0.6444em;"}[8]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 张，共计 [[$104$][[[]{.strut
style="height: 0.6444em;"}[104]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 张。在此基础上，规定"小王"的点数为
[[$14$][[[]{.strut
style="height: 0.6444em;"}[14]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，"大王"的点数为
[[$15$][[[]{.strut
style="height: 0.6444em;"}[15]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，这两种牌分别用字符 `w` 和 `W`
表示。这样，每一张扑克牌都有对应的点数和符号了。

游戏开始时，地主拥有 [[$33$][[[]{.strut
style="height: 0.6444em;"}[33]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 张牌，三位农民每人拥有
[[$25$][[[]{.strut
style="height: 0.6444em;"}[25]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
张牌。游戏将进行若干回合，直到有人出完手中所有的牌：
- 每回合的首发者先出牌（游戏开始时，首发者是地主）。
- 每回合的首发者必须从自己拥有的牌中挑选若干张打出，且出的牌必须组成一种合法牌型（见下文）。出过的牌将被弃置不再使用。
- 接下来按照顺序，玩家依次选择是否跟出牌。例如若首发者是地主，那么接下来依次询问一号农民、二号农民、三号农民、地主、一号农民、二号农民、三号农民，以此类推。注意同一人可以在同一回合中多次出牌。
- 如果某位玩家跟出牌，那么必须从自己拥有的牌中挑选若干张打出，所出的牌必须也组成一种合法牌型，且必须比上一位出牌者出的牌更大（见下文）。出过的牌将被弃置不再使用。
- 如果某一时刻，有连续三位玩家均选择不出牌，本回合结束，最后一位出牌的玩家成为下一回合的首发者。
- 如果在某一回合的某一次出牌中，出牌者出完了手中所有的牌，那么游戏立即结束，该玩家所属的阵营获胜。

四人斗地主一共有十类合法牌型：
- 单张 [[$\text{S}(a)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[S]{.mord}]{.mord
    .text}[(]{.mopen}[a]{.mord
    .mathnormal}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：由一张点数为
    [[$a$][[[]{.strut style="height: 0.4306em;"}[a]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的牌组成，满足 [[$1 \leq a \leq 15$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[a]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[15]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 对子 [[$\text{D}(a)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[D]{.mord}]{.mord
    .text}[(]{.mopen}[a]{.mord
    .mathnormal}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：由两张点数为
    [[$a$][[[]{.strut style="height: 0.4306em;"}[a]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的牌组成，满足 [[$1 \leq a \leq 15$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[a]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[15]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 三张 [[$\text{T}(a)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[T]{.mord}]{.mord
    .text}[(]{.mopen}[a]{.mord
    .mathnormal}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：由三张点数为
    [[$a$][[[]{.strut style="height: 0.4306em;"}[a]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的牌组成，满足 [[$1 \leq a \leq 13$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[a]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[13]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 三带二 [[$\text{C}(a,b)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[C]{.mord}]{.mord
    .text}[(]{.mopen}[a]{.mord .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[b]{.mord
    .mathnormal}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：由三张点数为
    [[$a$][[[]{.strut style="height: 0.4306em;"}[a]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    和两张点数为 [[$b$][[[]{.strut
    style="height: 0.6944em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的牌组成，满足 [[$a \neq b$][[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[a]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[[[[[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
    .vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6944em;"}[b]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq a \leq 13$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[a]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[13]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq b \leq 15$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.136em;"}[b]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[15]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 顺子 [[$\text{SS}(l,r)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[SS]{.mord}]{.mord
    .text}[(]{.mopen}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：由点数为
    [[$l$][[[]{.strut style="height: 0.6944em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 至 [[$r$][[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 中的牌组成，每种各一张，满足
    [[$5 \leq l + 4 \leq r \leq 12$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[5]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[4]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[12]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 连对 [[$\text{SD}(l,r)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[SD]{.mord}]{.mord
    .text}[(]{.mopen}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：由点数为
    [[$l$][[[]{.strut style="height: 0.6944em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 至 [[$r$][[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 中的牌组成，每种各两张，满足
    [[$3 \leq l + 2 \leq r \leq 12$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[3]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[12]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 钢板 [[$\text{ST}(l,r)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[ST]{.mord}]{.mord
    .text}[(]{.mopen}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：由点数为
    [[$l$][[[]{.strut style="height: 0.6944em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 至 [[$r$][[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 中的牌组成，每种各三张，满足
    [[$2 \leq l + 1 \leq r \leq 12$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[12]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 飞机 [[$\text{SC}(l,r,P)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[SC]{.mord}]{.mord
    .text}[(]{.mopen}[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[P]{.mord .mathnormal
    style="margin-right: 0.1389em;"}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：由点数为
    [[$l$][[[]{.strut style="height: 0.6944em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 至 [[$r$][[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 中的牌组成，每种各三张，满足
    [[$2 \leq l + 1 \leq r \leq 12$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[2]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[12]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]；外加
    [[$r - l + 1$][[[]{.strut
    style="height: 0.6667em; vertical-align: -0.0833em;"}[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 个对子
    [[$P = \{\text{D}(x_{1}),\text{D}(x_{2}),\cdots,\text{D}(x_{r - l + 1})\}$][[[]{.strut
    style="height: 0.6833em;"}[P]{.mord .mathnormal
    style="margin-right: 0.1389em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[{]{.mopen}[[D]{.mord}]{.mord
    .text}[(]{.mopen}[[x]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[D]{.mord}]{.mord
    .text}[(]{.mopen}[[x]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[D]{.mord}]{.mord
    .text}[(]{.mopen}[[x]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[[r]{.mord .mathnormal .mtight
    style="margin-right: 0.0278em;"}[−]{.mbin .mtight}[l]{.mord
    .mathnormal .mtight style="margin-right: 0.0197em;"}[+]{.mbin
    .mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2083em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)}]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]。注意：[[$x_{1},x_{2},\cdots,x_{r - l + 1}$][[[]{.strut
    style="height: 0.6389em; vertical-align: -0.2083em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[⋯]{.minner}[]{.mspace
    style="margin-right: 0.1667em;"}[]{.mspace
    style="margin-right: 0.1667em;"}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[r]{.mord
    .mathnormal .mtight style="margin-right: 0.0278em;"}[−]{.mbin
    .mtight}[l]{.mord .mathnormal .mtight
    style="margin-right: 0.0197em;"}[+]{.mbin .mtight}[1]{.mord
    .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3361em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2083em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 不必互不相同，也允许为
    [[$l$][[[]{.strut style="height: 0.6944em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 至 [[$r$][[[]{.strut
    style="height: 0.4306em;"}[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 中的点数。也就是说，一共有
    [[$5(r - l + 1)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[5]{.mord}[(]{.mopen}[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[1]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 张牌。
- 炸弹 [[$\text{B}(x,a)$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[B]{.mord}]{.mord
    .text}[(]{.mopen}[x]{.mord .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[a]{.mord
    .mathnormal}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]：由 [[$x$][[[]{.strut
    style="height: 0.4306em;"}[x]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    张点数为 [[$a$][[[]{.strut
    style="height: 0.4306em;"}[a]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    的牌组成，满足 [[$4 \leq x \leq 8$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[4]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[x]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[8]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$1 \leq a \leq 13$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7719em; vertical-align: -0.136em;"}[a]{.mord
    .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.6444em;"}[13]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 王炸：由两张"大王"、两张"小王"组成。

可以得知，每种合法牌型恰好属于上面十种类型中的一种。

合法牌型 [[$X$][[[]{.strut
style="height: 0.6833em;"}[X]{.mord .mathnormal
style="margin-right: 0.0785em;"}]{.base}]{.katex-html
aria-hidden="true"}] 要想比合法牌型
[[$Y$][[[]{.strut style="height: 0.6833em;"}[Y]{.mord
.mathnormal style="margin-right: 0.2222em;"}]{.base}]{.katex-html
aria-hidden="true"}] 大，需要满足下面的条件：
- 王炸比所有其余合法牌型都大。一整场游戏中只能有一个王炸，因此比较王炸之间的大小没有意义。
- 炸弹比不是炸弹或王炸的合法牌型大。
- 对于两个炸弹
    [[$X = \text{B}(x_{1},a_{1})$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[B]{.mord}]{.mord
    .text}[(]{.mopen}[[x]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 和
    [[$Y = \text{B}(x_{2},a_{2})$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[B]{.mord}]{.mord
    .text}[(]{.mopen}[[x]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
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
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$X$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 比 [[$Y$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 大的充要条件为
    [[$x_{1} > x_{2}$][[[]{.strut
    style="height: 0.6891em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 或者
    [[$x_{1} = x_{2}$][[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[x]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}] 且
    [[$a_{1} > a_{2}$][[[]{.strut
    style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 对于前八类合法牌型，不同类之间不能比较大小。也就是说，不能拿与上一个人出的牌不同类的前八类牌型来接牌。
- 对于两个单张 [[$X = \text{S}(a_{1})$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[S]{.mord}]{.mord
    .text}[(]{.mopen}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 和
    [[$Y = \text{S}(a_{2})$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[S]{.mord}]{.mord
    .text}[(]{.mopen}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]、两个对子
    [[$X = \text{D}(a_{1})$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[D]{.mord}]{.mord
    .text}[(]{.mopen}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 和
    [[$Y = \text{D}(a_{2})$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[D]{.mord}]{.mord
    .text}[(]{.mopen}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 或两个三张
    [[$X = \text{T}(a_{1})$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[T]{.mord}]{.mord
    .text}[(]{.mopen}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 和
    [[$Y = \text{T}(a_{2})$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[T]{.mord}]{.mord
    .text}[(]{.mopen}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$X$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 比 [[$Y$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 大的充要条件为
    [[$a_{1} > a_{2}$][[[]{.strut
    style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 对于两个三带二
    [[$X = \text{C}(a_{1},b_{1})$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[C]{.mord}]{.mord
    .text}[(]{.mopen}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[b]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 和
    [[$Y = \text{C}(a_{2},b_{2})$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[C]{.mord}]{.mord
    .text}[(]{.mopen}[[a]{.mord .mathnormal}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[b]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，[[$X$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 比 [[$Y$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 大的充要条件为
    [[$a_{1} > a_{2}$][[[]{.strut
    style="height: 0.6891em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[1]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[a]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[2]{.mord
    .mtight}]{.sizing .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。也就是说，三带二牌型比较大小只看三张的部分，不看两张的部分。三张部分一样大的三带二牌型视为相等，无论两张部分是否一样大。
- 对于两个顺子
    [[$X = \text{SS}(l_{1},r_{1})$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[SS]{.mord}]{.mord
    .text}[(]{.mopen}[[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 和
    [[$Y = \text{SS}(l_{2},r_{2})$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[SS]{.mord}]{.mord
    .text}[(]{.mopen}[[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]、两个连对
    [[$X = \text{SD}(l_{1},r_{1})$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[SD]{.mord}]{.mord
    .text}[(]{.mopen}[[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 和
    [[$Y = \text{SD}(l_{2},r_{2})$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[SD]{.mord}]{.mord
    .text}[(]{.mopen}[[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 或两个钢板
    [[$X = \text{ST}(l_{1},r_{1})$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[ST]{.mord}]{.mord
    .text}[(]{.mopen}[[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 和
    [[$Y = \text{ST}(l_{2},r_{2})$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[ST]{.mord}]{.mord
    .text}[(]{.mopen}[[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，若
    [[$r_{1} - l_{1} \neq r_{2} - l_{2}$][[[]{.strut
    style="height: 0.7333em; vertical-align: -0.15em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[[[[[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
    .vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7333em; vertical-align: -0.15em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8444em; vertical-align: -0.15em;"}[[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，则 [[$X$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 和 [[$Y$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}]{.base}]{.katex-html
    aria-hidden="true"}]
    不能比较大小；否则，[[$X$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 比 [[$Y$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 大的充要条件为
    [[$r_{1} > r_{2}$][[[]{.strut
    style="height: 0.6891em; vertical-align: -0.15em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 对于两个飞机
    [[$X = \text{SC}(l_{1},r_{1},P_{1})$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[SC]{.mord}]{.mord
    .text}[(]{.mopen}[[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[P]{.mord .mathnormal
    style="margin-right: 0.1389em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.1389em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}] 和
    [[$Y = \text{SC}(l_{2},r_{2},P_{2})$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}[]{.mspace
    style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[[SC]{.mord}]{.mord
    .text}[(]{.mopen}[[l]{.mord .mathnormal
    style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[r]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[[P]{.mord .mathnormal
    style="margin-right: 0.1389em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.1389em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]，若
    [[$r_{1} - l_{1} \neq r_{2} - l_{2}$][[[]{.strut
    style="height: 0.7333em; vertical-align: -0.15em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[[[[[[]{.strut
    style="height: 0.8889em; vertical-align: -0.1944em;"}[[[]{.mrel}]{.mord}]{.inner}[]{.fix}]{.rlap}]{.thinbox}]{.mord
    .vbox}]{.mrel}[=]{.mrel}]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.7333em; vertical-align: -0.15em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.8444em; vertical-align: -0.15em;"}[[l]{.mord
    .mathnormal style="margin-right: 0.0197em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0197em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]，则 [[$X$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 和 [[$Y$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}]{.base}]{.katex-html
    aria-hidden="true"}]
    不能比较大小；否则，[[$X$][[[]{.strut
    style="height: 0.6833em;"}[X]{.mord .mathnormal
    style="margin-right: 0.0785em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 比 [[$Y$][[[]{.strut
    style="height: 0.6833em;"}[Y]{.mord .mathnormal
    style="margin-right: 0.2222em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 大的充要条件为
    [[$r_{1} > r_{2}$][[[]{.strut
    style="height: 0.6891em; vertical-align: -0.15em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[1]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[\>]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.5806em; vertical-align: -0.15em;"}[[r]{.mord
    .mathnormal style="margin-right: 0.0278em;"}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[2]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -2.55em; margin-left: -0.0278em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3011em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。也就是说，飞机牌型比较大小只看连续三张的部分，不看剩余两张的部分。连续三张部分一样大的飞机牌型视为相等，无论剩余两张部分是否一样大。

现在 Silvefish 当上了地主，并得到了属于他的
[[$33$][[[]{.strut
style="height: 0.6444em;"}[33]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 张牌。真是一手好牌啊！Silvefish
想起了"春天"。"春天"是四人斗地主中的一种特殊现象，指从游戏开始到游戏结束的过程中，所有农民均未打出任何一张牌。现在他想知道，他是否有
[[$100\%$][[[]{.strut
style="height: 0.8056em; vertical-align: -0.0556em;"}[100%]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
的把握打出"春天"。他不知道农民手里的牌，所以这意味着他需要有一种出牌策略，使得无论农民剩余的
[[$75$][[[]{.strut
style="height: 0.6444em;"}[75]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 张牌如何分成三份（每份
[[$25$][[[]{.strut
style="height: 0.6444em;"}[25]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
张牌）给农民，他都一定能打出"春天"。可以认为农民们都非常希望出牌，只有他们真的无法打出任何牌时，才会选择不出。可惜手里的牌太多了，他算不过来。你能告诉他答案吗？

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（[[$1 \leq T \leq 5 \times 10^{4}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[5]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[4]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]）表示测试数据组数。

接下来对于每一组测试数据：

输入包含一行一个长度为 [[$33$][[[]{.strut
style="height: 0.6444em;"}[33]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的字符串，表示 Silvefish 作为地主拿到的
[[$33$][[[]{.strut
style="height: 0.6444em;"}[33]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 张牌。保证字符串中的所有字符均为
`Ww2AKQJT9876543`
中的字符，且按照该顺序（也就是点数从大到小）依次输入，含义见题面描述。

保证每一组测试数据都是合法的地主开局手牌。

### Output

对于每一组测试数据，如果 Silvefish 有
[[$100\%$][[[]{.strut
style="height: 0.8056em; vertical-align: -0.0556em;"}[100%]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 的把握打出"春天"，那么输出一行一个字符串
`Yes`，否则输出一行一个字符串 `No`。

### Sample Input

```plain
2
WW22222222AAKKQQTT777666555444333
W22AAKKQQQJJJTTT99988775544443333
```

### Sample Output

```plain
Yes
No
```

### Hint

样例包含两组测试数据。

在第一组测试数据中，Silvefish 可以选择先打出炸弹
[[$\text{B}(8,13)$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[B]{.mord}]{.mord
.text}[(]{.mopen}[8]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[13]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]（也即
`22222222`），农民无法接牌；然后再将剩余的
[[$25$][[[]{.strut
style="height: 0.6444em;"}[25]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 张牌作为飞机
[[$\text{SC}(1,5,\{\text{D}(8),\text{D}(10),\text{D}(11),\text{D}(12),\text{D}(15)\})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[SC]{.mord}]{.mord
.text}[(]{.mopen}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[{]{.mopen}[[D]{.mord}]{.mord
.text}[(]{.mopen}[8]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[D]{.mord}]{.mord
.text}[(]{.mopen}[10]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[D]{.mord}]{.mord
.text}[(]{.mopen}[11]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[D]{.mord}]{.mord
.text}[(]{.mopen}[12]{.mord}[)]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[D]{.mord}]{.mord
.text}[(]{.mopen}[15]{.mord}[)})]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]（也即
`WWAAKKQQTT777666555444333`）一次性打出，从而达成"春天"。

第二组测试数据取自真实生活中的一局四人斗地主，可以证明在这种情况下
Silvefish 无法达成"春天"。

