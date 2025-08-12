## F. Military Training

### 题目描述

College life has begun! The beginning of college life is military
training.

Pog is a pig with two feet. The distance between Pog's two feet is
always exactly $\textstyle 1$, and they
always stand on two integer grid points on a two-dimensional plane.
During military training, the instructor taught Pog a special skill:
rotation. The rules are as follows:
- In each operation, Pog can choose either foot as a pivot, and then
    rotate the other foot around the pivot by $\textstyle 90^\circ$ (either clockwise
    or counterclockwise).

Now, Pog is initially standing at two points on the plane, $\textstyle (sx_1, sy_1)$ and $\textstyle (sx_2, sy_2)$. His goal is to
move his two feet onto two other points, $\textstyle (tx_1, ty_1)$ and $\textstyle (tx_2, ty_2)$, by using the
allowed rotations. It does not matter which foot ends up at which target
point. The distance between the two feet always remains $\textstyle 1$, no matter how Pog rotates.

Please help Pog determine: what is the minimum number of rotations
needed for him to reach the target positions? If it is impossible to
reach the target positions, output $\textstyle -1$ instead.

### 输入描述

Each test contains multiple test cases. The first line contains a single
integer $\textstyle T~(1 \le T \le 10^5)$ ---
the number of test cases.

The only line of each case contains eight integers $\textstyle sx_1, sy_1, sx_2, sy_2, tx_1, ty_1, tx_2, ty_2 ~ (|s*_*|,|t*_*| \le 10 ^ 9)$.

It is guaranteed that $\textstyle |sx_1 - sx_2| + |sy_1 - sy_2| = |tx_1 - tx_2| + |ty_1 - ty_2| = 1$.

### 输出描述

For each test case, if Pog can reach the final position, output a single
integer --- the minimum number of operations Pog needs to rotate.
Otherwise, output $\textstyle -1$.

### 示例1

#### 输入

```plain
7
0 0 0 1 0 0 0 1
0 0 1 0 0 0 0 1
0 0 0 1 1 1 0 1
0 0 0 1 1 1 1 0
0 0 0 1 0 0 -1 0
0 0 1 0 0 1 -1 1
0 0 -1 0 40 50 40 51
```

#### 输出

```plain
0
1
1
2
1
2
101
```

### 备注

![](https://uploadfiles.nowcoder.com/images/20250724/0_1753350986679/6F9F206148B2F04B1EDF328BDF41B49E)

