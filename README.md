# 编译原理小工具

![C++](https://img.shields.io/badge/C++-Solutions-blue.svg?style=flat&logo=c%2B%2B)
![GitHub last commit](https://img.shields.io/github/last-commit/luzhixing12345/compilation-principle-tools)
[![GitHub license](https://img.shields.io/github/license/luzhixing12345/compilation-principle-tools)](https://github.com/luzhixing12345/compilation-principle-tools/blob/main/LICENSE)

## 前言

虽然小镇做题家,但无论如何太理论的东西总是令人恼火的.鉴于算法并不是那么复杂,所以有了写一下这个想法

- 如果你是想依靠这个工具完成作业,那么我建议三思
- 如果你是想看一看代码怎么写的,那我非常欢迎.
- 如果你是想对比学习一下/体验感受一下,那我非常欢迎. 我目前还没有测试出现什么问题,如果你发现了哪里的程序计算有问题,那估计是我写了bug,请留Issue,我会尽快修复.(如果你愿意提PR我也非常感谢)

## 实现的算法

### [NFA-DFA-RE](NFA-DFA-RE/README.md) NOT FINISHED YET

### [求解FIRST集-FOLLOW集-SELECT集](FIRST-FOLLOW-SELECT/README.md)

### [求解LL1文法](LL1/README.md)

### [求解LR0-SLR1文法](LR0-SLR1/README.md) NOT FINISHED YET

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

以上内容集成在了一个QT的程序中,关于这部分的代码见[QT分支](https://github.com/luzhixing12345/compilation-principle-tools/tree/QT)
