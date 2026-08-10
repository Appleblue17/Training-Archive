## A. AVL tree

### 题目描述

Riceshower is an umamusume in the training center, and she is having a
data structure class!

In the data structures class, she learned about AVL trees. An AVL tree
is a type of binary search tree that is balanced based on its height.
The height of a binary tree $\textstyle \mathcal{T}$ is defined as
follows:
- If $\textstyle \mathcal{T}$ is empty,
    then $\textstyle h_\mathcal{T} = 0$;
- Otherwise, let the root of $\textstyle \mathcal{T}$ be $\textstyle u$, and let $\textstyle ls_u$ and $\textstyle rs_u$ represent the left and
    right subtrees of $\textstyle u$ (which
    may be empty). In this case, $\textstyle h_\mathcal{T} = \max(h_{ls_u}, h_{rs_u}) + 1$.

A rooted binary tree$\textstyle \mathcal{T}$ is called an AVL tree if and only if:
- $\textstyle \mathcal{T}$ is empty, or
- Let the root of$\textstyle \mathcal{T}$     be $\textstyle u$, and both the left
    subtree $\textstyle ls_u$ and the right
    subtree $\textstyle rs_u$ (which may be
    empty) of $\textstyle u$ are AVL trees,
    and $\textstyle |h_{ls_u} - h_{rs_u}| \leq 1$.

Now, Riceshower is given a binary tree with root $\textstyle 1$. However, it may not be an AVL
tree. She hopes to transform the tree into an AVL tree. She can perform
the following operations any number of times:
- Delete a leaf.
- Choose a vertex whose left son is empty and create a new vertex as
    its left son.
- Choose a vertex whose right son is empty and create a new vertex as
    its right son.

She wants to know the minimum number of operations needed to make the
tree an AVL tree.

### 输入描述

Each test contains multiple test cases. The first line contains the
number of test cases $\textstyle T~(1 \le T \le 10000)$.

For each testcase, the first line contains one integer $\textstyle n~(1 \le n \le 2 \times 10^5)$,
the number of vertices of the tree.

The $\textstyle i$-th of the next following $\textstyle n$ lines contains two integers $\textstyle ls_i, rs_i~(0 \le ls_i, rs_i \le n)$,
representing the left son and the right son of vertex $\textstyle i$. If the left son or right son
is empty, it is represented by $\textstyle 0$.

It is guaranteed that the given tree is a binary tree with root $\textstyle 1$, and $\textstyle \sum n \le 2 \times 10^5$.

### 输出描述

For each testcase, output one integer -- how many operations at least
she needs to make this tree an AVL tree.

### 示例1

#### 输入

```plain
3
3
0 2
3 0
0 0
4
0 2
3 4
0 0
0 0
5
0 2
3 0
4 0
0 5
0 0
```

#### 输出

```plain
1
1
3
```

