## F. Grid Survival

### 题目描述

Alice and Bob are playing a game with one piece on a grid board with $\textstyle n$ rows and $\textstyle m$ columns. The rules of the game
are as follows:

The grid in the $\textstyle l$-th line and
the $\textstyle c$-th column is called of
position $\textstyle (l,c)$ , and is colored
**white** when $\textstyle l$ and $\textstyle c$ have the same parity and
**black** when different.

The piece must be within a certain grid at any moment; in other words,
the position of the piece can also be represented by an integer pair $\textstyle (l,c)$ , which means that the
piece is in the grid of the $\textstyle l$-th
line and the $\textstyle c$-th column, and$\textstyle 1 \leq l \leq n,1 \leq c \leq m$ always holds.

On the board there are $\textstyle k$ grid(s)
specialized in advance, the $\textstyle i$-th
special grid is of position $\textstyle (l'_i,c'_i)$ and has a positive
integer value $\textstyle w_i$ .

The game lasts for a number of round(s) (starting with $\textstyle 1$):
- Initially, the board is empty and the piece is not placed yet;
- In the first round, Bob chooses a color $\textstyle col$ either white or black,
    and for each special grid (of the $\textstyle i$-th) , he can make it
    **active** at the cost of $\textstyle w_i$ or **inactive** with no
    cost;
- In the second round, Alice chooses an arbitrary grid of color $\textstyle col$ to place the piece;
- In the third round and further odd rounds, Bob must move the piece
    along the line by 1 unit, from position $\textstyle (l,c)$ to either $\textstyle (l+1,c)$ or $\textstyle (l-1,c)$. Note that after the
    move $\textstyle 1 \leq l \leq n$ should
    still be satisfied, and Bob can\'t leave the piece not moved in the
    round.
- In the fourth round and further even rounds, Alice must move the
    piece along the column by 1 unit, from position $\textstyle (l,c)$ to either $\textstyle (l,c-1)$ or $\textstyle (l,c+1)$. Similarly, after
    the move$\textstyle 1 \leq c \leq m$     should still be satisfied, and Alice can\'t leave the piece not
    moved in the round.

Whenever the piece lies in any **active** grid, Alice loses and Bob
wins; else if the game lasts for $\textstyle 10^{100}$ rounds (or forever),
Bob loses and Alice wins.

Assuming that both players are smart enough, and given the parameters of
the grid board ($\textstyle n$ and $\textstyle m$) and special grid(s)
($\textstyle l'_i,c'_i$ and $\textstyle w_i$); for each chosen color,
please calculate the minimal total cost for Bob to activate some special
grid(s) to win, or report that it\'s impossible.

Note that you may answer multiple queries.

### 输入描述

The first line contains the number of test cases$\textstyle t$ ($\textstyle 1 \leq t \leq 2 \times 10^5$).
The description of the test cases follows.

The first line contains three integers$\textstyle n,m,k$ ($\textstyle 2 \leq n,m \leq 10^6 , 0 \leq k \leq \min(2 \times 10^5,n \times m)$)
meaning as above;

Then following $\textstyle k$ lines, the $\textstyle i$-th line contains three
integers$\textstyle l'_i,c'_i$ ($\textstyle 1 \leq l'_i \leq n,1 \leq c'_i \leq m$)
and$\textstyle w_i$ ($\textstyle 1 \leq w_i \leq 10^9$),
representing the located row and column and the value of the $\textstyle i$-th special grid; it's
guaranteed that in the same test case no two special grids fall in the
same position
($\textstyle ~\forall~1 \leq i 

It's also guaranteed that the sum of $\textstyle k$ in each test file doesn't
exceed$\textstyle 2 \times 10^5$ ($\textstyle \sum k \leq 2 \times 10^5$);
note that there are no restrictions with the sum of $\textstyle n$ and $\textstyle m$ .

### 输出描述

For each test case, answer it on a full line, containing two integers
representing the answer for the chosen color (white or black in order):
the minimal total cost if possible, or $\textstyle -1$ if impossible.

### 示例1

#### 输入

```plain
7
2 3 4
1 1 52
1 2 33
2 1 47
2 2 95
2 3 2
1 2 90
1 3 30
5 5 4
4 2 30
4 4 10
2 4 40
2 2 20
6 6 4
6 2 10
6 4 10
1 3 10
1 5 10
5 6 4
5 2 10
5 4 10
1 3 10
1 5 10
11 5 5
2 1 1
2 3 1
6 3 1
10 3 1
10 5 1
2 2 0
```

#### 输出

```plain
33 33
90 90
40 30
-1 40
40 40
5 -1
-1 -1
```

