## F. Gcd Master

### Problem Description

给定 $n$，求

$$\sum_{i=1}^n\sum_{j=i}^n\sum_{k=i}^j\gcd(i,k)\gcd(j,k){j \choose k}$$

对 $998244353$ 取模的结果。

### Input

第一行包含一个整数 $T$（$1 \le T \le 10$），表示测试数据的组数。

之后 $T$ 行，每行包含一个整数 $n$（$1 \le \sum n \le 5 \times 10^5$）。

### Output

对于每组测试数据，输出一行一个整数，表示答案。

### Sample Input

```plain
1
5
```

### Sample Output

```plain
298
```

