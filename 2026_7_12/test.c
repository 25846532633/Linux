#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
int main()
{
    pid_t id = fork();

    if(id < 0)
    {
        perror("fork");
        return 1;
    }
    else if(id == 0)
    {
        int cnt = 3;
        printf("I am child,%d\n",getpid());
        while(cnt--)
        {
            printf("I am child,after %d second exit\n",cnt);
            sleep(1);
        }
        exit(1);
    }
    else
    {
        printf("I am father,%d\n",getpid());
        printf("准备调用wait\n");
        sleep(5);
        int status = 0;
        pid_t ret = wait(&status);
        if(ret)
            printf("回收子进程 pid = %d 成功,status = %d\n",ret,status);
        else
            printf("回收失败\n");
    }

    return 0;
}*/

int main(void)
{
    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        // 子进程
        sleep(10);
        exit(10);
    }
    else
    {
        int st = 0;
        int ret = wait(&st);

        //if (ret > 0 && (st & 0x7F) == 0)
        if(WIFEXITED(st))
        {
            printf("child exit code: %d\n", WEXITSTATUS(st));
        }
        else if (ret > 0)
        {
            printf("sig code: %d\n", st & 0x7F);
        }
    }

    return 0;
}
