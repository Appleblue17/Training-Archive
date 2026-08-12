## L. 向量

### Problem Description

*上一世，小 L
线性代数期末考试不会做这道题导致挂科，身败名裂，多年心血付诸东流。*

*这一世，小 L 突破重重关卡，成功将手机带进考场，把这道题拍给了豆包。*

*你作为被囚禁于豆包中的众多灵魂之一，被分配到解答这个问题。*

已知 $\mathbf{A}$ 是一个 $n$ 行 $n$ 列的 01
矩阵，且矩阵中值为 $1$ 的位置的个数恰好为 $m$。 $\mathbf{v}$ 是一个 $n$ 维列向量，且 $\mathbf{v}$ 的每个分量均为 $\lbrack - 10^{9},10^{9}\rbrack$ 内的整数。

设向量 $\mathbf{u} = (\mathbf{I} + k\mathbf{A})\mathbf{v}$，其中 $\mathbf{I}$ 为$n$ 阶单位矩阵，$k$ 是一个给定的常数。

请你根据给定的 $n,k,m,\mathbf{A},\mathbf{u}$，求出列向量 $\mathbf{v}$。

若存在多个满足条件的 $\mathbf{v}$，请输出其中**字典序最小**的答案；若不存在满足条件的 $\mathbf{v}$，则输出 `No Solution`。

对于两个 $n$ 维向量 $v_{1},v_{2}$，称 $v_{1}$ 的字典序小于 $v_{2}$ 的字典序，当且仅当存在 $1 \leq i \leq n$，使得对于所有 $1 \leq j < i$，都有 $v_{1,j} = v_{2,j}$，且 $v_{1,i} < v_{2,i}$。

### Input

第一行输入一个正整数 $T$ $(1 \leq T \leq 10^{5})$，表示数据组数。

接下来按如下格式输入 $T$ 组数据：

第一行输入三个整数 $n,k,m$ $(1 \leq n,m \leq 10^{6},2 \leq k \leq 10^{6},\sum n,\sum m \leq 2 \times 10^{6})$。

第二行输入 $n$ 个整数表示 $\mathbf{u}^{T} = (u_{1},u_{2},\ldots,u_{n})$ $(\mid u_{i}\mid \leq 10^{18})$。

第三行输入 $m$ 个整数 $x_{1},x_{2},\ldots,x_{m}$ $(1 \leq x_{i} \leq n)$。

第四行输入 $m$ 个整数 $y_{1},y_{2},\ldots,y_{m}$ $(1 \leq y_{i} \leq n)$。

第三行和第四行表示矩阵 $\mathbf{A}$ 中值为 $1$ 的位置，即 $a_{x_{i},y_{i}} = 1$。

保证每组数据内不存在重复的$(x_{i},y_{i})$ 对。

### Output

共输出 $T$ 行。

对于每组数据，输出 $n$ 个整数，表示 $\mathbf{v}^{T} = (v_{1},v_{2},\ldots,v_{n})$。

若无解或答案不合法，输出一行字符串 `No Solution`。

### Sample Input

```plain
2
2 2 1
3 1
1
2
2 2 2
1 0
1 2
2 1
```

### Sample Output

```plain
1 1
No Solution
```

### Hint

本题输入输出量较大，建议使用较快速的输入输出方式（如关闭流同步的 `cin` /
`cout`）。

