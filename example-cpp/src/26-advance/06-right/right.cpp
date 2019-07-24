/**
 * C++11右值引用详解
 * http://c.biancheng.net/view/439.html
 * 能出现在赋值号左边的表达式称为“左值”，不能出现在赋值号左边的表达式称为“右值”。
 * 一般来说，左值是可以取地址的，右值则不可以。
 * 非 const 的变量都是左值。
 * 
 * 可以引用右值，因而称为“右值引用”。无名的临时变量不能出现在赋值号左边，因而是右值。右值引用就可以引用无名的临时变量。
 * 类型 && 引用名 = 右值表达式;
 * 
 * 
 * 引入右值引用的主要目的是提高程序运行的效率。有些对象在复制时需要进行深复制，深复制往往非常耗时。合理使用右值引用可以避免没有必要的深复制操作。例如下面的程序：
 */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class String
{
public:
    char *str;
    String() : str(new char[1]) { str[0] = 0; }
    String(const char *s)
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    String(const String &s)
    { //复制构造函数
        cout << "copy constructor called" << endl;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    String &operator=(const String &s)
    { //复制赋值号
        cout << "copy operator = called" << endl;
        if (str != s.str)
        {
            delete[] str;
            str = new char[strlen(s.str) + 1];
            strcpy(str, s.str);
        }
        return *this;
    }
    String(String &&s) : str(s.str)
    { //移动构造函数
        cout << "move constructor called" << endl;
        s.str = new char[1];
        s.str[0] = 0;
    }
    String &operator=(String &&s)
    { //移动赋值号
        cout << "move operator = called" << endl;
        if (str != s.str)
        {
            str = s.str;
            s.str = new char[1];
            s.str[0] = 0;
        }
        return *this;
    }
    ~String() { delete[] str; }
};
template <class T>
void MoveSwap(T &a, T &b)
{
    T tmp(move(a)); //std::move(a) 为右值，这里会调用移动构造函数
    a = move(b);    //move(b) 为右值，因此这里会调用移动赋值号
    b = move(tmp);  //move(tmp) 为右值，因此这里会调用移动赋值号
}
int main()
{
    String s;
    s = String("this"); //调用移动赋值号
    cout << "* * * *" << endl;
    cout << s.str << endl;
    String s1 = "hello", s2 = "world";
    MoveSwap(s1, s2); //调用一次移动构造函数和两次移动赋值号
    cout << s2.str << endl;
    return 0;
}