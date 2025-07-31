## E. Array

### 题目描述

Given an array $a$ of length $n$ with all initial elements set to 0, and
an array $p$ of length $n$. You need to process $q$ operations, which are of two types:
- Update operation: Given four
    integers $opt=1$, $l$, $r$, $x$,
    for all $l \le i \le r$,
    add $x$ to the
    element $a_i$.
- Query operation: Given three
    integers $opt=2$, $l$, $r$,
    compute $\sum_{i=l}^{r} a_{p_{i}}$.

For each query operation, output the result of the query. This problem
is strictly online, and for each operation, the input parameters $l$, $r$, $x$ must be XORed with the last output answer
(do not XOR before the first query operation).

### 输入描述

The first line contains two
integers $n$ and $q$ ($1 \leq n, q \leq 10^5$),
representing the length of the array $a$ and
the number of operations.The second line contains $n$ integers,
representing the
array $p$ ($1 \leq p_i \leq n$).The next $q$ lines describe an operation,
formatted as one of the two types mentioned above. For all decrypted
inputs, there
are $1 \le opt \le 2$, $1 \le l \le r \le n$,
and $1 \le x \le 10^8$.

### 输出描述

For each query operation, output one line with one integer, representing
the result of the query.

### 示例1

#### 输入

```plain
6 10
3 6 5 1 2 6
1 1 3 8
1 2 3 9
1 2 5 4
1 2 3 9
2 1 3
1 33 33 38
1 32 32 35
2 35 33
1 36 34 36
2 39 35
```

#### 输出

```plain
34
38
81
```

