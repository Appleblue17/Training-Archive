## I. PalindromemordnilaP

### Problem Description

**温馨提示：请注意你代码的时间常数。**

定义一个字符串 $s$ 的子串 $s_{[l,r]}$ 为，依次拼接$s_l,s_{l+1},\cdots,s_r$ 而形成的字符串，其中下标从 $1$ 开始标号。

定义一个字符串$s$ 是**广义回文**的，当且仅当它能被表示为 $s=t_1+t_2+\cdots+t_k$，其中$t_i$ 为任意非空字符串，$k$ 为 $\ge2$ 的正整数，且满足对于任意 $1\le i\le k$，$t_i=t_{k+1-i}$。

例如，字符串$\texttt{abcbacab}$ 是广义回文的，因为它可以被表示为 $\texttt{ab}+\texttt{c}+\texttt{ba}+\texttt{c}+\texttt{ab}$。

给定一个长为 $n$，只包含前 $m$ 个小写字母的字符串 $s$。你要处理$q$ 次查询：
- 给定 $l,r$，问$s_{[l,r]}$     有多少个子串，满足它是**广义回文**的。

由于出题人懒得造有强度的数据，因此字符串$s$ 随机生成。具体的，每个位置上的字符均在前$m$ 个小写字母中等概率随机选取。

### Input

本题有多组数据。第一行一个正整数 $T$（$1\le T\le10^3$）表示数据组数。对于每组测试数据：

第一行输入三个正整数 $n,m,q$（$1\le n\le2\cdot10^5$，$1\le m\le26$，$1\le q\le2\cdot10^5$）。

第二行输入字符串 $s$。

接下来 $q$ 行，每行两个正整数 $l,r$（$1\le l\le r\le n$）表示一个询问。

保证 $\sum n\le2\cdot10^6$，$\sum q\le2\cdot10^6$。

### Output

为了减少输出量，对于每组数据，记第$i$ 次询问的答案为 $ans_i$，输出 $\oplus_{1\le i\le q}i\cdot ans_i$，其中 $\oplus$ 表示按位异或。

### Sample Input

```plain
1
8 3 2
abcbacab
1 8
2 6
```

### Sample Output

```plain
12
```

