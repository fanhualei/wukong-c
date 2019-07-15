#include <stdio.h>
#include <ctype.h>

int main()
{
   char var1[] = "tuts";
   char var2[] = "0xE";
  
   if( isxdigit(var1[0]) )
   {
     printf("var1 = |%s| 是十六进制数字\n", var1 );
   }
   else
   {
     printf("var1 = |%s| 不是十六进制数字\n", var1 );
   }
   
   if( isxdigit(var2[0] ))
   {
     printf("var2 = |%s| 是十六进制数字\n", var2 );
   }
   else
   {
     printf("var2 = |%s| 不是十六进制数字\n", var2 );
   }
   
   return(0);
}