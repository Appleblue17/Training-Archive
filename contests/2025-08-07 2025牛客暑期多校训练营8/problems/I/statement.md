## I. Tennis Match

### 题目描述

The training team has $m$ candidate players,
and now $2 n$ players need to be selected and
paired to participate in $n$ tennis doubles
matches.The $i$-th player has an estimated capability $e_i$ and is classified into junior and
senior categories based on their training duration.The $i$-th match requires that the capability
of any participating player does not exceed $l_i$, and for stability reasons, the coach
requires that the capability difference between every two paired players
does not exceed $d$.Though there is no limitation for players to be paired based on the same
category, in order to fully tap into the potential of junior players,
the coach expects a few junior players to be selected for
participation.The coach tends to know, for each $t = 0, 1, \ldots, 2 n$, if there exists a
pairing scheme that contains exactly$t$ junior players and also satisfies the above constraints. If no such
scheme exists, output $-1$, or otherwise
output the maximum possible sum of the ability values of the selected $2 n$ players.

### 输入描述

The first line contains an integer$T$ ($1 \leq T \leq 10^5$), indicating the number
of test cases.Then follow $T$ test cases. For each test
case:The first line contains three integers $n$, $m$ and$d$ ($1 \leq n \leq 20$, $2 n \leq m \leq 10^5$, $0 \leq d < 10^9$).The second line contains $n$ integers$l_1, l_2, \ldots, l_n$ ($1 \leq l_i \leq 10^9$).The next $m$ lines describe the candidate
players\' information, the $i$-th line of
which contains two integers $e_i$ and$t_i$ ($1 \leq e_i \leq 10^9$, $t_i \in \{1, 2\}$), indicating that the
estimated capability of the $i$-th player is $e_i$, and is junior type if $t_i = 1$, or otherwise senior type.It is guaranteed that the sum of $m$ across
all $T$ test cases does not exceed $2 \times 10^5$.

### 输出描述

For each test case, output$(2 n + 1)$ integers in a line, where the $i$-th integer
represents the answer with respect to selecting exactly $(i - 1)$ junior players.

### 示例1

#### 输入

```plain
2
4 9 400
800 900 1050 1200
46 1
264 2
295 1
305 1
332 2
678 1
770 2
903 2
1291 2
4 9 400
800 900 1050 1200
46 1
264 2
295 1
305 2
332 2
678 2
770 2
903 2
1291 1
```

#### 输出

```plain
-1 -1 -1 -1 3593 -1 -1 -1 -1
-1 -1 3593 -1 -1 -1 -1 -1 -1
```

