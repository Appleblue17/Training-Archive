## E. 大户爱的生成树2

### Problem Description

大户爱有两张图，图 $A$ 为一张 $N$ 个点、$M$ 条边的无向带权图，图 $B$ 为一张 $N$ 个点的完全图，图 $B$ 中任意两点间的边权为图 $A$ 中对应两点的最小割。

给定图 $A$，求图 $B$ 的最小生成树的边权之和。

**最小割定义：**

给定一个无向带权图 $G$，点集为 $V$，边集为 $E$，其中每条边 $\left. u\leftrightarrow v \right.$ 有权值 $w_{u,v}$。

一个**割**是指将点集$V$ 划分为两个非空不相交集合 $S$ 和 $T$，即：
- $S \cup T = V$ -$S \cap T = \varnothing$ -$S \neq \varnothing$ -$T \neq \varnothing$ 
该割的**容量**定义为所有跨越 $S$ 和 $T$ 的边的权值之和：

$$c = \sum\limits_{u \in S,v \in T}w_{u,v}$$

**最小割**是指所有可能割中容量最小的割，其容量记为：

$$\lambda = \underset{\varnothing \neq S \subset V}{\min}c$$

对于图 $G$ 中任意两个指定顶点 $s$ 和 $t$，$s$ 和 $t$ 之间的最小割定义为：在所有满足 $s \in S$、$t \in T$ 的割中，容量的最小值，即：

$$\lambda_{st} = \underset{\varnothing \neq S \subset V,\ s \in S,\ t \in T}{\min}c$$

### Input

第一行输入一个整数 $T$，表示数据组数。

每组数据首先输入两个整数 $N$ 和 $M$，表示图$A$ 的点数和边数。

接下来输入 $M$ 行，每行三个整数 $x,y,z$，表示$x$ 和 $y$ 之间有一条权值为$z$ 的边。**不保证图连通，且可能出现重边和自环。** $1 \leq T \leq 6$，$1 \leq N \leq 600$，$\sum N \leq 2000$，$0 \leq M \leq \frac{N(N - 1)}{2}$，$0 \leq z \leq 10^{9}$。

### Output

对于每组数据，输出一行一个整数，表示图$B$ 的最小生成树的边权之和。

### Sample Input

```plain
1
5 5
1 2 1
2 3 2
3 4 3
4 5 4
5 1 5
```

### Sample Output

```plain
12
```

