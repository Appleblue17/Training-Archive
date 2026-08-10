## D. Lost Woods

### 题目描述

Given a directed graph with$\textstyle n$ vertices and $\textstyle m$ edges, find the
infimum of variance for all walks from $\textstyle 1$ to $\textstyle n$.

A walk from $\textstyle 1$ to $\textstyle n$ is defined as a sequence of
edges $\textstyle \{e_1, e_2, \dots, e_l\}$,
where the starting vertex of$\textstyle e_1$ is $\textstyle 1$, the ending vertex of $\textstyle e_l$ is $\textstyle n$, and the ending vertex of $\textstyle e_i$ is the same as the starting
vertex of $\textstyle e_{i+1}$. Note that $\textstyle e_1,e_2,\dots,e_l$ is not
necessarily distinct. The variance of a walk $\textstyle p = \{e_1,e_2, \dots, e_l\}$ is$\displaystyle D(p) = \frac{1}{l} \sum\limits_{i=1}^l (w_{e_i} - \overline w)^2$ 
where $\textstyle w_{e_i}$ is the weight of
edge $\textstyle e_i$, and$\textstyle \overline w = \frac{1}{l} \sum\limits_{i=1}^l w_{e_i}$ is the average weight of $\textstyle e_1,e_2,\dots, e_l$.

The definition of infimum here is given in output format.

### 输入描述

The first line contains two integers$\textstyle n$ ($\textstyle 2 \leq n \leq 30$) and$\textstyle m$ ($\textstyle 1 \leq m \leq 200$).

For the following $\textstyle m$ lines, the $\textstyle i$-th line contains three
integers$\textstyle x_i, y_i, w_i$ ($\textstyle 1\le x_i,y_i \le n$, $\textstyle x_i \neq y_i$, $\textstyle 0 \leq w_i \leq 20$) indicating
an edge from $\textstyle x_i$ to $\textstyle y_i$ with weight $\textstyle w_i$.

### 输出描述

Output one line containing one real number, indicating the infimum
variance for all walks from $\textstyle 1$ to $\textstyle n$. If there is no walk from $\textstyle 1$ to $\textstyle n$, output "-1"(without quotes).

Your answer will be considered correct if its absolute or relative error
does not exceed $\textstyle 10^{-9}$.
Formally, suppose that your answer is $\textstyle b$ and let $\textstyle \epsilon=\max\{1,b\} \cdot 10^{-9}$,
your answer is considered correct if:
- For any walk $\textstyle p$ from $\textstyle 1$ to $\textstyle n$, $\textstyle D(p) > b - \epsilon$;
- There exists at least one walk $\textstyle p_0$ from $\textstyle 1$ to $\textstyle n$ such that $\textstyle D(p_0) < b + \epsilon$.

### 示例1

#### 输入

```plain
4 4
1 2 3
1 3 4
2 4 5
3 4 7
```

#### 输出

```plain
1.000000000000000
```

