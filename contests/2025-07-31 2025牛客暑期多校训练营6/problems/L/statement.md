## L. Minimum Parenthesis String

### 题目描述

Given $m$ intervals, find a valid parenthesis
string of length $2n$ that is
lexicographically smallest, such that there is at least one left
parenthesis in each interval. If there is no solution, output -1.We define that the lexicographic order of a left parenthesis is smaller
than that of a right parenthesis.

### 输入描述

This problem contains multiple test cases. The first line contains an
integer $T\ (1 \leq T \leq 10^5)$,
representing the number of test cases.For each test case, the first line contains two positive
integers $n$ and $m$ $(1 \leq n \leq 10^5,  0 \leq m \leq 10^5)$,
representing half the length of the parenthesis string to be constructed
and the number of restricted intervals, respectively.Next, there are $m$ lines, each containing
two positive
integers $l$ and $r$ $(1 \leq l \leq r \leq 2n)$,
indicating that the constructed parenthesis string must have at least
one left parenthesis in the
interval $[l,r]$.It is guaranteed
that $\sum n \leq 2\cdot 10^5$ and $\sum m \leq 4\cdot 10^5$.

### 输出描述

For each test case, output a string representing the constructed
lexicographically smallest valid parenthesis string. If there is no
solution, output -1.

### 示例1

#### 输入

```plain
3
2 2
1 2
3 4
3 4
1 1
2 2
3 3
4 4
5 3
2 4
3 9
7 10
```

#### 输出

```plain
()()
-1
(((())()))
```

