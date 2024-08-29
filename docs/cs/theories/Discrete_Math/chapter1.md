# Chap 1 
Logic and Proofs

## Logical Equivalences

| Equivalences | Name |
| --- | --- |
| $p \land T\equiv p$
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

=== "n-Queens"

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
  
=== "Sudoku"

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
| $\lnot \exists xP(x)$ | $\forall x \lnot P(x)$ |
| $\lnot \forall xP(x)$ | $\exists x \lnot P(x)$ |

!!! warning "Attention"
    - to tell the difference 

    - All CS students are smart students
        - $\forall x (C(x)→S(x))$
    - Some CS students are smart students
        - $\exists x(C(x)\land S(x))$

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled.png)

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%201.png)

### Nested Quantifiers

- From these observations, it follows that if $∃y∀xP(x, y)$ is true, then $∀x∃yP(x, y)$ must also
be true. However, if $∀x∃yP(x,y)$ is true, it is not necessary for $∃y∀xP(x,y)$ to be true

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%202.png)

## Norm formals

### DNF

- Full Disjunctive Normal forms = Sum of minterms
- minterm: conjunctions of each single variable
- every variable is presented exactly once in a minterm

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%203.png)

### CNF

- product of maxterms

- application:
    1.determine equivalence
    2.determine tautology ,contradiction or contingency

### prenex normal form :

- $Q_1x_1Q_2x_2···Q_nx_nB$ , where $Q_i(i=1,···n)$ is quantifiers $\forall$ or $\exists$ and the predicate $B$ is quantifier free

!!! note "how to transform into prenex normal form"

    1. eliminate  $→$ and $\leftrightarrow$
    2. rename the variables

## Rules of Inference

1. Modus ponens

$$
p \\  
p→q \\  
\therefore q
$$

2. Modus tollens

$$
\lnot q \\
p→q \\
\therefore \lnot p
$$

3. Hypothetical Syllogism

$$
p\rightarrow q \\
q→r \\
\therefore p \rightarrow r
$$

4. Disjunctive Syllogism

$$p \lor q \\
\lnot p \\
\therefore q
$$

5. Addition

$$p \\
\therefore p \lor q
$$

6. Simplifcation

$$p\land q \\
\therefore p
$$

7. Conjunction

$$p \\
q \\
\therefore p\land q
$$

8. Resolution

$$
p\lor q \\
\lnot p \land r \\
\therefore q\lor r
$$
