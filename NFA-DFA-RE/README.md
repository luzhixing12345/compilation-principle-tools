# NFA-DFA-RE 表达式推导转换

该段程序实现了NFA转DFA, DFA最小状态自动机, RE转DFA

TODO: RE

## 编译

```bash
cd NFA-DFA-RE
make
```

## 使用方法

这一部分涉及到画图,所以说单纯的使用命令行并不可能满足我的画图需求,这里我使用的是一个画图的库.

在[Graphviz](http://graphviz.org/download/)官网下载,我使用的是[win10-64位](https://github.com/luzhixing12345/compilation-principle/releases/download/v0.0.2/windows_10_cmake_Release_graphviz-install-3.0.0-win64.exe),安装后将目录加入环境变量path中

开启终端,输入如下指令测试,如果单纯换行没有反应那么证明安装成功

```bash
dot
```

- RE -> NFA

  ```bash
  main {RE}
  ```

  这里的RE表达式仅支持

  - 数字/字符
  - ( )
  - \*
  - |

  > 小玩具,RE表达式那么丰富想要做全可有点太费劲了,搞一搞基本的就可以了

我在该文件夹下提供了一个示例文件 `grammar.txt`,执行

```bash
main grammar.txt
```

