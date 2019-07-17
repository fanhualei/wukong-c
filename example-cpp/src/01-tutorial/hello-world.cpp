

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
int main()
{
    cout << "Hello, world!" << endl;
    // 定义一个8进制
    int a=011;
    char s[10];

    char *s1="hello, " "d" "ear";

    // itoa(a, s, 2);

    printf("a的10进制\t:%d \n",a);
    printf("a的 8进制\t:%04o \n",a);
    printf("a的16进制\t:%04x \n",a);
    printf("a的 2进制\t:%s \n",s);

    printf("\t:%s \n",s1);
    return 0;
}
