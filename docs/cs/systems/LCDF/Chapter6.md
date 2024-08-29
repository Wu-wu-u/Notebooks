# Chapter 6
Registers and Register Transfers

!!! info
    寄存器由一系列的flip-flops组成，同时具有许多组合门来 决定 数据是否传入flip-flops中

    可以存储vector，还能实现一系列 如count、shift等的操作

## 2-bit Register

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20209.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20210.png)

## Load

- 原来的设计中，任何的时钟周期都可以进行数据的载入，我们希望这种数据载入能被人为控制，能有一个保持的状态，于是我们引入 `Load`

### Load Method 1: Registers with Clock Gating 门控时钟

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20211.png)

- 当`load=1`，正边沿可以正常触发；

- 当`load=0`，正边沿被屏蔽

- 但会有 `clock skew`问题

> 然而，在门控时钟技术中，由于添加了一个额外的逻辑门，时钟脉冲到达 Control 的时候会出现额外的传播延时，即**时钟偏移(clock skew)**。而这微小的延时会导致在整个同步系统中，不同组件得到的时钟脉冲有偏差，而这是我们所不希望看到的。所以在实际设计中，我们应当避免或尽可能缩小时钟偏移。
> 
> 
> ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20212.png)
> 

### Load Method 2: Registers with Load-Controlled Feedback

> 另外一个做法是，在不希望它修改的时候，不断将它的输入载入，也就是保持不变。我们可以通过一个 `MUX` 来实现这个功能，用 `Load` 使能端来选择是载入新值还是保持之前的值，如下图。
> 

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20213.png)

- $Y=\bar{Load}·Y+Load·In$

- 当Load=0，hold数据

- 当Load=1，载入新数据

## **寄存器传输**

- 一个复杂系统除了信息的存储还需要信息的传输和处理，换句话来说，为了实现灵活、复杂的计算，我们需要信息之间能够广泛地交互。大部分电子系统设计中，都会有一个**控制单元(Control Unit)**来负责指挥**数据通路(Datapath)**进行数据处理。

> Datapath performs data-processing operations, and control unit determines the sequence of those operations.
> 
> 
> Datapaths are defined by their registers and the operations performed on binary data stored in the registers.
> 

- 对于寄存器自身而言，它可能实现 载入(load)、清空(clear)、移位(shift) 和 计数(count) 等。此外，对于那些寄存器中的数据进行移动了的加工，被称为**寄存器传输操作(Register Transfer Operations)**，它们主要包含这三个部分：

    1. 系统中的寄存器集合；
    2. 对于数据的操作；
    3. 监督操作序列的控制；

- 其中，最基础的那部分操作被称为**微操作(microoperation)**，它们是实现复杂操作的基础，例如将 R1 的数据载入 R2，将 R1 和 R2 相加，或是自增 R1 等。它们通常是以比特向量为载体并行实现的。

### RTL 寄存器传输语言

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20214.png)

### 注意

- 对于如上出现的形式如：  
    $condition: reg \leftarrow options one regs$   
    的表达式，`:` 左侧出现的 `+` 表示或，右侧的则表示加（“乘”也是这样）！

## 寄存器传输的实现

- 如何实现寄存器所存储的数据之间的处理与交互是本章节的核心命题。如果说 [**微操作**](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap06/#%E5%BE%AE%E6%93%8D%E4%BD%9C%E5%8F%8A%E5%85%B6%E5%AE%9E%E7%8E%B0) 关注的是数据的处理，那 [**寄存器传输**](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap06/#%E5%AF%84%E5%AD%98%E5%99%A8%E4%BC%A0%E8%BE%93) 则着眼于数据之间的交互。

- 换句话来说，如何把数据给到别的寄存器、如何获取别的寄存器给到的数据、如何传输和选择这些数据，就是本小节要解决的问题。

- 特别的，寄存器传输的实现可以直接实现 [**转移**](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap06/#%E8%BD%AC%E7%A7%BB) 操作

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20215.png)

### MUX-based Transfers 
=== "基于 MUX 实现传输"

    - 对于一个单一寄存器，它的**输入**可能有多种来源，例如其它寄存器，又或者是其他操作的结果。总而言之，它的输入很可能是不唯一的，而同一时刻我们只能接受一个来源的输入。因此，我们需要使用 `MUX` 来对输入进行选择。

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20216.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20217.png)

    - 用语言来描述这个总体架构就是，我们通过一系列 `one-hot` 编码（或者是 one-cold）来表示选择哪个输入源（下图中 $K_0\sim K_{n-1}$），再通过 `Encoder` 将它们编码作为 `MUX` 的输入选择信号（下图中 $S_m \sim S_0$），从多个输入源（下图中 $0 \sim k \sim (n-1)$）中选择对应的源，并输出，给到 R0；此外，将选择信号都或起来，作为 R0 的 Load 信号输入。



=== "Dedicated MUX-Based"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20218.png)

    - 每个Register一个独立的MUX，我们就可以控制 R0,R1,R2之间的相互传输

=== "Bus implementation"
    - 基于总线实现传输    **MUX Bus**
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20219.png)

    - 共享一个MUX，用S0,S1和各个Load信号控制传输

===  "**Three-State Bus**"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20220.png)

    - 一条线上，只能有一个输入信号，每个寄存器配一个三态门控制其传输

## 微操作及其实现

- 微操作一般分为这四种：

    1. 转移，transfer microoperations，将数据从一个寄存器转移到另外一个寄存器；
    2. 算术，arithmetic microoperations，对数据的算术运算操作；
    3. 逻辑，logic microoperations，对数据的逻辑运算操作；
    4. 移位，shift microoperations，对数据的移位操作；

### 转移

- 不改变数据本身，只是从一个寄存器中把数据移动到另外一个寄存器。

- 将 R0 中的数据转移到 R1 中，用 RTL 表示就是 $𝑅0←𝑅1$。

- 这一部分的实现途径在 [**寄存器传输的实现**](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap06/#%E5%AF%84%E5%AD%98%E5%99%A8%E4%BC%A0%E8%BE%93%E7%9A%84%E5%AE%9E%E7%8E%B0) 已经阐述。

### 算术

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20221.png)

---

- 就像我们之前学过的，用加法器实现加减法器，在 RTL 和模块逻辑电路的维度下，可以这么表示：

$\begin{aligned}    &\overline{X}K_1:R_1\leftarrow R_1 + R_2 \\
    &XK_1:R_1\leftarrow R_1 + \overline{R_2} + 1
\end{aligned}$

- ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20222.png)

### 逻辑

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20223.png)

- 直接用逻辑门即可

### 移位

=== "串行"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20224.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20225.png)

    - 利用多个D-FF，前一个的输出作为后者的输入，再多添一个 `serial input/shift right input` (In)


=== "**并行 (Parallel Load)** "

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20226.png)

    - 并行输出的实现非常简单，只需要给每一个 `FF` 的输出引出一条线就行了，它与串行输出可以直接同时存在；而并行输入则与串行输入冲突，一次只能实现其中一个，所以需要一些控制电路

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20227.png)

    - 看起来有点复杂，但是实际上逻辑还是很清晰的。

    - 纵向观察右侧的四个 `FF`，可以发现基本上就是串行移位实现，只不过其输入不再是直接从上一个 `FF` 那边拿来的；
    - 四个 `FF` 的输入是类似的，所以我们仅关注最上面的那三个与门和一个或门，表示数据输入有三个可能的来源；
        1. 第一个与门， $F_i=Shift⋅SI$（对于后面几个 `FF`，则是 $F_i=Shift⋅FF_{i−1}$），可以发现，此时电路的行为与**串行移位实现**一致；
            
            $𝐹_𝑖=𝑆ℎ𝑖𝑓𝑡⋅𝑆𝐼$
            
            $𝐹_𝑖=𝑆ℎ𝑖𝑓𝑡⋅𝐹𝐹_{𝑖−1}$
            
            - 即 *Shift* 为 `1` 时，`SHR` 表现为「**每个周期执行一次移位**」；
        2. 第二个与门，*Fi*=*Shift*⋅*Load*⋅*Di*，此时电路的行为是使用比特向量对每一个 `FF` 赋值，即**并行载入**；
            
            $𝐹_𝑖=\overline{𝑆ℎ𝑖𝑓𝑡}⋅𝐿𝑜𝑎𝑑⋅𝐷_𝑖$
            
            - 即 $\overline{𝑆ℎ𝑖𝑓𝑡}⋅𝐿𝑜𝑎𝑑$为 `1` 时，`SHR` 表现为「**并行载入**」；
        3. 第三个与门，*Fi*=*Shift*⋅*Load*⋅*Qi*，此时电路的行为是保持上一周期的结果；
            
            $𝐹_𝑖=\overline{𝑆ℎ𝑖𝑓𝑡}⋅\overline{𝐿𝑜𝑎𝑑}⋅𝑄_𝑖$
            
            - 即 $\overline{Shift}⋅\overline{Load}$ 为 `1` 时，`SHR` 表现为「**保持**」；
        

    - 总和来说，就是：

    $Shift:Q←\text{sl}~Q\\\overline{Shift}·Load:Q←D\\\overline{Shift}·\overline{Load}:Q←Q$



=== "双向移位"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20228.png)

    - 用一个MUX来控制4种功能

------

## Counter

- 对比两种计数器

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20229.png)

### Ripple Counter 行波计数器（异步）

- 行波计数器的主要思想就是将一个不断自反的 `FF` 的输出直接或间接作为下一个 `FF` 的时钟脉冲。由于形成一次脉冲需要一对 `0`&`1`，所以前一个 `FF` 取反两次才能引起下一个 `FF` 取反一次，如果下一个 `FF` 是在上一个 `FF` 的输出从 `1` 变 `0` 时触发，那两个 `FF` 的变化刚好对应于二进制自增的进位规律：`(0,0)`，`(0,1)`，`(1,0)`，`(1,1)`，`(0,0)`，...

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20230.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20231.png)

- 可以发现，行波计数器的优点是电路简单，成本低；但是缺点也很明显，既然它与同步计数器相区分，就说明它不是同步电路，每一个 `FF` 都会有传播延时，**随着计数范围增大，总传播延时也会增加**，而为了让电路正常工作，时钟频率也要因此下降。

- 由于这些，书上对行波计数器的评价是多数情况下行波加法器只会在低功耗电路中被采用。

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20232.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20233.png)

-------

### Synchronous Counters 同步计数器

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20234.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20235.png)

- 左边是个自增器，右边是4个D-FF，用CE来控制是否自增，CO是满溢的输出

---

!!! note "同步载入"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20236.png)

    - 这里同步载入的含义可以同 [**移位寄存器的并行载入**](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap06/#%E5%B9%B6%E8%A1%8C%E5%8C%96) 类比，其主要目的是将计数器的当前值设为一个我们需要的数字。

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20237.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20238.png)

### Synchronous BCD

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20239.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20240.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20241.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20242.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20243.png)

- 当计数器的输出为 `9` 时，下一周期让计数器载入 `0`

> 按理来说这里应该是 $𝐿𝑜𝑎𝑑=𝑄_0⋅\overline{𝑄_1}⋅\overline{𝑄_2}⋅𝑄_3$，以对应 9D=1001B，但是由于自增过程中，`1001` 是第一个满足 `1??1` 的组合，所以可以直接简化为 $𝐿𝑜𝑎𝑑=𝑄_0⋅𝑄_3$
> 

---

??? note "Mod N 计数器"

    - 实际上，我们可以把 BCD 码循环计数器看作是特殊的 Mod N 计数器，即 N = 10 的 Mod N 计数器。

    - 或许你会想，实现 Mod N 计数器能不能在满足输出条件后直接使用 `Clear` 输入。但是请不要忘记了，`Clear` 也好，`Set` 也罢，它们都是异步操作。我们没有必要也不应该使用异步操作，所以最好的做法还是使用 `Load`。

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20244.png)

## Register Cell
寄存器单元

**寄存器单元(Register Cell)**是寄存器的个体单元，主要包括一个 `FF` 及实现其组合逻辑的组合电路。

### Register cell design

- 设计寄存器（尤其是大规模的寄存器）的重要手段之一，就是**寄存器单元设计(Register Cell Design)**。通常遵循以下步骤：

    1. 设计具有代表性的寄存器单元；
    2. 复制并连接若干个这样的寄存器单元；
    3. 修改某几个寄存器单元（通常可能是一串寄存器的首尾两个单元）以解决一些特殊情况或边界问题；

### Register Cell Specification

- 设计寄存器单元时，我们需要对寄存器单元进行定义。而指定(Specify)一个寄存器单元的功能的主要有这些方面：

- 寄存器的功能函数；
    - 一般指寄存器传输；
- 控制信号构成；
    - 有哪些控制信号、是否编码、如何决定是否 Load 等；
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20245.png)
    
- 寄存器的输入数据；
    - 有哪些输入数据、是否需要预先处理等；

- 在实际实现时，分为 `MUX` 实现 和 时序逻辑实现 两种方法。

- MUX 易读简单但门输入代价高，传统时序电路设计不易读但们输入代价低

---

!!! note "MUX实现"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20246.png)

    ??? tip "Example 1"
    
        ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20247.png)
    
        === "**MUX法**"
        
            ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20248.png)
        
            ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20249.png)
        
        === "传统时序电路设计法"
        
            ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20250.png)
            
            ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20251.png)
            
            ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20252.png)
            
            ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20253.png)
            

---

## Register Transfer System Design
寄存器传输系统设计

1. 确定系统的行为(specification)；
2. 定义外部的输入、输出，以及控制单元(control unit)和数据通路(datapath)需要的寄存器；
3. 设计状态机；
4. 定义内部的控制信号、状态信号；
    - 用这些信号来分配输出条件(output condition)、输出行为(output actions)等，包括寄存器传输(register transfer)（个人理解是设计内部信号来进一步设计状态机，包括设计 TC、OC、OA 等）；
5. 绘制框图(block diagram)；
6. 设计控制单元和数据通路的寄存器传输逻辑(register transfer logic)；
7. 设计控制单元逻辑(control unit logic)；
8. 验证正确性；

??? tip "Example Dash-Watch"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20254.png)

    - 分析输入、输出、寄存器

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20255.png)
