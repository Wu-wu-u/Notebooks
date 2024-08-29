# Chapter 7 Memory Basics

## 内存

- **内存(Memory)**由一系列存储单元与相应的逻辑电路组成，计算机中的内存包括两类：**随机访问内存(Random-Access Memory)**与**只读内存(Read-Only Memory)**。这两类内存都需要借助**地址(address)**来实现对数据的读与写。其中，只读内存（即 ROM）的相关知识已经在 [第五章#ROM](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap05/#rom) 中提及，本章主要讨论随机访问内存（即 RAM）。

---

### **组织架构**

- **内存组织架构(Memory Organization)**反映了内存中的数据是如何通过地址被访问的。

### **数据类型**

- 计算机中常用的数据类型主要有三种：

    - **位(bit)**：最小单元
    - **字节(byte)**：8 个连续的 bit
    - **字(word)**：特定数量的连续的 bit，由内存类型决定，传统意义上 1 word = 4 bytes

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20256.png)

- 考虑一个 $2𝑘×𝑛$ 的内存单元， $k$ 表示地址的位宽， $𝑛$ 表示 word 的位宽。这个内存单元的示意图如下，其中，*k*-bit 的地址经过 decoder 译码，得到的 2𝑘 个输出分别与 2𝑘 个 word 形成唯一确定的连接，从而达到寻址的目的；每个 word 由 𝑛-bit 组成，所以输入和输出也都是 𝑛-bit 的。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20257.png)

### 基本操作

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20258.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20259.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20260.png)

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20261.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20262.png)

- 总之，地址信号先进来等待译码结束后再传入读写信号，最后再有一段恢复时间

## 静态内存

- RAM 可以分为**静态内存(Static RAM, or SRAM)**和**动态内存(Dynamic RAM, or DRAM)**两种：

    - SRAM：数据存储在锁存器(latch)中；
    - DRAM：数据存储在电容中，以电荷量的形式存储；

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20263.png)

- 静态内存更复杂更快但成本更高

### **SRAM Cell**

- 首先考虑一个 SRAM 的最小单元，即 **SRAM Cell**（下面简称为 RAM Cell），用于存储 1-bit 的信息。

- 这个 RAM Cell 是通过一个 SR Latch 实现的，当 select 置 `0` 时，表示 RAM Cell 未被使能，锁存器中的数据处于保持状态，输出恒为 `1`；当 select 置 `1` 时，锁存器中的数据由 B 端的输入信号决定，C 端输出锁存器中存储的数据。但是，现在这样一个简单的 RAM Cell 还无法实现真正意义上的读和写操作，还需要一些外部逻辑电路，详见 [#SRAM Bit Slice](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap07/#sram-bit-slice)。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20264.png)

---

### **SRAM Bit Slice**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20265.png)

- 地址有4位，那么地址深度就是 $2^4$,然后每个cell存一个bit，得到一个 $2^4\times1$RAM

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20266.png)

- `Word select`选择要输出的cell，`Bit Select(Chip Select)`使能信号控制整个内存是否运转

!!! note 
    上图中：
    - 当 bit select 置 `1` 时，表示这个 SRAM Bit Slice 被使能，可以进行读写操作；
    - word select 用于选择对哪一个 cell 进行操作，在同一个 slice 中，每次只有一个 cell 能被 word select 使能，即每次只能对一个 cell 进行操作；
        - 换言之，2*n* 条 word select 中，只能存在至多一个置 `1`，其余均置 `0`；
            
            2𝑛
            
    - 读和写操作的逻辑电路如图所示，当 R/W 置 `0` 时，表示正在进行写操作；
        - 当写操作正常进行时，输入进来的新数据其实被总线输送给了所有的 cell，但只有被 word select 使能的那个 cell 才可以写入这个新数据；
        - 注意，对于这幅图而言，不论 R/W 置任何值，读操作都在正常进行；如果不想进行读操作，可以将 word select 全部置 `0`；
    

---

### 重合选择 Coincidence Selection

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20267.png)

- 下图使用两个 2-to-4 decoder 替代了 16×1 RAM 中的 4-to-16 decoder；
    
    16×1
    
- 地址使用 4-bit 表示，其中 2-bit 被分给了 column decoder，用于选择访问哪个 slice；另外 2-bit 被分给了 row decoder，用于选择访问 slice 中的哪一行 cell；

![https://note.isshikih.top/cour_note/D2QD_DigitalDesign/img/137.png](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/img/137.png)

---

### **字扩展与位扩展**

内存的容量由 **word 的数量和位宽**（即每个 word 由多少个 bit 组成）决定。要想扩展内存，可以从 word 的数量和位宽这两个角度进行：

- **字扩展**（扩展 word 的数量）：将多个 RAM “并联”，并相应地扩展地址的位宽；
- **位扩展**（扩展 word 的位宽）：将多个 RAM “串联”，并相应地扩展输入输出的位宽；

---

**字扩展**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20268.png)

- 低位信号 `A1,A0`原封不动D地接入RAM中
- 高位信号 `A3,A2`通过译码器变成4位分别接入RAM的CS信号

---

**位扩展**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20269.png)

- 共享`Address`信号和`CS`信号
- 把输出变成向量而已

## 动态内存

### **DRAM Cell**

- DRAM Cell 和 SRAM Cell 基本类似，也拥有一个 select 使能端和一组输入输出端，唯一的区别在于存储器的不同。SRAM Cell 使用一个锁存器来存储数据，而 DRAM Cell 使用**一个电容**和**一个晶体管**来存储数据。

- 晶体管 T 可以视作一个开关，用来连接外部输入信号 B 和电容 C；
- 电容 C 用于存储数据，当电容为满（电荷量高于某一阈值）时表示高电平（如图 (b)），当电容为空（电荷量低于某一阈值）时表示低电平（如图 (c)）；

---

- 下面考虑 DRAM Cell 的读操作和写操作：

- 写操作：如图 (d) 写入高电平，如图 (e) 写入低电平；
- 读操作：如图 (f) 读取高电平，当 T 打开时，左侧输入端可以监测到一个电荷量的升高，这就代表读取到的数据是高电平；而相应地，右侧电容中的电荷量也有所降低；如图 (g) 读取低电平同理；
    - 不难发现，每次读操作都会稍微改变电容中存储的电荷量，因此对于每一次读操作，都要进行**复位(restore)**，也就是将电容中的电荷量恢复到读操作之前的水平；

![https://note.isshikih.top/cour_note/D2QD_DigitalDesign/img/141.png](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/img/141.png)

---

### DRAM Bit Slice

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20270.png)

- DRAM Bit Slice 和 SRAM Bit Slice 基本类似，前者的输出端会额外加一个放大器，从而将电荷量微小的变化转化成数字信号。虽然电路结构并没有本质差别，但两者**实际的电路开销**却区别很大。DRAM cell 含有一个电容和一个晶体管，而 SRAM cell 含有六个晶体管，所以 DRAM 的每 bit 的开销显著低于 SRAM，这也是 DRAM 在大型内存中被更加广泛的应用的原因。

---

- DRAM 常用于大型内存，而在这些内存中，地址会变得很长（超过 20-bit），以至于 DRAM 的引脚数量不足以一次性接收这么长的地址。解决方法是将地址**分成两部分串行的输入**到 DRAM 里来，首先是 row address，然后紧接着是 column address（注意到这里也有重合选择的思想）。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20271.png)

- 例如64K需要传16位寻址信号，可以先传高的8位，再传低的8位

---

- DRAM传输先给行地址(row)再给列地址(column)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20272.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20273.png)

!!! note
    上图中：

    - 由于地址被分成两部分串行输入到 DRAM 里来，因此需要用 register 分别存储 row address 和 column address；
    - RAS(Row Address Strobe) 和 CAS(Column Address Strobe) 用作 register 的载入信号，置 `0` 表示载入；
    - 对于写操作，当 row address 选中某一行的时候，除了被写入的 cell 之外，这一行中的其他 cell 也被使能并进行了 restore 操作；
    - 对于读操作，当 row address 选中某一行的时候，包括要读取的 cell 在内，这一行中的所有 cell 都被使能并进行了 restore 操作；
    - refresh controller 和 refresh counter 模块负责实现 refresh 功能；

---

### Refresh Policies

- 由于DRAM会逐渐丢失存储数据，所以必须定期刷新

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20274.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20275.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20276.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20277.png)

---

## DRAM类型

- Synchronous DRAM（即 **SDRAM**）：不同于 DRAM 的异步，SDRAM 增加了一个时钟来实现**同步**；
- Double-data-rate synchronous DRAM（即 **DDR SDRAM**）：与 SDRAM 基本一致，但同时利用了时钟的上升沿和下降沿来输出数据；
- Rambus DRAM（即 **RDRAM**）：专利技术，用相对更窄的总线来实现极高的内存访问速度；
    
    Ⓡ
    

!!! info "引入"

    - 为了解释这些 DRAM 是如何达到更快的内存访问速度的，这里有必要先介绍两个事实：

    1. 现代计算机中，绝大多数时候从 DRAM 中读取的数据并没有直接传输给 CPU，而是被存放在了高速缓存(cache)中。高速缓存从 DRAM 中读取数据的时候，总是一次性读取一串相邻的字节，这被称为**爆发模式读取数据(burst read)**。对于 burst read 而言，影响速度的最重要因素不再是寻址的时间，而是连续读取相邻字节的时间；
    2. DRAM 的特性是，每当 row address 选中某一行时，这一行内的所有 cell 都被使能，即都是可访问的；

    - 所以，DRAM 的这种特性，使得它非常适合 burst read，即连续读取同一行中的相邻字节。利用 burst read，DRAM 可以达到更快的内存访问速度。

---

### SDRAM

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20278.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20279.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20280.png)

### DDRAM

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20281.png)