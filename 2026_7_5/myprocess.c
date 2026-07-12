#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    //pid_t ret = fork();

    /*if(ret < 0)
    {
        perror("fork");
        return 1;
    }
    else if(ret == 0)
    {
        printf("I am child,pid = %d,ret = %d\n",getpid(),ret);
    }
    else
    {
        printf("I am father,pid = %d,ret = %d\n",getpid(),ret);
    }
    sleep(1);
    return 0;
    */
    
    pid_t id = fork();

    if(id < 0)
    { 
        perror("fork");
        return 1;
    }
    else if(id > 0)
    {
        printf("parent[%d] is sleeping...\n",getpid());
        sleep(30);
    }
    else
    {
        printf("child[%d] is begin Z...\n",getpid());
        sleep(5);
        exit(EXIT_SUCCESS);
    }
    return 0;

}
