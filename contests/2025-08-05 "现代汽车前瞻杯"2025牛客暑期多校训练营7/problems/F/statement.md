## F. The Correlation

### 题目描述

You're given an integer sequence $\textstyle a_1, a_2, \dots, a_n$ of length $\textstyle n$. You can perform an operation
no more than $\textstyle n$ times: choose an
integer $\textstyle v$, and update each
number: $\textstyle a_i$ to $\textstyle |a_i - v|$.

Find the minimum possible sum of absolute differences between all
distinct pairs of elements in the sequence after performing some
operations. That is, minimize $\textstyle \sum\limits_{1 \le i < j \le n} |a_i - a_j|$.

Since the answer may be large, output this minimum sum modulo $\textstyle 998244353$.

### 输入描述

The first line contains a single integer$\textstyle n$ ($\textstyle 1 \le n \le 2 \times 10^5$).

The second line contains$\textstyle n$ integers$\textstyle a_1, a_2, \dots, a_n$ ($\textstyle 0 \le a_i \le 10^9$).

### 输出描述

Output a single integer, the minimum possible sum$\textstyle \sum\limits_{1 \le i < j \le n} |a_i - a_j|$ modulo $\textstyle 998244353$.

### 示例1

#### 输入

```plain
3
5 10 15
```

#### 输出

```plain
2
```

### 示例2

#### 输入

```plain
5
0 0 0 0 1
```

#### 输出

```plain
4
```

