## F. For the Treasury!

### 题目描述

In the early 11th century A.D., there were groups of Danish invaders
known as Vikings in England.\
\
Askeladd, a leader of a group of Viking pirates, searches for treasure
on this fertile land. After attacking a village one night, they
collected a total of $n$ treasures, ordered
in a line, with values $a_1,a_2,\dots,a_n$,
respectively. Askeladd\'s group had an agreement on how to divide these
treasures: Askeladd, as the leader, would take **the
first** $k$ treasures, i.e., treasures with
values $a_1,a_2,\dots,a_k$, while the
remaining pirates would divide the rest. However, as it was too late,
they decided to make this division the next morning.\
\
Askeladd, being cunningly smart, sneaked out at night and tried to
rearrange the treasures so that he could have a larger total value of
the treasures. However, for certain reasons, he was only allowed to
**swap two adjacent treasures** at a time. Additionally, each swap would
cost Askeladd a value of $c$, considering the
risk of being discovered by the other pirates. Askeladd can perform any
number (possibly zero) of swaps.\
\
Askeladd wonders what the maximum profit he can gain is (equal to the
total value of all treasures he can get minus the number of total costs
from the swaps).\

### 输入描述

The first line contains three integers$n,k$ and $c$ $(0\leq k\leq n\leq 3\times 10^5,0\leq c\leq 10^9)$,
denoting the number of treasures, the number of treasures Askeladd is
promised to take from the first, and the cost to swap two adjacent
treasures, respectively.\
\
The next line contains $n$ integers $a_1,a_2,\dots,a_n$ $(1\leq a_i\leq 10^9)$, denoting the values
of the treasures in order.

### 输出描述

Output one integer in a line, denoting the maximum profit Askeladd can
gain.

### 示例1

#### 输入

```plain
3 2 1
1 3 5
```

#### 输出

```plain
6
```

### 示例2

#### 输入

```plain
3 2 2
1 3 5
```

#### 输出

```plain
4
```

### 示例3

#### 输入

```plain
4 2 1
2 3 5 6
```

#### 输出

```plain
7
```

### 示例4

#### 输入

```plain
7 3 2
2 1 3 6 10 9 7
```

#### 输出

```plain
10
```

