## B. 数上的图

### Problem Description

给出一个正整数 $n$，表示数值的上界。已知起点 $x$ 与终点 $y$（其中 $1 \leq x, y \leq n$），你想通过若干次操作将 $x$ 转化为 $y$。

对于任意的 $1 \leq i \leq n$，你可以进行以下两种操作之一：
- 若 $\mathrm{count}(x) = \mathrm{count}(i)$，则可以将 $x$ 转化为 $i$。
- 若 $\mathrm{lowbit}(x) = \mathrm{lowbit}(i)$，则可以将 $x$ 转化为 $i$。

请你求出将 $x$ 转化为 $y$ 的最小操作次数。 $\dagger$ $\mathrm{count}(i)$ 表示 $i$ 在二进制表示下 $1$ 的个数。 $\dagger$ $\mathrm{lowbit}(i)$ 表示 $i$ 在二进制表示下最低位的 $1$ 及其后面所有的 $0$ 构成的数值。

### Input

每个测试点中包含多组测试数据。输入的第一行包含一个正整数 $T(1 \leq T \leq 10^5)$，表示数据组数。对于每组测试数据：

一行三个正整数 $n, x, y(1 \leq x, y \leq n \leq 10^{15})$，分别表示数值的上界以及起点与终点。

### Output

对于每组测试数据：输出一行一个整数，表示答案。

### Sample Input

```plain
2
10 10 1
36 35 26
```

### Sample Output

```plain
2
1
```

