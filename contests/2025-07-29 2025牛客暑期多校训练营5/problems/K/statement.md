## K. Perfect Journey

### 题目描述

<div>

In a country with $\textstyle n$ cities,
there are $\textstyle n-1$ bidirectional
roads connecting these cities, forming a tree.You are now visiting this
country, and there are$\textstyle m$ specific roads that you definitely want to travel through.The travel
agency offers $\textstyle k$ optional tour
routes. Each route starts from city $\textstyle s_i$ and follows the shortest
path to reach city $\textstyle t_i$.

<div>

\

<div>

Your goal is to select as few routes as possible from these $\textstyle k$ tour routes, ensuring that all $\textstyle m$ key roads are traveled at
least once.

<div>

\

<div>

Please calculate the minimum number of tour routes you need to select,
and the number of possible ways to achieve this minimum, with the answer
modulo $\textstyle 998244353$. A plan is
defined as the set of tour routes you choose. Two plans are considered
different if and only if there exists a tour route that is selected in
one plan but not in the other.

<div>

\

<div>

If it's impossible to travel through all the specific roads, output $\textstyle -1$.

<div>

\

The problem guarantees that the answer is non-zero modulo $\textstyle 998244353$.

</div>

</div>

</div>

</div>

</div>

</div>

</div>

</div>

### 输入描述

<div>

The first line contains three integers $\textstyle 2\leq n\leq 2\times 10^5$, $\textstyle 1\leq m\leq 22$, $\textstyle 1\leq k\leq 2\times 10^5$,
representing the number of cities, the number of specific roads, and the
number of tour routes.

</div>

<div>

\

</div>

The next $\textstyle n-1$ lines each contain
two integers $\textstyle 1\leq u_i,v_i\leq n$,
guaranteeing that the given graph is a tree.

<div>

\

</div>

<div>

The next line contains$\textstyle m$ distinct integers $\textstyle 1\leq x_i\leq n-1$ representing
the indices of the specific roads (according to the input order).

</div>

<div>

\

</div>

<div>

The next $\textstyle k$ lines each contain
two integers $\textstyle 1\leq s_i,t_i\leq n$, indicating
that the tour route goes from $\textstyle s_i$ to $\textstyle t_i$.

</div>

### 输出描述

Output the minimum number of tour routes you need to select, and the
number of ways to achieve this minimum, with the answer modulo $\textstyle 998244353$.

<div>

\

</div>

<div>

If it's impossible to travel through all the specific roads, output $\textstyle -1$.

</div>

### 示例1

#### 输入

```plain
3 2 2
1 2
1 3
1 2
2 3
1 2
```

#### 输出

```plain
1 1
```

### 示例2

#### 输入

```plain
7 3 3
1 2
1 3
2 4
2 5
3 6
6 7
1 3 5
1 4
2 7
2 4
```

#### 输出

```plain
2 2
```

#### 说明

<div>

<div>

we need to select at least 2 routes, and there are two possible plans:

</div>

<div>

\

</div>

<div>

<div>

Route 1 and Route 2，Route 1 covers road 1 and road 3, Route 2 covers
road 1 and road 5.

</div>

</div>

<div>

<div>

Route 2 and Route 3，Route 2 covers road 1 and road 5, Route 3 covers
road 3.

</div>

</div>

</div>

