## J. Ivory

### 题目描述

You will be given four positive integers $\textstyle a, b, c, d$. Calculate the value
of$\textstyle \operatorname{gcd}(a^b, c^d)$ modulo $\textstyle 998244353$.

### 输入描述

The first line contains a single integer$\textstyle t$ ($\textstyle 1 \le t \le 10^5$), the number
of test cases.

For each test case, the input consists of a single line containing four
positive integers$\textstyle a, b, c, d$ ($\textstyle 1 \le a, b, c, d \le 10^{18}$).

### 输出描述

For each test case, print a single integer in one line, representing the
result of$\textstyle \operatorname{gcd}(a^b, c^d)$ modulo $\textstyle 998244353$.

### 示例1

#### 输入

```plain
5
2 3 3 2
4 2 8 1
6 2 9 1
7 1 11 1
10000000000000 1 10000000000000 1
```

#### 输出

```plain
1
8
9
1
586315999
```

