## J. Game on a Tree

### 题目描述

Little Q is playing a game on a tree.The rules of the game are as follows: In each round, Little Q can choose
an undeleted point on the tree and delete it along with all of its
directly connected edges. The game ends when all edges have been deleted
(note that not all nodes need to be deleted).Now Little Q wants to know how many rounds the game is expected to last
if the node to delete is chosen uniformly at random in each round.
Output the result modulo $998244353$.

### 输入描述

The first line contains a positive
integer $n(2 \leq n \leq 5000)$, representing
the number of nodes in the tree.The next $n-1$ lines each contain two
positive integers $x,y(1 \leq x,y \leq n)$,
indicating that there is an edge
between $x$ and $y$.

### 输出描述

Output a single integer, representing the answer.

### 示例1

#### 输入

```plain
3
1 2
2 3
```

#### 输出

```plain
665496237
```

### 示例2

#### 输入

```plain
5
1 2
2 3
3 4
2 5
```

#### 输出

```plain
598946615
```

