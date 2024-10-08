# X86 汇编语言

## Lec 2

### 标号
- 在汇编语言中，**标号（Label）**是指向代码或数据位置的标识符。标号允许程序员在汇编代码中引用**内存地址**，而不需要知道具体的地址值。这使得代码更易于编写、阅读和维护。
```asm
main:         
    mov eax, 0 
    mov ebx, 1
again:
    add eax, ebx
    add ebx, 1  
    cmp ebx, 100
    jbe again   
```

### wsprintf

- `wsprintf`是windows系统内部的函数，对应C标准库的`sprintf`  
- `sprintf`是C语言标准库中的一个函数，用于将**格式化的数据写入字符串**。它是`printf`函数的一个变体，`printf`将格式化的数据输出到标准输出（通常是**屏幕**），而`sprintf`则将格式化的数据输出到一个**字符串**中。
```c
char result[100], format[] = "%d";
sprintf(result,format,5050);
sprintf(&result[0],&format[0],5050);
```

!!! note "invoke, offset"
    - `invoke`是在某些汇编语言环境中用于简化函数或过程调用的指令。它的目的是使函数调用更加直观，类似于高级语言中的函数调用。invoke指令会自动处理参数的传递和调用约定，简化了传统汇编中手动压栈和设置寄存器的过程。  
    - `offset`是一个操作符，用于获取变量、标号或函数的内存地址。


### MessageboxA
- `MessageBoxA`是**Windows API**中的一个函数，用于显示一个模态对话框，该对话框包含一条消息和一些按钮（如“确定”和“取消”）

```asm
invoke MessageBoxA, 0, offset result, offset prompt, 0
```
```c
int MessageBoxA(
  HWND   hWnd,
  LPCSTR lpText,
  LPCSTR lpCaption,
  UINT   uType
);
```
- hWnd：父窗口的句柄。如果此参数为NULL，消息框没有父窗口。  
- lpText：消息框中显示的文本。  
- lpCaption：消息框标题栏的文本。  
- uType：定义消息框样式的选项，比如消息框中按钮的类型（如MB_OK、MB_OKCANCEL等）和图标（如MB_ICONWARNING、MB_ICONERROR等）  


### .data

- 在汇编语言中，`.data`段是用来声明**初始化**的数据或变量的区域。这些数据在程序开始执行前就已经被分配和初始化了。`.data`段通常包含的是程序中将要使用的**静态数据**，比如字符串、整数等。这些数据在程序的整个生命周期内都是可用的，并且它们的值可以在程序执行过程中被修改。  

```asm
.data
result db 100 dup(0); dup:duplicate重复
;char result[100]={0};
format db "%d",0; db:define byte字节类型
; char format[3]="%d";
prompt db "The result",0
```
!!! warning "注意"
    - 在定义数据的时候，把变量名放在最前面，然后跟数据类型，最后接赋值内容  
    - 其中注意**字符串**，要手动在最后加`\0`  

-----

### 打印

!!! note "Example-Hello World"
    === "输出Hello,world!"
        ```asm
        data segment
        hello db "Hello,world!", 0Dh, 0Ah, '$'
        data ends

        code segment
        assume cs:code, ds:data
        main:
            mov ax, data
            mov ds, ax
            mov ah, 9; ah = 9 用来指定要调用的子函数编号
            mov dx, offset hello
            int 21h; interrupt
            mov ah, 4Ch
            mov al, 0
            int 21h
        code ends
        end main

        ```

        - `0Dh`代表回车，`0Ah`代表换行，`$`在DOS中表示字符串结尾  
        - `int 21h`是在DOS操作系统及其编程环境中使用的一种**中断调用**，用于访问DOS提供的各种系统服务，`21h`指定了DOS中断处理程序的编号，其中有许多**子函数**  
        - `ah = 9` 用来指定要调用的**子函数**编号，此处代表*Write String to Standard Output*  
        - `ds`寄存器只能接受一个**变量**或者**寄存器**给它赋值，**不能接受一个常数**  
        - `data` 代表了`hello`的**段地址**，其中`mov ax, data`还可以写成`mov ax, seg hello`  
        - 最后末尾的`int 21h`相当于`exit(0)`，最后三条指令不能改成`ret`，否则会死机；也不能删除，否则cpu会继续执行后续代码导致死机  

    === "输出Hello$world"        
        - 不能像之前程序一样调用`9h`一口气输出，因为有`$`在中间  
        - 于是一个个取然后打印
        
        ```asm
        data segment
        a db "ABC"
        s db "Hello$world", 0Dh, 0Ah, 0
        data ends

        code segment
        assume cs:code, ds:data
        main:
            mov ax, seg s
            mov ds, ax
            mov bx, 0
        next:
            mov dl, s[bx]; 编译后会变成mov dl, ds:[3+bx]
                         ; 其中ds是s的段地址，3是s的偏移地址
            cmp dl, 0
            je exit
            mov ah, 2
            int 21h
            add bx, 1
            jmp next
        exit:
            mov ah, 4Ch
            mov al, 00
            int 21
        ```

        - 在`data segment`中定义了一个没有用的a变量，于是得出s在段地址中的偏移地址为3（a的字节数）  
        - 然后我们一个个读取字符并打印
    
        !!! info "标志寄存器"
            - **标志寄存器（Flag Register）**是CPU中的一个特殊寄存器，用于指示处理器的状态或者指令执行的结果。它包含了多个标志位（Flag Bits），每个标志位代表了不同的状态或条件。在执行指令后，这些标志位会根据指令的执行结果被设置（置1）或清除（置0）。  
                - 零标志（ZF, Zero Flag）：如果指令执行的结果为0，则设置此标志。  
                - 符号标志（SF, Sign Flag）：如果指令执行的结果为负，则设置此标志。  
                - 进位标志（CF, Carry Flag）：在执行算术运算时，如果最高位产生了进位或借位，则设置此标志。  
                - 溢出标志（OF, Overflow Flag）：在执行算术运算时，如果结果超出了目标数据类型的表示范围，则设置此标志。  
                - 奇偶校验标志（PF, Parity Flag）：如果指令执行的结果中1的数量为偶数，则设置此标志。  
            - 标志寄存器的内容会影响程序的流程控制指令，如**条件跳转指令**  
            - 因此，不同于`if`，在到达跳跃语句前，如果比较量发生了改变，`cmp`结果即标志寄存器仍然会**随之改变**  


## Lec 3

### td调试
- ++ctrl+g++可以查看输入地址的对象内容；  
- ++ctrl+o++可以返回将要执行的指令处  
- ++alt+f5++可以查看程序运行结果  

----


### gets

```asm
data segment
s db 100 dup(0)
data ends

code segment
assume cs:code, ds:data
main:
    mov ax, seg s
    mov ds, ax
    mov bx, 0
input:
    mov ah, 1
    int 21h
    cmp al, 0Dh
    je input_done
    mov s[bx], al
    add bx, 1
    jmp input
input_done:
    mov s[bx], 0 ; 字符串末尾'\0'
    mov bx, 0
    mov ah, 2
    mov dl, 0Ah
    int 21h
output:
    mov dl, s[bx]
    cmp dl, 0
    je output_done
    cmp dl, 'a'
    jl not_lower_case ; 小于a则不是小写字母
    cmp dl, 'z'
    jg not_lower_case 
is_lower_case:
    sub dl, ' '
not_lower_case:
    mov ah, 2
    int 21h
    add bx, 1
    jmp output
output done:
    mov ah, 4Ch
    mov al, 0
    int 21h
code ends
end main
```
