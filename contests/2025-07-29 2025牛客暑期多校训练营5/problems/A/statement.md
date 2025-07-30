## A. Entangled Coins

### 题目描述

<div>

Given $\textstyle n$ coins with two sides
(facing downwards or upwards),$\textstyle s$ of them are facing upwards while the remaining are the opposite.

<div>

\

<div>

You can operate coins **any number of times (including zero)**; in each
operation, you should arbitrarily choose **exactly** $\textstyle k$ coins to flip (facing up
becomes facing down and vice versa).

<div>

\

Your goal is to change the number of coins facing up (from $\textstyle s$) to $\textstyle t$ . Output the **minimum**
number of operations or report that it's impossible.

</div>

</div>

</div>

</div>

### 输入描述

<div>

The first line contains the number of test cases$\textstyle t$ ($\textstyle 1 \leq t \leq 2 \times 10^5$).
The description of the test cases follows.

</div>

<div>

\

</div>

Each test case is represented by one line, containing four integers$\textstyle n,k,s,t$ ($\textstyle 1 \leq k \leq n \leq 10^9,0 \leq s,t \leq n$)
meaning as above.

### 输出描述

<div>

For each test case, answer it on a full line:

</div>

<div>

\

</div>

<div>

if there exists a solution, output an integer representing the minimum
number of operations;or if not, output $\textstyle -1$ as the report for impossible.

</div>

### 示例1

#### 输入

```plain
8
8 3 4 7
9 7 1 0
16 15 1 0
4 2 3 3
6 6 2 4
7 6 2 5
98257693 98257692 24 43850682
98257693 98257692 24 43850681
```

#### 输出

```plain
1
5
15
0
1
-1
43850658
-1
```

### 备注

\

