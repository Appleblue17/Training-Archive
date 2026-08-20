## A. 串串

### Problem Description

定义一个字符串 $t$ 为
**$k$-优秀的**，当且仅当满足以下条件：

1.  $t = A_{1} + A_{2} + \cdots + A_{k}$，其中
    "$+$" 表示字符串连接；
2.  对于所有 $i \geq 2$，有 $\mid A_{i}\mid = \mid A_{i - 1}\mid + 1$。对于一个字符串 $t$，我们用 $\mid t\mid$ 表示串 $t$ 的长度；
3.  $\mid A_{1}\mid \geq 1$；
4.  对于所有 $i \geq 2$，有 $lcp$（$A_{i},A_{i - 1}$）$= \mid A_{i - 1}\mid$。

其中 $lcp$（$x,y$）
表示字符串 $x$ 与 $y$ 的 **最长公共前缀长度**。也就是说， $lcp$（$x,y$）
表示从开头开始，$x$ 和 $y$ 有多少个连续的字符是相同的。

例如：
- $lcp$（$\text{"abcde"},\text{"abf"）} = 2$；
- $lcp$（$\text{"aaaa"},\text{"aa"）} = 2$；
- $lcp$（$\text{"abc"},\text{"xyz"）} = 0$。

给定一个长度为$n$ 的、仅由小写字母组成的字符串 $s$ 和一个正整数 $k$，请你计算字符串中有多少个子串是 $k$ 优秀的。

两个子串 $s\lbrack L_{1},R_{1}\rbrack$ 和$s\lbrack L_{2},R_{2}\rbrack$ 被认为不同，当且仅当满足以下任意一个条件：
- $L_{1} \neq L_{2}$；
- $R_{1} \neq R_{2}$。

### Input

每个测试文件包含多组测试数据。

第一行包含一个整数 $T = 1505$，表示测试数据的组数。

对于每组测试数据：
- 第一行包含两个整数 $n$（$1 \leq n \leq 10^{5}$）和 $k$（$2 \leq k \leq 2 \times 10^{5}$），具体含义见题面；
- 第二行包含一个长度为 $n$ 的字符串 $s$。

数据保证 $\sum n \leq 5 \times 10^{5}$。

### Output

对于每组测试数据，输出一个整数，表示满足条件的 $k$ 优秀子串的数量。

### Sample Input

```plain
2
5 2
aaaaa
7 3
aababca
```

### Sample Output

```plain
4
1
```

### Hint

对于第二组样例，唯一优秀的字符串为 $s\lbrack 1,6\rbrack$，可以表示为
`"a" + "ab" + "abc"`。

