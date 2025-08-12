## L. Ping Pong

### 题目描述

There are $\textstyle n$ classmates to play
ping pong on a single table in turns. The $\textstyle i$-th person's ability value is $\textstyle a_i$, with all ability values
being distinct. The rules for playing ping pong are as follows:
- At the beginning, there is only one person on the court, numbered $\textstyle 1$. The queue$\textstyle Q = \{2, 3, \dots, n\}$     represents the current players waiting in line from front to back.
- In each subsequent round, the player at the front of the queue will
    pop out and compete against the person on the court. During the
    match, the player with the higher ability value will win. The loser
    will join the back of the queue, while the winner remains on the
    court.

However, to prevent strong players from dominating the game, an
additional anti-monopoly rule has been established: if a person has
already played in $\textstyle n - 1$ matches
consecutively, then the next match will be considered a loss for that
person regardless of the outcome; they will join the back of the queue,
while their opponent will remain on the court.

They will play a total of$\textstyle k$ rounds of matches. Can you calculate how many matches each person played
in?

### 输入描述

The input consists of multiple test cases. The first line contains a
positive integer $\textstyle T~(1 \le T \le 10000)$ indicating
the number of test cases. Each test case is described as follows:
- The first line contains two integers $\textstyle n, k~(3 \le n \le 2 \times 10^5, 1\leq k \leq 10 ^ 9)$.
- The second line contains$\textstyle n$     integers $\textstyle a_1, a_2, \dots, a_n~(1 \le a_i \le 10^9)$.

It is guaranteed that all$\textstyle a_i$ are distinct, and the sum of$\textstyle n$ across $\textstyle T$ test cases will not
exceed $\textstyle 2 \times 10 ^ 5$.

### 输出描述

For each test case, output one line containing $\textstyle n$ integers. The $\textstyle i$-th integer represents the
total number of matches the $\textstyle i$-th
classmate in the input order has played in.

### 示例1

#### 输入

```plain
2
3 3
100 50 20
3 5
2 3 1
```

#### 输出

```plain
3 2 1
4 4 2
```

### 备注

For the first sample case, here is what happened:

1.  On-court $\textstyle 1$, queue $\textstyle [2,3]$. $\textstyle 1$ vs. $\textstyle 2$ : $\textstyle 1$ wins, queue becomes $\textstyle [3,2]$.

2.  On-court $\textstyle 1$, queue $\textstyle [3,2]$. $\textstyle 1$ vs. $\textstyle 3$ : $\textstyle 1$ wins, queue becomes $\textstyle [2,3]$.

3.  On-court $\textstyle 1$, queue $\textstyle [2,3]$. $\textstyle 1$ vs. $\textstyle 2$ : $\textstyle 2$ wins (anti-monopoly rule
    applies), queue becomes $\textstyle [3,1]$.

