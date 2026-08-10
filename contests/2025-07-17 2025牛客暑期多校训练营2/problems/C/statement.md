## C. Colorful Tree

### 题目描述

It\'s a colorful world in Color Town!

Color Town is well known for each place of interest: the Colorful Tree.
The Colorful Tree is not a real tree. It\'s actually a gigantic painting
on the ground which looks like a tree if you take a hot air balloon and
see the painting from up in the sky.

Families in the town work together to renew the painting each year.
There are $n$ families in the town, and there
are $n$ parts that form the whole painting.
Family $i$ paints Part $i$.

Why does the painting look like a tree? Actually, the structure of the
painting is almost like a rooted tree in graph theory! Each part other
than Part $1$ has its parent, and the parent
of Part $u$ is $p_u$ . Part$i$ and Part $j$ are adjacent if and only if $i$ is the parent of $j$ or $j$ is the
parent of $i$ .

Each family produces its own paint. But since the paint producing
technique of the family can be unstable, the color of the paint they
produce can be quite different. We note each color as an integer, and
the color of the paint produced by Family$i$ can be a random integer in the range $[l_i,r_i]$ equiprobably.

To make work less tiring, each family paints the part entirely using the
paint it produces this year. Together, they form a beautiful painting!

There is another thing about paint that you should know: as time passes,
the family may lose or improve its technology, so $[l_i,r_i]$ can change over time. Relevant
updates will be provided.

To show the painting to the world, the mayor of the town, Sean, decides
to take a picture of the painting each year. In the $i$-th year, when he takes a photo of the
painting, the photo taken shows the parts in the subtree of $u_i$ fully, and no other parts are shown in
the photo. Part $i$ is in the subtree of Part $j$ if there is a sequence $v_1,v_2,\dots,v_k$ such that$v_1=i, p_{v_t}=v_{t+1}\ (1\leq t\lt k), v_k=j$ . Specially, Part $i$ is in the subtree of
Part $i$ .

Sean wants to tell others how colorful the photo is, so he defines the
colorfulness as the number of great components in the photo. A component
is an area that is in one color, and any point in the area can go
through points in the components to get to another point. A great
component is a component which can\'t be completely covered by any other
component.

Let the colorfulness be $C_i$ in the $i$-th year. As the randomness of the paints
produced, $C_i$ can be a random variable each
year. To learn more information about $C_i$,
Sean asks you about the expectation and the variance value of $C_i$. Can you help him?

Recall that the variance of a random variable $X$ is$\mathrm{Var}(X)=\mathrm{E}[(X-\mathrm{E}X)^2]$ where $\mathrm{E}X$ is the expectation of $X$ .

It\'s guaranteed that the root of the tree is $1$, and the tree (except the example) is
randomly generated this way:

- Let $rnd(a)$ be the result of selecting a
  number from $1,2,\dots, a$ equiprobably.
- We use $[p_2,p_3,\dots,p_n]$ to describe
  the rooted tree, which means the \"parent\" of Part $i$ is $p_i$ .
- The array $[p_2,p_3,\dots,p_n]$ is
  generated this way: $p_2=rnd(1),p_3=rnd(2),\dots,p_{i+1}=rnd(i),\dots,p_n=rnd(n-1)$.

<div>

The queries are not necessarily randomly generated.

<div>

</div>

</div>

### 输入描述

<div>

Each test contains multiple test cases. The first line contains the
number of test cases $t\ (1≤t≤10^4)$ .

Each test case consists of many lines.

The first line
contains $2$ integers $n,q\ (4\leq n\leq 5\times10^5,1\leq q\leq 10^5)$,
the size of the tree and the number of queries.

The second line
contains $n-1$ integers $p_2,p_3,\dots,p_n\ (1\leq p_i\lt i)$,
where $p_i$ is the parent
of $i$.

The third line
contains $n$ integers $cl_1,cl_2,\dots,cl_n\ (1\leq cl_i\lt 998\ 244\ 353)$ and
the fourth line
contains $n$ integers $cr_1,cr_2,\dots,cr_n\ (cl_i\leq cr_i\lt  998\ 244\ 353)$.
The original color range of
Family $i$ is $[cl_i,cr_i]$.

Each line from the $5$-th to
the $(q+4)$-th contains a query. The query
can be one of the two types:

</div>

<div>

</div>

<div>

1. $1\ u\ l\ r$ :
Type-$1$ query. Change the color range of
vertex $u\ (1\leq u\leq n)$ into $[l,r]\ (1\leq l\leq r\lt 998\ 244\ 353)$.

</div>

<div>

</div>

<div>

2. $2\ u$:
Type-$2$ query. Ask about the expected
colorfulness and its variance in the subtree of
vertex $u\ (1\leq u\leq n)$.

</div>

<div>

</div>

<div>

It is guaranteed that $\sum n$ over all test
cases in one test will not
exceed $5\times 10^5$,
and $\sum q$ over all test cases in one test
will not exceed $10^5$. There are
exactly $30$ test cases for this
problem other than the given test case.

</div>

### 输出描述

For each Type-$2$ query, output $2$ integers to represent the expected
colorfulness and its variance in the subtree of vertex $u$.

It can be proved that the answer is always a rational number, which can
be expressed as $\frac{p}{q}\ (\gcd(p,q)=1,p,q∈\mathbb{Z}, 998\ 244\ 353\nmid q)$.
You should output an integer $x$ such that$q\times x\bmod 998\ 244\ 353=p \bmod 998\ 244\ 353$ and $x\in [0,998\ 244\ 353)$ .

### 示例1

#### 输入

```plain
2
4 5
1 2 2
1 1 2 3
1 3 2 3
2 1
2 2
1 2 2 3
2 1
2 2
4 7
1 1 1
1 998244352 1 998244352
998244352 998244352 1 998244352
2 1
1 2 1 998244352
2 1
1 3 998244352 998244352
2 1
1 4 1 1
2 1
```

#### 输出

```plain
3 0
332748120 887328314
3 0
2 0
7 998244339
7 998244345
7 998244343
7 998244345
```
