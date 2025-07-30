## B. Extra Training

### 题目描述

<div>

Pigeon aspires to become a string master. Every day he trains extra-hard
on string problems.

<div>

\

<div>

Today he is solving a problem that goes like this:

<div>

\

<div>

Given a string $\textstyle S$ of length $\textstyle n$. You need to perform the
following operation exactly$\textstyle k$ times:

<div>

\

For the i-th operation $\textstyle (1 \leq i \leq k)$，Choose a
substring of $\textstyle S$ as $\textstyle S_i$.$\textstyle S[l_i,r_i]$ is substring of $\textstyle S$. (i.e., the
contiguous substring of$\textstyle S$ starting at position $\textstyle l_i$ and
ending at position $\textstyle r_i$ , where $\textstyle 1 \leq l_i \leq r_i \leq n$). In
additonal, the empty string is also a substring of $\textstyle S$.

<div>

\

Concatenate the chosen substrings $\textstyle S_i(1\leq i \leq k)$ in order to
form a new string $\textstyle S_1+S_2+...+S_k$.

<div>

\

Let $\textstyle X$ be the number of distinct
strings that can be formed by
concatenating $\textstyle k$ substrings in
this way. Output $\textstyle X$ mod
998244353.

</div>

</div>

</div>

</div>

</div>

</div>

</div>

</div>

### 输入描述

<div>

The first line contains two
integers $\textstyle n$ and $\textstyle k$ ($\textstyle 1\leq n \leq 5 \times 10^5, 1\leq k \leq 10^9$).

</div>

<div>

\

</div>

The second line contains a
string $\textstyle S$ of
length $\textstyle n$, only consisting of
both uppercase and lowercase English letters.

<div>

\

</div>

<div>

Note that uppercase and lowercase letters are treated as distinct.

</div>

### 输出描述

Output a single integer, the number of distinct strings that can be
formed by concatenating$\textstyle k$ substrings (selected in order from the 1st to the k-th operation) modulo
998244353.

### 示例1

#### 输入

```plain
2 2
ab
```

#### 输出

```plain
12
```

#### 说明

For the first sample, the substrings of \"ab\" are: \"\" (empty string),
\"a\", \"b\", and \"ab\".

\(1\) \"\" + \"\" = \"\"

\(2\) \"\" + \"a\" = \"a\"

\(3\) \"\" + \"b\" = \"b\"

\(4\) \"\" + \"ab\" = \"ab\"

\(5\) \"a\" + \"\" = \"a\"

\(6\) \"a\" + \"a\" = \"aa\"

\(7\) \"a\" + \"b\" = \"ab\"

\(8\) \"a\" + \"ab\" = \"aab\"

\(9\) \"b\" + \"\" = \"b\"

\(10\) \"b\" + \"a\" = \"ba\"

\(11\) \"b\" + \"b\" = \"bb\"

\(12\) \"b\" + \"bab\" = \"bab\"

\(13\) \"ab\" + \"\" = \"ab\"

\(14\) \"ab\" + \"a\" = \"aba\"

\(15\) \"ab\" + \"b\" = \"abb\"

\(16\) \"ab\" + \"ab\" = \"abab\"

Among the sixteen strings above, only twelve are
distinct：\"\",\"a\",\"b\",\"ab\",\"aa\",\"aab\",\"ba\",\"bb\",\"bab\",\"aba\",\"abb\",\"abab\"

### 示例2

#### 输入

```plain
3 3
abb
```

#### 输出

```plain
96
```

### 示例3

#### 输入

```plain
2 10
Aa
```

#### 输出

```plain
28656
```

### 示例4

#### 输入

```plain
9 6
IcePigeon
```

#### 输出

```plain
811212467
```

### 备注

\

