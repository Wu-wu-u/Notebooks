!!! Tip "Reference"
    [Tutorial](https://www.gnu.org/software/make/) 

## Rules

!!! note "important"
    ```makefile
    target : prerequisites
    [tab]	command
    ```

- 可以使用通配符 `* ? ~`  和 变量 `$( … )`
- 文件搜寻
    
    大型工程中源文件会分类存放在不同目录，为文件添加路径让make自动去找
    
    - 特殊变量 `VPATH`
    
    ```makefile
    e.g.
    VPATH = src:../headers
    ```
    
    - 关键字 `vpath`
    (注意，它是全小写的），这不是变量，这是一个make的关键字，这和上面提到的那个VPATH变量很类似，但是它更为灵活。它可以指定不同的文件在不同的搜索目录中。这是一个很灵活的功能。它的使用方法有三种：
        
        **`path <pattern> <directories>`**
        
        为符合模式<pattern>的文件指定搜索目录<directories>。
        
        **`vpath <pattern>`**
        
        清除符合模式<pattern>的文件的搜索目录。
        
        **`vpath`**
        
        清除所有已被设置好了的文件搜索目录。
        
        vpath使用方法中的`<pattern>`需要包含 `%` 字符。 
        `%` 的意思是匹配零或若干字符，（需引用 `%` ，使用 `\` ）
        例如， `%.h` 表示所有以 `.h` 结尾的文件。
        <pattern>指定了要搜索的文件集，而<directories>则指定了< pattern>的文件集的搜索的目录。
        例如：
        
        ```makefile
        vpath %.h ../headers
        ```
        
- 伪目标
    
    “伪目标”并不是一个文件，只是一个标签，由于“伪目标”不是文件，所以make无法生成它的依赖关系和决定它是否要执行。我们只有通过显式地指明这个“目标”才能让其生效。当然，“伪目标”的取名不能和文件名重名，不然其就失去了“伪目标”的意义了。
    
    为了避免和文件重名的这种情况，我们可以使用一个特殊的标记“.PHONY”来显式地指明一个目标是“伪目标”，向make说明，不管是否有这个文件，这个目标就是“伪目标”。
    
    ```makefile
    .PHONY : clean
    clean : 
    		rm *.o temp
    ```
    
    目标也可以成为依赖。所以，伪目标同样也可成为依赖。看下面的例子：
    
    ```makefile
    .PHONY : clean_all clean_obj clean_diff
    clean_all : clean_obj clean_diff
    		rm program
    clean_obj : 
    		rm *.o
    clean_diff : 
    		rm *.diff
    ```