## D. Determinant of 01-Matrix

### 题目描述

Given a positive integer $N \le 10^9$, please
construct a matrix $A=(a_{i,j})_{1 \le i,j \le n}$ that contains
only $0$s and $1$s, satisfying\

1.  $1 \le n \le 200$;
2.  $\mathrm{det}(A) = N$.

It is guaranteed that there exists a valid solution under the problem
constraints.\

### 输入描述

The input contains only one positive integer$N$ ($1 \le N \le 10^9$).

### 输出描述

The output should contain a first line with a positive integer$n$ ($1 \le n \le 200$), indicating the size of
the constructed matrix.\
\
Next, output $n$ lines, where the $i$-th line contains $n$ integers$a_{i,1}, a_{i,2},\ldots,a_{i,n}$ ($a_{i,j} \in \{0,1\}$), representing the
elements of the $i$-th row of the matrix. If
there are multiple solutions, any one of them can be output.\

### 示例1

#### 输入

```plain
1
```

#### 输出

```plain
1
1
```

### 示例2

#### 输入

```plain
5
```

#### 输出

```plain
7
0 0 0 1 0 0 1
0 0 1 0 0 1 0
0 1 1 0 0 0 1
0 1 0 1 1 0 0
1 1 0 1 1 1 0
1 1 1 1 0 0 0
1 1 1 0 1 0 0
```

