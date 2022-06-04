# 编译原理小工具

![C++](https://img.shields.io/badge/C++-Solutions-blue.svg?style=flat&logo=c%2B%2B)
![GitHub last commit](https://img.shields.io/github/last-commit/luzhixing12345/compilation-principle-tools)
[![GitHub license](https://img.shields.io/github/license/luzhixing12345/compilation-principle-tools)](https://github.com/luzhixing12345/compilation-principle-tools/blob/main/LICENSE)

本项目为编译原理的学习过程,作为大三下学期的一门专业课我并没有听懂老师讲课,所以打算自学.在学习过程中写的一些编译原理的算法

## 功能

### [NFA-DFA-RE](NFA-DFA-RE/README.md) NOT FINISHED YET

### [求解FIRST集-FOLLOW集-SELECT集](FIRST-FOLLOW-SELECT/README.md)

### [求解LL1文法](LL1/README.md)

### [求解LR0 SLR1文法](LR0/README.md) NOT FINISHED YET

## 可执行文件下载

|功能模块|exe|
|:--:|:--:|
|NFA-DFA-RE|[download]()|
|FIRST集-FOLLOW集-SELECT集|[download](https://github.com/luzhixing12345/compilation-principle-tools/releases/download/v0.0.1/ffs.exe)|
|LL1|[download](https://github.com/luzhixing12345/compilation-principle-tools/releases/download/v0.0.1/ll1.exe)|
|LR0|[download]()|

编写一个测试文件,然后运行. 关于测试文件的写法见对应部分的README

```bash
{EXE_NAME} {TXT_NAME}
# ffs grammar.txt
```

## TODO: QT程序集成

以上内容集成在了一个QT的程序中,关于这部分的代码见[branch-QT](https://github.com/luzhixing12345/compilation-principle-tools/tree/QT)
