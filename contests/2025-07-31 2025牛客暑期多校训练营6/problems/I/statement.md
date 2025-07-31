## I. Longest Common Substring

### 题目描述

The longest common substring between two strings is the longest sequence
of consecutive characters that appears in both strings.Given a string $s$ of length $n$ and$q$ queries, each query provides two parameters $l$ and $r$.
Calculate the length of the longest common substring between the prefix $s[1..l]$ and the suffix $s[r..n]$.

### 输入描述

The first line contains two positive
integers $n$ and $q$ ($1 \leq n, q \leq 2\cdot 10^5$)
\-\-- the length of the string $s$ and the
number of query operations.The second line contains a
string $s$ consisting
of $n$ lowercase English letters.The following $q$ lines each contain two
positive
integers $l$ and $r$ ($1 \leq l, r \leq n$).

### 输出描述

For each query operation, output an integer on a separate line,
representing the length of the longest common substring
between $s[1..l]$ and $s[r..n]$.

### 示例1

#### 输入

```plain
10 14
aaabaaaaab
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
7 1
4 8
6 10
5 5
2 5
```

#### 输出

```plain
1
2
3
4
4
4
3
2
1
7
3
1
4
2
```

