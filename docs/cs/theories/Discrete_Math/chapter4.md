# Chap 4
Number Theory and Cryptography

## 4.1 Divisibility and Modular Arithmetic

- 除法没什么好说，注意余数必须非负就行


!!! "定理"

    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2021.png)

## 4.3 质数与gcd

!!! note "Algorithm"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2022.png)

!!! note "贝祖定理（裴蜀定理）"
    ![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2023.png)

## 4.4 Solving Congruences 求解同余方程

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2024.png)

### 求逆

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2025.png)

- 两个互质的数求gcd，最后一定是1；然后求出对应的贝祖表达式，和a相乘的数就是 $\overline{a}$

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2026.png)

### 求解方程

- 两边同乘a的逆，然后就得到 $x\equiv m$的同余方程，就秒了

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2027.png)

### 中国剩余定理

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2028.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2029.png)

- 找到所有模数的乘积m，然后依次构造除了mi以外的乘积项Mi；然后找到每一项Mi的逆（模mi）；最后构造 $x=a_1M_1y_1+…+a_nM_ny_n$

### 费马小定理

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2030.png)

![Untitled](Discrete%20Mathematics%20707067c13df14f39b11935dff13def32/Untitled%2031.png)
