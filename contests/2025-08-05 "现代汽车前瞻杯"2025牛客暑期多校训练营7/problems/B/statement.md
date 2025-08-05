## B. A Gift from the Star

### 题目描述

Alice and Bob enjoy playing a simplified version of Dou Dizhu: only
single cards can be played, and both players know each other's hands.

Initially, Alice and Bob each hold some cards (a total of $\textstyle n$ cards), and each card has a
unique rank. In each game, the two players take turns, with Alice
starting first. In a player's turn, assuming the opponent's last played
card had a rank of $\textstyle x$, they can
choose one of two operations:
- Pass (play no card).
- Play a card with a rank greater than $\textstyle x$.

Specifically, if the opponent has not yet acted or chose to pass in the
previous turn, the current player can only play any card and cannot
choose to pass. The player who plays all their cards first wins.

Over the next $\textstyle q$ days, Alice and
Bob play several games of Dou Dizhu. Each day, one of the following two
events occurs:
- The owner of the card with rank $\textstyle x$ changes. In other words,
    if it currently belongs to Alice, after this day it belongs to Bob;
    otherwise, after this day it belongs to Alice.
- They want to know who will win if they only play with cards whose
    ranks are between $\textstyle l$ and $\textstyle r$ (inclusive), assuming both
    players adopt optimal strategies. Specifically, if the opponent has
    not yet acted or chose to pass in the previous turn, the current
    player must play a card (cannot pass).

Help them predict the result of each game.

Note that all cards return to the player's hand after each game.

### 输入描述

The first line contains two integers$\textstyle n,q$ ($\textstyle 1 \le n,q \le 5\times 10^5$),
representing the total number of cards and the number of subsequent
days.

The second line contains a string $\textstyle s$ of length $\textstyle n$ consisting only of $\textstyle \texttt{A}$ and $\textstyle \texttt{B}$, where $\textstyle s_i=\texttt{A}$ means the card
with rank $\textstyle i$ initially belongs to
Alice, and otherwise it belongs to Bob.

The next $\textstyle q$ lines, the $\textstyle i$-th line contains several
integers, the first integer being$\textstyle op_i$ ($\textstyle op_i\in\{1,2\}$).
- If $\textstyle op_i=1$, the $\textstyle i$-th line contains another
    integer$\textstyle x_i$     ($\textstyle 1\le x_i \le n$), indicating
    that on the $\textstyle i$-th day, the
    owner of the card with rank $\textstyle x_i$ changed.
- If $\textstyle op_i=2$, the $\textstyle i$-th line contains two other
    integers$\textstyle l_i,r_i$     ($\textstyle 1\le l_i \le r_i \le n$),
    indicating a query about who will win if they only play with cards
    whose ranks are between$\textstyle l_i$     and $\textstyle r_i$.

It is guaranteed that at least one game is played.

### 输出描述

For each query, output a single string "Alice" or "Bob", representing
the winning player.

### 示例1

#### 输入

```plain
5 5
ABBAB
2 2 2
2 1 5
1 2
2 2 5
2 1 5
```

#### 输出

```plain
Alice
Alice
Bob
Bob
```

