## H. VI Civilization

### 题目描述

In the game VI Civilization, the player needs to achieve a science
victory: accumulating at least$\textstyle s$ science points in the science victory slot within $\textstyle t$ turns.

There are $\textstyle n$ technologies in the
game. Initially, only the first technology, $\textstyle Tech_1$, is unlocked and can be
completed. All other technologies are locked. The player must complete
the technologies in a fixed sequence: $\textstyle Tech_1 \rightarrow Tech_2 \rightarrow \dots \rightarrow Tech_n$.
This order cannot be skipped or changed. Specifically, technology $\textstyle Tech_i$ is unlocked only after
all preceding technologies 
($\textstyle Tech_1$ to $\textstyle Tech_{i-1}$)  have been
completed.

Completing each technology requires a certain amount of science points.
The player can allocate production to trigger the technology's
\"Eureka\" moment, which reduces the science points required for
completion.**Each technology's Eureka can only be triggered once**. Upon
completing a technology, the science points gained per turn will
increase.

Each technology $\textstyle Tech_i$ has four
parameters: $\textstyle a_i$: The science points required
to complete this technology. $\textstyle k_i$: The increase in science
points per turn after completion. $\textstyle b_i$: The production required to
trigger its Eureka.

 $\textstyle c_i$: The reduction in required
science points after triggering the Eureka
($\textstyle 0 \leq c_i 

VI Civilization is a turn-based game. In each turn, the player first
gains science points and production, and then allocates them. The
allocation of science points and production must be **indivisible
(cannot be split among multiple tasks)**, and the science points and
production gained in the current turn **are not saved for the next
turn**.

The game proceeds as follows:

At the start of each turn, the player gains:

Science points $\textstyle m$ (after
completing technology $\textstyle i$, $\textstyle m$ permanently increases by $\textstyle k_i$).

A fixed amount of production$\textstyle p$ (remains constant throughout the game).

Then, the player performs actions:

**Science Point Allocation:**

1.  Allocate the entire amount of science points $\textstyle m$ gained this turn to either
    an unlocked technology or the science victory slot.

2.  When allocating to a technology, any excess points are wasted and do
    not carry over to the next technology. After completing technology $\textstyle Tech_i$, $\textstyle m$ permanently increases by $\textstyle k_i$.

3.  When allocated to the science victory slot, the points are directly
    added to its total.

**Production Allocation:**

1.  Allocate the entire amount of production $\textstyle p$ gained this turn
    **indivisibly (cannot be split among multiple Eurekas)** to the
    Eureka of **any technology (regardless of whether the technology is
    unlocked)**.

2.  When allocating to a Eureka, any excess production is wasted. After
    a Eureka is triggered, the science point required to complete the
    corresponding technology is reduced.

Find the minimum non-negative integer production $\textstyle p$ such that there exists a
strategy to achieve the science victory (accumulating $\textstyle \geq s$ science points in the
science victory slot) within$\textstyle t$ turns. If it's impossible to win within $\textstyle t$ turns, output $\textstyle -1$.

### 输入描述

The first line contains three integers $\textstyle m$, $\textstyle s$, and$\textstyle t$ ($\textstyle 1 \leq m \leq 100$, $\textstyle 1 \leq s \leq 10^9$, $\textstyle 1 \leq t \leq 100$).

The second line contains an integer$\textstyle n$ ($\textstyle 0 \leq n \leq 100$).

The next $\textstyle n$ lines each contain
four integers $\textstyle a_i$, $\textstyle k_i$, $\textstyle b_i$, and$\textstyle c_i$ ($\textstyle 1 \leq a_i \leq 10^6$, $\textstyle 0 \leq k_i \leq 1000$, $\textstyle 1 \leq b_i \leq 10000$, $\textstyle 0 \leq c_i

### 输出描述

Output the minimum non-negative integer $\textstyle p$. If it is impossible to win
within $\textstyle t$ turns, output $\textstyle -1$.

### 示例1

#### 输入

```plain
10 100 9
2
50 10 20 25
60 10 30 20
```

#### 输出

```plain
4
```

#### 说明

In the sample case, a valid strategy for $\textstyle p=4$ is as follows:

**Turn 1:** Gain 10 science and 4 production. Allocate production to $\textstyle Tech_1$'s Eureka and science to $\textstyle Tech_1$.

**Turn 2:** Gain 10 science and 4 production. Allocate production to $\textstyle Tech_1$'s Eureka and science to $\textstyle Tech_1$.

**Turn 3:** Gain 10 science and 4 production. Allocate production to $\textstyle Tech_1$'s Eureka and science to $\textstyle Tech_1$.

**Turn 4:** Gain 10 science and 4 production. Allocate production to $\textstyle Tech_1$'s Eureka and science to
the science victory slot.

**Turn 5:** Gain 10 science and 4 production. Allocate production to $\textstyle Tech_1$'s Eureka and science to
the science victory slot. At this turn, $\textstyle Tech_1$'s Eureka has accumulated $\textstyle 20$ production, triggering the
Eureka. The science cost for $\textstyle Tech_1$ is now $\textstyle 50-25=25$. Since $\textstyle 30$ science points have already
been allocated, $\textstyle Tech_1$ is
completed. The science per turn increases to $\textstyle 10+10=20$.

**Turn 6:** Gain 20 science and 4 production. Allocate science to the
science victory slot.

**Turn 7:** Gain 20 science and 4 production. Allocate science to the
science victory slot.

**Turn 8:** Gain 20 science and 4 production. Allocate science to the
science victory slot.

**Turn 9:** Gain 20 science and 4 production. Allocate science to the
science victory slot. 

The science victory slot has accumulated a total of$\textstyle 10 (\text{T4}) + 10 (\text{T5}) + 20 (\text{T6}) + 20 (\text{T7}) + 20 (\text{T8}) + 20 (\text{T9}) = 100$ science points. Science victory is achieved!

### 示例2

#### 输入

```plain
22 970 8
3
85 24 9 27
81 20 85 44
30 80 75 7
```

#### 输出

```plain
-1
```

