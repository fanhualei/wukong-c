/**
 * 回调函数
 * 函数指针作为某个函数的参数
 * 函数指针变量可以作为某个函数的参数来使用的，回调函数就是一个通过函数指针调用的函数。
 * 简单讲：回调函数是由别人的函数执行时调用你实现的函数。
 * https://www.runoob.com/cprogramming/c-fun-pointer-callback.html
 */


#include <stdlib.h>  
#include <stdio.h>
 
// 回调函数
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void))
{
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue();
}
 
// 获取随机值
int getNextRandomValue(void)
{
    return rand();
}
 
int main(void)
{
    int myarray[10];
    populate_array(myarray, 10, getNextRandomValue);
    for(int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}