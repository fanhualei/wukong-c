
/**
 * 函数指针是指向函数的指针变量。
 * 通常我们说的指针变量是指向一个整型、字符型或数组等变量，而函数指针是指向函数。
 * https://www.runoob.com/cprogramming/c-fun-pointer-callback.html
 */

#include <stdio.h>
 
int max(int x, int y)
{
    return x > y ? x : y;
}
 
int main(void)
{
    /* p 是函数指针 */
    int (* p)(int, int) = & max; // &可以省略
    int a, b, c, d;
 
    printf("请输入三个数字:");
    scanf("%d %d %d", & a, & b, & c);
 
    /* 与直接调用函数等价，d = max(max(a, b), c) */
    d = p(p(a, b), c); 
 
    printf("最大的数字是: %d\n", d);
 
    return 0;
}