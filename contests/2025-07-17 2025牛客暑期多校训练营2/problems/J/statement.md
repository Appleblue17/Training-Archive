## J. Just Curve it

### 题目描述

Sean is glad that he has already finished grading all his students\'
tests. But he is no longer glad when he sees the final scores. How low
they are!

Luckily for both Sean and his students, the dean\'s office allows Sean
to \"curve\" the scores to make the scores \"look better\" as long as
higher scores are still higher.

The scores are in the range $[1,100]$ , and
there are two classic operators used in curving:

- Type 1: $f_1(x)=kx+b$ , where$10^{-2}\leq k\leq 1, 0\leq b\leq 10^4, k+b\geq 1$ .
- Type 2: $f_2(x)=\sqrt{x}$ .

After curving, Sean will map the curved score into the target score
range, which we don\'t really care for now.

Sean has an array of operators of length$n$ : $[g_1,g_2,\dots,g_n]$, each of them is
either Type 1 or Type 2.

Each time, [to test the curving result, Sean tries the functions with a
new initial
value ]{style="text-wrap-mode:wrap;"}$x$. He
chooses a subarray of the operator array $[g_l,g_{l+1},\dots,g_r]$, and uses the
operators like this:

- Initiate $a_0$ with $x$. 
- Calculate the variables $a_1,a_2,\dots,a_{r-l+1}$ using the
  following equations: $a_1=g_l(a_0),a_2=g_{l+1}(a_1),\dots,a_{r-l+1}=g_{r}(a_{r-l})$.

<div>

As Sean is way too busy and lazy to do this, he asks you to help him. To
know about the curving result and make sure you fully follow his
process, he asks you about both$a_{r-l+1}$ and $\sum\limits_{i=1}^{r-l+1}a_i$. Sean may
change some of the operators between the two times he asks questions.
Can you handle it?

<div>

<div>

</div>

</div>

</div>

### 输入描述

<div>

The first line contains an integer $n\ (1\leq n\leq 10^5)$, the length of the
operator array.

</div>

<div>

</div>

<div>

Each line from the $2$-nd to
the $(n+1)$-th contains a line that
represents the function $g_i$. Each line can
be of two forms:

</div>

<div>

</div>

<div>

1. $1\ k\ b$: The operator is Type
1. $kx+b\ (10^{-2}\leq k\leq 1, 0\leq b\leq 10^4, k+b\geq 1)$ . $k,b$ are
two decimals, and there are
exactly $2$ decimal places after the decimal
point for
both $k$ and $b$ .

</div>

<div>

</div>

<div>

2. $2$: The operator is Type
2. $\sqrt{x}$ .

</div>

The $(n+2)$-th line contains an
integer $q\ (1\leq q\leq 10^5)$, the number
of queries.

<div>

Each line from the $(n+3)$-th to
the $(n+q+2)$-th contains a query. The query
is in one of the given two forms:

</div>

<div>

</div>

<div>

1. $1\ l\ r\ x\ (1\leq l\leq r\leq n, 1\leq x\leq 100)$:
Type 1 query. Asking about $a_{r-l+1}$ and $\sum\limits_{i=1}^{r-l+1}a_i$ for the
operator subarray$[g_l,g_{l+1},\dots,g_r]$ with initial value $x$ . $l, r, x$ are all integers.

</div>

<div>

</div>

<div>

2. $2\ idx\ op\ (1\leq idx\leq n)$: Type 2
query. Changing the $idx$-th operator
into $op$,
where $op$ is given in the form of operators.

</div>

### 输出描述

For each Type 1 query, output two values:

Since the answers are not necessarily integers, if the real answer is $ans$, your answer $ans'$ is considered correct if $\frac{|ans-ans'|}{\max(1, ans)}\leq 10^{-4}$.

### 示例1

#### 输入

```plain
5
1 1.00 10.00
2
1 0.50 50.00
2
1 0.95 20.00
5
1 1 5 80
2 3 2
1 1 5 80
2 4 1 0.35 65.00
1 3 5 100
```

#### 输出

```plain
27.02893543 188.65806431
21.66726225 125.98917842
85.07500000 163.57500000
```

#### 说明
