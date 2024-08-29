# Discrete Mathematics

## References

online resources:[www.mhhe.com/rosen](http://www.mhhe.com/rosen)
notes:[https://oneko.zone/zju/dm/](https://oneko.zone/zju/dm/)

## Grading

- Homework (10%)
- Quizzes (20%)
Quiz 1 on April 2nd
Quiz 2 on May 28th
- Midterm exam(20%) on May 7th
- Final (50%)

# Chap 1 
Logic and Proofs

## Logical Equivalences

| Equivalences | Name |
| --- | --- |
| $p \land \bold{T}\equiv p$
$p \lor F \equiv p$ | Identity laws |
| $p \lor T \equiv T$
$p \land F \equiv p$ | Domination laws |
| $p \land p \equiv p$
$p \lor p \equiv p$ | Idempotent laws |
| $\lnot \lnot p \equiv p$ | Double negation laws |
| $p \land q \equiv q \land p$
$p \lor q \equiv q \lor p$ | Commutative laws |
| $(p \land q) \land r \equiv p \land (q \land r)$
$(p \lor q) \lor r \equiv p \lor (q \lor r)$ | Associative laws |
| $p \lor (q \land r) \equiv (p \lor q) \land (p \lor r)$
$p \land (q \lor r) \equiv (p \land q) \lor (p \land r)$ | Distributive laws |
| $\lnot (p \land q) \equiv \lnot p \lor \lnot q$
$\lnot (p \lor q) \equiv \lnot p \land \lnot q$ | De Morgan’s laws |
| $p \lor (p \land q) \equiv p$
$p \land (p \lor q) \equiv p$ | Absorption laws |
| $p \lor \lnot p \equiv T$
$p \land \lnot p \equiv F$ | Negation laws |
| $p \rightarrow q \equiv \lnot p \lor q$ | Implication laws |
| $p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p)$ | Equivalence laws |

### Examples:

### n-Queens

no queen can be placed in the same row or column or on the same diagonal.
We first note that $\lor _{j=1}^{n}p(i,j)$ asserts that row i contains at least one queen,and 
$Q_1=\land_{i=1}^{n} \lor_{j=1}^{n}p(i,j)$
asserts that every row contains at least one queen.

$Q_2=\land_{i=1}^{n} \land_{j=1}^{n-1}\land_{k=j+1}^{n}(\lnot p(i,j)\lor \lnot p(k,j))$
asserts that there is at most one queen in each row.

$Q_3=\land_{j=1}^{n} \land_{i=1}^{n-1}\land_{k=i+1}^{n}(\lnot p(i,j)\lor \lnot p(k,j))$
asserts that there is at most one queen in each column.

$Q_4=\land_{i=2}^{n} \land_{j=1}^{n-1}\land_{k=1}^{min(i-1,n-j)}(\lnot p(i,j)\lor \lnot p(i-k,j+k))$

$Q_5=\land_{i=1}^{n-1} \land_{j=1}^{n-1}\land_{k=1}^{min(n-i,n-j)}(\lnot p(i,j)\lor \lnot p(i+k,j+k))$
assert that no diagonal contains two queens.
$Q=Q_1\land Q_2 \land Q_3 \land Q_4 \land Q_5$

### Sudoku

We assert every row contains every number:
$\land_{i=1}^{9} \land_{n=1}^{9} \lor _{j=1}^{9} p(i,j,n)$

We assert every column contains every number:
$\land_{j=1}^{9} \land_{n=1}^{9} \lor _{i=1}^{9} p(i,j,n)$

We assert that each of the nine 3 $\times$ 3 blocks contains every  numnber:
$\land_{r=0}^{2} \land _{s=0}^{2} \land_{n=1}^{9} \lor_{i=1}^{3} \lor _{j=1}^{3} p(i+3r,j+3s,n)$

no cells have more than one number:
$p(i,j,n)→p(i,j,n’)$

## Predicates and Quantifiers

| Original  | Equivalences |
| --- | --- |
| $\lnot \exist xP(x)$ | $\forall x \lnot P(x)$ |
| $\lnot \forall xP(x)$ | $\exist x \lnot P(x)$ |

**Attention**:
to tell the difference 

All CS students are smart students
$\forall x (C(x)→S(x))$
Some CS students are smart students
$\exist x(C(x)\land S(x))$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%201.png)

### Nested Quantifiers

From these observations, it follows that if $∃y∀xP(x, y)$ is true, then $∀x∃yP(x, y)$ must also
be true. However, if $∀x∃yP(x,y)$ is true, it is not necessary for $∃y∀xP(x,y)$ to be true

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%202.png)

## Norm formals

### DNF

Full Disjunctive Normal forms = Sum of minterms
minterm: conjunctions of each single variable
every variable is presented exactly once in a minterm

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%203.png)

### CNF

product of maxterms

application:
1.determine equivalence
2.determine tautology ,contradiction or contingency

### prenex normal form :

$Q_1x_1Q_2x_2···Q_nx_nB$ , where $Q_i(i=1,···n)$ is quantifiers $\forall$ or $\exist$ and the predicate $B$ is quantifier free

how to transform into prenex normal form:
1. eliminate  $→$ and $\leftrightarrow$
2. rename the variables

## Rules of Inference

1. Modus ponens
$p \\
p→q \\
\therefore q$
2. Modus tollens
$\lnot q \\
p→q \\
\therefore \lnot p$
3. Hypothetical Syllogism
$p\rightarrow q \\
q→r \\
\therefore p \rightarrow r$
4. Disjunctive Syllogism
$p \lor q \\
\lnot p \\
\therefore q$
5. Addition
$p \\
\therefore p \lor q$
6. Simplifcation
$p\land q \\
\therefore p$
7. Conjunction
$p \\
q \\
\therefore p\land q$
8. Resolution
$p\lor q \\
\lnot p \land r \\
\therefore q\lor r$

# Chap 2
Basic Structures

## Set

| subset | $A \subseteq B$ |
| --- | --- |
| proper subset | $A\subset B$ |
| cardinality | $|A|$ |
| power set | $P(S)=\{x|x\subseteq S\}$ |
| union | $\cup$ |
| intersection | $\cap$ |
| cartesian product | $A \times B$ |

$|A\cup B|=|A|+B|-|A\cap B|$

$A-B=A\cap \overline B$

$A\oplus B=(A\cup B)-(A\cap B)$

## Computer Representation of Set

use bit string

$a_1,a_2,…a_n$依次可以用0/1表示存在与否，然后用bit operation求交并

## Function

$f:A→B$

$\exist a(a\in A \rightarrow \exist b ((b \in B \land f(a)=b )\land \forall c((c\in B \land c=f(a))\rightarrow c=b))$

### onto

B的每一个y 都能求出至少一个x对应

 意味着

 $|A|\geq|B|$

### one-to-one

A中的每个x都能对应一个独特的y，即x不同 f(x)不同

$|A|\leq|B|$

## Countable Infinite Set

$if, f: A→B  (bijection)\\|A|=|B|$

### prove

只需证明，和 $|N|\space/ \space |Z|$等相同即可

example 1:

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

# Chap 3
Algorithm

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2018.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2019.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2020.png)

# Chap 4
Number Theory and Cryptography

## 4.1 Divisibility and Modular Arithmetic

除法没什么好说，注意余数必须非负就行

---

### 定理：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2021.png)

## 4.3 质数与gcd

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2022.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2023.png)

## 4.4 Solving Congruences 求解同余方程

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2024.png)

### 求逆

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2025.png)

两个互质的数求gcd，最后一定是1；然后求出对应的贝祖表达式，和a相乘的数就是 $\overline{a}$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2026.png)

### 求解方程

两边同乘a的逆，然后就得到 $x\equiv m$的同余方程，就秒了

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2027.png)

### 中国剩余定理

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2028.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2029.png)

找到所有模数的乘积m，然后依次构造除了mi以外的乘积项Mi；然后找到每一项Mi的逆（模mi）；最后构造 $x=a_1M_1y_1+…+a_nM_ny_n$

### 费马小定理

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2030.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2031.png)

# Chap 5
Induction and Recursion

## Mathematical Induction

数学归纳法

假设P(k)成立 推断P(k+1)成立

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2032.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2033.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2034.png)

## Strong Induction

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2035.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2036.png)

### well-ordering property

良序性质（Well-Ordering Property)
定义是：对于任何非空的自然数集合，总存在一个最小元素。

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2037.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2038.png)

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2039.png)

- 首先，我们假设在一个循环赛中存在一个长度为m的循环，其中m >= 3。我们将这个循环的玩家记为p1, p2, ..., pm，满足p1击败p2，p2击败p3，...，pm-1击败pm，pm击败p1。
    
    我们考虑所有这样的循环的长度集合S = {m | m >= 3}。由于我们假设存在一个长度为m的循环，所以S是非空的。由于S是非空的自然数集合，根据良序性质，S中必然存在一个最小元素，我们将其记为n。
    
    如果n = 3，那么我们已经找到了一个长度为3的循环，证明结束。
    
    如果n > 3，我们考虑一个长度为n的循环，玩家为p1, p2, ..., pn。在p1,p2,p3中，p1和p3存在两种情况：p1打败p3或者p3打败p1，都将会构成一个长度为3的circle。这与我们假设n是S的最小元素矛盾。
    
    所以，我们证明了如果在一个循环赛中存在一个长度为m的循环，那么必然存在一个长度为3的循环。
    

## Recursive Definition

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2040.png)

先给定前k个值，再给出递推关系

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2041.png)

### 欧几里得算法

$gcd(a,b)=gcd(b,r)$

每进行一次gcd，就会让较大的数至少减小一半,

- LAME’S Theorem
    
    

## Structural Induction

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2042.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2043.png)

## 题集

Sec.5.1

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2044.png)

重言式(tautology)

这个证明关键在于，不仅assume P(K)成立，还要assume Hypothesis成立

所以证明P(K+1)时，

有 $p_k→p_{k+1}以及[(p_1\land … \land p_{k-1})→p_k]$

$\therefore (p_1 \land …\land p_{k-1})→p_{k+1}$

$\therefore (p_1 \land …\land p_{k-1}\land p_k)→p_{k+1}$是个weaker推理，更是正确

---

Sec.5.2

(well-ordering的应用）

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2045.png)

关于唯一性的证明：
我们假设 $a=dq+r=dq’+r’$

都有 $0<r≤d,0<r’≤d$

那么 $d(q-q’)=r-r’$

说明 r-r’是d的整数倍

又因为 $-d<r-r’<d$ 所以 $r-r’=0$

$q=q’$

---

Sec.5.2
（利用数学归纳法证明良序性）

我们先假设 Well-Ordering 不正确，也就是非空自然数集合无最小元素。
给定一个非空自然数集合S,
Statement P(n)代表了 $i\notin S, \text{for }i=1,2,3…n$

那么为了保证Well-Ordering为false，那么P(0)为true；假设P(n)为true，P(n+1)也必须为true，不然 n+1这个元素就是S里的最小元素；于是最后我们递推得到S是个空集φ，矛盾！

---

Sec.5.2

良序性可以用来证明:两个正整数有唯一的最大公因子。设a和b 都是正整数，设S是形如as+bt的正整数的集合，其中s和t都是正整数。

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2046.png)

a) 任选s=t=1，那么a+b就是一个元素，所以S非空

b) 根据良序性，S为非空自然数集合，那么有最小元c

c) $a\equiv b \equiv c \equiv 0 (\text{mod d})$

d) 先假设c不整除a，那么就会有余数r, $0<r<c$
$r=(1-qs)a+(-qt)b, r\in S$ 矛盾

e) 根据c)我们知道ab的公因子一定是c的因子，那么这个公因子 d≤c;同时，c又可以整除a与b，说明c是ab的公因子；综上ab的最大公因子就是c且唯一

---

# Chap 6
Counting

容斥原理: $|A\cup B|=|A|+|B|-|A\cap B|$

## Pigeonhole Principle

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2047.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2048.png)

妙妙的例题：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2049.png)

---

广义鸽巢原理

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2050.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2051.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2052.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2053.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2054.png)

## 排列与组合

### 帕斯卡恒等式

$C_{n+1}^{k}=C_{n}^{k-1}+C_n^k$

### 范德蒙德恒等式

$C_{m+n}^r = \sum _{k=0}^r C_m^{r-k} C_n^{k}$

m里选r-k个，n里选k个

### 其他的

$C_{2n}^n=\sum_{k=0}^n (C_n^k)^2$ 范德蒙德的特例

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2055.png)

$C_{n+1}^{r+1} = \sum_{j=r}^n C_j^r$

### 隔板法

隔板的个数就是不同种类的物件数 n-1

星星数也就是要取的数 为r

$N=C(n+r-1,r)=C(n+r-1,n-1)$

### 有别盒子与有别物体

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2056.png)

### 有别盒子与无别物体（就是隔板）

$N=C(n+r-1,r)=C(n+r-1,n-1)$

### 无别盒子与有别物体

只能分类讨论！！

### 无别盒子与无别物体

就是写数字＝什么

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2057.png)

## Generating Permutations and Combinations
(生成排列和组合)

### 字典序生成排列

从后往前两两比对 $a_n和a_{n-1}$

如果 $a_n > a_{n-1}$ 直接互换就完事

如果不是：即 $a_{n-1}>a_n$

继续向前两两比对，直到找到 $i$
$s.t. \space a_i<a_{i+1}$

然后在 $a_{(i+1,n)}$中找到找到 恰比 $a_i$大的数，进行互换。

随后把 $(a_{i+1},a_n)$升序排列

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2058.png)

### 生成比特串组合

从后往前找到第一个0，然后把这个0变成1，它的右边全变为0（异或 carry-in）

$e.g. \\ 1000100111 → 1000101000$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2059.png)

### 生成集合的 r 组合

对于集合 ${1,2,3,4…,n}$
最小的r集合 ${1,2,3,4…,r}$
最大的r集合 ${n-r+1,n-r+2…,n}$

那么我们可以认为 对于 每一位 $a_i$ 它的上限 就是 自己对应最大r集合的 数 即 n-r+i 
超过这个上限，可以看做是一种进位

于是我们的算法是：

找到第一个不满足 $a_i=n-r+i$的数，也就是说右边的数全达上限，我们开始进位， $a_i$++ 
那么右边的数也有一个下限 即 $a_{i+1}=a_i+1$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2060.png)

## 题集

Sec.6.2（鸽巢）

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2061.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2062.png)

同理我们有序列 $a_1≤…≤a_{75},1≤a_i≤125$

$a_1+24≤…≤a_{75}+24,25≤a_j+24≤149$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2063.png)

关键是c和d

c) 刚好一人一坑，所以必须是 $a_1=1,a_2=2,…a_{25}=25$

d) 用刚刚的鸽巢法就不太行了，用新方法

我们可以发现 $a_1,…a_{31}$一定存在两个数同余(mod 30)，如果这两个数刚好相差30，那么我们就已经找到了答案；

如果没有相差30，那肯定相差30的倍数60、90、120；那么肯定有 $a_{31}≥61$，那么同样的方法，我们去序列 $a_{31}…a_{61}$去找，
这次就必须两个数相差30，不然相差60以上的话， $a_{61}≥121 , a_{66}≥126$ 矛盾；所以存在！

---

Sec.6.2（鸽巢）

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2064.png)

把每个整数写成2的幂与一个奇数的乘积

---

Sec.6.2

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2065.png)

设序列为 $a_1,a_2…a_m$

$d_k=\sum _{i=1}^k a_i$ 为前k项和，

从 $d_1...d_m$，如果有 $d_i \equiv 0 (\text{mod m})$

那么答案已出，如果没有，那么余数一定是 1 ~ m-1

那必有两个数的余数相同 $d_i \equiv d_j ,i<j$

那么这若干个连续整数和就是 $d_j-d_i$

---

Sec.6.2(最难鸽巢)

$设 x 是 无 理 数 。 证 明 : 对 于 某 个 不 超 过 n的 正 整 数 j ，\\ 在 jx 与 到 jx 最 近 的整 数 之 间 的 差 的 绝 对 值 小 于1/n 。$

$\{a\}$ 表示a的小数部分

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled.jpeg)

---

Sec.6.5

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2066.png)

设3个函数，对于n位比特串 

$f(n)表示没有01出现，\\g(n)表示01恰出现一次，\\h(n)表示01恰出现2次$

那么没有 01 出现的比特串一定是

$00...000 \\ 10…000 \\ 1100…000 \\ …\\ 1111…111$

$\therefore f(n)=n+1$

对于g(n),我们假定第k位出现了01，那么前k-1位没有01，后n-k-1位没有01

$g(n)\\=\sum _{k=1}^{n-1} f(k-1)f(n-k-1)\\=\sum _{k=1}^{n-1} k(n-k)\\=(n+1)n(n-1)/6=C(n+1,3)$

对于h(n),我们假定第k位出现了01，前面k-1位没有出现，后n-k-1为恰有一个01

$h(n)\\=\sum _{k=1}^{n-3} f(k-1)g(n-k-1)\\=\sum _{k=1}^{n-1} kC(n-k,3)\\=C(n+1,5)$

---

Sec.6.2

证明:在任何n+1个不超过2n的正整数中必存在2个数互素。

用鸽巢：

把2n个数分为n组,

$\{1,2\},\{3,4\}….\{2n-1,2n\}$

那么必有两个数在同一组，而相邻的两个数必定互素

# Chap 8
Advanced Counting Techniques

## Recurrence Relations（递推关系）

degree：递推需要的初始项个数

经典应用：

斐波那契数列： $F_N=F_{N-1}+F_{N-2}$

汉诺塔： $H_N=2H_{N-1}+1$

比特串： 

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2067.png)

编码字：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2068.png)

### 卡塔兰数

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2069.png)

## Solve Linear Recurrence Relations

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2070.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2071.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2072.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2073.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2074.png)

通解 $b_n=a_n^{(p)}+a_n^{(h)}$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2075.png)

注意要点：

1. F(n)的指数项和特征根是否重合，尤其关注 $1^n$
2. n重特征根就会有 $(n^0,n^1,…,n^t)$的幂函数项

步骤：

1. 找出齐次式下的特征根 $r_1…r_n$
2. 写出 $a_n^{(h)}$的形式
3. 写出 $a_n^{(p)}$的特解形式
4. 代入递推方程，找到各系数的方程
5. 再利用给定的初始值，再得到系数的方程解

## generating functions 
(生成函数)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2076.png)

### 有用的事实

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2077.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2078.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2079.png)

注意几个常用级数：

1. 二项式级数， $a_k=C(n,k)$
2. 二项式级数的倒数，

 $a_k=C(n+k-1,k)=C(n+k-1,n-1)$

### 应用！！！

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2080.png)

关键是如何找到 $a_{3r}$

明显只需要考虑分子的 1 和 $x^{2r+1}$项

于是我们把分母变换一下 成 级数形式

那么它的每 i 项 系数为 

$C(3+i-1,i)=C(i+2,i)$

最后就是考虑分母的 第 3r 项和 r-1 项

---

用于求解线性齐次递推关系

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2081.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%201.jpeg)

## Inclusive-exclusion
（容斥）

妙妙的证明

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2082.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2083.png)

### sieve of Eratosthenes
(埃拉托色尼筛)（寻找素数个数）

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2084.png)

### onto functions的个数

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2085.png)

### 错位排列

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2086.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2087.png)

组合证明：

1. 我们考虑第一个元素，它必不会是1，因此有 $n-1$种选择，假设占据 1th 位置的元素是 k
2. 对于kth位置 又有两种情况，若1在kth位置，那就是剩下的 $n-2$个的错排
3. 若1不在kth位置，那其实1就在扮演k的角色，参与了剩下 $n-1$个元素的错排

$D_n=(n-1)(D_{n-1}+D_{n-2})$

## 题集

8.6

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2088.png)

只考虑 质因子的平方 即可

$99-\lfloor{99/2^2}\rfloor-\lfloor{99/3^2}\rfloor-\lfloor{99/5^2}\rfloor-\lfloor{99/7^2}\rfloor+\lfloor{99/2^23^2}\rfloor=61$

8.4 生成函数，卡特朗数

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2089.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%202.jpeg)

最妙在于 $\frac{2·4·6···2n}{2^nn!}=1$

拓展：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2090.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%203.jpeg)

8.4 生成函数证明帕斯卡、范德蒙恒等式

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2091.png)

8.4 生成函数求平方和公式

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2092.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%204.jpeg)

8.5  使用数学归纳法证明容斥原理。

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%205.jpeg)

8.6 欧拉函数

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2093.png)

1. $\phi(pq)=pq-pq/p-pq/q+pq/pq=(p-1)(q-1)$
2. $\phi(n)=n-\sum_{i=1}^m\frac{n}{p_i}+\sum_{1≤i<j≤m}\frac{n}{p_ip_j}-···+/- \frac{n}{p_1p_2···p_m}\\=n\prod_{i=1}^m(1-\frac{1}{p_i})$

# Chap 9
Relations

## 关系的数量

一个从A到B的二元关系是 $A\times B$ 的子集

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2094.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2095.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2096.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2097.png)

尤其反对称，对角线上任意 所以 $2^n$;
然后对称位置有3种可能，然后考虑下三角，共有      

$\frac{(1+n-1)(n-1)}{2}=n(n-1)$项

## Property

symmetric(对称性)：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2098.png)

Antisymmetric（反对称性）：

$对于任意 a，b \in A，若(a，b)\in R且(b，a)\in R，一定有a=b，则称定义在集合A 上的关系R 为反对称的。$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2099.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20100.png)

就是说这个矩阵不能有对称相同的两个点，只有3种对角情况

reflexive（自反性）：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20101.png)

irreflexive(非自反性）：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20102.png)

transitive(传递性）：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20103.png)

## 关系的组合

主要注意: $R1\oplus R2=R1\cup R2 - R1\cap R2$

### 关系的合成

有点像嵌套函数

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20104.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20105.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20106.png)

所有的通过两条有向边的路径

$\circ$后的关系是 在内层，所以由它出发

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20107.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20108.png)

## Closures of Relations 
（关系的闭包）

闭包是，包含R，具有性质P，的最小关系

证明步骤：

1. 包含R
2. 具有什么性质
3. 最小关系，证明给定集合 $S \subset R'$ ， $R'$是具有这个关系的集合

### Reflexive Closure 自反闭包

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20109.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20110.png)

用 $r(R)=R\cup I_A$表示

### Symmetric Closure 对称闭包

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20111.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20112.png)

思路都是：考虑一对(a,b)在R和R’各自的情况，都能推导出要的结论

### Transitive Closure 传递闭包

定理：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20113.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20114.png)

---

连通性关系：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20115.png)

Prove: $t(R)=R^*$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20116.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20117.png)

Step3:

给定包含R的传递关系为S
关键 $S^n\subset S$

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20118.png)

如果warshall得到的传递关系和原关系相同就说明原关系传递

### Warshall’s Algorithm

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20119.png)

我们先考虑原先想要计算传递闭包，也就是要计算 $M_R,M_R^{[2]}…M_R^{[n]}$

那么 对于除 $M_R$以外的n-1个01矩阵的计算，

$M^{[2]}_{ij}= \lor_{k=1} (M_{ik} \land M_{kj})$ 此处有n次与、n-1次或

对于 $n \times n$的矩阵，每个矩阵的计算就是 $n^2(2n-1)$

所以 $T(n)=n^2(2n-1)(n-1)=O(n^4)$

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20120.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20121.png)

传递闭包本就是 从 $V_1 -V_n$ 的所有路径可能，

那么每层循环 Mt[i,j]保留（逻辑加）

然后通过 Mt[i,k]&Mt[k,j]实现一层又一层的 路过 $V_1…V_n$，完成所有路径可能

## Equivalence Relations 等价关系

同时满足自反，对称，传递的关系

### Equivalence Classes等价类

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20122.png)

---

定理：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20123.png)

关于证明：

1. 由(i)推(ii)，关键在于 证明 $有x \in [a]时，也有 x \in [b]$

---

**集合的划分**

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20124.png)

$pr(A)={A_i|i\in I}$

满足三个条件:

1. $A_i \neq \phi \text{ for } i \in I (I \text{ is an index set})$
2. $A_i \cap A_j = \phi$
3. $\forall a \in A, \exist i \text{ such that } a \in A_i (i=1,2,…)\\ 即 \cup _{i\in I}A_i=A$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20125.png)

证明：

1.证明 R的等价类 构成 Pr(A)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20126.png)

2.证明 给定划分，R是一个等价关系

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20127.png)

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20128.png)

划分就是 `Components`

---

求一个集合的等价关系数（等同于可别物件，不可别盒子）

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20129.png)

---

### The Operations of equivalence relations

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20130.png)

自反性，对称性，传递性都易证明

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20131.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20132.png)

所以我们能推出 $(R_1\cup R_2)^*$是等价关系

### mod 定理

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20133.png)

证明 modulo 是等价关系

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20134.png)

## Partial Ordering 偏序

自反的，反对称的，传递的

### 全序集（线序集）(chain)

totally ordered or linearly ordered set

如果偏序集 S 中 任意两个元素都可比，那么这个集合就叫全序集或线序集，一个全序集也叫链(chain)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20135.png)

### Lexicographic Order （字典序）

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20136.png)

在两个偏序集的笛卡尔积上的字典序是一个偏序集

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20137.png)

**Example**

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20138.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20139.png)

### Hasse Diagrams

自下而上，路径上的点都是顶点的等价类

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20140.png)

### chain and antichain

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20141.png)

这是对于集合A的子集的概念

如果子集B， $(B,\preccurlyeq)$是全序集，那B就是 $(A,\preccurlyeq)$的chain

如果子集B，B中任两个元素都不可比，那B就是 $(A,\preccurlyeq)$的antichain

### Maximal and Minimal Elements

概念辨析：

Maximal,Minimal（极大元，极小元）是极值，可以有多个，是top, bottom 元素

greatest element, least element （最大元，最小元）唯一

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20142.png)

---

**上下界**：对于S的子集A，

上界u, $\forall a \in A, a \preccurlyeq u$

下界l, $\forall a \in A, l \preccurlyeq a$

注意别忘了A里面自身的元素也可作上下界

最小上界(**lub**),最大下界(**glb**)

### Well-order Sets

---

良序集：

对于偏序集 $(S,\preccurlyeq)$， $\preccurlyeq$是全序的，且S的每个非空子集都有一个最小元素（least），就称它为良序集

### Lattices 格

如果一个偏序集的每对元素都有最小上界和最大下界，就称这个偏序集为格

﻿

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20143.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20144.png)

先确定上下界有哪些，再去思考这些上下界中是否能确定有lub和glb

### Topological Sorting

**相容(compatible):**

如果只要 $aRb$ 就有 $a \preccurlyeq b$ ，则称全序$\preccurlyeq$和偏序$R$是相容的

**Lemma 1**

每个有穷非空偏序集 $(S,\preccurlyeq)$至少有一个极小元(minimal)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20145.png)

**Algorithm 1**

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20146.png)

example

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20147.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20148.png)

# Chap 10
Graphs

## 10.1 Graph Models

### Undirected Graph

1. Simple Graph
没有一条边连接到相同的两个顶点，不含自环和多重边
2. Multigraph 多重图
两点间有多条边
3. Pseudograph 伪图
包含环或存在多重边的

三者是包含关系

### Directed Graph

1. simple directed graph 简单有向图
两点间最多一条有向边
2. directed multigraphs 有向多重图
有多重有向边
3. mixed graph 混合图
既有有向边又有无向边

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20149.png)

## 10.2 Terminology and Special Graphs

### Basic Terminology

Degree:度 deg(v)

**定理：**

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20150.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20151.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20152.png)

### Special Simple Graphs

1. Complete Graph - $K_n$ 完全图
不同顶点间都恰有一条边
    
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20153.png)
    
2. Cycles - $C_n$ 圈图
    
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20154.png)
    
3. Wheel - $W_n$ 轮图
    
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20155.png)
    
4. n-Cubes - $Q_n$ n-立方体图
    
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20156.png)
    

### Bipartite Graph （二分图）

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20157.png)

一个图可以拆成两部分的顶点 $V_1,V_2$，只存在从 V1到V2的边

**Complete Bipartite Graph** 完全二分图

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20158.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20159.png)

### regular graphs 正则图

如果简单图的每个顶点的度都相同，则称这个图是正则的，对于deg(v)=n，则称n-regular

### New Graphs from Old 构建子图

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20160.png)

点和边分别来自原来的子集，然后构成新的图

**Example**

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20161.png)

共有四种情况，即顶点数分别为1-4

一个顶点： $C(4,1)$

两个顶点： $C(4,2)*2$(有一条边或者没有)

三个顶点： $C(4,3)*2^3$(他们之间有三条边，那么显然2^3)

四个顶点： $C(4,4)*2^6$

## 10.3 Representing Graphs 图的表示

### adjacency lists 邻接表

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20162.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20163.png)

### adjacency matrices

对于简单图就是一个01矩阵，

对于多重图和伪图，就把1改成两点间边的数量

**结论：**

1. 对于无向图：
$i\text{th}$ row的和等于 Vertex $i$的 度数减去在 $i$处环的数量
$\sum_k^n a_{ik}=deg(V_i)-loop(V_i)$
而有向图：
仅是该点的 $deg^+(V_i)$

### Incidence matrices 关联矩阵

对于无向图，我们把边编号为 $e_1,e_2…e_m$，顶点还是 $V_1,V_2…V_n$，于是构成一个 $n\times m$的矩阵M

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20164.png)

每列两个1是边，每列一个1是环

## Graph Isomorphism 图的同构

通过一个双射函数，把一个顶点集V1映射到另一个顶点集V2，并且顶点的相邻情况仍不变，即重新给顶点编号

### invariants 图形不变量

我们想判断两个图是否同构，就要利用图形不变量来判断

1. 顶点数，边数
2. 对应顶点度数
3. 如果一个图是 bipartite/complete/wheel，那另一个也一定是

于是

我们可以先构建映射关系，然后在比对两个adjacency matrices(当然一般还是瞪眼法)

## 10.4 Connectivity 连通性

### path,circuit概念

给一个顶点序列 $x_0,x_1,x_2,…x_n$，相邻两点间是一条边，那么就是一个通路；如果始末点相同则是回路(circuit);
简单的：不重复包含相同的边

### path 路径

**定理：**
$V_i-V_j$**长为n的路径的，就等价于** $A^r的a_{ij}$

此处的 $A^r$是矩阵乘积，而非布尔积（关系里求传递闭包）

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20165.png)

计算通路数方法↑

### connectedness

无向图：连通就是任意两点间存在一条路径

有向图：

1. 强连通：在有向的情况下任意两点间存在路径
2. 弱连通：在无向的情况下任意两点间存在路径

## 10.5 Euler and Hamilton Paths

### Euler Terminology

欧拉回路：就是始末点相同的一笔画

欧拉通路：就是一笔画但始末不同

### 欧拉通路、回路 两个定理

1. 有两个点以上的联通多重图具有欧拉回路当且仅当每个顶点的度为偶数
    
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20166.png)
    
2. 有欧拉通路但无回路，当且仅当它恰有2个度为奇数的顶点

有向图中：

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20167.png)

### Hamilton Terminology

哈密顿通路：每个顶点恰经过一次

哈密顿回路：每个顶点恰经过一次，但最终又回 $x_0$的回路

### Properties

1. 带有度为1的图没有哈密顿回路，因为在哈密顿回路中每个顶点都关联着回路的两条边
2. 如果图中有度为2的点，它关联的两条边一定属于哈密顿回路

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20168.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20169.png)

### Hamilton 两个定理

**Dirac’s Theorem**

如果G是有n个顶点的简单图，其中 $n≥3$，并且G中每个顶点的度至少为 $n/2$，则G有哈密顿回路

**Ore’s Theorem**

如果G是有n个顶点的简单图， $n≥3$，并且对于G中每一对不相邻顶点 $u,v$，都有 deg(u)+deg(v)≥n,则G有哈密顿回路

## 10.6 Shortest Path

### Dijkstra’s Algorithm

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20170.png)

$T(N)=O(V^2+E)$

### Traveling Salesperson Problem

旅行商要访问n个城市且没每个城市恰好一次，并且返回出发点，并使得旅行总距离最短

等价于求完全图中总权值最小的哈密顿回路

---

方法一：

遍历所有可能得哈密顿回路，然后选择总权重最小的

首先对于 $K_n$，环的个数为 $(n-1)!$

其次哈密顿回路可以从反方向再遍历一次，所以实际上只有 $(n-1)!/2$个回路

（这个数字同前文组合里的环排列）

时间复杂度: $n!$

---

方法二：估计算法

用一个贪心的算法，每次从一个点出发都选择权重最小的边，可以得到一个接近最优解的结果

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20171.png)

## 10.7 Planar Graphs

定义：一个图中没有任何交叉的边，那这个图就是平面图

### K3,3是非平面图

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20172.png)

### Euler’s Formula

设G是带e条边和v个顶点的联通平面简单图，设r是G的平面图表示中的面数，则r=e-v+2

证明：数学归纳法

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20173.png)

注意：

1. 欧拉公式只是一个必要条件，平面图必须满足但满足的并非是平面图
2. 对于非联通的简单图
我们记c为连通组件数，
$r-(c-1)=e-v+2$

---

引入：
定义: 面的度数

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20174.png)

贴着边界 数

$2e=\sum deg(R_i)$

---

### 三条推论

推论1：

若G是e条边和v个顶点的连通平面简单图，其中v≥3,则e≤3v-6

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20175.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20176.png)

---

推论2：

若G是连通平面简单图，则G中有度数不超过5的顶点

证明：

1. 如果G只有1个或者2个顶点，这显然成立
2. 如果G有至少3个顶点，由推论1知 2e≤6v-12,同时2e=∑deg(vi),如果度数至少为6，那么2e≥6v矛盾

---

推论3：

若连通平面简单图有e条边和v个顶点，v≥3并且没有长度为3的回路，则e≤2v-4

这个本质上和推论1证明一样，只是说推论1中deg(R)至少为3，而现在排除了长度为3的回路，使得deg(R)至少为4

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20177.png)

---

在这些定理的加持下，我们就可以证明nonplanar了

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20178.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20179.png)

### Kuratowski’s Theorem 
库拉图斯基定理

初等细分(elementary subdivision)：

若一个图是平面图，通过删除一条边{u,v}并且添加一个新顶点w和两条边{u,w}和{w,v}得到的任何图也是平面图。（这个操作叫做初等细分）

同胚的(Homeomorphic):

如果可以从相同的图G经过一系列初等细分得到G1和G2，则他们是同胚的

---

一个图是nonplanar 当且仅当它包含一个同胚于 $K_{3,3}或K_5$的子图

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20180.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20181.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20182.png)

## 10.8 Graph Coloring

着色问题就是研究用最少的颜色数来染图，并使得相邻的面不是相同的颜色

引入：

1. 对偶图（dual graph)：就是把region视作顶点，相邻关系的面用edge连接，构成的图
2. 图的着色数（chromatic number）：就是着色这个图所需要的最少颜色数，图G的着色数记作 $\chi(G)$

---

### 四色定理

平面图的着色数不超过4

### 一些简单图的着色数

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20183.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20184.png)

### 着色的应用例子

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20185.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20186.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20187.png)

根据给的条件画出不重课图，然后找到它的补图，补图就是相邻的会重课；于是进行一个染色

# Chap 11 Trees

树是没有简单回路的连通无向图

## 11.1 Introduction to trees

### 术语

1. Parents vs. Children
2. Siblings
3. Ancestors vs. Descendants
4. Root,leaf,and internal vertex（内点就是有Child的点）
5. subtrees

---

### 数树的个数

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20188.png)

思路就是 按照Longest Path来分类讨论

路径长分别为：4,3,2,1的情况

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20189.png)

---

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20190.png)

### Tree Propertities

1. 带有n个顶点的树有n-1条边
2. 带有i个内点的满m叉树含有n=mi+1个顶点

---

一个满m叉树若有：

1. n个顶点，则有 $i=(n-1)/m$个内点； $l=[(m-1)n+1]/m,即l=n-i$个叶节点
2. $i$个内点,则有 $n=mi+1$个顶点和 $l=n-i=(m-1)i+1$个叶节点
3. $l$个叶节点，则有 $n=(ml-1)/(m-1)$个顶点和 $i=(l-1)/(m-1)$个内点

关键是第二个，三个之间彼此互推

### Balanced

level和height的概念：

level是指从root到某个顶点v所需要的路径长

height就是整棵树中最大的level（所以根节点是从level=0开始计算height）

---

Balanced: 指叶节点在 h or h-1 level

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20191.png)

---

**定理（性质）：**

m叉树中最多有 $m^h$个叶节点（也就是hlevel处全是叶节点）

**引理：**

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20192.png)

## 11.2 Applications of trees

### BST

详情见FDS

### Decision Trees

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20193.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20194.png)

### PrefixCode 前缀码

我们在为字母编码时一开始想着用5bit长，但为了缩减空间于是采用变长的bit来编码

而为了明显区别出每个字母的编码，就必须用某种方法来确定字母从何开始从何结束

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20195.png)

### 哈夫曼编码

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20196.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20197.png)

## 11.3 Tree Traversal

- Preorder：中、左、右
- Inorder：左、中、右
- Postorder：左、右、中

## 11.4 Spanning Trees

- Spanning Tree（生成树）的概念：
就是包含原图G所有顶点的一个子图，因而可以有多个生成树

**定理：**

一个简单图是连通的，当且仅当他有一个生成树

---

### DFS in Spanning Trees

1. 随意选一个顶点作为`root`
2. 访问一个相邻未访问过的节点
3. 重复进行直至无法再访问，则回溯

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20198.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20199.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20200.png)

### BFS in Spanning Trees

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20201.png)

DFS是对于相邻未访问的节点直接深入下去；BFS则是先访问一遍所有未访问的相邻节点，再一层层深入

## 11.5 Minimum Spanning Trees

- 最小生成树，是边权重之和最小的生成树

### Prim’s Algorithm

similar to Dijkstra

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20202.png)

从一个点开始，

去走

已知的

cost最小的

能到未知顶点的边

（此例中顺序为 $V_1-V_4,V_1-V_2,V_4-V_3,V_4-V_7,V_7-V_6,V_7-V_5$)

### Kruskal’s Algorithm

类并查集算法

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%20203.png)

从边入手，

建一个最小堆存放所有的边 

然后 依次delemin，也就是每次都去选择cost最小的边

对于每条边我们去 union/find 他们的顶点是否存在过（或者说顶点是不是在同一root下）