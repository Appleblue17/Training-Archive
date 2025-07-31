## J. 中位数

### Problem Description

对于一个长度为$L$ （$L$ 为奇数） 的数组 $a$，定义它的中位数 $\text{median}$（a） 为 $a$ 中第 $\dfrac{L+1}2$ 大的数。

现在给你一个长度为 $n$ 的排列，对于每对满足 $1\leq i\leq j\leq n$ 且 $j − i \equiv 0\pmod 2$ 的
（$i$, $j$），你需要计算 $i*j * \text{median}$（$p[i\dots j]$）。

输出所有值的总和。

### Input

第一行输入一个整数$T$ （$1 \le T \le 20$），表示测试的总数。

对于每个测试用例，第一行输入一个整数 $n$（$1 \le n \le 2000$）。

接来下一行 $n$ 个整数，表示 $1$ 到$n$ 的排列。

### Output

对于每个测试用例，输出一个数表示答案。

### Sample Input

```plain
2
3
1 3 2
5
2 3 1 5 4
```

### Sample Output

```plain
37
308
```

