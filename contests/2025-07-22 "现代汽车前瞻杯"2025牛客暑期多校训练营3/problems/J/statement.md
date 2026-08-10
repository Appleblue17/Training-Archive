## J. Jetton

### 题目描述

Yuki and Ena are playing a turn-based poker game.
Initially, Yuki has $x$ jetton, and Ena has $y$ jetton. The winner of each round is
determined as follows:

- If Yuki has a different number of jetton from Ena, the player with
  fewer jetton is the winner;
- If Yuki has the same number of jetton as Ena, Yuki is the winner.

The other player must pay the winner an amount of jetton equal to the
number of jetton the winner had.

When either player\'s number of jetton becomes $0$, the game ends immediately. You are asked
to determine whether the game will end in a finite number of rounds.
Specifically, if it does, you also need to compute the number of rounds
from start to finish.

### 输入描述

Each test contains multiple test cases. The first line of input contains
a single integer$t$ ($1 \leq t \leq 10^5$) --- the number of test
cases. The description of the test cases follows.

The first and only line of input of each test case contains two integers $x$ and$y$ ($1 \leq x, y \leq 10^9$), denoting the
initial jetton that Yuki and Ena initially possess, respectively.

### 输出描述

For each test case, output a single line containing an integer: if the
game ends in a finite number of rounds, output an integer representing
the number of rounds; otherwise, output $-1$.

### 示例1

#### 输入

```plain
5
100 100
30 90
15 55
11 4514
2 126
```

#### 输出

```plain
1
2
-1
-1
6
```

### 备注

In the first test case, in the first round, both Yuki and Ena have $100$ jetton, so Yuki is the winner. Yuki\'s
jetton count becomes $100 + 100 = 200$, and
Ena\'s jetton count becomes $100 - 100 = 0$.
At this point, the game ends immediately, and the number of rounds is $1$.

In the second test case, in the first round, Yuki has $30$ jetton and Ena has $90$ jetton; Yuki has fewer jetton, so she is
the winner. Her jetton count becomes $30 + 30 = 60$, while Ena\'s jetton count
becomes $90 - 30 = 60$. In the second round,
both Yuki\'s and Ena\'s jetton counts are $60$, and similarly, the number of rounds is $2$.

For the third test case, it can be proven that the game cannot end in a
finite number of rounds.
