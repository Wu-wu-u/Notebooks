# Introduction

## Purpose of Database Systems

!!! info "数据库系统用来解决这些问题"
    - data redundancy (数据冗余) and inconsistency

    - data isolation (数据孤立，数据孤岛)

    - difficulty in accessing data

    - Integrity problems (完整性问题)

        - 完整的约束条件被藏在数据和代码中，而不是显式地声明。 e.g. "account balance≥1"

    - Atomicity problems (原子性问题)

        - Failures may leave database in an inconsistent state with partial updates carried out e.g. 从 A 账户转账到 B, 我们必须保证 A 转出 B 转入这两件事同时进行，不能被打断。

    - Concurrent access anomalies (并发访问异常)

        - Uncontrolled concurrent accesses can lead to inconsistencies

    - Security problems

        - Authentication (认证), Priviledge (权限), Audit (审计)

## 数据视图

### 数据模型

- 数据库结构的基础是数据模型(data model)，描述了**data, data relationships, data semantics, data constrains**，可划分为四类：

    - **关系模型**(relational model)：经典的二维表

    - **实体-联系模型**(entity-relationship model)：E-R模型用于数据库设计
    
        ??? tip "E-R图示例"
            ```
            +----------------+          +----------------+
            |    Student     |          |     Course     |
            |----------------|          |----------------|
            | StudentID      |          | CourseID       |
            | Name           |          | CourseName     |
            | Age            |          | Credits        |
            +----------------+          +----------------+
                    |                          |
                    |                          |
                    +----------Enrolls---------+
            ```

    - 半结构化数据模型(semi-structured data model)

    - 基于对象的数据模型(object-based data model)


### 数据抽象

- 物理层(physical level)：最低层次的抽象，描述数据实际上是**如何存储**的

- 逻辑层(logical level)：描述数据库存储什么数据以及数据间的联系

- 视图层(view level)：最高层次的抽象，只描述整个数据库的某个部分。很多用户并不需要所有的信息，只需要访问数据库的一部分，视图层的存在让用户与系统的交互更简单。

## 数据库语言

- 数据库系统提供数据定义语言(data-definition language, **DDL**)来定义数据库模式，同时提供数据操纵语言(data-manipulation language, **DML**)来表达数据库的查询和更新。这两个并不是互相分离的语言，是单一SQL语言的不同部分

### DDL

- DDL语言提供了指明一些约束的工具

    - 域约束(domain constraint)：

    - 引用完整性(referential integrity)

    - 授权(authorization)


### DML

- 基本上有两种类型的DML：

    - 过程化的DML(procedural)：要求用户制定需要什么数据以及**如何**获得

    - 声明式的DML(declarative/non-procedural)：只要求用户制定需要什么数据，**不需要**指明如何获得

### SQL

- SQL查询语言是**non-procedural**