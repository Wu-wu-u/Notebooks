# Randomized Algorithm

## 例：The Hiring Problem

- 我们现在打算雇佣一个人，先进行面试后进行聘用，其中Interview和Hiring都有相应的cost:$C_i << C_h$；假设一共雇佣了M个人，那么总的cost就是$O(NC_i+MC_h)$

```cpp title="Naive Solution"
// 只雇佣更强的人
int Hiring (EventType C[], int N){
    int Best = 0;
    int BestQ = the quality of candidate 0;
    for(int i = 1; i <= N; i++){
        Qi = interview(i); //Ci
        if(Qi > BestQ){
            BestQ = Qi;
            Best = i;
            hire(i)       //Ch
        }
    }
    return Best;
}
// 但是这个naive做法的worst case很坏,O(NCh)
```

!!! tip "考虑申请者以随机顺序到来的统计学视角"
    - 记X = 雇佣的人数

    - $X=\sum X_i$，其中$X_i = 0/1$表示第$i$人是否被雇佣

    - 然后我们雇佣的原则是雇佣最强的人，那么第$i$人被雇佣的概率，就是他是前i人里最强的概率，也就是$\frac{1}{i}$

    - $E(X)=\sum_{i=1}^n \frac{1}{i} = \text{ln}N + O(1)$

    - total cost = $O(C_h\text{ln}N+NC_i)$

---

- 如果candidate比较聪明，他们在来之前就预先按照了从弱到强的顺序进来，那么这就worst，所以我们手动**加入随机因子**，来使得order确实是随机的

```cpp title="Randomized Algorithm"
int RandomizedHiring (EventType C[], int N){
    int Best = 0;
    int BestQ = the quality of candidate 0;

    randomly permute the list of candidates;

    for(int i=1; i<=N; i++){
        Qi = interview(i);
        if(Qi > BestQ){
            BestQ = Qi;
            Best = i
            hire(i);
        }
    }
}
```

---

??? tip "随机排序的实现"
    - 方法一：我们可以给每个元素A[i]分配一个随机的数字**random priority**，然后再排序
        ```cpp
        void PermuteBySorting (ElemType A[], int N){
            for(int i=1; i<=N; i++)
                A[i].P = 1+rand()%(N^3);
            Sort A by P
        }
        ```

---

### Online Hiring Algorithm

- Online Hiring Algorithm -- hire only once：每一个候选人马上决定雇佣与否，如果雇佣了一个人，那么在他之后的人都不再看

- 那么我们就会很纠结，我怎么知道第一个人好不好呢？一开始好的标准是什么呢？

- 所以，我们先拿先$K$个人进行练手，这些炮灰仅用来帮我恒量best的标准，并不会被雇佣；后面$K+1 \sim N$个人才是我正在开始选人的阶段

```cpp
int OnlineHiring (EventType C[], int N, int k){
    int Best = N;
    int BestQ = -∞;
    for(int i=1; i<=k; i++){
        Qi = interview();
        if(Qi > BestQ) BestQ = Qi;
    }
    for (i=k+1;i<=N;i++){
        Qi = interview();
        if(Qi > BestQ){
            Best = i;
            break;
        }
    }
    return Best;
}
```

- 假设$S_i$是最优秀的人，如果我们想要雇佣到他，有两个条件：

    1. 他不能在前$K$个人中，必须在$K+1\sim N$

    2. $K+1\sim i-1$中，不能出现比前$K$个人优秀的存在

- 这个算法经过一通概率和数学计算之后，可以算出，选出最优秀的人的概率为$\frac{1}{e}\sim 1-\frac{1}{e}$

## 例：Quicksort

- **确定性**的快排（**Deterministic Quicksort**）有着$O(N^2)$的worst-cast time；$O(N\text{log}N)$的average time

- 快排中有一个worst case：当我们选择的pivot很差，导致pivot一侧的数太少，那么接下来的分治就会很差；所以我们就采用随机算法来优化快排

---

- **central splitter**: 好的pivot使得每一侧至少含有$\frac{4}{n}$的数据

- **Modified Quicksort**: 在开始**分治之前**，我们要尽量选出一个**central splitter**

- **Claim**：找到一个central splitter的迭代次数的期望**是2次**（因为central splitter落在$N/4 \sim 3N/4$之间）

- 另一个结论：对于$type~j$子问题，每一类问题的总开销是$O(N)$，然后一共有$\text{log}_{4/3}N$个*type*，所以总的开销就是$O(N\text{log}N)$



