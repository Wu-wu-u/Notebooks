## Commands

- `file <filename>`：加载可执行文件。
- `r` 或 `run [args]`：运行程序。`[args]` 是可选的命令行参数。
- `b` 或 `break <line>`：在指定行设置断点。
- `b` 或 `break <function>`：在指定函数设置断点。
- `b` 或 `break *<address>`：在指定地址设置断点。
- `info breakpoints`：查看断点信息。
- `delete breakpoints <number>`：删除指定编号的断点。
- `continue`：继续执行程序。
- `next`：执行下一行。
- `step`：执行下一行，如果遇到函数调用，进入函数内部。
- `print <variable>`：打印变量的值。
- `print <expression>`：打印表达式的值。
- `watch <expression>`：监视表达式的值，当值发生变化时，程序会停下来。
- `backtrace`：查看函数调用栈。
- `finish`：执行完当前函数后停下来。
- `q` 或 `quit`：退出 `gdb`。
- `help`：查看帮助信息。

!!! tip
    - shell :调用终端命令
    - set logging on :日志功能 会生成gdb.txt
    - watchpoint : 观察变量是否变化
        
        ```bash
        watch &i
        ```
        
    - ulimit 修改 core
        
        ```bash
        $ gdb ./a.out core.~
        ```

```bash title="调试进行中的程序"
./a.out & //后台执行
1234
gdb -p 1234
```