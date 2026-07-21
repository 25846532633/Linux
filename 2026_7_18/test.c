#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
int main()
{
    printf("替换前:%d\n",getpid());
    //execl("./test2","test2",NULL);
    char* const argv[] = {
        "ls",
        "-l",
        "-a",
        NULL
    };
    char* const argv[] = {
        "env",
        NULL
    };

    char* const envp[] = {
        "MY_VALUE=hello_execle",
        "PATH=/usr/bin:/bin",
        NULL
    };
    execve("/usr/bin/ls",argv,envp);
    //execv("/usr/bin/ls",argv);
    //execlp("ls","ls","-l","-a",NULL);
    //execvp("ls",argv);
    printf("成功结束\n");
    return 0;
}*/



int main()
{
    char* const argv[] = {
        "ls",
        "-l",
        "-a",
        NULL
    };
    pid_t id = fork();

    if(id < 0)
    {
        perror("fork failed");
        return 1;
    }
    else if(id == 0)
    {
        sleep(5);
        execvp("ls",argv);
        //替换失败
        perror("execlp");
        _exit(127);
    }
    else
    {
        int status = 0;
        waitpid(-1,&status,0);
        if(WIFEXITED(status))
        {
         printf("child exit success,its exit code:%d\n",WEXITSTATUS(status));
        }
        else
        {
            printf("failed");
        }
        printf("父进程继续运行\n");
    }
    return 0;
}


