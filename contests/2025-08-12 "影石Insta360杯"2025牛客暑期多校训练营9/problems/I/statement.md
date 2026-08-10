## I. Tree Construction

### 题目描述

Nice Nature and Twin Turbo are umamusumes in the training center, and
they are having a data structure class!

In the data structures class, they learned about weighted trees and the
distances between two points on a tree.

During the class, Nice Nature received two trees with the same
structure, but the difference between the two trees was that the weights
of the same edge may vary between the two trees. Formally, each edge can
be represented by a quadruple $\textstyle (u, v, w1, w2)$ , where $\textstyle u$ and $\textstyle v$ represent the two nodes
connected by the edge, and$\textstyle w1$ and $\textstyle w2$ represent the weights of
the edge in the first tree and the second tree, respectively.

To represent the information of the entire tree more conveniently, she
calculated the "distance" between every pair of nodes. Specifically, for
each pair of nodes $\textstyle i, j$, she
recorded $\textstyle \text{dis1}_{i, j}$ and $\textstyle \text{dis2}_{i, j}$, which
represent the sum of weights of all the edges on the path from $\textstyle i$ to $\textstyle j$ in the first tree and the
second tree, respectively.

However, Twin Turbo played a prank. While Nice Nature did not notice,
Twin Turbo randomly swapped several pairs of $\textstyle (\text{dis1}_{i, j}, \text{dis2}_{i, j})$.
In other words, in the "distance matrix" you now have, the values of$\textstyle (\text{dis1}_{i, j}, \text{dis2}_{i, j})$ for some $\textstyle (i, j)$ may have been
swapped. For example, the original values in the "distance matrix" might
have been$\textstyle \text{dis1}_{i, j} = 1$ and $\textstyle \text{dis2}_{i, j} = 2$, but
after Twin Turbo played the prank, the new values in the "distance
matrix" are $\textstyle \text{dis1}_{i, j} = 2$ and $\textstyle \text{dis2}_{i, j} = 1$.

Now, you have the new "distance matrix" after Twin Turbo played the
prank. Can you help her restore the original structure of the tree and
the edge weights on each edge in the two trees?

### 输入描述

Each test contains multiple test cases. The first line contains a single
integer$\textstyle T~(1 \le T \le 10000)$ --- the number of test cases. For each test case,
- The first line of each test case contains one integer $\textstyle n~(1 \le n \le 1000)$.
- The $\textstyle i$-th line of the
    following $\textstyle n$ lines of each
    test case contains$\textstyle n$     integers $\textstyle \text{dis1}_{i, 1}, \dots, \text{dis1}_{i, n}~(0 \le \text{dis1}_{i, j} \le 10^9)$.
- The $\textstyle i$-th line of the
    following $\textstyle n$ lines of each
    test case contains$\textstyle n$     integers $\textstyle \text{dis2}_{i, 1}, \dots, \text{dis2}_{i, n}~(0 \le \text{dis2}_{i, j} \le 10^9)$.

It is guaranteed that for$\textstyle T$ cases, the sum of $\textstyle n ^ 2$ will not
exceed $\textstyle 10 ^ 6$.

### 输出描述

For each test case, output$\textstyle n - 1$ lines. The $\textstyle i$-th line contains
four integers $\textstyle u_i, v_i, w1_i, w2_i~(1 \le u_i, v_i \le n, 0 \le w1_i, w2_i \le 10^9)$,
representing the $\textstyle i$-th edge of
the tree.If there are multiple solutions, output any of them. It is
guaranteed that there is a solution.

### 示例1

#### 输入

```plain
3
3
0 2 3
1 0 4
2 4 0
0 1 2
2 0 4
3 4 0
3
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
5
0 1 2 4 5
2 0 4 2 2
2 4 0 6 6
4 3 6 0 4
5 2 7 7 0
0 2 2 4 4
1 0 3 3 4
2 3 0 6 7
4 2 6 0 7
4 4 6 4 0
```

#### 输出

```plain
1 2 1 2
1 3 3 2
1 2 0 0
1 3 0 0
1 2 1 2
1 3 2 2
2 4 3 2
2 5 4 2
```

