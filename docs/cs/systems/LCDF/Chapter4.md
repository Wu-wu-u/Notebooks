# Chap 4
Sequential Circuits

!!! info "引例"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20114.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20115.png)

    - 单一的R、S变量无法真正决定Q的状态，还要取决于内部的上一个状态。

## Latch （锁存器）

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20116.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20117.png)

- 每个门电路都有一个独立的电源，所以发光不是依靠输入的电源；（不是永动

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20118.png)

- 两个稳定态，持续维持稳定状态，同时SR改变时状态发生改变

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20119.png)

- 如果SR双置位，那么就会发生震荡，最后得到一个未知状态

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20120.png)

---

!!! note "亚稳态"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20121.png)

    给的信号时间过短，就会意外处于亚稳态，而亚稳态并不稳定也会造成未知状态

---

### Synchronous Circuit

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20122.png)

- 多 *与非** 的处理，让状态调整和C的一定频率同步，而不是SR改变就马上改变Q状态

### D Latch

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20123.png)

- 单输入的信号，锁存的信号就是D

## Flip-Flops

!!! info
    - latch情况下 会发生空翻现象

    - 所以引入flip-flop

### S-R Master-Slave Flip-Flop

- Master 进行置位信号的采样

- Slave 来决定Q的状态

- 两者工作在不同的时间片区

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20124.png)

!!! warning "problem：1s catching"

    - 置位信号稍微有些抖动毛刺，都会产生错误信号且难以修正

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20125.png)

### D-Edge-Triggered

- 用D latch替换掉SR；因为只要在进入Slave前回到正确状态就行，关键就在高低电平转换的Edge

- 这个是**主从类型**的D-edge-triggered

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20126.png)



---

- 这是带SR预置位的，**正边沿**触发

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20127.png)


---

### J-K Flip-Flop

- JK就是升级版的SR，在保留了 00,01,10的功能前提下，将原来未知态的11变为了 $Q(t+1)=\bar {Q(t)}$

!!! note "方程"
    - 特征方程：

    $Q(t+1)=J\bar Q+\bar KQ$

    - 激励方程：

    $J=Q(t+1)+Q(t)\\K=\bar{Q(t+1)}+\bar{Q(t)}$

### T Flip-Flop

- 相当于一个计数器，clk到edge就加一

!!! note "方程"
    - 特征方程：

    $Q(t+1)=Q(t)\oplus T$

    - 激励方程：

    $T=Q(t)\oplus Q(t+1)$

## Flip-Flop Timing Parameters 时间参数

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20128.png)

- 对于边缘触发器，必须给定一定时间的time to setup or hold，这样数据才能稳定存储，不然就会进入亚稳态

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20129.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20130.png)

## Sequential Circuit Analysis

### 四大方程

=== "**触发器的输入方程(flip-flop input equation)** "

    - 表示 触发器的D/SR/JK/T端 和 其他信号的逻辑关系

=== "**输出方程（output equation）**"

    - 表示 输出信号Y的逻辑

=== "**状态方程（next-state equation)**"

    - 表示 $Q(t+1)=F(Q(t),X,D)$的逻辑

=== "**激励方程（excitation equation）**"

    - 表示 从 $Q(t)到Q(t+1)$,D/SR/JK/T端需要的值
    $D=F(Q(t),X)$

    - 一般是两输入两输出（两个外部信号，两个内部信号）

!!! note
    一共要分析三个方程

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20131.png)

---

!!! note "E.g.1"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20132.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20133.png)

### State Table

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20134.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20135.png)

### State Diagram

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20136.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20137.png)

- 有向弧上表示了状态切换时的输入量；
- 然后输出结果有两种表示，也对应了两种类型：
    - （Mealy type;Moore type）

- Mealy type
    - 输出与状态和输入都有关
    - 有向弧上 `input/output`
- Moore type
    - 输出只与当前状态有关
    - 有向弧上 `input` 状态圈里表示 `output`

### Equivalent State(等价状态)

- 有**相同的输入，输出，下一状态**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20138.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20139.png)

---

!!! note "E.g 2"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20140.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20141.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20142.png)

## TimingAnalysis of Sequential Circuits 时间分析

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20143.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20144.png)

== "e.g1" 
    - 只是从 input 到 output ：2个 xor

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20145.png)

=== "e.g2" 
    - input 到 positive edge :xor+not+ts

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20146.png)

=== "e.g3" 
    - positive edge to output : tpd+and+xor+xor

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20147.png)

=== "e.g.4" 
    - from positive to next positive : tpd+and+xor+not+ts

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20148.png)

=== "e.g.5" 

    - Maximum frequency : 就是从 clk edge到clk edge那段时间对应的频率

## Method of Describing Sequential Analysis

- 电路设计 也是三个方程！

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20149.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20150.png)

- 难点在于什么是“状态” 能不能很好的抽象

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20151.png)

=== "Example 1101"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20152.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20153.png)

    - 初始状态 设置成正确的序列

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20154.png)

    - 然后补全其余的state

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20155.png)

    - 接着根据 状态图 补全 状态表

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20156.png)

=== "Example 1011-Moore型"

    - 刚才的设计是 `Mealy`型

    - 现在欲改为`Moore`型

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20157.png)

    - 去找输出都不变的 就变更输出到状态里面去

    - （我们可以把输出藏在输入端或者输出端）

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20158.png)

    - 而对于无法处理的节点：新添节点

    - 比如 对于原图中的D节点

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20159.png)

    - **我们添加了E节点，同时理解E状态就是 成功读取最后一个1之后的状态，所以再多一个1就到C，如果是0就到A**

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20160.png)

### Simplification of State Table （状态表简化）

- ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20161.png)

- 对于 Next State和Output 都相同的两个state 是等价，可以合并

---

- Three cases of equivalent states

- 首先outputs一定要相同

1. Next States 相同
2. Next States interleaved 交错
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20162.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20163.png)
    
3. Next States circulated 循环
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20164.png)
    

-----

=== "Example 2 (modulo 3)"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20165.png)

    - 对输出的理解不同，则model不同

    - Mealy：

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20166.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20167.png)

    - Moore：

    - 输出藏在了输入端

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20168.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20169.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20170.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20171.png)

=== "Example unlimited sequences"

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20172.png)

-----

## State Assignment Method
- 状态编码的方法

- 将状态进行编码，主要三种

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20173.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20174.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20175.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20176.png)

!!! tip "Example 1"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20177.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20178.png)

    - 利用卡诺图化简 得到input 和 output方程
    
    === "BCD"
        ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20179.png)

        - BCD编码 cost较高

    === "Gray"
        ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20180.png)

        ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20181.png)

        - Gray cost较低

    === "one-hot"

        ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20182.png)

## Basic Flip-Flop Descriptors

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20183.png)

- 特征方程：给定FF的信号，下一个Q(t+1)会如何变化

- 激励方程：给定Q(t)和Q(t+1)，需要如何的FF信号

### D Flip-Flop Descriptor

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20184.png)

### T Flip-Flop Descriptor

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20185.png)

### S-R Flip-Flop Descriptor

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20186.png)

### J-K Flip-Flop Descriptor

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20187.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20188.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20189.png)

### Bahavior

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20190.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20191.png)
