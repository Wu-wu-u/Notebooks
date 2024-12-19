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

- Online Hiring Algorithm -- hire only once：每一个候选人马上决定雇佣与否，如果雇佣了一个人，那么在他之后的人都不再看
