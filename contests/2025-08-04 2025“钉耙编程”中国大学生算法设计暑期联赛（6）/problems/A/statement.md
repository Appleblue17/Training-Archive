## A. cats 学乘法

### Problem Description

cats 有一个长为 $n$ 的数组 $a_1,a_2,\dots,a_n$。在一次操作中，cats
可以选择 $1\leq i\leq n$，将 $a_i$ 变为 $a_i + 1$ 或 $a_i - 1$。

现在 cats 希望数组中所有数的乘积是一个正整数，即 $\prod_{i=1}^{n} a_i > 0$。在此基础上，cats
希望最小化他的操作次数。你能告诉 cats
最少操作多少次才能让数组中所有数的乘积是一个正整数吗？

### Input

第一行包含一个整数$T$ （$1\leq T \leq 2\cdot 10^4$），表示一共有 $T$ 组测试数据。

对于每组测试数据：

第一行为一个整数$n$ （$1\leq n\leq 2\cdot 10^5$），表示数组 $a$ 的长度。

第二行为 $n$ 个整数$a_1,a_2,\dots,a_n$ （$-10^9 \leq a_i \leq 10^9$），表示数组 $a$。

保证所有测试数据的 $n$ 之和不超过 $10^6$。

### Output

对于每组测试数据，输出一个整数，表示 cats 最少需要的操作次数。

### Sample Input

```plain
3
3
0 0 0
3
1 1 1
3
-1 -1 -1
```

### Sample Output

```plain
3
0
2
```

