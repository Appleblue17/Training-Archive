## H. Highway Upgrade

### 题目描述

The highway system in NowLand has been used for quite some decades and
requires upgrades.

In the country, there are $n$ cities and $m$ one-way highways that go from one city to
another. Using the $i$-th highway, one car
can go from City $u_i$ to City $v_i$ in$t_i$ minutes. An upgrade reduces the time used in the journey by $w_i$ minutes. The highway can be upgraded as
many times as you want.

As a selfish person, the president of NowLand only considers his own
interests. It\'s his last job to upgrade the highways, and after that,
he will retire. After he retires, he will leave City $1$, the capital of NowLand, for City $n$, where he will spend the rest of his
life. He will only use highways for this journey, so he only cares about
the time to go to City $n$ from City $1$ and wants it to be as short as possible.

But as the government doesn\'t have enough money, there\'s a limited
budget for upgrades. With the budget yet to be confirmed, the president
needs to prepare for different conditions. That\'s why he wants to know
the minimum time he needs to get to City$n$ from City $1$ if he can do $k$ upgrades. What are the results, though?

It\'s guaranteed that it is always possible to get to City $n$ from City$1$ using only highways.

### 输入描述

Each test contains multiple test cases. The first line contains the
number of test cases $t\ (1≤t≤10^4)$ .

Each test case consists of many lines.

The first line contains $2$ integers $n,m\ (4\leq n\leq 10^5, 1\leq m\leq 3\times 10^5)$,
the number of cities and highways in the country.

Each line from the $2$-nd to the $(m+1)$-th contains $4$ integers $u_i,v_i,t_i,w_i\ (1\leq u_i,v_i\leq n, u_i\neq v_i, 2\leq t_i\leq 10^{12}, 1\leq w_i\leq \min(t_i-1,10^9))$,
representing the starting point, ending point, original travel time, and
the upgrade parameter of the $i$-th highway.
It is guaranteed that it is possible to travel from City $1$ to City$n$ using highways.

The $(m+2)$-th line contains one integer $q\ (1\leq q\leq 3\times 10^5)$, the number
of queries to ask.

Each line from the $(m+3)$-th to the $(m+q+2)$-th contains one integer $k_i\ (1\leq k_i\leq 10^9)$, the number of
upgrades. It is guaranteed that $\forall 1\leq j\leq m, t_j-w_j\times k_i\gt 0$.

It is guaranteed that $\sum n$ over all test
cases in one test will not exceed $2\times 10^5$, and $\sum m$ and $\sum q$ over all test cases in one test will
not exceed $6\times 10^5$ .

### 输出描述

For each test case, output $q$ integers: the
minimum time to travel from City $1$ to City $n$ using$k_i$ upgrades.

### 示例1

#### 输入

```plain
1
4 4
1 2 15 1
1 3 20 2
2 4 10 1
3 4 10 1
2
9
1
```

#### 输出

```plain
12
24
```
