/**
 * C++ 数据抽象
 *  https://www.runoob.com/cplusplus/cpp-data-abstraction.html
 *  数据抽象是指，只向外界提供关键信息，并隐藏其后台的实现细节，即只表现必要的信息而不呈现细节。
 *  数据抽象是一种依赖于接口和实现分离的编程（设计）技术。
 * 
 * 数据抽象的实例
 *  C++ 程序中，任何带有公有和私有成员的类都可以作为数据抽象的实例。请看下面的实例：
 *  类把数字相加，并返回总和。公有成员 addNum 和 getTotal 是对外的接口，用户需要知道它们以便使用类。私有成员 total 是用户不需要了解的，但又是类能正常工作所必需的。
 */

#include <iostream>
using namespace std;
 
class Adder{
   public:
      // 构造函数
      Adder(int i = 0)
      {
        total = i;
      }
      // 对外的接口
      void addNum(int number)
      {
          total += number;
      }
      // 对外的接口
      int getTotal()
      {
          return total;
      };
   private:
      // 对外隐藏的数据
      int total;
};
int main( )
{
   Adder a;
   
   a.addNum(10);
   a.addNum(20);
   a.addNum(30);
 
   cout << "Total " << a.getTotal() <<endl;
   return 0;
}