#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        printf("fork error\n");
        return 1;
    }
    else if(pid == 0)
    {
        printf("I am child, pid is %d\n",getpid());
        sleep(5);
        exit(257);
    }
    else
    {
        int status = 0;
        pid_t ret = 0;

        do
        {
            ret = waitpid(-1,&status,WNOHANG);
            if(ret == 0)
                printf("child is running\n");
            sleep(1);
        }while(ret == 0);
        
        if(WIFEXITED(status) && ret == pid)
        {
            printf("等待成功，子进程返回码为:%d\n",WEXITSTATUS(status));
        }
        else
        {
            printf("等待失败\n");
            return 1;
        }
    }
    return 100;
}
