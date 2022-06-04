# 求FIRST FOLLOW SELECT集

关于如何计算 求FIRST FOLLOW SELECT集的知识我整理在 [我的博客-编译原理](https://luzhixing12345.github.io/tags/%E7%BC%96%E8%AF%91%E5%8E%9F%E7%90%86/)上, 如果你对这部分知识尚不清楚可以去看一下

一些代码实现时的细节我也补充在注释里了, 有兴趣的话可以参考

## 编译

```bash
cd FIRST-FOLLOW-SELECT
make
```

## 使用方法

我在该文件夹下提供了一个示例文件 `grammar.txt`,执行

```bash
main grammar.txt
```

```txt
---------------------
SUCCESS to calculate ffs set
---------------------
---------------------
FIRST SET: 
T: , e 
L: ( a 
S: ( a 
---------------------
FOLLOW SET: 
T: ) 
L: ) 
S: $ ) , 
---------------------
SELECT SET: 
S -> (L)  : ( 
S -> a    : a 
L -> ST   : ( a 
T -> ,ST  : ,
T -> e    : )
```

编写 `grammar.txt` 时需要注意以下几点:

- 默认第一行第一个字符是文法的起始字符
- 由于空 $\epsilon$ 并不便于直接打出来,所以我使用了字符 `e` 作为等价替换
- 一些特殊字符,比如 $\neg$ , $\rightarrow$ 字符是不支持的,会出现中文乱码,请使用其他字符等效替换

- 不支持 `S'`这种写法,不支持多字符的终结符/非终结符表示如 `id`,`expr`,请使用单个字符如 `P`,`a`

  > 不然处理起来太麻烦了...
  
- 空格和空行我在程序中有做处理,`A -> (B)`与 `A-> ( B )`是等效的,无需担心

  > 只要不在 `->`中间加空格都无所谓

比如我想要求得的文法是

```txt
D -> TL
T -> int | char
L -> *L | L[] | L() | (L) |id
```

我可以写作如 `test.txt`中的形式, 执行 `main.exe test.txt`

```txt
D -> TL
T -> a | b
L -> *L | L[]|L()|(L)|c
```

结果为

```txt
---------------------
SUCCESS to calculate ffs set
---------------------
---------------------
FIRST SET:
D: a b
L: ( * c
T: a b
---------------------
FOLLOW SET:
L: $ ( ) [
T: $ ( * c
D: $
---------------------
SELECT SET:
D -> TL   : a b
T -> a    : a
T -> b    : b
L -> *L   : *
L -> L[]  : ( * c
L -> L()  : ( * c 
L -> (L)  : (
L -> c    : c
```
