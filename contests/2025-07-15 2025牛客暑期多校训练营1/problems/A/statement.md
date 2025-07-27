## A. Rectangular Posters

### 题目描述

A rectangular board with sides parallel to the coordinate axes lies on a
two-dimensional plane. The bottom-left corner of the board has
coordinates $(0, 0)$, and the top-right
corner has coordinates $(W, H)$.\
\
There are $n$ rectangular posters, the $i$-th of which has a width of$w_i$ ($1 \le w_i < W$) and a height of$h_i$ ($1 \le h_i < H$). These posters are placed
fully inside the board randomly and independently, without being rotated
or flipped, and the sides are parallel to the coordinate axes. More
specifically, the bottom-left corner of the $i$-th poster has coordinates $(x_i, y_i)$, and the top-right corner has
coordinates $(x_i + w_i, y_i + h_i)$, where
each $x_i$ is independently and uniformly
randomly chosen from $[0, W - w_i]$, and each $y_i$ is independently and uniformly randomly
chosen from $[0, H - h_i]$.\
\
You need to find the expected area covered by the $n$ posters modulo $10^9+7$.\

### 输入描述

The first line contains three integers$n$ ($1 \le n \le 120$), $W$, and$H$ ($2 \le W, H \le 10^9$), indicating the
number of rectangular posters, the width, and the height of the
rectangular board.\
\
Then $n$ lines follow, the $i$-th of which contains two integers$w_i$ ($1 \le w_i < W$) and$h_i$ ($1 \le h_i < H$), indicating the width and
the height of the $i$-th rectangular poster.\

### 输出描述

Output a line containing an integer, indicating the expected area
covered by the $n$ posters modulo $10^9+7$.\
\
It can be proved that the probability is always a rational number.
Additionally, under the constraints of this problem, it can also be
proved that when that value is represented as an irreducible fraction $p/q$, we have $q \not\equiv 0 \pmod{10^9+7}$. Thus, there
is a unique integer$r$ ($0 \le r < 10^9+7$) such that $p \times r \equiv q \pmod{10^9+7}$. This $r$ is what we need.\

### 示例1

#### 输入

```plain
1 2 2
1 1
```

#### 输出

```plain
1
```

#### 说明

For the first sample case, the expected covered area is $1$.

### 示例2

#### 输入

```plain
2 2 2
1 1
1 1
```

#### 输出

```plain
555555561
```

#### 说明

For the second sample case, the expected covered area is $14/9$.\

