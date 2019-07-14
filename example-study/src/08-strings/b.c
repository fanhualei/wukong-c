#include <stdio.h>
#include <string.h>

void pringstr()
{

    char str1[12] = "Hello";
    char str2[12] = "Hello\n";
    char *str4 = "你好";

    char *p;
    p = str1;
    str1[8] = 'a';

    printf("%s\n", p);
    printf("%d\n", strlen(p));
}

int word_count(char *s){

    printf("%s\n", s);
    // while(*s!='\0'){
    //     printf("%s\n", s);
    //     s++;
    // }

    return 0;
}

int main()
{

    //pringstr();

    word_count("hello word");

    return 0;
}