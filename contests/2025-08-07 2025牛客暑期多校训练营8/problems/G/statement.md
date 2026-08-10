## G. Changing Minimum Spanning Tree

### 题目描述

An undirected graph is a graph where any edge can be traversed in both
directions. A simple graph is a graph that does not have duplicate edges
or self-loops. A connected graph is a graph in which there exists at
least one path between any two vertices.A spanning tree of an undirected graph is a connected subgraph that
includes all the vertices of the graph and some of its edges, where
there exists exactly one path between any two vertices. An undirected
graph can have edge weights, and the spanning tree with the minimum sum
of edge weights is called the minimum spanning tree.Given a weighted undirected simple graph with $n$ vertices and $m$ edges, where the weight of each edge is
required to be an integer between $1$ and $k$, now we want to add one more edge under
the weight constraint, such that the new graph is a simple graph that
has **at least one** spanning tree, and the newly added edge must be
included in **any** minimum spanning tree of it. Please help calculate
how many ways to do that, and output the number of ways in modulo $(10^9 + 7)$.

### 输入描述

The first line contains an integer$T$ ($1 \leq T \leq 10^5$), indicating the number
of test cases.Then follow $T$ test cases. For each test
case:The first line contains three integers $n$, $m$ and$k$ ($1 \leq n \leq 10^5$, $0 \leq m \leq \min\left(2 \times 10^5, \frac{n (n - 1)}{2}\right)$, $1 \leq k \leq 10^9$).The next $m$ lines describe the given simple
graph. Each line of them contains three integers $u$, $v$, and$w$ ($1 \leq u, v \leq n$, $u \neq v$, $1 \leq w \leq k$), representing an edge of
weight $w$ connecting $u$ and $v$.It is guaranteed that the sum of $N$ and the
sum of $M$ over $T$ test cases do not exceed $5 \times 10^5$ and $10^6$, respectively.

### 输出描述

For each test case, output an integer in one line, representing the
number of ways, in modulo $(10^9 + 7)$, to
add an edge meeting the requirements.

### 示例1

#### 输入

```plain
5
3 2 2
1 2 1
2 3 2
3 3 5
1 2 3
2 3 4
1 3 5
2 1 3
1 2 3
6 6 5
1 2 3
1 3 1
2 4 2
3 5 2
2 6 4
5 6 5
2 0 25
```

#### 输出

```plain
1
0
0
20
25
```

