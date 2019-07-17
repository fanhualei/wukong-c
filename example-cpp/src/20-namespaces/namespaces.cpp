/**
 * C++ 命名空间
 * 作为附加信息来区分不同库中相同名称的函数、类、变量等。使用了命名空间即定义了上下文。
 * 本质上，命名空间就是定义了一个范围。
 * https://www.runoob.com/cplusplus/cpp-namespaces.html
 * 
 */

#include <iostream>
using namespace std;
 
// 第一个命名空间
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}
// 第二个命名空间
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}
int main ()
{
 
   // 调用第一个命名空间中的函数
   first_space::func();
   
   // 调用第二个命名空间中的函数
   second_space::func(); 
 
   return 0;
}