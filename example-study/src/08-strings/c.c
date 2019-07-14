#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * 字符串的定义 : 建议使用 char * str1="hello" 的形式定义字符串
 */
void test()
{
    //定义字符串
    char *str1 = "hello world";
    char strArra[] = "hello world";
    printf("%s\n", str1);
    printf("%s\n", strArra);

    //改变字符串内容
    str1 = "new string the string is long";
    printf("%s\n", str1);
    //strcpy 不能追加给一个数组过大的字符串，建议是用char *
    strcpy(strArra, "new");
    printf("%s\n", strArra);

    //字符串追加

    //不能使用strcat追加到一个字符串指针上，
    // strcat(str1,"next long string is add");
    // printf("%s\n", str1);

    //只能追加一个很少的数值
    strcat(strArra, "next");
    printf("%s\n", strArra);
}

/**
 * 字符串拼接1 strcpy+strcat
 */
void wk_strcat1()
{
    char *fStr = "你好呀";
    char *sStr = " 小明";
    char *newStr = NULL;
    newStr = (char *)malloc(strlen(fStr) + strlen(sStr));
    strcpy(newStr, fStr);
    strcat(newStr, sStr);
    printf("%s\n", newStr);
}

/**
 * 字符串拼接2 sprintf
 */
void wk_strcat2()
{
    char *fStr = "你好呀";
    char *sStr = " 小明";
    char *newStr = NULL;
    //如果不追加空间，那么后面的数字不会出现．
    newStr = (char *)malloc(strlen(fStr) + strlen(sStr) + 100);
    sprintf(newStr, "%s%s    12312312355555555555522222222222444444444", fStr, sStr);
    printf("%s\n", newStr);
}

/**
 * 字符串 strlen与sizeof的区别
 */
void wk_len()
{
    char a[100] = "123456a";
    printf("定义了一个字符串               ：char a[100]=\"123456a\";　\n");
    printf("字符串长度　strlen(a)         ：%d\n", strlen(a));
    printf("地址控件长度　sizeof(a)       ：%d\n", sizeof(a));

    int b[100] = {10, 2, 3};
    printf("\n定义了一个整数数组           ：int b[100]={10,2,3};　\n");
    printf("第一个元素的数值               ：%d\n", *b);
    printf("数组内存大小长度　sizeof(b)    ：%d\n", sizeof(b));
    printf("数组大小　sizeof(b)/sizeof(*b)：%d\n", sizeof(b) / sizeof(*b));
}

/**
 * 比较两个字符串 strcmp
 */

void wk_cmp()
{
    char *str = "aaa";
    char *str2 = "aaa";
    char strAra[] = "aaa";

    if ("aaa" == "aaa")
    {
        printf("两个常量比较是相同的\n");
    }

    if (str == "aaa")
    {
        printf("常量与一个 char* 比较是相同的\n");
    }

    //不同
    if (strAra == "aaa")
    {
        printf("－－－－－－－－常量与一个 char[]数组 比较是相同的\n");
    }

    printf("strcmp对比：%d\n", strcmp(strAra, "aaa"));

    if (str == str2)
    {
        printf("两个char* 比较是相同的\n");
    }

    // 不同
    if (str == strAra)
    {
        printf("－－－－－－－－一个char*与char[] 比较是相同的\n");
    }
    printf("strcmp对比：%d\n", strcmp(strAra, str));
    printf("strcmp对比aba与aab：%d\n", strcmp("aba", "aab"));
}

/**
 * 查找字符串 strchr
 */
void wk_chr()
{
    char *a = "123456.7890";
    char *ret = NULL;
    ret = strchr(a, '.');
    printf("%s,%d\n", ret, strlen(ret));
    printf("%s,%d\n", a, strlen(a));
}

/**
 * 字符串截取
 * subString
 */

void wk_sub()
{
    //截取前n个字符
    char *a = "123456.7890";
    char ret[20];
    strxfrm(ret, a, 5);
    printf("截取前5个字符：%s\n", ret);

    int index = strlen(a) - strlen(strchr(a, '.'));
    strxfrm(ret, a, index);
    printf("截取.前字符：%s\n", ret);

    //截取后字符
    printf("截取.后字符：%s\n", strchr(a, '.') + 1);

    //分隔字符串
    char text[80] = "This is-www.runoob.com-website";
    const char s[2] = "-";
    char *token;

    /* 获取第一个子字符串 */
    token = strtok(text, s);
    /* 继续获取其他的子字符串 */
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, s);
    }
}

void wk_split()
{
    char text[] = "This is-www.runoob.com-website";
    const char s[2] = "-";
    char *token;

    /* 获取第一个子字符串 */
    token = strtok(text, s);
    /* 继续获取其他的子字符串 */
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, s);
    }
}

int main()
{

    wk_split();
    printf("\n----------------------------\n");
    return 0;
}