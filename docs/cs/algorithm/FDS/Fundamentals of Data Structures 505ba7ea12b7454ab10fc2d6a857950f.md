
## Chapter 2
Algorithm Analysis

- example:
Fibonacchi
can be optimized by creating a **table
put the known numbers into it for next searching**

### Compare the algorithms

- **MaxSubsequenceSum**
Given (possible negative) integers $A_1,A_2,…,A_N$,
find the maximun value of $\sum_{k=i}^{j} A_k$
    1. 无脑遍历
        
        ```c
        for (int i=0;i<n;i++){
        		for(int j=i;j<n;j++){
        				for (int k=i;k<=j;k++)
        							sum(); //phony
        							compare(sum,max);
        		}
        }
        ```
        
        $O(N^3)$
        
    2. 利用上次计算结果
        
        ```c
        for (int i=0;i<n;i++){
        			ThisSum=0;
        			for (int j=i;j<n;j++){
        					ThisSum+=A[j];
        					compare(Thissum,max);
        		}
        }
        ```
        
        $O(N^3)$
        
    3. Divide and Conquer
        
        ```c
        int border(int l,int r,int a[]){
            int lsum=0,lmax=0,rsum=0,rmax=0;
            int mid=(l+r+1)/2;
            for (int i=mid-1;i>=l;i--){
                lsum+=a[i];
                if(lsum>lmax) lmax=lsum;
            }
            for (int i=mid;i<=r;i++){
                rsum+=a[i];
                if(rsum>rmax) rmax=rsum;
            }
            int bd=lmax+rmax;
            return bd;
        
        }
        
        int DC(int l,int r,int a[]){
            int maxl,maxr;
            if(l==r){
                if(a[l]>0) return a[l];
                else return 0;
            }
            int mid=(l+r+1)/2;
            maxl=DC(l,mid-1,a);
            maxr=DC(mid,r,a);
            int across=border(l,r,a);
            return max(maxl,maxr,across);
        }
        ```
        
        $O(NlogN)$
        
    4. On-line Algorithm
    
        
        ```c
        int online(int a[],int n){
            int Max=0,ThisSum=0;
            for (int i=0;i<n;i++){
                ThisSum+=a[i];
                if(ThisSum>Max) Max=ThisSum; 
                if(ThisSum<0) ThisSum=0;
            }
            return Max;
        }
        ```
        
- **Euclid’s Algorithm
search for gcd**
    
    ```c
    int gcd(int m,int n){
        if (n>m){
            int temp=n;
            n=m;
            m=temp;
        }
        int rem;
        while(n>0){
            rem=m%n;
            m=n;
            n=rem;
        }
        //结束时即整除 此时有（m,0)
        return m;
    }
    ```
    
    $O(logN)$
    
- **Exponentiation**
    
    ```c
    int pow (int x,int n){
    		if(n==0) return 1;
    		if(n==1) return x;
    		if(even(n)){
    			return pow(x*x,n/2);
    		}
    		else return (pow(x*x,n/2)*x);
    }
    ```
    
    $O(logN)$
    

## Chapter 3
Lists,Stacks,and Queues

### List

#### Subquential Lists

#### Linked Lists

#### Doubly Linked Circular Lists

```c
typedef struct node* node_ptr
typedef struct node {
	node_ptr llink;
	element item;
	node_ptr rlink;

};
//An empty list:
node dummy_head;
dummy_head.llink=dummy_head;
dummy_head.rlink=dummy_head;
```

Applications
1. The Polynomial ADT

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled.png)

```c
typedef struct Node *PtrToNode;
struct Node {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Add( Polynomial a, Polynomial b ){
    struct Node* dummyhead=(struct Node*)malloc(sizeof(struct Node));
    dummyhead->Coefficient=dummyhead->Exponent=0;
    dummyhead->Next=0;
    Polynomial pa=a,pb=b,sum=dummyhead;
    
    while(a&&b){
            if(a->Exponent>b->Exponent){
                sum->Next=a;
                sum=a;
                pa=a=a->Next;
            }
            else if(b->Exponent>a->Exponent){
                sum->Next=b;
                sum=b;
                pb=b=b->Next;
            }
            else{
                if(a->Coefficient+b->Coefficient){
                    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
                    node->Exponent=a->Exponent;
                    node->Coefficient=a->Coefficient+b->Coefficient;
                    sum->Next=node;
                    sum=node;
                }
                a=a->Next;
                b=b->Next;
                free(pa);
                free(pb);
                pa=a;pb=b;
            }
    }
    if(a){
        sum->Next=a;
    }
    else if(b){
        sum->Next=b;
    }
    return dummyhead;
}
```

1. Multilists

e.g.

**Suppose that we have 40,000 students and 2,500 courses.  Print the students’ name list for each course, and print the registered classes’ list for each student.**   

```c
See in ./basic/Multilists.c
```

#### cursor implementation of linkede list

### Stack

#### Stack Applicaiton

Balancing Symbols 括号配对

push the left part into the stack, and match the right part with the top, if true pop the top.

$T(N)=O(N)$

---

Postfix Evaluation 

example: $6\space2/3-4\space2*+=8$
$T(N)=O(N)$

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%201.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%202.png)

Infix to Postfix Conversion 

Notes:

- The order of operands is the same in postfix and infix
- Operators with higher precedence appear before those with lower precedence

when encouter an operand, output it ;an operator, push into the stack; when operators are already at top, compare the precedences of the new operator and the top. 

- Never pop a `(` from the stack except when processing a `)`
- Observe that when `(` is not in the stack, its precedence is the **highest**, but when it’s not it is the **lowest.**
Define **in-stack** and **incoming** precedence for symbols.

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%203.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%204.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%205.png)

Function calls

### Queue

a queue is a first-in-first-out (FIFO) list.

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%206.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%207.png)

## Chapter 4
Trees

Note:

every node has only one edge and not connect to other siblings.（A unique path)

terminology

degree of a node: the number of subtrees of the node.
degree of a tree : $Max\{degree\space of\space nodes\}$.

siblings : from the same parent

ancestors : the nodes along the path to the root

leaf (terminal node): degree = 0.

depth : length of the path to the root.

height: $Max${the length of the path to the leaf}.

### Implementation

defined by linked list

```c
typedef struct tree_node* tree_ptr;
typedef struct tree_node{
	element_type element;
	tree_ptr first_child;
	tree_ptr next_sibling;
};
```

defined by array

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%208.png)

### Expression Trees(syntax trees)

先把infix 转成 postfix

From postfix expression 入手

先push 再pop operand 成为operator 的node

### Tree Traversals

#### Preorder Traversal

首先访问根节点，然后递归地遍历左子树，最后递归地遍历右子树。

```c
void preorder (tree_ptr tree){
	if(tree){
		visit(tree);
		for (each child C for tree)
			preorder(C);
	}
}
//stack
//DFS
```

#### postorder Traversal

首先递归地遍历左子树，然后递归地遍历右子树，最后访问根节点。

```c
void postorder (tree_ptr tree){
	if(tree){
		for (each child C for tree)
			postorder(C);
		visit(tree);
	}
}
//stack
//DFS
```

#### Inorder Traversal

首先递归地遍历左子树，然后访问根节点，最后递归地遍历右子树。

```c
void inorder(tree_ptr tree){
	if(tree){
		inorder(tree->Left);
		visit(tree->element);
		inorder(tree->Right);
	}
}
```

```c
//Iterative version

```

#### Levelorder Traversal

```c
void levelorder(tree_ptr tree){
	enquene(tree);
	while(quene is not empty){
			visit (T = dequeue());
			for (child C of T)
				enqueue(C);
		}
}
//BFS
```

三种traversal 与expreesion搭配，（inorder的版本要加括号）

> T的preorder = BT的preorder
T的postorder = BT的inorder
> 

### Threaded Binary Trees

```c
typedef  struct  ThreadedTreeNode  *PtrTo  ThreadedNode;
typedef  struct  PtrToThreadedNode  ThreadedTree;
typedef  struct  ThreadedTreeNode {
       int           		LeftThread;   /* if it is TRUE, then Left */
       ThreadedTree  	Left;      /* is a thread, not a child ptr.   */
       ElementType	Element;
       int           		RightThread; /* if it is TRUE, then Right */
       ThreadedTree  	Right;    /* is a thread, not a child ptr.   */
}

```

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%209.png)

### Binary Trees

#### property

nodes : n ;  edges : n-1 ;

$n=D_2+D_1+D_0$

$n-1=2*D_2+D1+0*D_0$

度为0的节点数=度为2的节点数+1

### Binary Search Trees(BST)

中序遍历一遍就是 从小到大的数列

operations:

```c
Position Find(ElementType X,SearchTree T);
SearchTree insert(ElementType X,SearchTree T);
SearchTree delete(ElementType X,SearchTree T);
```

#### Find

```c
Position Find(int X,SearchTree T){
		if(T == NULL) return NULL;
		if (T->data == X) return T;
		else if(T->data < X) return Find(X,T->right)
		else return Find(X,T->left);
}
//recursive 
Position Iter_Find(int X,SearchTree T){
	while(T){
	if(T->data < X) T = T->right;
	else if(T->data > X) T= T->left;
	else return T;
	}
	return NULL;
}
//iteration
```

$T(N)=S(N)=O(d)$ where d is the depth of X

#### FindMin / FindMax

```c
Position FindMin(SearchTree T)
{
	if(T==NULL) return NULL;
	else
		if(T->Left == NULL) return T;
		else return FindMin(T->left);

}
```

#### Insert

```c
SearchTree Insert (int X,SearchTree T){
	if (T == NULL){
		T = (SearchTree) malloc(sizeof(treenode));
		if(T == NULL)
			FatalError("out of space");
		else {
			T->data = X;
			T->left=T->right=NULL;}
	}
	else // if there is a tree
		if(X < T->element)
			T->left=Insert(X,T->left);
		else if(X > T->element)
			T->right=Insert(X,T->right);
	//already exist x, we'll do nothing
	return T:
}
```

#### Delete

分三种情况：

1. leaf node: 重设它的parent to NULL
2. degree 1 node: 让它的child 代替位置
3. degree 2 node：
找左子树的MAX或者右子树的MIN
同时这两种node一定是degree 为1

## Chapter 5
Priority Queues

### Binary Heap

mintree和perfect binary tree的结合

树的思想，数组来部署

#### Min Tree

每个子树的根节点是子树里最小的数

#### property

- $2^h\leq N\leq 2^{h+1}-1$
- height $h=\lfloor logN\rfloor$

完全二叉树，铺完一层再铺下一层

然后给每个节点自上而下，从左到右编号 1 - n

- 对于节点数为 $N$的Heap，前 $\lfloor N/2 \rfloor$个节点为内部节点，从 $\lfloor N/2 \rfloor +1$到 $N$ 为叶节点

#### Array Representation

任何BST都可以用array来存，但是如果不是perfect，array有很多浪费的空位

`BT[n+1]`（BT[0] is not used）

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

#### Percolate up

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

#### Percolate down

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

#### Insert

只能插入到最后一层的待定区，插入后不能破坏min_tree的结构，要进行父子比较

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2010.png)

例如，
对于形如这样的Heap，我们insert一个9，那么就去和parent进行比较，然后考虑是否互换

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2011.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2012.png)

哨兵(sentinel):
BT[0]=比所有节点都小的数，便于退出祖先for循环

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2013.png)

#### DeleteMin

删除后，

先把最后一个节点挪至根节点处

（不选择去 根节点的children里 去递归替换 的原因是 可能最后不是complete）
再考虑父子间的关系，找到较小的child，递归比较、交换

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2014.png)

#### DecreaseKey(p, $\Delta$ ,H)

减小某个位置的键值，然后一个percolateup

IncreaseKey

增大某个位置的键值，然后一个percolatedown

#### Delete(P,H)

换个思路，把这个地方的键值减小到最小，然后Deletemin
Decrease(P, $\infin$ ,H) ;
DeleteMin;

#### BuildHeap(H)

直接存进数组里，组成一个complete tree，然后找到最大的非叶结点N=n/2, 然后依次PercolateDown(N,N-1,N-2…)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2015.png)

$T(N)=O(N)$

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2016.png)

- MaxHeap,MinHeap转换
    
    对于MaxHeap转换为MinHeap；
    还是用BuildHeap的思想，从N=n/2处开始PercolateDown
    

## Chapter 6
Sorting

### Insertion Sort 插入排序

类似于抓牌时，边拿边理牌

步骤：

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

worst case: $T(N)=O(N^2)$

best case: $T(N)=O(N)$

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2017.png)

因为每次相邻元素的交换只会使逆序对减1，那么插入排序的总操作次数，就是N个元素过一把，加上I次swap

$T(N,I)=O(I+N)$

---

两个定理：

1. 对于一个N元素数组，它逆序对的个数为，
$I=C_n^2 * 0.5 = N(N-1)/4$
2. 那么凡是通过交换相邻元素实现排序的算法，一定是有平均复杂度 $\Omega (N^2)$

### Shell sort 希尔排序

每间隔n来取数，并把取的数字进行`insertion sort`（这种非相邻元素的交换，可以保证逆序对的纠正 ≥1）

间隔依次减小，最后减小到1

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2018.png)

而且进行 $h_{k-1}$-sorted时，会保证 $h_k$-sorted

---

increment sequence 的取法

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2019.png)

希尔本人是 除2来取，但实际上并不好

#### Hibbard’s Increment Sequence:

$h_k=2^k-1$

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2020.png)

这样子 $h_i$之间彼此互质

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

记得选择排序 $O(N^2)$就在于每次遍历n元素才能确定最小值，于是构建最小堆，就可以用 $O(logN)$来找到最小值

#### Algorithm 1 费内存

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2021.png)

算法一有点浪费空间，
我们会发现每次deletemin 完，数组末尾会有空余位置，于是

#### Algorithm 2 (in-place)

我们采用 `MaxHeap`

每次 DeleteMax 都是在把 H[0] 与 H[tail]交换

然后pecolatedown(0);

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2022.png)

$T(N)=O(NlogN)$
无论best、worst、average case 都是很好的NlogN

这个版本是
in-place, 非 stable

### Merge sort 归并排序

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2023.png)

前置思想：Merge两个有序list，就是和合并链表一样，从头比较

于是

MergeSort(分治思想)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2024.png)

要点解析：

1. `if(Left < Right)` 就代表了递归停止的时候，只剩一个元素(Left=Right)
先递归Msort(也就是分半)，再调用Merge
2. `void Mergesort` 就是个`TmpArray`启动器,
记得给TmpArray分配空间，调用Msort时是从`0~N-1`

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2025.png)

要点解析：

1. 两段序列，一个是从 `Lpos~LeftEnd=Rpos-1` ，另一个是从 `Rpos~RightEnd` ,总元素 `NumElements= RightEnd-Lpos+1`
2. 紧接着三重while，
第一重，两序列比较，未到End时，边比边退
第二、三重，走完未尽的道路
3. 最后倒着一个个赋值，其实可以（开始的时候i=Lpos,然后正向赋值)

#### Analysis

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2026.png)

$T(N)=O(NlogN)$

不是 `in-place` 但是`stable`

### Quick sort 快速排序

先找到一个`pivot`然后整个序列进行一个partition，一部分比pivot小，一部分比它大；然后递归进行

#### Picking the Pivot

问题在于 如何选择一个好的`pivot`

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2027.png)

综上：选取位置上的第一个，最后一个和中间数，选择其中这三个里的中间大小的数

#### Partition strategy

1. 把选取的 `pivot`移至末尾
2. 给定 i,j 两个指针分别指向 a[0]和a[n-2]
3. i负责比pivot大的部分，j负责比pivot小的部分
4. 一旦有一方不符合，直接互换a[i]和a[j]
5. 最后 j会在i前面，且两者相邻，于是我们交换末尾a[n-1]的pivot 和 a[i]

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2028.png)

注意：

1. 当 a[i] or a[j] == pivot 时，我们就互换一下 a[i]和a[j]就好了，然后让i和j继续往前走

#### Small Array

当数据量 $N \leq 10$时，QuickSort实际没有insertion sort来的快，于是我们可以在partition到10以内的数据量时调用insertion sort

#### Implementation

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2029.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2030.png)

注意细节：`pivot` 被放在了 `A[Right-1]`
是因为我们真正需要 管理排序的部分 其实是 A[Left+1] 到 A[Right-1]

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2031.png)

注意细节：为了配合 `++i,—-j`  i和j 分别初始化为 Left和Right-1

#### Analysis

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2032.png)

#### Kth largest

因为在quicksort的partition环节，我们可以确定pivot是数组中第i大的数(从0开始记)，于是

k≥i,去右边找；k≤i，去左边找

### Table Sort

**Problem:交换两个特别大的结构是十分expensive的**

Solution:只是挪动 指针

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2033.png)

### General Lower Bound for Sorting
排序算法的下界

任何用比较实现的算法只能有 $\Omega(NlogN)$的最坏情况时间复杂度

引入：**决策树**

假设3个元素 $K_0,K_1,K_2$

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2034.png)

`Worst case`的时间复杂度 在决策树中就是depth

那对于最优良的算法（树）的形态就应该是complete binary tree

### Bucket Sort and Radix Sort

#### Bucket Sort

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2035.png)

我们划分出M个桶来分装 N个元素

当 N>>M时，是极好的 $T(N,M)=O(N)$

---

当M>>N时

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2036.png)

我们观察到虽然 M很大，但是1000这个数字实际上位数不多，于是便有了 Radix Sort 基数排序

#### Radix Sort

依次基于位数字进行的桶排序

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2037.png)

利用上一轮排序的结果，可以快速得到下一个桶的排序

$T(N)=O(P(N+B))$

P是Pass数也就是位数，N+B就是每次pass的桶排序

#### MSD(Most Significant Digit) Sort 最高有效位排序

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2038.png)

#### LSD(Least Significant Digit) Sort 最低有效位排序

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2039.png)

## Chapter 7
Hashing

### 引入：Interpolation Search

我们试图在一个分布较均匀的sorted list中，找到一个好的起始划分点，而不总是对半砍

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2040.png)

### ADT: Symbol  Table

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2041.png)

### Hash Tables

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2042.png)

行是b个bucket，列是s个slot

然后我们有一个映射函数 $f(x)$（哈希函数）可以用来确定 $x$在哪一个bucket中

Loading density $\lambda=n/(s*b)$

---

意外情况:

1. `collision`
$f(i_1)=f(i_2),i_1\neq i_2$
2. `overflow`
往满的的bucket里塞了新的 identidier，（有overflow一定有collision）

### Hash Function

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2043.png)

性质：

1. $f(x)$尽可能简单并且减少冲突
2. $f(x)$要unbiased,每个x分配到bucket的可能性均等

#### For integers

$f(x)=x~ \%~ TableSize$

实践发现，`TableSize` 最好是一个 较大的质数

#### For string

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2044.png)

用位操作解决乘法

### Separate Chaining

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2045.png)

这个哈希表就是一个装有指针的数组(`List *TheLists`)

然后每个指针往后构成一个个链表（bucket）

这样就不会 `overflow`

---

#### Create empty table

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2046.png)

---

#### Find Key

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2047.png)

用hash function找到属于哪个bucket，然后遍历链表

P可能是NULL或者是找到，所以有两个终止情况

---

#### Insert Key

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2048.png)

一开始去`Find Key` 是否已经存在

存在的话就什么也不干，

否则，`Pos==NULL`,用hash function去算bucket去插在头（不插末尾就不用遍历）

注意：

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2049.png)

想优化的话，就要利用好Find里算过的`HashVal`

### Open Addressing
开放寻址

> Find Another empty cell to solve collision(avoiding pointer)
> 

我们的哈希表假设是一个slot，没有链表什么的

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2050.png)

引入一个偏移量i，去冲突的 $Hash(x)$附近找空位

这里的 $f(i)$是冲突处理函数，不是哈希函数

#### 1.Linear Probing

$f(i)=i$, a linear function

优点：有空一定能找到

缺点：search time过多

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2051.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2052.png)

引入一个期望探测次数 $p$,来判断probe是否 good

#### 2. Quadratic Probing

$f(i)=i^2$

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2053.png)

Find操作

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2054.png)

Find是在找x应处的位置，空位或者是x已经存储的位置

解读：

1. while循环条件，检查是否empty 同时检查是否为所找数字
2. $i^2-(i-1)^2=2i-1$

---

insert操作

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2055.png)

delete操作

并不是把某个元素直接删去，而是把状态设置成deleted，然后保留元素在原位，不然find会断层！

然而delete元素过多之后，insert就会大大受影响，出现secondary clustering问题

---

#### 3. Double Hashing

$f(i)=i*hash_2(x)$

注意：

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2056.png)

### Rehashing

1. 开个新表，比原来至少大1倍
2. 扫描原表中未被删除的元素
3. 用一个新的hash function去转移元素

$T(N)=O(N)$

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2057.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2058.png)

## Chapter 8 
The Disjoint Set

### Equivalence Relations

要满足reflexive（自反性），symmetric（对称性），transitive（传递性）

### Algorithm

所以我们为了实现这个并查集，就主要运用Union和Find函数，让每个元素一开始成为单独的集合

然后利用Find找到根，Union两个集合

#### Union（i,j）

利用数组下标和对应元素来部署

`S[element]= parent’s index`
`S[root]=0` 

数组下标就是这个数，存放的元素是对应父节点的下标，根节点下标为0

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2059.png)

只要轻轻改动对应子集的 根节点的元素 就能完成Union

Note：对于不是按1-N给的数据，可以另开一个数组来映射

#### Find（i）

```c
for(;S[X]>0;X=S[X]); //有个分号
return X;
```

#### Final Presentation

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2060.png)

先初始化数组设定为独立的集合，然后根据关系查找根，根不同的集合Union到一起

#### Smart Union

- Union-by-size
    
    S[root]=-size 关键步骤
    
    将根节点原先的元素0利用起来，用来记录整个Set的大小，用负数避免误判为index，一开始就初始化为-1
    
    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2061.png)
    

#### Path Compression

将一路的祖先的parent设置为根节点,来减少后续Find的压力

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2062.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2063.png)

## Chapter 9
Graph Algorithms

### Definitions

#### Undirected graph

$(v_i,v_j) = (v_j,v_j)$

#### Directed graph

$<v_i,v_j> \neq <v_j,v_j>$

#### Complete graph

$V=n, E=C_{n}^{2}$

#### path

从 $v_p$到 $v_q$ 经过的路径

- simple path： $v_p$到 $v_q$路径上的每个点都不同

#### Special graph

- tree
    
    联通无环的图
    
- DAG
    
    有向无环图
    
- Strong connected directed graph
    
    强联通：存在任意两点间的有向路径
    弱连通：存在任意两点间的无向路径
    

#### Degree

in-degree（入度）：射入v的edge个数
out-degree（出度）：v射出的edge个数

结论：

图里边个数的顶点度数和的一半

$$
e=(\sum_{i=0}^{n-1}d_i /2) 
$$

### Representation

#### Adjacency Matrix

把表示的每一条边存入数组中 <vi,vj>

$$
adj\_mat[i][j] = \begin{cases} 1 & \text{if }(v_i,v_j) \space \text{or }<v_i,v_j>\in E(G) \\ 0 & \text{otherwise }  \end{cases}
$$

无向图只需要存储一半的数据

对于度数的计算：

无向图：d(i)=遍历第i行

$$
degree(i)=\sum_{j=0}^{n-1}adj\_mat[i][j]
$$

有向图：d(i)=遍历第i行+遍历第i列

$$
degree(i)=\sum_{j=0}^{n-1}adj\_mat[i][j]+\sum_{j=0}^{n-1}adj\_mat[j][i]
$$

$T(N)=O(N^2)$

#### Adjacency Lists

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2064.png)

`graph[i]`表示 $v_i$指向的所有的顶点

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2065.png)

再开个来表示`in-degree`的

#### Adjacency Mutilists

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2066.png)

用node来表示所有的边，node里的指针就代表了哪l两个vertice

#### Weighted Edges

数组表示的话：
adj_mat[i][j]把存的数值从1更改为weight

链表或者多重表：

增加一个weight变量

### Topological Sort

对象：DAG（有向无环图）

对于序列 $V_1,V_2,V_3...V_n$

必须保证 $<V_i,V_j>$存在，

即 $V_i$是predecessor，$V_j$是successor

那么我们只需要每次挑选 In-Degree 为 0 的顶点

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2067.png)

### Shortest Path Algorithms

#### Unweighted Shortest Path

CurrDist是当前步数

找到符合CurrDist的V顶点，然后标记为Known，然后对于每个相邻的顶点，把距离进行变换，然后入队

#### Single-Source Problem

如果有负环则无解，而不是负边来决定

#### Dijkstra’s Algorithms

1.select 如何选择符合条件的点

2.update 如何更新相邻顶点的值 (d[u]+Cuv ? d[v])

两种部署:

Dense的情况，我们用数组(simply scan the table)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2068.png)

$T=O(V^2+E)$

---

Sparse的情况，用minheap

此处补代码

$T=O(VlogV+ElogV)$

#### AOE

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2069.png)

在项目管理和调度理论中，"Earliest Completion Time"（最早完成时间），"Latest Completion Time"（最晚完成时间）和 "Slack Time"（浮动时间）是关键的概念，它们帮助我们理解和管理项目的时间表和进度。

1. **Earliest Start Time（最早完成时间）**: 这是指在给定的前提条件下，任务或项目能够完成的最早时间点。这通常基于任务的最早开始时间和所需的工作量来计算，同时考虑到任何前置任务的完成时间。在项目调度中，计算每个任务的最早完成时间有助于确定项目的最短可能持续时间，并帮助项目经理优化资源分配。
2. **Latest Complete Time（最晚完成时间）**: 这是一个任务或活动在不延误整个项目的情况下可以完成的最晚时间。这个时间通常是通过向后计划法（从项目结束时间开始，向前推算每个任务的最晚开始和结束时间）计算出来的。
3. **Slack Time（浮动时间）**: 这是一个任务或活动的开始或结束时间可以在不影响其他任务或整个项目进度的情况下延后的时间长度。换句话说，这是任务或活动的开始或结束时间相对于其最早开始时间或最晚完成时间的"弹性"。浮动时间可以用来调整项目计划，以应对不可预见的延误或其他问题。

这些概念在关键路径方法（Critical Path Method，CPM）中被广泛使用，关键路径方法是一种用于计划和管理复杂项目的技术。在这种方法中，关键路径是项目中所有路径中最长的路径，它决定了项目的最短完成时间。关键路径上的任务通常没有浮动时间，因为它们的延误会直接影响到整个项目的完成时间。

---

### Network Flow Problems

引入两个图：流量图(Flow)和残量图(Residual)

用反向边来修正

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2070.png)

总的步骤：

1. 从Residual找一条从s到t的path，流量就是整个路径上的最小权重
2. 然后在Residual上减小正向边权重的同时增加刚刚所选路径的反向边和权重
3. 然后重复上述步骤，直到没有从s到t的路径

即便如此，还是有值得改进的地方，例如这个e.g.

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2071.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2072.png)

也就是说，我们选边是要有原则的

选增量最大的边或者是路径最短的边 总是好的

### Minimum Spanning Tree
（最小生成树）

一个图的子集，包含所有的顶点，就是spanning tree

Minimum 就是 所有边的cost和最小

边数恰好为 $E=V-1$

存在最小生成树 $\text {iff}$ G是联通的 

#### Prim’s Algorithm

similar to Dijkstra

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2073.png)

从一个点开始，

去走

已知的

cost最小的

能到未知顶点的边

（此例中顺序为 $V_1-V_4,V_1-V_2,V_4-V_3,V_4-V_7,V_7-V_6,V_7-V_5$)

#### Kruskal’s Algorithm

类并查集算法

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2074.png)

从边入手，

建一个最小堆存放所有的边 

然后 依次delemin，也就是每次都去选择cost最小的边

对于每条边我们去 union/find 他们的顶点是否存在过（或者说顶点是不是在同一root下）

### DFS

对比：

BFS是从一个点往一个相邻顶点向外扩散

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2075.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2076.png)

与前序遍历的区别是，树里面有父子关系，只从父到子；

而图里面两个点之间互为邻接，所以要有一个 `if(!visited[W])`

#### DFS in Undirected Graphs

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2077.png)

其实是两个函数，一个是`DFS`，另一个是`ListComponents`,因为DFS只处理连通图，对于多个组件我们就需要用这个函数

#### DFS in Biconnectivity

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2078.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2079.png)

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2080.png)

- 关节点是指，删除这个顶点后，图会产生至少两个联通组件
- 双联通图就是没有关节点的图；即任意拿掉一个顶点，图仍联通
- 双联通组件，注意Maximal

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2081.png)

可以发现没有边被两个或多个双联通组件共享

---

利用DFS寻找双联通组件

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2082.png)

DFS走出来的最小生成树中，未走过的`Back edges`一定是祖孙关系，不可能是平行关系，然后祖先的index肯定比后代的index小

---

寻找关节点：

1. 根节点如果有两个以上的children，则root一定是关节点
2. 一个非叶节点即有至少一个child，如果它往下走n步却还是能通过back edges等回到它的祖先，那它就不是关节点；反之就是关节点
（因为 如果能回到祖先，那就算拿掉这个点 也仍然联通；如果不能回去，那么和祖先断联了）

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2083.png)

---

借此我们引入一个函数 `Low(u)`

$Low(u)=\text{min}\{Num(u),\\ \text{min}\{Low(w)|w \text{ is a child of u}\},\\ \text{min}\{Num(w)|(u,w) \text{ is a back edge}\}\}$

`Low(u)` 就是顶点 u 能通过自己或者自己的后代的back edge 所能到达的最远祖先（所以是min）

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2084.png)

1. root还是只看有无多孩子
2. 非叶节点，如果存在一个孩子的祖先不能在我之上，我就会和祖先断联

#### DFS in Euler Circuits

一笔画问题

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2085.png)

欧拉路径：就是一笔画

欧拉回路：就是起末点都相同的一笔画

两个结论：

1. 只有当所有顶点都是偶数的度，才有可能存在欧拉回路
2. 只有当仅两个顶点是奇数的度且其余顶点都是偶数的度，才有可能存在欧拉路径

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2086.png)

## Self-Study

- sparse matrix

## 题目集

### 判断题

#### Lists,Stack,Queue

1. If a linear list is represented by a linked list, the addresses of the elements in the memory must be consecutive. 
False
这句话是不正确的。在链表中，元素的内存地址并不需要连续。链表的每个元素（通常称为节点）包含数据和指向下一个节点的指针。这些节点可以在内存中的任何位置，不需要连续。这是链表与数组的主要区别之一，数组的元素在内存中是连续的，而链表的元素则不是。
2. Buffer是一种Queue
    
    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2087.png)
    

### 选择题

#### Lists,Stacks,Queues

1.

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2088.png)

分别标号为 $o_1p_1p_2o_2$，成功的序列只能是 `o1p1p2o2, o1p2p1o2, o2p2p1o1`

#### Trees

1. 删除一个根节点时，只能选左子树的MAX或者右子树的MIN
    
    ![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2089.png)
    

#### QuickSort

1.

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%2090.png)