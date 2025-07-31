## K. K-th Memorable Sub-string

### 题目描述

A string is a sequence of characters and a 01-string is a string
composed of only $0$-s and $1$-s.

When reading a few 01-strings, Sean found some of them are pretty
memorable: There is a prefix and a suffix that are the same with no
overlapping. Also, they are separated by no more than $k$ characters.

Then, he came across a long string $s$. He
wants to dive deeper into this string and know about all the memorable
sub-strings of $s$. A sub-string is a
contiguous sequence of characters within a string.

He also wants you to do so, which is so inconsiderate. To make sure you
really did this, he will ask queries like this:

- What is the $q_i$-th
  lexicographically-smallest sub-string of $s$ that is memorable?

<div>

A word $s_1$ is lexicographically smaller
than $s_2$ if and only if one of the
following things happens:

<div>

- $s_1$[ ]{style="text-wrap-mode:wrap;"}is
  a prefix of $s_2$ .

<!-- -->

- There exists a $j$ such that $\forall 1\leq i\lt j, s_1[i]=s_2[i]$ and $s_1[j]\lt s_2[j]$.

Also, if $s='011101'$, the sub-strings $s[1...2]$ and $s[5...6]$ are considered different, as
different indexes are chosen from the original string.

Also, Sean wants to make sure you listen to the words he says, so
questions are slightly adjusted based on the answer to the last
question. Check the input description for further information.

</div>

</div>

### 输入描述

The first line contains two integers $n,k\ (2\leq n\leq 10^4, 0\leq k\leq n-2)$,
the length of the given string $s$ and the
parameter for the memorable sub-string.

The second line contains the string $s$,
which is composed of only $0$-s and $1$-s.

The third line contains an integer $q\ (1\leq q\leq 5\times 10^5)$, the number
of questions Sean asks.

Each of the lines from the $4$-th to the $(q+3)$-th contains an integer $v_i\ (1\leq v_i\leq 10^9)$, which represents
the question that you need to answer.

Let $total$ be the total number of different
memorable sub-strings in $s$, and let $ans_i$ be the answer to the $i$-th query
($1\leq i\leq q$). The answer $ans_i$ is a 01-string, and it is the binary
representation (ignore unnecessary leading zeros) of an integer $x_i$. Let $x_0=0$, so in the $i$-th query, $q_i=\left((x_{i-1}\bmod 998\ 244\ 353+v_i-1)\bmod total+1\right)$,
you need to find out the $q_i$-th
lexicographically-smallest memorable substring.

### 输出描述

For each query, output a string as the answer, the $q_i$-th lexicographically-smallest memorable
substring.

It is guaranteed that the total lengths of the output strings will not
exceed $10^7$ .

### 示例1

#### 输入

```plain
6 1
110111
2
5
6
```

#### 输出

```plain
11011
11
```

#### 说明

The memorable sub-strings of the original strings are$s[2...4]='101',s[1...2]='11',s[4...5]='11',s[5...6]='11',s[1...5]='11011',s[4...6]='111'$ (in lexicographical order). So, $total=6$.

The first query asks about the $5$-th
element, so the result is $'11011'$.
\ $11011$ is the binary representation of $27$, so the second query asks about the $(27\bmod998\ 244\ 353+6-1)\bmod 6+1=3$-rd
element, so the result is $'11'$.
