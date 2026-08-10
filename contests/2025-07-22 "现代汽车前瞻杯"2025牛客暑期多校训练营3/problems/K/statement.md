## K. Kaleidoscope

### 题目描述

Kobato Jiyogoro and Osanai Yuki are investigating the theft of a
permutation $p_1, \ldots, p_n$. There are
already some testimonies $(x, y)$ indicating
that $p_x = y$. It\'s guaranteed that the
testimonies have no contradictions. In order to find out the suspects,
they come up with another problem:

<div>
- Two permutations$p$     and $q$ *resemble* each other if and only
    if the lengths of$p$     and $q$ are the same, and the sets of the
    prefix maximal positions are the same. A
    position $k$ of a
    permutation $p$ is called a prefix
    maximal position if and only if $p_k = \max(p_1, \ldots, p_k)$.
- Osanai wants to count the number of different
    permutations $q$ such that there exists a
    way to fill out all the missing positions in $p_1, \ldots, p_n$ so that$p$     *resembles* $q$.

<div>

Please help Kobato do the calculations. As the answer might be huge,
print it modulo $998244353$.

<div>

<div>

Recall that a permutation of length $n$ is an
array consisting of $n$ distinct integers
from $1$ to $n$ in
arbitrary order. For example, $[2, 3, 1, 5, 4]$ is a permutation, but $[1, 2, 2]$ is not a permutation
($2$ appears twice in the array), and $[1, 3, 4]$ is also not a permutation
($n = 3$ but there is $4$ in the
array).[]{style="text-wrap-mode:wrap;"}

</div>

</div>

</div>

</div>

### 输入描述

Each test contains multiple test cases. The first line of input contains
a single integer$t$ ($1 \leq t \leq 1.8\cdot 10^3$) --- the
number of test cases. The description of the test cases follows.

The first line of input contains a single integer$n$ ($1 \leq n \leq 5\cdot 10^3$).

The second line of input contains$n$ integers$p'_1, \ldots, p'_n$ ($0 \leq p'_i \leq n$). If $p'_i = 0$, there is currently no information
about $p_i$; otherwise, there is a testimony
indicating that $p_i = p'_i$. It\'s
guaranteed that no pairs $(i, j)$ exist such
that $1 \leq i < j \leq n$ and $p'_i = p'_j  > 0$.

It\'s guaranteed that the sum of $n$ over all
test cases does not exceed $10^4$.

### 输出描述

For each test case, output a single line containing an integer: the
number of different permutations that
might *resemble *$p$, modulo $998244353$.

### 示例1

#### 输入

```plain
13
3
0 0 2
3
0 1 3
4
0 1 0 0
4
1 3 2 0
4
0 3 0 0
4
0 0 2 1
5
3 1 4 2 5
6
0 0 3 0 5 0
7
0 0 0 0 0 0 0
9
0 0 6 0 0 7 0 0 0
10
0 0 3 1 0 0 2 5 0 0
11
0 0 6 0 3 8 9 0 0 0 0
16
0 0 3 5 0 0 6 0 0 12 0 0 16 0 7 0
```

#### 输出

```plain
4
1
12
2
11
12
3
374
5040
202820
1360800
16287920
399815880
```

### 备注

In the first example test case, there are two possible permutations $p$:

1. $p = [1, 3, 2]$. The set of prefix maximal
positions is $\{1, 2\}$. There are $2$ permutations $q$ that
_resemble _$p$: $[1, 3, 2]$, and $[2, 3, 1]$.
2. $p = [3, 1, 2]$. The set of prefix maximal
positions is $\{1\}$. There are $2$ permutations$q$ that *resemble* $p$: $[3, 1, 2]$, and $[3, 2, 1]$.

Thus, the answer is $2 + 2 = 4$.

The only possible permutation in the second example test case is $p = [2, 1, 3]$. The set of prefix maximal
positions is $\{1, 3\}$, and the only
permutation $q$ that
_resembles _$p$ is exactly $p$ itself, so the answer is $1$.

In the third example test case, all the possible $12$ permutations $q$ that
might *resemble* $p$ are as follows: $[2, 1, 3, 4]$, $[2, 1, 4, 3]$, $[3, 1, 2, 4]$, $[3, 1, 4, 2]$, $[3, 2, 1, 4]$, $[3, 2, 4, 1]$, $[4, 1, 2, 3]$, $[4, 1, 3, 2]$, $[4, 2, 1, 3]$, $[4, 2, 3, 1]$, $[4, 3, 1, 2]$, and $[4, 3, 2, 1]$. Note that it\'s possible to
have $p = [3, 2, 1, 4]$ and $p = [3, 1, 2, 4]$, both having the prefix
maximal set as $\{1, 4\}$, but the
corresponding resembling permutations $q$ are
still counted only once.
