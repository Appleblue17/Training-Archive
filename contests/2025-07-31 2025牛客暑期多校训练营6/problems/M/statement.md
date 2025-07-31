## M. Minimum Difference

### 题目描述

Given $n$ distinct integers $a_i$, you need to separate these numbers
into exactly two sets, and arrange them arbitrarily to construct two
base $m$ numbers $A$ and$B$ (leading zeros are allowed), such that the difference between $A$ and $B$ is
minimized.

::::: {style="text-wrap-mode:wrap;"}

:::::

### 输入描述

This problem contains multiple test cases. The first line contains an
integer $T\ (1 \leq T \leq 10^5)$,
representing the number of test cases.For each test case, the first line contains two positive
integers $n,m(2 \leq n,m \leq 10^5)$,
representing the number of integers and the base, respectively.The next line
contains $n$ integers $a_i(0 \leq a_i

### 输出描述

Since the minimum difference can be very large, you only need to output
the result of the difference converted to decimal
modulo $998244353$.

For each test case, output one integer per line, representing the
result.

### 示例1

#### 输入

```plain
3
4 10
3 4 5 6
7 10
1 2 3 4 5 6 7
6 16
2 3 5 7 11 13
```

#### 输出

```plain
7
469
124
```

