#include <stdio.h>

int main()
{
   char buf[BUFSIZ];

   setbuf(stdout, buf);
   puts("This is runoob");
   puts("你好呀");

   fflush(stdout);
   return(0);
}