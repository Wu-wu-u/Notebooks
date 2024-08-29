## Chapter 6
Sorting

### Insertion Sort 插入排序

- 类似于抓牌时，边拿边理牌

- 步骤：

    1. 对于新抓的第p个元素，去和前面理好的p-1个元素相比较，比它大就交换
    2. 直到找到恰比它小的数字

```c
void InsertionSort(int a[],int n){
	int temp;
	for (int i=1;i<n;i++){
		temp = a[i];
		for (int j=i-1;j>=0&&a[j]>temp;j--){
				a[j+1]=a[j];
		}
		//错误代码：a[j+1]=temp;
		a[j+2]=temp;
		//问题就在于for条件不满足后仍会j--，可以把j--挪至循环内部 
	}
}
```

- worst case: $T(N)=O(N^2)$

- best case: $T(N)=O(N)$

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2017.png)

- 因为每次相邻元素的交换只会使逆序对减1，那么插入排序的总操作次数，就是N个元素过一把，加上I次swap

$T(N,I)=O(I+N)$

---

!!! note "两个定理："

    1. 对于一个N元素数组，它逆序对的个数为，
    $I=C_n^2 * 0.5 = N(N-1)/4$
    2. 那么凡是通过交换相邻元素实现排序的算法，一定是有平均复杂度 $\Omega (N^2)$

### Shell sort 希尔排序

- 每间隔n来取数，并把取的数字进行`insertion sort`（这种非相邻元素的交换，可以保证逆序对的纠正 ≥1）

- 间隔依次减小，最后减小到1

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2018.png)

- 而且进行 $h_{k-1}$-sorted时，会保证 $h_k$-sorted

---

- increment sequence 的取法

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2019.png)

- 希尔本人是 除2来取，但实际上并不好

#### Hibbard’s Increment Sequence:

- $h_k=2^k-1$

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2020.png)

- 这样子 $h_i$之间彼此互质

```c
int k=log2(n);
for (;k>0;k--){
		int incremtnent=pow(2,k)-1;
		for (int i=increment;i<n;i++){
				int temp=a[i];
				int j;
				for (j=i-increment;j>=0&&a[j]>temp;){		
						a[j+increment]=a[j];
						j-=increment
				}
				a[j+increment]=temp;
		}
}
```

#### In-place 与 stable

- in-place:
    
    如果一个算法是就地的，那么它在处理数据时不需要或只需要固定的额外空间。
    
    例如，许多排序算法（如冒泡排序、插入排序、选择排序和快速排序）可以被实现为就地排序，这意味着它们可以在原数组上进行排序，而不需要创建一个新的等大小的数组。
    
    就地算法的优点是它们通常比非就地算法更节省内存。然而，就地算法可能会修改输入数据，这在某些情况下可能是不可接受的。
    
- stable:  
等值元素的相对位置没有发生改变

|  | in-place | stable |
| --- | --- | --- |
| shell sort | $\checkmark$ | $\times$ |
| insertion sort | $\checkmark$ | $\times$ |

### Heap sort 堆排序

- 记得选择排序 $O(N^2)$就在于每次遍历n元素才能确定最小值，于是构建最小堆，就可以用 $O(logN)$来找到最小值

=== "Algorithm 1 费内存"

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2021.png)

- 算法一有点浪费空间，
- 我们会发现每次deletemin 完，数组末尾会有空余位置，于是有了算法二的想法

=== "Algorithm 2 (in-place)"

- 我们采用 `MaxHeap`

- 每次 DeleteMax 都是在把 H[0] 与 H[tail]交换

- 然后pecolatedown(0);

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2022.png)

- $T(N)=O(NlogN)$
- 无论best、worst、average case 都是很好的NlogN

- 这个版本是  
**in-place, 非 stable**

### Merge sort 归并排序

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2023.png)

- 前置思想：Merge两个有序list，就是和合并链表一样，从头比较

- 于是  
MergeSort(分治思想)

=== "Msort"
    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2024.png)

    !!! note "要点解析"

        1. `if(Left < Right)` 就代表了递归停止的时候，只剩一个元素(Left=Right)
        先递归Msort(也就是分半)，再调用Merge
        2. `void Mergesort` 就是个`TmpArray`启动器,
        记得给TmpArray分配空间，调用Msort时是从`0~N-1`

=== "Merge"
    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2025.png)

    !!! note "要点解析"

        1. 两段序列，一个是从 `Lpos~LeftEnd=Rpos-1` ，另一个是从 `Rpos~RightEnd` ,总元素 `NumElements= RightEnd-Lpos+1`
        2. 紧接着三重while，
        第一重，两序列比较，未到End时，边比边退
        第二、三重，走完未尽的道路
        3. 最后倒着一个个赋值，其实可以(开始的时候i=Lpos,然后正向赋值)

#### Analysis

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2026.png)

- $T(N)=O(NlogN)$

- **不是 `in-place` 但是`stable`**

### Quick sort 快速排序

- 先找到一个`pivot`然后整个序列进行一个partition，一部分比pivot小，一部分比它大；然后递归进行

#### Picking the Pivot

- 问题在于 如何选择一个好的`pivot`

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2027.png)

!!! abstact 
    综上：选取位置上的第一个，最后一个和中间数，选择其中这三个里的中间大小的数

#### Partition strategy

1. 把选取的 `pivot`移至末尾
2. 给定 i,j 两个指针分别指向 a[0]和a[n-2]
3. i负责比pivot大的部分，j负责比pivot小的部分
4. 一旦有一方不符合，直接互换a[i]和a[j]
5. 最后 j会在i前面，且两者相邻，于是我们交换末尾a[n-1]的pivot 和 a[i]

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2028.png)

!!! warning "注意"

    1. 当 a[i] or a[j] == pivot 时，我们就互换一下 a[i]和a[j]就好了，然后让i和j继续往前走

#### Small Array

- 当数据量 $N \leq 10$时，QuickSort实际没有insertion sort来的快，于是我们可以在partition到10以内的数据量时调用insertion sort

#### Implementation

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2029.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2030.png)

!!! Tip 
    - 注意细节：`pivot` 被放在了 `A[Right-1]`
    - 是因为我们真正需要 管理排序的部分 其实是 A[Left+1] 到 A[Right-1]

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2031.png)

!!! Tip
    - 注意细节：为了配合 `++i,—-j`  i和j 分别初始化为 Left和Right-1

#### Analysis

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2032.png)

#### Kth largest

- 因为在quicksort的partition环节，我们可以确定pivot是数组中第i大的数(从0开始记)，于是

- k≥i,去右边找；k≤i，去左边找

### Table Sort

- **Problem:交换两个特别大的结构是十分expensive的**

- Solution:只是挪动 指针

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2033.png)

### General Lower Bound for Sorting
- 排序算法的下界

- 任何用比较实现的算法只能有 $\Omega(NlogN)$的最坏情况时间复杂度

!!! info "引入：**决策树**"

    - 假设3个元素 $K_0,K_1,K_2$

    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2034.png)

    - `Worst case`的时间复杂度 在决策树中就是depth

    - 那对于最优良的算法（树）的形态就应该是complete binary tree

### Bucket Sort and Radix Sort

#### Bucket Sort

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2035.png)

- 我们划分出M个桶来分装 N个元素

- 当 N>>M时，是极好的 $T(N,M)=O(N)$

---

- 当M>>N时

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2036.png)

- 我们观察到虽然 M很大，但是1000这个数字实际上位数不多，于是便有了 Radix Sort 基数排序

#### Radix Sort

- 依次基于位数字进行的桶排序

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2037.png)

- 利用上一轮排序的结果，可以快速得到下一个桶的排序

- $T(N)=O(P(N+B))$

- P是Pass数也就是位数，N+B就是每次pass的桶排序

#### MSD(Most Significant Digit) Sort 最高有效位排序

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2038.png)

#### LSD(Least Significant Digit) Sort 最低有效位排序

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2039.png)
