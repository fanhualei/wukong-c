#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("I am a test. id:%d 父id:%d \n",getpid(),getppid()); 
    int i =0;
    pid_t pid = 0; //pid表示fork函数返回的值

    for (i = 0; i < 5; i++)
    {
        pid = fork();
        if (pid <= (pid_t)0)
        {
            break;
        }
    }

    if (pid < (pid_t)0)
    {
        fprintf(stderr, "problems forking worker no. %d\n", i);
        perror("fork failed.");
        return 3;
    }


   if (pid == (pid_t)0)
   {
      /* I am a child */
      printf("I am a child. 编号:%d fork返回值:%d id:%d 父id:%d \n",i,pid,getpid(),getppid());
   }else{
      printf("I am a father. 编号:%d fork返回值:%d id:%d 父id:%d \n",i,pid,getpid(),getppid()); 
   }


    return 0;
}