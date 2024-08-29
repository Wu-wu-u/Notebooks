# Chap 2
Combinational Logic Circuits

??? info "逻辑门"
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%202.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%203.png)

## **Duality rules**

- 变 $AND$ 为 $OR$ , 添加括号保证内容运算顺序不变
- self-dual
    - H=AB+AC+BC
    - dual H=(A+B)$\cdot$(A+C) (B+C)
- complementing functions
    - use DeMorgan’s Laws(break the line,change the sign)

## Theorem

=== "Minimization"
    $XY+\overline{X}Y=Y$
    $(X+Y)(\overline {X}+Y)=Y$
=== "Distributive"
    $X+YZ=(X+Y)(X+Z)$
=== "Absorption"
    $A+A \cdot B=A$
    $A+\overline{A}B=A+B$
=== "Consensus"
    $AB+\overline{A} C+BC=AB+\overline{A}C\\=（A+C)(\overline A+B)=(A+C)(\overline A +B)(B+C)$

??? note "Examples"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%204.png)

    - 想absorb $\overline Y Z, XY$, 就主动填项来让剩余的去吸收

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

- Gate Input Cost:
    - L(literal cost) 
    - G(gate input count excluding single literal) 
    - GN(gate input count with NOTs)

??? note "Example"
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2014.png)

    - **非门不要重复数**

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2015.png)

## K-Maps

- **Gary-code, adjacent squares combining**

??? note "三维卡诺图"
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2016.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2017.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2018.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2019.png)

!!! warning "Pitfalls"
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2020.png)

    - **圈 $2^n$ 个**

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2021.png)

    - 四维注意number位置

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2022.png)

??? note "Traps Example"

    不可圈中间4个，因为另4个小圈必会包含！！！

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2023.png)

    正确的圈法就是红色，而非红+蓝

## Don’t Cares

- "don't cares"可以在以下情况下使用：

    1. **输入不可能出现**：例如，如果我们有一个4位的二进制输入，但我们知道只有10种输入是有效的（0000到1001），那么其他6种输入（1010到1111）就可以被视为"don't cares"。
    2. **输出对系统行为无影响**：例如，如果我们正在设计一个系统，该系统在某些输入条件下的输出并不会影响系统的其他部分，那么这些输出就可以被视为"don't cares"。

!!! note "example"
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2024.png)

??? tip "one-hot encoding"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2025.png)

    - 更多的输入换取更多的优化机会和更少的门cost

## **Systematic Simplification**

!!! info
    - Prime Implicant 包含 $2^n$个implicant的最大的

    - Essential Prime Implicant 含有其他prime implicant没有的项

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2026.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2027.png)

    - Essential Prime Implicant 是必须优化的，剩余的有很多选择性

### **Quine–McCluskey Algorithm**

!!! info
    1.Find all prime implicants.
    2.Include all essential prime implicants in the
    solution
    3.Select a minimum cost set of non-essential
    prime implicants to cover all minterms not yet
    covered:

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2028.png)

## XOR

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2029.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2030.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2031.png)



!!! tip "applications of odd/even functions"
    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2032.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2033.png)

## Buffer

中继器

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2034.png)

### 3-state Buffer(0/1/z)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2035.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%2036.png)
