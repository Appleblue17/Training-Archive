## L. Desertrium (desertrium)

### 题目描述

Little ppip is playing tuxun in his dream. He is now given a photo of a
desert. Since his dream is abstract, he discovers some marine creatures.
Little ppip wants to find the number of different marine creatures, and
he asks for your help.Specifically, you need to find the number of sub-jellyfish,
sub-starfish, and sub-eels. Definitions are shown below.
- A **desert** is a graph of at least one cactus.
- A **cactus** is a simple connected graph, in which every vertex is
    in at most one simple cycle of size at least $3$.
- A **jellyfish** is a simple connected graph which contains exactly
    one simple cycle of size at least $3$,
    and every vertex not included in the cycle has a degree of at most $2$. In other words, it\'s multiple
    chains hanging on a cycle. Following is a sample of a jellyfish:

![](https://uploadfiles.nowcoder.com/images/20250811/0_1754914627587/E91CA973462C25D5A22CEE5E691FFA73)

(the simple cycle is $1-2-3-4$)
- A **sub-jellyfish** of size $k$ is a
    graph $(V,E)$, in which $V$ is a vertex set of size $k$ and $E$ is
    an edge set of size $k$, satisfying that $(V,E)$ forms a jellyfish. Two
    sub-jellyfish are different iff their edge sets are different.
- A **starfish** is a simple connected graph with no simple cycles (in
    other words, a tree), and there is at most one vertex whose degree
    exceeds $2$. In other words, it\'s
    multiple chains hanging on a vertex. Following is a sample of a
    starfish:

![](https://uploadfiles.nowcoder.com/images/20250811/0_1754914666325/066588B1D44193A8213BB8C8271E9019)

(vertex $1$ has a degree of $4$)
- A **sub-starfish** of size $k$ is a graph $(V,E)$, in which $V$ is a vertex set of size $k$ and $E$ is
    an edge set of size $k-1$, satisfying
    that $(V,E)$ forms a starfish. Two
    sub-starfish are different iff their edge sets are different.
- An **eel** is a chain, which is a simple connected graph with no
    simple cycles, and every vertex has a degree of no more than $2$.
- A **sub-eel** of size $k$ is a graph $(V,E)$, in which $V$ is a vertex set of size $k$ and $E$ is
    an edge set of size $k-1$, satisfying
    that $(V,E)$ forms an eel. Two sub-eels
    are different iff their edge sets are different.

Please note that some sub-starfish are also sub-eels, which should be
counted twice in the answer. In addition, all the marine creatures
listed above must have a size of at least $2$.

Since the answer may be large, print it modulo $998244353$.

### 输入描述

**The problem contains multiple test cases.**The first line contains a positive integer$T$ ($1\leq T\le 10^6$), indicating the number of
test cases.For each test case:The first line contains two integers$n,m$ ($1\leq n\leq 10^5$, $0\le m\le 2n$, $1\le\sum n\leq 10^6$)
indicating the number of vertices and edges in the desert.The $i+1$-th
($1\le i\le m$) line contains two integers$u_i,v_i$ ($1\leq u_i,v_i\leq n$, $u_i\not=v_i$) representing an edge in the
desert. It\'s guaranteed that all pairs $(u_i,v_i)$ are distinct, meaning that
multiedges will not exist.

### 输出描述

For each test case, output a single integer representing the number of
marine creatures in the desert modulo $998244353$.

### 示例1

#### 输入

```plain
1
10 10
1 4
2 8
5 9
8 4
7 9
5 3
6 1
9 3
10 3
2 4
```

#### 输出

```plain
83
```

