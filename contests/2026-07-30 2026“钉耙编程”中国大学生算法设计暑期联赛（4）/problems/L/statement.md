## L. L. Yet Another Suffix Array Problem

### Problem Description

**题目描述**

给定一个长度为 $n$ 的小写字母字符串 $S$，以及$m$ 次询问。

每次询问给出两个整数 $l,r$。令：

$$T = S_{l}S_{l + 1}\cdots S_{r},$$

并记 $q = r - l + 1$。

考虑 $T$ 的所有非空后缀。令$SA_{T}\lbrack 1\rbrack,SA_{T}\lbrack 2\rbrack,\ldots,SA_{T}\lbrack q\rbrack$ 表示这些后缀按字典序从小到大排列后的起点，其中起点按照 $T$ 内从$1$ 开始的编号。如果一个字符串是另一个字符串的前缀，较短的字符串字典序更小。

定义 $T$ 的 `height` 数组：

$${height}_{T}\lbrack 1\rbrack = 0,$$

对于每个 $2 \leq i \leq q$：

$$height_{T}\lbrack i\rbrack = LCP\lbrack T_{SA_{T}\lbrack i - 1\rbrack}\cdots T_{q},T_{SA_{T}\lbrack i\rbrack}\cdots T_{q}\rbrack.$$

其中 $LCP$ 表示两个字符串的最长公共前缀长度。

令：

$$H = \underset{2 \leq i \leq q}{\max}{height}_{T}\lbrack i\rbrack.$$

如果有多个下标 $i$ 满足 ${height}_{T}\lbrack i\rbrack = H$，取其中最小的 $i$。

对于每次询问，求 $H$，以及 $SA_{T}\lbrack i - 1\rbrack$ 和$SA_{T}\lbrack i\rbrack$ 对应的两个后缀在原字符串$S$ 中的起点。**两个起点的输出顺序必须与$SA_{T}$ 中的顺序相同。**每次询问保证 $H > 0$。

**样例解释**

对于第一次询问，$T = \texttt{banana}$。其后缀数组中的原串起点依次为：

$$6,4,2,1,5,3,$$

对应的 `height` 数组为：

$$0,1,3,0,0,2.$$

最大值为 $3$，最早在起点 $4$ 和起点$2$ 对应的相邻后缀之间取得。

第二次询问中，$T = \texttt{banan}$。后缀 `an`
是后缀 `anan` 的前缀，因此起点 $4$ 排在起点 $2$ 之前，答案为 `2 4 2`。

**数据范围**
- $1 \leq T \leq 5$ -$2 \leq n \leq 2 \times 10^{5}$ -$1 \leq m \leq 2 \times 10^{5}$ -$1 \leq l  0$ -   所有测试数据的 $n$ 之和不超过$4 \times 10^{5}$ -   所有测试数据的 $m$ 之和不超过$4 \times 10^{5}$

### Input

输入包含多组测试数据。第一行包含一个整数 $T$（$1 \leq T \leq 5$），表示测试数据组数。

对于每组测试数据：

第一行包含两个整数 $n,m$（$2 \leq n \leq 2 \times 10^{5}$，$1 \leq m \leq 2 \times 10^{5}$）。

第二行包含一个长度为 $n$ 的小写字母字符串 $S$。

接下来 $m$ 行，每行包含两个整数 $l,r$（$1 \leq l < r \leq n$），表示一次询问。

保证每个询问子串中至少有一个字符出现两次。

### Output

对于每次询问，输出一行三个整数：

$$H,\quad l + SA_{T}\lbrack i - 1\rbrack - 1,\quad l + SA_{T}\lbrack i\rbrack - 1.$$

其中 $i$ 是满足${height}_{T}\lbrack i\rbrack = H$ 的最小下标。

### Sample Input

```plain
1
6 3
banana
1 6
1 5
2 4
```

### Sample Output

```plain
3 4 2
2 4 2
1 4 2
```

