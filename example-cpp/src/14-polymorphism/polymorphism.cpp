/**
 * C++ 多态
 *  https://www.runoob.com/cplusplus/cpp-polymorphism.html
 *  多态按字面的意思就是多种形态。
 *  当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。
 *  C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。
 *  下面的实例中，基类 Shape 被派生为两个类，如下所示：
 * 
 * 虚函数
 *  虚函数 是在基类中使用关键字 virtual 声明的函数。
 *  在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。
 *  我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定。
 * 
 * 纯虚函数
 *  您可能想要在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象
 *  但是您在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。
 *  将下面的代码写成这样子：virtual int area() = 0;
 * 
 */


#include <iostream> 
using namespace std;
 
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      virtual int area()
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }
};
class Rectangle: public Shape{
   public:
      Rectangle( int a=0, int b=0):Shape(a, b) { }
      int area ()
      { 
         cout << "Rectangle class area :" <<endl;
         return (width * height); 
      }
};
class Triangle: public Shape{
   public:
      Triangle( int a=0, int b=0):Shape(a, b) { }
      int area ()
      { 
         cout << "Triangle class area :" <<endl;
         return (width * height / 2); 
      }
};
// 程序的主函数
int main( )
{
   Shape *shape;
   Rectangle rec(10,7);
   Triangle  tri(10,5);
 
   // 存储矩形的地址
   shape = &rec;
   // 调用矩形的求面积函数 area
   shape->area();
 
   // 存储三角形的地址
   shape = &tri;
   // 调用三角形的求面积函数 area
   shape->area();
   
   return 0;
}