# ODBC的使用

!!! info

    - [MySQL官方文档](https://dev.mysql.com/doc/connector-odbc/en/connector-odbc-installation.html)

    - 常用的ODBC Driver有iODBC和unixODBC

    - 鉴于MacOS上的MySQL Connector/ODBC 只支持iODBC，下面就以iODBC为例进行配置

## 安装与配置iODBC

- [iODBC官方安装](https://www.iodbc.org/dataspace/doc/iodbc/wiki/iodbcWiki/Downloads)

- 安装成功后，会在`/usr/local/iODBC`生成`odbc.ini`和`odbcinst.ini`文件，同时也有一个*iodbc administrator*应用程序，可以用来管理DSN

- 然后去MySQL官网安装*MySQL-connector-odbc*，会自动对`odbc.ini`和`odbcinst.ini`进行配置（就算没有也没关系，可以手动进行配置）

```ini
[ODBC Data Sources]
MySQLa = MySQL ODBC 9.2 ANSI Driver
MySQL  = MySQL ODBC 9.2 Unicode Driver

[ODBC]
Trace         = 0
TraceAutoStop = 0
TraceFile     = 
TraceLibrary  = 

[MySQLa]
Driver     = MySQL ODBC 9.2 ANSI Driver
NO_CATALOG = 0
NO_SCHEMA  = 1
SERVER     = localhost

[MySQL]
Driver     = /usr/local/mysql-connector-odbc-9.2.0-macos15-arm64/lib/libmyodbc9w.so
NO_CATALOG = 0
NO_SCHEMA  = 1
Server     = localhost
Username   = username
Password   = password
Database   = database
```

---

## C/C++程序的编译与链接

```cpp
#include <iostream>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sqlucode.h>
#include <string>

using namespace std;

void ODBCexample() {
    SQLRETURN ret;
    SQLHENV env;
    SQLHDBC conn;
    SQLHSTMT stmt;

    // Allocate environment handle
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        cerr << "Error allocating environment handle" << endl;
        return;
    }

    // Set the ODBC version environment attribute
    ret = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        cerr << "Error setting ODBC version" << endl;
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return;
    }

    // Allocate connection handle
    ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &conn);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        cerr << "Error allocating connection handle" << endl;
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return;
    }

    // Connect to the DSN
    ret = SQLConnect(conn, (SQLCHAR*)"MySQL", SQL_NTS, (SQLCHAR*)"username", SQL_NTS, (SQLCHAR*)"password", SQL_NTS);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        cerr << "Error connecting to the database" << endl;
        SQLFreeHandle(SQL_HANDLE_DBC, conn);
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return;
    }

    // Allocate statement handle
    ret = SQLAllocHandle(SQL_HANDLE_STMT, conn, &stmt);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        cerr << "Error allocating statement handle" << endl;
        SQLDisconnect(conn);
        SQLFreeHandle(SQL_HANDLE_DBC, conn);
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return;
    }

    // Execute a query
    ret = SQLExecDirect(stmt, (SQLCHAR*)"SELECT * FROM employee", SQL_NTS);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        cerr << "Error executing query" << endl;
        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        SQLDisconnect(conn);
        SQLFreeHandle(SQL_HANDLE_DBC, conn);
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return;
    }

    // Bind columns and fetch data
    SQLINTEGER id;
    SQLCHAR name[50];
    SQLCHAR street[50];
    SQLCHAR city[50];

    ret = SQLBindCol(stmt, 1, SQL_C_SLONG, &id, 0, NULL);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        cerr << "Error binding column 1" << endl;
        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        SQLDisconnect(conn);
        SQLFreeHandle(SQL_HANDLE_DBC, conn);
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return;
    }
    ret = SQLBindCol(stmt, 2, SQL_C_CHAR, name, sizeof(name), NULL);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        cerr << "Error binding column 2" << endl;
        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        SQLDisconnect(conn);
        SQLFreeHandle(SQL_HANDLE_DBC, conn);
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return;
    }
    ret = SQLBindCol(stmt, 3, SQL_C_CHAR, street, sizeof(street), NULL);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        cerr << "Error binding column 3" << endl;
        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        SQLDisconnect(conn);
        SQLFreeHandle(SQL_HANDLE_DBC, conn);
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return;
    }
    ret = SQLBindCol(stmt, 4, SQL_C_CHAR, city, sizeof(city), NULL);
    if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
        cerr << "Error binding column 4" << endl;
        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        SQLDisconnect(conn);
        SQLFreeHandle(SQL_HANDLE_DBC, conn);
        SQLFreeHandle(SQL_HANDLE_ENV, env);
        return;
    }

    while (SQLFetch(stmt) != SQL_NO_DATA) {
        cout << "ID: " << id << ", Name: " << name << ", Street: " << street << ", City: " << city << endl;
    }

    // Free handles
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
    SQLDisconnect(conn);
    SQLFreeHandle(SQL_HANDLE_DBC, conn);
    SQLFreeHandle(SQL_HANDLE_ENV, env);
}

int main() {
    ODBCexample();
    return 0;
}
```

- 这个c程序，由于用到了外部的头文件和库文件，所以我们必须为编译器指明头文件和库文件的目录；否则编译器只会在当前目录和系统目录中查找

### 命令

- 我们可以在编译时添加额外的参数信息来指明：

```bash
$> g++ main -o main -L/usr/local/iODBC/lib -I/usr/local/iODBC/include -liodbc
```

- `-L/usr/local/iODBC/lib`：指定库文件目录。

- `-I/usr/local/iODBC/include`：指定头文件目录。

- `-liodbc`：告诉链接器链接 iodbc 库。

- `-l` 选项告诉链接器链接一个特定的库。例如，`-liodbc` 告诉链接器链接名为 `iodbc` 的库。链接器会在指定的库目录（通过 -L 选项指定）中搜索名为 `libiodbc.so`（Linux）或 `libiodbc.dylib`（macOS）的文件。

- 这里使用的是**动态链接**

### CMake

- 也可以用CMake来辅助我们通过配置文件（CMakeLists.txt）定义项目的构建规则，包括源文件、头文件、库文件、编译选项等。这样可以避免手动编写复杂的构建脚本，简化构建过程。

```bash title="CMakeLists.txt"
cmake_minimum_required(VERSION 3.20)
project(mysqlTest)

set(CMAKE_CXX_STANDARD 17)

# 设置别名
set(IODBC_LIB /usr/local/iODBC/lib)
set(IODBC_HEADER /usr/local/iODBC/include)

# 添加IODBC连接头文件
include_directories(${IODBC_HEADER})
# 添加IODBC外部库
link_directories(${IODBC_LIB})

# 添加源文件
add_executable(main main.cpp)

# 添加MySQL链接库
target_link_libraries(main iodbc)
```

```bash
$> cmake .
$> make
```