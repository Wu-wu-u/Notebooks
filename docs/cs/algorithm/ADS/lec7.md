# lec7|Divide & Conquer

!!! abstract "ADS中的重点"
    - 本节的重点实际上并不是聚焦于分治本身，而是其**复杂度分析**


---

## Closet Points Problem

pdf 16-19


## 复杂度分析

$$
T(N)=aT(\frac{N}{b})+f(N)~~a,b \in Z^+
$$

- 分治的时间复杂度往往满足这样的公式；我们的任务就是求解形如这样的递推公式

---

### 代换法

- **代换法**(substitution method)的思路非常直白，首先我们通过“某些手段”来得到一个预设的结果，接下来通过代入、**归纳**的方法来证明这个结果。

补pdf

### 递归树法

- **递归树法**(recursion-tree method)的思路是，我们通过**画出递归树**来分析算法的时间复杂度，实际上和直接数学推理的区别不是很大，主要就是通过观察递归过程中数据增长的模式来进行分析。

??? tip "数学上的工具"
    
    $$
    a^{log_bN} = exp^{\frac{lnN}{lnb}lna}=exp^{\frac{lna}{lnb}lnN}=N^{log_ba}
    $$

- 123

### 主方法

- 公式法！

- 还是用递归树来理解主方法最好；对于这个公式$T(n)=aT(\frac{n}{b})+f(n)$，可以画出这样的树

补图

---

!!! tip "master theorem"
    
    - 补主定理 p52

    - 证明就不补了，很复杂

    !!! warning "不能应用的情况"
        - pdf45页








