#include <iostream>
#include <cmath>
using namespace std;
 
int main ()
{
   // 数字定义
   short  s = 10;
   int    i = -1000;
   long   l = 100000;
   float  f = 230.47;
   double d = 200.374;
 
   // 数学运算
   cout << "sin(d)   \t:" << sin(d) << endl;
   cout << "abs(i)   \t:" << abs(i) << endl;
   cout << "floor(d) \t:" << floor(d) << endl;
   cout << "sqrt(f) \t:" << sqrt(f) << endl;
   cout << "pow( d, 2) \t:" << pow(d, 2) << endl;
 
   return 0;
}