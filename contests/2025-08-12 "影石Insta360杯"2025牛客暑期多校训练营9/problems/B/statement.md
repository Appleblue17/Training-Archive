## B. Date

### 题目描述

::::: epigraph
*One and another moment accumulated will become a whole life.*

:::: epigraph-source
- -- Tomori

Looking at Anon, Tomori asked sincerely, "Can you form a band with me
for your whole life?" But Anon did not reply. After returning home
sadly, Tomori still wanted to know how long she could form a band with
Anon, so she found a string consisting of numbers from 0 to 9 and
counted the number of all the subsequences of legal dates in it, which
she believes to be the number of days she can form a band with Anon.
However, counting subsequences isn't a simple job, so Tomori asks you to
help her find this answer.

![image](https://uploadfiles.nowcoder.com/images/20250724/0_1753348814918/2311CC240C41D961D60944E531EB2E2F){style="width:500px;height:auto;"}Tomori asking Anon to form a band with her whole life.

Formally, you are given a string $\textstyle S$ consisting of only numbers
from 0 to 9, and you need to count all the subsequences in it which are
legal dates. Since the answer may be very big, you only need to output
the answer modulo $\textstyle 998244353$.

A *subsequence* of $\textstyle S$ is obtained
by deleting some number of elements (eventually, also zero) from $\textstyle S$, leaving the remaining
elements in their original order.

A *legal date* $\textstyle T$ is defined as
follows:
- $\textstyle |T| = 8$.
- The first four numbers in$\textstyle T$     denote the year $\textstyle Y$, then the
    following two numbers denote the month $\textstyle M$, then the following two
    numbers denote the day $\textstyle D$.
    For example, a legal date$\textstyle T$     with $\textstyle Y = 2025, M=4, D=20$ is $\textstyle 20250420$, and a legal date $\textstyle T$ with $\textstyle Y = 1, M=1, D=1$ is $\textstyle 00010101$.
- The year $\textstyle Y$ should satisfy $\textstyle 1 \le Y \le 9999$, and there
    are no further constraints on $\textstyle M$ and $\textstyle D$ except that the date must
    be a real, valid date.

In this problem, we use the common rules of leap year. A year is called
a *leap year* if and only if
- The year is divisible by $\textstyle 4$,
    and;
- The year is not divisible by $\textstyle 100$ unless it is also
    divisible by $\textstyle 400$.

Otherwise, the year is called a common year. For example, `2000` was a
leap year, but `1900` was a common year. The number of days in each
month is shown as the following table.

::: center
         **Month**          **01**   **02**   **03**   **04**   **05**   **06**   **07**   **08**   **09**   **10**   **11**   **12**
- ----------------------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- -------- --------
   **Days (Common Year)**     31       28       31       30       31       30       31       31       30       31       30       31
    **Days (Leap Year)**      31       29       31       30       31       30       31       31       30       31       30       31

::::
:::::

### 输入描述

The first line of input contains a single integer $\textstyle n (1 \le n \le 10^5)$ --- the
length of $\textstyle S$.

The second line contains a string $\textstyle S$ of length $\textstyle n$, consisting of only numbers
from 0 to 9.

### 输出描述

Output a single integer, which is the number of days Tomori can form a
band with Anon, modulo $\textstyle 998244353$.

### 示例1

#### 输入

```plain
8
20250420
```

#### 输出

```plain
1
```

### 示例2

#### 输入

```plain
8
00000101
```

#### 输出

```plain
0
```

### 示例3

#### 输入

```plain
8
00010101
```

#### 输出

```plain
1
```

### 示例4

#### 输入

```plain
10
0123401234
```

#### 输出

```plain
10
```

