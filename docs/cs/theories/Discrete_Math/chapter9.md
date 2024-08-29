# Chap 9
Relations

## 关系的数量

!!! note "关键"
    一个从A到B的二元关系是 $A\times B$ 的子集

??? examples:
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2094.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2095.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2096.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2097.png)

    - 尤其反对称，对角线上任意 所以 $2^n$;
    - 然后对称位置有3种可能，然后考虑下三角，共有      

    - $\frac{(1+n-1)(n-1)}{2}=n(n-1)$项

## Property

=== "symmetric(对称性)"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2098.png)

=== "Antisymmetric（反对称性）"

    - $对于任意 a，b \in A，若(a，b)\in R且(b，a)\in R，一定有a=b，则称定义在集合A 上的关系R 为反对称的。$

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2099.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20100.png)

    - 就是说这个矩阵不能有对称相同的两个点，只有3种对角情况

=== "reflexive（自反性）"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20101.png)

=== "irreflexive（非自反性）"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20102.png)

=== "transitive（传递性）"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20103.png)

## 关系的组合

!!! warning "注意" 
    $R1\oplus R2=R1\cup R2 - R1\cap R2$

### 关系的合成

- 有点像嵌套函数

??? note "定义"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20104.png)

??? note "Examples"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20105.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20106.png)

    - 所有的通过两条有向边的路径

    - $\circ$后的关系是 在内层，所以由它出发

??? note "幂"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20107.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20108.png)

## Closures of Relations 
（关系的闭包）

- **闭包是，包含R，具有性质P，的最小关系**

!!! abstract "证明步骤"

    1. 包含R
    2. 具有什么性质
    3. 最小关系，证明给定集合 $S \subset R'$ ， $R'$是具有这个关系的集合

=== "Reflexive Closure 自反闭包"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20109.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20110.png)

    - 用 $r(R)=R\cup I_A$表示

=== "Symmetric Closure 对称闭包"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20111.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20112.png)

    - 思路都是：考虑一对(a,b)在R和R’各自的情况，都能推导出要的结论

=== "Transitive Closure 传递闭包"

    ??? note "定理"

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20113.png)

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20114.png)

    ??? note "连通性关系"

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20115.png)

    ??? Tip "Example-Prove: $t(R)=R^*$"

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20116.png)

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20117.png)

        - Step3:

        - 给定包含R的传递关系为S
        - 关键 $S^n\subset S$

    ??? "引理"

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20118.png)

        如果warshall得到的传递关系和原关系相同就说明原关系传递

### Warshall’s Algorithm

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20119.png)

- 我们先考虑原先想要计算传递闭包，也就是要计算 $M_R,M_R^{[2]}…M_R^{[n]}$

- 那么 对于除 $M_R$以外的n-1个01矩阵的计算，

- $M^{[2]}_{ij}= \lor_{k=1} (M_{ik} \land M_{kj})$ 此处有n次与、n-1次或

- 对于 $n \times n$的矩阵，每个矩阵的计算就是 $n^2(2n-1)$

- 所以 $T(n)=n^2(2n-1)(n-1)=O(n^4)$

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20120.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20121.png)

- 传递闭包本就是 从 $V_1 -V_n$ 的所有路径可能，

- 那么每层循环 Mt[i,j]保留（逻辑加）

- 然后通过 Mt[i,k]&Mt[k,j]实现一层又一层的 路过 $V_1…V_n$，完成所有路径可能

## Equivalence Relations 等价关系

- **同时满足自反，对称，传递的关系**

### Equivalence Classes等价类

??? note "定义"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20122.png)

---

??? note "定理"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20123.png)

??? note "关于证明"

    1. 由(i)推(ii)，关键在于 证明 $有x \in [a]时，也有 x \in [b]$

---

!!! note "**集合的划分**"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20124.png)

    - $pr(A)={A_i|i\in I}$

    - 满足三个条件:

    1. $A_i \neq \phi \text{ for } i \in I (I \text{ is an index set})$
    2. $A_i \cap A_j = \phi$
    3. $\forall a \in A, \exist i \text{ such that } a \in A_i (i=1,2,…)\\ 即 \cup _{i\in I}A_i=A$

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20125.png)

??? Tip "证明"

    1.证明 R的等价类 构成 Pr(A)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20126.png)

    2.证明 给定划分，R是一个等价关系

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20127.png)

---

??? note "Examples"
    === "E.g.1"
        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20128.png)

        划分就是 `Components`


    === "E.g.2"
        求一个集合的等价关系数（等同于可别物件，不可别盒子）

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20129.png)

---

### The Operations of equivalence relations

!!! note "定理"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20130.png)

    - 自反性，对称性，传递性都易证明

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20131.png)

    ??? note "Example"
        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20132.png)

        - 所以我们能推出 $(R_1\cup R_2)^*$是等价关系

### mod 定理

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20133.png)

- 证明 modulo 是等价关系

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20134.png)

## Partial Ordering 偏序

- **自反的，反对称的，传递的**

### 全序集（线序集）(chain)

- **totally ordered or linearly ordered set**

- 如果偏序集 S 中 任意两个元素都可比，那么这个集合就叫全序集或线序集，一个全序集也叫链(chain)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20135.png)

### Lexicographic Order （字典序）

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20136.png)

- 在两个偏序集的笛卡尔积上的字典序是一个偏序集

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20137.png)

??? note "Example"


    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20138.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20139.png)

### Hasse Diagrams

- 自下而上，路径上的点都是顶点的等价类

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20140.png)

### chain and antichain

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20141.png)

- 这是对于集合A的子集的概念

- 如果子集B， $(B,\preccurlyeq)$是全序集，那B就是 $(A,\preccurlyeq)$的chain

- 如果子集B，B中任两个元素都不可比，那B就是 $(A,\preccurlyeq)$的antichain

### Maximal and Minimal Elements

!!! tip "概念辨析"

    Maximal,Minimal（极大元，极小元）是极值，可以有多个，是top, bottom 元素

    greatest element, least element （最大元，最小元）唯一

---

??? note "Example"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20142.png)

---

!!! note "上下界"
    **上下界**：对于S的子集A，

    - 上界u, $\forall a \in A, a \preccurlyeq u$

    - 下界l, $\forall a \in A, l \preccurlyeq a$

    - 注意别忘了A里面自身的元素也可作上下界

    - 最小上界(**lub**),最大下界(**glb**)

### Well-order Sets



- 良序集：

- 对于偏序集 $(S,\preccurlyeq)$， $\preccurlyeq$是全序的，且S的每个非空子集都有一个最小元素（least），就称它为良序集

### Lattices 格

- 如果一个偏序集的每对元素都有最小上界和最大下界，就称这个偏序集为格


![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20143.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20144.png)

- 先确定上下界有哪些，再去思考这些上下界中是否能确定有lub和glb

### Topological Sorting

!!! note "**相容(compatible):**"

    - 如果只要 $aRb$ 就有 $a \preccurlyeq b$ ，则称全序$\preccurlyeq$和偏序$R$是相容的

=== "**Lemma 1**"

    每个有穷非空偏序集 $(S,\preccurlyeq)$至少有一个极小元(minimal)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20145.png)

=== "**Algorithm 1**"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20146.png)

=== "example"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20147.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20148.png)
