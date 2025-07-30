## B. Bitwise Perfect

### 题目描述

Binary army ants are preparing for a cruel war, but things become more
complicated than they thought.

There are $n$ ants in the squad. Originally,
each army ant $i\ (1\leq i\leq n)$ has its
power $a_i$ .

However, it turns out something strange will happen during the war: a
random pair$(i,j)\ (1\leq i\lt j\leq n)$ will be chosen, and the ant $i$ and the ant $j$ will disappear, and a new ant with power $a_i\oplus a_j$, which is the **bitwise
exclusive OR (XOR)** of $a_i$ and $a_j$, will magically appear.

This kind of thing is so rare that it happens at most once throughout
the war.

The ants think the total strength of the whole squad is $\sum\limits_{i=1}^n2^{a_i}$ , and the squad
is called **bitwise perfect** if the event above could never decrease
its strength.

Too busy practicing, ants don\'t have enough time to check whether the
squad is bitwise perfect. Can you help them with this? There can be $T$ squads.

### 输入描述

Each test contains multiple test cases. The first line contains the
number of test cases $T\ (1≤T≤10^5)$ .

Each test case consists of two lines.

The first line contains one integer $n\ (2\leq n\leq 5\times 10^5)$, the number
of ants in the squad.

The second line contains $n$ integers $a_1,a_2,\dots,a_n\ (1\leq a_i\leq 10^{18})$,
the power of each ant.

It is guaranteed that $\sum n$ over all test
cases in one test will not exceed $5\times 10^5$.

### 输出描述

For each test case, output **\"YES\"** if the squad is **bitwise
perfect** and **\"NO\"** otherwise. You can print the answer in any
case.

### 示例1

#### 输入

```plain
3
2
3 5
4
1 2 4 8
3
1 2 3
```

#### 输出

```plain
YES
YES
NO
```

#### 说明

In the first case, if the two ants merge, as $3\oplus 5=6$, the total strength of the
whole squad changes from $2^3+2^5=40$ to $2^6=64$, so the event will not decrease the
total strength. So the squad is **bitwise perfect**.
