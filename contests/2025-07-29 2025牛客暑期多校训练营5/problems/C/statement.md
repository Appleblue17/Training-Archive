## C. Array Deletion Game

### 题目描述

Alice and Bob play a game on an array $\textstyle A$ of length $\textstyle N$, where all elements are
positive integers. The rules are as follows:

Players take turns, with Alice going first.

On each turn, a player can:
- Remove the leftmost element of the array, or
- Remove the rightmost element of the array.

If after a player's move, the sum of the remaining elements $\textstyle \leq s$, that player loses the
game.

Given the initial array, you need to process $\textstyle Q$ queries. For each query with a
different $\textstyle s$, determine whether
Alice has a winning strategy.

### 输入描述

The first line contains an integer$\textstyle N$ ($\textstyle 1 \leq N \leq 10^5$), the length
of the array.

The second line contains$\textstyle N$ integers$\textstyle A_i$ ($\textstyle 1 \leq A_i \leq 10000$), the
elements of the array.

The third line contains an integer$\textstyle Q$ ($\textstyle 1 \leq Q \leq 10^5$), the number
of queries.

The next $\textstyle Q$ lines each contain an
integer$\textstyle s$ ($\textstyle 1 \leq s

### 输出描述

For each query $\textstyle s$, output one
line:
- If Alice has a winning strategy, output "Alice".
- Otherwise, output "Bob".

### 示例1

#### 输入

```plain
5
1 3 5 7 9
3
10
15
20
```

#### 输出

```plain
Alice
Alice
Bob
```

