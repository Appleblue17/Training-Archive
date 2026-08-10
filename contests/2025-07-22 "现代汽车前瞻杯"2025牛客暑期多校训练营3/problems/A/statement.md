## A. Ad-hoc Newbie

### 题目描述

Yuki gives you a sequence of $n$ positive
integers $f_1, \ldots, f_n$, **where for
each** $\boldsymbol{i}$, $\boldsymbol{1 \leq f_i \leq i}$ **holds**.
She wants you to construct an $n$-ordered
square matrix $A$ such that:

<div>
- For each $1 \leq i, j \leq n$, $0 \leq A_{i,j} \leq n$;
- For each $1 \leq i \leq n$, $\operatorname{mex}(A_{i,1}, A_{i,2}, \ldots, A_{i,n}) = \operatorname{mex}(A_{1,i}, A_{2,i}, \ldots, A_{n,i}) = f_i$.

It can be proven that for any valid $f_1, \ldots, f_n$, a solution always
exists.

Recall that the $\operatorname{mex}$ of a
sequence $b_1, \ldots, b_m$ is the smallest
non-negative integer $x$ such that $x$ does not appear in $b$.

</div>

### 输入描述

Each test contains multiple test cases. The first line of input contains
a single integer$t$ ($1 \leq t \leq 2\cdot 10^4$) --- the number
of test cases. The description of the test cases follows.

The first line contains a single integer$n$ ($1 \leq n \leq 1\;414$), denoting the length
of the sequence.

The second line contains $n$ integers$f_1, \ldots, f_n$ ($1 \leq f_i \leq i$), describing the given
sequence.

It is guaranteed that the sum of $n^2$ over
all test cases does not exceed $2\cdot 10^6$.

### 输出描述

For each test case, output $n$ lines, in
which the $i$-th line contains $n$ non-negative integers $A_{i,1}, A_{i,2}, \ldots, A_{i,n}$ in the
range $[0, n]$.

### 示例1

#### 输入

```plain
3
3
1 1 2
5
1 1 3 2 5
4
1 2 1 3
```

#### 输出

```plain
0 2 0
0 0 0
0 0 1
3 2 0 0 4
0 0 2 0 3
2 4 1 0 2
0 0 1 1 0
2 0 4 3 1
2 0 2 2
0 1 0 1
2 3 0 0
0 0 2 1
```

### 备注

In the first test case, $f = [1, 1, 2]$, and
a possible square matrix is as follows:
\ $A = \begin{bmatrix} 0 &2 &0\\ 0 &0 &0\\ 0 &0 &1\end{bmatrix}.$

In the first row, $\operatorname{mex}([0, 2, 0]) = f_1 = 1$,
because $0$ appears in $[0, 2, 0]$, but $1$ does not, so $1$ is the smallest non-negative integer not
present; in the first column, similarly, $\operatorname{mex}([0, 0, 0]) = f_1 = 1$. It
is easy to verify that this matrix also satisfies all other
constraints.
