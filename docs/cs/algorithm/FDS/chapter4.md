## Chapter 4
!!! note
    every node has only one edge and not connect to other siblings.(A unique path)

### terminology

- degree of a node: the number of subtrees of the node.
- degree of a tree : $Max\{degree\space of\space nodes\}$.

- siblings : from the same parent

- ancestors : the nodes along the path to the root

- leaf (terminal node): degree = 0.
 
- depth : length of the path to the root.
 
- height: $Max${the length of the path to the leaf}.

### Implementation

- defined by linked list

```c
typedef struct tree_node* tree_ptr;
typedef struct tree_node{
	element_type element;
	tree_ptr first_child;
	tree_ptr next_sibling;
};
```

- defined by array

![Untitled](Fundamentals%20of%20Data%20Structures%20505ba7ea12b7454ab10fc2d6a857950f/Untitled%208.png)

### Expression Trees(syntax trees)

- 先把infix 转成 postfix

- From postfix expression 入手

- 先push 再pop operand 成为operator 的node

### Tree Traversals

=== "Preorder Traversal"

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

=== "postorder Traversal"

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

=== "Inorder Traversal"

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

=== "Levelorder Traversal"

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

!!! note
    **T的preorder = BT的preorder**  
    **T的postorder = BT的inorder**
 

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

- nodes : n ;  edges : n-1 ;

- $n=D_2+D_1+D_0$

- $n-1=2*D_2+D1+0*D_0$

- 度为0的节点数=度为2的节点数+1

### Binary Search Trees(BST)

中序遍历一遍就是 从小到大的数列

**operations:**

```c
Position Find(ElementType X,SearchTree T);
SearchTree insert(ElementType X,SearchTree T);
SearchTree delete(ElementType X,SearchTree T);
```

=== "Find"

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

=== "FindMin / FindMax"

    ```c
    Position FindMin(SearchTree T)
    {
        if(T==NULL) return NULL;
        else
            if(T->Left == NULL) return T;
            else return FindMin(T->left);

    }
    ```

=== "Insert"

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

=== "Delete"

    分三种情况：

    1. leaf node: 重设它的parent to NULL
    2. degree 1 node: 让它的child 代替位置
    3. degree 2 node：
    找左子树的MAX或者右子树的MIN
    同时这两种node一定是degree 为1
