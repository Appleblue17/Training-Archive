## L. Float

### 题目描述

**赛后数据加强，已经通过的代码不再重测**

There are $\textstyle n$ levels, the $\textstyle i$-th level allows one traveling
from point $\textstyle i-1$ to point $\textstyle i$ ; you start at point $\textstyle 0$ , and want to pass through
each level sequentially to reach point $\textstyle n$. Each time you attempt a
level, you have a probability$\textstyle p$ of passing and a probability $\textstyle (1-p)$ of failing.

Initially you have some number of coins, if you fail and have at least
one coin, you will stay at the current level and retry by consuming one
coin (you won't leave it unused even if you are at point $\textstyle 0$); and if you fail and have no
coins left, you will be kicked back to the starting point (point $\textstyle 0$) .

Given $\textstyle m$, calculate the expected
number of steps to reach the endpoint for every possible initial number
of coins from $\textstyle 0$ to $\textstyle m$, modulo $\textstyle 998244353$.

### 输入描述

The first line contains three integers $\textstyle n$, $\textstyle m$, and$\textstyle p$ ($\textstyle 1\leq n \leq 10^9$，$\textstyle 1 \leq m \leq 2 \times 10^5$，$\textstyle 0 < p < 998244353$),
representing the number of levels, the maximum number of coins, and the
probability of passing a level.

### 输出描述

A single line containing$\textstyle m+1$ integers, where the $\textstyle i$-th number
represents the expected number of steps to reach the endpoint when
starting with $\textstyle i-1$ coins.

### 示例1

#### 输入

```plain
2 2 499122177
```

#### 输出

```plain
6 499122182 5
```

#### 说明



### 示例2

#### 输入

```plain
1 3 332748118
```

#### 输出

```plain
3 3 3 3
```

#### 说明

Under modulo $\textstyle 998244353$, the
value $\textstyle 332748118$ corresponds to a
probability of $\textstyle \frac{1}{3}$.

In this scenario, the result is independent of $\textstyle m$, because regardless of whether
coins are available or not, failure always results in returning to the
starting point.

### 示例3

#### 输入

```plain
1000000000 1 1
```

#### 输出

```plain
1755647 1755647
```

