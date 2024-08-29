# Chap 3
Combinational Logic Design

## Combinational Circuits

### How to degisn

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2037.png)

=== "example 1"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2038.png)

=== "example 2"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2039.png)

    - 相当于是4张真值表分别去读

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2040.png)

    - 多输出的优化，联合

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2041.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2042.png)

## Technology Parameters

### Fan-in

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2043.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2044.png)

### Fan-out

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2045.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2046.png)

### Propagation Delay

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2047.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2048.png)

!!! warning "区别propagation delay 和 transition time"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2049.png)

!!! note "Delay Models"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2050.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2051.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2052.png)

    Transport delay就认为output和input永远间隔固定的时间差

    Inertial delay就认为 input还要满足一定的rejection time，过短的input会被过滤掉

- 最后延迟的计算

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2053.png)

??? tip "延迟的典例"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2054.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2055.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2056.png)

    - 消除毛刺！ 添项

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2057.png)

## Technology Mapping

### NAND Mapping

- 与非门是万能门，可以替换AND OR, 非门同样是硬件上可由与非门组成

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2058.png)

- 两个连续的非门 可以优化成导线，输出有交叉口的非门，可以把非门推过去再两两消

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2059.png)

## Function Blocks

### Enabling Function

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2060.png)

- 与三态门的区别：

- 三态门的EN是在中间，使其Hi-Z or not；

- Enabling Function的EN是作为信号输入，决定最后输出状态（即EN=1，由X决定；EN=0，则一定是0）

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2061.png)

### Decoder

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2062.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2063.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2064.png)

!!! note "Top-Down Design"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2065.png)

    层次化设计，用共享项可以减少cost

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2066.png)

!!! note "带Enable的decoder"
    - 可以视作选择E的信号从哪路出去
    - 实现信号分离器

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2067.png)

---

!!! note "Bottom-UP Design"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2068.png)

---

??? note "example"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2069.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2070.png)

### Encoder

=== "One-hot to binary"
    - decimal-to-BCD
    
    - 利用one-hot可以解决多信号的真值问题
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2071.png)
    
    - 下面的e.g除了能编码的1，2，4其余都是Don't cares
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2072.png)
    
    - 这种one-hot编码可以不用K-map，直接读那个ONE对应的信号,但可能并非最优解！
    

---

=== "Priority Encoder"
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2073.png)
    
    - 所谓优先级，高的信号为1，其余全无所谓(X)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2074.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2075.png)
    

### MUX

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2076.png)

- 两种信号：输入信号，选择信号

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2077.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2078.png)

- 将n个选择信号decode成 $2^n$ 个，去和 $I_n$ AND起来

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2079.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2080.png)

- 对于向量的选择：

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2081.png)

- 一位一位选择

---

!!! note "另类部署-利用三态门的Enable"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2082.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2083.png)

    利用三态门最好是多次筛选

---

!!! note "应用"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2084.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2090.png)

---

??? tip "Example:Gray to Binary"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2085.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2086.png)

    - 我们重新分配一下真值表，最开始是根据xyz来写出对应格雷码；现在我们把格雷码作为输入，写出对应xyz的真值表

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2087.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2088.png)

    - 将AB作为选择信号，C接入来降维

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2089.png)

---



## Arithmetic Functions

设计思路：迭代组合

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2091.png)

### Adder

=== "Ripple"
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2092.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2093.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2094.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2095.png)

    - 构造很简单，但是这种Ripple型计算太慢，一点一点从低到高计算。
    - 原因就是Ci的传递，于是我们考虑先算本地可算的部分



=== "CLA"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2096.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2097.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2098.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2099.png)

    - 十六位就拆成四个一组，组内CLA，组间行波进位

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20100.png)

### Subtractor

- 反码定义： $(r-1)^n-N$

- 补码定义： $r^n-N$

- 求反码：按位求反

- 求补码：

    1. 可以用反码+1

    或者

    2. 先找到copy右边连续的0直到第一个1
    然后把前面的digit取反

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20101.png)

---

- 用补码做减法：

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20102.png)

- 如果M-N够减，那么最后加上 $2^n$也无所谓，因为相当于最高位的carry( $2^n$位一定有carry-in )被舍去（总位数有限，同余原理）

- 如果M-N不够，那么说明最后结果没有 $2^n$位的carry，那么就进行结果修正，求结果的补码，并mark为负数

### Signed Integer Arithmetic

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20103.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20104.png)

- 通过对符号位和操作符 做 奇函数 来判断 属于同符号数还是异符号数

- 同符号处理简单，加法处理绝对值后 加上符号位

!!! note "异符号"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20105.png)

    - 变加为减，然后看有没有borrow位，有的话：
    - 把结果取补码，同时符号位与被减数相反

    - 没有borrow位则：

    - 结果不用取补码，符号位与被减数相同

### Signed Integer and Signed 2’s Complement conversion

- 由补码转换成符号数：

    - ①负数，先求补码得绝对值然后＋符号
    
        - ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20106.png)

    - ②负权重
    - 相当于一套公式完成 无论正负数的转换

        - ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20107.png)

    - 把符号位给上意义 $-2^{n-1}$，其余位正常求和

    - 再也不用分别符号和数字，全部拿来用统一的算法一起算！

### 符号数扩展

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20108.png)

- 位数对齐时，整数扩展0，负数扩展1

### 补码能表示数的范围

- 上限: $2^{n-1}-1$

- 下限: $-2^{n-1}$

- 所以会有溢出的情况:

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20109.png)

- 如果M，N的符号位相同，但结果却和他们不同，则说明发生了overflow，和有没有carry-in无关

- 而M，N符号不同，不可能overflow

### 电路表示

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20110.png)

- 利用S决定是加法还是减法

- 然后将S传入C0，完美解决从反码到补码的转换

- 上下溢检测：

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20111.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20112.png)

- 最简单方法：

- 我们将五个变量，去找overflow之间的函数关系

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20113.png)

- 即最优是 $C_{in} \oplus C_{out}$

### 一些对比

- 无符号数和有符号数减法中，都用到了补码来变减为加，但是原理不同，现对比如下：

    - 1）无符号数计算中，减去一个数等于加上这个数的补码，其原理是模N系统中的同余原理。例如，模2的三次方系统中，011–010≡011+110≡001，其中，–010和110在mod 2的三次方下同余，运算采用同余符号≡。

    - 2）有符号数计算中，减去一个数等于加上这个数的补码，其原理是减去一个数等于加上这个数的相反数。因为在补码编码中，相反数互为补码关系。例如，011-010=011+110=001，其中，010(表示+2)和110（表示-2）互为相反数，运算采用等号=。
