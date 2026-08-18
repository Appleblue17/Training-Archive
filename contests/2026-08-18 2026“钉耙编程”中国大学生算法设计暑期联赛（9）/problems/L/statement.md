## L. Grand Swap Master

### Problem Description

小L在做Swap
Master这道题时读错题了，将题目原本的询问由$\sum_{i = 1}^{n - 1}\mid a_{i} - a_{i + 1}\mid$读成
如下的题面：
- 给定序列$\{ a_{n}\}$，定义其贡献
$$f\text{（}A\text{）} = \sum\limits_{i = 1}^{n - 1}\text{（}a_{i} - a_{i + 1}\text{）}^{2}$$
- 询问存在多少对合法的交换$i,j$，合法交换指$1 \leq i  f\text{（}A\text{）}$ 
现在小L不会做这道题了，作为队友，帮助他一下

### Input

每个测试文件包含多组测试数据。第一行包含测试数据的组$T$,
其中$1 \leq T \leq 30$。每组测试数据的格
式如下。

每组测试数据包含两行
第一行包含一个整数$n$，表示数列的长度
第二行包含$n$个整数$a_{i}$，表示数列的具体值

数据保证$1 \leq n \leq 10^{5},1 \leq a_{i} \leq 10^{5}$ 以及所有测试数据的$\sum n \leq 3 \times 10^{5}$

### Output

对于每组测试数据，输出一行一个整数，表示可能的交换对数

### Sample Input

```plain
2
3
1 2 10
5
1 4 2 5 3
```

### Sample Output

```plain
2
3
```

