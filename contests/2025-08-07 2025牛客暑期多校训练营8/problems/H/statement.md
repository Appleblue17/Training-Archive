## H. Interval LRU

### 题目描述

Little Q is learning about a page replacement algorithm in operating
systems memory management\~\-- the LRU (Least Recently Used) algorithm.To help Little Q understand this algorithm, you need to answer some
questions regarding LRU in this problem. First, we briefly introduce the
principle of this algorithm:
- Set up a cache container of capacity$k$     to store loaded pages and related information. Initially, no pages
    are in the container.
- The system will sequentially process requests to access pages,
    handling one request at a time.
- For accessing a page that is already in the cache (i.e., a cache
    hit), use the cache directly as the data source and update the
    page\'s most recent access time.
- For accessing a page that is not in the cache (i.e., a cache miss),
    if the number of pages in the cache has reached $k$, first evict a page from the cache to
    ensure the number of pages in the cache is less than $k$, and then load the accessed page from
    its real address into the cache, using the cache as the data source
    and updating the page\'s most recent access time.
- Whenever a page needs to be evicted, choose the one with the
    earliest most recent access time to release from the cache.

Next, we use pages numbered from $1$ to $n$ and provide an array of length $n$, $[a_1, a_2, \ldots, a_n]$, along with $q$ queries, and you are asked to answer
these queries. Each query is one of the following two types:
- $1\ l\ r\ k$: Access the pages numbered $a_l, a_{l + 1}, \ldots, a_r$ in order,
    using an LRU cache with a maximum capacity of $k$, and report the number of cache hits.
- $2\ l\ r\ k$: Access the pages numbered $a_l, a_{l + 1}, \ldots, a_r$ in order,
    using an LRU cache, requiring that the number of cache hits is at
    least $k$, and report the minimum
    required LRU capacity. If the goal of
    [cache ]{style="font-family:\"font-size:medium;text-wrap-mode:wrap;background-color:#80FF80;text-decoration-line:underline;"}hits
    cannot be achieved, regard the capacity as $-1$.

### 输入描述

The first line contains an integer$T$ ($1 \leq T \leq 10^5$), indicating the number
of test cases.Then follow $T$ test cases. For each test
case:The first line contains two integers $n$ and$q$ ($1 \leq n, q \leq 10^5$).The second line contains $n$ integers$a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq n$).The next $q$ lines describe the queries, each
line of which contains four integers$t, l, r, k$ ($t \in \{1, 2\}, 1 \leq l \leq r \leq n, 1 \leq k \leq r - l + 1$),
representing a query of the $t$-th type
(parameters\' meaning are described above).It is guaranteed that the sum of $n$ and the
sum of $q$ over $T$ test cases do not exceed $2 \times 10^5$ and $2 \times 10^5$ respectively.

### 输出描述

For each test case, output $q$ lines, the $i$-th line of which contains an integer,
representing the answer to the $i$-th query.

### 示例1

#### 输入

```plain
1
8 8
1 2 1 3 2 4 2 1
1 1 8 1
1 1 8 2
1 1 8 3
1 1 8 4
2 2 7 1
2 2 7 2
2 3 8 2
2 1 8 3
```

#### 输出

```plain
0
2
3
4
2
3
4
3
```

