/**
 * C++ 预处理器
 * https://www.runoob.com/cplusplus/cpp-preprocessor.html
 *  预处理器是一些指令，指示编译器在实际编译之前所需完成的预处理。
 *  所有的预处理器指令都是以井号（#）开头，只有空格字符可以出现在预处理指令之前。
 *  预处理指令不是 C++ 语句，所以它们不会以分号（;）结尾。
 *  我们已经看到，之前所有的实例中都有 #include 指令。这个宏用于把头文件包含到源文件中。
 *  C++ 还支持很多预处理指令，比如 #include、#define、#if、#else、#line 等，让我们一起看看这些重要指令。
 * 
 * #define 预处理
 *  #define 预处理指令用于创建符号常量。该符号常量通常称为宏，指令的一般形式是：
 *  #define macro-name replacement-text 
 *  当这一行代码出现在一个文件中时，在该文件中后续出现的所有宏都将会在程序编译之前被替换为 replacement-text。例如：
 * 
 * 条件编译
 * 
 * # 和 ## 运算符
 * 
 * C++ 中的预定义宏
 * 
 */

// 接下来使用 -E 选项进行编译，并把结果重定向到 test.p。现在，如果您查看 test.p 文件，将会看到它已经包含大量的信息
#include <iostream>
using namespace std;

// 创建符号常量
#define PI 3.14159

// 参数宏 您可以使用 #define 来定义一个带有参数的宏，如下所示：
#define MIN(a, b) (a < b ? a : b)

// 条件编译
#define DEBUG

// # 运算符会把 replacement-text 令牌转换为用引号引起来的字符串。
#define MKSTR(x) #x

// ## 运算符用于连接两个令牌。
#define CONCAT(x, y) x##y

int main()
{

    cout << "Value of PI :" << PI << endl;

    int i, j;
    i = 100;
    j = 30;
    cout << "较小的值为：" << MIN(i, j) << endl;

#if 0
   /* 这是注释部分 这种玩法不常用 */
   cout << MKSTR(HELLO C++) << endl;
#endif

#ifdef DEBUG
    cerr << "Trace: Inside main function" << endl;
#endif

    // # 运算符会把 replacement-text 令牌转换为用引号引起来的字符串。
    cout << MKSTR(HELLO C++) << endl;
    // ## 运算符用于连接两个令牌。
    int xy = 100;
    cout << CONCAT(x, y);
    
    // C++ 中的预定义宏
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;

    return 0;
}