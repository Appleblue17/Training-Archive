## World Finals 2022 Luxor Z. Archaeological Recovery

- 题意

设 $a_1,a_2, \cdots, a_n \in \mathbb{F}_3^k$，给定：

$$\prod\limits_{i=1}^n (1+x^{a_i})$$

求还原一组可能的 $\{a_i\}$。

---

#### Notations

- **点积**定义为两向量的对应元素乘积之和模 $3$；
- **垂直**表示两向量点积为 $0$，记作 $x \perp y$。
- $\omega_p$ 表示 $p$ 次单位根，下文的 $\omega$ 默认为 $\omega_3$。

### Part 1

记 $P = \prod\limits_{i=1}^n (1+x^{a_i})$。


直接对原式进行 FWT 得到 $Q = \text{FWT}(P)$。每一项对 $[x^S] Q$ 会产生三种贡献：

- 若 $a_i \cdot S = 0$，则贡献为 $1+1=2$；
- 若 $a_i \cdot S = 1$，则贡献为 $1+\omega=\omega_6$；
- 若 $a_i \cdot S = 2$，则贡献为 $1+\omega^2=-\omega_6$；

记以上三种的数量分别为 $g_{0,S}, g_{1,S}, g_{2,S}$，即：

$$g_{d,S} = \sum\limits_{i=1}^n [a_i \cdot S = d]$$

于是 $[x^S] Q$ 就是每一位上以上三种贡献乘起来。

$$[x^S] Q = 2^{g_{0,S}} \omega_6^{g_{1,S} - g_{2,S}}$$

复数乘法就是模长相乘，幅角相加。先考虑模长，注意到只有 $a_i \cdot S = 0$ 时模长为 $2$，剩下两种模长都为 $1$。于是通过模长就可以直接知道所有 $g_{0,S}$。

$$g_{0,S} = \log_2 |[x^S] Q|$$

### Part 2

$g_{0,S}$ 的含义即与其正交的向量数量：

$$g_{0,S} = \sum\limits_{T \perp S} f_T$$

现在的问题是：通过 $g_{0,S}$ 的信息能得到什么？

考虑直接对 $g_0$ 进行 FWT 得到 $G_0 = \text{FWT}(g_0)$：

$$G_{0,R} = \sum\limits_S g_S \omega^{R \cdot S} = \sum\limits_S \omega^{R \cdot S} \sum\limits_{T \perp S} f_T = \sum\limits_{T} f_T \sum\limits_{S \perp T} \omega^{R \cdot S}$$

记 $c_{0,T,R} = \sum\limits_{S \perp T} \omega^{R \cdot S}$，它实际上有简单形式。

---

**引理 1**

对于线性空间 $V \in \mathbb{F}_p^n$ 及其子空间 $U \subseteq V$ 和向量 $\bold u \in U$，有

$$
\sum\limits_{\bold x \in U} \omega_p^{\bold u \cdot \bold x} =
\begin{cases}
p^{\dim U} & \text{if } \bold u \in U^\perp \\
0 & \text{otherwise}
\end{cases}
$$

**证明**

- 若 $\bold u \in U^{\perp}$，则对于任意 $\bold x \in U$，$\bold u$ 均与 $\bold x$ 垂直。故原式值为 $|U|$。

- 若 $\bold u \notin U^{\perp}$，考虑任意一组 $U$ 的基底 $e_1,e_2,\cdots,e_t$，其中至少存在一个 $\bold e_i \cdot \bold u \neq 0$。

这样，任意 $\bold x \in U$ 可被表示为 $\bold x = \bold x_0 + c \bold e_i$，其中 $\bold x_0 \in \text{span} \{e_1,\cdots,e_{i-1},e_{i+1},\cdots,e_{t}\}$。

$$LHS = \sum\limits_{\bold x_0} \sum\limits_{c=0}^{p-1} \omega_p^{\bold u \cdot (\bold x_0 + c \bold e_i)} = \sum\limits_{\bold x_0} \omega_p^{\bold u \cdot \bold x_0} \sum\limits_{c=0}^{p-1} (\omega_p^{\bold u \cdot \bold e_i})^c = 0$$

其中最后一步为单位根反演公式。

---

于是，枚举的 $S \perp T$ 相当于考虑 $S \in \{T\}^{\perp}$。令 $U = \{T\}^\perp$，运用引理得：

$$
c_{0,T,R} = 
\begin{cases}
3^k & ,T = R = \bold 0 \\
3^{k-1} & ,T \neq \bold 0 \wedge R = \bold 0 / T / 2T \\
0 & ,\text{otherwise}
\end{cases}
$$

$$
G_{0,R} = 
\begin{cases}
3^k f_0 + 3^{k-1} \sum_{S \neq \bold 0} f_S & ,R = \bold 0 \\
3^{k-1}(f_R + f_{-R}) & ,\text{otherwise}
\end{cases}
$$

由于我们知道 $\sum_{S} f_S = n$，可以直接算出 $f_0$；对于其他 $R \neq \bold 0$，我们可以知道 $f_R + f_{-R}$ 的数量。至此，模长信息基本已经完全用上了。

下面的问题是：如何确定每对 $(R, -R)$ 的数量如何分配？

### Part 3

幅角信息并不好利用（因为知道的是实际值模 $6$ 的值）。回到原来的模型。假设我们先根据 $g_0$ 的信息猜测一组 $\{a_i\}$，考虑将某一个 $a_t$ 变成 $2a_t$ 时，所有 $2^n$ 种组合构成的可重集 $S$ 会发生什么变化：

- 原来：设除了 $a_t$ 的所有数 $2^{n-1}$ 种组合构成的可重集为 $T$，则 $S = T \times \{0, a_t\}$。

- 现在：$T$ 没有变化，$S' = T \times \{0, 2a_t\} = S' = T \times \{-a_t, 0\}$。

也就是说，$S'$ 可以由 $S$ 中每个元素减去 $a_t$ 得到。也就是说，
如果将猜测的 $\{a_i\}$ 对应的 $S$ 记作 $R$，设猜测的数里要变号的和为 $x$，那么 $P$ 就是 $R$ 每个数加上 $x$ 得到的可重集。

知道了这个关键的性质后，整个问题只需要完成三步：

1. 由猜测的 $\{a_i\}$ 计算出 $R$。
2. 计算哪些 $x$ 能够使 $P$ 和 $R$ 对上。
3. 计算哪些 $x$ 能够由猜测的 $\{a_i\}$ 组合出来，需要还原方案。

#### Part 3.1

现在，我们需要由 $f$ 快速计算出 $g_1$ 和 $g_2$。仍然进行 FWT 得到 $G_1, G_2$：

$$G_{d,R} = \sum\limits_S \omega^{R \cdot S} \sum\limits_{S \cdot T = d} f_T = \sum\limits_{T} f_T \sum\limits_{S \cdot T = d} \omega^{R \cdot S} \triangleq \sum\limits_{T} c_{d,T,R} f_T $$

---

$d \neq 0$ 时：

- 若 $T = \bold 0$，则不存在合法的 $S$ 使 $S \cdot T = d$，$c_{d,T,R} = 0$。
- 否则，一定可以找到向量 $S_0$ 使 $S_0 \cdot T = d$。令 $\Delta S = S - S_0$。

$$c_{d,T,R} = \sum\limits_{S \cdot T = d} \omega^{R \cdot S} = \sum\limits_{\Delta S \cdot T = 0} \omega^{R \cdot (S_0 + \Delta S)} = \omega^{R \cdot S_0} \sum\limits_{\Delta S \cdot T = 0} \omega^{R \cdot \Delta S}$$

由前面的结果，只有当 $R = cT$ 时后半部分才不为 $0$。

$$c_{d,T,R} = \omega^{c (T \cdot S_0)} \cdot 3^{n-1} = 3^{n-1} \omega^{cd}$$

总结：

$$
c_{d,T,R} = 
\begin{cases}
3^{k-1} \omega^{cd} & , T \neq \bold 0 \wedge R = \bold cT \\
0 & ,\text{otherwise}
\end{cases}
$$

$$G_{1,R} = 3^{k-1} (\omega f_R + \omega^2 f_{-R})$$

$$G_{2,R} = 3^{k-1} (\omega^2 f_R + \omega f_{-R})$$

于是，由 $f$ 可以快速计算出 $G_1, G_2$，进行 IFWT 即可获得 $g_1, g_2$；再按位填进 $\text{FWT}(R)$，做一遍即可 IFWT 获得 $R$。

#### Part 3.2

要找到哪些 $x$ 能够使 $P$ 和 $R$ 对上，实际上是一个类似哈希的做法。考虑差的平方：

$$h_S = \sum\limits_{T} (f_T - g_{T-S})^2 = \sum\limits_T f_T^2 + \sum\limits_T g_T^2 - 2 \sum\limits_T f_T g_{T-S}$$

做一遍差卷积即可。注意这里值域可能爆 $2^{64}$，可以考虑在模意义下检查。

#### Part 3.3

如果不要求还原方案，直接按照 [Part 3.1](#part-31) 的做法做即可。

要还原方案的话，似乎没有什么好做法。因为这里是三进制，如果某种 $a_i$ 只有一个的话，构成的就不一定是线性空间，不能用线性基判。

最简单粗暴的做法是直接分层 DP 并记录每个状态有没有把当前层的 $a_t$ 取反。时间复杂度 $O(n 3^k)$。

---

综合以上做法，总时间复杂度为 $O((n+k) 3^k)$。
