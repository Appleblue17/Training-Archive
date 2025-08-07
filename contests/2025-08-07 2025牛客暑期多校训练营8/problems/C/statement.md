## C. Bernoulli's Principle

### 题目描述

Bernoulli\'s principle is a definition in fluid mechanics, stating that
the total sum of kinetic energy, potential energy and internal energy of
a fluid remains constant. Torricelli\'s law is a particular case of
Bernoulli\'s principle, stating that when a liquid flows out from a
small hole at the surface of a container, its initial velocity is $\sqrt{2 g h}$, where $h$ is the height difference from the center
of the hole to the highest point of the liquid surface, and $g$ is the gravitational acceleration.Now, a cylindrical container filled with liquid is placed vertically on
a horizontal plane, and the liquid is continuously and slowly added to
keep the height of the surface constant. On the side of the cylinder are $n$ small holes (numbered from $1$ to $n$)
through which liquid is flowing out. The liquid flow undergoes free fall
in the vertical direction with an initial velocity of $0$ and acceleration of $g$ (the horizontal initial velocity is as
mentioned above). Given the height of the liquid surface and the height
differences from the center of each small hole to the horizontal plane,
please analyze the horizontal distance that the liquid from each hole
travels before reaching the plane, and sort these $n$ small holes based on the size of this
distance.

### 输入描述

The first line contains an integer$T$ ($1 \leq T \leq 10^5$), indicating the number
of test cases.Then follow $T$ test cases. For each test
case:The first line contains two integers $n$ and$H$ ($1 \leq n \leq 10^5, 2 \leq H \leq 10^9$),
representing the number of holes and the height of the liquid surface.The second line contains $n$ integers$h_1, h_2, \ldots, h_n$ ($1 \leq h_i < H$), where the $i$-th number represents the height
difference from hole number $i$ to the
horizontal plane.It is guaranteed that the total sum of$n$ over $T$ test cases does not exceed $10^6$.

### 输出描述

For each test case, output $n$ integers in
one line, representing the indices of the$n$ holes sorted in non-decreasing order based on their horizontal movement
distances. If there are multiple possible outputs, any of them is
acceptable.

### 示例1

#### 输入

```plain
2
5 10
1 3 5 7 9
5 20
1 3 5 7 9
```

#### 输出

```plain
1 5 2 4 3
1 2 3 4 5
```

