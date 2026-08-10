## B. Dice Tower

### Problem Description

联合演出结束后，Ave Mujica
的舞台机关还没有拆。睦留下了一批骰子道具，祥子想把它们堆成一座能从观众席各个方向看到的骰子塔；一旁的爱音则认真研究起怎样摆才能让露出的点数更多。

骰子可以逐个旋转，塔的形状却已经固定。请帮她们算出最终能看到的点数之和最大是多少。

祥子在舞台平面上画出了一个 [[$n$][[[]{.strut
style="height: 0.4306em;"}[n]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行 [[$m$][[[]{.strut
style="height: 0.4306em;"}[m]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 列的网格。第
[[$i$][[[]{.strut style="height: 0.6595em;"}[i]{.mord
.mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 行第
[[$j$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
aria-hidden="true"}] 列的位置上堆着若干个完全相同的单位骰子。

从正上方看，第 [[$i$][[[]{.strut
style="height: 0.6595em;"}[i]{.mord .mathnormal}]{.base}]{.katex-html
aria-hidden="true"}] 行第 [[$j$][[[]{.strut
style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
.mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
aria-hidden="true"}] 列的骰子塔高度为
[[$h_{i,j}$][[[]{.strut
style="height: 0.9805em; vertical-align: -0.2861em;"}[[h]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
.mathnormal .mtight}[,]{.mpunct .mtight}[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，也就是说这个位置上堆了
[[$h_{i,j}$][[[]{.strut
style="height: 0.9805em; vertical-align: -0.2861em;"}[[h]{.mord
.mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
.mathnormal .mtight}[,]{.mpunct .mtight}[j]{.mord .mathnormal .mtight
style="margin-right: 0.0572em;"}]{.mord .mtight}]{.sizing .reset-size6
.size3
.mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
.vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个骰子。

所有骰子都与网格对齐，且同一个格子里的骰子上下紧贴摆放；若麦试图把它们摆歪，会被祥子立刻制止。

每个骰子的 [[$6$][[[]{.strut
style="height: 0.6444em;"}[6]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个面分别有
[[$1,2,3,4,5,6$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[6]{.mord}]{.base}]{.katex-html
aria-hidden="true"}] 个点，且相对两面的点数和为
[[$7$][[[]{.strut
style="height: 0.6444em;"}[7]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。睦提醒大家，骰子各个面的相对位置固定：初始时，上、下、前、后、左、右六个面的点数依次为
[[$1,6,2,5,3,4$][[[]{.strut
style="height: 0.8389em; vertical-align: -0.1944em;"}[1]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[6]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[2]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[5]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[3]{.mord}[,]{.mpunct}[]{.mspace
style="margin-right: 0.1667em;"}[4]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]；之后只能通过旋转改变朝向，不能将骰子翻成镜像。

爱音可以任意旋转每个骰子，并且不同骰子的朝向可以不同。

相邻两个骰子贴在一起的面不会露出。一个骰子对答案的贡献等于它所有露出面的点数之和。

请你帮爱音求出所有骰子的贡献之和最大可以是多少。

### Input

第一行包含一个整数 [[$T$][[[]{.strut
style="height: 0.6833em;"}[T]{.mord .mathnormal
style="margin-right: 0.1389em;"}]{.base}]{.katex-html
aria-hidden="true"}]（
[[$1 \leq T \leq 10^{5}$][[[]{.strut
style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8193em; vertical-align: -0.136em;"}[T]{.mord
.mathnormal style="margin-right: 0.1389em;"}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[5]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]），表示测试数据个数。

对于每组测试数据：
- 第一行包含两个整数 [[$n,m$][[[]{.strut
    style="height: 0.625em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[m]{.mord
    .mathnormal}]{.base}]{.katex-html
    aria-hidden="true"}]（[[$1 \leq n,m \leq 10^{3}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[1]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8304em; vertical-align: -0.1944em;"}[n]{.mord
    .mathnormal}[,]{.mpunct}[]{.mspace
    style="margin-right: 0.1667em;"}[m]{.mord .mathnormal}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[3]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]）。
- 接下来 [[$n$][[[]{.strut
    style="height: 0.4306em;"}[n]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    行，每行包含 [[$m$][[[]{.strut
    style="height: 0.4306em;"}[m]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}]
    个整数，第 [[$i$][[[]{.strut
    style="height: 0.6595em;"}[i]{.mord
    .mathnormal}]{.base}]{.katex-html aria-hidden="true"}] 行第
    [[$j$][[[]{.strut
    style="height: 0.854em; vertical-align: -0.1944em;"}[j]{.mord
    .mathnormal style="margin-right: 0.0572em;"}]{.base}]{.katex-html
    aria-hidden="true"}] 个整数为
    [[$h_{i,j}$][[[]{.strut
    style="height: 0.9805em; vertical-align: -0.2861em;"}[[h]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[j]{.mord .mathnormal
    .mtight style="margin-right: 0.0572em;"}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]（
    [[$0 \leq h_{i,j} \leq 10^{9}$][[[]{.strut
    style="height: 0.7804em; vertical-align: -0.136em;"}[0]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.9805em; vertical-align: -0.2861em;"}[[h]{.mord
    .mathnormal}[[[[[[]{.pstrut style="height: 2.7em;"}[[[i]{.mord
    .mathnormal .mtight}[,]{.mpunct .mtight}[j]{.mord .mathnormal
    .mtight style="margin-right: 0.0572em;"}]{.mord .mtight}]{.sizing
    .reset-size6 .size3
    .mtight}]{style="top: -2.55em; margin-left: 0em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.3117em;"}[​]{.vlist-s}]{.vlist-r}[[]{.vlist
    style="height: 0.2861em;"}]{.vlist-r}]{.vlist-t
    .vlist-t2}]{.msupsub}]{.mord}[]{.mspace
    style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
    style="margin-right: 0.2778em;"}]{.base}[[]{.strut
    style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
    style="height: 2.7em;"}[[9]{.mord .mtight}]{.sizing .reset-size6
    .size3
    .mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
    style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
    aria-hidden="true"}]）。

保证对于所有测试数据，
[[$\sum n \times m \leq 10^{6}$][[[]{.strut
style="height: 1em; vertical-align: -0.25em;"}[∑]{.mop .op-symbol
.small-op style="position: relative; top: 0em;"}[]{.mspace
style="margin-right: 0.1667em;"}[n]{.mord .mathnormal}[]{.mspace
style="margin-right: 0.2222em;"}[×]{.mbin}[]{.mspace
style="margin-right: 0.2222em;"}]{.base}[[]{.strut
style="height: 0.7719em; vertical-align: -0.136em;"}[m]{.mord
.mathnormal}[]{.mspace
style="margin-right: 0.2778em;"}[≤]{.mrel}[]{.mspace
style="margin-right: 0.2778em;"}]{.base}[[]{.strut
style="height: 0.8141em;"}[1]{.mord}[[0]{.mord}[[[[[[]{.pstrut
style="height: 2.7em;"}[[6]{.mord .mtight}]{.sizing .reset-size6 .size3
.mtight}]{style="top: -3.063em; margin-right: 0.05em;"}]{.vlist
style="height: 0.8141em;"}]{.vlist-r}]{.vlist-t}]{.msupsub}]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

### Output

对于每组测试数据，输出一行一个整数，表示该组测试数据中露出面的最大点数之和。

### Sample Input

```plain
2
2 2
1 2
3 4
3 4
0 2 0 1
3 1 4 0
0 2 2 5
```

### Sample Output

```plain
156
314
```

### Hint

样例中的两组测试数据分别对应原来的两座骰子塔。第一组的普通外表面积为
[[$34$][[[]{.strut
style="height: 0.6444em;"}[34]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]，但本题计算的是露出面上的点数之和。通过合理旋转每个骰子，可以使露出面的点数之和达到
[[$156$][[[]{.strut
style="height: 0.6444em;"}[156]{.mord}]{.base}]{.katex-html
aria-hidden="true"}]。

最底层的骰子的下表面也计入答案。

