## L. Ladder Challenge

### 题目描述

Xiao Ming and $n$ competitors are
participating in a \"Ladder\" game. Each competitor has a score, and the
scores are arranged in strictly increasing order, that is:\ $a_1 < a_2 < \dots < a_n$\
\
Xiao Ming is initially not among these$n$ competitors. Now, Xiao Ming wants to improve his ranking through
\"challenges.\"\
\
Each time he challenges, Xiao Ming will choose the **lowest scoring
competitor** who has a higher score than him. The rules of the challenge
are as follows:\
\
- Xiao Ming\'s score increases by $1$;
- The challenged competitor\'s score decreases by $1$.

\
There are a total of $q$ queries. Each query
provides Xiao Ming\'s initial score $x$ and
the target ranking $y$ (ranked by current
scores, with ties considered as the same rank). You need to determine
how many challenges Xiao Ming **needs at least** to achieve that
ranking. Output $0$ if Xiao Ming has already
achieved (or even above) the target ranking without any challenge.\

### 输入描述

The first line contains two integers $n$ and $q$, representing the number of competitors
and the number of queries;\
\
The second line contains $n$ strictly
increasing integers $a_1, a_2, \dots, a_n$,
representing the initial scores of each competitor;\
\
The following $q$ lines each contain two
integers $x$ and $y$, representing Xiao Ming\'s initial score
and his target ranking.

### 输出描述

For each query, output an integer indicating how many challenges Xiao
Ming needs at least to reach the target ranking.

### 示例1

#### 输入

```plain
5 3
2 5 8 11 20
25 1
3 4
0 2
```

#### 输出

```plain
0
1
9
```

### 示例2

#### 输入

```plain
2 3
2 3
1 3
1 2
1 1
```

#### 输出

```plain
0
1
2
```

### 备注

<div>

Constraints:

</div>

<div> $\bullet$ $1 \leq n, q \leq 2 \cdot 10^5$;\ $\bullet$ $1 \leq a_i \leq 10^9$;\ $\bullet$ $0 \leq x \leq 10^9$;\ $\bullet$ $1 \leq y \leq n + 1$.\

</div>

