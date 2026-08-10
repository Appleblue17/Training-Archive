## E. Effective Numbers

### 题目描述

Square numbers are always lovable. A square number is a number that can
be expressed by the square of an integer.

Here comes the group made of $l,l+1,\dots,r$,
and they want to be square numbers. The witch offers them a special
potion. When a number drinks a bottle of potion, it can enlarge itself
by one of its prime factors, and it can choose which one to add. As its
dream is always to become a square number, if it can enlarge itself into
a square number, it will always do so.

The potion is kind of dangerous, and drinking $2$ or more bottles may cause the number to
disappear, so the numbers won\'t do so. Also, as the potion can be quite
expensive, the group decides to buy as few as they can while making the
most amount of numbers to become square numbers. This is the most
effective way to do so!

How many bottles of potion should they buy?

### 输入描述

The input contains one line. The line consists of two integers $l,r\ (2\leq l\lt r\leq 10^{18})$ .

### 输出描述

An integer, the number of bottles of potion to buy.

### 示例1

#### 输入

```plain
2 9
```

#### 输出

```plain
2
```

#### 说明

In the interval $[2,9]$, there are two
numbers which need a bottle of potion: $2$ as $2+2=4=2^2$ and $6$ as $6+3=3^2$.
