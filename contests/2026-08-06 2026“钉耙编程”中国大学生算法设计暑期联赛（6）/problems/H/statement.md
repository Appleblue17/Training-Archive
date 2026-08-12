## H. CuteSafari

### Problem Description

称 $S$ 的一次变换为把 $S$ 分割成若干长度 $\geq k$ 的子串，每个子串的开头末尾交换。

现在给你长度为 $n$ 的字符串 $S$ 和 $T$。问 $S$ 可不可以通过若干次变换得到 $T$，或者报告无解。

### Input

第一行包含一个整数 $T$（$1 \leq T \leq 10^{5}$），表示测试数据组数。

对于每组测试数据：
- 第一行包含两个整数 $n,k$（$1 \leq k \leq n \leq 10^{7}$）。
- 第二行包含一个字符串 $S$。
- 第三行包含一个字符串 $T$。

保证对于所有测试数据，输入的字符串中只有小写英文字母，且 $1 \leq \sum n \leq 10^{7}$。

### Output

对于每组测试数据，输出一行一个字符串 `Yes` 或 `No` 表示答案。

### Sample Input

```plain
4
3 3
abc
cba
10 2
cutesafari
eutcasafir
3 1
aab
abb
10 3
safaricute
eutcasafir
```

### Sample Output

```plain
Yes
Yes
No
No
```

