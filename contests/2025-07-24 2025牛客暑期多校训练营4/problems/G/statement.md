## G. Ghost in the Parentheses

### 题目描述

Alice has a valid parentheses sequence $s$ and she wants to share it with Bob
through a noisy channel. For each character, the channel independently
transmits that character to Bob with a probability of $1/2$, or transmits an indistinguishable
character \`?\' to Bob with a probability of $1/2$. For example, if Alice\'s valid
parentheses sequence is $s$ = (()()), Bob
might receive the character sequences (?)()), ?(??)?, but cannot receive
the character sequence ??(()). After receiving the message, Bob tries to
reconstruct the valid parentheses sequence that Alice transmitted.
However, Alice knows that in some cases, the reconstruction is not
unique: for instance, when receiving the character sequence ?(??)?,
there are two possible reconstructions: (()()) and ((())).

<div>

Please help Alice calculate the probability that the message Bob
received can uniquely reconstruct the valid parentheses sequence. Output
the answer modulo $998\,244\,353$.

<div>

<div>

Parentheses sequence $s$ is valid if either
of the following holds true:

<div>
- $s$ is empty;
- $s = \texttt{`('} + t + \texttt{`)'}$,
    where $t$ is a valid parentheses
    sequence;
- $s = t_1 + t_2$, where $t_1$ and $t_2$ are valid parentheses sequences.

</div>

</div>

</div>

</div>

### 输入描述

The input consists of a single line containing a valid parentheses
sequence$s$ ($2 \le |s| \le 10^6$).

### 输出描述

Output a single integer indicating the probability that the message Bob
received can uniquely reconstruct the valid parentheses sequence, modulo $998\,244\,353$.

### 示例1

#### 输入

```plain
()()
```

#### 输出

```plain
249561089
```

#### 说明

For the first example, the message Bob received can uniquely reconstruct
the valid parentheses sequence if and only if the second character and
the third character are not both lost. The probability of this event
occurring is $\frac{3}{4} \equiv 249\,561\,089 \mod 998\,244\,353$.

### 示例2

#### 输入

```plain
((()(()())))
```

#### 输出

```plain
936828929
```

### 示例3

#### 输入

```plain
()(()(()))
```

#### 输出

```plain
826671105
```
