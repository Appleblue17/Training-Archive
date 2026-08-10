## D. Donkey Thinks...

### 题目描述

Donkey thinks potato chips are the best food ever!

So today, when he decides to go on a long journey, he wants his backpack
filled with all kinds of potato chips. He searches through the snack
zone in his home and finds lots of potato chips.

<div>

To better decide which bags of potato chips to bring with him (a subset
of the total bags, possibly none of them), he defines the property of a
bag of chips as follows:

<div>

- $h_i$. The happiness this bag of chips
  can give to Donkey.

<!-- -->

- $s_i$. The space this bag of chips
  occupies.

<!-- -->

- $d_i$. The delicacy of this bag of chips.

<div>

<div>

For simplicity, we note $h_i,s_i,d_i$ as the
\"happiness\", \"space\" and \"delicacy\" of the bag.
The total occupied space of the chosen bags can\'t exceed the volume of
the backpack, which is $V$.

<div>

\*\*
\*\*

<div>

However, the unoccupied space may cause bumps when Donkey moves during
the journey, which further causes value loss. If the chosen chips are $i_1,i_2,\dots,i_k\ (k\geq 1)$ and the
unoccupied space is $U$, the total value loss
on account of bumps is $(d_{i_1}+d_{i_2}+\dots+d_{i_k})\times U$. If
you choose no bag of chips, the value loss is $0$.
Considering both the advantages and disadvantages of bringing chips, the
value of the whole backpack is the sum of happiness brought by these
bags of chips minus the value loss. Donkey wants to maximize this value,
but just can\'t make the decision. Help is needed for this!

</div>

</div>

</div>

</div>

</div>

</div>

### 输入描述

Each test contains multiple test cases. The first line contains the
number of test cases $T\ (1≤T≤10^4)$ .

Each test case consists of many lines.

The first line contains $2$ integers $n,V\ (1\leq n\leq 10^5,1\leq V\leq 500)$,
the number of chip bags and the total volume of the bag.

Each line from the $2$-nd to the $(n+1)$-th contains $3$ integers $h_i,s_i,d_i\ (1\leq s_i\leq 500,1\leq h_i,d_i\leq 10^9)$,
the \"happiness\", \"space\" and \"delicacy\" of the $i$-th bag of chips.

It is guaranteed that $\sum n$ over all test
cases in one test will not exceed $10^5$, and $\sum V^2$ over all test cases in one test
will not exceed $2.5\times 10^5$.

### 输出描述

For each test case, output one integer: the maximum value.

### 示例1

#### 输入

```plain
2
2 5
10 2 1
2 2 100
2 5
10 2 1
2 3 100
```

#### 输出

```plain
7
12
```

#### 说明

In the first case, Donkey only chooses the first bag, resulting in a
value of $10-(5-2)\times 1=7$.

In the second case, Donkey chooses both the first bag and the second
bag, resulting in a value of $10+2-(5-2-3)\times(1+101)=12$.

It can be proved that there are no better strategies.
