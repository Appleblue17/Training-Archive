## K. Reversed Hanged Man

### 题目描述

*The Hierophant* and *The High Priestess* are fascinated by the
mysteries of the universe. To explore some of these mysteries on Earth
- -- apparently a part of the universe, they set up an experiment
involving a small ball, several strings, and a flat ceiling. The ceiling
is represented by the $\textstyle xOy$ plane,
and several hooks are attached to this ceiling at different positions.
From each hook, *The Hierophant* has hung a massless, inextensible
string, and at the end of all these strings, they have tied a small
ball.

Initially, *The Hierophant* holds the ball right at the origin $\textstyle (0, 0, 0)$, and all the strings
are loose. When he releases the ball, gravity starts pulling it straight
down along the negative $\textstyle z$-axis.
If a string becomes fully stretched, it will exert a force along its
direction on the ball to prevent it from moving further away from its
hook than the string's length. Under the constraints of the strings,
gravity pulls the ball as low as possible, stopping at the unique point
with the lowest gravitational potential.

![](https://uploadfiles.nowcoder.com/images/20250724/0_1753350149922/B1233FE5D2EDC5B4B494B56CBE338D2E){style="width:400px;height:auto;"}Illustration for the first sample.

*The High Priestess* is eager to know where the ball will finally come
to rest. Can you help them determine the final resting position of the
ball?

### 输入描述

The first line of input contains an integer $\textstyle n$ $\textstyle (1 \leq n \leq 32768)$,
representing the number of hooks.

The following $\textstyle n$ lines each
contain three integers $\textstyle x_i, y_i, l^2_i~(|x_i|, |y_i| \leq 128, x_i ^ 2 + y_i ^ 2  < l^2_i \leq 32768)$,
representing the coordinates $\textstyle (x_i, y_i, 0)$ of the $\textstyle i$-th hook and the **square** of
length $\textstyle l_i$ of the string
attached to that hook.

All volumes are considered negligible. Strings will not wind around each
other or collide with the ball.

### 输出描述

Output three decimal real numbers $\textstyle x, y, z$ separated by spaces,
which represent the final coordinates of the ball. Your answer should
have an absolute or relative error of at most $\textstyle 10^{-4}$.

### 示例1

#### 输入

```plain
5
-2 0 8
-1 0 6
0 0 4
1 0 8
3 0 13
```

#### 输出

```plain
0.000000000 0.000000000 -2.000000000
```

### 示例2

#### 输入

```plain
3
-1 -1 9
1 0 9
0 1 9
```

#### 输出

```plain
-0.166666667 -0.166666667 -2.758824226
```

