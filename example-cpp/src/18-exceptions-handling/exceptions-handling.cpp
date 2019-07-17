/**
 * C++ 异常处理
 *  异常是程序在执行期间产生的问题。
 *  C++ 异常是指在程序运行时发生的特殊情况，比如尝试除以零的操作。异常提供了一种转移程序控制权的方式。
 *  C++ 异常处理涉及到三个关键字：try、catch、throw。
 * 
 * 抛出异常
 *  您可以使用 throw 语句在代码块中的任何地方抛出异常。
 *  throw 语句的操作数可以是任意的表达式，表达式的结果的类型决定了抛出的异常的类型。
 * 
 * 捕获异常
 *  catch 块跟在 try 块后面，用于捕获异常。
 *  如果您想让 catch 块能够处理 try 块抛出的任何类型的异常，
 *  则必须在异常声明的括号内使用省略号 ...
 * 
 * 
 */


// 由于我们抛出了一个类型为 const char* 的异常，因此，当捕获该异常时，
// 我们必须在 catch 块中使用 const char*。当上面的代码被编译和执行时，它会产生下列结果：

#include <iostream>
using namespace std;
 
double division(int a, int b)
{
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}
 
int main ()
{
   int x = 50;
   int y = 0;
   double z = 0;
 
   try {
     z = division(x, y);
     cout << z << endl;
   }catch (const char* msg) {
     cerr << msg << endl;
   }
 
   return 0;
}