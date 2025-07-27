## E. Echoes of 24

### 题目描述

::::::: {style="text-wrap-mode:wrap;"}
**Please note the special memory limit of this problem.**\

:::::: {style="text-wrap-mode:wrap;"}
\

::::: {style="text-wrap-mode:wrap;"}
![](https://uploadfiles.nowcoder.com/images/20250708/0_1751963254497/F51C29794E630AF10DD08BC2804348B9){style="height:auto;width:236px;"}\

:::: {style="text-wrap-mode:wrap;"}
This is Tachibana Kanade. She is very cute.\

\
[In the quiet afterlife, where forgotten memories echo like distant
bells, a vast Tree connects every soul\'s
regret.]{style="text-wrap-mode:wrap;"}\
\
[Tachibana Kanade, the silent guardian, awakens in the center of this
realm. Each node on the Tree holds a
number ]{style="text-wrap-mode:wrap;"}$a_i$[ \-\--
fragments of emotion, unresolved wishes, and fading
light.]{style="text-wrap-mode:wrap;"}\
\
[To awaken her scattered friends, Kanade must walk from
node ]{style="text-wrap-mode:wrap;"}$l$[ to
node ]{style="text-wrap-mode:wrap;"}$r$[,
tracing a simple path. The values along this path
are ]{style="text-wrap-mode:wrap;"}$w_1, w_2, \dots, w_k$[.
She starts with the counter set
to ]{style="text-wrap-mode:wrap;"}$w_1$[.]{style="text-wrap-mode:wrap;"}\
\
[At each of the
next ]{style="text-wrap-mode:wrap;"}$k-1$[ steps,
she will:]{style="text-wrap-mode:wrap;"}\
\ $\bullet$[ Increase the step index by
1,]{style="text-wrap-mode:wrap;"}\ $\bullet$[ Choose to
either ]{style="text-wrap-mode:wrap;"}**add**[ or ]{style="text-wrap-mode:wrap;"}**multiply**[ the
counter by the current
value ]{style="text-wrap-mode:wrap;"}$w_{id}$[.]{style="text-wrap-mode:wrap;"}\
\
[Her mission: reach
exactly ]{style="text-wrap-mode:wrap;"}$24$[,
the number that symbolizes a complete day \-\-- 24 hours of precious
time, 24 echoes of unspoken memories.]{style="text-wrap-mode:wrap;"}\
\
[Some queries ask whether such a path can yield 24. Others alter the
memory fragments themselves.]{style="text-wrap-mode:wrap;"}\
\
[Can Kanade rewrite fate and reach that quiet resolution once
more?]{style="text-wrap-mode:wrap;"}Echoes of 24

::::
:::::
::::::
:::::::

### 输入描述

The first line contains two
integers $n$ and $q$ $( 1 \le n,q \le 5\times 10^5 )$ \-\--
the number of nodes in the tree and the number of queries.\
\
The second line
contains $n$ integers $a_1,a_2,\dots,a_{n} (1\le a_i \le 10^9)$ \-\--
the memory values stored at each node.\
\
Then follow $n-1$ lines, each containing two
integers $u$ and $v$ \-\--
indicating an undirected edge between
nodes $u$ and $v$.\
\

<div>

Then $q$ lines follow, each representing one
of the following two types of queries:

</div> $\quad \circ$ $\texttt{1 l r}$:
check if path
from $l$ to $r$ can
yield 24,\ $\quad \circ$ $\texttt{2 x d}$:
update value at
node $x$ to $d$.

### 输出描述

For each query of type $\texttt{1 l r}$,
output one line:\ $\bullet$ $\texttt{1}$ if
the path can reach value 24,\ $\bullet$ $\texttt{0}$ otherwise.

### 示例1

#### 输入

```plain
9 8
1 3 1 2 4 6 5 2 2
1 2
1 3
2 4
2 5
3 6
3 7
6 8
7 9
1 4 8
1 4 9
1 2 8
1 6 9
1 9 6
2 3 8
1 6 9
1 9 6
```

#### 输出

```plain
1
1
0
1
0
0
1
```

### 示例2

#### 输入

```plain
8 8
3 2 3 3 1 3 1 2
2 1
3 2
4 1
5 2
6 4
7 6
8 7
2 4 4
1 8 2
2 5 2
1 2 4
1 5 2
2 1 3
1 4 8
2 6 2
```

#### 输出

```plain
1
1
0
1
```

### 备注

<div>

Constraints:

</div>

<div> $\bullet$ $1 \le n,q \le 5\times 10^5$\ $\bullet$ $1 \le a_i,d \le 10^9$\

</div>

<div> $\bullet$$1 \le l,r,x \le n$ 
</div>

