# Chap 6
Counting

- **容斥原理: $|A\cup B|=|A|+|B|-|A\cap B|$**

## Pigeonhole Principle

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2047.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2048.png)

??? note "妙妙的例题"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2049.png)

---

??? note "广义鸽巢原理"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2050.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2051.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2052.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2053.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2054.png)

## 排列与组合

=== "帕斯卡恒等式"

    $C_{n+1}^{k}=C_{n}^{k-1}+C_n^k$

=== "范德蒙德恒等式"

    $C_{m+n}^r = \sum _{k=0}^r C_m^{r-k} C_n^{k}$

    - m里选r-k个，n里选k个

=== "其他"

    $C_{2n}^n=\sum_{k=0}^n (C_n^k)^2$ 范德蒙德的特例

    ----

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2055.png)

    $C_{n+1}^{r+1} = \sum_{j=r}^n C_j^r$

-----

### 隔板法

- 隔板的个数就是不同种类的物件数 n-1

- 星星数也就是要取的数 为r

- $N=C(n+r-1,r)=C(n+r-1,n-1)$

=== "有别盒子与有别物体"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2056.png)

=== "有别盒子与无别物体（就是隔板）"

    $N=C(n+r-1,r)=C(n+r-1,n-1)$

=== "无别盒子与有别物体"

    - 只能分类讨论！！

=== "无别盒子与无别物体"

    - 就是写**数字**＝**什么**

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2057.png)

----

## Generating Permutations and Combinations
(生成排列和组合)

### 字典序生成排列

- 从后往前两两比对 $a_n和a_{n-1}$

- 如果 $a_n > a_{n-1}$ 直接互换就完事
 
- 如果不是：即 $a_{n-1}>a_n$
 
- 继续向前两两比对，直到找到 $i$
- $s.t. \space a_i<a_{i+1}$
 
- 然后在 $a_{(i+1,n)}$中找到找到 恰比 $a_i$大的数，进行互换。
 
- 随后把 $(a_{i+1},a_n)$升序排列
 
![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2058.png)

### 生成比特串组合

- 从后往前找到第一个0，然后把这个0变成1，它的右边全变为0（异或 carry-in）

- $e.g. \\ 1000100111 → 1000101000$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2059.png)

### 生成集合的 r 组合

- 对于集合 ${1,2,3,4…,n}$
- 最小的r集合 ${1,2,3,4…,r}$
- 最大的r集合 ${n-r+1,n-r+2…,n}$

- 那么我们可以认为 对于 每一位 $a_i$ 它的上限 就是 自己对应最大r集合的 数 即 n-r+i 
- 超过这个上限，可以看做是一种进位

- 于是我们的算法是：

- 找到第一个不满足 $a_i=n-r+i$的数，也就是说右边的数全达上限，我们开始进位， 
- $a_i$++ 
- 那么右边的数也有一个下限 即 $a_{i+1}=a_i+1$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2060.png)

## 题集

=== "Sec.6.2（鸽巢）"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2061.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2062.png)

    同理我们有序列 $a_1≤…≤a_{75},1≤a_i≤125$

    $a_1+24≤…≤a_{75}+24,25≤a_j+24≤149$

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2063.png)

    关键是c和d

    c) 刚好一人一坑，所以必须是 $a_1=1,a_2=2,…a_{25}=25$

    d) 用刚刚的鸽巢法就不太行了，用新方法

    我们可以发现 $a_1,…a_{31}$一定存在两个数同余(mod 30)，如果这两个数刚好相差30，那么我们就已经找到了答案；

    如果没有相差30，那肯定相差30的倍数60、90、120；那么肯定有 $a_{31}≥61$，那么同样的方法，我们去序列 $a_{31}…a_{61}$去找，
    这次就必须两个数相差30，不然相差60以上的话， $a_{61}≥121 , a_{66}≥126$ 矛盾；所以存在！



=== "Sec.6.2（鸽巢）"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2064.png)

    把每个整数写成2的幂与一个奇数的乘积

    ---

=== "Sec.6.2"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2065.png)

    设序列为 $a_1,a_2…a_m$

    $d_k=\sum _{i=1}^k a_i$ 为前k项和，

    从 $d_1...d_m$，如果有 $d_i \equiv 0 (\text{mod m})$

    那么答案已出，如果没有，那么余数一定是 1 ~ m-1

    那必有两个数的余数相同 $d_i \equiv d_j ,i<j$

    那么这若干个连续整数和就是 $d_j-d_i$

    ---

=== "Sec.6.2(最难鸽巢)"

    $设 x 是 无 理 数 。 证 明 : 对 于 某 个 不 超 过 n的 正 整 数 j ，\\ 在 jx 与 到 jx 最 近 的整 数 之 间 的 差 的 绝 对 值 小 于1/n 。$

    $\{a\}$ 表示a的小数部分

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled.jpeg)

    ---

=== "Sec.6.5"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2066.png)

    设3个函数，对于n位比特串 

    $f(n)表示没有01出现，\\g(n)表示01恰出现一次，\\h(n)表示01恰出现2次$

    那么没有 01 出现的比特串一定是

    $00...000 \\ 10…000 \\ 1100…000 \\ …\\ 1111…111$

    $\therefore f(n)=n+1$

    对于g(n),我们假定第k位出现了01，那么前k-1位没有01，后n-k-1位没有01

    $g(n)\\=\sum _{k=1}^{n-1} f(k-1)f(n-k-1)\\=\sum _{k=1}^{n-1} k(n-k)\\=(n+1)n(n-1)/6=C(n+1,3)$

    对于h(n),我们假定第k位出现了01，前面k-1位没有出现，后n-k-1为恰有一个01

    $h(n)\\=\sum _{k=1}^{n-3} f(k-1)g(n-k-1)\\=\sum _{k=1}^{n-1} kC(n-k,3)\\=C(n+1,5)$



=== "Sec.6.2"

    证明:在任何n+1个不超过2n的正整数中必存在2个数互素。

    用鸽巢：

    把2n个数分为n组,

    $\{1,2\},\{3,4\}….\{2n-1,2n\}$

    那么必有两个数在同一组，而相邻的两个数必定互素
