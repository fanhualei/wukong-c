/**
 * 如果一个类将()运算符重载为成员函数，这个类就称为函数对象类，这个类的对象就是函数对象。
 * 函数对象是一个对象，但是使用的形式看起来像函数调用，实际上也执行了函数调用，因而得名。
 * 
 * 
    template <class_Tp>
    struct less
    {
        bool operator() (const_Tp & __x, const_Tp & __y) const
        { return __x < __y; }
    };
 */

#include <iostream>
using namespace std;
class CAverage
{
public:
    double operator()(int a1, int a2, int a3)
    {  //重载()运算符
        return (double)(a1 + a2 + a3) / 3;
    }
};
int main()
{
    CAverage average;  //能够求三个整数平均数的函数对象
    cout << average(3, 2, 3);  //等价于 cout << average.operator(3, 2, 3);
    return 0;
}