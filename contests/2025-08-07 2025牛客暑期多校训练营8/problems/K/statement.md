## K. Many Sprinklers!!!

### 题目描述

There are $n$ sprinklers on a two-dimensional
Cartesian plane, each of which can water an area inside (boundary
included) a circle.

![](https://uploadfiles.nowcoder.com/images/20250803/0_1754204180484/0EE66FDD85690660CC9316918E6CCB78){style="height:auto;width:400px;"}The sprinklers in the sample cases.You need to find the total area that can be watered by the sprinklers.

### 输入描述

The first line contains an integer$T$ ($1 \leq T \leq 10^4$), indicating the number
of test cases.Then follow $T$ test cases. For each test
case:The first line contains an integer$n$ ($1 \leq n \leq 10^5$), representing the
number of sprinklers.Then $n$ lines follow, the $i$-th of which contains three integers $x_i$, $y_i$ and$r_i$ ($-10^4 \leq x_i, y_i \leq 10^4$, $1 \leq r_i \leq 10^4$), indicating that the $i$-th sprinkler waters an area inside or on
the boundary of the circle centered at $(x_i, y_i)$ with radius $r_i$.It is guaranteed that the sum of $n$ over all $T$ test cases does not exceed $10^5$.

### 输出描述

For each test case, output a real number in one line, representing the
total area that can be watered by the sprinklers.Your answer is acceptable if its absolute or relative error does not
exceed $10^{-6}$. Formally speaking, suppose
that your output is $a$ and the jury\'s
answer is $b$, and your output is accepted if
and only if $\frac{|a - b|}{\max(1, |b|)} \le 10^{-6}$.

### 示例1

#### 输入

```plain
2
3
0 0 2
0 2 2
2 0 2
3
0 0 2
0 3 2
3 0 2
```

#### 输出

```plain
27.360855087873111763
34.072617811256640852
```

