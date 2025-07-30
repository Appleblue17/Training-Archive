## B. Bitwise Puzzle

### 题目描述

<div>

Yuki gives you three non-negative integers $a$, $b$, and $c$. You can perform the following operations
up to $k = 64$ times:

1.  $a \gets a \cdot 2$;
2.  $b \gets \lfloor \frac{b}{2} \rfloor$;
3.  $a \gets a \oplus b$, where $\oplus$ denotes the bitwise XOR;
4.  $b \gets b \oplus a$.

Please make $a = b = c$ within no more than $k$ operations, or report that there is no
valid solution. It can be proven that under the constraints of the
problem, there will be a valid solution that does not exceed $k = 64$ operations if a valid solution
exists.

</div>

### 输入描述

Each test contains multiple test cases. The first line of input contains
a single integer$t$ ($1 \leq t \leq 10^4$) --- the number of test
cases. The description of the test cases follows.

The first and only line of input of each test case contains three
integers $a$, $b$,
and$c$ ($0 \leq a, b, c < 2^{31}$).

### 输出描述

<div>

For each test case:

</div>

<div>

</div>

<div>

If there is no valid solution, output a single line containing an
integer $-1$;

</div>

<div>

Otherwise, output two lines. The first line contains an
integer $p$ ($0 \leq p \leq k$),
describing the number of operations you performed; the second line
contains $p$ integers, each in the
range $[1, 4]$, indicating the sequence of
the indices of the operations you performed.

</div>

### 示例1

#### 输入

```plain
4
3 5 6
0 0 1
7 7 7
2 9 4
```

#### 输出

```plain
2
4 1
-1
0

2
1 2
```

### 备注

In the first test case, initially $a = 3$, $b = 5$, $c = 6$.
After the first operation, $a = 3$, $b = 6$, $c = 6$;
after the second operation, $a = b = c = 6$,
which meets the requirement.

In the second test case, regardless of how the operations are performed, $a = b = 0$, which cannot satisfy $a = b = c$.
