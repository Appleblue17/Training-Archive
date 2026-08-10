## M. Digit Sum

### 题目描述

In the vast sky of numbers, each integer holds unique mysteries. Among
many of these mysteries, Pog began to focus on a special numerical
property: the digit sum. For a positive integer $\textstyle n$, we define $\textstyle S(n)$ as the sum of its digits in
decimal representation. For example, $\textstyle S(1729) = 1 + 7 + 2 + 9 = 19$.

Now, Pog has posed an interesting mathematical problem: Given a positive
integer $\textstyle n$, is there a positive
integer $\textstyle a$ such that $\textstyle S(na) = nS(a)$ holds?

It would be even more interesting if this puzzle could be solved. Please
help him find a possible $\textstyle a$, or
tell him that no solution exists.

### 输入描述

There are multiple test cases.The first line contains an integer $\textstyle T (1 \le T \le 10^5)$,
representing the number of test cases.

For each test case, a single integer $\textstyle n (1 \le n \le 10^9)$ is given in
a single line.

### 输出描述

For each test case, if there is no solution, output "-1". Otherwise,
output a positive integer $\textstyle a$ that
is no greater than $\textstyle 10^9$, which
represents a valid solution.

If there are multiple solutions, output any solution not exceeding
\$10\^9\$. It can be proven that if a valid solution exists, there
exists one that is less than or equal to $\textstyle 10^9$.

### 示例1

#### 输入

```plain
2
3
10
```

#### 输出

```plain
3
-1
```

