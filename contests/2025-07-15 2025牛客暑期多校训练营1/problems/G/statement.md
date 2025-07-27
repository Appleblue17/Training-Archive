## G. Symmetry Intervals

### 题目描述

Given a string $S$ of length $n$, you need to answer $q$ queries.\
\
For each query, a string $T$ and an integer$a$ ($1 \le a \le n - |T| + 1$) are given, and
you need to find the number of intervals$[u,v]$ ($1 \le u \le v \le |T|$) that $S_{a+x-1} = T_{x}$ holds for every integer $x \in [u,v]$, which are called symmetry
intervals. Note that $|T|$ is the length of $T$.\

### 输入描述

The first line contains two integers$n$ ($1\le n \le 10^5$) and$q$ ($1\le q \le 10^5$), indicating the length of
the given string $S$ and the number of
queries.\
\
The second line contains the given string$S$ of length $n$.\
\
The next $q$ lines each contain a string$T$ ($1 \le |T| \le n$) and an integer$a$ ($1 \le a \le n - |T| + 1$), indicating a
query.\
\
It is guaranteed that the sum of $|T|$ does
not exceed $10^6$ and that all input strings
only contain lowercase English letters.\

### 输出描述

For each query, output one line containing one integer, denoting the
number of symmFor each query, output one line containing one integer,
indicating the number of symmetry intervals.etry intervals.

### 示例1

#### 输入

```plain
10 3
helloworld
follow 1
echo 2
nowgold 4
```

#### 输出

```plain
10
2
6
```

#### 说明

For the first query, the $10$ symmetry
intervals are $[3,3]$, $[3,4]$, $[3,5]$, $[3,6]$, $[4,4]$, $[4,5]$, $[4,6]$, $[5,5]$, $[5,6]$,
and $[6,6]$.\
\
For the second query, the $2$ symmetry
intervals are $[1,1]$ and $[4,4]$.\
\
For the third query, the $6$ symmetry
intervals are $[2,2]$, $[2,3]$, $[3,3]$, $[6,6]$, $[6,7]$,
and $[7,7]$.\

