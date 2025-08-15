## I. 乘法逆元

### Problem Description

对于一个素数 $ p $，我们知道，对于任意正整数 $ 0<a<p $，存在唯一的正整数 $ 0 < x < p $ 使得 $ ax\equiv 1\pmod p $，称为 $ a $ 的乘法逆元，记为 $ \operatorname{inv} \left( a \right) $。

本题中，你需要计算 $ \bigoplus \limits_{i=1}^{p-1} \left( \operatorname{inv} \left( i \right)+2^k \right) \left(i+4^k \right) $，其中 $ k = \lceil \dfrac{p}{119} \rceil $。

由于结果可能过大，你只需要输出答案对素数$ 998244353 = 119 \times 2^{23}+1 $ 求余的结果即可。

### Input

**本题有多组测试数据。** 输入的第一行有一个正整数 $T$（$ 1\le T\le 100 $），表示数据组数。

接下来有 $ T $ 行，每行有一个正整数 $ p $（$ 2\le p\le 10^{12} $，保证 $ p $ 是素数），表示一个询问。

### Output

对于每组数据输出一行，表示上述算式的答案除以 $ 998244353 $ 的余数。

### Sample Input

```plain
1
3
```

### Sample Output

```plain
23
```

### Hint

$ k= \lceil \dfrac{3}{119} \rceil = 1$。 $i=1$ 对应 $(1+2^1)\times (1+4^1)=15$。 $i=2$ 对应 $(2+2^1)\times (2+4^1)=24$。

这两个数的异或和是 $23$。

