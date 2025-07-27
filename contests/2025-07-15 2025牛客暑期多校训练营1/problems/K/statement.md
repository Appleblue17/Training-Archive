## K. Museum Acceptance

### 题目描述

There is a big museum consisting of $n$ rooms
and some bidirectional corridors. There are at most $3$ doors in each room, and the corridor
outgoing from the room is behind the door. All corridors outgoing from a
single room lead to different rooms. The whole museum is connected,
i.e., it is possible to walk between any two rooms, possibly passing
through other rooms along the way.\
\
You are to help in setting labels on doors that will make the tour
through the whole museum much easier. The idea is that if a room $u$ has$d_u$ doors leading through corridors to other rooms, these doors are labeled
with numbers $1, 2, \ldots, d_u$, then all
visitors will follow a simple procedure. If they are in room $u$ at the very beginning of their tour, they
will choose the door labeled with $1$ and
pass through the corresponding corridor. If they are in room $u$ and they entered it from the corridor
through the door labeled with $i$, they will
pick the door labeled with the next number (i.e., $i + 1$ if $i < d_u$ and$1$ if $i = d_u$) and pass through the
corresponding corridor.\
\
Now we have already set a labeling, and you need to find the number of
different corridors that the visitors will pass through if they start
the tour in each room, assuming they follow the rules, do not get bored
easily, and walk long enough.\

### 输入描述

The first line contains an integer$n$ ($3 \le n \le 2 \times 10^5$), indicating the
number of rooms in the museum.\
\
The next $n$ lines contain a description of
all corridors, the $u$-th of which describes
corridors connecting the $u$-th room with
others. It begins with an integer$d_u$ ($1 \le d_u \le 3$), the number of doors in
this room. Then $d_u$ integers$v_1, v_2, \ldots, v_{d_u}$ ($1 \le v_i \le n$, $v_i \ne u$, and $v_i \ne v_j$ if $i \ne j$) follow, giving numbers of rooms
that those doors lead to, in the order of their assigned labels.\
\
Note that all corridors are bidirectional, so if there is a door from
room $u$ to room $v$, there is a door from room $v$ to room $u$ as
well.\

### 输出描述

Output $n$ lines, the $i$-th of which contains the number of
different corridors that the visitors will pass through if they start
the tour in room $i$.\

### 示例1

#### 输入

```plain
6
3 4 2 3
3 5 1 3
3 6 1 2
1 1
1 2
1 3
```

#### 输出

```plain
5
4
5
5
4
5
```

### 示例2

#### 输入

```plain
4
2 2 4
2 1 3
2 2 4
2 1 3
```

#### 输出

```plain
4
4
4
4
```

