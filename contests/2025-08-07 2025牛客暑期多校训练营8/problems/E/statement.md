## E. Matrix Lottery

### 题目描述

There is a lottery box, and the lottery action corresponds to an $n \times n$ matrix. Each cell in the matrix
has a light bulb, which is initially turned off. Each time a lottery is
drawn, a specific light bulb will be attempted to be turned on, each
with a fixed probability, even if the light bulb is already on. Once a
light bulb is turned on, it will remain on. In other words, each time a
lottery is drawn, there is a probability of $p_{i, j}$ of selecting the light bulb in the $i$-th row and $j$-th column, or indexed $(i, j)$, and attempting to turn it on
($1 \leq i, j \leq n$). If the light is
already on, this operation is ignored.

Whenever all the light bulbs in a particular row, column, or diagonal
are turned on, the organizer will give the player a special gift
corresponding to that line. There are $(2 n + 2)$ types of gifts, numbered from $0$ to $(2 n + 1)$, each type of gift corresponds to
[exactly ]{style="text-wrap-mode:wrap;"}one of the aforementioned lines,
and each line corresponds to exactly one type of the gifts.

![](https://uploadfiles.nowcoder.com/images/20250806/0_1754453944198/5619C086B5C144A666720E8E911B1863){style="height:auto;width:262.4px;"}

Players have a special fondness for certain gifts and are eager to know
the expected number of lottery draws needed to obtain these gifts, so
they come to you. You need to answer$q$ queries, where the $i$-th query corresponds
to a number$t_i$ ($0

### 输入描述

The first line contains an integer$T$ ($1 \leq T \leq 200$), indicating the number
of test cases.Then follow $T$ test cases. For each test
case:The first line contains two integers $n$ and$q$ ($2 \leq n \leq 7$, $1 \leq q \leq 10^5$).The next $n$ lines describe the probabilities
of selecting each cell. The $i$-th line
contains $n$ integers $w_{i, 1}, w_{i, 2}, \ldots, w_{i, n}$,
representing
that $p_{i, j} = \frac{w_{i, j}}{W}$, where$W = \sum_{i = 1}^{n} \sum_{j = 1}^{n} {w_{i, j}}$ ($1 \leq w_{i, j} \leq W \leq 10^3$).The next $(2 n + 2)$ lines describe the line
with respect to the gifts. The $i$-th line
contains $2 n$ integers $x_{i, 1}, y_{i, 1}, x_{i, 2}, y_{i, 2}, \ldots, x_{i, n}, y_{i, n}$,
representing that there are
exactly $n$ distinct cells with indices$(x_{i, 1}, y_{i, 1}), (x_{i, 2}, y_{i, 2}), \ldots, (x_{i, n}, y_{i, n})$ lying on the line with respect to the gift $(i - 1)$. It is guaranteed that all possible
lines (i.e. $n$ rows, $n$ columns and $2$ diagonals) are given.The next line contains $q$ integers$t_1, t_2, \ldots, t_q$ ($0 < t_i < 2^{2 n + 2}$).It is guaranteed that the number of test cases for $n = 4, 5, 6, 7$ does not exceed $50, 10, 3, 1$ respectively.It is also guaranteed that the sum of$q$ over $T$ test cases does not exceed $5 \times 10^5$.

### 输出描述

For each test case, output $q$ lines, the $i$-th line of which contains an integer,
representing your answer to the $i$-th
query.It can be proved that the expected value is always a rational number.
Additionally, under the constraints of this problem, it can also be
proved that when that value is represented as an irreducible fraction $u / d$, we have $d \not\equiv 0 \pmod{10^9 + 7}$. Thus, there
is a unique integer$f$ ($0 \leq f < 10^9 + 7$) such that $u \times f \equiv d \pmod{10^9 + 7}$. This $f$ is what we need.

### 示例1

#### 输入

```plain
1
2 12
10 20
30 40
1 1 2 2
1 2 2 1
1 1 1 2
2 1 2 2
1 1 2 1
1 2 2 2
1 2 3 4 5 6 8 9 10 16 32 63
```

#### 输出

```plain
500000014
333333342
361111126
666666683
928571447
166666680
404761912
154761917
849206362
833333350
833333345
361111126
```

