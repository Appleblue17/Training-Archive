## H. Symmetry Intervals 2

### 题目描述

<div>

**The time limit has been changed from 4 seconds to 2 seconds for
upsolving.**

<div>

<div>

Given a binary string $S$ of length $n$, you need to answer $q$ queries, where each query is in one of
the following two types:

1.  Given two integers$l,r$ ($1 \le l \le r \le n$), flip the binary
    bit $S_i$ for each $i \in [l,r]$.
2.  Given three integers$l,a,b$ ($1 \le l \le n, 1 \le a,b \le n - l + 1$),
    you need to find the number of intervals$[u,v]$ ($1 \le u \le v \le l$) such that $S_{a+x-1} = S_{b+x-1}$ holds for every
    integer $x \in [u,v]$, which are called
    symmetry intervals.

</div>

</div>

</div>

### 输入描述

The first line contains two integers $n$ and$q$ ($1\le n, q \le 10^6$), indicating the length
of the given string $S$ and the number of
queries.

The second line contains the given binary string $S$ of length $n$.

The next $q$ lines each contain a query,
which is in one of the following two types:
 ·$1\ l\ r$ ($1 \le l \le r \le n$), indicating that for
each binary bit$S_i$ ($i \in [l,r]$), flip the binary bit $S_i$ for each $i \in [l,r]$.
 ·$2\ l\ a\ b$ ($1 \le l \le n, 1 \le a,b \le n - l + 1$),
indicating that you need to find the number of intervals$[u,v]$ ($1 \le u \le v \le l$) such that $S_{a+x-1} = S_{b+x-1}$ holds for every
integer $x \in [u,v]$.

It is guaranteed that the number of type-2 queries does not exceed $2\,500$.

### 输出描述

For each type-2 query, output a line containing an integer, indicating
the number of symmetry intervals.

### 示例1

#### 输入

```plain
10 3
1001001001
2 4 3 5
1 2 6
2 5 2 6
```

#### 输出

```plain
2
7
```

#### 说明

For the first query, $S_{3..6} = 0100$, $S_{5..8} = 0010$, the $2$ symmetry intervals are $[1,1]$ and $[4,4]$.

After the second query, $S$ becomes $1110111001$.

For the third query, $S_{2..6} = 11011$, $S_{6..10} = 11001$, the $7$ symmetry intervals are $[1,1]$, $[1,2]$, $[1,3]$, $[2,2]$, $[2,3]$, $[3,3]$,
and $[5,5]$.
