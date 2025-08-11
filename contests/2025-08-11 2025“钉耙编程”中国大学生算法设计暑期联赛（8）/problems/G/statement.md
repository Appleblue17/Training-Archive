## G. 最绝望的 hidesuwa

### Problem Description

banana Ilya 龙哥请求支援 hide \~ 大虾发出绝望的最后一声

声一后最的望绝出发虾大 \~ edih 援支求请哥龙 aylI ananab

小 E 正在美美 hide，却突然发现自己掉入了回文时空，hide
之神要求他解决一个问题才能回到原本的生活。

具体来说，hide 之神的目标是：
- 一个长度为 $n$ 的字符串 $s$。
- 字符串由 $26$ 个小写字母 $a\sim z$ 组成。
- 有 $m$ 条限制，每条限制形如 $[l_i, r_i]$，表示 $s[l_i..r_i]$ 这个子串被要求是回文串。

你要求出满足要求的字符串个数，对$998244353$ 取模的结果。

同时，hide 之神还非常关注 top20，你还要输出满足要求的，字典序最小的前 $20$ 个字符串。（数据保证至少有 $20$ 个不同的字符串满足要求）

### Input

**本题有多组测试数据**。第一行一个正整数 $T$，表示数据组数，接下来输入每组测试数据。

对于每组测试数据：
- 第一行两个正整数 $n,m$，表示目标字符串长度，以及限制个数。
- 接下来 $m$ 行，每行两个正整数 $[l_i, r_i]$ 表示一个限制。

### Output

对于每组数据：
- 第一行输出一个非负整数，表示满足要求的字符串个数，对 $998244353$ 取模的结果。
- 接下来 $20$ 行，每行一个长度为 $n$ 的由$26$     个小写字母构成的字符串，表示 top20。

### Sample Input

```plain
1
5 1
1 5
```

### Sample Output

```plain
17576
aaaaa
aabaa
aacaa
aadaa
aaeaa
aafaa
aagaa
aahaa
aaiaa
aajaa
aakaa
aalaa
aamaa
aanaa
aaoaa
aapaa
aaqaa
aaraa
aasaa
aataa
```

### Hint

对于所有数据，$1\leq T\leq 10, 1\leq n, m\leq 10^5$，$1\leq l_i\leq r_i\leq n$。

