# 编译原理小工具

![C++](https://img.shields.io/badge/C++-Solutions-blue.svg?style=flat&logo=c%2B%2B)
![GitHub last commit](https://img.shields.io/github/last-commit/luzhixing12345/compilation-principle-tools)
[![GitHub license](https://img.shields.io/github/license/luzhixing12345/compilation-principle-tools)](https://github.com/luzhixing12345/compilation-principle-tools/blob/main/LICENSE)

## 前言

虽然小镇做题家,但无论如何太理论的东西总是令人恼火的.鉴于算法并不是那么复杂,所以有了写一下这个想法

- 如果你是想依靠这个工具完成作业,那么我建议三思
- 如果你是想看一看代码怎么写的,那我非常欢迎.
- 如果你是想对比学习一下/体验感受一下,那我非常欢迎.

我目前还没有测试出现什么问题,如果你发现了哪里的程序计算有问题,那估计是我写了bug,请留Issue,我会尽快修复.(如果你愿意提PR我也非常感谢)

## 实现的算法

> 部分还未实现/有bug未改正的算法使用 `#` 标记

- [NFA-DFA-RE](NFA-DFA-RE/README.md) #
- [FIRST集-FOLLOW集-SELECT集](FIRST-FOLLOW-SELECT/README.md)
- [LL1](LL1/README.md)
- [LR0-SLR1](LR0-SLR1/README.md) #
- [LR1]() #
- [SSD]() #

## 关于

### 关于算法

本仓库的代码实现是基于已掌握的编译原理知识进行实现的,如果对这部分尚不熟悉可以参考[我的博客](https://luzhixing12345.github.io/tags/%E7%BC%96%E8%AF%91%E5%8E%9F%E7%90%86/)

### 关于编译

每一个文件夹是一个独立的算法,部分算法之间存在重叠,比如SLR1算法也需要计算first/follow集所以需要调用FIRST-FOLLOW-SELECT中的文件

由于各部分算法关联性不大,所以并未统一编译为一个exe文件而是各文件夹内分别编译,编译方法见makefile文件(各部分README里也有提及)

如果你不想手动编译也可以下载下方我编译过的可执行程序

### 关于文件结构

根目录下的`utils.hpp`是基本的方法和宏定义

各文件夹内部也都是对应的模块,文件夹内部的`utils.hpp`为该算法的基本数据结构定义

`grammar.txt`为一个测试文件,你可以直接使用这个文件查看输出结果,也可以替换其中的内容为题目的文法.文法的书写注意事项见对应部分的README

具体算法都是hpp头文件和cpp实现对应,一些位置也写了注释,如需阅读请自行理解

### 关于测试用例

每一个对应算法文件夹下有相应的 `grammar.txt`文件可以直接运行测试

`testfiles`目录下的文件夹包含了一些测试用例,对应武汉大学期末考试题目的例子,详见[武汉大学编译原理课程复习](https://github.com/luzhixing12345/WHU-compilation-principle)

所有的测试用例在本项目中均未提供参考答案,笔者自行手算和试题参考答案对照无误进行测试,暂未发现异常情况

可以使用类似如下的方式测试`testfiles`文件夹中的测试数据

```bash
LL1\\main testfiles\\2012\\ffs.txt
```

## 可执行文件下载

> 以下可执行程序使用 `gcc/x86_64-w64-mingw32/8.1.0` 编译,可以在windows平台执行

这部分写完之后一起传上来

<!-- |算法|exe|
|:--:|:--:|
|NFA-DFA-RE|[download]()|
|FIRST集-FOLLOW集-SELECT集|[download](https://github.com/luzhixing12345/compilation-principle-tools/releases/download/v0.0.1/ffs.exe)|
|LL1|[download](https://github.com/luzhixing12345/compilation-principle-tools/releases/download/v0.0.1/ll1.exe)|
|LR0|[download]()| -->

编写一个测试文件,然后运行. 关于测试文件的写法见对应部分的README

```bash
{EXE_NAME} {FILE_NAME}
# ffs grammar.txt
```

## TODO: QT程序集成

以上内容集成在了一个QT的程序中,关于这部分的代码见[QT分支](https://github.com/luzhixing12345/compilation-principle-tools/tree/QT)
