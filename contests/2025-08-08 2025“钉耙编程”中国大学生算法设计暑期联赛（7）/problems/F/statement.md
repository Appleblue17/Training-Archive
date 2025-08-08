## F. 伤害冷却比

### Problem Description

小 Q 正在玩的 RPG
游戏最近推出了一个新系统使得玩家可以按自己的喜好调整技能的数据。

在这款游戏中，每个玩家只有一个技能，该技能的单次伤害为 1，冷却时间为$N$ 秒。衡量一个技能强力程度的标准只有一个，那就是在 $K$ 秒内这个技能可以造成多少伤害，即 $\lfloor\frac{K}{N}\rfloor+1$，这是因为一开始技能并不在冷却中。

利用新系统，玩家必须在 $[L,R]$ 内挑选一个实数 $X$，在保持技能伤害冷却比不变的情况下将技能的单次伤害与冷却时间都乘以 $X$。请帮助小 Q 挑选最佳的 $X$，最大化 $X\cdot\left(\lfloor\frac{K}{X\cdot N}\rfloor+1\right)$。请注意，$[L,R]$ 可能不会覆盖实数 1，此时无法维持原始单次伤害与原始冷却时间。

### Input

第一行包含一个正整数 $T$（$1\leq T\leq 100\,000$），表示测试数据的组数。

每组数据包含一行六个正整数 $K,N,A,B,C,D$（$1\leq K,N,A,B,C,D\leq 30\,000$, $\frac{A}{B}\leq\frac{C}{D}$），表示参数 $K,N,L,R$，其中 $L=\frac{A}{B}$，$R=\frac{C}{D}$。

### Output

对于每组数据输出一行一个既约分数
"$\texttt{P/Q}$"，表示$X\cdot\left(\lfloor\frac{K}{X\cdot N}\rfloor+1\right)$ 的最大可能值。

### Sample Input

```plain
3
40 9 3 10 2 1
20 8 1 1000 3 2
10 6 1 30000 2 30000
```

### Sample Output

```plain
6/1
15/4
25001/15000
```

