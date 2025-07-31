## G. Turn around

### 题目描述

There are $n$ people standing on a number
line, each facing either left (\'L\') or right (\'R\'). A string $S$ of length$n$ is given, where each character is \'L\' or \'R\', representing the
initial direction of each person. At each moment, when two adjacent
people face each other (i.e., the left one faces right and the right one
faces left), they will turn around simultaneously: if a person faces
left, he turns right; and vice versa.Your task is to determine the time after which no one\'s direction
changes anymore.Additionally, there are $q$ modifications.
Each modification gives an index $x$, meaning
the initial direction of the $x$-th person is
flipped (from \'L\' to \'R\' or vice versa). After each modification,
output the answer to the above problem.

### 输入描述

The first line contains two
integers $n$ ($1 \le n \le 2\cdot 10^5$)
and $q$ ($1 \le q \le 2\cdot 10^5$).The second line contains a string $S$ of
length $n$, representing the initial
direction of each person.The next $q$ lines contain an
integer $x$ ($1\leq x\leq n$).

### 输出描述

Print $q$ lines. Each line contains an
integer, representing the answer.

### 示例1

#### 输入

```plain
5 5
LRLRL
5
1
3
4
3
```

#### 输出

```plain
1
2
0
3
3
```

### 示例2

#### 输入

```plain
5 5
RLLLL
1
2
3
4
5
```

#### 输出

```plain
0
3
3
3
0
```

