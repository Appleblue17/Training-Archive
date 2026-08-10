## E. String

### 题目描述

For a certain binary string$\textstyle s$ (composed only of $\textstyle \texttt{0}$s
and $\textstyle \texttt{1}$s) and a positive
integer $\textstyle k$, define a function $\textstyle f(s,k)$ as the minimum increase
in the length of the longest palindromic substring after appending
exactly $\textstyle k$ characters (which can
only be $\textstyle \texttt{0}$ or $\textstyle \texttt{1}$) to the end of $\textstyle s$, relative to the length of the
longest palindromic substring of the original string $\textstyle s$.

You are given a binary string$\textstyle s$ and a positive integer $\textstyle k$.
Compute and output the sum of $\textstyle f(s',k)$ values for all non-empty
substrings $\textstyle s'$ of $\textstyle s$.

We define a substring as a contiguous subsegment of a string.

### 输入描述

The first line contains an integer$\textstyle t$ ($\textstyle 1 \le t \le 10^5$), representing
the number of test cases.

For each test case, the first line contains a binary string$\textstyle s$ ($\textstyle 1 \le |s| \le 5 \times 10^5$)
and a positive integer$\textstyle k$ ($\textstyle 1 \le k \le 10^9$), separated by
a single space.

It is guaranteed that the sum of $\textstyle |s|$ over all test cases does not
exceed $\textstyle 5 \times 10^5$.

### 输出描述

For each test case, you should output a single integer representing the
sum of $\textstyle f(s',k)$ values for all
non-empty substrings $\textstyle s'$ of $\textstyle s$.

### 示例1

#### 输入

```plain
3
010 1
010 2
0101011101001 100
```

#### 输出

```plain
2
7
108
```

#### 说明

In the first test case, $\textstyle f(\texttt{01},1)=f(\texttt{10},1)=1$,
and others equal $\textstyle 0$.

