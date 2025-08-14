## J. Segments (segments)

### 题目描述

Little A is attending a culture class and unfortunately cannot
understand anything. At this moment, he discovers that all the pens in
his pen case are of the same length. So he takes them out and starts
playing.Since this is a real event, the problem occurs in **three-dimensional
space**.Little A wants to determine $n+2$ real
coordinate points$V_1=(x_1,y_1,z_1),V_2=(x_2,y_2,z_2),V_3=(x_3,y_3,z_3),\cdots,V_{n+2}=(x_{n+2},y_{n+2},z_{n+2})$ (points can overlap) in space that satisfy the following requirements:
1.  $x_{n+1}=x_1$, $y_{n+1}=y_1$, $z_{n+1}=z_1$.
2.  $x_{n+2}=x_2$, $y_{n+2}=y_2$, $z_{n+2}=z_2$.
3.  For all integers$i$     ($1\le i\le n$), $\text{dis}(V_i,V_{i+1})=1$, where $\text{dis}(A,B)$ denotes the Euclidean
    distance between real coordinate points $A$ and $B$ in
    space.
4.  For all integers$i$     ($1\le i\le n$), line segment $V_iV_{i+1}$ is perpendicular to line
    segment $V_{i+1}V_{i+2}$.

Little A needs you to provide the coordinates of $V_1,V_2,V_3,\cdots,V_n$ in one set of
solution that satisfies the requirements. If multiple sets of solutions
exist, output any one. If no solution exists, no output is required.Additionally, he needs you to provide the number of distinct solution
sets that satisfy the requirements. If infinitely many sets satisfy the
requirements, output $\tt{inf}$. If no
solution exists, output $\texttt{-1}$.Two solutions are defined as distinct if and only if the $n$ points cannot be made to coincide through
any combination of translation, rotation, and axial symmetry.

### 输入描述

The first line contains an integer$T$ ($1 \le T \le 10^5$), indicating the number
of test cases.Lines $2$ to$T+1$ each contain an integer$n$ ($2 \le n \le \sum n \le 10^6$), representing
the number of points.

### 输出描述

For each test case:

If a valid solution exists: First output$n$ lines, where the $i$-th line
($1 \le i \le n$) contains three real numbers $x_i$, $y_i$, $z_i$. Then on line $n+1$, output an integer or a string
representing the number of distinct solutions. If infinitely many
solutions exist, output $\tt{inf}$.

If no valid solution exists, output a single line containing $\texttt{-1}$.

This problem uses a Special Judge. Your output must guarantee that for
all integers$i$ ($1 \le i \le n$), $|\text{dis}(V_i,V_{i+1}) - 1| \le 10^{-6}$,
and $|\overrightarrow{V_iV_{i+1}} \cdot \overrightarrow{V_{i+1}V_{i+2}}| \le 10^{-6}$.

### 示例1

#### 输入

```plain
2
4
5
```

#### 输出

```plain
0 0 0
1 0 0
1 1 0
0 1 0
1
-1
```

