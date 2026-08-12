## A. 今晚吃什么

### Problem Description

**本场比赛完整题目集参见：[PDF
题面](https://acm.hdu.edu.cn/downloads/2026HDU7-ProblemSheet.pdf)**
- -----------------------------------------------------------------------

"今晚吃什么？"真是一个难以解决的问题。

Hare
在竞赛网站上发布了有关"今晚吃什么"的帖子。不一会儿，帖子下方按照时间顺序就有了 $n$ 则评论，记作 $s_{1},s_{2},\cdots,s_{n}$。每则评论都是一个字符串，保证评论的长度随发布时间**单调不降**，也保证任意两则评论**不完全相同**。

不过，Hare 发现有一些是 Maki 骇入了网站，伪装成参赛选手发布的评论。Hare
已知，假如去除了 Maki 伪装发布的评论，剩下的参赛选手发布的评论满足：

每一则评论一定是在上一则评论的基础上，添加一段可能为空的字符串作为前缀，以及一段可能为空的字符串作为后缀所得到的。也就是说，上一则评论一定是本则评论的子串。

Hare 想知道，基于已知信息，对于 $k = 0,1,2,\cdots,n - 1$，若恰有$k$ 则评论是伪装的，那么有多少种可能的伪装情况？答案对$998244353$ 取模。两种情况不同当且仅当存在一则评论，在其中一种情况下是 Maki
发布的，而在另外一种情况下是参赛选手发布的。

### Input

**本题包含多组测试数据。**

首先在第一行输入一个整数 $T$（$1 \leq T \leq 300$）表示测试数据组数。

接下来对于每一组测试数据：

第一行包含一个整数 $n$（$1 \leq n \leq \sum n \leq 10^{5}$）表示评论数量。

接下来 $n$ 行，第 $i + 1$（$1 \leq i \leq n$）行包含一个字符串 $s_{i}$（$1 \leq \mid s_{i}\mid$），表示第$i$ 则评论。保证输入的字符串长度单调不降，保证输入的任意两个字符串不完全相同，保证单组测试数据内输入的字符串长度之和不超过 $2 \times 10^{5}$。

保证所有测试数据输入的字符串均只包含小写拉丁字母，长度之和不超过 $6 \times 10^{5}$。

### Output

对于每一组测试数据，输出包含一行$n$ 个整数表示 Maki 在$k = 0,1,2,\cdots,n - 1$ 的条件下，可能的伪装情况数对$998244353$ 取模的值。

### Sample Input

```plain
2
9
a
b
ab
ba
abc
abcd
abecd
abcde
fabcde
11
umm
ummspring
ummnahida
ummturkey
ummpastdays
ummamberconjecture
ummnpcnpcnpcnpcnpc
ummstrawberrystrawberry
ummkurokokurokokurokokuroko
ummcomputercomputercomputer
ummtoptreetoptreetoptreetoptree
```

### Sample Output

```plain
0 0 0 2 11 25 32 25 9
0 0 0 0 0 0 0 0 0 10 11
```

### Hint

![figure](https://files.seeusercontent.com/2026/08/08/c7Rw/hint-A5.png)

对于第一组测试数据，在$k = 6$ 的条件下，如上图：
- 情况 1 认为，评论 `a`、`abc`、`abcde`
    是参赛选手发布的。该情况合理，因为它满足已知信息给出的条件。
- 情况 2 通过验证也合理。它与情况 1 不完全一致，因此 $k = 6$ 时的答案需要同时统计到它们。
- 情况 3 认为，评论 `ab`、`abcd`、`abecd`
    是参赛选手发布的。该情况不合理，因为 `abcd` 不是 `abecd` 的子串。
- 情况 4 通过验证也不合理，因为 Maki 伪装的评论数量应当为 $6$，而不是情况 4 中的 $3$。

