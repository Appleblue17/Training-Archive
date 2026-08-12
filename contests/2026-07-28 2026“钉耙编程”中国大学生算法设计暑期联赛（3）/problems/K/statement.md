## K. Mex

### Problem Description

小 M 有 $A,B,C$ 三个由 $\lbrack 0,n)$ 中间的整数组成的排列。

小 H 有一个集合 $S$。

小 H 发现，可以取出 $S_{a} = \{ A_{i}\mid i \in S\},S_{b} = \{ B_{i}\mid i \in S\},S_{c} = \{ C_{i}\mid i \in S\}$。

小 M 发现，（mex{$S_{a}$},
mex{$S_{b}$},
mex{$S_{c}$}） 正好能够构成一个三元组。

小 M 不知道小 H 手里的集合$S$ 是什么，她想知道三元组 （mex{$S_{a}$},
mex{$S_{b}$},
mex{$S_{c}$}）在所有情况下有多少可能。

### Input

第一行输入一个正整数$T\text{（}1 \leq T \leq 10\text{）}$ 表述数据组数。

对于每组数据，第一行输入$n\text{（}1 \leq n \leq 2 \times 10^{5}\text{）}$ 表示集合大小。

接下来三行，每行 $n$ 个正整数，分别表示排列 $A,B,C$。

### Output

对于每组数据，输出一行一个数字表示答案。

### Sample Input

```plain
2
3
0 2 1
1 0 2
2 0 1
5
1 4 0 3 2
0 4 3 2 1
0 3 1 2 4
```

### Sample Output

```plain
7
11
```

