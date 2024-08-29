## Chapter 5
Priority Queues

### Binary Heap

- mintree和perfect binary tree的结合

- 树的思想，数组来部署

#### Min Tree

- 每个子树的根节点是子树里最小的数

#### property

- $2^h\leq N\leq 2^{h+1}-1$
- height $h=\lfloor logN\rfloor$

- 完全二叉树，铺完一层再铺下一层

- 然后给每个节点自上而下，从左到右编号 1 - n

- 对于节点数为 $N$的Heap，前 $\lfloor N/2 \rfloor$个节点为内部节点，从 $\lfloor N/2 \rfloor +1$到 $N$ 为叶节点

#### Array Representation

- 任何BST都可以用array来存，但是如果不是perfect，array有很多浪费的空位

- `BT[n+1]`（BT[0] is not used）

- parent和children的index关系
    
    $$
    parent(i) = \begin{cases} \lfloor i /2\rfloor & \text{if } i\neq1 \\ None & \text{if } i=1 \end{cases}
    $$
    
    $$
    left\_child(i) = \begin{cases} 2i & \text{if } 2i\leq n\\ None & \text{if } 2i>n \end{cases}
    $$
    
    $$
    right\_child(i) = \begin{cases} 2i+1 & \text{if } 2i+1\leq n\\ None & \text{if } 2i+1>n \end{cases}
    $$
    

### Operations

=== "Percolate up"

    记录p处的数据为data，

    然后向上寻根比较；

    若上面的大，则
    `H→Elements[p]=H→Elements[p/2];`

    `H→Elements[p/2]=data;`

    ```c
    Percolateup(int p,Priority_Queue H){
        int data=H->Elements[p];
        for (;p>0&&H->Element[p/2]>data;p=p/2){
            H->Elements[p]=H->Elements[p/2];
            H->Elements[p/2]=data;
        }
    }
    ```

=== "Percolate down"

    在child不越界size的情况下，进行左右child的比较，选择小的child再和parent对比；

    ```c
    Percolatedown(int p,Priority_Queue H){
        int child=2*p;
        int data=H->Elements[p];
        for (;2*p<=H->size;p=child){
            child=2*p;
            if(child!=H->size && H->Elements[child+1]<H->Elements[child]){
                child++;
            }
            if(data>H->Elements[child]){
                    H->Elements[p]=H->Elements[child];
                    H->Elements[child]=data;
            }
            else break;
        }
    }
    ```

=== "Insert"

    - 只能插入到最后一层的待定区，插入后不能破坏min_tree的结构，要进行父子比较

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2010.png)

    - 例如，  
    对于形如这样的Heap，我们insert一个9，那么就去和parent进行比较，然后考虑是否互换

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2011.png)

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2012.png)

    - 哨兵(sentinel):  
    BT[0]=比所有节点都小的数，便于退出祖先for循环

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2013.png)

=== "DeleteMin"

    - 删除后，  
    先把最后一个节点挪至根节点处

    - （不选择去 根节点的children里 去递归替换 的原因是 可能最后不是complete）  
    再考虑父子间的关系，找到较小的child，递归比较、交换

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2014.png)

=== "DecreaseKey(p, $\Delta$ ,H)"

    - 减小某个位置的键值，然后一个percolateup

    - IncreaseKey
        - 增大某个位置的键值，然后一个percolatedown

=== "Delete(P,H)"

    - 换个思路，把这个地方的键值减小到最小，然后Deletemin
    - Decrease(P, $\infty$ ,H) ;
    - DeleteMin;

=== "BuildHeap(H)"

    - 直接存进数组里，组成一个complete tree，然后找到最大的非叶结点N=n/2, 然后依次PercolateDown(N,N-1,N-2…)

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2015.png)

    $T(N)=O(N)$

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2016.png)

    - MaxHeap,MinHeap转换
        
        对于MaxHeap转换为MinHeap；
        还是用BuildHeap的思想，从N=n/2处开始PercolateDown
    
