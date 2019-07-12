# C 开发



## 第一章 开发环境



###第一步：安装vscode

直接去官网上查．

### 第二步：新建工程

```
１：新建一个目录，用vscode打开这个目录．[Add Folder to Workspace]
２：然后建立两个目录：src与bin
３：在src目录下建立一个hello.c文件
４：配置.vscode目录下的三个文件
	4.1：c_cpp_properties.json不用修改
	4.2：修改tasks.json，追加一个task
	4.3：修改Launch.json，追加一个launch
５：打开hello.c并且点击debug，选择新建的launch［编译并且执行］来执行数据
```





### 附件

> hello.c

```c
#include <stdio.h>

int main()
{
    int n;
    printf("This is a test file!\r\nInput a number: ");
    scanf("%d",&n);
    printf("The number is %d",n);
    return 0;
}
```



> 追加一个tasks

将默认的tasks复制一份，然后修改了args，添加了`${workspaceFolder}/bin/`将文件复制到bin目录

```json
        {
            "type": "shell",
            "label": "wukong-build",
            "command": "/usr/bin/gcc",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${workspaceFolder}/bin/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "/usr/bin"
            }
        },
```



> 追加一个launch

复制原有的，并修改。修改了`program`的执行地址，修改了`preLaunchTask`的`task`名。

```json
        {
            "name": "编译并且执行",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/bin/${fileBasenameNoExtension}",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "wukong-build",
            "miDebuggerPath": "/usr/bin/gdb"
        }
```





###插件安装

* 安装`IntelliJ IDEA Keybindings`，这样就可以使用`idea`快捷键的习惯了
  * 在左下角的一个工具图标，中有个菜单`keymaps`，可以选择安装idea快捷键
* 安装c的编译器，这个在使用工程中，系统会自动提示添加。
* [C/C++ Project Generator]



/etc/ld.so.conf

```shell
gcc   /home/fan/001-ffmpeg/code/hello-ffmpeg/src/ffmpeg.c -o /home/fan/001-ffmpeg/code/hello-ffmpeg/bin/ffmpeg -I /usr/local/include -L /usr/local/lib -l avformat -l avcodec -l avfilter -l avutil -l swresample -l swscale



gcc   /home/fan/001-ffmpeg/code/hello-ffmpeg/src/ffmpeg.c  -I /home/fan/001-ffmpeg/FFmpeg-n3.4.6 -L /home/fan/001-ffmpeg/FFmpeg-n3.4.6 -l avformat -l avcodec -l avfilter -l avutil -l swresample -l swscale   -o /home/fan/001-ffmpeg/code/hello-ffmpeg/bin/ffmpeg



```





## 第二章 知识准备

本章主要内容是了解`gcc`的编译

### 基本知识

参考文档：

* [C语言基础篇（零）gcc编译和预处理](https://www.cnblogs.com/kmist/p/9865382.html)
* [C语言函数篇（五）静态库和动态库的创建和使用](https://www.cnblogs.com/kmist/p/10088585.html)
* [准备篇（二）C语言-这个是总体的目录](https://www.cnblogs.com/kmist/p/9865363.html)



### 如何获得第三方库

>我知道了一个第三方库，通过什么命令，能知道这个库的引用呢？

```shell
# pkg-config　库名 --libs --cflage ,例如我想得到我机器的上ffmpeg的头文件与库，我可以这么来做．

pkg-config --cflags libavdevice                        \
                libavformat                        \
                libavfilter                        \
                libavcodec                         \
                libswresample                      \
                libswscale                         \
                libavutil                          \

# 上面输出　-I/usr/local/include

pkg-config --libs libavdevice                        \
                libavformat                        \
                libavfilter                        \
                libavcodec                         \
                libswresample                      \
                libswscale                         \
                libavutil                          \

# 上面输出：-L/usr/local/lib -lavdevice -lm -ldl -lz -pthread -lavfilter -lm -ldl -lz -pthread -lavformat -lm -ldl -lz -pthread -lavcodec -lm -ldl -lz -pthread -lswresample -lm -lswscale -lm -lavutil -lm

# 这就是第三方库在进行gcc时用的内容了
```

参考文档:

* [pkg-config的使用方法](https://jingyan.baidu.com/article/a681b0de684c2e3b184346f2.html)



### MAKEFILE的使用

> 常用的命令

```shell
# 定义变量，两种方法
CC=gcc
CC:=gcc

# 变量替换:替换成fun1.o fun2.o fun3.o
SRCS=fun1.c fun2.c fun3.c
OBJS=$(SRCS:.c=.o)

# 变量追加: C=-Wall -O2
C=-Wall
C+=-O2

# 引用变量
$(CC)

# 输出
＠echo

#　清空命令
rm　-rf ***

# 预先定义变量
CC:编译器类型
CFLAGS:编译选项，通常为-O2 -Wall -I -L
LDFLAGS:外部库
EXEC或APP:应用程序名
SRCS:源代码
OBJS:目标代码，一般是中间文件

#最有用的变量
$@ 目标文件
$^ 所有的依赖文件
$< 第一个依赖文件

#GCC 编译的参数
-Wall选项意思是编译后显示所有警告
-W选项类似-Wall，会显示警告，但是只显示编译器认为会出现错误的警告。
-w的意思是关闭编译时的警告
-Wextra 忘记参数类型  指针与整数零的逻辑比较 这个是报告一些编译错误
```





> 参考文档

* [makefile菜鸟入门](https://blog.csdn.net/shuizhizhiyin/article/details/51242406)

* [十分种学会](https://wenku.baidu.com/view/205e5e12eff9aef8941e0678.html)

* [区别gcc中的-w -W和-Wall选项](https://blog.csdn.net/cjtstrive/article/details/85375477)
* [Makefile中的-Wall -O2 -Os -g等选项介绍](https://blog.csdn.net/shenhuan1104/article/details/76861029)
* [gcc Wextra参数的作用](https://blog.csdn.net/robertsong2004/article/details/52473818)
* [GCC编译器（Linux gcc命令）30分钟入门教程](http://c.biancheng.net/gcc/)
* [C语言教程](http://c.biancheng.net/c/)



## 第三章 搭建开发环境

通过不同的开发环境，掌握不同makefile的制作技巧

### 3.1 单一APP形式

如何制作一个`makefile`文件，并结合`vscode`进行调试









