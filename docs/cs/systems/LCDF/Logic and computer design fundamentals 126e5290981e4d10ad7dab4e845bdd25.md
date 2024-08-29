# Logic and computer design fundamentals

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled.png)

## References

[HDLBits-Verilog Practice](https://www.notion.so/Logic-and-computer-design-fundamentals-126e5290981e4d10ad7dab4e845bdd25?pvs=21)
Logism:[https://sourceforge.net/projects/circuit/?source=typ_redirect](https://sourceforge.net/projects/circuit/?source=typ_redirect)
Logism tutorial video:[https://www.bilibili.com/video/av842668792/](https://www.bilibili.com/video/av842668792/)
Verilog:[https://www.runoob.com/w3cnote/verilog-tutorial.html](https://www.runoob.com/w3cnote/verilog-tutorial.html)

# Chap 1
Digital Systems and Information

## BCD

| Decimal | 8,4,2,1 |
| --- | --- |
| 0 | 0000 |
| 1 | 0001 |
| 2 | 0010 |
| 3 | 0011 |
| 4 | 0100 |
| 5 | 0101 |
| 6 | 0110 |
| 7 | 0111 |
| 8 | 1000 |
| 9 | 1001 |

超过9的数都是 invalid

对于超过9的数字，先加6(0110)再进位，保证每四位满足BCD

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%201.png)

将BCD码转binary,则先转decimal再算binary

## One-hot

## Gray

# Chap 2
Combinational Logic Circuits

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%202.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%203.png)

## **Duality rules**

- 变 $AND$ 为 $OR$ , 添加括号保证内容运算顺序不变
- self-dual
H=AB+AC+BC
dual H=(A+B)$\cdot$(A+C) (B+C)
- complementing functions
use DeMorgan’s Laws(break the line,change the sign)

## Theorem

- Minimization
$XY+\overline{X}Y=Y$
$(X+Y)(\overline {X}+Y)=Y$
- Distributive 
$X+YZ=(X+Y)(X+Z)$
- Absorption
$A+A \cdot B=A$
$A+\overline{A}B=A+B$
- Consensus
$AB+\overline{A} C+BC=AB+\overline{A}C\\=（A+C)(\overline A+B)=(A+C)(\overline A +B)(B+C)$

examples of computing:

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%204.png)

想absorb $\overline Y Z, XY$, 就主动填项来让剩余的去吸收

## Canonical Forms

- Boolean Expressions for a truth table
    
    SOM:sum of minterms
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%205.png)
    
    POM:product of maxterms
    索引反向读
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%206.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%207.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%208.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%209.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2010.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2011.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2012.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2013.png)
    

## Circuit Optimization

Gate Input Cost:

L(literal cost) / G(gate input count excluding single literal) / GN(gate input count with NOTs)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2014.png)

非门不要重复数

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2015.png)

## K-Maps

Gary-code, adjacent squares combining

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2016.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2017.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2018.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2019.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2020.png)

圈 $2^n$ 个

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2021.png)

四维注意number位置

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2022.png)

Traps Example

不可圈中间4个，因为另4个小圈必会包含！！！

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2023.png)

正确的圈法就是红色，而非红+蓝

## Don’t Cares

"don't cares"可以在以下情况下使用：

1. **输入不可能出现**：例如，如果我们有一个4位的二进制输入，但我们知道只有10种输入是有效的（0000到1001），那么其他6种输入（1010到1111）就可以被视为"don't cares"。
2. **输出对系统行为无影响**：例如，如果我们正在设计一个系统，该系统在某些输入条件下的输出并不会影响系统的其他部分，那么这些输出就可以被视为"don't cares"。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2024.png)

one-hot encoding

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2025.png)

更多的输入换取更多的优化机会和更少的门cost

## **Systematic Simplification**

Prime Implicant 包含 $2^n$个implicant的最大的

Essential Prime Implicant 含有其他prime implicant没有的项

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2026.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2027.png)

Essential Prime Implicant 是必须优化的，剩余的有很多选择性

### **Quine–McCluskey Algorithm**

1.**Find all prime implicants.
2.Include all essential prime implicants in the
solution
3.Select a minimum cost set of non-essential
prime implicants to cover all minterms not yet
covered:**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2028.png)

## XOR

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2029.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2030.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2031.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2032.png)

applications of odd/even functions:

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2033.png)

## Buffer

中继器

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2034.png)

### 3-state Buffer(0/1/z)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2035.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2036.png)

# Chap 3
Combinational Logic Design

## Combinational Circuits

### How to degisn

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2037.png)

example 1:

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2038.png)

example 2:

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2039.png)

相当于是4张真值表分别去读

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2040.png)

多输出的优化，联合

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

区别propagation delay 和 transition time

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2049.png)

Delay Models

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2050.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2051.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2052.png)

Transport delay就认为output和input永远间隔固定的时间差

Inertial delay就认为 input还要满足一定的rejection time，过短的input会被过滤掉

最后延迟的计算

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2053.png)

延迟的典例

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2054.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2055.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2056.png)

消除毛刺！ 添项

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2057.png)

## Technology Mapping

### NAND Mapping

与非门是万能门，可以替换AND OR, 非门同样是硬件上可由与非门组成

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2058.png)

两个连续的非门 可以优化成导线，输出有交叉口的非门，可以把非门推过去再两两消

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2059.png)

## Function Blocks

### Enabling Function

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2060.png)

与三态门的区别：

三态门的EN是在中间，使其Hi-Z or not；

Enabling Function的EN是作为信号输入，决定最后输出状态（即EN=1，由X决定；EN=0，则一定是0）

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2061.png)

### Decoder

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2062.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2063.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2064.png)

Top-Down Design

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2065.png)

层次化设计，用共享项可以减少cost

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2066.png)

带Enable的decoder
可以视作选择E的信号从哪路出去
实现信号分离器

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2067.png)

---

Bottom-UP Design

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2068.png)

---

example

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2069.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2070.png)

### Encoder

- One-hot to binary
decimal-to-BCD
    
    利用one-hot可以解决多信号的真值问题
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2071.png)
    
    下面的e.g除了能编码的1，2，4其余都是Don't cares
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2072.png)
    
    这种one-hot编码可以不用K-map，直接读那个ONE对应的信号,但可能并非最优解！
    

---

- Priority Encoder
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2073.png)
    
    所谓优先级，高的信号为1，其余全无所谓(X)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2074.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2075.png)
    

### MUX

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2076.png)

两种信号：输入信号，选择信号

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2077.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2078.png)

将n个选择信号decode成 $2^n$ 个，去和 $I_n$ AND起来

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2079.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2080.png)

对于向量的选择：

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2081.png)

一位一位选择

---

另类部署-利用三态门的Enable

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2082.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2083.png)

利用三态门最好是多次筛选

---

应用：

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2084.png)

---

Example:Gray to Binary

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2085.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2086.png)

我们重新分配一下真值表，最开始是根据xyz来写出对应格雷码；现在我们把格雷码作为输入，写出对应xyz的真值表

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2087.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2088.png)

将AB作为选择信号，C接入来降维

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2089.png)

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2090.png)

## Arithmetic Functions

设计思路：迭代组合

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2091.png)

### Adder

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2092.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2093.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2094.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2095.png)

构造很简单，但是这种Ripple型计算太慢，一点一点从低到高计算。
原因就是Ci的传递，于是我们考虑先算本地可算的部分

---

CLA

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2096.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2097.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2098.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2099.png)

十六位就拆成四个一组，组内CLA，组间行波进位

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20100.png)

### Subtractor

反码定义： $(r-1)^n-N$

补码定义： $r^n-N$

求反码：按位求反

求补码：

①可以用反码+1

或者

②
先找到copy右边连续的0直到第一个1
然后把前面的digit取反

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20101.png)

---

用补码做减法：

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20102.png)

如果M-N够减，那么最后加上 $2^n$也无所谓，因为相当于最高位的carry( $2^n$位一定有carry-in )被舍去（总位数有限，同余原理）

如果M-N不够，那么说明最后结果没有 $2^n$位的carry，那么就进行结果修正，求结果的补码，并mark为负数

### Signed Integer Arithmetic

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20103.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20104.png)

通过对符号位和操作符 做 奇函数 来判断 属于同符号数还是异符号数

同符号处理简单，加法处理绝对值后 加上符号位

异符号：

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20105.png)

变加为减，然后看有没有borrow位，有的话：
把结果取补码，同时符号位与被减数相反

没有borrow位则：

结果不用取补码，符号位与被减数相同

### Signed Integer and Signed 2’s Complement conversion

由补码转换成符号数：

①

负数，先求补码得绝对值然后＋符号

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20106.png)

②

负权重

相当于一套公式完成 无论正负数的转换

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20107.png)

把符号位给上意义 $-2^{n-1}$，其余位正常求和

再也不用分别符号和数字，全部拿来用统一的算法一起算！

### 符号数扩展

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20108.png)

位数对齐时，整数扩展0，负数扩展1

### 补码能表示数的范围

上限: $2^{n-1}-1$

下限: $-2^{n-1}$

所以会有溢出的情况:

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20109.png)

如果M，N的符号位相同，但结果却和他们不同，则说明发生了overflow，和有没有carry-in无关

而M，N符号不同，不可能overflow

### 电路表示

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20110.png)

利用S决定是加法还是减法

然后将S传入C0，完美解决从反码到补码的转换

上下溢检测：

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20111.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20112.png)

最简单方法：

我们将五个变量，去找overflow之间的函数关系

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20113.png)

即最优是 $C_{in} \oplus C_{out}$

### 一些对比

无符号数和有符号数减法中，都用到了补码来变减为加，但是原理不同，现对比如下：

1）无符号数计算中，减去一个数等于加上这个数的补码，其原理是模N系统中的同余原理。例如，模2的三次方系统中，011–010≡011+110≡001，其中，–010和110在mod 2的三次方下同余，运算采用同余符号≡。

2）有符号数计算中，减去一个数等于加上这个数的补码，其原理是减去一个数等于加上这个数的相反数。因为在补码编码中，相反数互为补码关系。例如，011-010=011+110=001，其中，010(表示+2)和110（表示-2）互为相反数，运算采用等号=。

# Chap 4
Sequential Circuits

## 引例

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20114.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20115.png)

单一的R、S变量无法真正决定Q的状态，还要取决于内部的上一个状态。

## Latch （锁存器）

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20116.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20117.png)

每个门电路都有一个独立的电源，所以发光不是依靠输入的电源；（不是永动

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20118.png)

两个稳定态，持续维持稳定状态，同时SR改变时状态发生改变

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20119.png)

如果SR双置位，那么就会发生震荡，最后得到一个未知状态

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20120.png)

---

亚稳态

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20121.png)

给的信号时间过短，就会意外处于亚稳态，而亚稳态并不稳定也会造成未知状态

---

### Synchronous Circuit

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20122.png)

多 与非 的处理，让状态调整和C的一定频率同步，而不是SR改变就马上改变Q状态

### D Latch

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20123.png)

单输入的信号，锁存的信号就是D

## Flip-Flops

latch情况下 会发生空翻现象

所以引入flip-flop

### S-R Master-Slave Flip-Flop

Master 进行置位信号的采样

Slave 来决定Q的状态

两者工作在不同的时间片区

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20124.png)

problem：1s catching

置位信号稍微有些抖动毛刺，都会产生错误信号且难以修正

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20125.png)

### D-Edge-Triggered

用D latch替换掉SR；因为只要在进入Slave前回到正确状态就行，关键就在高低电平转换的Edge

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20126.png)

这个是主从类型的D-edge-triggered

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20127.png)

这是带SR预置位的，正边沿触发

### J-K Flip-Flop

JK就是升级版的SR，在保留了 00,01,10的功能前提下，将原来未知态的11变为了 $Q(t+1)=\bar {Q(t)}$

特征方程：

$Q(t+1)=J\bar Q+\bar KQ$

激励方程：

$J=Q(t+1)+Q(t)\\K=\bar{Q(t+1)}+\bar{Q(t)}$

### T Flip-Flop

相当于一个计数器，clk到edge就加一

特征方程：

$Q(t+1)=Q(t)\oplus T$

激励方程：

$T=Q(t)\oplus Q(t+1)$

## Flip-Flop Timing Parameters 时间参数

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20128.png)

对于边缘触发器，必须给定一定时间的time to setup or hold，这样数据才能稳定存储，不然就会进入亚稳态

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20129.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20130.png)

## Sequential Circuit Analysis

### 四大方程

**触发器的输入方程(flip-flop input equation)** 

表示 触发器的D/SR/JK/T端 和 其他信号的逻辑关系

**输出方程（output equation）**

表示 输出信号Y的逻辑

**状态方程（next-state equation)**

表示 $Q(t+1)=F(Q(t),X,D)$的逻辑

**激励方程（excitation equation）**

表示 从 $Q(t)到Q(t+1)$,D/SR/JK/T端需要的值
$D=F(Q(t),X)$

一般是两输入两输出（两个外部信号，两个内部信号）

一共要分析三个方程

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20131.png)

---

### E.g.1

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20132.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20133.png)

### State Table

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20134.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20135.png)

### State Diagram

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20136.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20137.png)

有向弧上表示了状态切换时的输入量；
然后输出结果有两种表示，也对应了两种类型：
（Mealy type;Moore type)

- Mealy type
输出与状态和输入都有关
有向弧上 `input/output`
- Moore type
输出只与当前状态有关
有向弧上 `input` 状态圈里表示 `output`

### Equivalent State(等价状态)

有相同的输入，输出，下一状态

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20138.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20139.png)

---

### E.g 2

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20140.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20141.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20142.png)

## TimingAnalysis of Sequential Circuits 时间分析

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20143.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20144.png)

e.g1 只是从 input 到 output ：2个 xor

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20145.png)

e.g2 input 到 positive edge :xor+not+ts

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20146.png)

e.g3 positive edge to output : tpd+and+xor+xor

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20147.png)

e.g.4 from positive to next positive : tpd+and+xor+not+ts

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20148.png)

e.g.5 Maximum frequency : 就是从 clk edge到clk edge那段时间对应的频率

## Method of Describing Sequential Analysis

电路设计 也是三个方程！

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20149.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20150.png)

难点在于什么是“状态” 能不能很好的抽象

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20151.png)

### Example 1101

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20152.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20153.png)

初始状态 设置成正确的序列

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20154.png)

然后补全其余的state

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20155.png)

接着根据 状态图 补全 状态表

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20156.png)

### Example 1011-Moore型

刚才的设计是 `Mealy`型

现在欲改为`Moore`型

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20157.png)

去找输出都不变的 就变更输出到状态里面去

（我们可以把输出藏在输入端或者输出端）

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20158.png)

而对于无法处理的节点：新添节点

比如 对于原图中的D节点

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20159.png)

**我们添加了E节点，同时理解E状态就是 成功读取最后一个1之后的状态，所以再多一个1就到C，如果是0就到A**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20160.png)

### Simplification of State Table （状态表简化）

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20161.png)

对于 Next State和Output 都相同的两个state 是等价，可以合并

---

Three cases of equivalent states

首先outputs一定要相同

1. Next States 相同
2. Next States interleaved 交错
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20162.png)
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20163.png)
    
3. Next States circulated 循环
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20164.png)
    

---

### Example 2 (modulo 3)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20165.png)

对输出的理解不同，则model不同

Mealy：

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20166.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20167.png)

Moore：

输出藏在了输入端

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20168.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20169.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20170.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20171.png)

### Example unlimited sequences

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20172.png)

## State Assignment Method
状态编码的方法

将状态进行编码，主要三种

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20173.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20174.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20175.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20176.png)

### Example 1

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20177.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20178.png)

利用卡诺图化简 得到input 和 output方程

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20179.png)

BCD编码 cost较高

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20180.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20181.png)

Gray cost较低

---

one-hot

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20182.png)

## Basic Flip-Flop Descriptors

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20183.png)

特征方程：给定FF的信号，下一个Q(t+1)会如何变化

激励方程：给定Q(t)和Q(t+1)，需要如何的FF信号

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

# Chap 5
Digital Hardware Implementation

## Programmable Logic Device

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20192.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20193.png)

ROM：或项可动，与项不可

PAL：与项上可动，或项个数不行

PLA：与或项都可动

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20194.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20195.png)

---

### ROM

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20196.png)

或项连接个数可变 但最大数量一定

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20197.png)

每个 $D_i$其实就代表 $A_1,A_2,A_3$的不同最小项，F就是最小项之和（所以说与项固定，或项可变）

### PAL

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20198.png)

与项可变，但最终的或项个数不能变

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20199.png)

不止可以是input变量，还可以是先前产生的函数

用例：

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20200.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20201.png)

Fan-in 限定为3则F1超，

但可以将其中两项合为W再作为Fan-in

也就是说PAL并非能表达所有逻辑，因为Fan-in有限，但是我们可以把其他函数的结果作为逻辑信号，间接实现更复杂的逻辑

### PLA

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20202.png)

可以看作前面是PAL后面是ROM

区别在于 PLA 并不使用译码器获得所有最小项，而是用可编程的 AND 阵列来代替译码器。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20203.png)

原来要5个与门（AB+BC+AC+~AB+A~B），现在通过异或巧妙地只需要4个与门(AB+BC+AC+~A~B)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20204.png)

巧用K-map找到一些共同项

看是（1,1）的重合程度高，还是（1,0）的重合程度高

### Lookup Tables（非考试要求）

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20205.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20206.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20207.png)

## FPGA

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20208.png)

# Chapter 6
Registers and Register Transfers

### 概念

寄存器由一系列的flip-flops组成，同时具有许多组合门来 决定 数据是否传入flip-flops中

可以存储vector，还能实现一系列 如count、shift等的操作

## 2-bit Register

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20209.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20210.png)

## Load

原来的设计中，任何的时钟周期都可以进行数据的载入，我们希望这种数据载入能被人为控制，能有一个保持的状态，于是我们引入 `Load`

### Load Method 1:
Registers with Clock Gating
门控时钟

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20211.png)

当`load=1`，正边沿可以正常触发；

当`load=0`，正边沿被屏蔽

但会有 `clock skew`问题

> 然而，在门控时钟技术中，由于添加了一个额外的逻辑门，时钟脉冲到达 Control 的时候会出现额外的传播延时，即**时钟偏移(clock skew)**。而这微小的延时会导致在整个同步系统中，不同组件得到的时钟脉冲有偏差，而这是我们所不希望看到的。所以在实际设计中，我们应当避免或尽可能缩小时钟偏移。
> 
> 
> ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20212.png)
> 

### Load Method 2: Registers with Load-Controlled Feedback

> 另外一个做法是，在不希望它修改的时候，不断将它的输入载入，也就是保持不变。我们可以通过一个 `MUX` 来实现这个功能，用 `Load` 使能端来选择是载入新值还是保持之前的值，如下图。
> 

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20213.png)

$Y=\bar{Load}·Y+Load·In$

当Load=0，hold数据

当Load=1，载入新数据

## **寄存器传输**

一个复杂系统除了信息的存储还需要信息的传输和处理，换句话来说，为了实现灵活、复杂的计算，我们需要信息之间能够广泛地交互。大部分电子系统设计中，都会有一个**控制单元(Control Unit)**来负责指挥**数据通路(Datapath)**进行数据处理。

> Datapath performs data-processing operations, and control unit determines the sequence of those operations.
> 
> 
> Datapaths are defined by their registers and the operations performed on binary data stored in the registers.
> 

对于寄存器自身而言，它可能实现 载入(load)、清空(clear)、移位(shift) 和 计数(count) 等。此外，对于那些寄存器中的数据进行移动了的加工，被称为**寄存器传输操作(Register Transfer Operations)**，它们主要包含这三个部分：

1. 系统中的寄存器集合；
2. 对于数据的操作；
3. 监督操作序列的控制；

其中，最基础的那部分操作被称为**微操作(microoperation)**，它们是实现复杂操作的基础，例如将 R1 的数据载入 R2，将 R1 和 R2 相加，或是自增 R1 等。它们通常是以比特向量为载体并行实现的。

### RTL 寄存器传输语言

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20214.png)

### 注意

对于如上出现的形式如：

 $condition: reg \leftarrow options one regs$ 

的表达式，`:` 左侧出现的 `+` 表示或，右侧的则表示加（“乘”也是这样）！

## 寄存器传输的实现

如何实现寄存器所存储的数据之间的处理与交互是本章节的核心命题。如果说 [**微操作**](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap06/#%E5%BE%AE%E6%93%8D%E4%BD%9C%E5%8F%8A%E5%85%B6%E5%AE%9E%E7%8E%B0) 关注的是数据的处理，那 [**寄存器传输**](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap06/#%E5%AF%84%E5%AD%98%E5%99%A8%E4%BC%A0%E8%BE%93) 则着眼于数据之间的交互。

换句话来说，如何把数据给到别的寄存器、如何获取别的寄存器给到的数据、如何传输和选择这些数据，就是本小节要解决的问题。

特别的，寄存器传输的实现可以直接实现 [**转移**](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap06/#%E8%BD%AC%E7%A7%BB) 操作

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20215.png)

### MUX-based Transfers 
**基于 MUX 实现传输**

对于一个单一寄存器，它的**输入**可能有多种来源，例如其它寄存器，又或者是其他操作的结果。总而言之，它的输入很可能是不唯一的，而同一时刻我们只能接受一个来源的输入。因此，我们需要使用 `MUX` 来对输入进行选择。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20216.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20217.png)

用语言来描述这个总体架构就是，我们通过一系列 `one-hot` 编码（或者是 one-cold）来表示选择哪个输入源（下图中 $K_0\sim K_{n-1}$），再通过 `Encoder` 将它们编码作为 `MUX` 的输入选择信号（下图中 $S_m \sim S_0$），从多个输入源（下图中 $0 \sim k \sim (n-1)$）中选择对应的源，并输出，给到 R0；此外，将选择信号都或起来，作为 R0 的 Load 信号输入。

---

**Dedicated MUX-Based**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20218.png)

每个Register一个独立的MUX，我们就可以控制 R0,R1,R2之间的相互传输

### **Bus implementation
基于总线实现传输**

**MUX Bus**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20219.png)

共享一个MUX，用S0,S1和各个Load信号控制传输

---

**Three-State Bus**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20220.png)

一条线上，只能有一个输入信号，每个寄存器配一个三态门控制其传输

## 微操作及其实现

微操作一般分为这四种：

1. 转移，transfer microoperations，将数据从一个寄存器转移到另外一个寄存器；
2. 算术，arithmetic microoperations，对数据的算术运算操作；
3. 逻辑，logic microoperations，对数据的逻辑运算操作；
4. 移位，shift microoperations，对数据的移位操作；

### 转移

不改变数据本身，只是从一个寄存器中把数据移动到另外一个寄存器。

将 R0 中的数据转移到 R1 中，用 RTL 表示就是 $𝑅0←𝑅1$。

这一部分的实现途径在 [**寄存器传输的实现**](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap06/#%E5%AF%84%E5%AD%98%E5%99%A8%E4%BC%A0%E8%BE%93%E7%9A%84%E5%AE%9E%E7%8E%B0) 已经阐述。

### 算术

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20221.png)

---

就像我们之前学过的，用加法器实现加减法器，在 RTL 和模块逻辑电路的维度下，可以这么表示：

$\begin{aligned}    &\overline{X}K_1:R_1\leftarrow R_1 + R_2 \\
    &XK_1:R_1\leftarrow R_1 + \overline{R_2} + 1
\end{aligned}$

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20222.png)

### 逻辑

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20223.png)

直接用逻辑门即可

### 移位

**串行**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20224.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20225.png)

利用多个D-FF，前一个的输出作为后者的输入，再多添一个 `serial input/shift right input` (In)

---

**并行 (Parallel Load)** 

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20226.png)

并行输出的实现非常简单，只需要给每一个 `FF` 的输出引出一条线就行了，它与串行输出可以直接同时存在；而并行输入则与串行输入冲突，一次只能实现其中一个，所以需要一些控制电路

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20227.png)

看起来有点复杂，但是实际上逻辑还是很清晰的。

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
        

总和来说，就是：

$Shift:Q←\text{sl}~Q\\\overline{Shift}·Load:Q←D\\\overline{Shift}·\overline{Load}:Q←Q$

---

**双向移位**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20228.png)

用一个MUX来控制4种功能

## Counter

对比两种计数器

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20229.png)

### Ripple Counter 行波计数器（异步）

行波计数器的主要思想就是将一个不断自反的 `FF` 的输出直接或间接作为下一个 `FF` 的时钟脉冲。由于形成一次脉冲需要一对 `0`&`1`，所以前一个 `FF` 取反两次才能引起下一个 `FF` 取反一次，如果下一个 `FF` 是在上一个 `FF` 的输出从 `1` 变 `0` 时触发，那两个 `FF` 的变化刚好对应于二进制自增的进位规律：`(0,0)`，`(0,1)`，`(1,0)`，`(1,1)`，`(0,0)`，...

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20230.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20231.png)

可以发现，行波计数器的优点是电路简单，成本低；但是缺点也很明显，既然它与同步计数器相区分，就说明它不是同步电路，每一个 `FF` 都会有传播延时，**随着计数范围增大，总传播延时也会增加**，而为了让电路正常工作，时钟频率也要因此下降。

由于这些，书上对行波计数器的评价是多数情况下行波加法器只会在低功耗电路中被采用。

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20232.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20233.png)

### Synchronous Counters 同步计数器

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20234.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20235.png)

左边是个自增器，右边是4个D-FF，用CE来控制是否自增，CO是满溢的输出

---

**同步载入**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20236.png)

这里同步载入的含义可以同 [**移位寄存器的并行载入**](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap06/#%E5%B9%B6%E8%A1%8C%E5%8C%96) 类比，其主要目的是将计数器的当前值设为一个我们需要的数字。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20237.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20238.png)

### Synchronous BCD

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20239.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20240.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20241.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20242.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20243.png)

当计数器的输出为 `9` 时，下一周期让计数器载入 `0`

> 按理来说这里应该是 $𝐿𝑜𝑎𝑑=𝑄_0⋅\overline{𝑄_1}⋅\overline{𝑄_2}⋅𝑄_3$，以对应 9D=1001B，但是由于自增过程中，`1001` 是第一个满足 `1??1` 的组合，所以可以直接简化为 $𝐿𝑜𝑎𝑑=𝑄_0⋅𝑄_3$
> 

---

**Mod N 计数器**

实际上，我们可以把 BCD 码循环计数器看作是特殊的 Mod N 计数器，即 N = 10 的 Mod N 计数器。

或许你会想，实现 Mod N 计数器能不能在满足输出条件后直接使用 `Clear` 输入。但是请不要忘记了，`Clear` 也好，`Set` 也罢，它们都是异步操作。我们没有必要也不应该使用异步操作，所以最好的做法还是使用 `Load`。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20244.png)

## Register Cell
寄存器单元

**寄存器单元(Register Cell)**是寄存器的个体单元，主要包括一个 `FF` 及实现其组合逻辑的组合电路。

### Register cell design

设计寄存器（尤其是大规模的寄存器）的重要手段之一，就是**寄存器单元设计(Register Cell Design)**。通常遵循以下步骤：

1. 设计具有代表性的寄存器单元；
2. 复制并连接若干个这样的寄存器单元；
3. 修改某几个寄存器单元（通常可能是一串寄存器的首尾两个单元）以解决一些特殊情况或边界问题；

### Register Cell Specification

设计寄存器单元时，我们需要对寄存器单元进行定义。而指定(Specify)一个寄存器单元的功能的主要有这些方面：

- 寄存器的功能函数；
    - 一般指寄存器传输；
- 控制信号构成；
    - 有哪些控制信号、是否编码、如何决定是否 Load 等；
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20245.png)
    
- 寄存器的输入数据；
    - 有哪些输入数据、是否需要预先处理等；

在实际实现时，分为 `MUX` 实现 和 时序逻辑实现 两种方法。

MUX 易读简单但门输入代价高，传统时序电路设计不易读但们输入代价低

---

**MUX实现**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20246.png)

- **Example 1**
    
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20247.png)
    
    - **MUX法**
        
        ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20248.png)
        
        ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20249.png)
        
    - 传统时序电路设计法
        
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

### Example Dash-Watch

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20254.png)

分析输入、输出、寄存器

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20255.png)

# Chapter 7 Memory Basics

## 内存

**内存(Memory)**由一系列存储单元与相应的逻辑电路组成，计算机中的内存包括两类：**随机访问内存(Random-Access Memory)**与**只读内存(Read-Only Memory)**。这两类内存都需要借助**地址(address)**来实现对数据的读与写。其中，只读内存（即 ROM）的相关知识已经在 [第五章#ROM](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap05/#rom) 中提及，本章主要讨论随机访问内存（即 RAM）。

---

### **组织架构**

**内存组织架构(Memory Organization)**反映了内存中的数据是如何通过地址被访问的。

### **数据类型**

计算机中常用的数据类型主要有三种：

- **位(bit)**：最小单元
- **字节(byte)**：8 个连续的 bit
- **字(word)**：特定数量的连续的 bit，由内存类型决定，传统意义上 1 word = 4 bytes

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20256.png)

考虑一个 $2𝑘×𝑛$ 的内存单元， $k$ 表示地址的位宽， $𝑛$ 表示 word 的位宽。这个内存单元的示意图如下，其中，*k*-bit 的地址经过 decoder 译码，得到的 2𝑘 个输出分别与 2𝑘 个 word 形成唯一确定的连接，从而达到寻址的目的；每个 word 由 𝑛-bit 组成，所以输入和输出也都是 𝑛-bit 的。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20257.png)

### 基本操作

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20258.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20259.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20260.png)

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20261.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20262.png)

总之，地址信号先进来等待译码结束后再传入读写信号，最后再有一段恢复时间

## 静态内存

RAM 可以分为**静态内存(Static RAM, or SRAM)**和**动态内存(Dynamic RAM, or DRAM)**两种：

- SRAM：数据存储在锁存器(latch)中；
- DRAM：数据存储在电容中，以电荷量的形式存储；

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20263.png)

静态内存更复杂更快但成本更高

### **SRAM Cell**

首先考虑一个 SRAM 的最小单元，即 **SRAM Cell**（下面简称为 RAM Cell），用于存储 1-bit 的信息。

这个 RAM Cell 是通过一个 SR Latch 实现的，当 select 置 `0` 时，表示 RAM Cell 未被使能，锁存器中的数据处于保持状态，输出恒为 `1`；当 select 置 `1` 时，锁存器中的数据由 B 端的输入信号决定，C 端输出锁存器中存储的数据。但是，现在这样一个简单的 RAM Cell 还无法实现真正意义上的读和写操作，还需要一些外部逻辑电路，详见 [#SRAM Bit Slice](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/Chap07/#sram-bit-slice)。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20264.png)

---

### **SRAM Bit Slice**

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20265.png)

地址有4位，那么地址深度就是 $2^4$,然后每个cell存一个bit，得到一个 $2^4\times1$RAM

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20266.png)

`Word select`选择要输出的cell，`Bit Select(Chip Select)`使能信号控制整个内存是否运转

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

DRAM Cell 和 SRAM Cell 基本类似，也拥有一个 select 使能端和一组输入输出端，唯一的区别在于存储器的不同。SRAM Cell 使用一个锁存器来存储数据，而 DRAM Cell 使用**一个电容**和**一个晶体管**来存储数据。

- 晶体管 T 可以视作一个开关，用来连接外部输入信号 B 和电容 C；
- 电容 C 用于存储数据，当电容为满（电荷量高于某一阈值）时表示高电平（如图 (b)），当电容为空（电荷量低于某一阈值）时表示低电平（如图 (c)）；

下面考虑 DRAM Cell 的读操作和写操作：

- 写操作：如图 (d) 写入高电平，如图 (e) 写入低电平；
- 读操作：如图 (f) 读取高电平，当 T 打开时，左侧输入端可以监测到一个电荷量的升高，这就代表读取到的数据是高电平；而相应地，右侧电容中的电荷量也有所降低；如图 (g) 读取低电平同理；
    - 不难发现，每次读操作都会稍微改变电容中存储的电荷量，因此对于每一次读操作，都要进行**复位(restore)**，也就是将电容中的电荷量恢复到读操作之前的水平；

![https://note.isshikih.top/cour_note/D2QD_DigitalDesign/img/141.png](https://note.isshikih.top/cour_note/D2QD_DigitalDesign/img/141.png)

---

### DRAM Bit Slice

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20270.png)

DRAM Bit Slice 和 SRAM Bit Slice 基本类似，前者的输出端会额外加一个放大器，从而将电荷量微小的变化转化成数字信号。虽然电路结构并没有本质差别，但两者**实际的电路开销**却区别很大。DRAM cell 含有一个电容和一个晶体管，而 SRAM cell 含有六个晶体管，所以 DRAM 的每 bit 的开销显著低于 SRAM，这也是 DRAM 在大型内存中被更加广泛的应用的原因。

---

DRAM 常用于大型内存，而在这些内存中，地址会变得很长（超过 20-bit），以至于 DRAM 的引脚数量不足以一次性接收这么长的地址。解决方法是将地址**分成两部分串行的输入**到 DRAM 里来，首先是 row address，然后紧接着是 column address（注意到这里也有重合选择的思想）。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20271.png)

例如64K需要传16位寻址信号，可以先传高的8位，再传低的8位

---

DRAM传输先给行地址(row)再给列地址(column)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20272.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20273.png)

上图中：

- 由于地址被分成两部分串行输入到 DRAM 里来，因此需要用 register 分别存储 row address 和 column address；
- RAS(Row Address Strobe) 和 CAS(Column Address Strobe) 用作 register 的载入信号，置 `0` 表示载入；
- 对于写操作，当 row address 选中某一行的时候，除了被写入的 cell 之外，这一行中的其他 cell 也被使能并进行了 restore 操作；
- 对于读操作，当 row address 选中某一行的时候，包括要读取的 cell 在内，这一行中的所有 cell 都被使能并进行了 restore 操作；
- refresh controller 和 refresh counter 模块负责实现 refresh 功能；

---

### Refresh Policies

由于DRAM会逐渐丢失存储数据，所以必须定期刷新

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
    

**引入**

为了解释这些 DRAM 是如何达到更快的内存访问速度的，这里有必要先介绍两个事实：

1. 现代计算机中，绝大多数时候从 DRAM 中读取的数据并没有直接传输给 CPU，而是被存放在了高速缓存(cache)中。高速缓存从 DRAM 中读取数据的时候，总是一次性读取一串相邻的字节，这被称为**爆发模式读取数据(burst read)**。对于 burst read 而言，影响速度的最重要因素不再是寻址的时间，而是连续读取相邻字节的时间；
2. DRAM 的特性是，每当 row address 选中某一行时，这一行内的所有 cell 都被使能，即都是可访问的；

所以，DRAM 的这种特性，使得它非常适合 burst read，即连续读取同一行中的相邻字节。利用 burst read，DRAM 可以达到更快的内存访问速度。

---

### SDRAM

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20278.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20279.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20280.png)

### DDRAM

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20281.png)