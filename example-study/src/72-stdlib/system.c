#include <stdio.h>
#include <string.h>
#include<stdlib.h>
 
int main ()
{
   char command[50];
 
   strcpy( command, "ls -l" );
   system(command);
 
   return(0);
}