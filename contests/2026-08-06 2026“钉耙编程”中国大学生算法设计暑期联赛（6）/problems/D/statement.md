## D. Three Colors

### Problem Description

小 C 在便利店购物，店内共有三种类型的物品，分别记为 $\texttt{A},\texttt{B},\texttt{C}$。商店中的商品按顺序摆放，形成一个长度为 $n$ 的字符串 $s$，其中$s_i\in{\texttt{A},\texttt{B},\texttt{C}}$ 表示第 $i$ 件商品的类型。

小 C 想从指定的一段商品中挑选一段 **连续** 的商品送给小 X。

现在有 $q$ 次询问，每次给出一个区间 $[l,r]$。你需要在区间 $[l,r]$ 内选择一个连续子区间 $[l',r']$（满足 $l\le l'\le r'\le r$）。

设该子区间内三种商品出现次数分别为 $\mathrm{cnt}_\texttt{A},\mathrm{cnt}_\texttt{B},\mathrm{cnt}_\texttt{C}$，其中未出现的商品类型出现次数视为 $0$。要求三种商品的出现次数两两不同，即$\mathrm{cnt}_\texttt{A}\neq \mathrm{cnt}_\texttt{B}$ 且$\mathrm{cnt}_\texttt{A}\neq \mathrm{cnt}_\texttt{C}$ 且 $\mathrm{cnt}_\texttt{B}\neq \mathrm{cnt}_\texttt{C}$。

对于每次询问，输出一个满足条件且长度最大的子区间 $[l',r']$。若存在多个长度最大的答案，输出任意一个即可；若不存在满足条件的子区间，则输出
`0 0`。

### Input

**本题强制在线。**

第一行包含一个整数 $n\ (1\leq n\leq 2\times 10^6)$，表示商品的数量。

第二行包含一个长度为 $n$ 的字符串 $s$，保证仅由大写字母 $\texttt{A},\texttt{B},\texttt{C}$ 组成。

第三行包含一个整数 $q\ (1\leq q\leq 10^6)$，表示询问的次数。

接下来 $q$ 行，每行包含两个整数 $x', y'\ (0\leq x', y'\leq 10^9)$。你需要通过以下规则解密得到真实的查询区间 $[l, r]$：

设 $x$ 和$y$ 为解密后的临时端点，则：
- $x = ((x' \oplus \text{last\_ans}) - 1) \bmod n + 1$，
- $y = ((y' \oplus \text{last\_ans}) - 1) \bmod n + 1$。

其中 $\oplus$ 表示按位异或操作。此处约定 $\lparen -1 \rparen \bmod n = n - 1$。

最终真实的查询区间端点为 $l = \min\lparen x, y \rparen$，$r = \max(x, y)$。

变量 $\text{last\_ans}$ 初始值为 $0$。在每次询问后，$\text{last\_ans}$ 将被更新为**本次输出的满足条件的最大子区间长度**，即 $\text{last\_ans} = r' - l' + 1$。若不存在满足条件的子区间（即输出为
`0 0`），则视长度为 $0$，即 $\text{last\_ans} = 0$。

保证解密后的真实区间满足 $1 \leq l \leq r \leq n$。

### Output

输出共 $q$ 行。

对于每次询问，输出两个用空格分隔的整数$l'$ 和 $r'$，表示你选择的满足条件且长度最大的连续子区间的左右端点。若有多个长度相同的合法答案，输出任意一个；若无解，请输出
`0 0`。

### Sample Input

```plain
8
BCAABCCC
4
1 8
6 2
7 4
2 0
```

### Sample Output

```plain
2 8
2 4
5 7
0 0
```

### Hint

初始 $\text{last\_ans}=0$。

**第一次询问**：$L=1,R=8$ 异或后得 $[1,8]$，子串 $\texttt{BCAABCCC}$。最长合法区间为 $[2,8]$，其中 $\mathrm{cnt} _{\texttt A}=2$，$\mathrm{cnt} _{\texttt B}=1$，$\mathrm{cnt} _{\texttt C}=4$，输出
`2 8`，$\text{last\_ans}=7$。

**第二次询问**：$L=6,R=2$ 异或后得 $[1,5]$，子串 $\texttt{BCAAB}$。最长合法区间长度为 3，可取 $[2,4]$（或 $[3,5]$），其中 $\mathrm{cnt} _{\texttt A}=2$，$\mathrm{cnt} _{\texttt B}=0$，$\mathrm{cnt} _{\texttt C}=1$，输出
`2 4`，$\text{last\_ans}=3$。

**第三次询问**：$L=7,R=4$ 异或后得 $[4,7]$，子串 $\texttt{ABCC}$。最长合法区间为 $[5,7]$，其中 $\mathrm{cnt} _{\texttt A}=0$，$\mathrm{cnt} _{\texttt B}=1$，$\mathrm{cnt} _{\texttt C}=2$，输出
`5 7`，$\text{last\_ans}=3$。

**第四次询问**：$L=2,R=0$ 异或后得 $[1,3]$，子串 $\texttt{BCA}$。不存在满足 $\mathrm{cnt} _{\texttt A}$，$\mathrm{cnt} _{\texttt B}$，$\mathrm{cnt} _{\texttt C}$ 两两不同的子区间，输出
`0 0`，$\text{last\_ans}=0$。

真实区间依次为 $[1,8],[1,5],[4,7],[1,3]$。

