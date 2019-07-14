#include <stdio.h>

int main()
{

    FILE *fp;

    fp = fopen("file123.txt", "r");
    if (fp == NULL)
    {
        perror("错误");
        return (-1);
    }
    fclose(fp);

    return (0);
}