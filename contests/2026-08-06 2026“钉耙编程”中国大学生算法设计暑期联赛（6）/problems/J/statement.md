## J. Card Damage

### Problem Description

你正在玩一款卡牌游戏。

你手中的牌分为蓝色牌和红色牌两种。最初，你有
[[$x$][[[]{.strut style="height: 0.4306em;"}[x]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
张蓝色牌和 [[$y$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 张红色牌。此外，还有一个变量
[[$k$][[[]{.strut style="height: 0.6944em;"}[k]{.mord
.mathnormal style="margin-right: 0.0315em;"}]{.base}]{.katex-html
aria-hidden="true"}]，初始为 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

然后，你需要打出 [[$x + y$][[[]{.strut
style="height: 0.6667em; vertical-align: -0.0833em;"}[x]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}] 次牌。对于每次出牌：
- 若你打出了一张蓝色牌，则会令 [[$k$][[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 增加 [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。
- 若你打出了一张红色牌，设出牌后你的剩余手牌数为
    [[$p$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[p]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]，则会造成
    [[$k \times p$][[[]{.strut
    style="height: 0.7778em; vertical-align: -0.0833em;"}[k]{.mord
    .mathnormal style="margin-right: 0.0315em;"}[]{.mspace
    style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
    style="margin-right: 0.2222em;"}]{.base}[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[p]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    点伤害，然后将 [[$k$][[[]{.strut
    style="height: 0.6944em;"}[k]{.mord .mathnormal
    style="margin-right: 0.0315em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 设为 [[$1$][[[]{.strut
    style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]。

现在给定 [[$x,y$][[[]{.strut
style="height: 0.625em; vertical-align: -0.1944em;"}[x]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}]{.base}]{.katex-html
aria-hidden="true"}]，请你求出你能造成的最大伤害。

### Input

第一行包含一个整数
[[$T\ (1 \leq T \leq 10^{6})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}[ ]{.mspace}[(]{.mopen}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，表示测试数据组数。

接下来 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含两个整数
[[$x,y\ (0 \leq x,y \leq 10^{9})$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[x]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[ ]{.mspace}[(]{.mopen}[0]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[x]{.mord
.mathnormal}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.0641em; vertical-align: -0.25em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[)]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每组测试数据，输出一行一个整数代表你能造成的最大伤害。

### Sample Input

```plain
3
2 2
3 4
1 6
```

### Sample Output

```plain
5
19
21
```

### Hint

设 [[$\texttt{0}$][[[]{.strut
style="height: 0.6111em;"}[[0]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]
为打出一张红色牌，[[$\texttt{1}$][[[]{.strut
style="height: 0.6111em;"}[[1]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]
为打出一张蓝色牌。

对于第一组数据，一种能最大化伤害的出牌顺序为
[[$\texttt{0011}$][[[]{.strut
style="height: 0.6111em;"}[[0011]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html
aria-hidden="true"}]。打出第一张红色牌时，[[$k = 1$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，剩余手牌数为
[[$3$][[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，造成
[[$1 \times 3 = 3$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]
点伤害；打出第二张红色牌时，[[$k = 1$][[[]{.strut
style="height: 0.6944em;"}[k]{.mord .mathnormal
style="margin-right: 0.0315em;"}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，剩余手牌数为
[[$2$][[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，造成
[[$1 \times 2 = 2$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[2]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 点伤害。总伤害为
[[$2 + 3 = 5$][[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[3]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。可以证明，没有方案能使得总伤害
[[$> 5$][[[]{.strut
style="height: 0.5782em; vertical-align: -0.0391em;"}[\>]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6444em;"}[5]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

对于第二组数据，一种能最大化伤害的出牌顺序为
[[$\texttt{0001011}$][[[]{.strut
style="height: 0.6111em;"}[[0001011]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]。

对于第三组数据，一种能最大化伤害的出牌顺序为
[[$\texttt{0000001}$][[[]{.strut
style="height: 0.6111em;"}[[0000001]{.mord .texttt}]{.mord
.text}]{.base}]{.katex-html aria-hidden="true"}]。

