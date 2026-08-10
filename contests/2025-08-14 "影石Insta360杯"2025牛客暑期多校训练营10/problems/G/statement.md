## G. Starlight (starlight)

### 题目描述

Given a sequence $a$ of length $n$ and a positive integer $m$, you need to handle $q$ operations.Each operation provides $x, y, z$, meaning:
- First, permanently update $a_x$ to $y$.
- Then, query the minimum number of deletion operations required to
    ensure that at least $z$ elements in the
    sequence become $0$.

Definition of one **deletion** operation:

1.  Sort the **non-zero** elements in ascending order of their values.
    Let $b_1, b_2, \ldots, b_k$ be the
    sequence of their **indices** after sorting.
2.  Choose an arbitrary non-negative integer $k' \leq m$. For every $i$ satisfying $1 \le i \le\min(k,k')$, set $a_{b_i} := a_{b_i} - 1$.

Note:
- The update to $a_x$ is **permanent** and
    affects subsequent operations.
- The deletion operations are **not permanent**; the sequence reverts
    to its current state after each query.

### 输入描述

The first line contains three positive integers $n$, $m$,$q$ ($1 \leq n, m, q \leq 10^5$), as described in
the problem statement.The second line contains $n$ positive
integers representing the sequence$a$ ($1 \leq a_i \leq 10^9$).The next $q$ lines each contain three
integers $x'$, $y'$, $z'$,
representing an operation. For this
operation, $x = 1 + \big((x' + \text{lans}) \bmod n\big)$, $y = 1 + \big((y' + \text{lans}) \bmod 10^9\big)$,
and $z = 1 + \big((z' + \text{lans}) \bmod n\big)$.Here, $\text{lans}$ denotes the answer to the
previous operation (or $\text{lans}=0$ if no
prior operation exists). It is guaranteed that $x', y', z' \in [0, 2^{63})$.

### 输出描述

For each operation, output a single line containing an integer
representing the answer.

### 示例1

#### 输入

```plain
5 4 5
793982278 930973954 65057664 63383158 226369572
1815647561 1400488026 3187009203
968072559 3087832345 1063159872
1111136800 2762585403 1385851423
759541154 2135314604 2835883033
880295667 717958068 387325293
```

#### 输出

```plain
400488027
857365436
857365436
1056063199
226369572
```

