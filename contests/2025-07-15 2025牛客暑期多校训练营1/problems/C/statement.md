## C. Clamped Sequence 2

### 题目描述

Given an integer sequence $a_1, a_2, \ldots, a_n$, along with a weight
sequence $w_1, w_2, \ldots, w_{n-1}$, you
need to answer $q$ queries. Each query gives
a positive integer $d$, and you need to clamp
the sequence $a_1, a_2, \ldots, a_n$ to a
range $[l,r]$ satisfying $0 \le r-l \le d$ that maximizes $\sum_{i=1}^{n-1}w_i \times |a_i - a_{i+1}|$,
where $|x|$ is the absolute value of $x$.\
\
More specifically, clamping the sequence $a_1, a_2, \ldots, a_n$ to the range $[l,r]$ makes each element\
\
[[$a_i := \left\{
\begin{array}{rcl}
l,   & a_i < l; \\
a_i, & l \le a_i \le r; \\
r,   & a_i > r. \\
\end{array} \right.$]]\
\
Both $l$ and$r$ are arbitrary real numbers decided by you under the given constraints.
It can be shown that the maximum weighted sum is always an integer.

### 输入描述

The first line contains two integers$n$ ($2 \le n \le 1\,000$) and$q$ ($1 \le q \le 10^6)$, indicating the length
of the given sequence and the number of queries.\
\
The second line contains $n$ integers$a_1, a_2, \ldots, a_n$ ($-10^9 \le a_i \le 10^9$), indicating the
given sequence.\
\
The third line contains $n-1$ integers$w_1, w_2, \ldots, w_{n-1}$ ($-10^6 \le w_i \le 10^6$), indicating the
weight sequence.\
\
Then $q$ lines follow, each containing an
integer$d$ ($1 \le d \le 2 \times 10^9$), indicating the
given parameter for this query.\

### 输出描述

Output $q$ lines, each containing a single
integer, indicating the maximum weighted sum under the given parameter $d$.

### 示例1

#### 输入

```plain
6 3
3 1 4 1 5 9
2 6 5 3 5
2
3
5
```

#### 输出

```plain
32
46
54
```

#### 说明

For the first query, the clamping range can be $[1,3]$, so the sequence will be $[3, 1, 3, 1, 3, 3]$, and the value equals $2 \times |3-1| + 6 \times |1-3| + 5 \times |3-1| + 3 \times |1-3| + 5 \times |3-3| = 4 + 12 + 10 + 6 + 0 = 32$.\
\
For the second query, the clamping range can be $[1,4]$, so the sequence will be $[3, 1, 4, 1, 4, 4]$, and the value equals $2 \times |3-1| + 6 \times |1-4| + 5 \times |4-1| + 3 \times |1-4| + 5 \times |4-4| = 4 + 18 + 15 + 9 + 0 = 46$.\
\
For the third query, the clamping range can be $[1,6]$, so the sequence will be $[3, 1, 4, 1, 5, 6]$, and the value equals $2 \times |3-1| + 6 \times |1-4| + 5 \times |4-1| + 3 \times |1-5| + 5 \times |5-6| = 4 + 18 + 15 + 12 + 5 = 54$.

