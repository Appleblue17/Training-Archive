## F. Flight Tracker 2

### 题目描述

Let the Earth be a sphere centered at $(0,0,0)$ with a radius $r$ in 3D Euclidean space. There is a flight
flying along the shortest path from the departure place to the
destination place on the surface of the Earth.\
\
As an aviation enthusiast, you have a receiver that can receive the
signal from the flight with a distance no more than $d$. Note that we calculate the distance
between two points by measuring the shortest path on the surface of the
Earth, which is NOT the Euclidean distance in 3D Euclidean space.\
\
You need to find the area of the region on the surface of the Earth
where you can receive the signal from the flight with the receiver at
some time when the flight is flying.\

### 输入描述

The first line of the input contains an integer$T$ ($1 \le T \le 10^4$), indicating the number
of test cases. For each test case:\
\
The first line contains two integers$r$ ($1 \le r \le 100$) and$d$ ($1 \le d \le 1\,000$), indicating the radius
of the Earth and the maximum distance on the surface of the Earth for
receiving the signal from the flight.\
\
The second line contains three integers $u$, $v$, and $w$ $(-100 \le u, v, w \le 100, u^2 + v^2 + w^2 > 0)$,
indicating that the departure place has coordinates $\left( \frac{ru}{\sqrt{u^2 + v^2 + w^2}}, \frac{rv}{\sqrt{u^2 + v^2 + w^2}}, \frac{rw}{\sqrt{u^2 + v^2 + w^2}} \right)$.\
\
The third line contains three integers $x$, $y$, and $z$ $(-100 \le x, y, z \le 100, x^2 + y^2 + z^2 > 0)$,
indicating that the destination place has coordinates $\left( \frac{rx}{\sqrt{x^2 + y^2 + z^2}}, \frac{ry}{\sqrt{x^2 + y^2 + z^2}}, \frac{rz}{\sqrt{x^2 + y^2 + z^2}} \right)$.\
\
It is guaranteed that the departure place and the destination place
cannot coincide with each other and cannot be directly opposite each
other on the Earth. Therefore, the shortest path from the departure
place to the destination place on the surface of the Earth is uniquely
determined.

### 输出描述

For each test case, output a line containing a real number, indicating
the area of the region on the surface of the Earth where you can receive
the signal from the flight with the receiver at some time when the
flight is flying.\
\
Your answer is acceptable if its absolute or relative error does not
exceed $10^{-4}$. Formally speaking, suppose
that your output is $a$ and the jury\'s
answer is $b$, and your output is accepted if
and only if $\frac{|a - b|}{\max(1, |b|)} \le 10^{-4}$.\

### 示例1

#### 输入

```plain
3
10 10
1 0 0
0 1 0
10 20
1 0 0
0 1 0
10 30
1 0 0
0 1 0
```

#### 输出

```plain
553.192486159509631660
1167.025509055589598928
1256.637061435917295360
```

