## I. Matrix (matrix)

### 题目描述

Piggy has an $n\times m$ **cyclic** matrix
(or Torus). That is, the $n$-th row and the $1$-st row are adjacent, and the $m$-th column and the $1$-st column are adjacent. You need to fill
the matrix with integers from $1$ to $nm$ to ensure the following conditions
hold:
- Each integer from $1$ to $nm$, inclusive, appears exactly once in
    the matrix. That is, exactly one grid in the matrix contains each
    integer.
- For every $1\leq i\leq nm-1$, the grid
    filled with $i$ and the grid filled with $i+1$ are either in the same row or in
    the same column.
- For every $1\leq i\leq nm-1$, if Piggy
    starts from the grid filled with$i$     initially, there always exists a direction from left, right, up, and
    down, so that he can reach the grid filled with $i+1$ by moving towards that direction
    for exactly $i$ grids. Note that the
    matrix is cyclic, meaning that he will reach the $1$-st row if moving down for one grid in
    the $n$-th row, and reach the $1$-st column if moving right for one
    grid in the $m$-th column, and vice
    versa.

Construct a legal matrix or report that no legal matrix exists.

### 输入描述

The only line contains two positive integers$n,m$ ($1\leq n,m,nm\leq 10^6$).

### 输出描述

The first line contains either$\texttt{YES}$ or $\texttt{NO}$, indicating whether or not
you have found a legal matrix.

If the answer is $\texttt{YES}$, then $n$ lines follow, each
containing $m$ integers, describing the legal
matrix.

**Outputting any legal matrix will be considered correct.**

### 示例1

#### 输入

```plain
4 5
```

#### 输出

```plain
YES
1 9 14 15 8
2 10 3 16 17
20 19 4 5 18
12 11 13 6 7
```

### 示例2

#### 输入

```plain
4 6
```

#### 输出

```plain
NO
```

