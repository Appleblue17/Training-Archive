## B. Inversion Number Parity

### 题目描述

**Attention: unusual memory limit for this problem**An inversion in a sequence is a pair of elements that are out of their
natural order, and the inversion number of a permutation $P = [p_0, p_1, \ldots, p_{n - 1}]$ of $0$ to$(n - 1)$ is the number of pairs $(p_i, p_j)$ such that $i  p_j$.Given a permutation $P = [p_0, p_1, \ldots, p_{n - 1}]$ and $(n - 1)$ modifications $[(l_1, r_1, d_1), (l_2, r_2, d_2), \ldots, (l_{n - 1}, r_{n - 1}, d_{n - 1})]$,
your task is to find out the parity of the inversion number of $P$ before and after each modification.More specifically, the permutation $P$ will
have $n$ versions, where the first version is
given as above, and for $i = 1, 2, \ldots, n - 1$, the $(i + 1)$-th version is based on the $i$-th version after shifting the interval
between indices $l_i$ and $r_i$ of the permutation circularly left $d_i$ times (check the note for more
details), and the parity of the inversion number
of $P$ is required for each version.Additionally, since the given $n$ is a bit
large, we will generate the permutation$P$ and modifications by the following random generator from the given $n$, $A$, $B$ and$C$ instead.The random generated sequence $[f_0, f_1, \ldots]$ is defined as:
- $\land$ means bitwise-AND, $\oplus$ means bitwise-XOR, and $\lfloor x \rfloor$ means rounding $x$ down to the nearest integer;
- let $U = 2^{30} - 1$, and the
    undermentioned $f_x$, $g_x$,$h_x$     are all integers between $0$ and $U$, inclusive;
- let $f_{-3} = A \land U$, $f_{-2} = B \land U$ and $f_{-1} = C \land U$;
- for $i = 0, 1, \ldots$, let $g_i = f_{i - 3} \oplus ((2^{16} f_{i - 3}) \land U)$;
- for $i = 0, 1, \ldots$, let $h_i = g_i \oplus \left \lfloor \frac{g_i}{2^5} \right \rfloor$;
- for $i = 0, 1, \ldots$, let $f_i = h_i \oplus ((2 h_i) \land U) \oplus f_{i - 2} \oplus f_{i - 1}$.

With the above generator,
- $x \bmod y$     ($y > 0$) means the remainder of $x$ divided by $y$;
- the first version of permutation $P$ is
    derived from$[0, 1, \ldots, n - 1]$     after swapping $p_i$ and $p_{i + (f_i \bmod (n - i))}$ for $i = 0, 1, \ldots, n - 1$ sequentially;
- for $i = 1, \ldots, n - 1$, let $l_i = \min(f_{n + 3 i - 3} \bmod n, f_{n + 3 i - 2} \bmod n)$, $r_i = \max(f_{n + 3 i - 3} \bmod n, f_{n + 3 i - 2} \bmod n)$, $d_i = (f_{n + 3 i - 1} \bmod n) + 1$.

### 输入描述

The first line contains an integer$T$ ($1 \leq T \leq 10^5$), indicating the number
of test cases.Then follow $T$ test cases. For each test
case:The only line contains four integers $n$, $A$, $B$ and$C$ ($1 \leq n \leq 10^7, 0 \leq A, B, C \leq 10^9$).It is guaranteed that the sum of $n$ over $T$ test cases does not exceed $10^7$.

### 输出描述

For each test case, output a string of length $n$ in one line, where the $i$-th character of the string is $0$ if the parity of the inversion number of
the $i$-th version of $P$ is even, or $1$ otherwise (i.e. the parity is odd).

### 示例1

#### 输入

```plain
5
3 0 0 0
3 0 0 1
3 0 1 0
3 6 7 8
10 123 456 789
```

#### 输出

```plain
000
111
111
110
1111101111
```

#### 说明

The generated
sequences $[f_0, f_1, \ldots]$ for the first
two test cases in the example are:

· $[0, 0, 0, 0, 0, 0, 0, 0, 0, \ldots]$;· $[1, 0, 202754, 1, 202755, 692070724, 692070724, 692070725, 792595, \ldots]$.The generated permutations and modifications for all test cases in the
example are:· $P = [0, 1, 2]$, $\mathrm{modifications} = [(0, 0, 1), (0, 0, 1)]$;· $P = [1, 0, 2]$, $\mathrm{modifications} = [(0, 1, 2), (1, 2, 2)]$;· $P = [1, 0, 2]$, $\mathrm{modifications} = [(0, 2, 1), (0, 1, 2)]$;· $P = [2, 1, 0]$, $\mathrm{modifications} = [(1, 1, 3), (1, 2, 3)]$;· $P = [3, 1, 2, 8, 5, 0, 4, 7, 6, 9]$, $\mathrm{modifications} = [(1, 8, 2), (0, 6, 10), (3, 5, 10), (2, 4, 2), (7, 8, 9), (1, 2, 7),$ $(0, 9, 2), (8, 9, 2), (5, 7, 5)]$.For the last test case,· the second version
of $P$ is $[3, 8, 5, 0, 4, 7, 6, 1, 2, 9]$,
resulting from circularly shifting the interval of
indices $[1, 8]$ left twice
(i.e. $[\ldots, 1, 2, 8, 5, 0, 4, 7, 6, \ldots]$ $\to$ $[\ldots, 2, 8, 5, 0, 4, 7, 6, 1, \ldots]$ $\to$ $[\ldots, 8, 5, 0, 4, 7, 6, 1, 2, \ldots]$);· the third version
of $P$ is $[0, 4, 7, 6, 3, 8, 5, 1, 2, 9]$,
resulting from circularly shifting the interval of
indices $[0, 6]$ left $10$ times
(i.e. $[3, 8, 5, 0, 4, 7, 6, \ldots]$ $\to$ $[8, 5, 0, 4, 7, 6, 3, \ldots]$ $\to$ $\cdots$ $\to$ $[0, 4, 7, 6, 3, 8, 5, \ldots]$);· the inversion numbers of all versions
are $13$, $21$, $19$, $19$, $21$, $22$, $23$, $25$, $25$ and $27$ respectively.

