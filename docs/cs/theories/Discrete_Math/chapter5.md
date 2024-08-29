# Chap 5
Induction and Recursion

## Mathematical Induction

数学归纳法

- **假设P(k)成立 推断P(k+1)成立**

??? note "Examples"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2032.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2033.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2034.png)

## Strong Induction

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2035.png)

??? note "Example"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2036.png)

### well-ordering property

- 良序性质（Well-Ordering Property）
- 定义是：对于任何非空的自然数集合，总存在一个最小元素。

??? note "Examples"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2037.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2038.png)

    ---

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2039.png)

    - 首先，我们假设在一个循环赛中存在一个长度为m的循环，其中m >= 3。我们将这个循环的玩家记为p1, p2, ..., pm，满足p1击败p2，p2击败p3，...，pm-1击败pm，pm击败p1。
        
    - 我们考虑所有这样的循环的长度集合S = {m | m >= 3}。由于我们假设存在一个长度为m的循环，所以S是非空的。由于S是非空的自然数集合，根据良序性质，S中必然存在一个最小元素，我们将其记为n。
        
    -  如果n = 3，那么我们已经找到了一个长度为3的循环，证明结束。
        
    - 如果n > 3，我们考虑一个长度为n的循环，玩家为p1, p2, ..., pn。在p1,p2,p3中，p1和p3存在两种情况：p1打败p3或者p3打败p1，都将会构成一个长度为3的circle。这与我们假设n是S的最小元素矛盾。
        
    - 所以，我们证明了如果在一个循环赛中存在一个长度为m的循环，那么必然存在一个长度为3的循环。
    

## Recursive Definition

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2040.png)

- 先给定前k个值，再给出递推关系

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2041.png)

### 欧几里得算法

- $gcd(a,b)=gcd(b,r)$

- 每进行一次gcd，就会让较大的数至少减小一半,

??? note "LAME’S Theorem"
    
    

## Structural Induction

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2042.png)

!!! Abstract

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2043.png)

## 题集

=== "Sec.5.1"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2044.png)

    重言式(tautology)

    这个证明关键在于，不仅assume P(K)成立，还要assume Hypothesis成立

    所以证明P(K+1)时，

    有 $p_k→p_{k+1}以及[(p_1\land … \land p_{k-1})→p_k]$

    $\therefore (p_1 \land …\land p_{k-1})→p_{k+1}$

    $\therefore (p_1 \land …\land p_{k-1}\land p_k)→p_{k+1}$是个weaker推理，更是正确



=== "Sec.5.2"

    (well-ordering的应用）

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2045.png)

    关于唯一性的证明：
    我们假设 $a=dq+r=dq’+r’$

    都有 $0<r≤d,0<r’≤d$

    那么 $d(q-q’)=r-r’$

    说明 r-r’是d的整数倍

    又因为 $-d<r-r’<d$ 所以 $r-r’=0$

    $q=q’$



=== "Sec.5.2"
    （利用数学归纳法证明良序性）

    我们先假设 Well-Ordering 不正确，也就是非空自然数集合无最小元素。
    给定一个非空自然数集合S,
    Statement P(n)代表了 $i\notin S, \text{for }i=1,2,3…n$

    那么为了保证Well-Ordering为false，那么P(0)为true；假设P(n)为true，P(n+1)也必须为true，不然 n+1这个元素就是S里的最小元素；于是最后我们递推得到S是个空集φ，矛盾！



=== "Sec.5.2"

    良序性可以用来证明:两个正整数有唯一的最大公因子。设a和b 都是正整数，设S是形如as+bt的正整数的集合，其中s和t都是正整数。

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2046.png)

    a) 任选s=t=1，那么a+b就是一个元素，所以S非空

    b) 根据良序性，S为非空自然数集合，那么有最小元c

    c) $a\equiv b \equiv c \equiv 0 (\text{mod d})$

    d) 先假设c不整除a，那么就会有余数r, $0<r<c$
    $r=(1-qs)a+(-qt)b, r\in S$ 矛盾

    e) 根据c)我们知道ab的公因子一定是c的因子，那么这个公因子 d≤c;同时，c又可以整除a与b，说明c是ab的公因子；综上ab的最大公因子就是c且唯一


