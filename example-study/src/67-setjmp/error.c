

/**
 * 模拟捕获错误
 */

#include <stdio.h>
#include <setjmp.h>

static jmp_buf env;

double divide(double to, double by)
{
    if (by == 0)
        longjmp(env, 1);
    return to / by;
}

int main()
{

    int x = 0, y = 0;
    printf("请输入一个计算公式(例如2/3=):\n");
    scanf("%d/%d=", &x, &y);

    if (setjmp(env) == 0)
        printf("=%f\n",divide(x, y));
    else
        printf("Cannot / 0　\n\n");
    printf("done");
    return 0;
}