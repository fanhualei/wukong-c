#include <stdio.h>
#include <stdlib.h>

int main()
{
   char str[30] = "2030300123456";
   char *ptr;
   long ret;

   ret = strtol(str, &ptr, 10);
   printf("数字（无符号长整数）是 %ld\n", ret);
   printf("字符串部分是 |%s|", ptr);

   return(0);
}