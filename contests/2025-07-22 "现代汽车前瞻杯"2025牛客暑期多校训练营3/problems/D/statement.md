## D. Distant Control

### 题目描述

You have $n$ robot friends, arranged in a
row, labeled from left to right as $1, 2, \ldots, n$. Initially, some robots are
turned off, while others are turned on.\
\
Your phone can distantly control the power state of the robots, but
unfortunately, it is not always very accurate. Specifically, there is a
constant $1 \leq a \leq n - 1$, and you can
only perform the following two types of operations with your phone:\
- Select $a$ robots with consecutive labels
    **which are all turned on** and turn them all off.
- Select $a + 1$ robots with consecutive
    labels **which are all turned off** and turn them all on.

You want to determine the maximum possible number of robots that are on
after several (possibly, $0$) operations.\

### 输入描述

Each test contains multiple test cases. The first line of input contains
a single integer$t$ ($1 \leq t \leq 4\cdot 10^4$) --- the number
of test cases. The description of the test cases follows.\
\
The first line of each test case contains two integers $n$ and$a$ ($2 \leq n \leq 2\cdot 10^5$, $1 \leq a \leq n - 1$).\
\
The second line of each test case contains a string $s$ of length$n$ consisting only of $\tt{01}$, describing the
initial power states of the robots. Specifically, the $i$-th robot is initially turned on if and
only if $s_i = \tt{1}$.\
\
It is guaranteed that the sum of $n$ over all
test cases does not exceed $4\cdot 10^5$.\

### 输出描述

For each test case, output a single line containing an integer: the
maximum possible number of robots that are on.

### 示例1

#### 输入

```plain
4
3 1
001
4 3
0101
5 2
10110
10 4
1011010001
```

#### 输出

```plain
3
2
5
5
```

### 备注

In the first test case, it is possible to perform a single operation to
turn all robots on: select the robots labeled $1, 2$, which are both off, and turn them
on.\
\
In the second test case, no operations can be performed, so the answer
is the number of robots that are initially turned on, which is $2$.\

