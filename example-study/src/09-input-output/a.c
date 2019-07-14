/**
 * 函数从标准输入流 stdin 读取输入，并根据提供的 format 来浏览输入。
 * https://www.runoob.com/cprogramming/c-input-output.html
 */

#include <stdio.h>
int main( ) {
 
   char str[100];
   int i;
 
   printf( "Enter a value :");
   scanf("%s %d", str, &i);
 
   printf( "\nYou entered: %s %d ", str, i);
   printf("\n");
   return 0;
}