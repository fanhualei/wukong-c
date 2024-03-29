/**
 * C++ 多线程
 * https://www.runoob.com/cplusplus/cpp-multithreading.html
 * 多线程是多任务处理的一种特殊形式，多任务处理允许让电脑同时运行两个或两个以上的程序。
 * 一般情况下，两种类型的多任务处理：基于进程和基于线程。
 *  基于进程的多任务处理是程序的并发执行。
 *  基于线程的多任务处理是同一程序的片段的并发执行。
 * 
 * 多线程程序包含可以同时运行的两个或多个部分。这样的程序中的每个部分称为一个线程，每个线程定义了一个单独的执行路径。
 * 本教程假设您使用的是 Linux 操作系统，我们要使用 POSIX 编写多线程 C++ 程序。
 * POSIX Threads 或 Pthreads 提供的 API 可在多种类 Unix POSIX 系统上可用，比如 FreeBSD、NetBSD、GNU/Linux、Mac OS X 和 Solaris。
 * 
 * 创建线程
 *  #include <pthread.h>
 *  pthread_create (thread, attr, start_routine, arg) 
 * 
 * 终止线程
 *  pthread_exit (status) 
 *  如果 main() 是在它所创建的线程之前结束，并通过 pthread_exit() 退出，那么其他线程将继续执行。否则，它们将在 main() 结束时自动被终止。
 * 
 * 要将 -lpthread添加到g++
 *    g++ test.cpp -lpthread -o test.o
 * 
 */

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
   // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
   int tid = *((int *)threadid);
   cout << "Hello Runoob! 线程 ID, " << tid << endl;
   pthread_exit(NULL);
}

int main()
{
   pthread_t threads[NUM_THREADS];
   int indexes[NUM_THREADS]; // 用数组来保存i的值
   int rc;
   int i;
   for (i = 0; i < NUM_THREADS; i++)
   {
      cout << "main() : 创建线程, " << i << endl;
      indexes[i] = i; //先保存i的值
      // 传入的时候必须强制转换为void* 类型，即无类型指针
      rc = pthread_create(&threads[i], NULL,
                          PrintHello, (void *)&(indexes[i]));
      if (rc)
      {
         cout << "Error:无法创建线程," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
