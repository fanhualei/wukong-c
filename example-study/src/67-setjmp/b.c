/**
 * goto 的c版本
 */

#include <stdio.h>
#include <setjmp.h>

int main()
{

    jmp_buf buf;
    int i;
    
    i=setjmp(buf);
    printf("i=%d\n",i);

    if(i!=0)exit(0);

    longjmp(buf,2);
    printf("main\n"); // 打印
    return 0;
}