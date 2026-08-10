## K. Amazing Sets (amazing)

### 题目描述

You are given a rooted tree $T$ of $n$ vertices and $n-1$ directed edges.For vertex $i$, its value is $a_i$. Vertex$x$ is **reachable** from vertex $y$ iff there
exists a path that starts from $y$, ends at $x$, and only goes through directed edges. It
is guaranteed that all vertices are reachable from the root.Given $m$ pairs of vertices $(u_i,v_i)$, satisfying that $u_i$ is reachable from $v_i$ on the original tree. Now, new directed
edges $u_i\to v_i$ will be added to form a
new graph.Define a subset $S$ (may be empty) of the set
of the tree vertices **amazing**, iff for each element $x$ in $S$, all
the vertices reachable from $x$ in the new
graph are in $S$. The value of an
**amazing **set $S$ is defined as the sum of
the values of all elements in $S$. The value
of an empty set is $0$.For all **amazing **sets, how many different kinds of values appeared?

### 输入描述

The first line includes a single integer $n$ ($1\le n\le 10^4$),
which is the number of vertices of tree $T$.The second line includes $n$ integers. The $i$-th number represents $a_i$ ($0\le a_i\le \sum_{i=1}^n a_i\le 10^4$).The next $n-1$ lines show all $n-1$ directed edges of the tree. For the $i$-th line in this part, two given numbers
are $U_i,V_i$ ($1\le U_i,V_i\le n$)
respectively. An edge starting from $U_i$ and
ending at $V_i$ exists.The next line has an integer $m$ ($1\le m\le 5\times 10^5$),
representing the number of new edges.The next $m$ lines show all $m$ new directed edges of the tree. For the $i$-th line in this part, two given numbers
are $u_i,v_i$ ($1\le u_i,v_i\le n$)
respectively. A new edge starting from$u_i$ and ending at $v_i$ exists.

### 输出描述

A single number which is the answer to the question above.

### 示例1

#### 输入

```plain
3
1 2 3
1 3
1 2
1
2 1
```

#### 输出

```plain
3
```

#### 说明

There are three **amazing** sets in the sample: $\lbrace 1,2,3\rbrace$, $\lbrace 3\rbrace$, and $\varnothing$. Since they have different
values, the answer is $3$.

### 备注

It\'s **not** guaranteed that $(u_i,v_i)$ are
pairwise different.

It\'s **not** guaranteed that $u_i\not=v_i$.

The root of the tree is **not** given.

