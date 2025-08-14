## E. Sensei and Affection (affection)

### 题目描述

Currently, there are $n$ students, with id $1,2,3,\cdots,n$. The initial **affection**
of each student is $a_1,a_2,a_3,\cdots,a_n$.
Sensei can perform the following operation exactly once a day:
- Pick integers $l,r$ satisfying $1\le l\le r\le n$, and increase the
    affection of every student whose id lies between $[l,r]$ by $1$. To be specific, for every integer$i$     ($l\le i\le r$), set $a_i:=a_i+1$.

Sensei now wants to find the minimum number of days required to ensure
that at most $m$ different integers appear in
the affection sequence $a_1,a_2,a_3,\cdots,a_n$. He asks for your
help.

### 输入描述

**The problem contains multiple test cases.**The first line of input contains a positive integer$T$ ($1 \le T \le 10$), representing the number
of test cases.For each test case:The first line contains two integers$n,m$ ($1\le n\le 400$, $1\le m\le 2$) referring to the number of
students and a parameter.The second line contains $n$ integers$a_1,a_2,a_3,\cdots,a_n$ ($0\le a_i\le100$) referring to the initial
affection of each student.

### 输出描述

For each test case, output a single line containing a non-negative
integer representing the minimum number of days required.

### 示例1

#### 输入

```plain
4
3 1
3 1 3
5 1
5 1 6 1 8
5 2
5 1 6 1 8
5 2
1 3 2 3 1
```

#### 输出

```plain
2
12
3
1
```

