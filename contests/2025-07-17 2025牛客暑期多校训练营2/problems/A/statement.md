## A. Another Day of Sun

### 题目描述

[\'Cause morning rolls around, and it\'s another day of
sun!]{style="text-wrap-mode:wrap;"}

[But as a sleep addict, Sean spends lots of hours sleeping, and thus, he
can\'t even remember which day it is when he wakes
up.]{style="text-wrap-mode:wrap;"}

[So starting from someday, he started taking notes: when he wakes up, he
writes a number about whether there\'s sunlight outside. If there is, he
will write
a ]{style="text-wrap-mode:wrap;"}$1$[ on it;
otherwise, he will write
a ]{style="text-wrap-mode:wrap;"}$0$[ . And
after taking notes, without enough time for sunlight to fade or for
moonlight to dim, he falls asleep again. We assume that every time Sean
wakes up, he sees either the sunlight or the moonlight, but not
both.]{style="text-wrap-mode:wrap;"}

[So the notes actually form an array of
length ]{style="text-wrap-mode:wrap;"}$n$[ : ]{style="text-wrap-mode:wrap;"}$[a_1,a_2,\dots,a_n]\ (\forall 1\leq i\leq n, 0\leq a_i\leq 1)$[ ,
where ]{style="text-wrap-mode:wrap;"}$a_i$[ represents
the ]{style="text-wrap-mode:wrap;"}$i$[-th
number Sean wrote.]{style="text-wrap-mode:wrap;"}

[However, as time goes on, some numbers written become ambiguous and are
just impossible to identify, and you can\'t really tell whether it is
a ]{style="text-wrap-mode:wrap;"}$1$[ or
a ]{style="text-wrap-mode:wrap;"}$0$[ . So if
there
are ]{style="text-wrap-mode:wrap;"}$k$[ numbers
that you can\'t identify, there can
be ]{style="text-wrap-mode:wrap;"}$2^k$[ different
arrays.]{style="text-wrap-mode:wrap;"}

<div>

[For each array, you can calculate the minimum number of days on which
Sean sees the sunlight at least once that is consistent with the notes
the array represents. If you add the results of different arrays
together, what will you get? ]{style="text-wrap-mode:wrap;"}As the
answer can get quite enormous, output it
modulo $998\ 244\ 353$ .

<div>

<div>

Note that we only care about the minimum number of days when the notes
with number $1$ are taken.

</div>

</div>

</div>

### 输入描述

Each test contains multiple test cases. The first line contains the
number of test cases $T\ (1≤T≤10^4)$ .

Each test case consists of two lines.

The first line contains one integer $n\ (2\leq n\leq 5\times 10^5)$, the number
of notes.

The second line contains $n$ integers $a_1,a_2,\dots,a_n\ (-1\leq a_i\leq 1)$, each
number written on the note. The number is unknown if and only if $a_i=-1$.

It is guaranteed that $\sum n$ over all test
cases in one test will not exceed $5\times 10^5$.

### 输出描述

For each test case, output $1$ integer: the
sum of results modulo $998\ 244\ 353$ .

### 示例1

#### 输入

```plain
3
3
1 0 1
3
0 0 0
3
1 -1 1
```

#### 输出

```plain
2
0
3
```

#### 说明

In the first test case, when Sean takes the first note and the third
note, the sun he has seen must have been of $2$ different days.

<div>

In the second test case, Sean never sees the sun, so the answer is $0$.

</div>

<div>

</div>

<div>

In the third test case, the array can
be $[1,1,1]$ or $[1,0,1]$. If the array
is $[1,1,1]$, the notes can be taken in the
same day, so Sean could have seen the daylight of the same day, and the
result is $1$. If the array is $[1,0,1]$, the first and third notes must
have been taken in different days, so there are at least $2$ days of sun that Sean has seen. So the
answer is $1+2=3$.

</div>
