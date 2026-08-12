## A. runs

### Problem Description

你知道吗，中文里拼音为 \"run\" 的常用字只有 \"润\"，\"闰\"
字多数人只有在鲁迅的文章里以名字的方式见到过。

没了。

定义一个字符串是重串，当前仅当它可以被表示为 $u^{k}(k \geq 2)$ 的形式，即将字符串 $u$ 连续拼接$k$ 次。

定义一个字符串 $s$ 的划分为一个集合 $\{ l_{k},r_{k}\}$，满足 $l_{1} = 1,r_{k} = \mid s\mid,l_{i} = r_{i - 1} + 1,l_{i} \leq r_{i}$, $s = s\lbrack l_{1},r_{1}\rbrack + s\lbrack l_{2},r_{2}\rbrack + \cdots + s\lbrack l_{k},r_{k}\rbrack$。

定义一个字符串 $s$ 的一个划分 $\{ l_{k},r_{k}\}$ 是好的，当且仅当$\forall i,s\lbrack l_{i},r_{i}\rbrack$ 不是重串。

给出一个 01 串，求它的好的划分的数量，对 `998244353` 取模。

### Input

第一行一个整数 $T\text{（}$T\\leq
100$\text{）}$，表示数据组数。

接下来 $T$ 行，每行一个 01
串，表示询问的字符串 $s\text{（}\mid s\mid \leq 10^{6},\sum\mid s\mid \leq 9 \times 10^{6}\text{，}s\lbrack i\rbrack \in \{ 0,1\}\text{）}$。

### Output

对于每组测试数据，输出一行一个整数表示答案

### Sample Input

```plain
5
1
01
001
000100011
1010101010
```

### Sample Output

```plain
1
2
3
71
345
```

