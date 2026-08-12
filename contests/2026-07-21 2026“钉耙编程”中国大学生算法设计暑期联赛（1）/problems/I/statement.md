## I. 数组

### Problem Description

给定长为 $n$ 的序列 $A = (a_{1},a_{2},\ldots,a_{n})$ 和长为 $2^{w}$ 的数组 $H\left\lbrack 0..2^{w} - 1 \right\rbrack$。对于 $1 \leq i \leq n$，定义

$$C_{i} = \sum\limits_{1 \leq b_{1},b_{2},\ldots,b_{m} \leq n}H\left\lbrack \left( \sum\limits_{j = 1}^{m}a_{b_{j}} \right)\operatorname{}2^{w} \right\rbrack \cdot \left( \sum\limits_{j = 1}^{m}\lbrack b_{j} = i\rbrack \right)^{k}.$$

其中，外层求和遍历所有 $B = (b_{1},b_{2},\ldots,b_{m})(1 \leq b_{j} \leq n)$，$\lbrack \cdot \rbrack$ 为艾弗森括号。

求 $C_{1},C_{2},\ldots,C_{n}$ 对 $998244353$ 取模的结果。

### Input

第一行输入一个正整数 $T(1 \leq T \leq 35)$，表示数据组数。接下来按如下格式输入 $T$ 组数据：

第一行输入四个整数 $n,w,m,k(1 \leq n \leq 5 \times 10^{5},0 \leq w \leq 19,1 \leq m \leq 10^{9},1 \leq k \leq 20)$。

第二行输入 $n$ 个整数表示 $A = (a_{1},a_{2},\cdots,a_{n})(0 \leq a_{i} < 2^{w})$。

第三行输入 $2^{w}$ 个整数表示 $H\left\lbrack 0..2^{w} - 1 \right\rbrack(0 \leq h_{i} < 2^{w})$。

保证输入数据中 $\sum n,\sum 2^{w}$ 均不超过 $10^{6}$。

### Output

共 $T$ 行，对于每组数据，输出 $n$ 个整数，表示每个数得到的贡献。

### Sample Input

```plain
2
2 2 2 1
0 1
1 1 2 2
4 2 1 1
0 1 2 3
3 3 2 0
```

### Sample Output

```plain
4 6
3 3 2 0
```

### Hint

本题输入输出量较大，建议使用较快速的输入输出方式（如关闭流同步的 `cin` /
`cout`）。

请注意常数因子对程序效率的影响。

