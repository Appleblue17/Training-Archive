## F. Broken LED Lights

### 题目描述

There is an ancient tall building that uses LED light tubes in the
elevator to display the floor numbers. However, due to budget
constraints for maintenance, the management is trying to reduce the
number of floors the elevator can stop at and then discard unnecessary
LED light tubes.Currently, the number of floors the elevator can stop at has been
determined, and the task of reducing the LED light tube wiring has been
assigned to you. You know that the building has $10^m$ floors, with floor numbers ranging
from $0$ to $(10^m - 1)$ and displayed as numbers of
length $m$ (which may be left-padded with
zeros). For each digit of the floor number, there were originally $7$ light tubes, as shown in the figure
below, that would flexibly turn on and off according to the required
displayed number.

![](https://uploadfiles.nowcoder.com/images/20250805/0_1754372657498/971DF7DE24A0F12A0C4A2C0010B954F6){style="height:auto;width:399.2px;"}Now, $n$ floors have been selected to
continue supporting stops, and the elevator will only display these $n$ floor numbers while moving and stopping.
Your task is to minimize the number of light tubes that need to remain
operational so that the on and off states of these tubes can be used to
determine which of the $n$ possible numbers
the stopping floor corresponds to. Your time is very precious, so please
calculate the minimum number of light tubes that need to remain
operational as soon as possible.

### 输入描述

The first line contains an integer$T$ ($1 \leq T \leq 100$), indicating the number
of test cases.Then follow $T$ test cases. For each test
case:The first line contains two integers $n$ and$m$ ($1 \leq n \leq 100$, $1 \leq m \leq 3$).The second line contains $n$ distinct
integers$x_1, x_2, \ldots, x_n$ ($0 \leq x_i < 10^m$), representing the
selected floor numbers. It is guaranteed that each floor number has
exactly $m$ digits.It is also guaranteed that the sum of$n$ over $T$ test cases does not exceed $10^3$.

### 输出描述

For each test case, output an integer in one line, representing the
minimum number of light tubes that need to remain operational.

### 示例1

#### 输入

```plain
3
10 1
0 1 2 3 4 5 6 7 8 9
5 2
01 02 05 08 11
1 3
012
```

#### 输出

```plain
5
3
0
```

#### 说明

For the second case of the example, one of the possible solutions is
listed below.The original states:![](https://uploadfiles.nowcoder.com/images/20250805/0_1754372709217/192FDB4410765D8D95097DA340E3694A){style="height:auto;width:453.6px;"}After reduction:![](https://uploadfiles.nowcoder.com/images/20250805/0_1754372724401/867952DF52577EAA1AC1030919C75B57){style="height:auto;width:453.6px;"}

