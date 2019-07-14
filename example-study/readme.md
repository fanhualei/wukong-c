# 例子说明

参考了[菜鸟C教程](https://www.runoob.com/cprogramming/c-tutorial.html)



## 知识关键点



### linux

后台执行：nohup和&的区别



### 关键字

> [参考文档](<https://www.runoob.com/cprogramming/c-basic-syntax.html>)

`extern`外部声明

`register`:寄存器

`signed`:有符号类型的函数或变量

`unsigned`:无符号

`short`:短类型

`sizeof`:计算长度

`struct`结构体

`typedef`:给变量起名字

`union`:声明共用体类型

`volatile`:在执行过程中变量会被隐形的改变



### 类型

> [参考文档](https://www.runoob.com/cprogramming/c-data-types.html)

一个字节占８位．

char:1字节

int:2或4字节，根据系统来定

long:4字节

float:4字节

double:8字节



### 常量

#### 整数常量

* 前缀
  * 0x 或 0X 表示十六进制
  * 0 表示八进制
* 后缀
  *  U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）

#### 浮点常量

浮点常量由`整数部分`、`小数点`、`小数部分`和指`数部分`组成．带符号的指数是用`e` 或 `E` 引入的

0.01 == 1E-2l

#### 字符常量

如何定义一个８进制或１６进制字符串？

### 运算符

位运算符：&  |  ^  ~ << >>

```
0^0=0;   
0^1=1;   
1^0=1;  
1^1=0;
```









### printf参数说明

```
详细如下
printf: 转换说明符
%a 浮点数、十六进制数字和p-计数法(C99)
%A 浮点数、十六进制数字和P-计数法(C99)
%c 一个字符
%d 有符号十进制整数
%e 浮点数、e-计数法
%E 浮点数、E-计数法
%f 浮点数、十进制计数法
%g 根据数值类型不同自动选择%f或%e。
%e 格式在指数小于-4或者大于等于精度时使用
%G 根据数值类型不同自动选择%f或%E。
%E 格式在指数小于-4或者大于等于精度时使用
%i 有符号十进制整数(与%d相同)
%o 无符号八进制整数
%p 指针
%s 字符串
%u 无符号十进制整数
%x 使用十六进制数字0f的无符号十六进制整数
%X 使用十六进制数字0F的无符号十六进制整数
%% 打印一个百分号
```



### 回调函数

将一个函数指针，作为一个参数传递到一个方法中，在这个方法中，调用这个函数．





### 位域

有些信息在存储时，并不需要占用一个完整的字节，而只需占几个或一个二进制位。例如在存放一个开关量时，只有 0 和 1 两种状态，用 1 位二进位即可。为了节省存储空间，并使处理简便，C 语言又提供了一种数据结构，称为"位域"或"位段"。

所谓"位域"是把一个字节中的二进位划分为几个不同的区域，并说明每个区域的位数。每个域有一个域名，允许在程序中按域名进行操作。这样就可以把几个不同的对象用一个字节的二进制位域来表示。

典型的实例：

- 用 1 位二进位存放一个开关量时，只有 0 和 1 两种状态。
- 读取外部文件格式——可以读取非标准的文件格式。例如：9 位的整数。

```c
struct bs{
    int a:8;
    int b:2;
    int c:6;
}data;
```



### 输入输出

* printf & scanf
* getchar & putchar
* gets & puts

scanf更高级

```c
#include <stdio.h>
int main( ) {
 
   char str[100];
   int i;
 
   printf( "Enter a value :");
   scanf("%s %d", str, &i);
 
   printf( "\nYou entered: %s %d ", str, i);
   printf("\n");
   return 0;
}

```



### 文件操作

* fopen(name mode)
* fclose(fp)
* fputc & fgetc
* fputs & fgets
* fscanf
* fprintf



### 字符串

> 参考文档

* [字符串知识](https://wenku.baidu.com/view/c45ab62b68eae009581b6bd97f1922791688be92.html)

