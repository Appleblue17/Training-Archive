## M. Miscalculated Triangles

### 题目描述

In his homework, Sean ran into this problem:

\-\-- How many different shapes of triangles are there in a 2D-plane,
with lengths of its sides in $\{1,2,\dots,s\}$ and perimeter no longer
than $l$ ? Two triangles are considered to be
in the same shape if they can completely overlap using only translation
and rotation. Note that **flips are not allowed**. So for $\Delta ABC$ and $\Delta A'B'C'$ ($A,B,C$[ and ]{style="text-wrap-mode:wrap;"}$A',B',C'$[ are
listed anti-clockwise.]{style="text-wrap-mode:wrap;"}), if $AB=2,BC=3,CA=4$ and $A'B'=2,A'C'=4,C'A'=3$, they are **not**
considered to be in the same shape.

<div>

Sean likes to consider problems in the binary system, so he uses the
binary representation of numbers. He iterated over all possible $(a,b,c)$ trying to find the answer, so what
he wanted is the number of triplets$(a,b,c)$ such that:

<div>

- $1\leq a,b,c\leq s$ and are all integers.
- $a+b\gt c, a+c\gt b, b+c\gt a$ -$a+b+c\leq l$

Then, he chose from these triplets such that each triplet chosen
represents a different triangle. However, Sean was so bad at math that
when he calculated $a+b+c$ , he totally
forgot about the carries, and therefore got the result of $a⊕b⊕c$, which is **the bitwise exclusive OR
(XOR)** **sum** of $a,b$ and $c$ .

Despite this mistake, Sean wants to know if he makes other mistakes, so
he asks you about the answer if the third condition is $a⊕b⊕c\leq l$ rather than $a+b+c\leq l$. Can you help him out with
this?

Since the answer can be enormous, output it modulo $998\ 244\ 353$ .

</div>

</div>

### 输入描述

Each test contains multiple test cases. The first line contains the
number of test cases $T\ (1≤T≤10^4)$ .

Each test case consists of a single line. The line contains $2$ strings $s_l, s_s\ (|s_l|\leq 10^5,|s_s|\leq 10^5)$ ,
the binary representation of the integers$l$ and $s$ . It is guaranteed that $l\gt 0$ and $s\gt 0$, and the first character of string $s_s$ and $s_l$ is
always $1$ .

It is guaranteed that $\sum|s_l|$ over all
test cases in one test will not exceed $5\times 10^5$ and $\sum|s_s|$ over all test cases in one test
will not exceed $5\times 10^5$.

### 输出描述

For each test case, output $1$ integer: the
number of triangles in different shapes modulo $998\ 244\ 353$ .

### 示例1

#### 输入

```plain
2
101 1111
1111 101
```

#### 输出

```plain
267
25
```
