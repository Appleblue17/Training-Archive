## H. Highs and Lows

### 题目描述

Given integers $a_1,a_2,\ldots,a_n$ and $M$, please find out a polynomial $f(x)=\sum_{i=0}^k c_i x^i$ with integer
coefficients satisfying

1.   for all $1 \le i \le n$, $f(i) \equiv a_i \pm 1 \mod M$.
2.   $k$ is minimized.

### 输入描述

The first line of the input contains integers $n$ and$M$ ($1 \le n \le 30$, $2 \le M \le 10^9$).

The second line of the input contains$n$ integers$a_1,a_2,\ldots,a_n$ ($0 \le a_i < M$).

Please note that $M$ is not necessarily a
prime number.

### 输出描述

If there exists no solution, output $-1$ in
one line.

Otherwise, output a single integer$k$ ($0 \le k \le 10^6$) in one line. Then,
output $k+1$ integers$c_0,c_1,\ldots,c_k$ ($0 \le c_i<M$), denoting the coefficients of
the polynomial. If there exist multiple solutions, output any.

### 示例1

#### 输入

```plain
5 998244353
1 3 5 9 11
```

#### 输出

```plain
1
0 2
```

### 示例2

#### 输入

```plain
5 998244353
1 4 9 16 25
```

#### 输出

```plain
2
998244352 0 1
```

### 示例3

#### 输入

```plain
7 19
1 1 2 3 5 8 13
```

#### 输出

```plain
5
13 18 13 1 1 11
```

### 示例4

#### 输入

```plain
6 998244353
1 2 4 8 16 31
```

#### 输出

```plain
4
0 748683264 707089751 249561088 291154603
```
