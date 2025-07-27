## E. Equal

### 题目描述

Yuki gives you a sequence of positive integers $a_1, \ldots, a_n$ of length $n$, you can perform the following two
operations any number of times:\
- Choose positive integers $i, j, d$ such
    that $1 \leq i < j \leq n$ and $d \mid a_i, d \mid a_j$, then update $a_i \gets \frac{a_i}{d}$ while $a_j \gets \frac{a_j}{d}$;
- Choose positive integers $i, j, d$ such
    that $1 \leq i < j \leq n$, then update $a_i \gets a_i \cdot d$ while $a_j \gets a_j \cdot d$.

Determine whether it is possible to make $a_1 = a_2 = \ldots = a_n$ after several
operations.\

### 输入描述

Each test contains multiple test cases. The first line of input contains
a single integer$t$ ($1 \leq t \leq 10^5$) --- the number of test
cases. The description of the test cases follows.\
\
The first line contains an integer$n$ ($1 \leq n \leq 10^6$), representing the
length of the sequence.\
\
The second line contains $n$ integers$a_1, \ldots, a_n$ ($1 \leq a_i \leq 5\cdot 10^6$), describing
the given sequence.\
\
It is guaranteed that the sum of $n$ across
all test cases does not exceed $2\cdot 10^6$.\

### 输出描述

For each test case, print \"$\texttt{YES}$\"
(without quotes) if it\'s possible to make all elements in $a$ equal after several operations, and
\"$\texttt{NO}$\" (without quotes)
otherwise.\
\
You can output the answer in any case (upper or lower). For example, the
strings \"$\tt{yEs}$\",
\"$\tt{yes}$\",
\"$\tt{Yes}$\", and
\"$\tt{YES}$\" will be recognized as positive
responses.\

### 示例1

#### 输入

```plain
6
1
6
2
2 4
3
1 3 3
4
5 3 15 2
5
1 3 8 7 6
6
13 15 39 169 9 5
```

#### 输出

```plain
YES
NO
YES
NO
YES
YES
```

### 备注

In the first test case, since $n = 1$, all
numbers are already the same, so the answer is
\"$\texttt{YES}$\".\
\
In the second test case, it can be shown that no matter what operation
we perform, $a_1$ cannot be made equal to $a_2$.\
\
In the third test case, you can choose $i = 2$, $j = 3$, $d = 3$ and perform the first operation,
transforming the original sequence into $[1, 1, 1]$, where all numbers are the same;
thus, the output is \"$\texttt{YES}$\".\

