## K. Maximum GCD

### 题目描述

Given a sequence $a$ of length $n$, you need to perform exactly one
operation: select an interval and a non-negative integer $X$, and add$X$ to all numbers in the interval, maximizing the GCD of all numbers in the
sequence.  Output the maximun GCD，and if it is infinite, output $0$.

### 输入描述

This problem contains multiple test cases.The first line contains a positive
integer $T(1 \leq T \leq 10^5)$, representing
the number of test cases.For each test case, the first input is a positive
integer $n(1 \leq n \leq 10^5)$, representing
the length of the sequence.Next, input $n$ positive integers,
representing the
sequence $a(1 \leq a_i \leq 10^5)$.It is guaranteed
that $\sum n \leq 2\cdot 10^5$.

### 输出描述

For each test case, output a single line containing an integer,
representing the answer.

### 示例1

#### 输入

```plain
5
2
114 514
1
2
5
1 2 3 5 8
5
4 3 3 3 4
5
6 1 4 7 9
```

#### 输出

```plain
514
0
1
4
3
```

