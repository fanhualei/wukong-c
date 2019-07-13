/**
 * 定义常量
 * 在 C 中，有两种简单的定义常量的方式：
 * 使用 #define 预处理器。
 * 使用 const 关键字。
 * https://www.runoob.com/cprogramming/c-constants.html
 */

#include <stdio.h>
 
#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'
 
int main()
{
 
   int area;  
   
   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);
 
   return 0;
}