## C. Computational Geometry Problem

### 题目描述

Given integer $N$, $M$, and $K$,
calculate the number of integer sequences $A = [A_1,A_2,\ldots,A_{NM}]$ satisfying the
following constraint:

1.  $1 \le A_i \le M$ and each number from $1$ to$M$ appears in $A$ exactly $N$ times;
2.  There do not exist integers $1 \le i<j<k<\ell \le NM$ satisfying $A_i = A_k$, $A_j = A_\ell$, and $A_i \neq A_j$;
3.  The number of $1 \le i < NM$ such that $A_i = A_{i+1}$ is $K$.

The answer might be enormous, and you should output the answer modulo $998\,244\,353$.

### 输入描述

The only line of the input contains three integers $N$ , $M$ and$K$ ($1 \le N,M \le 10^7$, $0 \le K \le NM-1$).

### 输出描述

Output a single integer, denoting the answer modulo $998\,244\,353$.

### 示例1

#### 输入

```plain
3 3 6
```

#### 输出

```plain
6
```

### 示例2

#### 输入

```plain
3 3 5
```

#### 输出

```plain
36
```

### 示例3

#### 输入

```plain
5 3 3
```

#### 输出

```plain
0
```

### 示例4

#### 输入

```plain
35 13 433
```

#### 输出

```plain
131803241
```
