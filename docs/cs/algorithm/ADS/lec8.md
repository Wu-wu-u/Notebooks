# lec8|Dynamic Programming

> "Those who cannot remember the past are condemned to repeat it."

- 拆分为子问题，然后将子问题的结果存入一个table

- 前面的**最优解**可以作用于后面的最优解


## 例：斐波那契数列

```c title="递归"
int Fib(int N){
    if(N<=1)
        return 1;
    else
        return Fib(N-1) + Fib(N-2);
}
```

```c title="优解"
int Fib(int N){
    int i, Last, NextToLast, Answer;
    if(N<=1) return 1;
    Last = NextToLast = 1;
    for (i = 2; i <= N; i++){
        Answer = Last + NextToLast;
        NextToLast = Last; Last = Answer;
    }
    return Answer
}
```

----

## 例：最优二叉搜索树

??? note "概念"
    - 最优二叉搜索树(Optimal Binary Search Tree)是仅用于**静态搜索**的最佳的二叉搜索树（它不能insert和delete）

？？？ 没听懂 搜视频看；好像是在连续的一坨点中，拿出一个作根，然后左右都是已经最优的子树，然后求出min；然后慢慢拆成了小的

也是可以调用先前的结果 P21

---

## 例：背包问题

??? tip "概念"
    - 背包问题，就是“抢劫问题”（

    - 在有限的空间内，装下最值钱的东西

小聪明之拆分成 $OPT(i,w)= \text{optimal value of knapsack problem with items} 1, …, i\text{subject to weight limit} w.$

![alt text](dp_1.png)
![alt text](dp_2.png)

？？？为什么$O(nW)$是伪多项式时间

---

## 例：矩阵连乘

??? tip "概念"
    p40

p42，原理和optimal bst差不多

补代码p43

## 例：Rod-cutting Problem

- 给定一根长度为 $N$ 的杆和一个价格表$P_L,L=1,2,...,M$，其中价格表 $P_i$ 表示长度为$i$的杆的价格。目标是将这根杆切割成若干段，使得这些段的总价格$R_N$最大化。

- 例如下面这个价格表：如果我们要卖一根长为8的杆，最佳的切法是分成长为2和6的部分；如果我们要卖一根长为3的杆，最好的办法就是不切割

|Length $L$|1|2|3|4|5|6|7|8|
|---|---|---|---|---|---|---|---|---|
|Price $P_L$|1|5|8|9|10|17|17|20|

!!! tip "状态转移方程"
    当$N\leq M$，$R_N=\text{max}\{P_N,\text{max}_{1\leq i \leq N}\{R_i+R_{N-i}\}\}$

    当$N > M$，$R_N=\text{max}_{1\leq i \leq N}\{R_i+R_{N-i}\}$

- 这个算法的时间复杂度为$O(N^2)$，因为有两个嵌套的循环，每层循环范围是$N$