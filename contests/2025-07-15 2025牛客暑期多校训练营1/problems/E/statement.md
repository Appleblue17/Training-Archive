## E. Endless Ladders

### 题目描述

In the ancient Square Kingdom, the resident$c$ ($c=1,2,3,\ldots$) lives on a stone pillar
that is $c^2$ units high from the ground.

For the convenience of visiting each other, the Square King built
ladders of different lengths. A ladder of length $d$ enables two residents that the absolute
difference between their heights is exactly $d$ to visit each other. Due to the limited
budget, a ladder of length $d$ is built if
and only if there are two residents such that the absolute difference
between their heights is exactly $d$, and
only one ladder of the same length will be built.

The ladders are labeled with positive integers $1,2,3,\ldots$ starting from the shortest
length. One day the resident $a$ wants to
visit the resident $b$, and you need to find
the label of the ladder they should use.

### 输入描述

The first line of the input contains an integer$T$ ($1 \le T \le 10^4$), indicating the number
of test cases. For each test case:

The only line contains two integers $a$ and$b$ ($1\le a,b \le 10^9, a\neq b$), indicating
that the resident $a$ is going to visit the
resident $b$.

### 输出描述

For each test case, output a line containing an integer, indicating the
label of the used ladder.

### 示例1

#### 输入

```plain
2
3 1
2 5
```

#### 输出

```plain
4
14
```

#### 说明

The lengths of the first $5$ labeled ladders
are $3,5,7,8,9$ respectively.

For the first sample case, the length of the used ladder is $3^2 - 1^2 = 8$, which is labeled with $4$.
