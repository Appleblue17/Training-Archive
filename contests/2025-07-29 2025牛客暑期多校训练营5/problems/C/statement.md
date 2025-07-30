## C. Array Deletion Game

### 题目描述

<div>

Alice and Bob play a game on an array $\textstyle A$ of length $\textstyle N$, where all elements are
positive integers. The rules are as follows:

<div>

\

Players take turns, with Alice going first.

<div>

\

On each turn, a player can:
- Remove the leftmost element of the array, or
- Remove the rightmost element of the array.

<div>

\

If after a player's move, the sum of the remaining elements $\textstyle \leq s$, that player loses the
game.

<div>

\

Given the initial array, you need to process $\textstyle Q$ queries. For each query with a
different $\textstyle s$, determine whether
Alice has a winning strategy.

</div>

</div>

</div>

</div>

</div>

### 输入描述

<div>

The first line contains an integer$\textstyle N$ ($\textstyle 1 \leq N \leq 10^5$), the length
of the array.

</div>

<div>

\

</div>

The second line contains$\textstyle N$ integers$\textstyle A_i$ ($\textstyle 1 \leq A_i \leq 10000$), the
elements of the array.

<div>

\

</div>

<div>

The third line contains an integer$\textstyle Q$ ($\textstyle 1 \leq Q \leq 10^5$), the number
of queries.

</div>

<div>

\

</div>

<div>

The next $\textstyle Q$ lines each contain an
integer$\textstyle s$ ($\textstyle 1 \leq s < \sum A$), the
threshold for the current query.

</div>

### 输出描述

<div>

For each query $\textstyle s$, output one
line:

</div>

<div>

\

</div>
- If Alice has a winning strategy, output "Alice".

    <div>

    \

    </div>
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

