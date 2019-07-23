/**
 * const_cast
 * const_cast 运算符仅用于进行去除 const 属性的转换，它也是四个强制类型转换运算符中唯一能够去除 const 属性的运算符。
 * 
 */

#include <iostream>
using namespace std;

int main()
{
    const string s = "Inception你好";
    string &p = const_cast<string &>(s);
    string *ps = const_cast<string *>(&s); // &s 的类型是 const string*
    cout<< p << endl;
    cout<< ps << endl;
    cout<< *ps << endl;
}