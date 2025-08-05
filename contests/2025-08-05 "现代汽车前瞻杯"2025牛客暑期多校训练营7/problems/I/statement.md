## I. Lava Layer

### 题目描述

Given a positive integer $\textstyle n$ and a
non-empty set of digits $\textstyle D \subset \{1, 2, 3, 4, 5, 6, 7, 8, 9\}$.

Randomly and uniformly generate an arithmetic expression of length $\textstyle 2n-1$. The construction of this
expression follows these rules:
- All characters at odd positions
    ($\textstyle 1$-indexed) will be a digit
    chosen uniformly at random from the given set of digits $\textstyle D$.
- All characters at even positions
    ($\textstyle 1$-indexed) will be an
    operator chosen uniformly at random from$\textstyle \{+, \times, \land, \lor, \oplus\}$     (addition, multiplication, bitwise AND, bitwise OR, bitwise XOR).

For example, if $\textstyle n=2$ and the
digit set $\textstyle D=\{1, 2\}$, the
expression may be $\textstyle 1 + 1$, $\textstyle 2 \lor 1$, etc.

Calculate the expected value of this randomly generated expression,
modulo $\textstyle 998244353$.

Note: All operators have the **same precedence**, and operations are
performed from left to right.

### 输入描述

The first line contains an integer$\textstyle t$ ($\textstyle 1 \le t \le 100$), representing
the number of test cases.

For each test case, the first line contains two integers$\textstyle n,k$ ($\textstyle 1 \le n \le 10^{18}$, $\textstyle 1 \le k \le 9$).

The second line contains$\textstyle k$ distinct integers, representing the elements of set $\textstyle D$. Each element is within the
range of $\textstyle 1$ to $\textstyle 9$.

### 输出描述

For each test case, print a single integer on a line, representing the
expected value of the expression modulo $\textstyle 998244353$.

It can be proven that the answer can be expressed as $\textstyle \dfrac pq$ where $\textstyle p$ and $\textstyle q$ are integers, and there exists
a unique integer $\textstyle x\in [0,998244353)$ such that $\textstyle qx \equiv p\pmod{998244353}$. You
need to output this $\textstyle x$.

### 示例1

#### 输入

```plain
3
1 1
5
2 2
1 2
10000 9
1 2 3 4 5 6 7 8 9
```

#### 输出

```plain
5
848507702
463950893
```

