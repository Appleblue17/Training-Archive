## I. 自乘

### Problem Description

给定一个长度为 $n$ 的数组 $a$（$1 \leq a_{i} \leq n$），定义自乘操作：将 $a$ 映射为新数组 $c$，其中 $c_{i} = a_{a_{i}}$。

记初始数组为 $a_{0} = a$，每次操作后 $a_{i + 1}$ 为 $a_{i}$ 的自乘。即：

$$a_{0} = a,\qquad a_{i + 1}\lbrack j\rbrack = a_{i}\left\lbrack a_{i}\lbrack j\rbrack \right\rbrack\quad(1 \leq j \leq n)$$

给定初始数组 $a$ 和目标数组 $b$，求最小的非负整数 $k$ 使得 $a_{k} = b$。若无法得到，输出 $- 1$。

### Input

第一行一个整数 $t$（$1 \leq t \leq 2000$），表示测试用例数。

每组测试用例包含三行：
- 第一行一个整数 $n$（$1 \leq n \leq 1000$），表示数组长度。
- 第二行 $n$ 个整数 $a_{1},a_{2},\ldots,a_{n}$（$1 \leq a_{i} \leq n$）。
- 第三行 $n$ 个整数 $b_{1},b_{2},\ldots,b_{n}$（$1 \leq b_{i} \leq n$）。

保证所有测试用例的 $n$ 之和不超过 $10^{6}$。

### Output

对于每组测试用例，输出一行一个整数 $k$。若不存在这样的 $k$，则输出 $- 1$。

### Sample Input

```plain
4
5
2 3 4 5 1
4 5 1 2 3
5
4 3 2 1 4
1 2 3 4 1
2
1 2
1 2
2
1 2
2 1
```

### Sample Output

```plain
3
1
0
-1
```

### Hint

对于第一组样例，$a_{0} = \lbrack 2,3,4,5,1\rbrack$。
- 第 1
    次自乘后：$a_{1} = \lbrack 3,4,5,1,2\rbrack$；
- 第 2
    次自乘后：$a_{2} = \lbrack 5,1,2,3,4\rbrack$；
- 第 3
    次自乘后：$a_{3} = \lbrack 4,5,1,2,3\rbrack = b$，故 $k = 3$。

对于第三组样例，$a_{0} = \lbrack 1,2\rbrack$，已等于 $b$，无需操作，$k = 0$。

对于第四组样例，数组 $a$ 一直是 $\lbrack 1,2\rbrack$，无法达到 $b$，输出 $- 1$。

