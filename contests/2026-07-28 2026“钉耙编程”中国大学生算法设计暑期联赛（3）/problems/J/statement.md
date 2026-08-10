## J. Random

### Problem Description

在小 H 和小 M 的世界里，有 [[$w$][[[]{.strut
style="height: 0.4306em;"}[w]{.mord .mathnormal
style="margin-right: 0.0269em;"}]{.base}]{.katex-html
aria-hidden="true"}] 种不同的音符

小 H 特别喜欢一段由 [[$l$][[[]{.strut
style="height: 0.6944em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}]{.base}]{.katex-html
aria-hidden="true"}] 个音符组成的旋律。

小 M 是个莫名其妙的人，经常莫名其妙的哼起歌来。

小 M 哼歌是完全随机的，也就是说，她每次会随机从
[[$w$][[[]{.strut style="height: 0.4306em;"}[w]{.mord
.mathnormal style="margin-right: 0.0269em;"}]{.base}]{.katex-html
aria-hidden="true"}]
个音符中哼出一个，这些哼出的音符按照顺序组成了一曲歌。

每当小 M 哼歌时，哼出了小 H 喜欢的那段旋律（连续的一段音符），小 H
就会立即打断她，并且奖励她一个吻。

跟小 M 呆久了，小 H 也变得莫名其妙起来，也就是说，他会在所有长度为
[[$l$][[[]{.strut style="height: 0.6944em;"}[l]{.mord
.mathnormal style="margin-right: 0.0197em;"}]{.base}]{.katex-html
aria-hidden="true"}] 的旋律中，随机喜欢上其中的一个。

小 M 哼歌很累，她想知道期望情况下，哼出多少个音符，小 H 会奖励她那个吻。

### Input

第一行一个正整数
[[$T\text{（}1 \leq T \leq 10^{5}\text{）}$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[（]{.mord
.cjk_fallback}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html aria-hidden="true"}]
表示数据组数。

对于每组数据，输入两个整数
[[$w,l\text{（}1 \leq w,l \leq 10^{9}\text{）}$][[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[w]{.mord
.mathnormal style="margin-right: 0.0269em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[（]{.mord
.cjk_fallback}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[w]{.mord
.mathnormal style="margin-right: 0.0269em;"}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[l]{.mord .mathnormal
style="margin-right: 0.0197em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]，分别表示这个世界的音符数量，以及小 H
喜欢的旋律长度。

### Output

每组数据输出一个整数，表示小 M 哼歌长度期望（答案对 998244353 取模）

### Sample Input

```plain
2
2 3
3 2
```

### Sample Output

```plain
10
10
```

