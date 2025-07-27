## F. Field of Fire

### 题目描述

Alarm! Fire is taking over the forest!\
\
The shape of this forest is like a ring and can be divided into $n$ parts. Part $i\ (1\leq i\leq n)$ is adjacent only to Part $((i-2)\bmod n)+1$ and Part $(i\bmod n)+1$. If no action is taken and
there is a fire in Part $i$, its adjacent
parts will also be engulfed by flames in one minute.\
\
As a responsible resident yourself, you have called the firefighters to
come as soon as possible to put out this scary fire. However, it will
take $t_0$ minutes before they can ever get
here. Is there anything you could do?\
\
There is! You decide to set a controllable fire by yourself on exactly
one part of the forest to get a fire isolation zone immediately before
the fire can ever get to it. In that way, the fire can never spread over
this place afterwards.\
\
But it\'s hard to make a wise decision: You need to choose the place of
the fire isolation zone to guarantee more parts of the forest remain
unburned. What is the maximum number of unburned parts you can get
before firefighters come?

### 输入描述

Each test contains multiple test cases. The first line contains the
number of test cases $T\ (1≤T≤10^4)$ .\
\
Each test case consists of $2$ lines.\
\
The first line contains two integers $n,t_0\ (1\leq n, t_0\leq 10^5)$, the number
of parts in the forest and the time firefighters need to get to the
forest.\
\
The second line contains a string $s\ (|s|=n)$ consisting of $0$ and $1$. The
part $i$ is currently on fire if and only if $s_i=1$. It is guaranteed that there exists
one $i\ (1\leq i\leq n)$ such that $s_i=1$.\
\
It is guaranteed that $\sum n$ over all test
cases in one test will not exceed $5\times 10^5$.

### 输出描述

For each test case, output one integer:  the maximum number of unburned
parts in the forest when the firefighters come.

### 示例1

#### 输入

```plain
3
5 2
10000
5 3
10000
10 1
1000000100
```

#### 输出

```plain
1
0
4
```

#### 说明

For the first test case, once you burn Part $2$, the fire only gets time to burn Part $4$ and $5$,
leaving Part $3$ unburned.

