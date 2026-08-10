## H. Summit Down Side

### 题目描述

**Note that the definition of $\textstyle \operatorname{mex}$ is different
from other problems.**

You are given a permutation of$\textstyle n$ integers $\textstyle a_1, a_2, \dots, a_n$.
Calculate the sum of $\textstyle \operatorname{mex}$ for all
subarrays of $\textstyle a$.

The $\textstyle \operatorname{mex}$ of a
non-empty set of integers $\textstyle S$ is
the smallest integer $\textstyle k$ such that $\textstyle k \notin S$ and $\textstyle k > \min(S)$. For example, $\textstyle \operatorname{mex}(\{1, 3, 5\}) = 2$, $\textstyle \operatorname{mex}(\{1, 2, 3\}) = 4$.

A permutation of length $\textstyle n$ is a
sequence where each integer from $\textstyle 1$ to $\textstyle n$ appears exactly once.

### 输入描述

The first line contains a single integer$\textstyle t$ ($\textstyle 1 \le t \le 10^4$), the number
of test cases.

For each test case, the first line contains a single integer$\textstyle n$ ($\textstyle 1 \le n \le 5\times 10^5$).

The second line contains$\textstyle n$ distinct integers$\textstyle a_1, a_2, \dots, a_n$ ($\textstyle 1 \le a_i \le n$).

It is also guaranteed that the sum of $\textstyle n$ over all test cases will not
exceed $\textstyle 5\times 10^5$.

### 输出描述

For each test case, print a single integer in one line, representing the
sum of $\textstyle \operatorname{mex}$ for
all subarrays.

### 示例1

#### 输入

```plain
3
3
1 2 3
3
2 1 3
10
6 7 5 3 10 1 2 8 4 9
```

#### 输出

```plain
20
18
259
```

