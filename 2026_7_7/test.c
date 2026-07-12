#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t id = fork();
    int cnt = 0;
    if(id == 0)
    {
        while(1)
        {
            printf("I am child,PID = %d,id = %d\n",getpid(),id);
            sleep(1);
        }
    }
    else
    {
        while(1)
        {
            cnt++;
            printf("I am father,PID = %d,id = %d\n",getpid(),id);
            sleep(1);
            if(cnt == 5)
                break;
        }
    }
    return 0;
}
