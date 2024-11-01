# 微信开发者工具

!!! abstract "参考文档"
    - [微信小程序官方指南](https://developers.weixin.qq.com/miniprogram/dev/framework/quickstart/code.html#JSON-%E9%85%8D%E7%BD%AE)

---

## 小程序代码构成

### JSON 配置

- JSON 是一种数据格式，并不是编程语言，在小程序中，JSON扮演的静态配置的角色。

- 在项目的根目录有一个 `app.json` 和 `project.config.json`，此外在 `pages/logs` 目录下还有一个 `logs.json`，我们依次来说明一下它们的用途。

=== "小程序配置 app.json"

    - app.json 是当前小程序的全局配置，包括了小程序的所有页面路径、界面表现、网络超时时间、底部 tab 等。QuickStart 项目里边的 app.json 配置内容如下：
    
    ```json
    {
    "pages":[
        "pages/index/index",
        "pages/logs/logs"
    ],
    "window":{
        "backgroundTextStyle":"light",
        "navigationBarBackgroundColor": "#fff",
        "navigationBarTitleText": "Weixin",
        "navigationBarTextStyle":"black"
    }
    }
    ```

    - `pages`字段 —— 用于描述当前小程序所有页面路径，这是为了让微信客户端知道当前你的小程序页面定义在哪个目录。

    - `window`字段 —— 定义小程序所有页面的顶部背景颜色，文字颜色定义等。

=== "工具配置 project.config.json"
    
    - 小程序开发者工具在每个项目的根目录都会生成一个 `project.config.json`，你在工具上做的**任何配置都会写入到这个文件**，当重新安装工具或者换电脑工作时，只要载入同一个项目的代码包，开发者工具就自动会帮你恢复到当时你开发项目时的**个性化配置**，其中会包括编辑器的颜色、代码上传时自动压缩等等一系列选项。

=== "页面配置 page.json"

    - 这里的 `page.json` 其实用来表示 `pages/logs` 目录下的 `logs.json` 这类和小程序页面相关的配置。

    - 如果你整个小程序的风格是蓝色调，那么你可以在 `app.json` 里边声明顶部颜色是蓝色即可。实际情况可能不是这样，可能你小程序里边的每个页面都有不一样的色调来区分不同功能模块，因此提供了 `page.json`，让开发者可以**独立定义每个页面的一些属性**，例如顶部颜色、是否允许下拉刷新等等。


----


#### JSON 语法

- JSON文件都是被包裹在一个大括号中 `{}`，通过**key-value**的方式来表达数据。JSON的**Key必须包裹在一个双引号中**

- JSON的值只能是以下几种数据格式，其他任何格式都会触发报错，例如 JavaScript 中的 undefined。

    - 数字，包含浮点数和整数
    - 字符串，需要包裹在双引号中
    - Bool值，true 或者 false
    - 数组，需要包裹在方括号中 []
    - 对象，需要包裹在大括号中 {}
    - Null
    - 还需要注意的是 JSON 文件中**无法使用注释**，试图添加注释将会引发报错。

---

