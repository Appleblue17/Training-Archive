## E. Tournament

### 题目描述

Pog is watching a tournament. There are a total of $\textstyle 2k$ players in this tournament,
and initially, there are$\textstyle n$ different scores. For each $\textstyle i$,
there are $\textstyle b_i$ players who have a
score of $\textstyle a_i$. Each player has a
number between $\textstyle 1$ and $\textstyle 2k$, where the $\textstyle j$-th player with a score of $\textstyle a_i$ is numbered $\textstyle j + \sum_{1 \leq k < i} b_k$.

In each round, all$\textstyle 2k$ contestants are paired up for matches. In a match:
- If the two contestants have different scores, the one with the lower
    score wins;
- If the two contestants have the same score, the contestant with the
    smaller number wins.

After the match, the winner's score increases by $\textstyle 1$, and the loser's score
decreases by $\textstyle 1$.

Since Pog is playing Umamusume Pretty Derby, he did not pay close
attention to the tournament. He only knows that after one round, there
are $\textstyle m$ distinct scores, where for
each $\textstyle i$, there are $\textstyle d_i$ contestants with score $\textstyle c_i$.

Now, he wants to know: how many possible initial pairing schemes could
result in the given configuration after one round? Print the answer
modulo $\textstyle 998244353$. Two schemes
are considered different if there exists a contestant pairing up with a
different opponent in two schemes.

### 输入描述

The first line contains three integers $\textstyle k, n, m ~ (1 \le k \le 5 \times 10^6, 1 \leq n \le 5 \times 10^4, 1\leq m \le 10^5)$.

The next $\textstyle n$ lines, the $\textstyle i$-th line contains two integers $\textstyle a_i, b_i~(|a_i| \le 10^9, b_i \le 200)$.

The next $\textstyle m$ lines, the $\textstyle i$-th line contains two integers $\textstyle c_i, d_i~(|c_i| \le 10^9, d_i \le 400)$.

It is guaranteed that $\textstyle a_i$ are
all distinct, $\textstyle c_i$ are all
distinct, and $\textstyle \sum_{i = 1}^n b_i = \sum_{i = 1}^m d_i = 2k$.

### 输出描述

Output one single integer --- the number of possible pairing methods
modulo $\textstyle 998244353$.

### 示例1

#### 输入

```plain
2 2 3
1 2
3 2
0 1
2 2
4 1
```

#### 输出

```plain
1
```

### 示例2

#### 输入

```plain
3 3 2
1 2
3 2
5 2
2 3
4 3
```

#### 输出

```plain
10
```

