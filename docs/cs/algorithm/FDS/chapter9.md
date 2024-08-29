## Chapter 9
Graph Algorithms

### Definitions

=== "Undirected graph"

    - $(v_i,v_j) = (v_j,v_j)$

=== "Directed graph"

    - $<v_i,v_j> \neq <v_j,v_j>$

=== "Complete graph"

    - $V=n, E=C_{n}^{2}$

=== "path"

    - 从 $v_p$到 $v_q$ 经过的路径

    - simple path： $v_p$到 $v_q$路径上的每个点都不同

=== "Special graph"

    - tree
        
        联通无环的图
        
    - DAG
        
        有向无环图
        
    - Strong connected directed graph
        
        强联通：存在任意两点间的有向路径
        弱连通：存在任意两点间的无向路径
    

=== "Degree"

    - in-degree（入度）：射入v的edge个数
    - out-degree（出度）：v射出的edge个数

    !!! note"结论"

        - 图里边个数的顶点度数和的一半

        $$
        e=(\sum_{i=0}^{n-1}d_i /2) 
        $$

--------

### Representation

#### Adjacency Matrix

- 把表示的每一条边存入数组中 <vi,vj>

$$
adj\_mat[i][j] = \begin{cases} 1 & \text{if }(v_i,v_j) \space \text{or }<v_i,v_j>\in E(G) \\ 0 & \text{otherwise }  \end{cases}
$$

- 无向图只需要存储一半的数据

- 对于度数的计算：

=== "无向图"

    - d(i)=遍历第i行

    $$
    degree(i)=\sum_{j=0}^{n-1}adj\_mat[i][j]
    $$

=== "有向图"

    - d(i)=遍历第i行+遍历第i列

    $$
    degree(i)=\sum_{j=0}^{n-1}adj\_mat[i][j]+\sum_{j=0}^{n-1}adj\_mat[j][i]
    $$
    
    $T(N)=O(N^2)$

---------------

#### Adjacency Lists

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2064.png)

- `graph[i]`表示 $v_i$指向的所有的顶点

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2065.png)

- 再开个来表示`in-degree`的

#### Adjacency Mutilists

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2066.png)

- 用node来表示所有的边，node里的指针就代表了哪l两个vertice

#### Weighted Edges

- 数组表示的话：          
    - adj_mat[i][j]把存的数值从1更改为weight

- 链表或者多重表：
    - 增加一个weight变量

### Topological Sort

- 对象：DAG（有向无环图）

- 对于序列 $V_1,V_2,V_3...V_n$

- 必须保证 $<V_i,V_j>$存在，

- 即 $V_i$是predecessor，$V_j$是successor

- 那么我们只需要每次挑选 In-Degree 为 0 的顶点

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2067.png)

### Shortest Path Algorithms

#### Unweighted Shortest Path

- CurrDist是当前步数

- 找到符合CurrDist的V顶点，然后标记为Known，然后对于每个相邻的顶点，把距离进行变换，然后入队

#### Single-Source Problem

- 如果有负环则无解，而不是负边来决定

#### Dijkstra’s Algorithms

!!! note "步骤"
    1.select 如何选择符合条件的点

    2.update 如何更新相邻顶点的值 (d[u]+Cuv ? d[v])

- 两种部署:

=== "Dense"
    Dense的情况，我们用数组(simply scan the table)

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2068.png)

    $T=O(V^2+E)$

=== "Sparse"
    Sparse的情况，用minheap

    此处补代码

    $T=O(VlogV+ElogV)$

----------------

#### AOE

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2069.png)

!!! Info
    - 在项目管理和调度理论中，"Earliest Completion Time"（最早完成时间），"Latest Completion Time"（最晚完成时间）和 "Slack Time"（浮动时间）是关键的概念，它们帮助我们理解和管理项目的时间表和进度。

    1. **Earliest Start Time（最早完成时间）**: 这是指在给定的前提条件下，任务或项目能够完成的最早时间点。这通常基于任务的最早开始时间和所需的工作量来计算，同时考虑到任何前置任务的完成时间。在项目调度中，计算每个任务的最早完成时间有助于确定项目的最短可能持续时间，并帮助项目经理优化资源分配。
    2. **Latest Complete Time（最晚完成时间）**: 这是一个任务或活动在不延误整个项目的情况下可以完成的最晚时间。这个时间通常是通过向后计划法（从项目结束时间开始，向前推算每个任务的最晚开始和结束时间）计算出来的。
    3. **Slack Time（浮动时间）**: 这是一个任务或活动的开始或结束时间可以在不影响其他任务或整个项目进度的情况下延后的时间长度。换句话说，这是任务或活动的开始或结束时间相对于其最早开始时间或最晚完成时间的"弹性"。浮动时间可以用来调整项目计划，以应对不可预见的延误或其他问题。

    - 这些概念在关键路径方法（Critical Path Method，CPM）中被广泛使用，关键路径方法是一种用于计划和管理复杂项目的技术。在这种方法中，关键路径是项目中所有路径中最长的路径，它决定了项目的最短完成时间。关键路径上的任务通常没有浮动时间，因为它们的延误会直接影响到整个项目的完成时间。


### Network Flow Problems

- 引入两个图：流量图(Flow)和残量图(Residual)

- 用反向边来修正

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2070.png)

!!! Abstract "总的步骤"

    1. 从Residual找一条从s到t的path，流量就是整个路径上的最小权重
    2. 然后在Residual上减小正向边权重的同时增加刚刚所选路径的反向边和权重
    3. 然后重复上述步骤，直到没有从s到t的路径


- 即便如此，还是有值得改进的地方，例如这个e.g.

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2071.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2072.png)

- 也就是说，我们选边是要有原则的

- **选增量最大的边或者是路径最短的边 总是好的**

### Minimum Spanning Tree

!!! info "生成树"
    - 一个图的子集，包含所有的顶点，就是spanning tree

- Minimum 就是 所有边的cost和最小

- 边数恰好为 $E=V-1$

- 存在最小生成树 $\text {iff}$ G是联通的 

#### Prim’s Algorithm

> similar to Dijkstra

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2073.png)

- 从一个点开始，去走
    - 已知的
    - cost最小的
    - 能到未知顶点的边
- （此例中顺序为 $V_1-V_4,V_1-V_2,V_4-V_3,V_4-V_7,V_7-V_6,V_7-V_5$)

#### Kruskal’s Algorithm

- 类并查集算法

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2074.png)

- 从边入手，

- 建一个最小堆存放所有的边 

- 然后 依次delemin，也就是每次都去选择cost最小的边

- 对于每条边我们去 union/find 他们的顶点是否存在过（或者说顶点是不是在同一root下）

### DFS

- 对比：
    - BFS是从一个点往一个相邻顶点向外扩散

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2075.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2076.png)

- 与前序遍历的区别是，树里面有父子关系，只从父到子；

- 而图里面两个点之间互为邻接，所以要有一个 `if(!visited[W])`

#### DFS in Undirected Graphs

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2077.png)

- 其实是两个函数，一个是`DFS`，另一个是`ListComponents`,因为DFS只处理连通图，对于多个组件我们就需要用这个函数

#### DFS in Biconnectivity

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2078.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2079.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2080.png)

- 关节点是指，删除这个顶点后，图会产生至少两个联通组件
- 双联通图就是没有关节点的图；即任意拿掉一个顶点，图仍联通
- 双联通组件，注意Maximal

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2081.png)

- 可以发现没有边被两个或多个双联通组件共享

---

=== "利用DFS寻找双联通组件"

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2082.png)

    - DFS走出来的最小生成树中，未走过的`Back edges`一定是祖孙关系，不可能是平行关系，然后祖先的index肯定比后代的index小



=== "寻找关节点"

    1. 根节点如果有两个以上的children，则root一定是关节点
    2. 一个非叶节点即有至少一个child，如果它往下走n步却还是能通过back edges等回到它的祖先，那它就不是关节点；反之就是关节点
    （因为 如果能回到祖先，那就算拿掉这个点 也仍然联通；如果不能回去，那么和祖先断联了）

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2083.png)

    !!! Tip
        借此我们引入一个函数 `Low(u)`

        $Low(u)=\text{min}\{Num(u),\\ \text{min}\{Low(w)|w \text{ is a child of u}\},\\ \text{min}\{Num(w)|(u,w) \text{ is a back edge}\}\}$

        `Low(u)` 就是顶点 u 能通过自己或者自己的后代的back edge 所能到达的最远祖先（所以是min）

        ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2084.png)

        1. root还是只看有无多孩子
        2. 非叶节点，如果存在一个孩子的祖先不能在我之上，我就会和祖先断联

#### DFS in Euler Circuits

- 一笔画问题

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2085.png)

- 欧拉路径：就是一笔画

- 欧拉回路：就是起末点都相同的一笔画

!!! note "两个结论"

    1. 只有当所有顶点都是偶数的度，才有可能存在欧拉回路
    2. 只有当仅两个顶点是奇数的度且其余顶点都是偶数的度，才有可能存在欧拉路径

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2086.png)
