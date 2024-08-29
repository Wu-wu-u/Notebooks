## Chapter 7
Hashing

!!! info "引入：Interpolation Search"

    - 我们试图在一个分布较均匀的sorted list中，找到一个好的起始划分点，而不总是对半砍

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2040.png)

### ADT: Symbol  Table

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2041.png)

### Hash Tables

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2042.png)

- 行是b个bucket，列是s个slot

- 然后我们有一个映射函数 $f(x)$（哈希函数）可以用来确定 $x$在哪一个bucket中

- Loading density $\lambda=n/(s*b)$


!!! warning "意外情况"

    1. `collision`  
    $f(i_1)=f(i_2),i_1\neq i_2$
    2. `overflow`  
    往满的的bucket里塞了新的 identidier，（有overflow一定有collision）

### Hash Function

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2043.png)

!!! note "性质"

    1. $f(x)$尽可能简单并且减少冲突
    2. $f(x)$要unbiased,每个x分配到bucket的可能性均等

=== "For integers"

    - $f(x)=x~ \%~ TableSize$

    - 实践发现，`TableSize` 最好是一个 较大的质数

=== "For string"

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2044.png)

    - 用位操作解决乘法

### Separate Chaining

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2045.png)

- 这个哈希表就是一个装有指针的数组(`List *TheLists`)

- 然后每个指针往后构成一个个链表（bucket）

- 这样就不会 `overflow`

---
#### Operation

=== "Create empty table"

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2046.png)



=== "Find Key"

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2047.png)

    - 用hash function找到属于哪个bucket，然后遍历链表

    - P可能是NULL或者是找到，所以有两个终止情况



=== "Insert Key"

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2048.png)

    - 一开始去`Find Key` 是否已经存在

    - 存在的话就什么也不干，

    - 否则，`Pos==NULL`,用hash function去算bucket去插在头（不插末尾就不用遍历）

    ??? warning "注意"

        ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2049.png)

        想优化的话，就要利用好Find里算过的`HashVal`

----------

### Open Addressing
开放寻址

> Find Another empty cell to solve collision(avoiding pointer)
> 

- 我们的哈希表假设是一个slot，没有链表什么的

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2050.png)

- 引入一个偏移量i，去冲突的 $Hash(x)$附近找空位

- 这里的 $f(i)$是冲突处理函数，不是哈希函数

=== "Linear Probing"

    - $f(i)=i$, a linear function

    - 优点：有空一定能找到

    - 缺点：search time过多

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2051.png)

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2052.png)

    - 引入一个期望探测次数 $p$,来判断probe是否 good

=== "Quadratic Probing"

    - $f(i)=i^2$

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2053.png)

===  "Find操作"

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2054.png)

    - Find是在找x应处的位置，空位或者是x已经存储的位置

    !!! note
        1. while循环条件，检查是否empty 同时检查是否为所找数字
        2. $i^2-(i-1)^2=2i-1$



=== "insert操作"

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2055.png)

=== "delete操作"

    - 并不是把某个元素直接删去，而是把状态设置成deleted，然后保留元素在原位，不然find会断层！

    - 然而delete元素过多之后，insert就会大大受影响，出现secondary clustering问题

--------

#### 3. Double Hashing

- $f(i)=i*hash_2(x)$

??? warning "注意"

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2056.png)

### Rehashing

!!! note "Implementation"
    1. 开个新表，比原来至少大1倍
    2. 扫描原表中未被删除的元素
    3. 用一个新的hash function去转移元素  

    -  $T(N)=O(N)$

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2057.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2058.png)
