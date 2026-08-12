## C. Phi Master

### Problem Description

小 C 在找 npy。

众所周知，找 npy 需要考虑两人之间的默契。经过初步筛选，小 C
列出了一个候选人列表 $a_{1},a_{2},\ldots,a_{n}$，其中 $a_{i}$ 表示第$i$ 号候选人的能力值。

如果小 C 的能力值为 $x$，那么候选人 $i$ 和小 C 之间的默契度为 $\varphi(xa_{i})$，其中 $\varphi$ 表示欧拉函数。

由于小 C 的能力值未知，小 R 想要你对每个可能的能力值 $x$，求出此时的最大默契度。

形式化地，对每组测试数据，给定序列 $a_{1},a_{2},\ldots,a_{n}$，对所有满足 $1 \leq x \leq 10^{7}$ 的整数 $x$，定义

$$F_{x} = \underset{1 \leq i \leq n}{\max}\varphi(xa_{i}).$$

你需要按照特殊格式输出这些值的压缩结果。

### Input

第一行一个正整数 $T$（$1 \leq T \leq 3$），表示测试数据的组数。

对于每组测试数据：
- 第一行包含一个正整数 $n$（$1 \leq n \leq 2 \times 10^{6}$），表示序列长度。
- 第二行包含 $n$ 个正整数 $a_{1},a_{2},\ldots,a_{n}$（$1 \leq a_{i} \leq 10^{7}$）。

### Output

对每组测试数据，令 $B = 1000$。你需要输出 $B$ 行，第$i + 1$ 行输出整数 $A_{i}$，其中 $0 \leq i < B$，并且

$$A_{i} = \bigoplus\limits_{\substack{1 \leq x \leq 10^{7} \\ x\mspace{6mu}\operatorname{}\mspace{6mu} B = i}}\left\lceil \frac{x}{B} \right\rceil F_{x}.$$

这里 $\oplus$ 表示按位异或。

多组测试数据的输出依次排列，**中间不需要输出空行**。

### Sample Input

```plain
1
8
13 7 10 20 4 9 19 16
```

### Sample Output

```plain
见题目附件
```

### Hint

[题目附件](https://acm.hdu.edu.cn/downloads/sample.out)

