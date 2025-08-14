## C. Hexagis (hexagis)

### 题目描述

Here are some definitions before the problem statement.
- Two squares in the square grid are **adjacent** iff they share
    exactly one side.
- Two squares in the square grid are **reachable** iff there exists a
    sequence of squares, where the two squares are the first and the
    last term of the sequence respectively, and each pair of adjacent
    squares in the sequence is adjacent in the square grid.
- A subset of the square grid is **4-connected** iff every pair of
    squares in the subset is reachable in the subset after deleting all
    squares not included in the subset. A 4-connected subset is also
    called a **block**.

There are seven kinds of **tetrominoes** in the popular game \'tetris\'.
They are all the possible shapes of four 4-connected squares in the
square grid, where shapes that are able to coincide after some
translation and rotation are considered the same.

![](https://uploadfiles.nowcoder.com/images/20250810/0_1754803277411/0BB019BEE24E0AEADD76439E006874C4){style="height:auto;width:240px;"}

(seven kinds of tetrominoes in \'tetris\')

However, you consider \'tetris\' too easy. That\'s because there are few
kinds of tetrominoes used in \'tetris\'. As a result, few combinations
of tetrominoes can be formed, making the game quite simple. Now, you\'ve
made up your mind to play a similar but more difficult game:
\'hexagis\'.There are $60$ kinds of **hexominoes** in the
game \'hexagis\'. They are all the possible shapes of six 4-connected
squares in the square grid, where shapes that are able to coincide after
some translation and rotation are considered the same.The goal is to fit these hexominoes in a $19 \times 19$ square grid, using exactly one
hexomino of each kind. At the same time, every square except the central
square should be covered by exactly one hexomino.This game is significantly harder, as you scratched your head but found
no solution. So you decided to share the game with your friend. To your
surprise, he claimed that he solved the game as soon as he saw it. To
prove his words, he gave you $T$ solutions he
found. Unfortunately, you discovered that all of his solutions were
wrong by finding out how many hexominoes of each kind were used in each
of his solutions.Now he begins to believe that no solution exists. Can you find one to
prove him wrong?

### 输入描述

The input contains $19T+1$ lines:
- The first line
    contains $T$ ($1\le T\le500$),
    indicating the number of your friend\'s solutions.
- After the first line follow $19T$ lines,
    the $19k+i-18$ -th
    ($1\le k\le T,1\le i\le19$) line of the
    input contains a
    string $S_{k,i}$ consisting
    of $19$ characters, indicating
    the $i$ -th row of
    the $k$ -th solution of your friend.

In the $k$ -th solution, the tenth character
of $S_{k,10}$ ($1\le k\le T$)
is \'.\', while the rest of the characters are number digits.
4-connected characters with the same number represent a block of your
friend\'s solution.

### 输出描述

Your output should contain $T+19$ lines:
- If the $k$ -th
    ($1\le k\le T$) solution of your friend
    contains a block that is not a hexomino,
    output $-1$ in
    the $k$ -th line. Otherwise,
    output $60$ non-negative
    integers $a_{k,1},a_{k,2},a_{k,3},\cdots,a_{k,60}$,
    indicating the numbers of the $60$ types
    of hexominoes used in the solution in **non-increasing order**.
- Then you should output $19$ more lines,
    the $T+i$ -th line in your output
    ($1\le i\le19$) should contain a
    string $R_i$ consisting
    of $19$ characters, indicating
    the $i$ -th row of your solution.

You have to make sure that the tenth character
of $R_{10}$ is \'.\', while the rest of the
characters are number digits. 4-connected characters with the same
number represent a block of your solution. Any output violating the form
above or not satisfying the requirements of a real solution will be
considered as Wrong Answer.If multiple solutions exist, output any.

### 示例1

#### 输入

```plain
2
0001114545454001100
0001114545454001100
1110004545454001100
1110004545454110011
0001114545454110011
0001114545454110011
4444443222222444444
5555553001113555555
4444443001113444444
555555300.003555555
4444443111003444444
5555553111003555555
4444442222223444444
1100114545454111000
1100114545454111000
1100114545454000111
0011004545454000111
0011004545454111000
0011004545454111000
3141592653589793238
4626433832795028841
9716939937510582097
4944592307816406286
2089986280348253421
1706798214808651328
2306647093844609550
5822317253594081284
8111745028410270193
852110555.964462294
8954930381964428810
9756659334461284756
4823378678316527120
1909145648566923460
3486104543266482133
9360726024914127372
4587006606315588174
8815209209628292540
9171536436789259036
```

#### 输出

```plain
32 28 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
-1
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
000000000.000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
0000000000000000000
```

#### 说明

The first solution of your friend
contains $32$ hexominoes on the left
and $28$ hexominoes on the right shown in the
image below.

![](https://uploadfiles.nowcoder.com/images/20250810/0_1754803679056/D37AF07FFF6F6393980676013C7C2975){style="height:auto;width:240px;"}

The second solution of your friend contains blocks that are not
hexominoes.However, in the sample output, your solution does **not** satisfy the
requirements of a real solution. Thus, the sample output will be
considered as Wrong Answer.

