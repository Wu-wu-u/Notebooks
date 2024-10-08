## Lists

### 增删

=== "增添、插入"
    - `list.append()`：将元素添加到列表末尾  
    - `list.insert(index,object)`：必须明确索引处，然后将元素插入到`index`**前面**
    - `list.exetend(iterable)`：将可遍历对象中的元素添加至`list`末尾
        ```python
        >>> list = [5,4,3,2,1]
        >>> list.extend('string')
        >>> list
        [5, 4, 3, 2, 1, 's', 't', 'r', 'i', 'n', 'g']
        ```

=== "删除"
    - `del`：可以删除某个**元素、列表、键值对**  
        - `del list[0]`,`del list`  
        - `del`删除后无法再访问  
    - `list.pop(index=-1)`：类似于栈**弹出栈顶元素**
        - 默认`index`为`-1`，即栈顶元素；可以修改索引来任意弹出
        - 有一个**返回值**即弹出的元素
    - `list.remove(value)`：删除**特定值**的元素
        - 如果有**多个**符合条件的变量，则只删除**第一个**
    
### 排序

=== "`list.sort()`"
    - `list.sort(key=None,reverse=False)`
        - 这个排序是**in-place**且**stable**的  
        - 默认升序排列，如果`reverse=True`则降序
        - 可以传入一个`key`**函数**，会对每个元素调用`key`函数后根据结果进行排序
        - 这个排序是**永久性**的

=== "`sorted()`"
    - `sorted(iterable,key=None,reverse=False)`
        - 这个函数**返回**一个**新的列表**

=== "`list.reverse()`"
    - **in-place**永久性翻转

------

## Tuple

??? info "读音"
    - 有趣的是`Tuple`有两种读音，**/'tjʊpəl; 'tʌpəl/**

### 定义元组

- 我们使用圆括号(parenthesis)而非方括号(brackets)  
    - 同时也可以不用圆括号，任何由**逗号分隔开**的变量都会被解释为`tuple`  
    ```python
    >>> (3,4,5)
    (3,4,5)
    >>> 3,4,5
    (3,4,5)
    ```
- 我们也可以使用`tuple(iterable=())`，返回一个与原序列相同的`tuple`  

----

### 不可变对象

- 元组是**不可变对象**  
    - 可以用作字典中的`key`：`{(1,2):'a'}`  

----

## Dictionary

### 添加键值对

- **赋值**：
    - `dict[1] = '1'`，就会多一个键值对 `1:'1'`

### 删除

- `del `
    - `del dict[1]`，会删除key`1`同时删除与之绑定的value
    - 删除的键值对永久消失

### 访问

- `dict.get(key,default=None)`
    - 第一个参数传入key，第二个参数是如果key**不存在**时让方法**返回什么**
- `dict.keys()`,`dict.values()`,`dict.items()`：返回键或值或键值对的序列
- `in`：可以使用`in`来检查某个`key`是否存在

## 读取文件

- `open(file, mode='r', buffering=-1, encoding=None, errors=None, newline=None, closefd=True, opener=None)`  
    - `file`：要打开的文件的名称（路径）。  
    - `mode`：打开文件的模式。默认为`'r'`，表示以只读方式打开文件。其他模式包括写入（`'w'`）、追加（`'a'`）、二进制（`'b'`）、更新（`'+'`）等。  
    - `buffering`：设置文件缓冲的大小。-1表示使用系统默认缓冲大小，0表示不缓冲，1表示缓冲一行。  
    - `encoding`：用于解码或编码文件的编码方式。例如，使用`'utf-8'`进行编码。  
    - `errors`：指定如何处理编码和解码错误，常见的值有`'strict'`、`'ignore'`、`'replace'`等。  
    - `newline`：控制如何处理换行符，可选值有`None`、`''`、`'\n'`、`'\r'`和`'\r\n'`。  
    - `closefd`：如果打开的是一个文件，则设置为`True`；如果是一个文件描述符，则设置为`False`。  
    - `opener`：一个可调用的对象，用于自定义文件打开过程，接收文件名和标志作为参数。

- 方法:  
    - `read(size=-1)`方法从文件中读取并返回最多`size`个字符（在文本模式下）或字节（在二进制模式下）。如果未指定`size`或指定为负数，则读取并返回文件的全部内容。  
    - `readlines(hint=-1)`方法读取文件直到末尾，返回一个列表，其中每个元素是文件中的一行。`hint`参数可以指定读取的大致字节数，但实际读取的内容可能会超过这个数，因为读取会继续直到完整的行。如果未指定`hint`或指定为负数，则读取并返回文件的所有行。
    - `write(content)`方法用于将字符串`content`写入文件。如果要写入的内容不是字符串，则需要先将其转换为字符串。

    - `writelines(lines)`方法用于将一个字符串**列表**`lines`写入文件，列表中的**每个字符串代表一行**。`writelines`**不会自动添加行结束符（如\n）**，因此如果需要在每行末尾添加行结束符，必须在列表的每个元素中手动添加。

```python title="Example"
with open('input.txt','r') as file:
    content = file.read()
with open('output.txt','w') as file:
    file.write(content)
```


