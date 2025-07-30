## M. Monopoly

### 题目描述

Bobo is playing a game of Monopoly with$N$ other players, who have $a_1, a_2, \ldots, a_N$ gold coins
respectively, while Bobo has no gold coins. It is now Bobo\'s turn, and
in order to turn the tide, Bobo wishes to use the \"Equalization Card\"
item. This item allows Bobo to choose a number of players **excluding
himself** and replace their gold coin counts with the **floor of the
average** of the selected players\' gold coins. Formally, when Bobo uses
an Equalization Card, he can choose a non-empty subset $S \subseteq \{1,2,\ldots,N\}$, and let $T = \left\lfloor \frac{\sum_{i \in S} a_i}{|S|}\right\rfloor$.
For all $i \in S$, the gold coin count of
player $i$ is set to $T$.

Bobo has an unlimited number of \"Equalization Cards\" and can use any
number of them in this turn. Bobo wishes to minimize the maximum number
of gold coins that the other $N$ players can
have by using the \"Equalization Cards\" in this turn. Please help Bobo
calculate what this minimum value is.

### 输入描述

The input consists of $T$ test cases
($1 \le T \le 1000$). Each test case is
described as follows.

The first line contains a single positive integer$N$ ($2 \le N \le 50$), representing the number
of other players.

The next line contains $N$ non-negative
integers$a_1, a_2, \ldots, a_N$ ($0 \le a_i \le 50$), representing the number
of gold coins owned by the other players.

### 输出描述

For each test case, output a single integer in one line, denoting the
answer.

### 示例1

#### 输入

```plain
2
5
4 6 2 7 5
5
1 1 1 1 1
```

#### 输出

```plain
3
1
```
