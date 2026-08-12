## E. indigo 究竟是谁？

### Problem Description

![figure](../../../data/images/C1233-1005-1.jpg)

如图所示，indigo
机器人由于一直在复读别人的话，因此产生了出乎意料的效果。

但 indigo 的主人不希望大家知道谁是 indigo，因此他给 indigo
换了一个头像。但由于 indigo
只会复读别人的话，所以大家可以从聊天记录里分析出 indigo 可能是谁。

首先需要确认的是 indigo 究竟说了哪些话，indigo 发的话需要满足如下要求：
- indigo 说的话只能是前文别人已经说过的话。
- 一句话只有被连续复读过 $k$ 次，才能被
    indigo 用来复读。
- 一句话只有在说出后，有任何人（包含 indigo 自己）发表了 $m$ 句话后，才能被 indigo 用来复读。
- 为了避免禁言，如果一句话被说出达到了$q$     次，indigo 将会把这句话从语料库中**永久移除**并且不再复读这句话。

现在给出聊天记录，你需要判断每句话是否可能由 indigo 说出。

### Input

第一行输入一个整数 $T$（$1 \leq T \leq 30$），表示数据组数。

第一行四个整数 $n,k,m,q$（$1 \leq n \leq 10^{4},1 \leq k \leq 5,1 \leq m \leq 10,k \leq q \leq 50$），表示聊天记录条数，以及
indigo 复读的相关参数。

接下来$n$ 行，每行一个仅由大小写英文字母和数字组成的字符串 $S_{i}$（$1 \leq \mid S_{i}\mid \leq 10^{6}$），表示一个人发表的话。

保证所有数据的 $\sum\mid S_{i}\mid \leq 2 \times 10^{7}$。

### Output

对于每一组数据，按从小到大的顺序输出一行整数，表示 indigo
可能说的是哪几句话。如果 indigo 实际上一句话都没有说，请输出一行 $\texttt{empty}$。

### Sample Input

```plain
2
12 2 3 5
add1
add1
add1
minus1
add1
add2
add2
add1
minus3
add3
add1
minus3
20 1 4 12
y
y
w3
i
q
7k
3vda
uo7
vd2jw
b92
7dkfcrq
4n
g
idahv
bnhcphdb1
bnhcphdb1
2u1
szxphn4n45pn
7bpqz
dnvu1xv59izr
```

### Sample Output

```plain
5 8
empty
```

### Hint

对于第一组样例，$\texttt{add1}$ 第一次出现在第 1 句，并且在第 2 句就达到了连续复读 2
次的要求，但在第4句话说完后$\texttt{add1}$ 才加入 indigo 的语料库，所以第 5 句和第 8 句可能是 indigo 说的，但说完第
8 句后 $\texttt{add1}$ 的复读次数达到了 5
次，因此 indigo 会将$\texttt{add1}$ 从语料库中删除，所以第 11 句一定不是 indigo 说的。

对于第二组样例，没有话满足条件，故输出 $\texttt{empty}$。

