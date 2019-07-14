#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * retstring();
int main()
{
    char * name2;
    name2 = retstring();
    printf("%s\n",name2);
    //记住一定要用free释放，否则会造成内存泄露
    free(name2);
    return 0;
}

char * retstring()
{
    char * name;
    name = (char *)malloc(10); 
    strcpy(name,"张汉青");
    return name;
}