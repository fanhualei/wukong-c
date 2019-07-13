/**
 * https://www.runoob.com/cprogramming/c-data-types.html
 * 一个字节8个二进制
 * 一个整型4个字节，32个二进制　　１　２　４　８　１６　３２　６４　１２８　
 * １１１１１１１１＝　　　　　　　
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>
 
int main()
{
   printf("char 存储大小 : %lu \n", sizeof(char));
   printf("int 存储大小 : %lu \n", sizeof(int));
   printf("float 存储最大字节数 : %d \n", sizeof(float));
   printf("float 最小值: %E\n", FLT_MIN );
   printf("float 最大值: %E\n", FLT_MAX );
   printf("精度值: %d\n", FLT_DIG );

   printf("最大的字节数 : %lu \n", (1+2+4+8+16+32+64+128));
   
   return 0;
}