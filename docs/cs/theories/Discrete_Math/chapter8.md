# Chap 8
Advanced Counting Techniques

## Recurrence Relations（递推关系）

- degree：递推需要的初始项个数

!!! note "经典应用"

    - 斐波那契数列： $F_N=F_{N-1}+F_{N-2}$

    - 汉诺塔： $H_N=2H_{N-1}+1$

    - 比特串： 

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2067.png)

    - 编码字：

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2068.png)

### 卡塔兰数

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2069.png)

## Solve Linear Recurrence Relations

=== "定理1"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2070.png)

=== "定理2"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2071.png)

=== "定理3"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2072.png)

=== "定理4"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2073.png)

=== "定理5"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2074.png)

    通解 $b_n=a_n^{(p)}+a_n^{(h)}$

=== "定理6"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2075.png)

-------

!!! warning "注意"

    1. F(n)的指数项和特征根是否重合，尤其关注 $1^n$
    2. n重特征根就会有 $(n^0,n^1,…,n^t)$的幂函数项

!!! Abstract "步骤"

    1. 找出齐次式下的特征根 $r_1…r_n$
    2. 写出 $a_n^{(h)}$的形式
    3. 写出 $a_n^{(p)}$的特解形式
    4. 代入递推方程，找到各系数的方程
    5. 再利用给定的初始值，再得到系数的方程解

## generating functions 
(生成函数)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2076.png)

### 有用的事实

=== "定理1"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2077.png)

=== "定理2"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2078.png)

=== "生成函数表"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2079.png)

-----

- 注意几个常用级数：

    1. 二项式级数， $a_k=C(n,k)$
    2. 二项式级数的倒数，  
    $a_k=C(n+k-1,k)=C(n+k-1,n-1)$



### 应用！！！

=== "计数"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2080.png)

    - 关键是如何找到 $a_{3r}$

    - 明显只需要考虑分子的 1 和 $x^{2r+1}$项

    - 于是我们把分母变换一下 成 级数形式

    - 那么它的每 i 项 系数为 

    - $C(3+i-1,i)=C(i+2,i)$

    - 最后就是考虑分母的 第 3r 项和 r-1 项



=== "用于求解线性齐次递推关系"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2081.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%201.jpeg)

===  "Inclusive-exclusion"
    （容斥）

    ??? tip "妙妙的证明"

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2082.png)

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2083.png)

=== "sieve of Eratosthenes"
    (埃拉托色尼筛)（寻找素数个数）

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2084.png)

=== "onto functions的个数"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2085.png)

------

### 错位排列

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2086.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2087.png)

??? note "组合证明"

    1. 我们考虑第一个元素，它必不会是1，因此有 $n-1$种选择，假设占据 1th 位置的元素是 k
    2. 对于kth位置 又有两种情况，若1在kth位置，那就是剩下的 $n-2$个的错排
    3. 若1不在kth位置，那其实1就在扮演k的角色，参与了剩下 $n-1$个元素的错排

    - $D_n=(n-1)(D_{n-1}+D_{n-2})$

## 题集

=== "8.6"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2088.png)

    - 只考虑 质因子的平方 即可

    $99-\lfloor{99/2^2}\rfloor-\lfloor{99/3^2}\rfloor-\lfloor{99/5^2}\rfloor-\lfloor{99/7^2}\rfloor+\lfloor{99/2^23^2}\rfloor=61$

=== "8.4 生成函数，卡特朗数"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2089.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%202.jpeg)

    -  最妙在于 $\frac{2·4·6···2n}{2^nn!}=1$

    - 拓展：

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2090.png)

        ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%203.jpeg)

=== "8.4 生成函数证明帕斯卡、范德蒙恒等式"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2091.png)

=== "8.4 生成函数求平方和公式"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2092.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%204.jpeg)

=== "8.5  使用数学归纳法证明容斥原理。"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%205.jpeg)

=== "8.6 欧拉函数"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2093.png)

    1. $\phi(pq)=pq-pq/p-pq/q+pq/pq=(p-1)(q-1)$
    2. $\phi(n)=n-\sum_{i=1}^m\frac{n}{p_i}+\sum_{1≤i<j≤m}\frac{n}{p_ip_j}-···+/- \frac{n}{p_1p_2···p_m}\\=n\prod_{i=1}^m(1-\frac{1}{p_i})$
