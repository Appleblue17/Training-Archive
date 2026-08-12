## L. Shift Square

### Problem Description

在某星系观测计划中，天文台记录了$n$ 个恒星碎片在二维平面中的初始位置，其中第$i$ 个碎片的位置为

$$P_{i}\{ x_{i},y_{i}\}\text{。}$$

受到中心引力源的影响，这些碎片会绕星系中心$O\{ 0,0\}$ 以相同的角速度进行匀速旋转，且任意时刻所有点相对于原点的旋转角度相同。

天文台使用一个观测框对这些碎片进行持续观测。该观测框满足如下条件：
- 观测框为一个各边平行于坐标轴的正方形；
- 观测框必须完全覆盖所有碎片的位置；
- 观测框不必覆盖星系中心 $O\{ 0,0\}$；
- 在所有满足覆盖条件的观测框中，选取周长最小的那个。

随着时间的推移，碎片不断旋转，观测框的大小也随之变化。观测系统在该时刻的能量消耗速率与观测框的周长成正比。

为了合理估计观测系统的能量消耗，你打算通过观测框周长对能量消耗进行估计。随着观测时间的增加，观测框周长的平均值会趋于某个值，你的任务是计算这个值。

形式化地说： 设在某一时刻碎片系统绕$O$ 点的旋转角度为 $\theta$，第 $i$ 个碎片的位置为 $\{ x_{i}^{\prime},y_{i}^{\prime}\}$，其中

$$x_{i}^{\prime} = x_{i}\cos\theta - y_{i}\sin\theta,$$

$$y_{i}^{\prime} = x_{i}\sin\theta + y_{i}\cos\theta\text{。}$$

定义此时所有点的横向宽度和纵向高度分别为

$$W\{\theta\} = \underset{i = 1}{\overset{n}{\max}}x_{i}^{\prime} - \underset{i = 1}{\overset{n}{\min}}x_{i}^{\prime},$$

$$H\{\theta\} = \underset{i = 1}{\overset{n}{\max}}y_{i}^{\prime} - \underset{i = 1}{\overset{n}{\min}}y_{i}^{\prime}\text{。}$$

由于观测框必须是正方形，所以最小正方形的边长为

$$L\{\theta\} = \max\{ W\{\theta\},H\{\theta\}\}\text{。}$$

因此该时刻观测框的周长为

$$Q\{\theta\} = 4L\{\theta\}\text{。}$$

你的任务是计算下面的值：

$$\underset{T\rightarrow + \infty}{\lim}\frac{1}{T}\int_{0}^{T}Q\{\theta\}\ d\theta\text{。}$$

### Input

输入包含多组测试数据。

第一行包含一个整数 $t\text{（}1 \leq t \leq 10\text{）}$，表示测试数据的组数。

下面是 $t$ 组数据，对于每组测试数据：

第一行包含一个整数 $n\text{（}2 \leq n \leq 2 \times 10^{5},\text{）}$，表示恒星碎片的数量。

接下来 $n$ 行，每行包含两个整数 $x_{i},y_{i}\text{（} - 10^{8} \leq x_{i},y_{i} \leq 10^{8}\text{）}$，表示第 $i$ 个恒星碎片的初始坐标。

保证同一组测试数据内，所有点两两不同。

### Output

对于每组测试数据，输出一行一个实数，表示观测框周长的长期平均值。
当你的答案与标准答案的相对误差或绝对误差不超过 $10^{- 6}$ 时，视为正确。

### Sample Input

```plain
3
2
0 0
1 0
4
0 0
0 2
0 3
0 5
4
0 0
1 0
1 1
0 1
```

### Sample Output

```plain
3.601265264628424
18.006326323142121
5.092958178940651
```

### Hint

对于第一组数据，两个点之间的距离为 $1$。
旋转过程中，最小正方形的边长为

$$\max\{\mid\cos\theta\mid,\mid\sin\theta\mid\},$$

所以平均周长为

$$\frac{1}{2\pi}\int_{0}^{2\pi}4\max\{\mid\cos\theta\mid,\mid\sin\theta\mid\},d\theta\frac{8\sqrt{2}}{\pi} \approx 3.601265264628\text{。}$$

