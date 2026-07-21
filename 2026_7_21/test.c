#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#define SIZE 512 //命令行的行数
#define SkipPath(p) do{ p += (strlen(p)-1);while(*p != '/')p--;}while(0)
#define NUM 32 //最多可以接收的命令行参数个数
#define ZERO '\0'
#define SEP " " //分割命令行各参数的间隔符

char* gArgv[NUM];//命令行参数表
char cwd[SIZE*2];//当前进程自己的环境变量表
int lastcode = 0;

const char* GetHome()
{
    const char* home = getenv("HOME");
    if(home == NULL)
        return "/";
    return home;
}

const char* GetUserName()
{
    const char* name = getenv("USER");
    if(name == NULL) return "None";
    return name;
}

const char* GetHostName()
{
    const char* hostname = getenv("HOSTNAME");
    if(hostname == NULL) return "None";
    return hostname;
}

const char* GetCwd()
{
    const char* cwd = getenv("PWD");
    if(cwd == NULL) return "None";
    return cwd;
}

int GetUserCommand(char command[], size_t n)
{
    //从输入流中读取n个字符到缓冲区command
    char* str = fgets(command,n,stdin);
    if(str == NULL)
        return -1;
    //按下的回车也会被读取进去，所以需要自己调整置为\0
    command[strlen(command)-1]=ZERO;
    return strlen(command);
}

void SplitCommand(char command[],size_t n)
{
    (void)n;//这个函数我暂时不用
    gArgv[0] = strtok(command,SEP);
    int index = 1;
    while((gArgv[index++] = strtok(NULL,SEP)));
    /*index -= 1;
    while(index--)
    {
        printf("%s\n",gArgv[index]);
        
    }*/
}

void Cd()
{
    const char* path = gArgv[1];
    if(path == NULL) path = GetHome();
    chdir(path);//修改进程真正的当前工作目录

    //更新环境变量
    char temp[SIZE*2];
    getcwd(temp,sizeof(temp));
    snprintf(cwd,sizeof(cwd),"PWD=%s",temp);
    putenv(cwd);
}

int CheckBuildin()
{
    int yes = 0;//如果是则为1，不是则为0
    const char* enter_cmd = gArgv[0];
    if(strcmp(enter_cmd,"cd") ==0 )
    {
        yes = 1;
        Cd();
    }else if(strcmp(enter_cmd,"echo") == 0 &&
    strcmp(gArgv[1],"$?") == 0)
    {
        yes = 1;
        printf("%d\n",lastcode);
        lastcode = 0;
    }
    
    return yes;
}


void commandline()
{
    char line[SIZE];
    const char* username = GetUserName();
    const char* hostname = GetHostName();
    const char* cwd = GetCwd();

    SkipPath(cwd);
    //问题1：cwd要不要考虑别的情况
    snprintf(line,sizeof(line),"[%s@%s %s]> ",username,hostname,cwd+1);
    printf("%s",line);
    fflush(stdout);
}

void ExecuteCommand()
{
    pid_t id = fork();
    if(id < 0) 
        exit(1);
    else if(id == 0)
    {
        execvp(gArgv[0],gArgv);
        exit(errno);
    }
    else
    {
        int status = 0;
        pid_t rid = waitpid(id,&status,0);
        if(WIFEXITED(status))
        {
            lastcode = WEXITSTATUS(status);
            if(lastcode != 0)
                printf("%s:%s:%d\n",gArgv[0],strerror(lastcode),lastcode);
        }
    }
}

int main()
{
    //控制这个bash一直都在，而不是运行完立马退出
    int quit = 0;
    while(!quit)
    {
     //1.输出自己的命令行
        commandline();
    
    //2.获取用户命令
        char usercommand[SIZE];
        int n = GetUserCommand(usercommand,sizeof(usercommand));
        if(n <=0)
            return 1;
    
    //3.将读取的命令进行分割
        SplitCommand(usercommand,sizeof(usercommand));
    //printf("%s\n",usercommand);
    
    //4.判断是否为内建命令
        n = CheckBuildin();
        if(n)
            continue;

    //5.执行命令
        ExecuteCommand();
   }
   return 0;
}   

