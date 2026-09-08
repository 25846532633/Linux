#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <cstring>
#include <cerrno>
using namespace std;

int cnt = 3;
#define MAX 1024
int main()
{
    //1.创建管道
    int pipefd[2];

    if(pipe(pipefd) < 0)
    {
        cerr << "errno:" << errno << ":" << "errstring:" << strerror(errno) << endl;
    }

    //2.再创建子进程
    pid_t id = fork();
    if(id < 0)
    {
       cerr << "errno:" << errno << ":" << "errstring:" << strerror(errno) << endl; 
    }
    else if(id == 0)
    {
        //子进程 - 负责读

        close(pipefd[1]); //子进程不用写端

        char buffer[MAX];
        sleep(1);   
        ssize_t n = read(pipefd[0], buffer, sizeof(buffer)-1);
        if(n > 0)
        {
            buffer[n] = '\0';
            sleep(1); 
            cout << "子进程读取的消息：" << buffer << endl;
        }
        
        close(pipefd[0]);
    }
    else
    {
        //父进程负责写
        close(pipefd[0]);//写入不用读端
        const string message = "hello child";
        cout << "父进程准备写入" << endl;
        sleep(1);
        write(pipefd[1], message.c_str(), strlen(message.c_str()));
        cout << "父进程写入完成" << endl;
        sleep(1);
        pid_t ret = waitpid(id, nullptr, 0);

        if(ret)
        {
            sleep(1);
            cout << "等待成功" << endl;
        }

        close(pipefd[1]);
    }

    return 0;
}
