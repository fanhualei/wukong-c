/**
 * C++ 信号处理
 * 信号是由操作系统传给进程的中断，会提早终止一个程序。
 * https://www.runoob.com/cplusplus/cpp-signal-handling.html
 * 
 * 
 * 系统自定义信号
 *  SIGABRT　SIGFPE　SIGILL　SIGINT　SIGSEGV　SIGTERM 
 * 
 * signal() 函数
 *  C++ 信号处理库提供了 signal 函数，用来捕获突发事件
 * 
 * raise() 函数
 *  您可以使用函数 raise() 生成信号，该函数带有一个整数信号编号作为参数，语法如下：
 * 
 */


#include <iostream>
#include <csignal>
#include <unistd.h>
#include <cstdlib>
 
using namespace std;
 
void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";
 
    // 清理并关闭
    // 终止程序  
    exit(signum);
}
 
int main ()
{
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);  
    // 不建议自定义一个信息号，因为系统捕获不了 
    // signal(55, signalHandler); 
    int i = 0;
    while(++i){
       cout << "Going to sleep...." << endl;
       if( i == 3 ){
          raise(SIGINT);
       }
       sleep(1);
    }
 
    return 0;
}