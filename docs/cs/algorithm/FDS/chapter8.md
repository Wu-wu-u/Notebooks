## Chapter 8 
The Disjoint Set

### Equivalence Relations

- 要满足reflexive（自反性），symmetric（对称性），transitive（传递性）

### Algorithm

- 所以我们为了实现这个并查集，就主要运用Union和Find函数，让每个元素一开始成为单独的集合

- 然后利用Find找到根，Union两个集合

=== "Union(i,j)"

    - 利用数组下标和对应元素来部署

    - `S[element]= parent’s index`
    - `S[root]=0` 

    - 数组下标就是这个数，存放的元素是对应父节点的下标，根节点下标为0

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2059.png)

    - 只要轻轻改动对应子集的 根节点的元素 就能完成Union

    !!! Note
        对于不是按1-N给的数据，可以另开一个数组来映射

=== "Find（i）"

    ```c
    for(;S[X]>0;X=S[X]); //有个分号
    return X;
    ```
    !!! warning "注意分号"

-------

#### Final Presentation

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2060.png)

- 先初始化数组设定为独立的集合，然后根据关系查找根，根不同的集合Union到一起

#### Smart Union

- Union-by-size
    
    S[root]=-size 关键步骤
    
    将根节点原先的元素0利用起来，用来记录整个Set的大小，用负数避免误判为index，一开始就初始化为-1
    
    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2061.png)
    

#### Path Compression

- 将一路的祖先的parent设置为根节点,来减少后续Find的压力

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2062.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2063.png)
