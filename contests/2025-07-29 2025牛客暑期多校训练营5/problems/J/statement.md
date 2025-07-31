## J. Fastest Coverage Problem

### 题目描述

Given an $\textstyle n \times m$ binary
matrix where $\textstyle 1$ represents a
black cell and $\textstyle 0$ represents a
white cell. Every second, each black cell will convert its four
neighboring white cells (top, bottom, left, right) to black.

You may change **at most** one white cell to black (convert $\textstyle 0$ to $\textstyle 1$) to minimize the time required
for the entire matrix to become completely black. Find this minimum
time.

### 输入描述

The first line contains two integers $\textstyle n$ and$\textstyle m$ ($\textstyle 1 \leq n \times m \leq 2 \times 10^5$),
representing the number of rows and columns of the matrix.

The next $\textstyle n$ lines each contain $\textstyle m$ digits
($\textstyle 0$ or $\textstyle 1$), representing the initial
state of the matrix.

### 输出描述

Output a single integer representing the minimum time required to turn
the entire matrix black after adding one black cell.

### 示例1

#### 输入

```plain
3 3
0 0 0
0 0 0
0 0 1
```

#### 输出

```plain
2
```

#### 说明

You can choose position (1,1).Matrix at second 0:1 0 00 0 00 0 1Matrix at second 1:1 1 01 0 10 1 1Matrix at second 2:1 1 11 1 11 1 1

### 示例2

#### 输入

```plain
2 2
1 0
0 0
```

#### 输出

```plain
1
```

### 示例3

#### 输入

```plain
1 5
0 1 0 0 0
```

#### 输出

```plain
1
```

