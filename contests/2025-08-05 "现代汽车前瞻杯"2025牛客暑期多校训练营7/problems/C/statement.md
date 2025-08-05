## C. Forsaken City

### 题目描述

You're given an integer sequence $\textstyle a$ of length $\textstyle n$. You can perform an operation:
choose any **subsequence** of$\textstyle a$ and decrease every number in that chosen subsequence by $\textstyle 1$.

Calculate the minimum number of operations required to make $\textstyle a$ sorted into non-decreasing
order.

A subsequence is defined as sequences that can be formed by deleting
several elements from the original sequence. A non-decreasing sequence
refers to sequences where $\textstyle a_i\le a_{i+1}$ holds for all $\textstyle 1 \le i < n$.

### 输入描述

The first line contains a single integer$\textstyle t$ ($\textstyle 1 \le t \le 10^4$), representing
the number of test cases.

Each test case starts with a line containing a single integer$\textstyle n$ ($\textstyle 1 \le n \le 2 \times 10^5$).

The next line contains$\textstyle n$ integers$\textstyle a_1, a_2, \dots, a_n$ ($\textstyle 0 \le a_i \le 10^9$).

It is also guaranteed that the sum of \$n\$ does not exceed 2\*10^5^

### 输出描述

For each test case, output a single integer representing the minimum
number of operations.

### 示例1

#### 输入

```plain
3
5
4 2 5 1 3
3
10 8 6
2
7 7
```

#### 输出

```plain
4
4
0
```

