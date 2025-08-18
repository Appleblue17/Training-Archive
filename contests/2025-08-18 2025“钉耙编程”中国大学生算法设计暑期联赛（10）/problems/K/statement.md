## K. Worst Problem Of All Time

### Problem Description

**温馨提示：请注意你代码的时间常数。**

给定一张 $n$ 个点 $m$ 条边有向图，可能有重边自环。

你需要构造长为 $m$ 的正整数序列 $c_i$，满足 $\forall x$，只保留 $c_i=x$ 的所有边，则该图是
DAG（有向无环图）。

你需要找到字典序最小的序列 $c_i$，或报告无解。

### Input

本题有多组数据。第一行一个正整数 $T$（$1\le T\le10^3$）表示数据组数。对于每组测试数据：

第一行输入两个正整数 $n,m$（$2\le n\le5\cdot10^4$，$1\le m\le10^5$）。

接下来 $m$ 行，每行两个正整数 $u,v$（$1\le u,v\le n$）表示一条有向边。

保证 $\sum n\le2.5\cdot10^5$，$\sum m\le5\cdot10^5$。

### Output

对于每组数据，若有解，则一行$m$ 个正整数表示字典序最小的 $c_i$；若无解，仅输出一行一个 $-1$。

### Sample Input

```plain
2
3 3
1 2
2 3
3 1
2 4
1 1
1 2
2 1
2 2
```

### Sample Output

```plain
1 1 2
-1
```

