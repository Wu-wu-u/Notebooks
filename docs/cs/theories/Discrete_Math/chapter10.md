# Chap 10
Graphs

## 10.1 Graph Models

### Undirected Graph

1. Simple Graph
没有一条边连接到相同的两个顶点，不含自环和多重边
2. Multigraph 多重图
两点间有多条边
3. Pseudograph 伪图
包含环或存在多重边的

三者是包含关系

### Directed Graph

1. simple directed graph 简单有向图
两点间最多一条有向边
2. directed multigraphs 有向多重图
有多重有向边
3. mixed graph 混合图
既有有向边又有无向边

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20149.png)

## 10.2 Terminology and Special Graphs

### Basic Terminology

Degree:度 deg(v)

=== "定理1"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20150.png)

=== "定理2"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20151.png)

=== "定理3"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20152.png)

### Special Simple Graphs

=== "1. Complete Graph - $K_n$ 完全图"  
    不同顶点间都恰有一条边
    
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20153.png)
    
=== "2. Cycles - $C_n$ 圈图"
    
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20154.png)
    
=== "3. Wheel - $W_n$ 轮图"
    
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20155.png)
    
=== "4. n-Cubes - $Q_n$ n-立方体图"
    
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20156.png)

-------
    

### Bipartite Graph （二分图）

=== "二分图"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20157.png)

    - 一个图可以拆成两部分的顶点 $V_1,V_2$，只存在从 V1到V2的边

=== "**Complete Bipartite Graph** 完全二分图"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20158.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20159.png)

-----

### regular graphs 正则图

- 如果简单图的每个顶点的度都相同，则称这个图是正则的，对于deg(v)=n，则称n-regular

### New Graphs from Old 构建子图

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20160.png)

- 点和边分别来自原来的子集，然后构成新的图

!!! note "Example"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20161.png)

    - 共有四种情况，即顶点数分别为1-4

    - 一个顶点： $C(4,1)$

    - 两个顶点： $C(4,2)*2$(有一条边或者没有)

    - 三个顶点： $C(4,3)*2^3$(他们之间有三条边，那么显然2^3)

    - 四个顶点： $C(4,4)*2^6$

## 10.3 Representing Graphs 图的表示

### adjacency lists 邻接表

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20162.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20163.png)

### adjacency matrices

- 对于简单图就是一个01矩阵，

- 对于多重图和伪图，就把1改成两点间边的数量

!!! note "结论"

    1. 对于无向图：  
        $i\text{th}$ row的和等于 Vertex $i$的 度数减去在 $i$处环的数量
        $\sum_k^n a_{ik}=deg(V_i)-loop(V_i)$
    2. 而有向图：  
        仅是该点的 $deg^+(V_i)$

### Incidence matrices 关联矩阵

- 对于无向图，我们把边编号为 $e_1,e_2…e_m$，顶点还是 $V_1,V_2…V_n$，于是构成一个 $n\times m$的矩阵M

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20164.png)

- 每列两个1是边，每列一个1是环

## Graph Isomorphism 图的同构

- 通过一个双射函数，把一个顶点集V1映射到另一个顶点集V2，并且顶点的相邻情况仍不变，即重新给顶点编号

### invariants 图形不变量

!!! info
    - 我们想判断两个图是否同构，就要利用图形不变量来判断

    1. 顶点数，边数
    2. 对应顶点度数
    3. 如果一个图是 bipartite/complete/wheel，那另一个也一定是

- 于是

- 我们可以先构建映射关系，然后在比对两个adjacency matrices(当然一般还是瞪眼法)

## 10.4 Connectivity 连通性

### path,circuit概念

- 给一个顶点序列 $x_0,x_1,x_2,…x_n$，相邻两点间是一条边，那么就是一个通路；
- 如果始末点相同则是回路(circuit);
- 简单的：不重复包含相同的边

### path 路径

!!! "定理"
    - $V_i-V_j$**长为n的路径的，就等价于** $A^r的a_{ij}$

    - 此处的 $A^r$是矩阵乘积，而非布尔积（关系里求传递闭包）

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20165.png)

    计算通路数方法↑

### connectedness

- 无向图：连通就是任意两点间存在一条路径

- 有向图：

    1. 强连通：在有向的情况下任意两点间存在路径
    2. 弱连通：在无向的情况下任意两点间存在路径

## 10.5 Euler and Hamilton Paths

### Euler Terminology

- 欧拉回路：就是始末点相同的一笔画

- 欧拉通路：就是一笔画但始末不同

### 欧拉通路、回路 两个定理

1. 有两个点以上的联通多重图具有欧拉回路当且仅当每个顶点的度为偶数
    
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20166.png)
    
2. 有欧拉通路但无回路，当且仅当它恰有2个度为奇数的顶点

- 有向图中：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20167.png)

### Hamilton Terminology

- 哈密顿通路：每个顶点恰经过一次

- 哈密顿回路：每个顶点恰经过一次，但最终又回 $x_0$的回路

### Properties

1. 带有度为1的图没有哈密顿回路，因为在哈密顿回路中每个顶点都关联着回路的两条边
2. 如果图中有度为2的点，它关联的两条边一定属于哈密顿回路

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20168.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20169.png)

!!! Tip "两个定理"
    - **Dirac’s Theorem**
        - 如果G是有n个顶点的简单图，其中 $n≥3$，并且G中每个顶点的度至少为 $n/2$，则G有哈密顿回路

    - **Ore’s Theorem**
        - 如果G是有n个顶点的简单图， $n≥3$，并且对于G中每一对不相邻顶点 $u,v$，都有 deg(u)+deg(v)≥n,则G有哈密顿回路

## 10.6 Shortest Path

### Dijkstra’s Algorithm

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20170.png)

- $T(N)=O(V^2+E)$

### Traveling Salesperson Problem

- 旅行商要访问n个城市且没每个城市恰好一次，并且返回出发点，并使得旅行总距离最短

- 等价于求完全图中总权值最小的哈密顿回路

---

=== "方法一"

    - 遍历所有可能得哈密顿回路，然后选择总权重最小的

    - 首先对于 $K_n$，环的个数为 $(n-1)!$

    - 其次哈密顿回路可以从反方向再遍历一次，所以实际上只有 $(n-1)!/2$个回路

    - （这个数字同前文组合里的环排列）

    - 时间复杂度: $n!$


=== "方法二：估计算法"

- 用一个贪心的算法，每次从一个点出发都选择权重最小的边，可以得到一个接近最优解的结果

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20171.png)


----

## 10.7 Planar Graphs

!!! info "定义"
    一个图中没有任何交叉的边，那这个图就是平面图

??? Tip "K3,3是非平面图"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20172.png)

### Euler’s Formula

- 设G是带e条边和v个顶点的联通平面简单图，设r是G的平面图表示中的面数，则r=e-v+2

??? note "证明"
    - 数学归纳法
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20173.png)

!!! warning "注意"

    1. 欧拉公式只是一个必要条件，平面图必须满足但满足的并非是平面图
    2. 对于非联通的简单图
    我们记c为连通组件数，
    $r-(c-1)=e-v+2$

---

!!! info "引入：面的度数"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20174.png)

    - 贴着边界 数

    - $2e=\sum deg(R_i)$

---

### 三条推论

=== "推论1"

    - 若G是e条边和v个顶点的连通平面简单图，其中v≥3,则e≤3v-6

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20175.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20176.png)



=== "推论2"

    - 若G是连通平面简单图，则G中有度数不超过5的顶点

    ??? note "证明"

        1. 如果G只有1个或者2个顶点，这显然成立
        2. 如果G有至少3个顶点，由推论1知 2e≤6v-12,同时2e=∑deg(vi),如果度数至少为6，那么2e≥6v矛盾


=== "推论3"

    - 若连通平面简单图有e条边和v个顶点，v≥3并且没有长度为3的回路，则e≤2v-4

    - 这个本质上和推论1证明一样，只是说推论1中deg(R)至少为3，而现在排除了长度为3的回路，使得deg(R)至少为4

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20177.png)

-----

- 在这些定理的加持下，我们就可以证明nonplanar了
??? note "Proof"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20178.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20179.png)

### Kuratowski’s Theorem 
- 库拉图斯基定理

??? info "初等细分(elementary subdivision)"

    若一个图是平面图，通过删除一条边{u,v}并且添加一个新顶点w和两条边{u,w}和{w,v}得到的任何图也是平面图。（这个操作叫做初等细分）

??? info "同胚的(Homeomorphic)"

    如果可以从相同的图G经过一系列初等细分得到G1和G2，则他们是同胚的

---

!!! note "定理"
    一个图是nonplanar 当且仅当它包含一个同胚于 $K_{3,3}或K_5$的子图

??? note "Examples"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20180.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20181.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20182.png)

-------

## 10.8 Graph Coloring

- 着色问题就是研究用最少的颜色数来染图，并使得相邻的面不是相同的颜色

!!! info "引入"

    1. 对偶图（dual graph)：就是把region视作顶点，相邻关系的面用edge连接，构成的图
    2. 图的着色数（chromatic number）：就是着色这个图所需要的最少颜色数，图G的着色数记作 $\chi(G)$

---

### 四色定理

- 平面图的着色数不超过4

### 一些简单图的着色数

??? note "Examples"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20183.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20184.png)

### 着色的应用例子

??? note "Choosing Classes-Examples"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20185.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20186.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20187.png)

    根据给的条件画出不重课图，然后找到它的补图，补图就是相邻的会重课；于是进行一个染色
