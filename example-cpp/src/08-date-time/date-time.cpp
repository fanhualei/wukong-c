/**
 * C++ 日期 & 时间
 * C++ 标准库没有提供所谓的日期类型。
 * C++ 继承了 C 语言用于日期和时间操作的结构和函数。
 * 为了使用日期和时间相关的函数和结构，需要在 C++ 程序中引用 <ctime> 头文件。
 */



#include <iostream>
#include <ctime>
 
using namespace std;
 
int main( )
{
   // 基于当前系统的当前日期/时间
   time_t now = time(0);
   
   // 把 now 转换为字符串形式
   char* dt = ctime(&now);
 
   cout << "本地日期和时间：" << dt << endl;
 
   // 把 now 转换为 tm 结构
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "UTC 日期和时间："<< dt << endl;
}