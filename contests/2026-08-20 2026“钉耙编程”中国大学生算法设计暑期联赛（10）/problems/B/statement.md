## B. 大户爱的硬币

### Problem Description

大户爱正在抛硬币，每次抛到正面的概率为 $p$。大户爱知道如果她记抛到第一次正面需要的次数为 $X$，那么 $E\lbrack X\rbrack = \frac{1}{p}$。这个问题有点太简单了，所以大户爱又给了你一个参数 $k$，你需要求 $Var\lbrack X^{k}\rbrack$，其中 $Var$ 表示方差。

### Input

第一行一个整数 $T$ 表示测试数据数量。接下来 $T$ 行，每行两个整数 $k,p$ 分别表示参数 $k$ 和概率 $p$。输入中的 $p$ 表示正面概率在模$998244353$ 意义下的值。所有除法均按模逆元计算。$1 \leq T \leq 5,1 \leq k \leq 2 \times 10^{5},0 < p < 998244353$

### Output

$T$ 行，每行一个整数表示答案在模 $998244353$ 意义下的结果。

### Sample Input

```plain
2
1 499122177
114514 1919810
```

### Sample Output

```plain
2
822979729
```

### Hint

当$k = 1$ 时，$Var\lbrack X\rbrack = \frac{1 - p}{p^{2}}$，此时带入 $p = \frac{1}{2}$ 即可计算答案。

