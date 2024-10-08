## Flexbox

- 将父元素设置为`display: flex`，可以使得子元素使用Flexbox布局，允许子元素根据设置的宽度比例进行排列和分配空间

??? note "示例"

    ```css
    html, body {
        height: 100%;
        margin: 0;
        padding: 0;
    }

    body {
        display: flex;
        flex-direction: column;
        height: 100vh;
    }

    /* 导航栏 */
    .navigator {
        width: 100%;
        height: 10%;
        background-color: red;
        text-align: center;

    }

    /* 内容区域 */
    .content {
        display: flex;
        flex: 1;
    }

    /* 侧边栏 */
    .leftside {
        width: 20%;
        background-color: green;
        text-align: center;
        display: flex;
        align-items: center;  /* 垂直居中 */
        justify-content: center;  /* 水平居中 */
    }

    /* 主体内容 */
    .main {
        width: 80%;
        background-color: blue;
        text-align: center;
        display: flex;
        align-items: center;  /* 垂直居中 */
        justify-content: center;  /* 水平居中 */
    }

    /* 页脚 */
    .footer {
        width: 100%;
        height: 10%;
        background-color: yellow;
        text-align: center;

    }

    ```

## margin

- `margin` 是 CSS 中的一个属性，用于设置元素周围的外边距。它的主要功能是**控制元素与其周围其他元素之间的距离**

- `margin: 0 auto` 是 CSS 中的一种常见用法，用于水平居中一个块级元素。它的具体含义如下：

- `margin: 0 auto`：表示上下边距为 0，左右边距为自动（auto）。  

    - `0`：表示上下边距为 0 像素。  

    - `auto`：表示浏览器会自动计算左右边距，使元素水平居中。  

## padding

- `padding` 是 CSS 中的一个属性，用于设置元素内容与其边框之间的内边距。