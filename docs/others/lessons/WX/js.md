# JavaScript

## 使用方法

- 在 HTML 中，JavaScript 代码必须位于 `<script>` 与 `</script>` 标签之间。  

    ```js title="实例"
    <script>
    document.getElementById("demo").innerHTML = "我的第一段 JavaScript";
    </script>
    ```

- 外部脚本  

    - `<script src="myScript.js"></script>`

## 输出

- JavaScript 能够以不同方式“显示”数据：

    - 使用 window.alert() 写入警告框  
    - 使用 document.write() 写入 HTML 输出  
    - 使用 innerHTML 写入 HTML 元素  
    - 使用 console.log() 写入浏览器控制台  

=== "InnerHTML"
    
    - 如需访问 HTML 元素，JavaScript 可使用 `document.getElementById(id)` 方法。
    
    - `id` 属性定义 HTML 元素。innerHTML 属性定义 HTML 内容：

    - 更改 HTML 元素的 `innerHTML` 属性是在 HTML 中**显示数据的常用方法**。

    ```js
    <!DOCTYPE html>
    <html>
    <body>

    <h1>我的第一张网页</h1>

    <p>我的第一个段落</p>

    <p id="demo"></p>

    <script>
        document.getElementById("demo").innerHTML = 5 + 6;
    </script>

    </body>
    </html> 

    ```


=== "document.write()"
    - 在 HTML 文档完全加载后使用 `document.write()` 将删除所有已有的 HTML ：

    ```js
    <!DOCTYPE html>
    <html>
    <body>

    <h1>我的第一张网页</h1>

    <p>我的第一个段落</p>

    <script>
    document.write(5 + 6);
    </script>

    </body>
    </html> 

    ```

=== "window.alert() & console.log()"
    - 前者使用警告框来显示数据

    - 后者在浏览器中开发者工具的`console`来显示数据。


------







## 数据类型

- JavaScript 变量能够保存多种数据类型：数值、字符串值、数组、对象等

!!! tip "当数值和字符串相加时，JavaScript 将把数值视作字符串"

    ```js
    var x = 911 + 7 + "Porsche";
    >>> 918Porsche
    var x = "Porsche" + 911 + 7
    >>> Porsche9117
    ```

    - 在第一个例子中，JavaScript 把 911 和 7 视作数值，直到遇见 "Porsche"。

    - 在第二个例子中，由于第一个操作数是字符串，因此所有操作数都被视为字符串。



!!! note "对象"
    - JavaScript 对象用花括号来书写。

    - 对象属性是 name:value 对，由逗号分隔。

    ```js
    var person = {firstName:"Bill", lastName:"Gates", age:62, eyeColor:"blue"};
    ```

## 字符串

- 可以使用单或双引号

- 可以使用转义字符来插入特殊字符:`\b`,`\f`,`\n`,`\r`,`\t`,`\v`,`\\`,`\'`,`\"`


!!! tip "字符串可以是**对象**"
    - 通常，JavaScript 字符串是原始值，通过字面方式创建：

    ```js
    var firstName = "Bill"
    ```

    - 但是字符串也可通过关键词 new 定义为对象：

    ```js
    var firstName = new String("Bill")
    ```

    !!! warning "请不要把字符串创建为对象"
    
        - 它会拖慢执行速度。

        - `new` 关键字使代码复杂化。也可能产生一些**意想不到的结果**：

        - 当使用 `==` 相等运算符时，相等字符串是相等的

        - 当使用 `===` 运算符时，相等字符串是不相等的，因为 `===` 运算符需要**类型和值**同时相等。

        ```js
        var x = "Bill";
        var y = new String("Bill");

        // (x==y)为 true
        // (x===y)为 false，前者为字符串，后者为对象
        ```

        - 甚至更糟。对象无法比较：
        
        ```js
        var x = new String("Bill");             
        var y = new String("Bill");

        // (x == y) 为 false，因为 x 和 y 是不同的对象
        // (x === y) 为 false，因为 x 和 y 是不同的对象
        ```

        - JavaScript中**对象无法进行对比**，比较两个将始终返回 `false`。


----

### 字符串方法

!!! warning "Immutable"
    
    - 所有字符串方法都会返回新字符串。它们不会修改原始字符串。

    - 正式地说：字符串是**不可变的**：字符串**不能更改**，只能替换。




- `lengeth`：返回字符串长度

- `indexOf(query)`,`lastIndexOf`：返回给定的query在字符串中**首次(最后一次)出现的索引**
    - 如果没找到，都返回`-1`

    - 两种方法都接受作为**检索起始位置**的第二个参数。

    ```js
    var str = "The full name of China is the People's Republic of China.";
    var pos = str.indexOf("China", 18);

    ```

- `search()`：搜索特定值的字符串，并返回匹配的位置  

    ```js
    var str = "The full name of China is the People's Republic of China.";
    var pos = str.search("locate");
    ```

- `match()` 方法根据**正则表达式**在字符串中搜索匹配项，并将匹配项作为 Array 对象返回。



!!! tip "`indexOf()`与`search()`的差异"
    - 这两种方法是不相等的。区别在于：

    - `search()` 方法**无法设置第二个开始位置参数**。

    - `indexOf()` 方法无法设置更强大的搜索值（**正则表达式**）。

----

- `slice()`： 提取字符串的某个部分并在**新字符串**中返回被提取的部分。

    - 该方法设置两个参数：起始索引（开始位置），终止索引（结束位置）。

    - 如果省略第二个参数，则该方法将裁剪字符串的剩余部分

    ```js title="裁剪字符串中位置 7 到位置 13"
    var str = "Apple, Banana, Mango";
    var res = str.slice(7,13);
    ```


- `substring()`： 类似于 `slice()`。  
    - 不同之处在于 `substring()` 无法接受负的索引。

- `substr()`： 类似于 `slice()`。  
    - 不同之处在于第二个参数规定被提取部分的长度。


----

**替换字符串内容**

- `replace()` ：用另一个值替换在字符串中指定的值  

    - `replace()` 方法**不会改变**调用它的字符串。它**返回的是新字符串**。

    - 默认地，`replace()` 只替换**首个匹配**：

        ```js 
        str = "Please visit Microsoft and Microsoft!";
        var n = str.replace("Microsoft", "W3School");
        ```

    - 默认地，`replace()` 对**大小写敏感**。因此不对匹配 MICROSOFT：
        ```js
        str = "Please visit Microsoft!";
        var n = str.replace("MICROSOFT", "W3School");
        ```
    
    - 想要实现更多操作，如大小写不敏感(`/i`)、替换所有匹配(`/g`)，则要使用**正则表达式**


-----

**转换为大写和小写**

- `toUpperCase()`,`toLowerCase()`：返回转换后的字符串
    
    ```js
    var text1 = "Hello World!";       // 字符串
    var text2 = text1.toUpperCase();  // text2 是被转换为大写的 text1
    var text2 = text1.toLowerCase();  // text2 是被转换为小写的 text1
    ```

-----

- `concat()`： 连接两个或多个字符串

    - `concat()` 方法可用于代替加运算符。下面两行是等效的：

    ```js
    var text = "Hello" + " " + "World!";
    var text = "Hello".concat(" ","World!");
    ```

-----

- `trim()` 方法删除字符串**两端**的空白符

    ```js 
    var str = "       Hello World!        ";
    alert(str.trim());
    >>> "Hello World!"
    ```

- 可以说这个方法能用replace＋正则代替

    ```js
    var str = "       Hello World!        ";
    alert(str.replace(/^[\s\uFEFF\xA0]+|[\s\uFEFF\xA0]+$/g, ''));
    // 这个正则表达式用于匹配并移除字符串开头和结尾的空白字符，包括常见的空白字符和一些特殊的空白字符（如 Unicode 字符 \uFEFF 和 \xA0）。
    ```

----

**提取字符串字符**

- `charAt()` 方法返回字符串中指定**索引（位置）**的字符：

- `charCodeAt()` 方法返回字符串中指定索引的字符 `unicode` 编码：

    ```js 

    var str = "HELLO WORLD";
    str.charAt(0);            // 返回 H
    str.charCodeAt(0);         // 返回 72

    ```

- 当然也可以直接用 `str[0]`的语句来访问字符串字符

!!! warning "直接属性访问的坏处"

    - 不适用 Internet Explorer 7 或更早的版本

    - 它让字符串看起来像是数组（**其实并不是**）

    - 如果找不到字符，[ ] 返回 `undefined`，而 `charAt()` 返回空字符串。

    - 它是**只读的**。`str[0] = "A"` 不会产生错误（但也不会工作！）

---

**将字符串转换为数组**

- `split()` 将字符串转换为数组
    
    - 如果省略分隔符，被返回的数组将包含 index [0] 中的整个字符串。

    - 如果分隔符是 ""，被返回的数组将是间隔单个字符的数组：

    ```js
    var txt = "a,b,c,d,e";   // 字符串
    txt.split();             // 返回['a,b,c,d,e']
    txt.split(",");          // 用逗号分隔, 返回['a','b','c','d','e']
    txt.split(" ");          // 用空格分隔
    txt.split("|");          // 用竖线分隔
    txt.split("");           // 分隔每一个字符，返回['a',',','b',',','c',',','d',',','e']
    ```


## 日期

- 创建 Date 对象

- 有 4 种方法创建新的日期对象：

    - `new Date()`

    - `new Date(year, month, day, hours, minutes, seconds, milliseconds)`

    - `new Date(milliseconds)`

    - `new Date(date string)`


??? note "关于 `new Date(year, month, ...)`" 
    - 7个数字分别指定年、月、日、小时、分钟、秒和毫秒（按此顺序）

    - 少一数字，就少一个**最后的量**

    - 比如：6个数字指定年、月、日、小时、分钟、秒（没有了毫秒）

    - 但是最少是**两个参数**，因为一个参数不会被解读为年，而是**毫秒**

----

**毫秒**

- JavaScript 将日期存储为自 1970 年 1 月 1 日 00:00:00 UTC（协调世界时）以来的毫秒数。

- 零时间是 1970 年 1 月 1 日 00:00:00 UTC。

现在的时间是：1970 年 1 月 1 日之后的 <b id="Date"></b> <script>var d = new Date();document.getElementById("Date").innerHTML = d.getTime()</script>   毫秒。

### 日期获取方法 

|方法|描述|
|----|----|
|`getDate()`	|以数值返回天（1-31）|
|`getDay()`	|以数值获取周名（0-6）|
|`getFullYear()	`|获取四位的年（yyyy）|
|`getHours()	`|获取小时（0-23）|
|`getMilliseconds()`|	获取毫秒（0-999）|
|`getMinutes()`|	获取分（0-59）|
|`getMonth()`|	获取月（0-11）|
|`getSeconds()`|	获取秒（0-59）|
|`getTime()`|	获取时间（从 1970 年 1 月 1 日至今）|




## BOM

- 浏览器对象模型（Browser Object Model (BOM)）允许 JavaScript 与浏览器对话。

### Window

- 所有浏览器都支持 window 对象。它代表浏览器的窗口。

- 所有全局 JavaScript 对象，函数和变量自动成为 window 对象的成员。

- 全局变量是 window 对象的属性。

- 全局函数是 window 对象的方法。


```js title="这两者是等同的"
window.document.getElementById("header");
document.getElementById("header");
```

---

#### 窗口尺寸

- `window.innerHeight`：浏览器窗口的内高度（以像素计）
- `window.innerWidth`：浏览器窗口的内高度（以像素计）

- `window.open()`：打开新窗口
- `window.close()`：关闭当前窗口
- `window.moveTo()`：移动当前窗口
- `window.resizeTo()`：重新调整当前窗口

### Screen

- `window.screen` 对象包含用户**屏幕**的信息

- `window.screen` 对象不带 `window` 前缀也可以







