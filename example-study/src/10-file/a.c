/**
 * 文件操作
 * https://www.runoob.com/cprogramming/c-file-io.html
 */


#include <stdio.h>

#define __FILENAME__ (strrchr(__FILE__, '/') ? (strrchr(__FILE__, '/') + 1):__FILE__)


 
int main()
{
   
   printf("%s\n",__FILE__);
   printf("%s\n",__FILENAME__);
   return 0;
 
   FILE *fp = NULL; 
   fp = fopen("test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
   return 0;
}