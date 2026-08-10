## L. 最小值

### Problem Description

给定两个长度为 $n$ 的整数数组 $a_1,a_2,\ldots, a_n$ 和 $b_1,b_2,\ldots, b_n$，求

$$
\min_{p\neq q} ||a_p-a_q|-|b_p-b_q||
$$

的值。

### Input

第一行一个整数 $T$（$1\le T\le 10^4$），表示数据组数。

对于每组数据，第一行一个整数 $n$（$2\le n\le 10^5$），表示数组的长度。

第二行 $n$ 个整数 $a_1,a_2,\ldots, a_n$（$|a_i|\le 10^{12}$）。

第三行 $n$ 个整数 $b_1,b_2,\ldots, b_n$（$|b_i|\le 10^{12}$）。

对于所有数据，保证 $\sum n\le 5\times 10^5$。

### Output

对于每组数据，输出一行一个整数，表示答案。

### Sample Input

```plain
2
3
1 4 1
1 5 4
4
1 2 -2 5
4 -5 3 4
```

### Sample Output

```plain
1
2
```

