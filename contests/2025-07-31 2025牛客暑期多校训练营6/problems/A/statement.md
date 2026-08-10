## A. Dominoes on Tree

### 题目描述

Given a tree with $n$ nodes, rooted at node $1$. At node $i$,
there is a domino, which is a rectangle of size $1 \times 2$. This domino is divided into two
squares on the left and right, containing $a_i$ points and $b_i$ points, respectively. The domino is
undirected, meaning you can rotate it and swap the number of points in
the left and right squares.There is a group of people living on this tree, and the resident at node $x$ can go to the subtree of $x$ and collect all the dominoes (including
the domino at node $x$ itself). The residents
want to form the fewest possible chains with these dominoes. You need to
calculate the minimum number of chains that can be formed by the
residents at all nodes $i \in [1, n]$ using
all the dominoes in the subtree of node $i$.
We consider each resident\'s operation to be independent, meaning that
before each resident starts collecting, each node in the tree contains
exactly one domino.Here, a chain refers to a sequence of dominoes placed horizontally in
order, ensuring that the number of points on the right side of the
previous domino equals the number of points on the left side of the next
domino.

### 输入描述

The first line of input contains an integer $n\ (1 \leq n \leq 2 \times 10^5)$,
representing the number of nodes in the tree.The next line contains $n$ integers $a_i\ (1 \leq a_i \leq n)$, representing the
number of points in the left square of the domino.The following line contains $n$ integers $b_i\ (1 \leq b_i \leq n)$, representing the
number of points in the right square of the domino.The next $n - 1$ lines each contain two
integers $u, v\ (1 \leq u, v \leq n, u \neq v)$,
indicating that there is an edge between node $u$ and node $v$.
It is guaranteed that the given $n - 1$ edges
can connect the $n$ nodes into a tree.

### 输出描述

Output a single line with $n$ integers, where
the $i$-th integer represents the minimum
number of chains that the resident at node $i$ can form.

### 示例1

#### 输入

```plain
7
7 6 1 6 6 3 4
7 4 2 7 5 2 4
2 1
3 1
4 2
5 2
6 3
7 3
```

#### 输出

```plain
3 2 2 1 1 1 1
```

#### 说明

For the resident at node $2$, one possible
chain configuration is: $[4|6][6|7]$ and $[6|5]$. Note that this configuration rotates
the domino at node $2$.For the resident at node $3$, one possible
chain configuration is: $[1|2][2|3]$ and $[4|4]$.For the resident at node $1$, one possible
chain configuration is: $[4|4][4|6][6|7][7|7]$ and $[1|2][2|3]$ and $[6|5]$.

### 备注



