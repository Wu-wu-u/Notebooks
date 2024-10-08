# HTML 
!!! abstract "Reference"
    - [W3school](https://www.w3school.com.cn/h.asp)  
    - [标签参考手册](https://www.w3school.com.cn/tags/html_ref_byfunc.asp)


##  属性

- HTML 标签可以拥有属性。属性提供了有关 HTML 元素的更多的信息。  
- 属性总是以名称/值对的形式出现，比如：`name="value"`。   
- 属性总是在 HTML 元素的**开始标签**中规定。

### 使用小写属性

- 属性和属性值对大小写不敏感。  
- 不过，万维网联盟在其 HTML 4 推荐标准中推荐小写的属性/属性值。  
- 而新版本的 (X)HTML 要求使用小写属性。  

### 始终为属性值加引号

- 属性值应该始终被包括在引号内。双引号是最常用的，不过使用单引号也没有问题。  
- 在某些个别的情况下，比如属性值本身就含有双引号，那么必须使用**单引号** 
```html
name='Bill "HelloWorld" Gates'
```

-----

##  标题

- 标题（Heading）是通过 `<h1>` - `<h6>` 等标签进行定义的。  
- `<h1>` 定义最大的标题。`<h6>` 定义最小的标题。  
- 浏览器会自动地在标题的前后添加空行。  
- 默认情况下，HTML 会自动地在块级元素前后添加一个额外的空行，比如段落、标题元素前后。  

!!! note "header is important"
    - 确保将 HTML heading 标签只用于标题。不要仅仅是为了产生粗体或大号的文本而使用标题。  
    - 搜索引擎使用标题为您的网页的结构和内容编制索引。  

----

##  段落

- 使用空的段落标记 `<p></p>` 去插入一个空行是个坏习惯。用 `<br />` 标签代替它！（但是不要用 `<br />` 标签去创建列表。不要着急，您将在稍后的篇幅学习到 HTML 列表。）  
- 当显示页面时，浏览器会移除源代码中多余的空格和空行。所有连续的空格或空行都会被算作一个空格。需要注意的是，HTML 代码中的所有连续的空行（换行）也被显示为一个空格。  

!!! note "重要的几个标签"
    1. `<body>`
        - <body>标签定义了HTML文档的主体部分，是所有可见内容的容器。  
        - 一个HTML文档中只能有一个<body>标签。  
        - 它通常包含文本、图片、链接、表格、列表等所有用户可见的内容。  
    
    2. `<div>`
        - <div>是一个块级元素，用于组织内容和布局。  
        - 它没有特定的语义含义，主要用于CSS样式化和JavaScript操作的钩子。  
        - <div>标签常用于创建布局的“容器”，因为它可以轻松地通过CSS进行样式化和定位。  
   
    3. `<span>`

        - <span>是一个内联元素，用于对文档中的文本的一部分进行分组或应用样式。  
        - 与<div>类似，<span>也没有特定的语义含义。  
        - 它主要用于在文本内部进行小范围的样式化或用作JavaScript的钩子。  

----


##  样式

- 通过 HTML 样式，能够通过使用 `style` 属性直接将样式添加到 HTML 元素，或者间接地在独立的样式表中（CSS 文件）进行定义。

!!! warning "不赞成使用的标签和属性"
    - 在 HTML 4 中，有若干的标签和属性是被废弃的。被废弃（Deprecated）的意思是在未来版本的 HTML 和 XHTML 中将不支持这些标签和属性。  
    <li style="color: red"> 避免使用这些被废弃的标签和属性！</li>
    - 对于这些标签和属性：使用**样式**代替！
    
    |标签|	描述|
    |---|---|
    |`<center>`|	定义居中的内容。|
    |`<font>` 和 `<basefont>`|	定义 HTML 字体。|
    |`<s>` 和 `<strike>`|	定义删除线文本|
    |`<u>`|	定义下划线文本|
    |**属性**|	**描述**|
    |`align`|	定义文本的对齐方式|
    |`bgcolor`|	定义背景颜色|
    |`color`|	定义文本颜色|

??? note "样式示例"
    === "背景颜色"
        - `background-color` 属性为元素定义了背景颜色
        - `style` 属性淘汰了“旧的” `bgcolor` 属性
        ```html
        <html>

        <body style="background-color:yellow">
        <h2 style="background-color:red">This is a heading</h2>
        <p style="background-color:green">This is a paragraph.</p>
        </body>

        </html>
        ```

    === "字体、颜色和尺寸"
        - `font-family`、`color` 以及 `font-size` 属性分别定义元素中文本的字体系列、颜色和字体尺寸：
        - `style` 属性淘汰了旧的 `<font>` 标签。
        ```html
        <html>

        <body>
        <h1 style="font-family:verdana">A heading</h1>
        <p style="font-family:arial;color:red;font-size:20px;">A paragraph.</p>
        </body>

        </html>
        ```

    === "文本对齐"
        - `text-align` 属性规定了元素中文本的水平对齐方式：
        - `style` 属性淘汰了旧的 `"align"` 属性。
        ```html
        <html>

        <body>
        <h1 style="text-align:center">This is a heading</h1>
        <p>The heading above is aligned to the center of this page.</p>
        </body>

        </html>
        ``` 

##  格式化

=== "预格式文本"
    ```html
    <pre>
    这是
    预格式文本。
    它保留了      空格
    和换行。

    适合显示计算机代码
    for i = 1 to 10
        print i
    next i
    </pre>
    ```  

    <pre>
    这是
    预格式文本。
    它保留了      空格
    和换行。
    适合显示计算机代码
    for i = 1 to 10
        print i
    next i
    </pre>
    
=== "计算机输出类"
    - 这些标签常用于显示计算机/编程代码。

    ```html
    <code>Computer code</code>
    <br />
    <kbd>Keyboard input</kbd>
    <br />
    <tt>Teletype text</tt>
    <br />
    <samp>Sample text</samp>
    <br />
    <var>Computer variable</var>
    <br />
    ```

    <code>Computer code</code>
    <br />
    <kbd>Keyboard input</kbd>
    <br />
    <tt>Teletype text</tt>
    <br />
    <samp>Sample text</samp>
    <br />
    <var>Computer variable</var>
    <br />

=== "地址"
    - 此元素通常以斜体显示。大多数浏览器会在此元素前后添加折行。

    ```html 
    <address>
    Written by <a href="mailto:webmaster@example.com">Donald Duck.<br> 
    Visit us at:<br>
    Example.com<br>
    Box 564, Disneyland<br>
    USA
    </a></address>
    ```
    <address>
    Written by <a href="mailto:webmaster@example.com">Donald Duck.<br> 
    Visit us at:<br>
    Example.com<br>
    Box 564, Disneyland<br>
    USA
    </a></address>


=== "缩写"

    在某些浏览器中，当您把鼠标移至缩略词语上时，title 可用于展示表达的完整版本。 

    ```html
    <abbr title="etcetera">etc.</abbr>
    <br />
    <acronym title="World Wide Web">WWW</acronym>
    ```

    <abbr title="etcetera">etc.</abbr>
    <br />
    <acronym title="World Wide Web">WWW</acronym>


=== "文字方向"
    - 如果您的浏览器支持 bi-directional override (bdo)，下一行会从右向左输出 (rtl)；

    ```html
    <bdo dir="rtl">
    Here is some Hebrew text
    </bdo>
    ```
    <bdo dir="rtl">
    Here is some Hebrew text
    </bdo>

=== "引用"
    - 使用 `blockquote` 元素的话，浏览器会插入换行和外边距，而 q 元素不会有任何特殊的呈现。

    ```html
    这是长的引用：
    <blockquote>
    这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。
    </blockquote>

    这是短的引用：
    <q>
    这是短的引用。
    </q>
    ```
    这是长的引用：
    <blockquote>
    这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。这是长的引用。
    </blockquote>

    这是短的引用：
    <q>
    这是短的引用。
    </q>


=== "删除和插入字"
    ```html
    <p>一打有 <del>二十</del> <ins>十二</ins> 件。</p>
    ```
    <p>一打有 <del>二十</del> <ins>十二</ins> 件。</p>

<hr/>

##  颜色

!!! abstract
    - [颜色名列表](https://www.w3school.com.cn/html/html_colornames.asp)

<table class="dataintable" style="border: 1;">
<tr>
<th width="25%">颜色名</th>
<th width="25%">十六进制颜色值</th>
<th width="50%">颜色</th>
</tr>

<tr>
<td>AliceBlue</td>
<td>#F0F8FF</td>
<td style="background-color:#F0F8FF">&nbsp;</td>
</tr>

<tr>
<td>AntiqueWhite</td>
<td>#FAEBD7</td>
<td style="background-color:#FAEBD7">&nbsp;</td>
</tr>

<tr>
<td>Aqua</td>
<td>#00FFFF</td>
<td style="background-color:#00FFFF">&nbsp;</td>
</tr>

<tr>
<td>Aquamarine</td>
<td>#7FFFD4</td>
<td style="background-color:#7FFFD4">&nbsp;</td>
</tr>

<tr>
<td>Azure</td>
<td>#F0FFFF</td>
<td style="background-color:#F0FFFF">&nbsp;</td>
</tr>

<tr>
<td>Beige</td>
<td>#F5F5DC</td>
<td style="background-color:#F5F5DC">&nbsp;</td>
</tr>

<tr>
<td>Bisque</td>
<td>#FFE4C4</td>
<td style="background-color:#FFE4C4">&nbsp;</td>
</tr>

<tr>
<td>Black</td>
<td>#000000</td>
<td style="background-color:#000000">&nbsp;</td>
</tr>

<tr>
<td>BlanchedAlmond</td>
<td>#FFEBCD</td>
<td style="background-color:#FFEBCD">&nbsp;</td>
</tr>

<tr>
<td>Blue</td>
<td>#0000FF</td>
<td style="background-color:#0000FF">&nbsp;</td>
</tr>

<tr>
<td>BlueViolet</td>
<td>#8A2BE2</td>
<td style="background-color:#8A2BE2">&nbsp;</td>
</tr>

<tr>
<td>Brown</td>
<td>#A52A2A</td>
<td style="background-color:#A52A2A">&nbsp;</td>
</tr>

<tr>
<td>BurlyWood</td>
<td>#DEB887</td>
<td style="background-color:#DEB887">&nbsp;</td>
</tr>

<tr>
<td>CadetBlue</td>
<td>#5F9EA0</td>
<td style="background-color:#5F9EA0">&nbsp;</td>
</tr>

<tr>
<td>Chartreuse</td>
<td>#7FFF00</td>
<td style="background-color:#7FFF00">&nbsp;</td>
</tr>

<tr>
<td>Chocolate</td>
<td>#D2691E</td>
<td style="background-color:#D2691E">&nbsp;</td>
</tr>

<tr>
<td>Coral</td>
<td>#FF7F50</td>
<td style="background-color:#FF7F50">&nbsp;</td>
</tr>

<tr>
<td>CornflowerBlue</td>
<td>#6495ED</td>
<td style="background-color:#6495ED">&nbsp;</td>
</tr>

<tr>
<td>Cornsilk</td>
<td>#FFF8DC</td>
<td style="background-color:#FFF8DC">&nbsp;</td>
</tr>

<tr>
<td>Crimson</td>
<td>#DC143C</td>
<td style="background-color:#DC143C">&nbsp;</td>
</tr>

<tr>
<td>Cyan</td>
<td>#00FFFF</td>
<td style="background-color:#00FFFF">&nbsp;</td>
</tr>

<tr>
<td>DarkBlue</td>
<td>#00008B</td>
<td style="background-color:#00008B">&nbsp;</td>
</tr>

<tr>
<td>DarkCyan</td>
<td>#008B8B</td>
<td style="background-color:#008B8B">&nbsp;</td>
</tr>

<tr>
<td>DarkGoldenRod</td>
<td>#B8860B</td>
<td style="background-color:#B8860B">&nbsp;</td>
</tr>

<tr>
<td>DarkGray</td>
<td>#A9A9A9</td>
<td style="background-color:#A9A9A9">&nbsp;</td>
</tr>

<tr>
<td>DarkGreen</td>
<td>#006400</td>
<td style="background-color:#006400">&nbsp;</td>
</tr>

<tr>
<td>DarkKhaki</td>
<td>#BDB76B</td>
<td style="background-color:#BDB76B">&nbsp;</td>
</tr>

<tr>
<td>DarkMagenta</td>
<td>#8B008B</td>
<td style="background-color:#8B008B">&nbsp;</td>
</tr>

<tr>
<td>DarkOliveGreen</td>
<td>#556B2F</td>
<td style="background-color:#556B2F">&nbsp;</td>
</tr>

<tr>
<td>Darkorange</td>
<td>#FF8C00</td>
<td style="background-color:#FF8C00">&nbsp;</td>
</tr>

<tr>
<td>DarkOrchid</td>
<td>#9932CC</td>
<td style="background-color:#9932CC">&nbsp;</td>
</tr>

<tr>
<td>DarkRed</td>
<td>#8B0000</td>
<td style="background-color:#8B0000">&nbsp;</td>
</tr>

<tr>
<td>DarkSalmon</td>
<td>#E9967A</td>
<td style="background-color:#E9967A">&nbsp;</td>
</tr>

<tr>
<td>DarkSeaGreen</td>
<td>#8FBC8F</td>
<td style="background-color:#8FBC8F">&nbsp;</td>
</tr>

<tr>
<td>DarkSlateBlue</td>
<td>#483D8B</td>
<td style="background-color:#483D8B">&nbsp;</td>
</tr>

<tr>
<td>DarkSlateGray</td>
<td>#2F4F4F</td>
<td style="background-color:#2F4F4F">&nbsp;</td>
</tr>

<tr>
<td>DarkTurquoise</td>
<td>#00CED1</td>
<td style="background-color:#00CED1">&nbsp;</td>
</tr>

<tr>
<td>DarkViolet</td>
<td>#9400D3</td>
<td style="background-color:#9400D3">&nbsp;</td>
</tr>

<tr>
<td>DeepPink</td>
<td>#FF1493</td>
<td style="background-color:#FF1493">&nbsp;</td>
</tr>

<tr>
<td>DeepSkyBlue</td>
<td>#00BFFF</td>
<td style="background-color:#00BFFF">&nbsp;</td>
</tr>

<tr>
<td>DimGray</td>
<td>#696969</td>
<td style="background-color:#696969">&nbsp;</td>
</tr>

<tr>
<td>DodgerBlue</td>
<td>#1E90FF</td>
<td style="background-color:#1E90FF">&nbsp;</td>
</tr>

<tr>
<td>Feldspar</td>
<td>#D19275</td>
<td style="background-color:#D19275">&nbsp;</td>
</tr>

<tr>
<td>FireBrick</td>
<td>#B22222</td>
<td style="background-color:#B22222">&nbsp;</td>
</tr>

<tr>
<td>FloralWhite</td>
<td>#FFFAF0</td>
<td style="background-color:#FFFAF0">&nbsp;</td>
</tr>

<tr>
<td>ForestGreen</td>
<td>#228B22</td>
<td style="background-color:#228B22">&nbsp;</td>
</tr>

<tr>
<td>Fuchsia</td>
<td>#FF00FF</td>
<td style="background-color:#FF00FF">&nbsp;</td>
</tr>

<tr>
<td>Gainsboro</td>
<td>#DCDCDC</td>
<td style="background-color:#DCDCDC">&nbsp;</td>
</tr>

<tr>
<td>GhostWhite</td>
<td>#F8F8FF</td>
<td style="background-color:#F8F8FF">&nbsp;</td>
</tr>

<tr>
<td>Gold</td>
<td>#FFD700</td>
<td style="background-color:#FFD700">&nbsp;</td>
</tr>

<tr>
<td>GoldenRod</td>
<td>#DAA520</td>
<td style="background-color:#DAA520">&nbsp;</td>
</tr>

<tr>
<td>Gray</td>
<td>#808080</td>
<td style="background-color:#808080">&nbsp;</td>
</tr>

<tr>
<td>Green</td>
<td>#008000</td>
<td style="background-color:#008000">&nbsp;</td>
</tr>

<tr>
<td>GreenYellow</td>
<td>#ADFF2F</td>
<td style="background-color:#ADFF2F">&nbsp;</td>
</tr>

<tr>
<td>HoneyDew</td>
<td>#F0FFF0</td>
<td style="background-color:#F0FFF0">&nbsp;</td>
</tr>

<tr>
<td>HotPink</td>
<td>#FF69B4</td>
<td style="background-color:#FF69B4">&nbsp;</td>
</tr>

<tr>
<td>IndianRed </td>
<td>#CD5C5C</td>
<td style="background-color:#CD5C5C">&nbsp;</td>
</tr>

<tr>
<td>Indigo  </td>
<td>#4B0082</td>
<td style="background-color:#4B0082">&nbsp;</td>
</tr>

<tr>
<td>Ivory</td>
<td>#FFFFF0</td>
<td style="background-color:#FFFFF0">&nbsp;</td>
</tr>

<tr>
<td>Khaki</td>
<td>#F0E68C</td>
<td style="background-color:#F0E68C">&nbsp;</td>
</tr>

<tr>
<td>Lavender</td>
<td>#E6E6FA</td>
<td style="background-color:#E6E6FA">&nbsp;</td>
</tr>

<tr>
<td>LavenderBlush</td>
<td>#FFF0F5</td>
<td style="background-color:#FFF0F5">&nbsp;</td>
</tr>

<tr>
<td>LawnGreen</td>
<td>#7CFC00</td>
<td style="background-color:#7CFC00">&nbsp;</td>
</tr>

<tr>
<td>LemonChiffon</td>
<td>#FFFACD</td>
<td style="background-color:#FFFACD">&nbsp;</td>
</tr>

<tr>
<td>LightBlue</td>
<td>#ADD8E6</td>
<td style="background-color:#ADD8E6">&nbsp;</td>
</tr>

<tr>
<td>LightCoral</td>
<td>#F08080</td>
<td style="background-color:#F08080">&nbsp;</td>
</tr>

<tr>
<td>LightCyan</td>
<td>#E0FFFF</td>
<td style="background-color:#E0FFFF">&nbsp;</td>
</tr>

<tr>
<td>LightGoldenRodYellow</td>
<td>#FAFAD2</td>
<td style="background-color:#FAFAD2">&nbsp;</td>
</tr>

<tr>
<td>LightGrey</td>
<td>#D3D3D3</td>
<td style="background-color:#D3D3D3">&nbsp;</td>
</tr>

<tr>
<td>LightGreen</td>
<td>#90EE90</td>
<td style="background-color:#90EE90">&nbsp;</td>
</tr>

<tr>
<td>LightPink</td>
<td>#FFB6C1</td>

<td style="background-color:#FFB6C1">&nbsp;</td>
</tr>

<tr>
<td>LightSalmon</td>
<td>#FFA07A</td>
<td style="background-color:#FFA07A">&nbsp;</td>
</tr>

<tr>
<td>LightSeaGreen</td>
<td>#20B2AA</td>
<td style="background-color:#20B2AA">&nbsp;</td>
</tr>

<tr>
<td>LightSkyBlue</td>
<td>#87CEFA</td>
<td style="background-color:#87CEFA">&nbsp;</td>
</tr>

<tr>
<td>LightSlateBlue</td>
<td>#8470FF</td>
<td style="background-color:#8470FF">&nbsp;</td>
</tr>

<tr>
<td>LightSlateGray</td>
<td>#778899</td>
<td style="background-color:#778899">&nbsp;</td>
</tr>

<tr>
<td>LightSteelBlue</td>
<td>#B0C4DE</td>
<td style="background-color:#B0C4DE">&nbsp;</td>
</tr>

<tr>
<td>LightYellow</td>
<td>#FFFFE0</td>
<td style="background-color:#FFFFE0">&nbsp;</td>
</tr>

<tr>
<td>Lime</td>
<td>#00FF00</td>
<td style="background-color:#00FF00">&nbsp;</td>
</tr>

<tr>
<td>LimeGreen</td>
<td>#32CD32</td>
<td style="background-color:#32CD32">&nbsp;</td>
</tr>

<tr>
<td>Linen</td>
<td>#FAF0E6</td>
<td style="background-color:#FAF0E6">&nbsp;</td>
</tr>

<tr>
<td>Magenta</td>
<td>#FF00FF</td>
<td style="background-color:#FF00FF">&nbsp;</td>
</tr>

<tr>
<td>Maroon</td>
<td>#800000</td>
<td style="background-color:#800000">&nbsp;</td>
</tr>

<tr>
<td>MediumAquaMarine</td>
<td>#66CDAA</td>
<td style="background-color:#66CDAA">&nbsp;</td>
</tr>

<tr>
<td>MediumBlue</td>
<td>#0000CD</td>
<td style="background-color:#0000CD">&nbsp;</td>
</tr>

<tr>
<td>MediumOrchid</td>
<td>#BA55D3</td>
<td style="background-color:#BA55D3">&nbsp;</td>
</tr>

<tr>
<td>MediumPurple</td>
<td>#9370D8</td>
<td style="background-color:#9370D8">&nbsp;</td>
</tr>

<tr>
<td>MediumSeaGreen</td>
<td>#3CB371</td>
<td style="background-color:#3CB371">&nbsp;</td>
</tr>

<tr>
<td>MediumSlateBlue</td>
<td>#7B68EE</td>
<td style="background-color:#7B68EE">&nbsp;</td>
</tr>

<tr>
<td>MediumSpringGreen</td>
<td>#00FA9A</td>
<td style="background-color:#00FA9A">&nbsp;</td>
</tr>

<tr>
<td>MediumTurquoise</td>
<td>#48D1CC</td>
<td style="background-color:#48D1CC">&nbsp;</td>
</tr>

<tr>
<td>MediumVioletRed</td>
<td>#C71585</td>
<td style="background-color:#C71585">&nbsp;</td>
</tr>

<tr>
<td>MidnightBlue</td>
<td>#191970</td>
<td style="background-color:#191970">&nbsp;</td>
</tr>

<tr>
<td>MintCream</td>
<td>#F5FFFA</td>
<td style="background-color:#F5FFFA">&nbsp;</td>
</tr>

<tr>
<td>MistyRose</td>
<td>#FFE4E1</td>
<td style="background-color:#FFE4E1">&nbsp;</td>
</tr>

<tr>
<td>Moccasin</td>
<td>#FFE4B5</td>
<td style="background-color:#FFE4B5">&nbsp;</td>
</tr>

<tr>
<td>NavajoWhite</td>
<td>#FFDEAD</td>
<td style="background-color:#FFDEAD">&nbsp;</td>
</tr>

<tr>
<td>Navy</td>
<td>#000080</td>
<td style="background-color:#000080">&nbsp;</td>
</tr>

<tr>
<td>OldLace</td>
<td>#FDF5E6</td>
<td style="background-color:#FDF5E6">&nbsp;</td>
</tr>

<tr>
<td>Olive</td>
<td>#808000</td>
<td style="background-color:#808000">&nbsp;</td>
</tr>

<tr>
<td>OliveDrab</td>
<td>#6B8E23</td>
<td style="background-color:#6B8E23">&nbsp;</td>
</tr>

<tr>
<td>Orange</td>
<td>#FFA500</td>
<td style="background-color:#FFA500">&nbsp;</td>
</tr>

<tr>
<td>OrangeRed</td>
<td>#FF4500</td>
<td style="background-color:#FF4500">&nbsp;</td>
</tr>

<tr>
<td>Orchid</td>
<td>#DA70D6</td>
<td style="background-color:#DA70D6">&nbsp;</td>
</tr>

<tr>
<td>PaleGoldenRod</td>
<td>#EEE8AA</td>
<td style="background-color:#EEE8AA">&nbsp;</td>
</tr>

<tr>
<td>PaleGreen</td>
<td>#98FB98</td>
<td style="background-color:#98FB98">&nbsp;</td>
</tr>

<tr>
<td>PaleTurquoise</td>
<td>#AFEEEE</td>
<td style="background-color:#AFEEEE">&nbsp;</td>
</tr>

<tr>
<td>PaleVioletRed</td>
<td>#D87093</td>
<td style="background-color:#D87093">&nbsp;</td>
</tr>

<tr>
<td>PapayaWhip</td>
<td>#FFEFD5</td>
<td style="background-color:#FFEFD5">&nbsp;</td>
</tr>

<tr>
<td>PeachPuff</td>
<td>#FFDAB9</td>
<td style="background-color:#FFDAB9">&nbsp;</td>
</tr>

<tr>
<td>Peru</td>
<td>#CD853F</td>
<td style="background-color:#CD853F">&nbsp;</td>
</tr>

<tr>
<td>Pink</td>
<td>#FFC0CB</td>
<td style="background-color:#FFC0CB">&nbsp;</td>
</tr>

<tr>
<td>Plum</td>
<td>#DDA0DD</td>
<td style="background-color:#DDA0DD">&nbsp;</td>
</tr>

<tr>
<td>PowderBlue</td>
<td>#B0E0E6</td>
<td style="background-color:#B0E0E6">&nbsp;</td>
</tr>

<tr>
<td>Purple</td>
<td>#800080</td>
<td style="background-color:#800080">&nbsp;</td>
</tr>

<tr>
<td>Red</td>
<td>#FF0000</td>
<td style="background-color:#FF0000">&nbsp;</td>
</tr>

<tr>
<td>RosyBrown</td>
<td>#BC8F8F</td>
<td style="background-color:#BC8F8F">&nbsp;</td>
</tr>

<tr>
<td>RoyalBlue</td>
<td>#4169E1</td>
<td style="background-color:#4169E1">&nbsp;</td>
</tr>

<tr>
<td>SaddleBrown</td>
<td>#8B4513</td>
<td style="background-color:#8B4513">&nbsp;</td>
</tr>

<tr>
<td>Salmon</td>
<td>#FA8072</td>
<td style="background-color:#FA8072">&nbsp;</td>
</tr>

<tr>
<td>SandyBrown</td>
<td>#F4A460</td>
<td style="background-color:#F4A460">&nbsp;</td>
</tr>

<tr>
<td>SeaGreen</td>
<td>#2E8B57</td>
<td style="background-color:#2E8B57">&nbsp;</td>
</tr>

<tr>
<td>SeaShell</td>
<td>#FFF5EE</td>
<td style="background-color:#FFF5EE">&nbsp;</td>
</tr>

<tr>
<td>Sienna</td>
<td>#A0522D</td>
<td style="background-color:#A0522D">&nbsp;</td>
</tr>

<tr>
<td>Silver</td>
<td>#C0C0C0</td>
<td style="background-color:#C0C0C0">&nbsp;</td>
</tr>

<tr>
<td>SkyBlue</td>
<td>#87CEEB</td>
<td style="background-color:#87CEEB">&nbsp;</td>
</tr>

<tr>
<td>SlateBlue</td>
<td>#6A5ACD</td>
<td style="background-color:#6A5ACD">&nbsp;</td>
</tr>

<tr>
<td>SlateGray</td>
<td>#708090</td>
<td style="background-color:#708090">&nbsp;</td>
</tr>

<tr>
<td>Snow</td>
<td>#FFFAFA</td>
<td style="background-color:#FFFAFA">&nbsp;</td>
</tr>

<tr>
<td>SpringGreen</td>
<td>#00FF7F</td>
<td style="background-color:#00FF7F">&nbsp;</td>
</tr>

<tr>
<td>SteelBlue</td>
<td>#4682B4</td>
<td style="background-color:#4682B4">&nbsp;</td>
</tr>

<tr>
<td>Tan</td>
<td>#D2B48C</td>
<td style="background-color:#D2B48C">&nbsp;</td>
</tr>

<tr>
<td>Teal</td>
<td>#008080</td>
<td style="background-color:#008080">&nbsp;</td>
</tr>

<tr>
<td>Thistle</td>
<td>#D8BFD8</td>
<td style="background-color:#D8BFD8">&nbsp;</td>
</tr>

<tr>
<td>Tomato</td>
<td>#FF6347</td>
<td style="background-color:#FF6347">&nbsp;</td>
</tr>

<tr>
<td>Turquoise</td>
<td>#40E0D0</td>
<td style="background-color:#40E0D0">&nbsp;</td>
</tr>

<tr>
<td>Violet</td>
<td>#EE82EE</td>
<td style="background-color:#EE82EE">&nbsp;</td>
</tr>

<tr>
<td>VioletRed</td>
<td>#D02090</td>
<td style="background-color:#D02090">&nbsp;</td>
</tr>

<tr>
<td>Wheat</td>
<td>#F5DEB3</td>
<td style="background-color:#F5DEB3">&nbsp;</td>
</tr>

<tr>
<td>White</td>
<td>#FFFFFF</td>
<td style="background-color:#FFFFFF">&nbsp;</td>
</tr>

<tr>
<td>WhiteSmoke</td>
<td>#F5F5F5</td>
<td style="background-color:#F5F5F5">&nbsp;</td>
</tr>

<tr>
<td>Yellow</td>
<td>#FFFF00</td>
<td style="background-color:#FFFF00">&nbsp;</td>
</tr>

<tr>
<td>YellowGreen</td>
<td>#9ACD32</td>
<td style="background-color:#9ACD32">&nbsp;</td>
</tr>

</table>




##  CSS

=== "内部样式表"
    - 当单个文件需要特别样式时，就可以使用内部样式表。可以在 `head` 部分通过 `<style>` 标签定义内部样式表。
    ```html
    <head>
    <style type="text/css">
    body {background-color: red}
    p {margin-left: 20px}
    </style>
    </head>
    ```

=== "外部样式表"
    - 当样式需要被应用到很多页面的时候，外部样式表将是理想的选择。使用外部样式表，你就可以通过更改一个文件来改变整个站点的外观。
    ```html
    <head>
    <link rel="stylesheet" type="text/css" href="mystyle.css">
    </head>
    ```

=== "内联样式"
    - 当特殊的样式需要应用到**个别元素**时，就可以使用内联样式。使用内联样式的方法是在相关的**标签**中使用样式属性。样式属性可以包含任何 CSS 属性。以下实例显示出如何改变段落的颜色和左外边距。
    ```html
    <p style="color: red; margin-left: 20px">
    This is a paragraph
    </p>
    ```

=== "导入式"
    - @import写在`<style>`标签内最开始
    ```html
    <style>
      @import "外部CSS样式"
    </style>
    ```


-----

##  链接

- 有两种使用 `<a>` 标签的方式：  
    - 通过使用 href 属性 - 创建指向另一个文档的链接  
    - 通过使用 name 属性 - 创建文档内的书签  

!!! note "HTML 链接语法"
    - 链接的 HTML 代码很简单，href 属性规定链接的目标，开始标签和结束标签之间的文字被作为超级链接来显示。  
    - "链接文本" **不一定**是文本。**图片或其他 HTML 元素**都可以成为链接。
    ```html
    <a href="http://www.w3school.com.cn/">访问 W3School</a>
    ```

### target属性

- 使用 Target 属性，你可以定义被链接的文档在何处显示。
```html title="在新窗口打开"
<a href="http://www.w3school.com.cn/" target="_blank">Visit W3School!</a>
```

<a href="http://www.w3school.com.cn/" target="_blank">Visit W3School!</a>

### name属性
- `name` 属性规定**锚（anchor）**的名称。  
- 可以使用 `name` 属性创建 HTML 页面中的**书签**。  
- 书签不会以任何特殊方式显示，它对读者是不可见的。
- 当使用命名锚（named anchors）时，我们可以**创建直接跳至该命名锚**（比如页面中某个小节）的链接，这样使用者就无需不停地滚动页面来寻找他们需要的信息了。
    
---

- 首先，我们在 HTML 文档中对锚进行命名（创建一个书签）：
```html
<a name="tips">基本的注意事项 - 有用的提示</a>
```

- 然后，我们在同一个文档中创建指向该锚的链接：
```html
<a href="#tips">有用的提示</a>
```

- 也可以在其他页面中创建指向该锚的链接  
- 将 `#` 符号和锚名称添加到 URL 的末端，就可以直接链接到 `tips` 这个命名锚了。
```html
<a href="http://www.w3school.com.cn/html/html_links.asp#tips">有用的提示</a>
```

!!! tips "基本的注意事项 - 有用的提示"
    - 始终将正斜杠添加到子文件夹。假如这样书写链接：href="http://www.w3school.com.cn/html"，就会向服务器产生**两次** HTTP 请求。这是因为服务器会添加**正斜杠**到这个地址，然后创建一个新的请求，就像这样：href="http://www.w3school.com.cn/html/"  
    - 命名锚经常用于在大型文档开始位置上**创建目录**。可以为每个章节赋予一个命名锚，然后把链接到这些锚的链接放到文档的上部。  
    - 假如浏览器**找不到**已定义的命名锚，那么就会**定位到文档的顶端**。不会有错误发生。


##  图像

### 背景图片

<div style="background-image: url('../sources/persona-3-makoto.gif'); background-size: cover; background-position: 50% 85%">

<ul>
<li> <code>gif</code> 和 <code>jpg</code> 文件均可用作 HTML 背景。  </li>

<li> 如果图像小于页面，图像会进行重复。  </li>
</ul>
</div>


!!! note "调整图片"
    - `background-size`  
        - 可以指定背景图片的尺寸，可以是具体的宽高值，也可以是预定义的值`cover`,`contain`  
        - `cover`: 保证背景图片完全覆盖整个元素，图片可能会被裁剪。  
        - `contain`: 确保背景图片完整显示在元素内部，可能会导致图片无法完全覆盖元素的全部空间。  
        - 具体值：如`100px` `200px`，直接指定宽度和高度

    - `background-position`  
        - 这个属性接受两个值：第一个值控制**水平**位置，第二个值控制**垂直**位置。这些值可以是关键字（如top、bottom、left、right、center），也可以是长度（如px、em）或百分比。  
        - 50% 100%意味着背景图像将在容器的水平中心和垂直底部显示。    

##  表格

- 在HTML中，`<table>`标签用于创建表格。在这个表格结构中，`<tr>`和`<td>`是两个基本的元素，它们分别代表表格的行和单元格：  
    - `<tr>`: 表示Table Row，即表格的一行。你可以在`<tr>`元素内部使用`<td>`（表格单元格）或`<th>`（表格头部单元格）元素来定义行中的单元格。  
    - `<td>`: 表示Table Data，即表格中的一个数据单元格。它位于`<tr>`元素内部，用于显示内容。每个`<td>`元素代表一行中的一个单元格。  

    ```html
    <table>
    <tr>
    <td>row 1, cell 1</td>
    <td>row 1, cell 2</td>
    </tr>
    <tr>
    <td>row 2, cell 1</td>
    <td>row 2, cell 2</td>
    </tr>
    </table>
    ```

    <table>
    <tr>
    <td>row 1, cell 1</td>
    <td>row 1, cell 2</td>
    </tr>
    <tr>
    <td>row 2, cell 1</td>
    <td>row 2, cell 2</td>
    </tr>
    </table>

### 边框属性

- `border = "1"`：可以为表格添加边框，同时里面的整数代表了边框的粗细程度  

```html
<table border="1">
<tr>
<td>Row 1, cell 1</td>
<td>Row 1, cell 2</td>
</tr>
</table>
```

<table border="1">
<tr>
<td>Row 1, cell 1</td>
<td>Row 1, cell 2</td>
</tr>
</table>

----

- `frame` 属性可以控制围绕表格的边框。  

```html
<p>Table with frame="box":</p>
<table frame="box">
  <tr>
    <th>Month</th>
    <th>Savings</th>
  </tr>
  <tr>
    <td>January</td>
    <td>$100</td>
  </tr>
</table>

<p>Table with frame="above":</p>
<table frame="above">
  <tr>
    <th>Month</th>
    <th>Savings</th>
  </tr>
  <tr>
    <td>January</td>
    <td>$100</td>
  </tr>
</table>

<p>Table with frame="below":</p>
<table frame="below">
  <tr>
    <th>Month</th>
    <th>Savings</th>
  </tr>
  <tr>
    <td>January</td>
    <td>$100</td>
  </tr>
</table>

<p>Table with frame="hsides":</p>
<table frame="hsides">
  <tr>
    <th>Month</th>
    <th>Savings</th>
  </tr>
  <tr>
    <td>January</td>
    <td>$100</td>
  </tr>
</table>

<p>Table with frame="vsides":</p>
<table frame="vsides">
  <tr>
    <th>Month</th>
    <th>Savings</th>
  </tr>
  <tr>
    <td>January</td>
    <td>$100</td>
  </tr>
</table>

```
<img src="../image.png" width = 50%>

---


### 表头

- 表格的表头使用 <th> 标签进行定义。

- 大多数浏览器会把表头显示为粗体居中的文本：

```html
<table border="1">
<tr>
<th>Heading</th>
<th>Another Heading</th>
</tr>
<tr>
<td>row 1, cell 1</td>
<td>row 1, cell 2</td>
</tr>
<tr>
<td>row 2, cell 1</td>
<td>row 2, cell 2</td>
</tr>
</table>
```

<table border="1">
<tr>
<th>Heading</th>
<th>Another Heading</th>
</tr>
<tr>
<td>row 1, cell 1</td>
<td>row 1, cell 2</td>
</tr>
<tr>
<td>row 2, cell 1</td>
<td>row 2, cell 2</td>
</tr>
</table>

### 空单元格
- 在一些浏览器中，没有内容的表格单元显示得不太好。如果某个单元格是空的（没有内容），浏览器可能无法显示出这个单元格的边框。

```html
<table border="1">
<tr>
<td>row 1, cell 1</td>
<td>row 1, cell 2</td>
</tr>
<tr>
<td></td>
<td>row 2, cell 2</td>
</tr>
</table>
```

- 这个空的单元格的边框没有被显示出来。为了避免这种情况，在空单元格中添加一个空格占位符，就可以将边框显示出来。

```html
<table border="1">
<tr>
<td>row 1, cell 1</td>
<td>row 1, cell 2</td>
</tr>
<tr>
<td>&nbsp</td>
<td>row 2, cell 2</td>
</tr>
</table>
```

### 标题

- `<caption>`标签可以为表格添加标题
<table border="6">
<caption>我的标题</caption>
<tr>
  <td>100</td>
  <td>200</td>
  <td>300</td>
</tr>
<tr>
  <td>400</td>
  <td>500</td>
  <td>600</td>
</tr>
</table>

### 添加背景颜色和图片

- `bgcolor`和`background`可以为`<td>`或者整个表格添加背景颜色和图片
```html
<table border="1">
<tr>
  <td bgcolor="red">First</td>
  <td>Row</td>
</tr>   
<tr>
  <td 
  background="/i/eg_bg_07.gif">
  Second</td>
  <td>Row</td>
</tr>
</table>
```

### 跨行或跨列的单元格
- 在`<td>`标签中使用`clospan`或`rowspan`来达到跨列或跨行的效果  
```html
<table border="1">
  <tr>
    <td colspan="2" style="text-align:center;">First Row</td>
  </tr>
  <tr>
    <td>Second Row, First Column</td>
    <td>Second Row, Second Column</td>
  </tr>
</table>
```
```html
<table border="1">
  <tr>
    <td rowspan="2" >First Column</td>
    <td>First Row, Second Column</td>
  </tr>
  <tr>
    <td>Second Row, Second Column</td>
  </tr>
</table>

```


<table border="1">
  <tr>
    <td colspan="2">First Row</td>
  </tr>
  <tr>
    <td>Second Row, First Column</td>
    <td>Second Row, Second Column</td>
  </tr>
</table>



<table border="1">
  <tr>
    <td rowspan="2">First Column</td>
    <td>First Row, Second Column</td>
  </tr>
  <tr>
    <td>Second Row, Second Column</td>
  </tr>
</table>

----

## 块与内联元素

- “块级元素”译为 **block level element**，“内联元素”译为 **inline element**  
- 块级元素在浏览器显示时，通常会以新行来开始（和结束）  
    - 如：`<h1>`, `<p>`, `<ul>`, `<table>`  
- 内联元素在显示时通常不会以新行开始。  
    - 如：`<b>`, `<td>`, `<a>`, `<img>`

## 表单

- HTML 表单用于搜集不同类型的用户输入。
- `<form>`元素来定义表单  
- HTML 表单包含**表单元素**。  
- 表单元素指的是不同类型的 input 元素、复选框、单选按钮、提交按钮等等。  



### input 元素

- `<input>`元素是**最重要**的表单元素，根据不同的`type`属性可以有各种形态  

<table border="1">
<tr>
<th>类型</th>
<th>描述</th>
<th>实例</th>
</tr>
<tr>
<td>text</td>
<td>定义常规文本输入</td>
<td><input type="text" name="text" style="border: 1px solid black"></input></td>
</tr>
<tr>
<td>radio</td>
<td>定义单选按钮输入（选择多个选择之一）</td>
<td><input type="radio" name="text">Man!</input></td>
</tr>
<tr>
<td>Submit</td>
<td>定义提交按钮（提交表单）</td>
<td><input type="Submit" name="text" style="border: 1px solid black"></input></td>
</tr>

<tr>
<td>button</td>
<td>按钮</td>
<td><input type="button" value="Click Me" onclick="alert('Hello, World!')" style="border: 1px solid blue"></input></td>
</tr>

<tr>
<td>password</td>
<td>密码</td>
<td><input type="password" name="password" style="border: 1px solid black"></input></td>
</tr>

<tr>
<td>checkbox</td>
<td>复选框允许用户在有限数量的选项中选择零个或多个选项。</td>
<td><input type="checkbox" name="vehicle" value="Bike">I have a bike<br/><input type="checkbox" name="vehicle" value="Car">I have a car 
</td>
</tr>


</table>

!!! note "文本输入"  
    ```html
    <form>
    First name: </br>
    <input type="text" name="firstname">
    </br>
    Last name:</br>
    <input type="text" name="lastname">
    </form>
    ```

    - 表单本身并不可见。还要注意文本字段的默认宽度是 20 个字符。

    First name: </br>
    <input type="text" name="firstname" style="border: 1px solid black;">
    </br>
    Last name:</br>
    <input type="text" name="lastname" style="border: 1px solid black;">
    </form>

!!! note "单选按钮输入"
    - `radio`类型  
    ```html
    <form>
    <input type="radio" name="sex" value="male">Male
    <input type="radio" name="sex" value="male">Female
    </form>
    ```
    <form>
    <input type="radio" name="sex" value="male">Male
    <input type="radio" name="sex" value="male">Female
    </form>

!!! note "提交按钮"
    - <input type="submit"> 定义用于向表单处理程序（form-handler）提交表单的按钮。

    - 表单处理程序通常是包含用来处理输入数据的脚本的服务器页面。

    - 表单处理程序在表单的 action 属性中指定

    ```html
    <form action="action_page.php">
    First name:<br>
    <input type="text" name="firstname" value="Mickey">
    <br>
    Last name:<br>
    <input type="text" name="lastname" value="Mouse">
    <br><br>
    <input type="submit" value="Submit">
    </form> 
    ```
    <form action="action_page.php">
    First name:<br>
    <input type="text" name="firstname" value="Mickey" style="border: 1px solid black;">
    <br>
    Last name:<br>
    <input type="text" name="lastname" value="Mouse" style="border: 1px solid black;">
    <br><br>
    <input type="submit" value="Submit" style="border: 1px solid black;">
    </form> 

### Action 属性
- action 属性定义在提交表单时执行的动作。

- 向服务器提交表单的通常做法是使用提交按钮。

- 通常，表单会被提交到 web 服务器上的网页。

- 如果省略 action 属性，则 action 会被设置为当前页面。

```html 
<form action="action_page.php">
```

#### Method 属性

- method 属性规定在提交表单时所用的 HTTP 方法（GET 或 POST）：
```html
<form action="action_page.php" method="GET">
<form action="action_page.php" method="POST">

```

### Name 属性

- 如果要正确地被提交，每个输入字段必须设置一个 name 属性。

### fieldset 元素

- `<fieldset>`元素在HTML中用于对表单内的相关元素进行分组。它通常用于将表单 中的一组相关的控件（如输入框、选择列表等）组织在一起，这有助于提高表单的可读性和可用性。`<fieldset>`元素还可以与`<legend>`元素配合使用，后者为`<fieldset>`提供标题，进一步增强了表单的结构和清晰度。  

- 使用`<fieldset>`的主要目的和优点包括：   
    - 逻辑分组：将表单中相关的元素逻辑上分组在一起，使表单的结构更加清晰。  
    - 可访问性：对于使用屏幕阅读器的用户，`<fieldset>`和`<legend>`的组合提高了表单的可访问性，因为屏幕阅读器可以宣读`<legend>`内容，让用户知道接下来的表单控件属于哪个分组。  
    - 样式化：可以对`<fieldset>`应用CSS样式，以视觉上区分不同的表单部分。  

### 下拉菜单

|标签| 描述|
|----|----|
|`<select>`|下拉菜单和列表标签|
|`<option>`|下拉菜单和列表项目标签|
|`<optgroup>`|下拉菜单和列表项目分组标签|
|`<textarea>`|文字域标签|

<table>
<caption>select 标签属性</caption>
<tr>
<th>属性</th><th>描述</th>
</tr>
<tr>
<td>name</td><td>设置下拉菜单和列表的名称</td>
</tr>
<tr>
<td>multiple</td><td>设置可选择多个选项</td>
</tr>
<tr>
<td>size</td><td>设置列表中可见选项的数目</td>
</tr>
</table>

