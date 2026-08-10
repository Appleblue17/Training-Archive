## J. Multiplication in Base the Square Root of -2

### 题目描述

In this problem, you are asked to solve an easy task \-- $A$ **multiplies** $B$.Let$U = \{a + b \sqrt{-2} | a, b \in \mathbb{Z}\}$ be the whole set where multiplications will be taken. Obviously, the
product of any two elements in $U$ is also an
element in $U$.Each element $x \in U$ can be represented in
base $\sqrt{-2}$ as a 01-string of length $n$ in the form of $(c_{n-1} c_{n-2} \ldots c_0)_{\sqrt{-2}}$,
where $x = \sum_{i = 0}^{n - 1}{c_i \sqrt{-2}^i}$,$c_i \in \{0, 1\}$ ($i = 0, 1, \ldots, n - 1$) and when $n > 1$, $c_{n - 1} = 1$. For example,$-1 + \sqrt{-2} = \sqrt{-2}^0 + \sqrt{-2} + \sqrt{-2}^2 = (111)_{\sqrt{-2}}$ and $2 - 4 \sqrt{-2} = (4 - 2) + (-8 + 4) \sqrt{-2} = \sqrt{-2}^2 + \sqrt{-2}^4 + \sqrt{-2}^5 + \sqrt{-2}^7 = (10110100)_{\sqrt{-2}}$.Your task is to calculate the product of two elements $A$ and $B$ of $U$ in base $\sqrt{-2}$ representation.

### 输入描述

The first line contains an integer$T$ ($1 \leq T \leq 10^5$), indicating the number
of test cases.Then follow $T$ test cases. For each test
case:The only line contains two 01-strings $A$ and$B$ ($|A|, |B| \geq 1, |A| + |B| \leq 2 \times 10^5$).It is guaranteed that the sum of $(|A| + |B|)$ over $T$ test cases does not exceed $2 \times 10^6$.

### 输出描述

For each test case, output a 01-string in one line, representing the
product of $A$ and $B$ in base $\sqrt{-2}$.

### 示例1

#### 输入

```plain
5
0 1
10 10
10 11
101 101
110 110
```

#### 输出

```plain
0
100
110
1
10110100
```

#### 说明

For the last test case of the example, $(-2 + \sqrt{-2})^2 = 2 - 4 \sqrt{-2}$.

