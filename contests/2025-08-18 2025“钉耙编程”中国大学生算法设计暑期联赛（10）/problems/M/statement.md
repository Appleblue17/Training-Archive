## M. Spring River Flower Moon Night

### Problem Description

![](https://cdn.luogu.com.cn/upload/image_hosting/z02qg1u0.png)

你现在要从江的一边移动到另外一边，即从 $\lparen 0,0 \rparen$ 移到 $\lparen n,m \rparen$。你可以在游泳和划船之间选择一个方式行进，即向右或向上移动，每种移动方式都有一个代价：
- 从 $\lparen x,y \rparen$ 游到 $\lparen x+1,y \rparen$，代价为 $y$；
- 从 $\lparen x,y \rparen$ 划到 $\lparen x,y+1 \rparen$，代价为 $x$。

现在给定$q$ 组询问，对于每组询问请求出对于这条江的最小移动代价。

### Input

第一行一个正整数 $q$（$1 \le q \le 10^5$），表示询问数。

接下来 $q$ 行，每行输入两个整数 $n,m$（$0 \le n,m \le 10^9$），表示一次询问。

### Output

输出 $q$ 行，每行一个整数，表示最小代价。

### Sample Input

```plain
1
1 1
```

### Sample Output

```plain
1
```

