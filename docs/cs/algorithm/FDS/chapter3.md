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

```c
// 队列的节点
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 队列
typedef struct Queue {
    Node *front, *rear;
} Queue;

// 创建一个新的节点
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// 创建一个空的队列
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// 添加元素到队列
void enqueue(Queue* q, int data) {
    Node* temp = newNode(data);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// 从队列中移除元素
void dequeue(Queue* q) {
    if (q->front == NULL)
        return;

    Node* temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}
```
