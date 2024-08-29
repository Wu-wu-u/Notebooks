## Module

三部分：I/O说明，内部信号声明，功能定义

### 功能定义

1.用`assign`声明

`assign a = b & c;`

2.用实例元件

`and ## 2 ul(q , a , b)`
3.用`always`块

```verilog
always @(posedge clk or posedge clr)；
begin
			if(clr)q<=0;
				else if (en)q<=d;
end
```

### 同时发生与顺序发生

1.所有的过程块（如：`initial`块、`always`块）、连续赋值语句、实例引用都是并行的

它们表示的只是一种通过变量名互相连接的关系

2.三者出现的先后秩序没有关系

4.只有 **连续赋值语句`assign`和实例引用语句**可以独立于过程块存在于模块的功能定义部分

Note：许多与`C`类似的语句只能出现在过程块，而不能随意出现在模块功能定义的范围内。

## 数据类型

共有19种，最基本的四种为：

`reg、wire、integer、parameter`

### 1. 常量

#### 1.1 整数

常用基数表示法：
`[位宽][’][进制符号](b,o,d,h)[对应数值]` 

e.g.

1. 8’hab表示8bit的十六进制数，换算成二进制是1010_1011；
2. 8’d171表示8bit的十进制数，换算成二进制是1010_1011；
3. 8’o253表示8bit的八进制数，换算成二进制是1010_1011；
4. 8’b1010_1011表示8bit的二进制数，二进制就是1010_1011。
- x和z值
x代表不定值，z(?)代表高阻值
可以用来定义十六进制数的4位二进制数状态，八进制数的3位，二进制数的1位。

```verilog
4'b10x0 //位宽为4的二进制数从低位数起第2位为不定值
4'b101z //位宽为4的二进制数从低位数起第1位为高阻值
12'dz //位宽为4的二进制数从低位数起第1位为高阻值
12'd? //位宽为12的十进制数，其值为高阻值(第2种表达方式)
8'h4x //位宽为8的十六进制数, 其低4位值为不定值
```

- 负数

```verilog
-8'd5 //这个表达式代表5的补数,并不代表-5(用八位二进制数表示)
8'd-5 //非法格式
```

当常量不说明位数时 ，默认值是 3 2 位 ，每个字母用 8 位的 A S C I I 值表示 。例 :

```verilog
10 = 32‘d10 = 32'b1010
1 = 32'd1 = 32'b1
-1 = -32'd1 = 32'hFFFFFFFF
'BX = 32'BX = 32'BXXXXXX···X
"AB" = 16'B01000001_01000010 = 16'h4142  //字符串AB
```

#### 1.2 实数

可采用十进制，也可采用科学计数法：
13_2.18e2 → 13218

#### 1.3 参数

`parameter`是一种常量，出现在module内部，常被用于定义状态机的状态、数据位宽和计数器计数个数大小。

`parameter`是参数型数据的确认符，后面跟着一个赋值语句，每个赋值语句右边必须是一个常数表达式，也就是说，该表达式只能含数字或先前已定义过的参数

例如：

```verilog

parameter msb = 7;  //定义参数msb为参量7
parameter r = 5.7;  //声明r为实型参数
parameter byte_size = 8,byte_msb = byte_size - 1; //用常数表达式赋值

parameter IDLE = 3'b001
parameter CNT_1S_WIDTH = 4'd15
parameter CNT_MAX = 25'd24_999_999
```

参数型常数，常用于定义延迟时间和变量宽度

### 2.变量

#### 2.1 wire

`wire [n-1:0] data_name` 有n条线路

#### 2.2 reg

寄存器

`reg [n-1:0] data_name`

区别：

1. `wire`：`wire` 类型的变量用于描述连续赋值（continuous assignment）和模块间的连接。`wire` 变量的值只能通过 `assign` 语句或者作为模块的输出端口来改变。`wire` 变量不能在 `always` 或 `initial` 块中被赋值。
2. `reg`：`reg` 类型的变量用于描述过程赋值（procedural assignment），即在 `always` 或 `initial` 块中的赋值。`reg` 变量的值可以在 `always` 或 `initial` 块中通过 `=` 或 `<=` 来改变。尽管名为 `reg`，但它并不一定表示寄存器，它可以用来描述组合逻辑和时序逻辑。

## 语句

### 1. 赋值语句

1. 阻塞赋值（Blocking Assignment）：使用 `=` 进行赋值。它是顺序执行的，即在当前赋值语句执行完成之前，后续的赋值语句会被阻塞，不会执行。这种赋值方式主要用于描述组合逻辑。

```verilog
always @ (posedge clk)
begin
    a = b;
    c = a; // 这里的 a 是已经被赋值后的 a
end
```

1. 非阻塞赋值（Non-blocking Assignment）：使用 `<=` 进行赋值。所有的非阻塞赋值语句会在同一模拟时间内并行执行，即后续的赋值语句不会被前面的赋值语句阻塞。这种赋值方式主要用于描述时序逻辑，如触发器。

```verilog
always @ (posedge clk)
begin
    a <= b;
    c <= a; // 这里的 a 是未被赋值前的 a
end
```

### 2. 位拼接运算符

`{ , }` 

1. 将位宽较短的数据拼接成一个位宽长的数据

如果将8bit的a，3bit的b，5bit的c按顺序拼接成一个16bit的d：

```verilog
wire [15:0] d;
d={a,b,c}
```

1. 通过位拼接实现移位

e.g.

din是1bit的串行数据，假如刚开始传来的数据是1，后面的数据都是0，则第一个时钟时4bit dout的值为4’b1000，第二个时钟时dout的高三位放到最后，新来的0放到dout的最高位，变为4’b0100，从而实现了数据的右移功能。

```verilog
always@(posedge sys_clk or negedge sys_rst_n)

if(sys_rst_n == 1’b0)

dout <= 4’b0;

else

dout <= {din, dout[3:1]}; //右移
```

左移同理，din是1bit的串行数据，假如刚开始传来的数据是1，后面的数据都是0，则第一个时钟时4bit dout的值为4’b0001，第二个时钟时dout的低三位放到最前面，新来的0放到dout的最低位，变为4’b0010，从而实现了数据的左移功能。

```verilog
always@(posedge sys_clk or negedge sys_rst_n)

if(sys_rst_n == 1’b0)

dout <= 4’b0;

else

dout <= {dout[2:0], din}; //左移
```

### 3. if-else, case

if-else 同 C
case 类 C

e.g.

```verilog
module case_example(input [1:0] a, output reg [3:0] b);
    always @* begin
        case (a)
            2'b00: b = 4'b0001;
            2'b01: b = 4'b0010;
            2'b10: b = 4'b0100;
            2'b11: b = 4'b1000;
            default: b = 4'b0000;
        endcase
    end
endmodule
```

在这个例子中，我们有一个 2 位宽的输入 `a` 和一个 4 位宽的输出 `b`。`case` 语句根据 `a` 的值来决定 `b` 的值。如果 `a` 是 `00`，`b` 就被赋值为 `0001`；如果 `a` 是 `01`，`b` 就被赋值为 `0010`，以此类推。如果 `a` 的值不在 `case` 语句中列出的值中，`b` 就被赋值为 `0000`。这就是 `default` 语句的作用。