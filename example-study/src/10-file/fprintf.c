#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE * fp;

   fp = fopen ("file.txt", "w+");
   fprintf(fp, "%s %s %s %d %p", "We", "are", "in", 2014,fp);
   
   fclose(fp);
   
   return(0);
}