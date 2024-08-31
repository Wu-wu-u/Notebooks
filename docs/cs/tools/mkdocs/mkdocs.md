!!! Abstract
    - 对于Mkdocs部署的基本配置
    - **Tutorial** : 
        - https://squidfunk.github.io/mkdocs-material/setup/
        - https://squidfunk.github.io/mkdocs-material/reference/



## mkdocs.yml的组成

### Info
```yml title="左上角网页标题、仓库指向、版权声明"
site_name: Wu-wu-u's Notebooks
site_url: https://github.com/Wu-wu-u/Notebooks
site_author: Wu-wu-u
repo_url: https://github.com/Wu-wu-u/Notebooks
repo_name: Wu-wu-u/Notebooks
copyright: Copyright &copy; 2023-2024 <a herf="https://github.com/Wu-wu-u" target="_blank" rel="noopener">Wu-wu-u</a>
```

### Theme
- 都是包含在theme下的子分支，即
```yml
theme: 
    name: ...
    favicon: ...
    icon: ...
    ...: ...
```


```yml title="1. material主题及配色"
    name: material
    palette: 
    # 日间模式
    - media: "(prefers-color-scheme: light)"
    scheme: default
    # 主颜色 即上方颜色
    # https://squidfunk.github.io/mkdocs-material/setup/changing-the-colors/#primary-color
    primary: white
    # 链接等可交互元件的高亮色
    # https://squidfunk.github.io/mkdocs-material/setup/changing-the-colors/#accent-color
    # accent: teal 青色，默认为蓝色
    toggle:
        # 图标
        icon: material/weather-sunny
        # 鼠标悬浮提示
        name: 切换至夜间模式
    # 夜间模式
    - media: "(prefers-color-scheme: dark)"
    scheme: slate # slate是最接近黑夜模式的一个scheme
    primary: black
    accent: blue
    toggle:
        icon: material/weather-night
        name: 切换至日间模式
```
``` yml title="2. 图标"
favicon: assets/favicon.png # 使用 docs/assets/favicon.png 文件，作为网页图标
icon: 
    repo: fontawesome/brands/github # git仓库标识，好看的还有git-alt,github-alt
    annotation: material/arrow-right-circle # 拓展的注释功能的图标
    logo: material/notebook-outline # 左上角网页图标，此处选用一个笔记本标识

extra: #底部的图案，如github,qq,blog等
  social:
    - icon: fontawesome/brands/github
      link: https://github.com/Wu-wu-u
```

!!! warning inline end "并非都适用"
    这种方法只支持来自[Google Fonts](https://fonts.google.com/)的字体，特别的字体需要另外添加css文件（见后文）

``` yml title="3. 字体"
font:
    text: ...
    code: ...
```
```yml title="4. 基础拓展功能"
features:
    - toc.follow # 右侧目录随页面滑动

    # 使用 Tab 来进行分类
    # https://squidfunk.github.io/mkdocs-material/setup/setting-up-navigation/#navigation-tabs
    - navigation.tabs

    # 返回顶部的按钮，在上滑时出现
    # https://squidfunk.github.io/mkdocs-material/setup/setting-up-navigation/#back-to-top-button
    - navigation.top

    # 给每个 Tab 添加一个 index.md，且在点击 Tab 时打开
    # https://squidfunk.github.io/mkdocs-material/setup/setting-up-navigation/#section-index-pages-with-section-index-pages
    - navigation.indexes

    # 打开 Tab 时左侧目录全部展开
    # https://squidfunk.github.io/mkdocs-material/setup/setting-up-navigation/#navigation-expansion
    - navigation.expand

    # 可以通过按钮复制代码
    # https://squidfunk.github.io/mkdocs-material/reference/code-blocks/#code-copy-button
    - content.code.copy

    # 可以在代码块中内嵌注释
    # https://squidfunk.github.io/mkdocs-material/reference/code-blocks/#code-annotations
    - content.code.annotate

    # 搜索输入一些字母时推荐补全整个单词
    # https://squidfunk.github.io/mkdocs-material/setup/setting-up-site-search/#search-suggestions
    - search.suggest

    # 搜索的关键词文章加入高亮
    # https://squidfunk.github.io/mkdocs-material/setup/setting-up-site-search/#search-highlighting
    - search.highlight

```

### 字体的添加
- 将`theme`中的`font`设置为 `font: False`


```yml title="添加字体css文件"
extra_css:
    - https://cdn.tonycrane.cc/jbmono/jetbrainsmono.css
    - https://cdn.tonycrane.cc/lxgw/lxgwscreen.css
    # 这里用的是托管在tony cdn上的文件，挂了的话再去搜原文件进行本地添加
    - css/custom.css 
    # 添加自定义的css文件
```

---

```css title="在custom.css中设置字体关键字"
:root {
  --md-text-font: "JetBrains Mono", "LXGW WenKai Screen"; 
  --md-code-font: "JetBrains Mono"; # "Noto Serif SC" 
  # 前面是英文字体，后面是中文字体
}

```

### Extensions
- 详情见官方**Tutorial**

``` yml title="markdown_extensions"
markdown_extensions:
  - toc:
      permalink: true
      toc_depth: 5
  - admonition #应用admonition
  - pymdownx.highlight:
      anchor_linenums: true
      line_spans: __span
      pygments_lang_class: true
  - pymdownx.inlinehilite #添加了对内联代码块的语法突出显示的支持
  - pymdownx.snippets #使用简单语法将任意文件的内容嵌入到文档
  - pymdownx.superfences #允许代码和内容块任意嵌套，警告、选项卡、列表和所有其他元素
  - pymdownx.details #admonition可以折叠
  - attr_list #允许使用特殊语法将 HTML 属性和 CSS 类到几乎每个Markdown 内联和块级元素。
  - md_in_html
  - pymdownx.keys #添加了一个简单的语法来允许呈现键盘按键和组合
  # Caret 、 Mark和Tilde扩展添加了使用简单语法突出显本并定义下标和上标的功能。
  - pymdownx.caret
  - pymdownx.mark
  - pymdownx.tilde
  - pymdownx.critic #允许使用Critic 标记来突出显示文档添加、删除或更新的部分，即跟踪 Markdown 语法的更改。

   - pymdownx.emoji:
       emoji_index: !!python/name:material.extensions.emoji.twemoji
       emoji_generator: !!python/name:material.extensions.emoji.to_svg
   # 相关内容或者代码块可以分组展示
   - pymdownx.tabbed:
       alternate_style: true

   # 允许使用任务清单即- []
   - pymdownx.tasklist:
       custom_checkbox: true

   # 允许渲染公式，还需要添加mathjax配置和JavaScript
   # https://squidfunk.github.io/mkdocs-material/setup/extensions/python-markdown-extensions/#arithmatex
   - pymdownx.arithmatex:
       generic: true

   - def_list #使用各类表格
   - pymdownx.tasklist:
       custom_checkbox: true
   - meta
   - sane_lists
   - pymdownx.magiclink

```

??? warning "关于MathJax"
    - 添加mathjax时一定要按Tutorial中所述再额外添加配置文件和JavaScript文件

---

```yml title="plugin"
plugins: 
  - glightbox #图片放大
  - statistics: #统计页面字数、代码行数、阅读时间
    #https://github.com/TonyCrane/mkdocs-statistics-plugin
  - search
  - git-revision-date-localized

```

??? Warning
    - 其中glightbox,statistics,git-revision-date-localized需额外pip install
    
    ```bash
    pip install mkdocs-glightbox #图片放大拓展
    pip install mkdocs-statistics-plugin #数据统计
    pip install mkdocs-git-revision-date-localized-plugin #文章修改历史
    ```