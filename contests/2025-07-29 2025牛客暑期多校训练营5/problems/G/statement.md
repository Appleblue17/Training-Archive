## G. Line of Sight

### 题目描述

::::::: background-info
In 2024, team \"Moon Cat\" trained hundreds of hours together, walked
through a lot of places, ended with regret of loss, but experienced many
good things and memories, unpredicted and sparkling in mind as if a
dream.

SATSKY remembers, whenever the team was heading to somewhere, in the
streets or metro station or anywhere, it often occurs that laurxh
\"walks away without looking back, as if he had made some
determination\"(goes far ahead), while Genius_dream concentrates on her
phone and drops too far behind. In this case, SATSKY prefers to track
the middle point of two teammates\' locations, or at least find a place
where he can see his teammates both, especially when around the corner
and they can\'t see each other.

Now SATSKY transformed this into a programming geometry problem, in
commemoration of the memorable year with them, the treasure of his life.

Formally:

Give you an $\textstyle n$-sided polygon $\textstyle P$, of which each point $\textstyle P_{1 \sim n}$ is of integer
coordinates and given in **counterclockwise order;**

And give you two more integer points $\textstyle A$ and $\textstyle B$, inside the polygon
(**boundary not included) guaranteed;**

Call "point $\textstyle X$ can be seen from
point $\textstyle Y$ (in $\textstyle P$)" **if and only if the whole
segment connecting two points, **except two endpoints, is inside $\textstyle P$ strictly (and doesn't
intersect with any of edge of$\textstyle P$ naturally) ;****

You need to find out:
- For each point of polygon ($\textstyle i$     from $\textstyle 1$ to $\textstyle n$), can it
    ($\textstyle P_i$) be seen from point $\textstyle A$ ?
- For each point of polygon ($\textstyle i$     from $\textstyle 1$ to $\textstyle n$), can it
    ($\textstyle P_i$) be seen from point $\textstyle B$ ?
- Is there a point $\textstyle C$ inside
    the polygon (**boundary not included) to see $\textstyle A$ and $\textstyle B$ simultaneously ?**

:::::::

### 输入描述

The first line contains the number of test cases$\textstyle t$ ($\textstyle 1 \leq t \leq 2 \times 10^5$).
The description of the test cases follows.

The first line contains two integers$\textstyle n$ ($\textstyle 3 \leq n \leq 2 \times 10^5$),
indicating the number of points of $\textstyle P$;

The second line contains four integers $\textstyle x_A,y_A,x_B,y_B$ , representing
the x and y coordinates of point $\textstyle A$ and $\textstyle B$;

Then following $\textstyle n$ lines, the $\textstyle i$-th line contains two integers $\textstyle x_{P_i},y_{P_i}$ , representing
the x and y coordinates of point $\textstyle P_i$.

It's guaranteed that:
- $\textstyle P_{1 \sim n}$ are given in
    **counterclockwise order and must form a polygon;**
- For $\textstyle A$,$\textstyle B$     and each point of$\textstyle P$     ($\textstyle P_{1 \sim n}$), all the
    coordinates satisfy $\textstyle \lvert x \rvert,\lvert y \rvert \leq 10^9$;
- The sum of $\textstyle n$ in each test
    file doesn't exceed$\textstyle 10^6$     ($\textstyle \sum n \leq 10^6$).

    

Some emphasis:
- Adjacent edges of $\textstyle P$ may be
    collinear, so are not adjacent pairs;
- Any three points within $\textstyle A$,$\textstyle B$     and $\textstyle P_{1 \sim n}$ may be on
    the same straight line,$\textstyle A$     and $\textstyle B$ may even coincide;
- The coordinates of $\textstyle C$ you
    choose can be **decimals.**

### 输出描述

For each test case, answer it on three lines:

In the first line, output$\textstyle n$ integers separated by spaces: the $\textstyle i$-th integer should be 1 if $\textstyle P_i$ can be seen from point $\textstyle A$, or 0 if it can't;

In the second line, output$\textstyle n$ integers separated by spaces: the $\textstyle i$-th integer should be 1 if $\textstyle P_i$ can be seen from point $\textstyle B$, or 0 if it can't;

In the third line, if there exists a point $\textstyle C$ meeting the requirements
above, output a string "Yes" (without quotes); otherwise output a string
"No" (without quotes).

### 示例1

#### 输入

```plain
2
8
-1 1 1 -1
2 -1
2 1
1 2
-1 2
-2 1
-2 -1
-1 -2
1 -2
13
1 1 6 1
0 1
1 0
2 1
3 1
4 0
5 0
6 0
7 1
6 2
5 1
4 1
3 2
1 2
```

#### 输出

```plain
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
Yes
1 1 1 0 0 0 0 0 0 0 0 1 1
0 0 0 0 1 1 1 1 1 1 0 0 0
No
```

### 示例2

#### 输入

```plain
2
26
6 20 20 6
23 8
19 6
16 5
13 5
10 6
8 7
7 8
6 10
5 13
5 16
6 19
8 23
5 21
3 19
2 17
1 14
1 11
2 7
3 5
5 3
7 2
11 1
14 1
17 2
19 3
21 5
18
-15 20 15 20
-3 16
-6 15
-15 22
-18 13
-18 7
-21 -2
-21 -8
-18 -14
-6 -20
6 -20
18 -14
21 -8
21 -2
18 7
18 13
15 22
6 15
3 16
```

#### 输出

```plain
0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1
No
0 1 1 1 1 0 1 1 1 1 1 1 1 0 0 0 0 0
0 0 0 0 0 1 1 1 1 1 1 1 0 1 1 1 1 0
Yes
```

### 备注

Graphs of all samples are shown below in order:sample 1-1:

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603158294/6EE7CF07BD6DC5DB395EF3937F0429AE)

sample 1-2:

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603255082/8C48DA35E654A5AFEA304DD9994C453C)

sample 2-1:

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603262982/6C41A6E045994169B09A270749C8DDBB)sample 2-2:

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603272494/0DEE8CF824D43456DC0388C572D3DD13)sample 2-3:

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753607103004/7B6AB3489727CC25BCCF3F9D874CA47E)

sample 2-4:

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603295708/D6CD89C950A86309B2B04CD3C9D46BEA)sample 3-1:

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603302675/ACB5FAE62F0B664AD09A0D33FBC69341)sample 3-2:

![](https://uploadfiles.nowcoder.com/images/20250727/0_1753603309509/C60733D4ABD780EE730D67973686F7B5)

