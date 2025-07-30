## G. Geometry Friend

### 题目描述

A convex polygon lies lazily on the Euclidean $xOy$ plane. What is it like to have a
friend? It thinks to itself.

Tiny as it is, a point $P$ appears at the
position $(x,y)$ and catches the attention of
the polygon. They become friends, and the polygon loves rotating
anti-clockwise around this little point $P$,
as in that way, it can cover some area it never covered before. An area
is covered by the polygon if every point in it is inside or on the edges
of the polygon.

<div>

But $P$ is worried: There can be one day when
the polygon becomes bored with rotating. It thinks that when the area
that has once been covered by the polygon doesn\'t become larger, the
polygon will just ditch it and they will no longer be friends.

<div>

<div>

The angular velocity of the rotation of the polygon is $1$ rad per year, and let the time when the
polygon starts rotating be Time $0$. Help $P$ know the moment when his worries may come
true.

<div>

<div>

It is **not** **guaranteed** that $P$ is
inside the polygon.\*\*\*\*

</div>

</div>

</div>

</div>

</div>

### 输入描述

Each test contains multiple test cases. The first line contains the
number of test cases $T\ (1≤T≤10^4)$ .

Each test case consists of many lines.

The first line contains $3$ integers $n,x,y\ (3\leq n\leq 5\times 10^5, |x|\leq 10^9,|y|\leq 10^9)$,
where $n$ is the number of edges of the
convex polygon and $(x,y)$ is the position of $P$.

Each line from the second to the $(n+1)$-th
contains two integers $x_i, y_i\ (|x_i|\leq 10^9,|y_i|\leq 10^9)$,
the position of one vertex in the polygon. It is guaranteed that the
vertices given are in anti-clockwise order.

It is guaranteed that $\sum n$ over all test
cases in one test will not exceed $5\times 10^5$.

### 输出描述

For each test case, output one value: the moment when $P$\'s worries may come true. If the real
answer is $ans$, your answer $ans'$ is considered correct if $\frac{|ans-ans'|}{\max(1, ans)}\leq 10^{-6}$.

### 示例1

#### 输入

```plain
3
4 0 0
1 0
0 1
-1 0
0 -1
3 0 0
1 0
1 -1
2 0
3 0 0
0 0
1 -1
1 1
```

#### 输出

```plain
1.570796326794897
6.283185307179586
4.712388980384690
```
