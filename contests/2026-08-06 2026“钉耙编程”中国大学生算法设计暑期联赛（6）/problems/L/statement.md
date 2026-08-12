## L. P2P

### Problem Description

月一不小心下了一款大型开放风险软件。

（此处需要一张图）
- -----------------------------------------------------------------------

给定一个大小为 $n$ 的有根树，根节点为 $1$。记 $f_i$ 表示 $i$ 节点的父亲，其中满足 $i\in[2,n]$。初始每个点有两个权值 $A_i,B_i$。$A_i$ 初始给出，$B_i$ 初始为 $0$。现在执行以下操作 $998^{244^{353}}$ 次：
- **依次考虑** $2\sim n$，令 $B_{f_i}\leftarrow B_{f_i}+B_{i}+A_i$，$B_i\leftarrow 0$。

求操作完 $998^{244^{353}}$ 次后的 $\operatorname{sgn}\lparen B_1\rparen $。其中 $\operatorname{sgn}\lparen x\rparen $ 表示 $x$ 的符号。若 $x=0$，则 $\operatorname{sgn}\lparen x\rparen =0$；否则 $\operatorname{sgn}\lparen x\rparen =\dfrac{|x|}{x}$。

### Input

第一行一个整数 $T$（$1\le T\le 20$）表示测试数据组数。

对于每组测试数据：
- 第一行包含一个整数 $n$（$2\le n\le 2\times10^5$）。
- 第二行包含 $n$ 个整数，表示 $A_i$（$\left|A_i\right|\le 10^9$）。
- 第三行包含 $n-1$ 个整数，第 $i$ 个表示 $f_{i+1}$（$1\le f_i\le n$   且 $f_i\ne i$）。

对于所有测试数据，保证给定的树以 $1$ 为根。

### Output

对于每组测试数据，输出一行一个整数，表示操作完 $998^{244^{353}}$ 次操作后的 $\operatorname{sgn}(B_1)$。

### Sample Input

```plain
3
5
-5 -1 -1 -2 -7
1 1 5 3
5
5 5 5 9 8
1 1 5 3
5
-1 -2 3 -5 4
1 1 5 3
```

### Sample Output

```plain
-1
1
1
```

