## I. Identical Somehow

### 题目描述

A hash function converts data into an output string with a fixed number
of characters; therefore, it creates a \"tag\" for each data.

In this problem, inputs are always integers. It can be a bad thing if
two different integers $x,y\ (x\neq y)$ are
converted into the same string. These two integers are considered
identical somehow from the hash function. It is called a hash
collision.

We consider the following hash function with parameter $k$:
\ $H(x)=(x\bmod k)+(k\bmod x)$

For each input pair $(x,y)\ (x\neq y)$, is
there a hash function that results in a hash collision? If there is,
output any such $k$ ; otherwise, output $-1$ .

### 输入描述

Each test contains multiple test cases. The first line contains the
number of test cases $T\ (1≤T≤10^4)$ .

Each test case consists of one line. The line contains two integers $x,y\ (1\leq x, y\leq 10^9, x\neq y)$, the
elements of the pair.

### 输出描述

For each test case, output one integer \-\-- the parameter $k\ (1\leq k\leq 10^{18})$ that causes a hash
collision. If there is no such positive number no larger than $10^{18}$ that satisfies the condition,
output $-1$ instead.

### 示例1

#### 输入

```plain
2
5 9
9 15
```

#### 输出

```plain
4
6
```

#### 说明

For the first case, $5\bmod 4+4\bmod 5=1+4=5, 9\bmod 4+4\bmod9=1+4=5$.

For the second case, $9\bmod 6+6\bmod 9=3+6=9, 15\bmod 6+6\bmod 15=3+6=9$.
