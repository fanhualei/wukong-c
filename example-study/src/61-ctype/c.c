#include <ctype.h>

main()
{
    char s[] = "文曲星-BJGGV";
    int i = 15; // length of string s

    printf("%s\n", s);
    for (i = 0; i < 12; i++)
    {
        if (isascii(s[i]))
            putchar('^');
        else
            putchar('.');
    }
    getchar();
    return 0;
}