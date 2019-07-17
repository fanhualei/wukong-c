/**
 * C++ 动态内存
 * https://www.runoob.com/cplusplus/cpp-dynamic-memory.html
 * 了解动态内存在 C++ 中是如何工作的是成为一名合格的 C++ 程序员必不可少的。
 * C++ 程序中的内存分为两个部分：
 *  栈：在函数内部声明的所有变量都将占用栈内存。
 *  堆：这是程序中未使用的内存，在程序运行时可用于动态分配内存。所以堆里面的要删除
 * 
 * 很多时候，您无法提前预知需要多少内存来存储某个定义变量中的特定信息，所需内存的大小需要在运行时才能确定。
 * 在 C++ 中，您可以使用特殊的运算符为给定类型的变量在运行时分配堆内的内存，这会返回所分配的空间地址。
 * 这种运算符即 new 运算符。
 * 如果您不再需要动态分配的内存空间，可以使用 delete 运算符，删除之前由 new 运算符分配的内存。
 * 
 * 
 */

#include <iostream>
using namespace std;

class Box
{
public:
    Box()
    {
        cout << "调用构造函数！" << endl;
    }
    ~Box()
    {
        cout << "调用析构函数！" << endl;
    }
};

int main()
{
    int **p;
    int i, j; //p[4][8]
    //开始分配4行8列的二维数据
    p = new int *[4];
    for (i = 0; i < 4; i++)
    {
        p[i] = new int[8];
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 8; j++)
        {
            p[i][j] = j * i;
        }
    }
    //打印数据
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (j == 0)
                cout << endl;
            cout << p[i][j] << "\t";
        }
    }
    //开始释放申请的堆
    for (i = 0; i < 4; i++)
    {
        delete[] p[i];
    }
    delete[] p;

    // 对象的动态内存分配
    Box *myBoxArray = new Box[4];

    delete[] myBoxArray; // 删除数组

    return 0;
}