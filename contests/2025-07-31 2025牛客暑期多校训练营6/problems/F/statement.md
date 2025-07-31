## F. Random Segment Tree

### 题目描述

Define a random segment tree as a binary tree where each node represents
a closed interval $[l, r]$:
- If $l = r$, then the node is a leaf node.
- If $l

### 输入描述

The first line contains two
integers $n$ ($1 \le n \le 10^5$).

### 输出描述

Print $2\cdot n$ lines. Each line contains an
integer, representing the answer
modulo $998244353$.

### 示例1

#### 输入

```plain
3
```

#### 输出

```plain
1
2
2
1
0
0
```

### 示例2

#### 输入

```plain
4
```

#### 输出

```plain
1
2
4
2
1
0
0
0
```

### 示例3

#### 输入

```plain
5
```

#### 输出

```plain
1
2
4
4
499122179
1
499122177
0
0
0
```

