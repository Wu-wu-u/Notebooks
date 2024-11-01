# Processor

![alt text](pr_2.png)


## Datapath

!!! abstract "Overview"

    ![alt text](pr_1.png)

    - **PC** 寄存器存储当前运行到的指令的地址。**PC** 寄存器连到 **Instruction memory** 中，读出的结果就是当前要运行的指令。这个指令被 **Control** 解析产生相应的信号。


??? note "CPU在干什么"
    1. Fetch
        
        - 从memory中读取指令

        - 调整PC指针

    2. 解码指令并读取operand
        
        - 我们根据三种register在指令中的位置来确定读取哪些register operands，虽然不一定要用但一定要读

    3. 进行控制

        - 控制ALU进行哪个操作

    4. 访问内存

        - 决定是读取还是写入内存

    5. 结果写入寄存器

        - R-type **ALU结果**写入`rd`；I-type **MemoryData**写入`rd`

    6. 调整PC指针到跳转处(branch target)


---


### R型指令

![alt text](pr_3.png)




### 跳转

### Load和Store

### Control

|信号名称|置0时|置1时|
|---|----|----|
|RegWrite|不写入|写入WriteRegister|
|ALUScr|Rs2|立即数|
|Branch(PCSrc)|PC+4|跳转地址|
|Jump|PC+4|跳转地址|
|MemRead|不读|结合`address`从memory中读取数据|
|MemWrite|不写|往`address`处写入`Write data`|
|MemtoReg(**两位**)|00:选择ALU的结果|01:选择`memory data`；10:选择PC+4|


- 7+4的控制信号组合

- 我们发现只看opcode就可以决定7个控制信号，然后再去分析ALU的控制信号

- 于是我们采用两层解码的方式来控制


!!! tip "Main Controller"

    - 123


---

!!! tip "ALU Controller"

