#include <stdio.h>
#include "mytool1.h" 
#include "mytool2.h" 

int main(int argc,char *argv[]) 
{ 
    printf("You've input %d parameters.\n",argc-1);
    for(int i=1;i<argc;i++)
        printf("The No. %d is:%s \n",i,argv[i]);


    mytool1_print("hello");
    mytool2_print("hello"); 
} 