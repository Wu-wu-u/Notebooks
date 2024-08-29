# Chap 5
Digital Hardware Implementation

## Programmable Logic Device

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20192.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20193.png)

!!! abstract 
    - ROM：或项可动，与项不可

    - PAL：与项上可动，或项个数不行

    - PLA：与或项都可动

---

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20194.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20195.png)

---

### ROM

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20196.png)

- 或项连接个数可变 但最大数量一定

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20197.png)

- 每个 $D_i$其实就代表 $A_1,A_2,A_3$的不同最小项，F就是最小项之和（所以说与项固定，或项可变）

### PAL

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20198.png)

- 与项可变，但最终的或项个数不能变

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20199.png)

- 不止可以是input变量，还可以是先前产生的函数

??? tip "用例"

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20200.png)

    ![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20201.png)

    - Fan-in 限定为3则F1超，

    - 但可以将其中两项合为W再作为Fan-in

    - 也就是说PAL并非能表达所有逻辑，因为Fan-in有限，但是我们可以把其他函数的结果作为逻辑信号，间接实现更复杂的逻辑

### PLA

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20202.png)

- 可以看作前面是PAL后面是ROM

- 区别在于 PLA 并不使用译码器获得所有最小项，而是用可编程的 AND 阵列来代替译码器。

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20203.png)

- 原来要5个与门（AB+BC+AC+~AB+A~B），现在通过异或巧妙地只需要4个与门(AB+BC+AC+~A~B)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20204.png)

- 巧用K-map找到一些共同项

- 看是（1,1）的重合程度高，还是（1,0）的重合程度高

### Lookup Tables（非考试要求）

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20205.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20206.png)

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20207.png)

## FPGA

![Untitled](Logic%20and%20computer%20design%20fundamentals%20126e5290981e4d10ad7dab4e845bdd25/Untitled%20208.png)
