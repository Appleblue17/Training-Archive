## M. Mysterious Spacetime

### 题目描述

**The input data for this problem is large, please use a faster input
method.**

****

In a mysterious spacetime, there are $\textstyle x$ unknown energies, numbered
from $\textstyle 1$ to $\textstyle x$. These energies appear at
specific times and positions, following these rules:

1\. **Spacetime Appearance Rule**:

There are $\textstyle n$ different time
points, numbered from $\textstyle 1$ to $\textstyle n$.

At time point $\textstyle t$, all energies in
the interval $\textstyle [l, r]$ will appear
and disappear at time point $\textstyle t+1$.

2\. **Generation Rule**:

There are $\textstyle m$ generators, numbered
from $\textstyle 1$ to $\textstyle m$. Each generator $\textstyle i$ requires all energies in the
interval $\textstyle [L_i, R_i]$.

If at some integer time point $\textstyle t$,
at least $\textstyle k_i$ energies in the
interval $\textstyle [L_i, R_i]$ appear
simultaneously, then generator$\textstyle i$ will be activated at time point $\textstyle t$.

Each generator is activated only once at the earliest moment when
requirements are met.

You need to process $\textstyle q$ queries.
Each query gives `tl tr l r`, asking:
- Within the time range $\textstyle [\text{tl}, \text{tr}]$, what
    is the earliest time point$\textstyle t$     such that: there exists some generator $\textstyle i$ satisfying$\textstyle l \leq L_i \leq R_i \leq r$     that is activated at time point $\textstyle t$.
- If no such $\textstyle t$ exists, output $\textstyle -1$.

### 输入描述

The first line contains a number $\textstyle 1 \leq T \leq 10^5$, indicating
there are $\textstyle T$ test cases, each in
the following format:
- The first line contains four integers $\textstyle 1 \leq n,m,x,q \leq 5 \times 10^5$.
- The next $\textstyle n$ lines, each
    containing three integers $\textstyle 1 \leq t \leq 10^9$, $\textstyle 1 \leq l \leq r \leq x$,
    indicating that at time point $\textstyle t$, all energies in interval $\textstyle [l, r]$ appear. (The problem
    guarantees all time points are different)
- The next $\textstyle m$ lines, each
    containing three integers $\textstyle 1 \leq L_i \leq R_i \leq x$, $\textstyle 1 \leq k_i \leq R_i-L_i+1$,
    describing the requirements of generator $\textstyle i$.
- The next $\textstyle q$ lines, each
    containing four integers $\textstyle 1 \leq tl \leq tr \leq 10^9$, $\textstyle 1 \leq l \leq r \leq x$,
    representing a query.

    

The problem guarantees$\textstyle \sum n, \sum m, \sum q ,\sum x\leq 5 \times 10^5$

### 输出描述

For each query, output one integer per line, representing the answer.

### 示例1

#### 输入

```plain
1
6 6 4 4
1 2 3
5 1 3
3 1 1
6 1 3
2 4 4
4 4 4
1 3 2
1 3 1
1 2 2
1 3 1
1 2 1
4 4 1
1 4 1 2
2 4 1 3
1 4 1 3
3 5 4 4
```

#### 输出

```plain
1
-1
1
-1
```

### 备注



