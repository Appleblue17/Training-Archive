## J. 游戏

### Problem Description

Alice 和 Bob 在玩取石子游戏，有$n$ 堆石子从左到右排成一排，初始时从左到右第$i$ 堆有 $x_{i}$ 颗石子。

Alice 和 Bob 轮流操作：
- 轮到 Alice 操作时，Alice
    从最左边的堆选至少一个石子，把选中的石子移到第二左的堆。
- 轮到 Bob 操作时，Bob
    从最右边的堆选至少一个石子，把选中的石子移到第二右的堆。

若轮到某人无法操作时，当前操作的人输掉游戏。

若 Alice 和 Bob 都使用最优策略，你需要判断 Alice 是否有先手必胜策略。

### Input

第一行输入一个正整数 $T(1 \leq T \leq 10^{5})$，表示数据组数。接下来按如下格式输入 $T$ 组数据：

每组第一行输入一个整数 $n(1 \leq n \leq 10^{6})$。

第二行输入 $n$ 个正整数表示每堆石子数 $x_{1},x_{2},\ldots,x_{n}(1 \leq x_{i} \leq 10^{9})$。

保证输入数据中 $\sum n \leq 3 \times 10^{6}$。

### Output

共输出 $T$ 行。

如果 Alice 有先手必胜策略，输出 `YES`，否则输出 `NO`。

### Sample Input

```plain
5
5
4 5 4 5 9
3
4 4 1
2
10 9
5
1 2 1 1 2
5
2 1 1 2 1
```

### Sample Output

```plain
NO
YES
YES
NO
YES
```

### Hint

本题输入输出量较大，建议使用较快速的输入输出方式（如关闭流同步的 `cin` /
`cout`）。

