## H. Rev Equation (NOI-tAUqe ver.) (equation)

### 题目描述

Definitions:
- A **valid expression** is either a **non-negative digit** or two
    **non-negative digits** separated by an operator (one of $\texttt{+}$, $\texttt{-}$, $\texttt{*}$).
- The **value **of a valid expression is the result obtained by
    calculating the expression mathematically. For example, the value
    of $\texttt{3}$ is $3$, the value
    of $\texttt{3-4}$ is $-1$, and the value
    of $\texttt{5*6}$ is $30$.
- A **valid equation** is a series of (at least two) valid expressions
    with equal values, concatenated by $\tt{=}$. For
    example, $\texttt{3=3}$, $\texttt{1+2=3}$, $\texttt{3-2=1-0=1}$ are valid equations,
    while $\texttt{3+=5}$, $\texttt{8+8=16}$, $\texttt{=5+3=8}$, $\texttt{-1+5=4}$ are not.

Violet Eye has a string $s$ of length 4. It
satisfies that $s_0$ and $s_2$ are digits, $s_1$ is one of $\texttt{+}$, $\texttt{-}$, $\texttt{*}$, and $s_3$ is $\texttt{=}$.Now, Violet Eye wants to insert some characters at any positions
(including the beginning and end) to $s$ to
obtain a **palindromic** string. Since she is lazy, only palindromic
strings that can be obtained by adding the fewest number of characters
will be considered.She wants to know if there exists a palindromic string that is
considered and can be interpreted as a **valid equation.**Since Violet Eye has always believed that there is only one prime number
greater than seven, and poor her has been searching for that prime
number for three days without sleep, the problem has to be handed over
to you.

### 输入描述

**The problem contains multiple test cases.**The first line of input contains a positive integer$T$ ($1 \le T \le 300$), representing the number
of test cases.For each test case:The first and only line contains a string$s$ ($0 \le s_0,s_2 \le 9$; $s_1$ is
one
of $\texttt{+}$, $\texttt{-}$, $\texttt{*}$; $s_3$ is $\texttt{=}$)
of length 4.

### 输出描述

For each test case, if there exists a legal string, output $\tt{Yes}$; otherwise, $\tt{No}$.

### 示例1

#### 输入

```plain
3
1+2=
1*1=
5-3=
```

#### 输出

```plain
Yes
No
No
```

#### 说明

For the first test case, since the
string $\texttt{1+2=2+1}$ is considered and
can be interpreted as a valid equation, the answer is $\tt{Yes}$.For the second test case, only the
string $\texttt{=1*1=}$ will be considered.
The answer is $\tt{No}$.

