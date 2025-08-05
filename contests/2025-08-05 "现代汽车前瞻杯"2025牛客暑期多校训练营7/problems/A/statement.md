## A. Loopy Laggon

### 题目描述

Alice has a collection of special gem maze toys. This collection
consists of $\textstyle m$ independent sets.
Each set contains $\textstyle k$ toys, and
each toy is an$\textstyle n \times n$ two-dimensional grid. Initially, each toy is arranged in the following
order:

[[$\displaystyle \begin{pmatrix}
1 & 2 & \dots & n \n+1 & n+2 & \dots & 2n \\vdots & \vdots & \ddots & \vdots \(n-1)n+1 & (n-1)n+2 & \dots & n^2
\end{pmatrix}$]]

Alice performed $\textstyle 10^6$ operations
on these toys: uniformly at random selecting a $\textstyle 4 \times 4$ sub-block of a toy
and rotating it $\textstyle 90$ degrees
clockwise. For example,

[[$\displaystyle \begin{pmatrix}
1 & 2 & 3 & 4 \5 & 6 & 7 & 8 \9 & 10 & 11 & 12 \13 & 14 & 15 & 16
\end{pmatrix}
\to
\begin{pmatrix}
13 & 9 & 5 & 1 \14 & 10 & 6 & 2 \15 & 11 & 7 & 3 \16 & 12 & 8 & 4
\end{pmatrix}$]]

Bob accidentally damaged all$\textstyle k$ toys in $\textstyle \frac{m}{2}$ sets of
Alice's toys. Since Bob could not remember the exact configuration
before the damage, he remade the toys as follows: for each $\textstyle i$ from $\textstyle 1$ to $\textstyle n^2$, he randomly placed $\textstyle i$ into an unfilled cell with
equal probability.

Alice eventually discovered these tampered toys and was very angry,
wanting to know which sets of toys were remade by Bob. Help her
determine whether each set of toys was remade by Bob. Note that you do
not need to provide a correct judgment for every set of toys.

### 输入描述

The first line contains four integers $\textstyle id, m, k, n$. Here,$\textstyle id$ ($\textstyle 0\le id<10$) represents the test
number, $\textstyle m=100$ represents the
number of toy sets in this collection, $\textstyle k=10$ represents the number of
toys in each toy set, and$\textstyle n=10$ represents the side length of a toy.

The following lines describe$\textstyle m$ toy sets. For each toy set,$\textstyle k$ toys are described. Each toy consists of $\textstyle n$ rows, with each row containing $\textstyle n$ integers. These integers
represent the final arrangement of numbers in that toy.

The example might not conform to the given constraints and contains
extra blank lines, but the example itself is not part of the test.

### 输出描述

Output a single string of length $\textstyle m$ consisting of $\textstyle \texttt{01}$s. Output $\textstyle \texttt{1}$ if the corresponding
toy set was damaged by Bob, and $\textstyle \texttt{0}$ otherwise.

Please note that you are not required to provide a perfectly correct
judgment for every single toy set. In each test, if at least $\textstyle 90$ of your answers are correct,
your solution will be considered correct. You do not need to guarantee
the number of $\textstyle \texttt{0}$ and $\textstyle \texttt{1}$ equals.

### 示例1

#### 输入

```plain
-1 2 1 4

1 2 3 4
5 6 7 8
9 10 11 12
13 16 14 15

13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4
```

#### 输出

```plain
10
```

#### 说明

In the sample, there are two toy sets, each containing one $\textstyle 4\times 4$ toy:

The first toy set must have been damaged by Bob, as this outcome cannot
be achieved through rotation alone. Therefore, the second toy set is not
damaged.

