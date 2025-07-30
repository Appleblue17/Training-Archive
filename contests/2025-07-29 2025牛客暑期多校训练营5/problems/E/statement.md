## E. Mysterious XOR Operation

### 题目描述

We define a special mysterious XOR operation $\textstyle \oplus_{m}$ with the following
rules:

For two numbers $\textstyle a$ and $\textstyle b$, first compute their regular
XOR result $\textstyle c = a \oplus b$. Then
process $\textstyle c$'s binary
representation as follows:

Scan $\textstyle c$'s binary representation
from the least significant bit to the most significant bit

Initialize a counter$\textstyle count = 0$ 

For each bit:

If the bit is 1:
- Increment $\textstyle count$ by 1
- If $\textstyle count$ is odd, keep the
    bit
- If $\textstyle count$ is even, clear the
    bit (set to 0)

If the bit is 0, leave it unchanged

Example:$\textstyle (101001)_2 \oplus_{m} (10010)_2 = (101001)_2$ 

Given an array $\textstyle A$ of length $\textstyle N$, compute the sum of the
mysterious XOR of $A_i$ and $A_j$ for all unordered pairs $\textstyle (i,j)$ where $i\ne j$.Formally, this can be expressed
as $\sum_i^N \sum_{j>i}^N$$A_i \oplus_m A_j$.

### 输入描述

The first line contains an integer$\textstyle N$ ($\textstyle 2 \leq N \leq 10^5$).

The second line contains$\textstyle N$ integers$\textstyle A_i$ ($\textstyle 0 \leq A_i \leq 10^8$).

### 输出描述

Output a single integer representing the sum of mysterious XOR results
for all unordered pairs.

### 示例1

#### 输入

```plain
3
5 3 9
```

#### 输出

```plain
8
```

#### 说明

$5 \oplus_{m} 3 = 2$\ $5 \oplus_{m} 9 = 4$\ $3 \oplus_{m} 9 = 2$So the answer equals$4+2+2=8$

