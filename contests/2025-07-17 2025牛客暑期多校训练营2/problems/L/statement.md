## L. Love Wins All

### 题目描述

It\'s a loving community!\
\
There are $n$ residents in the community, and
each resident $i\ (1\leq i\leq n)$ in the
community has a unique resident $a_i\ (1\leq i\leq n)$ in the community whom
he/she loves so much. Each two residents love different residents. A
resident can love himself / herself. It is guaranteed that $n$ is even.\
\
One day, a bad thing happens: They need to choose $2$ residents to be forbidden to get married
forever.\
\
And to prevent such a thing from happening in the future, the rest $n-2$ residents decide to get married as $\frac{n}{2}-1$ couples, each couple
consisting of $2$ persons (of course). It
makes no sense that a couple consists of resident $x$ and resident $y$ while neither $x$ loves $y$ nor $y$ loves $x$, so
such a thing never happens.\
\

<div>

So, as the planner, you need to figure out how you can arrange this. You
want to know the number of different marriage plans. Two marriage plans
are considered different if at least one of the following conditions is
satisfied:

<div>

\
- In one plan, a person $i$ is married, and
    in the other, he/she is not.
- In one plan, a person $i$ is married to $j$, and in the other, he/she is not
    married to $j$.

<div>

\

<div>

As the number of plans can be quite enormous, output it modulo $998\ 244\ 353$.

</div>

</div>

</div>

</div>

### 输入描述

Each test contains multiple test cases. The first line contains the
number of test cases $T\ (1≤T≤10^4)$ .\
\
Each test case consists of two lines.\
\
The first line contains $1$ integer $n\ (4\leq n\leq 5\times 10^5)$, the number
of residents in the community. It\'s guaranteed that $n$ is even.\
\
The second line contains $n$ integers $a_1,a_2,\dots,a_n\ (1\leq a_i\leq n)$, where $a_i$ represents the one that the resident $i$ loves. It is guaranteed that if $i\neq j\ (1\leq i,j\leq n)$, $a_i\neq a_j$ .\
\
It is guaranteed that $\sum n$ over all test
cases in one test will not exceed $5\times 10^5$ .

### 输出描述

For each test case, output $1$ integer: the
number of different marriage plans modulo $998\ 244\ 353$.\

### 示例1

#### 输入

```plain
2
4
1 3 4 2
6
3 4 5 6 2 1
```

#### 输出

```plain
3
9
```

