## D. Kiritorisen

### 题目描述

Mygo!!!!!, a famous girl band, is going to host a live performance
tomorrow! However, they haven't decided their costumes yet, so tonight
they will make their costumes out of a piece of fabric. A piece of
fabric can be divided into$\textstyle n$ parts with equal length, and the color of the $\textstyle i$-th part is $\textstyle a_i$. To simplify input, the
fabric will be described as a string consisting only of lowercase
letters from `a` to `z`, where each letter denotes a specific color.

First, they will use several continuous parts of the fabric to make a
costume, which means they will choose $\textstyle l$ and $\textstyle r$, where $\textstyle 1 \le l \le r \le n$, and this
will make a costume of length $\textstyle r - l + 1$, and the color of the $\textstyle i$-th part of the costume, $\textstyle c_i$, will be $\textstyle a_{l + i - 1}$.

In order to make the live even more exciting, they believe that the
costume must be beautiful. A beautiful costume $\textstyle c$ with length $\textstyle k$ is a costume that satisfies $\textstyle c_i = c_{k - i + 1}$ for all $\textstyle 1 \le i \le k$, and it shows the
beauty of symmetry.

Now, they choose a beautiful costume with length **greater than** $\textstyle 1$, and they all go to sleep,
except Rana. Rana was very naughty, so she cut Soyorin's costume into
two non-empty costumes, which means for a costume $\textstyle c$ of length $\textstyle k$, she will choose $\textstyle d$ where $\textstyle 1 \le d < k$, and divide the
original costume into $\textstyle c[1,d]$ and $\textstyle c[d+1,k]$, then she goes to sleep
just like everyone else.

The next morning, Soyorin wakes up and finds her costume cut into two,
but there is no time for her to make a new costume, so she has to wear
both pieces. However, if both of the two costumes are beautiful, she can
just pretend as if nothing happened. Please help Soyorin calculate how
many cases exist in which the two costumes are both beautiful. Two cases
are considered different if at least one of $\textstyle l$, $\textstyle r$, or $\textstyle d$ is different.

![image](https://uploadfiles.nowcoder.com/images/20250724/0_1753350457982/EC97A87A5B14296FC9B0F3A7F968B8DC){style="width:16cm;"}Soyorin and the cut costumes

### 输入描述

The first line of input contains a single integer $\textstyle n$ $\textstyle (1 \le n \le 3 \cdot 10^6)$ ---
the length of the fabric.

The second line contains a string of length $\textstyle n$, consisting only of lowercase
letters fromatoz, where the $\textstyle i$-th
letter denotes $\textstyle a_i$, the color of
the $\textstyle i$-th part of the fabric.

### 输出描述

Output a single integer, the number of cases in which the two costumes
are both beautiful.

### 示例1

#### 输入

```plain
4
aaab
```

#### 输出

```plain
4
```

### 示例2

#### 输入

```plain
20
abababbabbbbbaaaaaba
```

#### 输出

```plain
42
```

### 备注

For sample one, in the first step there are three possible ways to
choose a beautiful costume: **aa** , **aa** and **aaa** , corresponding
to $\textstyle l = 1, r = 2$, $\textstyle l = 2, r = 3$ and $\textstyle l = 1, r = 3$. Note that **b** ,
corresponding to $\textstyle l = 4, r = 4$,
is not chosen because the costume length must be greater than $\textstyle 1$.

Now, consider Rana's choice of $\textstyle d$.
- For **aa** , there is only one possible $\textstyle d$, namely $\textstyle d = 1$, which splits it into
    **a** and **a** , both of which are beautiful.
- For **aaa** , when $\textstyle d = 1$, it
    splits into **a** and **aa** , both beautiful; when $\textstyle d = 2$, it splits into **aa**
    and **a** , both beautiful.

Therefore, there are$\textstyle 2 \times 1 + 1 \times 2 = 4$ cases in total.

