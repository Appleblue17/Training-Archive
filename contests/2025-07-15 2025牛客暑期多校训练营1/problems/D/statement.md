## D. LCM Challenge

### 题目描述

*There are lots of things to do in this contest besides this problem, so
let\'s make it quick.*\
\
Given two integers $n$ and $p$, where $p$ is
prime, you need to find the value of $\text{LCM}(1,2,3,\ldots,n) \bmod p$, i.e.,
the least common multiple of$1,2,3,\ldots,n$ modulo $p$.\

### 输入描述

The only line contains two integers $n$ and$p$ ($1 \le n < p < 10^{10}$), where $p$ is prime.\

### 输出描述

Output a line containing a single integer, indicating the value of $\text{LCM}(1,2,3,\ldots,n) \bmod p$.\

### 示例1

#### 输入

```plain
10 9999999967
```

#### 输出

```plain
2520
```

#### 说明

For the first sample case, $\text{LCM}(1,2,3,\ldots,10) = 2^3 \times 3^2 \times 5 \times 7 = 2520$.

### 示例2

#### 输入

```plain
30 9999999967
```

#### 输出

```plain
9089570456
```

#### 说明

For the second sample case, $\text{LCM}(1,2,3,\ldots,30) = 2\,329\,089\,562\,800$.

### 示例3

#### 输入

```plain
9999999966 9999999967
```

#### 输出

```plain
6047288450
```

