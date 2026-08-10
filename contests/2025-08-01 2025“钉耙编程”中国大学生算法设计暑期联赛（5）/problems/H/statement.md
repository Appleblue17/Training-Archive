## H. 双端魔咒

### Problem Description

对于在字符串中藏各种禁忌词语来达到魔咒的效果，这在某国屡见不鲜，于是为了更好地应对非法使用魔咒的案件发生，因此该国人民都需要学习魔咒学来帮助自己对魔咒进行防御。

其中有一类魔咒被称为双端魔咒，这样的魔咒对应的字符串需要满足如下要求：

1.  存在一个前缀 $p$，$p$     属于集合 $pre$；
2.  存在一个后缀 $s$，$s$     属于集合 $suf$。

注意，第二条要求中选择的 $s$ 和 $p$ 之间可以有重叠部分。

现在定义一个字符串的能量为其满足双端魔咒条件的子区间数目。你可以快速地求出给定的字符串的能量吗？

注：一个字符串的前缀是指删除字符串末尾连续若干个字符之后形成的字符串，例如 $\texttt{a, ab, abc}$ 都是字符串$\texttt{abc}$ 的前缀；一个字符串的后缀是指删除字符串开头连续若干个字符之后形成的字符串，例如 $\texttt{c, bc, abc}$ 都是字符串 $\texttt{abc}$ 的后缀。

### Input

第一行读入一个整数 $T$，表示数据总数。

对于每组数据输入如下：

第一行两个整数 $l,r$（$1\le l,r\le 10^6$），表示 $pre,suf$ 的字符串数量。

第二到第$l+1$ 行，每行一个由小写英文字母构成的字符串 $pre_i$（$1\le |pre_i|\le 10^6$），表示 $pre$ 中的字符串。

第 $l+2$ 到第$l+r+1$ 行，每行一个由小写英文字母构成的字符串 $suf_i$（$1\le |suf_i|\le 10^6$），表示 $suf$ 中的字符串。

第 $l+r+2$ 行一个由小写英文字母构成的字符串 $S$（$1\le |S|\le 10^6$），表示询问的串。

数据保证单组数据 $\sum |pre_i|, \sum |suf_i| \le 10^6$，对于全部数据，$\sum |pre_i|, \sum |suf_i|,\sum |S| \le 8\times 10^6$。

### Output

每行输出一个整数，表示该字符串的能量。

### Sample Input

```plain
2
3 3
ab
aab
aaab
ba
bb
aba
ababababbbbabbbab
3 3
aab
eab
aiaihao
aabeab
iaia
ai
aabeabaiaihaoaibfohagaabeabaiaihao
```

### Sample Output

```plain
37
22
```

