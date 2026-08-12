## K. 森林

### Problem Description

设有 $n$ 个点的完全图为 $K_{n} = (V,E)$。

给出 $k$ 个 $K_{n}$ 的子图 $G_{1} = (V,E_{1}),G_{2} = (V,E_{2}),\ldots,G_{k} = (V,E_{k})$，满足：
- $G_{1},G_{2},\ldots,G_{k}$ 均无环。
- $E_{1},E_{2},\ldots,E_{k}$ 的大小均为 $m$。

记第 $i$ 个子图 $G_{i}$ 的第$j$ 条边为 $e_{i,j}$。

定义边集 $S$ 是好的，当且仅当：
- 存在集合 $X_{1},X_{2},\ldots,X_{m}$，满足$X_{i} \subseteq \bigcup_{j = 1}^{k}\{ e_{j,i}\}$     且 $1 \leq \mid X_{i}\mid \leq C_{i}$，使得 $S = \bigcup_{i = 1}^{m}X_{i}$。
- 边集 $S$ 导出的图 $G_{S} = (V,S)$ 无环。

求最大的集合 $S$ 的大小。

### Input

第一行输入一个正整数 $T$ $(1 \leq T \leq 100)$，表示数据组数。接下来输入 $T$ 组数据：

第一行输入三个整数 $n,m,k$ $(1 \leq n,m,k \leq 100)$。

第二行输入 $m$ 个整数表示 $C_{1},C_{2},\cdots,C_{m}$ $(1 \leq C_{i} \leq k)$。

接下来 $k$ 行，第 $i$ 行输入$2m$ 个整数$u_{i,1},v_{i,1},\ldots,u_{i,m},v_{i,m}$ 表示子图 $i$ 的所有 $m$ 条边。

保证所有数据中，$\sum n,\sum m,\sum k \leq 200$，且 $1 \leq u_{i,j},v_{i,j} \leq n$。

### Output

共输出 $T$ 行。

对于每组数据，输出一个整数表示答案。

### Sample Input

```plain
2
2 1 1
1
1 2
5 1 3
3
4 1
1 3
1 3
```

### Sample Output

```plain
1
2
```

