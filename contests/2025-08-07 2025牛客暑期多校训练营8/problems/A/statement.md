## A. Insert One

### 题目描述

Given a decimal integer $x$ without leading
zeros, please insert a digit $1$ into it such
that the modified number $x$ is still a
decimal integer without leading zeros and is maximized.Here, leading zeros refer to all zeros located to the left of the first
non-zero digit in the numerical representation. If the number itself is $0$, then it does not contain leading zeros.

### 输入描述

The first line contains an integer $T$ ($1 \leq T \leq 10^5$),
indicating the number of test cases.Then follow $T$ test cases. For each test
case:The only line contains an integer$x$ ($-2^{63} \leq x < 2^{63}$).

### 输出描述

For each test case, output an integer in one line, representing the
maximum possible changed $x$.

### 示例1

#### 输入

```plain
6
2
1
0
-1
-2
-1000000000000000000
```

#### 输出

```plain
21
11
10
-11
-12
-10000000000000000001
```

