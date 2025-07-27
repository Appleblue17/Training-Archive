## I. Iron Bars Cutting

### 题目描述

There are $n$ iron bars, where the length of
the $i$-th iron bar is $a_i$. These$n$ iron bars are welded together in the order of $1, 2, 3, \ldots, n$ to form a very long iron
bar for some usage. Welding two adjacent iron bars creates a weld point,
resulting in a total of $n-1$ weld points.\
\
Little Q needs to cut this long iron bar back into $n$ iron bars. Each time he can choose an
iron bar that has at least one weld point and select a weld point to cut
the iron bar into two at that weld point, then let the lengths of the
resulting two iron bars be $l_1$ and $l_2$. The imbalance of this cut is defined
as $|l_1 - l_2|$, and the cost of the cut is
defined as $\min\{l_1,l_2\} \times \lceil \log_2(l_1+l_2) \rceil$.
Note that $|x|$ is the absolute value of $x$, and $\lceil \log_2(y) \rceil$ is the smallest
integer $z$ such that $2^z \ge y$.\
\
Little Q hopes that the imbalances of the $n-1$ cuts, denoted as $b_1, b_2, \ldots, b_{n-1}$, satisfy $b_1 \ge b_2 \ge \cdots \ge b_{n-1}$, and the
total cost of these $n-1$ cuts is minimized.
You need to find the minimum total cost for the first cut at the weld
point between the $i$-th and
($i+1$)-th iron bars, or indicate if it is
impossible to cut out $n$ iron bars, for each $i=1,2,\ldots,n-1$.\

### 输入描述

The first line of the input contains an integer$T$ ($1 \le T \le 200$), indicating the number of
test cases. For each test case:\
\
The first line contains an integer$n$ ($2 \le n \le 420$), indicating the number of
iron bars.\
\
The second line contains $n$ integers$a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$), indicating the
lengths of the iron bars.\
\
It is guaranteed that the sum of $n$ for all
test cases does not exceed $420$.\

### 输出描述

For each test case, output a line containing $n-1$ integers, the $i$-th of which indicates the minimum total
cost for the first cut at the weld point between the $i$-th and
($i+1$)-th iron bars, or $-1$ if it is impossible to cut out $n$ iron bars.\

### 示例1

#### 输入

```plain
3
3
8 9 7
3
1 5 9
3
3 1 4
```

#### 输出

```plain
68 75
24 -1
-1 -1
```

