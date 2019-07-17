/**
 * C++ 把引用作为返回值
 * 通过使用引用来替代指针，会使 C++ 程序更容易阅读和维护。
 * C++ 函数可以返回一个引用，方式与返回一个指针类似。
 * 当函数返回一个引用时，则返回一个指向返回值的隐式指针。
 * 这样，函数就可以放在赋值语句的左边。例如，请看下面这个简单的程序：
 * 
 * 当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。
 */


#include <iostream>
 
using namespace std;
 
double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
 
double& setValues( int i )
{
  return vals[i];   // 返回第 i 个元素的引用
}
 
// 要调用上面定义函数的主函数
int main ()
{
 
   cout << "改变前的值" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
 
   setValues(1) = 20.23; // 改变第 2 个元素
   setValues(3) = 70.8;  // 改变第 4 个元素
 
   cout << "改变后的值" << endl;
   for ( int i = 0; i < 5; i++ )
   {
       cout << "vals[" << i << "] = ";
       cout << vals[i] << endl;
   }
   return 0;
}