## K. Kindred Sums

### 题目描述

Given $N=1000$ positive integers $a_1,a_2,\ldots,a_N$ and $M = 10^{18}$, please find two distinct and
non-overlapping subsets $S,T \subseteq \{1,2,\ldots,N\}$ such that $\sum_{i \in S} a_i - \sum_{i \in T} a_i$ is
a multiple of $M$.

It can be proven that under the given conditions, there exists at least
one valid solution.

### 输入描述

The input consists of a single line containing $N = 1000$ non-negative integers$a_1,a_2,\ldots,a_N$ ($1 \le a_i \le 10^{18}$).

### 输出描述

The output consists of a single line containing a string of length $N = 1000$ that only includes $0$, $1$, and $2$. Where
\ $\bullet$ The $i$-th position being $0$ indicates that the element is neither in $S$ nor in $T$;\ $\bullet$ The $i$-th position being $1$ indicates that the element is in $S$;\ $\bullet$ The $i$-th position being $2$ indicates that the element is in $T$.

If there are multiple valid solutions, output any one of them.

### 示例1

#### 输入

```plain
0
```

#### 输出

```plain
0
```

#### 说明

This is a placeholder, and it will NOT be regarded as a test case!
