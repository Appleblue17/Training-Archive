### J. 利物浦集合

啥都别想，直接大力。注意到第三个条件等价于要求集合里不能有 $k$ 个相同的数，于是题目所求即为：

$$f(n,m,k) = [x^{\varnothing} t^n] \prod\limits_{S \subseteq [m]} \Big[ (1+t^2+\cdots+t^{\leq k}) x^{\varnothing} + (t+t^3+\cdots+t^{\leq k}) x^S \Big]$$

记 $A = 1+t^2+\cdots+t^{\leq k}$，$B = t+t^3+\cdots+t^{\leq k}$。

按照 FWT xor 的矩阵，考虑 $S$ 的贡献：对于集合 $T$，若 $T \cdot S = 0$，则贡献为 $A+B$；否则贡献为 $A-B$。于是 FWT 后的集合幂级数为：

$$
g_T = (A+B)^{\#_S(S \cdot T = 0)} (A-B)^{\#_S(S \cdot T = 1)}=
\begin{cases}
(A+B)^{2^m} & ,T = \varnothing \\
(A+B)^{2^{m-1}} (A-B)^{2^{m-1}} & ,T \neq \varnothing
\end{cases}
$$

而 IFWT 后 $[x^{\varnothing}]$ 的系数就是所有 $g_T$ 的和再除 $2^m$：

$$[x^{\varnothing}] S = \dfrac{1}{2^m} \sum\limits_{T \subseteq [m]} g_T = \dfrac{1}{2^m} \left[ (A+B)^{2^m} + (2^m-1) (A+B)^{2^{m-1}} (A-B)^{2^{m-1}} \right]$$

记 $F(x) = 1+x+x^2+\cdots+x^k = \frac{1-x^{k+1}}{1-x}$，则 $A+B = F(x)$，$A-B = F(-x)$。

$$P(x) = (A+B)^{2^m} = F(x)^{2^m}$$

$$
\begin{aligned}
[x^n] P(x) &= [x^n] (1-x^{k+1})^{2^m} (1-x)^{-2^m} \\
&= [x^n] (1-x^{k+1})^{2^m} \sum\limits_{i \geq 0} \dbinom{2^m-1+i}{i} x^i \\
&= \sum\limits_{i=0}^{n/(k+1)} (-1)^i \dbinom{2^m}{(k+1)i} \dbinom{m-1+n-(k+1)i}{m-1}
\end{aligned}
$$

---

$$Q(x) = (A+B)^{2^{m-1}} (A-B)^{2^{m-1}} = F(x)^{2^{m-1}} F(-x)^{2^{m-1}}$$

$$Q(x) = (1-x^{k+1})^{2^{m-1}} (1-x)^{-2^{m-1}} \cdot (1-(-x)^{k+1})^{2^{m-1}} (1+x)^{-2^{m-1}}$$

这里需要分情况讨论：

- 若 $k$ 为奇数，则，

$$
\begin{aligned}
Q(x) &=  (1-x^{k+1})^{2^m} (1-x^2)^{-2^{m-1}} \\
&= (1-x^{k+1})^{2^m} \sum\limits_{i \geq 0} \dbinom{2^{m-1}-1+i}{i} x^{2i} \\
\end{aligned}
$$

- 若 $k$ 为偶数，则，

$$
\begin{aligned}
Q(x) &= (1-x^{2k+2})^{2^{m-1}} (1-x^2)^{-2^{m-1}} \\
&= (1-x^{2k+2})^{2^{m-1}} \sum\limits_{i \geq 0} \dbinom{2^{m-1}-1+i}{i} x^{2i} \\
\end{aligned}
$$

均可以在 $O(\min\{n,2^m\}/k)$ 内求出。

于是第一问就可以在 $O(\min\{n,2^m\}/k)$ 内求出。对于第二问，复杂度即为 $\sum_k O(n/k) = n \ln n$。