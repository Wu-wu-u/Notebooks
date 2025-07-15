# Advanced SQL

## 通过编程语言访问SQL

- 从高级语言（如 C）访问数据库，主要是下面两种方式：

    - **API**(Application Program Interface)：API 是一组函数或方法，允许程序与数据库服务器连接并进行通信。通过 API，程序可以执行 SQL 查询、插入、更新和删除操作，并处理结果集。

    ```cpp
    #include <mysql_driver.h>
    #include <mysql_connection.h>
    #include <cppconn/statement.h>
    #include <cppconn/resultset.h>

    int main() {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;
        sql::Statement* stmt;
        sql::ResultSet* res;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "user", "password");
        con->setSchema("testdb");

        stmt = con->createStatement();
        stmt->execute("CREATE TABLE IF NOT EXISTS test (id INT, label CHAR(1))");
        stmt->execute("INSERT INTO test(id, label) VALUES (1, 'a')");
        res = stmt->executeQuery("SELECT id, label FROM test");

        while (res->next()) {
            std::cout << "id = " << res->getInt("id");
            std::cout << ", label = '" << res->getString("label") << "'" << std::endl;
        }

        delete res;
        delete stmt;
        delete con;

        return 0;
    }
    ```

    - **Embedded SQL**：嵌入式 SQL 是将 SQL 语句直接嵌入到高级编程语言的代码中。编译器或预处理器会将这些嵌入的 SQL 语句转换为相应的 API 调用。嵌入式 SQL 使得 SQL 语句与程序代码紧密结合，便于编写和维护。

    - 在嵌入式 SQL 中，`DECLARE CURSOR` 语句用于声明一个游标（Cursor）。游标是一个数据库查询的抽象，允许逐行处理查询结果集。使用游标可以在程序中逐行遍历查询结果，并对每一行进行处理。

    ```cpp
    #include <stdio.h>
    #include <stdlib.h>
    #include <sqlca.h>

    /* Declare host variables */
    EXEC SQL BEGIN DECLARE SECTION;
    char username[20];
    char password[20];
    EXEC SQL END DECLARE SECTION;

    int main() {
        /* Connect to the database */
        EXEC SQL CONNECT TO 'testdb' USER :username IDENTIFIED BY :password;

        /* Execute a SQL statement */
        EXEC SQL DECLARE cursor_name CURSOR FOR
            SELECT id, label FROM test;

        EXEC SQL OPEN cursor_name;

        /* Fetch and display the results */
        int id;
        char label[2];
        EXEC SQL FETCH cursor_name INTO :id, :label;
        while (sqlca.sqlcode == 0) {
            printf("id = %d, label = %s\n", id, label);
            EXEC SQL FETCH cursor_name INTO :id, :label;
        }

        /* Close the cursor and disconnect */
        EXEC SQL CLOSE cursor_name;
        EXEC SQL COMMIT WORK RELEASE;

        return 0;
    }
    ```

## Procedural Constructs

- 存储过程（**Stored Procedure**）是一组预编译的 SQL 语句，存储在数据库服务器上，可以通过调用来执行。存储过程可以接受参数、执行复杂的逻辑操作，并返回结果。它们在数据库管理系统（DBMS）中广泛使用，以提高性能、简化应用程序开发和增强安全性。

- 其实就是function/procedure

### SQL Function

!!! tip "Example--function"
    ```sql
    create function dept_count(dept_name varchar(20))
    returns integer
    begin
        declare d_count integer;
        select count(*) into d_count
        from instructor
        where instructor.dept_name = dept_name
        return d_count;
    end
    ```

### SQL Procedure

### 存储过程的特点

1. **预编译**：存储过程在创建时被预编译，这意味着它们在执行时比动态 SQL 查询更快，因为编译步骤已经完成。
2. **参数化**：存储过程可以接受输入参数、输出参数或输入输出参数，使其更加灵活和可重用。
3. **逻辑封装**：存储过程可以包含复杂的业务逻辑，包括条件语句、循环、异常处理等。
4. **安全性**：通过使用存储过程，可以限制直接访问数据库表的权限，从而增强安全性。
5. **可维护性**：将业务逻辑封装在存储过程中，可以简化应用程序代码的维护和更新。

### 存储过程的语法

- 相较function来说，有输入参数(**in**)和输出参数(**out**)

#### 创建存储过程

- 假设我们有一个名为 `employees` 的表，结构如下：

```sql
CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    salary DECIMAL(10, 2),
    department_id INT
);
```

- 我们可以创建一个存储过程来计算特定部门的平均工资：

```sql
DELIMITER //

CREATE PROCEDURE get_avg_salary_by_department(IN dept_id INT, OUT avg_salary DECIMAL(10, 2))
BEGIN
    SELECT AVG(salary)
    INTO avg_salary
    FROM employees
    WHERE department_id = dept_id;
END //

DELIMITER ;
```


## Trigger

- 触发器(**trigger**)是一种数据库对象，它在特定的数据库事件（如插入、更新或删除）发生时自动执行预定义的操作。触发器通常用于维护数据完整性、自动生成日志或执行复杂的业务逻辑。

- 触发器的组成部分

    1. 事件(**Event**)：触发器响应的数据库操作，如 INSERT、UPDATE 或 DELETE。

    2. 条件(**Condition**)：触发器在特定条件下执行，可以是简单的条件检查或复杂的逻辑。

    3. 动作(**Action**)：触发器在事件发生且条件满足时执行的操作。

---

- 但是现代开发中，不鼓励使用trigger
