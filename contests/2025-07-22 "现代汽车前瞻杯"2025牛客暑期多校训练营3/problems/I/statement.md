## I. Infinity

### 题目描述

Let $S_n$ be the set of all $n$-ordered permutations. For $\sigma \in S_n$, let $\nu(\sigma)$ be the number of elements in
the set $\{ \mu^{-1}\sigma \mu \mid \mu \in S_n \}$.

Given a fixed integer $k$, you have received
multiple queries of $n$, and for each of the
values, you must compute
\ $\sum_{\sigma \in S_n}\nu(\sigma)^k,$

taken modulo $998244353$.

### 输入描述

The first line of input contains two integers $t$ and$k$ ($1 \leq t \leq 10^3$, $1 \leq k \leq 10^9$) --- the number of test
cases and the given constant value.

Then $t$ lines follow. Each line contains a
positive integer$n$ ($1 \leq n \leq 2\cdot 10^5$), representing a
query.

### 输出描述

Output a total of $t$ lines. For each query,
output a single line containing an integer, representing your answer
modulo $998244353$.

### 示例1

#### 输入

```plain
7 1
1
2
3
4
5
6
7
```

#### 输出

```plain
1
2
14
146
2602
71412
2675724
```

### 示例2

#### 输入

```plain
8 5
2
10
50
250
1250
6250
31250
100000
```

#### 输出

```plain
2
738630138
158601508
770726379
894346889
987370821
445104440
460384381
```
