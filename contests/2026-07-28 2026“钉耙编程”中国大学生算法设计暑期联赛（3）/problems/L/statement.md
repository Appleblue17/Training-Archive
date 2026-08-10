## L. Shift Square

### Problem Description

在某星系观测计划中，天文台记录了 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个恒星碎片在二维平面中的初始位置，其中第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个碎片的位置为
[[[$$P_{i}\{ x_{i},y_{i}\}\text{。}$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[[P]{.mord .mathnormal
style="margin-right: 0.1389em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.1389em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[{]{.mopen}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[}]{.mclose}[。]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]]
受到中心引力源的影响，这些碎片会绕星系中心
[[$O\{ 0,0\}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[O]{.mord .mathnormal
style="margin-right: 0.0278em;"}[{]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[0]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]
以相同的角速度进行匀速旋转，且任意时刻所有点相对于原点的旋转角度相同。

天文台使用一个观测框对这些碎片进行持续观测。该观测框满足如下条件：
- 观测框为一个各边平行于坐标轴的正方形；
- 观测框必须完全覆盖所有碎片的位置；
- 观测框不必覆盖星系中心 [[$O\{ 0,0\}$][[[]{.strut
    style="height: 1em; vertical-align: -0.25em;"}[O]{.mord .mathnormal
    style="margin-right: 0.0278em;"}[{]{.mopen}[0]{.mord}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[0]{.mord}[}]{.mclose}]{.base}]{.katex-html
    aria-hidden="true"}]；
- 在所有满足覆盖条件的观测框中，选取周长最小的那个。

随着时间的推移，碎片不断旋转，观测框的大小也随之变化。观测系统在该时刻的能量消耗速率与观测框的周长成正比。

为了合理估计观测系统的能量消耗，你打算通过观测框周长对能量消耗进行估计。随着观测时间的增加，观测框周长的平均值会趋于某个值，你的任务是计算这个值。

形式化地说： 设在某一时刻碎片系统绕 [[$O$][[[]{.strut
style="height: 0.6833em;"}[O]{.mord .mathnormal
style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}] 点的旋转角度为
[[$\theta$][[[]{.strut
style="height: 0.6944em;"}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}]{.base}]{.katex-html
aria-hidden="true"}]，第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 个碎片的位置为
[[$\{ x_{i}^{\prime},y_{i}^{\prime}\}$][[[]{.strut
style="height: 1.0106em; vertical-align: -0.2587em;"}[{]{.mopen}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.4413em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.4413em; margin-left: -0.0359em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.7519em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2587em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[}]{.mclose}]{.base}]{.katex-html
aria-hidden="true"}]，其中
[[[$$x_{i}^{\prime} = x_{i}\cos\theta - y_{i}\sin\theta,$$][[[]{.strut
style="height: 1.0489em; vertical-align: -0.247em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.453em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8019em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.247em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[cos]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[sin]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[,]{.mpunct}]{.base}]{.katex-html
aria-hidden="true"}]]
[[[$$y_{i}^{\prime} = x_{i}\sin\theta + y_{i}\cos\theta\text{。}$$][[[]{.strut
style="height: 1.0489em; vertical-align: -0.247em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.453em; margin-left: -0.0359em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8019em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.247em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8444em; vertical-align: -0.15em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[sin]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[]{.mspace
style="margin-right: 0.2222em;"}[+]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.8889em; vertical-align: -0.1944em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[cos]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[。]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]]
定义此时所有点的横向宽度和纵向高度分别为
[[[$$W\{\theta\} = \underset{i = 1}{\overset{n}{\max}}x_{i}^{\prime} - \underset{i = 1}{\overset{n}{\min}}x_{i}^{\prime},$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[W]{.mord .mathnormal
style="margin-right: 0.1389em;"}[{]{.mopen}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[}]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.7596em; vertical-align: -0.7277em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.3723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3em;"}[max]{.mop}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[[[n]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.6306em; margin-left: 0em;"}]{.vlist
style="height: 1.032em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.7277em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.453em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8019em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.247em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.9969em; vertical-align: -0.7277em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.3723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3em;"}[min]{.mop}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[[[n]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.8679em; margin-left: 0em;"}]{.vlist
style="height: 1.2693em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.7277em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.453em; margin-left: 0em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8019em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.247em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}]{.base}]{.katex-html
aria-hidden="true"}]]
[[[$$H\{\theta\} = \underset{i = 1}{\overset{n}{\max}}y_{i}^{\prime} - \underset{i = 1}{\overset{n}{\min}}y_{i}^{\prime}\text{。}$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[H]{.mord .mathnormal
style="margin-right: 0.0813em;"}[{]{.mopen}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[}]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1.7596em; vertical-align: -0.7277em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.3723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3em;"}[max]{.mop}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[[[n]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.6306em; margin-left: 0em;"}]{.vlist
style="height: 1.032em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.7277em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.453em; margin-left: -0.0359em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8019em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.247em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.9969em; vertical-align: -0.7277em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[i]{.mord .mathnormal .mtight}[=]{.mrel
.mtight}[1]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.3723em; margin-left: 0em;"}[[]{.pstrut
style="height: 3em;"}[min]{.mop}]{style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[[[n]{.mord .mathnormal .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.8679em; margin-left: 0em;"}]{.vlist
style="height: 1.2693em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.7277em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[y]{.mord
.mathnormal style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.453em; margin-left: -0.0359em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[′]{.mord .mtight}]{.mord .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -3.113em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8019em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.247em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[。]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]]
由于观测框必须是正方形，所以最小正方形的边长为
[[[$$L\{\theta\} = \max\{ W\{\theta\},H\{\theta\}\}\text{。}$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[L]{.mord
.mathnormal}[{]{.mopen}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[}]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[max]{.mop}[{]{.mopen}[W]{.mord
.mathnormal style="margin-right: 0.1389em;"}[{]{.mopen}[θ]{.mord
.mathnormal
style="margin-right: 0.0278em;"}[}]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[H]{.mord .mathnormal
style="margin-right: 0.0813em;"}[{]{.mopen}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[}}]{.mclose}[。]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]] 因此该时刻观测框的周长为
[[[$$Q\{\theta\} = 4L\{\theta\}\text{。}$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[Q]{.mord
.mathnormal}[{]{.mopen}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[}]{.mclose}[]{.mspace
style="margin-right: 0.2778em;"}[=]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[4]{.mord}[L]{.mord
.mathnormal}[{]{.mopen}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[}]{.mclose}[。]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]] 你的任务是计算下面的值：
[[[$$\underset{T\rightarrow + \infty}{\lim}\frac{1}{T}\int_{0}^{T}Q\{\theta\}\ d\theta\text{。}$$][[[]{.strut
style="height: 2.5032em; vertical-align: -0.9119em;"}[[[[[[]{.pstrut
style="height: 3em;"}[[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}[→]{.mrel .mtight}[+]{.mord
.mtight}[∞]{.mord .mtight}]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.3557em; margin-left: 0em;"}[[]{.pstrut
style="height: 3em;"}[lim]{.mop}]{style="top: -3em;"}]{.vlist
style="height: 0.6944em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.8027em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mop
.op-limits}[]{.mspace style="margin-right: 0.1667em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[T]{.mord
.mathnormal
style="margin-right: 0.1389em;"}]{.mord}]{style="top: -2.314em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[1]{.mord}]{.mord}]{style="top: -3.677em;"}]{.vlist
style="height: 1.3214em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.686em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[[∫]{.mop .op-symbol .large-op
style="margin-right: 0.4445em; position: relative; top: -0.0011em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.7881em; margin-left: -0.4445em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[T]{.mord .mathnormal .mtight
style="margin-right: 0.1389em;"}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.8129em; margin-right: 0.05em;"}]{.vlist
style="height: 1.5912em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.9119em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[Q]{.mord
.mathnormal}[{]{.mopen}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[}]{.mclose}[ ]{.mspace}[d]{.mord
.mathnormal}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[。]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]]

### Input

输入包含多组测试数据。

第一行包含一个整数
[[$t\text{（}1 \leq t \leq 10\text{）}$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[t]{.mord
.mathnormal}[（]{.mord .cjk_fallback}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[t]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[10]{.mord}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]，表示测试数据的组数。

下面是 [[$t$][[[]{.strut
style="height: 0.6151em;"}[t]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 组数据，对于每组测试数据：

第一行包含一个整数
[[$n\text{（}2 \leq n \leq 2 \times 10^{5},\text{）}$][[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[（]{.mord .cjk_fallback}[2]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[n]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.7278em; vertical-align: -0.0833em;"}[2]{.mord}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 1.0085em; vertical-align: -0.1944em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]，表示恒星碎片的数量。

接下来 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行，每行包含两个整数
[[$x_{i},y_{i}\text{（} - 10^{8} \leq x_{i},y_{i} \leq 10^{8}\text{）}$][[[]{.strut
style="height: 0.8778em; vertical-align: -0.1944em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[（]{.mord .cjk_fallback}[]{.mspace
style="margin-right: 0.2222em;"}[−]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.9501em; vertical-align: -0.136em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[8]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8304em; vertical-align: -0.1944em;"}[[x]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[i]{.mord
.mathnormal .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[[y]{.mord .mathnormal
style="margin-right: 0.0359em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[i]{.mord .mathnormal .mtight}]{.sizing
.reset-size6 .size3
.mtight}]{style="top: -2.55em; margin-left: -0.0359em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.15em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[8]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}[）]{.mord
.cjk_fallback}]{.base}]{.katex-html aria-hidden="true"}]，表示第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
个恒星碎片的初始坐标。

保证同一组测试数据内，所有点两两不同。

### Output

对于每组测试数据，输出一行一个实数，表示观测框周长的长期平均值。
当你的答案与标准答案的相对误差或绝对误差不超过
[[$10^{- 6}$][[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[[−]{.mord .mtight}[6]{.mord .mtight}]{.mord
.mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 时，视为正确。

### Sample Input

```plain
3
2
0 0
1 0
4
0 0
0 2
0 3
0 5
4
0 0
1 0
1 1
0 1
```

### Sample Output

```plain
3.601265264628424
18.006326323142121
5.092958178940651
```

### Hint

对于第一组数据，两个点之间的距离为 [[$1$][[[]{.strut
style="height: 0.6444em;"}[1]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。 旋转过程中，最小正方形的边长为
[[[$$\max\{\mid\cos\theta\mid,\mid\sin\theta\mid\},$$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[max]{.mop}[{]{.mopen}[∣]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[cos]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[∣]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[∣]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[sin]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[∣]{.mord}[}]{.mclose}[,]{.mpunct}]{.base}]{.katex-html
aria-hidden="true"}]] 所以平均周长为
[[[$$\frac{1}{2\pi}\int_{0}^{2\pi}4\max\{\mid\cos\theta\mid,\mid\sin\theta\mid\},d\theta\frac{8\sqrt{2}}{\pi} \approx 3.601265264628\text{。}$$][[[]{.strut
style="height: 2.4962em; vertical-align: -0.9119em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[2]{.mord}[π]{.mord
.mathnormal
style="margin-right: 0.0359em;"}]{.mord}]{style="top: -2.314em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[1]{.mord}]{.mord}]{style="top: -3.677em;"}]{.vlist
style="height: 1.3214em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.686em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[[∫]{.mop .op-symbol .large-op
style="margin-right: 0.4445em; position: relative; top: -0.0011em;"}[[[[[[]{.pstrut
style="height: 2.7em;"}[[0]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -1.7881em; margin-left: -0.4445em; margin-right: 0.05em;"}[[]{.pstrut
style="height: 2.7em;"}[[[2]{.mord .mtight}[π]{.mord .mathnormal .mtight
style="margin-right: 0.0359em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3 .mtight}]{style="top: -3.8129em; margin-right: 0.05em;"}]{.vlist
style="height: 1.564em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.9119em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[max]{.mop}[{]{.mopen}[∣]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[cos]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[∣]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[∣]{.mord}[]{.mspace
style="margin-right: 0.1667em;"}[sin]{.mop}[]{.mspace
style="margin-right: 0.1667em;"}[θ]{.mord .mathnormal
style="margin-right: 0.0278em;"}[∣]{.mord}[}]{.mclose}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[d]{.mord .mathnormal}[θ]{.mord
.mathnormal style="margin-right: 0.0278em;"}[[]{.mopen
.nulldelimiter}[[[[[[]{.pstrut style="height: 3em;"}[[π]{.mord
.mathnormal
style="margin-right: 0.0359em;"}]{.mord}]{style="top: -2.314em;"}[[]{.pstrut
style="height: 3em;"}[]{.frac-line
style="border-bottom-width: 0.04em;"}]{style="top: -3.23em;"}[[]{.pstrut
style="height: 3em;"}[[8]{.mord}[[[[[[]{.pstrut
style="height: 3em;"}[2]{.mord
style="padding-left: 0.833em;"}]{.svg-align
style="top: -3em;"}[[]{.pstrut
style="height: 3em;"}[![](data:image/svg+xml;base64,PHN2ZyBoZWlnaHQ9IjEuMDhlbSIgcHJlc2VydmVhc3BlY3RyYXRpbz0ieE1pbllNaW4gc2xpY2UiIHZpZXdib3g9IjAgMCA0MDAwMDAgMTA4MCIgd2lkdGg9IjQwMGVtIj48cGF0aCBkPSJNOTUsNzAyCmMtMi43LDAsLTcuMTcsLTIuNywtMTMuNSwtOGMtNS44LC01LjMsLTkuNSwtMTAsLTkuNSwtMTQKYzAsLTIsMC4zLC0zLjMsMSwtNGMxLjMsLTIuNywyMy44MywtMjAuNyw2Ny41LC01NApjNDQuMiwtMzMuMyw2NS44LC01MC4zLDY2LjUsLTUxYzEuMywtMS4zLDMsLTIsNSwtMmM0LjcsMCw4LjcsMy4zLDEyLDEwCnMxNzMsMzc4LDE3MywzNzhjMC43LDAsMzUuMywtNzEsMTA0LC0yMTNjNjguNywtMTQyLDEzNy41LC0yODUsMjA2LjUsLTQyOQpjNjksLTE0NCwxMDQuNSwtMjE3LjcsMTA2LjUsLTIyMQpsMCAtMApjNS4zLC05LjMsMTIsLTE0LDIwLC0xNApINDAwMDAwdjQwSDg0NS4yNzI0CnMtMjI1LjI3Miw0NjcsLTIyNS4yNzIsNDY3cy0yMzUsNDg2LC0yMzUsNDg2Yy0yLjcsNC43LC05LDcsLTE5LDcKYy02LDAsLTEwLC0xLC0xMiwtM3MtMTk0LC00MjIsLTE5NCwtNDIycy02NSw0NywtNjUsNDd6Ck04MzQgODBoNDAwMDAwdjQwaC00MDAwMDB6Ij48L3BhdGg+PC9zdmc+)]{.hide-tail
style="min-width: 0.853em; height: 1.08em;"}]{style="top: -2.8672em;"}]{.vlist
style="height: 0.9072em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.1328em;"}]{.vlist-r}]{.vlist-t .vlist-t2}]{.mord
.sqrt}]{.mord}]{style="top: -3.677em;"}]{.vlist
style="height: 1.5842em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.686em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.mfrac}[]{.mclose .nulldelimiter}]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≈]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.6833em;"}[3.601265264628]{.mord}[。]{.mord
.cjk_fallback}]{.base}]{.katex-html
aria-hidden="true"}]]

