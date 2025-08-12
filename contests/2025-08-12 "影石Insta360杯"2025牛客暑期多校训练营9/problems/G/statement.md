## G. Permutation

### 题目描述

Little Pog has a permutation$\textstyle p$ of length $\textstyle n$. He wants to perform
exactly $\textstyle n$ operations to build a
new sequence $\textstyle a$, which starts out
empty.

In each operation, Pog can choose one of the following:
- **Remove** the leftmost or rightmost element from $\textstyle p$. The value is discarded
    and not added to $\textstyle a$.
- **Query** the minimum value in the current $\textstyle p$ and append it to the end
    of $\textstyle a$. This does not modify $\textstyle p$.

Exactly $\textstyle n$ operations must be
performed.

Pog wants to know how many distinct sequences $\textstyle a$ he can obtain through
different operation sequences. Print the answer modulo $\textstyle 998244353$.

In this problem, a permutation of length $\textstyle n$ is a sequence that contains
each of $\textstyle 1, 2, \dots, n$ exactly
once, in some order.

### 输入描述

The first line contains an integer$\textstyle t$ ($\textstyle 1 \le t \le 10^6$) --- the
number of test cases.

Each test case consists of two lines:
- The first line contains one integer$\textstyle n$     ($\textstyle 1 \le n \le 10^6$).
- The second line contains$\textstyle n$     integers $\textstyle p_1, p_2, \dots, p_n$,
    forming a permutation of $\textstyle \{1, 2, \dots, n\}$.

It is guaranteed that $\textstyle \sum n \le 10^6$.

### 输出描述

For each test case, output a single integer --- the number of different
sequences $\textstyle a$ that can be created
by performing $\textstyle n$ operations,
modulo $\textstyle 998244353$.

### 示例1

#### 输入

```plain
3
2
1 2
3
3 1 2
5
5 3 4 1 2
```

#### 输出

```plain
4
6
15
```

### 备注

Here is the list of all possible answers of the second test case. We use
**L**, **R** for **Remove** operations from left and right respectively,
and **Q** for **Query** operations.
- $\textstyle a = [\,]$:$\textstyle \texttt{L L L}$ 
- $\textstyle a = [1]$:$\textstyle \texttt{L R Q}$ 
- $\textstyle a = [2]$:$\textstyle \texttt{L L Q}$ 
- $\textstyle a = [3]$:$\textstyle \texttt{R R Q}$ 
- $\textstyle a = [1,1]$:$\textstyle \texttt{Q L Q}$ 
- $\textstyle a = [1,1,1]$:$\textstyle \texttt{Q Q Q}$

