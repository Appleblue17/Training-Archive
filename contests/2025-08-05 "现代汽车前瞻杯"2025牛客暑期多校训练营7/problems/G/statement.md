## G. Nice Doppelgnger

### 题目描述

Given a positive even integer $\textstyle n$,
construct a subset $\textstyle S$ of the set $\textstyle \{1, 2, \dots, n\}$ with exactly $\textstyle \frac{n}{2}$ elements, such that
for any three numbers$\textstyle x, y, z$ (possibly equal) in $\textstyle S$, their
product $\textstyle xyz$ is not a perfect
square.

### 输入描述

The first line contains a single integer$\textstyle t$ ($\textstyle 1 \le t \le 10^4$), representing
the number of test cases.

For each test case, a single line contains a positive even integer$\textstyle n$ ($\textstyle 2 \le n \le 10^6$).

It is guaranteed that the sum of $\textstyle n$ over all test cases does not
exceed $\textstyle 10^6$.

### 输出描述

For each test case, output a single line containing $\textstyle \frac{n}{2}$ space-separated
integers, representing the elements of the constructed subset $\textstyle S$.

### 示例1

#### 输入

```plain
2
4
6
```

#### 输出

```plain
2 3
2 3 5
```

