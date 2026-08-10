## B. Trimming Palindrome (trim)

### 题目描述

Violet Eye is a very cute girl with a unique perspective on things! Her
favorite thing is palindromic strings.She defines a value $g(s,t)$ (maybe zero) for
two **palindromic** strings, which represents the number of different
**palindromic** strings $u$ that satisfy $u$ is a suffix of $s$, and $t$ is a
suffix of $u$.Violet Eye has a palindromic string $s$ of
length $n$. One day, she idly selected a
**palindromic** substring from $s$ as string $t$. But this string looked too ugly! She
decided to trim it.She can trim the string any number of times (possibly zero):
each** trim** involves removing a **non-empty** prefix of the string,
leaving a **palindromic** suffix (maybe empty). However, she cannot trim
an empty string, meaning that she has to stop trimming once the string
becomes empty.Given an integer $m$ and three
arrays $a_1,a_2,a_3,\cdots,a_m$, $b_1,b_2,b_3,\cdots,b_m$, $c_0,c_1,c_2,\cdots,c_n$. Violet Eye\'s mood
changes during the trims. Specifically, when she trims the string from $U$ to $V$, she
gains **happiness** equal to $a_{\min(z,m)} \cdot g(U,V) + b_{\min(z,m)} c_{|V|}$,
in which $z$ is the number of different
strings $s'$ that satisfy $s'$ is a **palindromic** substring of $s$, and $V$ is a
suffix of $s'$.Please note that happiness might be negative.Violet Eye discovered that she could gain a lot of happiness! Now she
wants to know the maximum happiness she can achieve by **optimally
selecting string** $t$ **and performing
trimming operations**.

### 输入描述

The first line contains two integers$n,m$ ($1\le n<m\le 10^6$).The second line contains a palindromic string $s$ ($|s|=n$),
where $s$ **consists only of Latin lowercase
letters**.The third line contains $m$ integers
representing array$a_1, a_2, \dots, a_m$ ($|a_i|\le 2\times10^5$), with $a_i\le a_{i+1}$.The fourth line contains $m$ integers
representing array$b_1, b_2, \dots, b_m$ ($|b_i|\le 2\times10^5$).The fifth line contains $(n+1)$ integers
representing array$c_0, c_1, \dots, c_n$ ($|c_i|\le 2\times10^5$).

### 输出描述

A single integer representing the maximum happiness.

### 示例1

#### 输入

```plain
3 4
efe
-6 2 3 8
-3 -7 9 -2
9 -9 -1 4
```

#### 输出

```plain
67
```

### 示例2

#### 输入

```plain
10 11
nopqrrqpon
-989 -955 -878 -857 -826 -100 368 582 636 759 762
914 73 397 649 320 -621 -280 -321 -253 294 157
884 -397 -623 970 794 -724 223 -233 -74 629 488
```

#### 输出

```plain
141074
```

