# C++ 学习

`c`与`c++`是想通的，学完`c`后，顺便抽空把`c++`也给过了．

其中参考了

* [菜鸟c++](https://www.runoob.com/cplusplus/cpp-tutorial.html)
* [c++中文网教程](http://c.biancheng.net/cplus/)
* [c++ stl库快速入门](http://c.biancheng.net/stl/)



## 环境配置

学习c与c++不建议使用高级的编辑器，用一个文本编辑器或者`vscode`就行，这样能了解这种语言的基本特性．

> 建立目录

建立一个`src`目录，然后按照章节来写练习程序

> 建立一个tasks.json

这里使用了`g++`来编译，同时使用了`-Wall`来输出所有的警告，编译的文件后缀是`out`，放在本地目录．

```json
{
    "tasks": [
        {
            "type": "shell",
            "label": "g++ build active file",
            "command": "/usr/bin/g++",
            "args": [
                "-g",
                "-Wall",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.out"
            ],
            "options": {
                "cwd": "/usr/bin"
            }
        }
    ],
    "version": "2.0.0"
}
```



> 建立一个launch.json

调用刚才建立的`tasks.json`，并且可以进行`debug`

```json
// Use IntelliSense to learn about possible attributes.
// Hover to view descriptions of existing attributes.
// For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
{

    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.out",
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
            "preLaunchTask": "g++ build active file"
        }
    ]
}
```



> g++的编译

-Wall 生成所有警告　-w 不生成警告　-c生成编译文件





