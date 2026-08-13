## J. 合并之后字典序就变小了

### Problem Description

给定一个长度为 $N$ 的数组 $A$，其中每个元素均属于 $0,1,2$。

你可以执行任意多次以下操作：

选择两个相邻元素 $A_{i},A_{i + 1}$，将它们删除，并在原位置插入 $(A_{i} + A_{i + 1})\operatorname{}3$。

每次操作会使数组长度减少 $1$。

定义$f(A)$ 为通过若干次操作能够得到的字典序最小数组。

对于数组 $B$，定义 ${val}(B) = \sum_{i = 1}^{\mid B\mid}B_{i} \cdot 3^{i - 1}$。

给定数组 $A$，求$\sum_{L = 1}^{N}\sum_{R = L}^{N}{val}(f(A\lbrack L,R\rbrack))$ 
对 $998244353$ 取模后的结果。

其中，$A\lbrack L,R\rbrack$ 表示子数组 $\lbrack A_{L},A_{L + 1},\ldots,A_{R}\rbrack$。

对于两个不同的数组 $P,Q$，如果满足以下任意条件，则称 $P$ 的字典序小于 $Q$：
- $P$ 是$Q$     的前缀；
- 存在位置 $i$，满足 $P_{i} < Q_{i}$，且对所有 $j < i$ 都有 $P_{j} = Q_{j}$。

### Input

第二行输入 $N$ 个整数 $A_{1},A_{2},\ldots,A_{N}$。

对于一组测试数据： $1 \leq N \leq 2 \times 10^{5}$； $0 \leq A_{i} \leq 2$。

OJ 中只有一个正式测试点，该测试点满足： $T = 10000$； $\sum N = 2 \times 10^{6}$。

### Output

对于每组测试数据输出一行，表示所有子数组对应的 ${val}(f(A\lbrack L,R\rbrack))$ 之和，对 $998244353$ 取模后的结果。

### Sample Input

```plain
3
2
2 1
3
1 1 2
4
2 1 0 2
```

### Sample Output

```plain
3
9
30
```

