#include <stdio.h>
 
int main ()
{

    int a=100;
    int *pa=&a;
    printf("-------------\n");
    printf("%d \n",*pa);
    printf("%p \n",&pa);
    printf("%p \n",&a);
    printf("%p \n",pa);


}    