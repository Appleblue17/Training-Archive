## D. Prime XOR Permutation

### 题目描述

Given an integer $\textstyle N$, you need to
construct a permutation $\textstyle P$ of
integers from $\textstyle 0$ to $\textstyle N-1$ such that for all $\textstyle 1 \leq i < N$, $\textstyle P_i \oplus P_{i+1}$ is a prime
number. Here, $\textstyle \oplus$ denotes the
bitwise XOR operation.

### 输入描述

The first line contains an integer$\textstyle T$ ($\textstyle 1 \leq T \leq 2\times 10^5$),
the number of test cases.

For each test case, there is a single integer$\textstyle N$ ($\textstyle 1 \leq N \leq 10^6$).

It is guaranteed that the sum of $\textstyle N$ across all test cases does not
exceed $\textstyle 10^6$.

### 输出描述

For each test case:
- If a valid permutation exists, output a single line containing $\textstyle N$ space-separated integers
    representing the permutation $\textstyle P$.
- If no such permutation exists, output $\textstyle -1$.

### 示例1

#### 输入

```plain
2
4
5
```

#### 输出

```plain
3 1 2 0
4 1 3 0 2
```

