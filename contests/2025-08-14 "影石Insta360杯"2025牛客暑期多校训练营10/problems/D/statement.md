## D. Grammar Test (grammar)

### 题目描述

Consider a sequence of $n$ Boolean variables $a_1, a_2, a_3, \cdots, a_n$. For variables $x$ and$y$ initially set to arbitrary non-negative integers, perform the following
operations in the order of integer $i$ from $n-1$ down to $1$,
based on the values of $a_i$ and $a_{i+1}$ (where $\oplus$ denotes bitwise XOR):
- ------------------------------------------- -------------------------------------------- ----------------------------------------------------------------------------- ------------------------------------------- -------------------------------------------
  If $a_i$ is       true                                         true                                                                          false                                       false

  If $a_{i+1}$ is   true                                         false                                                                         true                                        false

  Perform                                      $x:=x\oplus x$\   [ ]{style="text-wrap-mode:wrap;"}$x:=x\oplus y$\   $y:=y\oplus x$$y:=y\oplus y$   -------------------------------------------- -------------------------------------------- ----------------------------------------------------------------------------- ------------------------------------------- -------------------------------------------

Count the number of distinct sequences $a_1, a_2, \cdots, a_n$ such that, for any
initial values of $x$ and $y$, after performing all the operations, the
variables always swap their initial values (i.e., $x$ ends up with the initial value of $y$, and $y$ ends
up with the initial value of $x$). Output the
answer modulo $998244353$.

### 输入描述

**The problem contains multiple test cases.**The first line of input contains a positive integer$T$ ($1 \le T \le 10$), denoting the number of
test cases.For each test case:The first and only line contains a positive integer$n$ ($1 \le n \le 10^{18}$), representing the
expected length of the sequence.

### 输出描述

For each test case, output a single line containing a non-negative
integer representing the number of sequences satisfying the condition,
modulo $998244353$.

### 示例1

#### 输入

```plain
3
1
2
4
```

#### 输出

```plain
0
0
2
```

