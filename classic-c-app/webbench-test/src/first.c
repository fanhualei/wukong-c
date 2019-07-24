
/**
 * 参考了这个网址
 * https://www.jianshu.com/p/ef1cf8609c4a
 * 编译的时候，要加上："-lpthread"
 * 
 */

#include <stdio.h>
#include <stdlib.h> // exit()
#include <unistd.h> // fork(), sleep(), _exit(), pid_t
#include <pthread.h>

void * hello(void * arg)
{
    printf("Thread start running!\n");
    printf("%s\n", (char *)arg);
    sleep(3);
    pthread_exit("Hello from thread!");
}

int main(void)
{
    pthread_t id;
    void * thread_retval;

    if (pthread_create(&id, 0, hello, "Hello from main!") != 0) {
        printf("Create thread failed!\n");
        exit(1);
    }

    pthread_join(id, &thread_retval);
    printf("%s\n", (char *)thread_retval);
    return 0;
}