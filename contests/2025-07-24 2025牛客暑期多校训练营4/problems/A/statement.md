## A. All Kinds of Dice

### 题目描述

Define a \`\`die\'\' as any shape with at least one face such that each
face shows a positive integer. When a die is rolled, one of its faces is
selected uniformly at random. When two dice roll against each other, the
die whose selected face shows a higher number earns $1$ point; if both numbers are equal, each
die earns $1/2$
points. For dice $D$ and $D_0$, define $\mathrm{score}(D, D_0)$ as the expected
number of points $D$ earns from a single roll
against $D_0$.

Given a tournament of $N$ vertices, please
construct $N$ dice $D_1,D_2,\ldots,D_N$ such that

- For every directed edge $i \to j$, $\mathrm{score}(D_i,D_j) > 1/2$.

<div>

Report if it is impossible to achieve the goal.

</div>

### 输入描述

The first line of the input contains a single integer$N$ ($2 \le N \le 100$), denoting the number of
vertices in the tournament.

Then, $N$ lines follow. The $i$-th line contains a binary string $s_i$.

It is guaranteed that exactly one of $s_{i,j}$ and $s_{j,i}$ equals to $\texttt{`1'}$ for any $1 \le i < j \le N$ and $s_{i,i} = \texttt{`0'}$ for all $1 \le i \le N$.

### 输出描述

If there exists no solution, output $-1$ in
one line.

Otherwise, output $N$ lines. The $i$-th line describes the $i$-th dice:\ $\bullet$ The first integer $k$ denotes the faces of the $i$-th \`\`die\'\';\ $\bullet$ Then$k$ integers$v_1,v_2,\ldots,v_k$ ($1 \le v_i \le 10^9$) follow, denoting the
integers in each face.
The total number of faces over all dice should be bounded by $10^5$.

### 示例1

#### 输入

```plain
4
0100
0010
1001
1100
```

#### 输出

```plain
3 1 5 9
3 3 4 8
3 2 6 7
3 5 5 6
```
