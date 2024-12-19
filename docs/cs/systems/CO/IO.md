# I/O

## Performance Measurement

- bandwidth, 单位时间内支持多少次IO操作

## Disk Storage

$MTTF$(mean time to failure):平均无故障时间

$MTTR$(mean time to repair):平均修复时间

availability: $Availability = \frac{MTTF}{MTTF+MTTR}$



### Redundant Array of Independent Disks

- RAID（Redundant Array of Independent Disks，独立磁盘冗余阵列）是一种将多个物理磁盘组合成一个逻辑单元，以提高数据存储性能和/或提供数据冗余的技术。RAID 通过将数据分布在多个磁盘上来实现这些目标，从而提高了数据的可靠性和读取/写入速度

---

1. RAID 0 (条带化)

    特点：将数据分块并分布到多个磁盘上，提供高性能，但没有冗余。

    优点：读写速度快。

    缺点：任何一个磁盘故障都会导致数据丢失。

2. RAID 1 (镜像)

    特点：将数据完全复制到两个或多个磁盘上，提供高冗余。
    
    优点：数据可靠性高，任何一个磁盘故障不会导致数据丢失。

    缺点：存储效率低（需要两倍的存储空间）。

3. RAID 3 (字节级奇偶校验)

    特点：RAID 3 是一种使用字节级条带化和专用奇偶校验磁盘的 RAID 级别。它将数据按字节分割，并将每个字节分布到多个磁盘上，同时使用一个专用的磁盘来存储奇偶校验信息。

    缺点：small write时，都需要修改parity盘，throughput较差

4. RAID 5 (分布式奇偶校验)

    特点：RAID 5 是一种使用块级条带化和分布式奇偶校验的 RAID 级别。它将数据和奇偶校验信息分布在所有磁盘上，而不是使用一个专用的奇偶校验磁盘。

## Bus

同步：时钟信号

异步：handshake protocal

bus在连续传递block的时候，可以在transfer word时就read in，就可以省略后面的一些read in时间

## 处理device的两种方式

- memory-mapped I/O：在memory中规定好哪一块是属于哪个IO设备的，就可以用load和store指令

- special I/O instructions（RISC-V无）：x86里的`in`和`out`

- 外设里也有相应的寄存器，status registre, data register, command register

## Communication with processor

- polling（轮询）：是一种与外设进行通信的方式，处理器通过不断检查外设的状态寄存器来确定外设是否需要服务。会waste很多processor time

- Interrupt：CPU能一边干其他事，一边响应IO的中断

- DMA：完全不经过CPU，就可以对memory进行读写

---

