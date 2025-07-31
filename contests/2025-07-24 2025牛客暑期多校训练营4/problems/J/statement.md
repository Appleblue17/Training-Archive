## J. Journey Around the World

### 题目描述

There is a grid with $n$ rows and $n$ columns
($3 \leq n \leq 200$). For $1 \leq i,j \leq n$, there is an undirected
edge between the cell in the $i$-th row and $j$-th column and the cell in the $i$-th row and $(j+1)$-th column (the $(n+1)$-th column is considered as the $1$-st column), with a weight of either $1$ or $2$. For $1 \leq i < n$ and $1 \leq j \leq n$, there is an undirected
edge between the cell in the $i$-th row and $j$-th column and the cell in the $(i+1)$-th row and $j$-th column, also with a weight of either $1$ or $2$.

For $1 \leq i \leq n$, find the shortest path
length from the cell in the $1$-st row and $i$-th column to the cell in the $n$-th row and $i$-th column, passing through each column at
least once.

### 输入描述

The first line contains a positive integer $T$ representing the number of test cases.
The sum of $n$ across all test cases does not
exceed $200$.

For each test case, the first line contains a positive integer $n$.

The next $n$ lines each contain $n$ integers, where the $j$-th integer of the $i$-th line represents the weight of the edge
between the cell in the $i$-th row and $j$-th column and the cell in the $i$-th row and $(j+1)$-th column.

The following $n-1$ lines each contain $n$ integers, where the $j$-th integer of the $i$-th line represents the weight of the edge
between the cell in the $i$-th row and $j$-th column and the cell in the $(i+1)$-th row and $j$-th column.

### 输出描述

For each test, output a total of $n$ lines,
where the $i$-th line contains a single
integer representing the shortest path length from the cell in the $1$-st row and $i$-th column to the cell in the $n$-th row and $i$-th column, passing through each column at
least once.

### 示例1

#### 输入

```plain
2
3
2 1 2
2 1 2
2 2 2
1 2 2
1 1 2
5
1 1 2 1 1
2 1 1 2 2
2 2 1 2 2
2 1 2 2 1
2 2 1 1 1
1 2 2 2 2
2 1 2 1 2
2 2 2 1 2
1 1 2 2 2
```

#### 输出

```plain
7
7
7
11
11
11
11
11
```
