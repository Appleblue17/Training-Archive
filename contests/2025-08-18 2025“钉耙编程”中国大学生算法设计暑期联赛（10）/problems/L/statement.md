## L. Counting Colorful Sequence

### Problem Description

给定两个正整数 $N,M$，你需要对于每个 $n=1,\dots,N$，求解以下问题：

求有多少个长度为 $n$，且每个元素都是 $1\sim n$ 之间正整数的序列 $a$ 满足：
- 存在至少一个 $i$，满足 $a_i=\left\vert\begin{Bmatrix}a_j\vert 1\le j\le i\end{Bmatrix}\right\vert$，即 $a_i$ 恰好为 $a_1,\cdots,a_i$ 这些数中不同数的个数。

答案对 $M$ 取模。

### Input

本题有多组数据。第一行一个正整数 $T$（$1\le T\le 75$），表示数据组数。

对于每组测试数据，第一行输入两个整数 $N,M$（$1\le N\le 300$，$2\le M\le 10^9$）。

保证 $\sum N^3\le 5\cdot 10^7$。

### Output

对于每组测试数据，输出一行 $N$ 个整数，表示 $n=1,\dots,N$ 时的方案数对 $M$ 取模的结果。

### Sample Input

```plain
1
4 998244353
```

### Sample Output

```plain
1 2 16 153
```

