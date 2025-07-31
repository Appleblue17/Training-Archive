## B. Binary Substrings 2

### 题目描述

Given two integers $n$ and $m$, you need to find a binary string of
length $n$ such that the number of different
nonempty substrings is exactly $m$. Here, $m$ is no less than $n$, the minimum number of different nonempty
substrings in a binary string of length $n$,
and is no more than $M_n = \sum_{i=1}^{n} \min\{2^i, n-i+1\}$,
the proved maximum number.

However, the problem described above seems too hard, so you just need to
find a binary string of length $n$ such that
the number of different nonempty substrings has at most $0.2$ relative error with $m$, i.e., is in the range $[0.8 \times m, 1.2 \times m]$, or indicate
that no binary string meets this condition.

### 输入描述

The first line of the input contains an integer$T$ ($1 \le T \le 10^4$), indicating the number
of test cases. For each test case:

The only line contains two integers$n$ ($1 \le n \le 2 \times 10^5$) and$m$ ($n \le m \le M_n$).

It is guaranteed that the sum of $n$ for all
test cases does not exceed $2 \times 10^5$.

### 输出描述

For each test case, output a line containing a binary string of length $n$ that meets the condition, or \`\`-1\'\'
(without quotes) if no binary string meets the condition.

### 示例1

#### 输入

```plain
5
5 5
5 6
5 7
5 8
5 9
```

#### 输出

```plain
00000
00000
-1
00001
00001
```

### 示例2

#### 输入

```plain
5
1 1
2 3
3 5
4 8
5 12
```

#### 输出

```plain
0
01
011
0110
01100
```
