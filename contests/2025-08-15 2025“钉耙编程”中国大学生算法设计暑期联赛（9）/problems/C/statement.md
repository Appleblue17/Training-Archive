## C. 碗窑尽空

### Problem Description

伟大的三文鱼曾有诗云：

"老猫下山，飞檐走壁，出销吃西人，碗窑尽空。"

jimmyywang 有一个长度为 $n$ 的字符串 $S$，我们称$S$ 中左端点是第 $l$ 个字符，右端点是第 $r$ 个字符的子串为 $ S_{[l,r]} $。

现在给定**全是小写字母**的字符串 $S$，请对每个 $k\in[1,n]$，求出：

$$ s_k= \sum_{1\le i<j\le n-k+1} \left[ S_{ \left[i,i+k-1 \right] } = S_{\left[ j,j+k-1 \right] } \right] f_{j-i} $$

对 $998244353$ 取模的值。其中，当$x\le 1$ 时，$f_x=x$，否则 $f_x=f_{x-1}+3f_{x-2}$。

### Input

本题有 $T$（$ 1\le T\le 10 $）
组测试数据。

对于每组测试数据，第一行输入 $n$（$ 1 \le n \le 3\times 10^5 $，$\sum n\le 10^6$）
表示字符串长度，第二行输入字符串 $S$，保证仅含小写字母。

### Output

对于每组测试数据，输出 $n$ 行，第 $i$ 行一个数代表 $s_i$。

### Sample Input

```plain
1
5
ababa
```

### Sample Output

```plain
10
2
1
0
0
```

