## B. Base Conversion Master

### 题目描述

Little T has received $n$ arrays $A_{1 \dots n}$, where the length of the $i$-th array$A_i$ is $l_i$. Additionally, Little T has provided
two integers $y$ and $M$, and wishes to determine all positive
integers $s$ within the range $[2, M]$ that satisfy the following
requirements.Enumerate $i \in [1, n]$ in order:
- Treat the array $A_i$ as a number in
    base $s$. If there exists a number in the
    array $A_i$ that is greater than or equal
    to $s$, it is considered not to meet the
    requirements.
- Convert $A_i$ and assign the resulting
    value $s'$ to $s$.

The initial value satisfies the requirements if and only if after
completing the above $n$ base conversions, $s = y$ holds.Specifically, given an array$a_{1 \dots k}$ and an initial base $s$, the conversion of
the array $a$ treated as a number in base $s$ results in:\ $s' = \sum_{i=1}^{k} a_i s^{k-i} = a_1 s^{k-1} + a_2 s^{k-2} + \dots + a_k$Little T\'s research has found that the positive integers $s$ that meet the conditions either do not
exist or are exactly all positive integers within some interval $[l, r]$. You need to report the
corresponding $l, r$, or determine that there
are no positive integers $s$ that satisfy the
conditions.

### 输入描述

This problem contains multiple test cases. The first line contains an
integer $T\ (1 \leq T \leq 10^5)$,
representing the number of test cases.For each test case:The first line contains three
integers $n, y, M\ (1 \leq n \leq 2 \times 10^5, 1 \leq y \leq 10^{9}, 2 \leq M \leq 10^{9})$.For the next $n$ lines,
the $i$-th line first contains an
integer $l_i\ (1 \leq l_i \leq 2 \times 10^5)$,
representing the length of the $i$-th
array $A_i$. It is followed
by $l_i$ integers $A_{i, j}\ (0 \leq A_{i, j} \leq 10^{9})$,
representing the contents of the array $A_i$.
It is guaranteed that the first element of the
array $A_{i, 1}$ is
not $0$.It\'s guaranteed that the total length of all arrays in a single input
does not exceed $2 \times 10^5$.

### 输出描述

For each test case:If there are no positive integers $s$ that
satisfy the requirements, output a line -1 -1;Otherwise, if all satisfying positive integers form an
interval $[l, r]$, output a line with two
integers, $l$ and $r$.

### 示例1

#### 输入

```plain
3
4 39244 100
2 1 1
2 1 1
2 1 1
6 1 1 4 5 1 4
3 1000000000 1000000000
3 1 0 0
1 65536
2 15258 51712
2 27 3
4 1 0 0 0
1 27
```

#### 输出

```plain
5 5
257 1000000000
-1 -1
```

