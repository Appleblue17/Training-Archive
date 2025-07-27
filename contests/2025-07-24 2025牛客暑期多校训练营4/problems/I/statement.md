## I. I, Box

### 题目描述

[Sokoban is a puzzle video game franchise created by Hiroyuki Imabayashi
in 1981, in which players push boxes around a warehouse to designated
storage locations. Despite its simple rules, Sokoban exhibits intricate
and challenging behavior that has captivated both puzzle enthusiasts and
theoretical computer scientists. In 1996, Dorit Dor and Uri Zwick proved
that Sokoban is NP-complete, and in 1997, Joseph C. Culberson further
showed that it is PSPACE-complete. To this day, Sokoban remains popular
among players, and many modern puzzle games are inspired by its
mechanics, including Stephen\'s Sausage Roll, Baba Is You, and
Patrick\'s Parabox.]{style="text-wrap-mode:wrap;"}\
\
[Bobo was also recently playing Sokoban and found it incredibly hard to
complete a level. Feeling frustrated, he complained, \"Mature boxes
should learn to push themselves!\'\' And then, bing! The magic happened.
Suddenly, the pusher disappeared from Sokoban, and you can order boxes
to push themselves. Now, the game becomes much easier! \... Or does
it?]{style="text-wrap-mode:wrap;"}\
\
[Formally, you need to solve the following problem of Sokoban with No
Pushers:]{style="text-wrap-mode:wrap;"}\
\
[You are given an$n \times m$ two-dimensional grid surrounded by walls, which may also contain
additional internal walls. There are several boxes and target positions
on the grid. **The number of boxes equals the number of target
positions**. It is guaranteed that no box or target position occupies a
wall cell, and that all boxes and all target positions are located at
distinct places.]{style="text-wrap-mode:wrap;"}\
\
[You may repeatedly perform the following
operation:]{style="text-wrap-mode:wrap;"}\

<div>

[\
]{style="text-wrap-mode:wrap;"}

<div>
- [Select any box and move it one square in one of the four cardinal
    directions (up, down, left, or right), provided the destination is
    not a wall or another box.]{style="text-wrap-mode:wrap;"}

\
[Your task is to determine whether it is possible to move all boxes onto
target positions. If so, construct one such sequence of
moves.]{style="text-wrap-mode:wrap;"}\

</div>

</div>

### 输入描述

The first line of input contains two integers $n,m$ $(1\leq n,m\leq 50)$, denoting the height of
the map, the width of the map, and the number of boxes, respectively.\
\
Then $n$ lines follow, where each line
contains a string of $m$ characters, denoting
the map. Each character lies within the set of $\{$\`#\', \`.\', \`@\', \`\*\',
\`!\'$\}$, such that for the $j$-th $(1\leq j\leq m)$ character of the $i$-th $(1\leq i\leq n)$ string:\
\ $\bullet$ a  \`#\' character denotes that a
**wall** is at position $(i,j)$;\ $\bullet$ a \`.\' character denotes that
position $(i,j)$ is **vacant**;\ $\bullet$ a \`@\' character denotes that a
**box** is at position $(i,j)$;\ $\bullet$ a \`\*\' character denotes that a
**target position** is at position $(i,j)$;\ $\bullet$ a \`!\' character denotes that both
a **box** and a **target position** are at position $(i,j)$.\
\
\
The map is surrounded by walls. The input guarantees that the number of
boxes equals the number of target positions and there are at most $50$ boxes in the map.

### 输出描述

If no valid sequence that moves all boxes onto target positions exists,
output $-1$ in a line.\
\
Otherwise, output an integer $\ell$ $(0 \leq \ell \leq 10^5)$ on a single line,
representing the length of the move sequence. Then, output $\ell$ lines, each containing two integers
and a character: $x\ y\ c$ $(1 \leq x \leq n,\ 1 \leq y \leq m,\ c \in \{\texttt{L}, \texttt{R}, \texttt{U}, \texttt{D}\})$.
This denotes moving the box currently at position $(x, y)$ one step to the left, right, down,
or up, that is, to $(x, y{-}1)$, $(x, y{+}1)$, $(x{-}1, y)$, or $(x{+}1, y)$, respectively. Please note that
you should not move any box onto a wall or another box.\
\
\
If there are multiple valid sequences of moves, outputting any of them
would be considered correct. It can be shown that under the given
constraints, if any valid sequence of moves exists, then there exists
one such sequence within $10^5$ moves.

### 示例1

#### 输入

```plain
3 3
@.#
#.#
#.*
```

#### 输出

```plain
4
1 1 R
1 2 D
2 2 D
3 2 R
```

### 示例2

#### 输入

```plain
3 3
#@#
@!*
#*#
```

#### 输出

```plain
4
2 2 D
1 2 D
2 2 R
2 1 R
```

### 示例3

#### 输入

```plain
3 3
@#@
#..
**#
```

#### 输出

```plain
-1
```

