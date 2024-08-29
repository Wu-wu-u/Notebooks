# Chap 2
Basic Structures

## Set

| subset | $A \subseteq B$ |
| --- | --- |
| proper subset | $A\subset B$ |
| cardinality | $\|A\|$ |
| power set |  $P(S)=\{x\|x\subseteq S\}$  |
| union | $\cup$ |
| intersection | $\cap$ |
| cartesian product | $A \times B$ |

- $|A\cup B|=|A|+B|-|A\cap B|$

- $A-B=A\cap \overline B$

- $A\oplus B=(A\cup B)-(A\cap B)$

## Computer Representation of Set

- use bit string

- $a_1,a_2,…a_n$依次可以用0/1表示存在与否，然后用bit operation求交并

## Function

- $f:A→B$

- $\exists a(a\in A \rightarrow \exists b ((b \in B \land f(a)=b )\land \forall c((c\in B \land c=f(a))\rightarrow c=b))$

### onto

- B的每一个y 都能求出至少一个x对应

- 意味着

- $|A|\geq|B|$

### one-to-one

- A中的每个x都能对应一个独特的y，即x不同 f(x)不同

- $|A|\leq|B|$

## Countable Infinite Set

- $if, f: A→B  (bijection)\\|A|=|B|$

??? Tip "Prove-Example"

    - 只需证明，和 $|N|\space/ \space |Z|$等相同即可

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%204.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%205.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%206.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%207.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%208.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%209.png)

## **Cantor Diagonalization Argument**

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2010.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2011.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2012.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2013.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2014.png)

## 题集


![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2015.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2016.png)

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2017.png)
