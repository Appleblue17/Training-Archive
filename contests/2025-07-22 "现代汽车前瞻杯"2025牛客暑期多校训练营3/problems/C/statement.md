## C. Capella

### 题目描述

A string $S$ consisting only of lowercase
English letters is called **Capella-like** if and only if it satisfies
all of the following conditions:\
- The number of letters that appear an odd number of times
    in $S$ is odd;
- The number of letters that appear a non-zero even number of times
    in $S$ is even.

It can be shown that the string
\"$\texttt{capella}$\" is Capella-like.
However, the string \"$\texttt{arcaea}$\" is
not Capella-like since there are $4$ letters
that appear an odd number of times, and
\"$\texttt{lowiro}$\" is not Capella-like
either since there is $1$ letter that appears
a non-zero even number of times and$4$ letters that appear an odd number of times.\
\

<div>

Now Yuki has a string $S$ of length $n$ consisting only of lowercase English
letters. Yuki performs $q$ operations on the
string $S$: the $i$-th operation gives a position$p_i$ ($1 \leq p_i \leq n$) and a lowercase letter $c_i$, modifying the character at the $p_i$-th position of $S$, denoted as $S_{p_i}$, to $c_i$. You need to find the length of the
longest substring of $S$ that is Capella-like
before all the $q$ operations and after each
operation.

<div>

\

<div>

Recall that a string $S'$ is a substring of $S$ if and only if $S'$ can be obtained by removing a possibly
empty prefix and suffix from $S$.

</div>

</div>

</div>

### 输入描述

The first line contains two integers $n$ and$q$ ($1 \leq n \leq 2 \cdot 10^5$, $1 \leq q \leq 2 \cdot 10^5$).\
\
The second line contains a string $S$ of
length $n$ consisting only of lowercase
English letters.\
\
Each of the next $q$ lines contains an
integer$p_i$ ($1 \leq p_i \leq n$) and a lowercase English
letter $c_i$, representing an operation.\

### 输出描述

Output $q + 1$ lines. Each line contains an
integer representing the length of the longest substring of $S$ that is Capella-like before all $q$ operations and after each operation.

### 示例1

#### 输入

```plain
6 4
ababab
3 c
6 a
4 c
2 a
```

#### 输出

```plain
1
5
5
5
1
```

### 备注

For the $q$ operations in the sample:\

<div>

\

</div>

<div>
- Before any operations, the initial value of string $S$ is
    \"$\texttt{ababab}$\", and the longest
    Capella-like substring is
    \"$\texttt{a}$\" or
    \"$\texttt{b}$\", with a length of $1$.
- After the first operation, the string$S$     becomes \"$\texttt{abcbab}$\", and the
    longest Capella-like substring is
    \"$\texttt{abcba}$\" or
    \"$\texttt{bcbab}$\", with a length of $5$.
- After the second operation, the string $S$ becomes
    \"$\texttt{abcbaa}$\", and the longest
    Capella-like substring is
    \"$\texttt{abcba}$\" or
    \"$\texttt{bcbaa}$\", with a length of $5$.
- After the third operation, the string$S$     becomes \"$\texttt{abccaa}$\", and the
    longest Capella-like substring is
    \"$\texttt{abcca}$\" or
    \"$\texttt{bccaa}$\", with a length of $5$.
- After the fourth operation, the string $S$ becomes
    \"$\texttt{aaccaa}$\", and the longest
    Capella-like substring is
    \"$\texttt{a}$\" or
    \"$\texttt{c}$\", with a length of $1$.

</div>

