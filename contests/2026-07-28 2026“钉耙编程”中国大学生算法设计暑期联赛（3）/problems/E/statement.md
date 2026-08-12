## E. GCD

### Problem Description

小 H 和小 M 玩游戏。

在游戏开始，小 H 会有一个整数 $x$，小 M
每次操作会找到两个正整数 $a,b$（满足 $a \times b = x$ 且 $\max\{ a,b\} > 1$），之后再把 $a,b$ 的 gcd 还给小 H。

小 M 笨笨的，她想知道这个游戏最多会进行几轮

### Input

第一行输入一个整数$T\text{（}T \leq 200\text{）}$ 表示数据组数。

接下来 $T$ 行，每行一个整数 $x\text{（}1 \leq x \leq 10^{18}\text{）}$，表示最开始小 $H$ 手里的整数

### Output

$T$ 行，每行一个整数，表示这组数据对应的答案。

### Sample Input

```plain
3
4
5
9
```

### Sample Output

```plain
2
1
2
```

