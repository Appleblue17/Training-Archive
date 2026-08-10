## B. 预处理器

### Problem Description

yummy 正在写一个 C++ 程序，程序的开头有$n$ 行宏定义，具体地，对于 $1\le i \le n$，第 $i$ 行只可能是下面四种之一，其中 $a,b,x$ 均为数字：
- `#define Si x`，用 `N x` 来表示，保证 $0\le x<10^9+7$。
- `#define Si Sa<<Sb`，用 `< a b` 来表示。
- `#define Si Sa+Sb`，用 `+ a b` 来表示。
- `#define Si Sa*Sb`，用 `* a b` 来表示。

本题中，我们假定程序中的 `int`
类型可以存储任意大的数字而不发生溢出，并且 `a<<b` 完全等价于 $a\times 2^b$。

对于每个 $1\le i\le n$，计算
`cout<<(Si)<<endl;` 的输出对$10^9+7$ 取余的结果。

保证程序可以在有限时间内编译成功。

### Input

输入的第一行有一个正整数 $ n $（$ 1\le n\le 3\times 10^5 $），表示宏定义的行数。

之后$ n $ 行，每行有一个宏定义语句，格式见题目描述。

### Output

输出 $ n $ 行，每行一个自然数，其中第 $ i $ 行输出 `cout<<(Si)<<endl;` 的结果对 $ 10^9+7 $ 取余的结果。

### Sample Input

```plain
5
N 3
N 1
< 1 2
+ 5 5
* 3 3
```

### Sample Output

```plain
3
1
6
6144
48
```

### Hint

因为数值比较小，所以不会发生溢出。选手不难使用如下程序验证：

``` cpp
#define S1 3
#define S2 1
#define S3 S1
using namespace std;
int main(){
    cout<<(S1)<<endl;
    cout<<(S2)<<endl;
    cout<<(S3)<<endl;
    cout<<(S4)<<endl;
    cout<<(S5)<<endl;
    return 0;
}
```

