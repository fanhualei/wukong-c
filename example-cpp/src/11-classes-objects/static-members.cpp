/**
 * https://www.runoob.com/cplusplus/cpp-static-members.html
 * C++ 类的静态成员
 *  我们可以使用 static 关键字来把类成员定义为静态的。
 *  当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。
 *  静态成员在类的所有对象中是共享的。
 *  如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。
 *  我们不能把静态成员的初始化放置在类的定义中，
 *  但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化
 * 
 * 静态成员函数
 *  如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。
 *  静态成员函数即使在类对象不存在的情况下也能被调用，静态函数只要使用类名加范围解析运算符 :: 就可以访问。
 *  静态成员函数只能访问静态成员数据、其他静态成员函数和类外部的其他函数。
 *  静态成员函数有一个类范围，他们不能访问类的 this 指针。您可以使用静态成员函数来判断类的某些对象是否已被创建。
 * 
 */

#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
         // 每次创建对象时增加 1
         objectCount++;
      }
      double Volume()
      {
         return length * breadth * height;
      }
      static int getCount()
      {
         return objectCount;
      }
   private:
      double length;     // 长度
      double breadth;    // 宽度
      double height;     // 高度
      static int objectCount; //在实际的例子中，这个成员被设置成public
};
 
// 初始化类 Box 的静态成员
int Box::objectCount = 0;
 
int main(void)
{
  
   // 在创建对象之前输出对象的总数
   cout << "Inital Stage Count: " << Box::getCount() << endl;
 
   Box Box1(3.3, 1.2, 1.5);    // 声明 box1
   Box Box2(8.5, 6.0, 2.0);    // 声明 box2
 
   // 在创建对象之后输出对象的总数
   cout << "Final Stage Count: " << Box::getCount() << endl;
 
   return 0;
}