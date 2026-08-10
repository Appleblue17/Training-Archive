## D. Beautiful Matrix

### 题目描述

A beautiful matrix $A$ with $n$ rows and$n$ columns satisfies the following condition:
- All elements are integers
    between $0$ and $m$.
- $A_{i, 1}=0$ for $1 \leq i \leq n$.
- $A_{i, j} \leq A_{i, j+1}$ for $1 \leq i \leq n$ and $1 \leq j \lt n$.
- $A_{i, j}+A_{k, l} \leq A_{i, l}+A_{k, j}$ for
    every quadruple of
    integers $(i,j,k,l)$ such
    that $1 \leq i \lt k \leq n$ and $1 \leq j \lt l \leq n$.

You are given two integers $n$ and $m$, find the number, mod $998244353$, of beautiful matrices.

### 输入描述

The first line contains two
integers $n$ and $m$ ($2 \le n \le 5\cdot 10^5$, $1 \le m \le 5\cdot 10^5$).

### 输出描述

Print the answer.

### 示例1

#### 输入

```plain
2 1
```

#### 输出

```plain
3
```

### 示例2

#### 输入

```plain
29912 86488
```

#### 输出

```plain
461289656
```

### 示例3

#### 输入

```plain
4 3
```

#### 输出

```plain
455
```

