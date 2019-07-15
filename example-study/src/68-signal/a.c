/**
 * 让我们编译并运行上面的程序，这将产生以下结果，且程序会进入无限循环，需使用 CTRL + C 键跳出程序。
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int);

int main()
{
   signal(SIGINT, sighandler);

   while(1) 
   {
      printf("开始休眠一秒钟...\n");
      sleep(1);
   }

   return(0);
}

void sighandler(int signum)
{
   printf("捕获信号 %d，跳出...\n", signum);
   exit(1);
}