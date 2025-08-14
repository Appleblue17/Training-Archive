## F. Sensei and Yuuka Going Shopping (yuuka)

### 题目描述

Sensei recently designed some programming competition problems and
earned a considerable amount of money. After spending part of it on
strawberry milk, a significant sum remained. Yuuka is on duty today, and
with little work to do, Sensei decided to take her shopping at the mall
to make up for a past joke he made about her weight.Before purchasing any items, Sensei learned that the mall has $n$ stores arranged in a row. The stores are
numbered from left to right as $1, 2, 3, \cdots, n$. Yuuka listed the
**uniqueness value** for each store: store$i$ ($1 \le i \le n$) has a uniqueness value of
positive integer $a_i$.Now, Sensei needs to partition all stores into three contiguous
sections, numbered $1$, $2$, and $3$ from
left to right.Specifically, Sensei will specify two integers$b_1, b_2$ ($1 
- Section$i$     ($1 \le i \le 3$) contains stores $b_{i-1}, b_{i-1} + 1, b_{i-1} + 2, \cdots, b_i - 1$.

For a uniqueness value $x$, if each section
contains at least one store with uniqueness value $x$, then Yuuka calls $x$ **universal**.Sensei is by no means stingy, but he wants to save money for more
important matters. To reduce Yuuka\'s spending on goods, he aims to
choose a partitioning scheme that maximizes the number of universal
uniqueness values. He asks for your help and also requests you provide a
partitioning scheme achieving this maximum value.

### 输入描述

**The problem contains multiple test cases.**The first line of input contains a positive integer$T$ ($1 \le T \le 10$), representing the number
of test cases.For each test case:The first line contains a positive integer$n$ ($3 \le n \le 150,000$), indicating the
number of stores.The second line contains $n$ positive
integers$a_1, a_2, a_3, \cdots, a_n$ ($1 \le a_i \le 10^6$), representing the
uniqueness value of each store.

### 输出描述

For each test case, output two lines:The first line contains an integer representing the maximum value sought
by the problem.

The second line contains two integers$b_1$ and $b_2$. You must ensure $1 

**Outputting any valid scheme will be considered correct.**

### 示例1

#### 输入

```plain
3
9
1 2 3 3 2 1 2 3 1
10
3 3 2 2 2 3 2 1 1 1
10
4 3 3 3 4 4 3 4 3 3
```

#### 输出

```plain
3
4 7
1
2 3
2
3 6
```

#### 说明

**A friendly reminder from Yuuka: This problem involves large input
sizes, so please choose an appropriate input method.**This sample contains three test cases.In the first test case, setting $b_1=4, b_2=7$ makes uniqueness values $1$, $2$, and $3$ universal. The number of universal
uniqueness values achieves the maximum possible value.In the second test case, setting $b_1=2, b_2=3$ makes uniqueness value $3$ universal. The number of universal
uniqueness values achieves the maximum possible value. It is worth
noting that for this test case, there exists more than one partitioning
scheme achieving the maximum value; outputting any valid scheme is
considered correct.In the third test case, setting $b_1=3, b_2=6$ makes uniqueness values $3$ and$4$ universal. The number of universal uniqueness values achieves the
maximum possible value. Similarly, for this test case, multiple
partitioning schemes achieve the maximum value; outputting any valid
scheme is considered correct.

