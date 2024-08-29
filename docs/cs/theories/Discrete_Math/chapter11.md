# Chap 11 Trees

- 树是没有简单回路的连通无向图

## 11.1 Introduction to trees

!!! info "术语"

    1. Parents vs. Children
    2. Siblings
    3. Ancestors vs. Descendants
    4. Root,leaf,and internal vertex（内点就是有Child的点）
    5. subtrees

---

### 数树的个数

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20188.png)

- 思路就是 按照Longest Path来分类讨论

- 路径长分别为：4,3,2,1的情况

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20189.png)

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20190.png)

### Tree Propertities

1. 带有n个顶点的树有n-1条边
2. 带有i个内点的满m叉树含有n=mi+1个顶点

---

- 一个满m叉树若有：
    1. n个顶点，则有 $i=(n-1)/m$个内点； $l=[(m-1)n+1]/m,即l=n-i$个叶节点
    2. $i$个内点,则有 $n=mi+1$个顶点和 $l=n-i=(m-1)i+1$个叶节点
    3. $l$个叶节点，则有 $n=(ml-1)/(m-1)$个顶点和 $i=(l-1)/(m-1)$个内点

- 关键是第二个，三个之间彼此互推

### Balanced

!!! info "level和height的概念"

    - level是指从root到某个顶点v所需要的路径长

    - height就是整棵树中最大的level（所以根节点是从level=0开始计算height）

---

!!! info "Balanced" 
    - 指叶节点在 h or h-1 level

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20191.png)

---

=== "定理（性质）"

    - m叉树中最多有 $m^h$个叶节点（也就是hlevel处全是叶节点）

=== "引理"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20192.png)

-------

## 11.2 Applications of trees

### BST

- 详情见FDS

### Decision Trees

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20193.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20194.png)

### PrefixCode 前缀码

- 我们在为字母编码时一开始想着用5bit长，但为了缩减空间于是采用变长的bit来编码

- 而为了明显区别出每个字母的编码，就必须用某种方法来确定字母从何开始从何结束

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20195.png)

### 哈夫曼编码

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20196.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20197.png)

## 11.3 Tree Traversal

- Preorder：中、左、右
- Inorder：左、中、右
- Postorder：左、右、中

## 11.4 Spanning Trees

!!! info "Spanning Tree（生成树）的概念"
    - 就是包含原图G所有顶点的一个子图，因而可以有多个生成树

!!! note "定理"

    一个简单图是连通的，当且仅当他有一个生成树

---

### DFS in Spanning Trees

info Tip "Steps"
    1. 随意选一个顶点作为`root`
    2. 访问一个相邻未访问过的节点
    3. 重复进行直至无法再访问，则回溯

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20198.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20199.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20200.png)

### BFS in Spanning Trees

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20201.png)

- DFS是对于相邻未访问的节点直接深入下去；BFS则是先访问一遍所有未访问的相邻节点，再一层层深入

## 11.5 Minimum Spanning Trees

- 最小生成树，是边权重之和最小的生成树

### Prim’s Algorithm

- similar to Dijkstra

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20202.png)

- 从一个点开始，  
去走

- 已知的

- cost最小的

- 能到未知顶点的边

- （此例中顺序为 $V_1-V_4,V_1-V_2,V_4-V_3,V_4-V_7,V_7-V_6,V_7-V_5$)

### Kruskal’s Algorithm

- 类并查集算法

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20203.png)

- 从边入手，

- 建一个最小堆存放所有的边 

- 然后 依次delemin，也就是每次都去选择cost最小的边

- 对于每条边我们去 union/find 他们的顶点是否存在过（或者说顶点是不是在同一root下）