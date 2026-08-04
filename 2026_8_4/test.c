#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//int main()
//{
//    printf("Hello world");
//    return 0;
//}
//
//

//int main()
//{
//    close(1);
//    int fd = open("log.txt",O_WRONLY | O_CREAT | O_APPEND,0644);
//    if(fd < 0)
//    {
//        perror("open");
//        return 1;
//    }
//
//    printf("fd = %d\n",fd);
//    
//    //标准输出流一般采用全缓冲，以便主动刷新和观察
//    fflush(stdout);    
//    close(fd);
//
//    return 0;
//
//}
//

int main()
{
    int fd = open("log2.txt",O_WRONLY | O_CREAT | O_TRUNC,0644);
    if(fd < 0)
    {
        perror("Open");
        return 1;
    }
    //将fd复制到文件描述符1，使得标准输出重定向到fd对应的文件
    if(dup2(fd,1) < 0)
    {
        perror("dup2");
        close(fd);
        return 2;
    }
    
    if(fd != 1)
    {
        close(fd);
    }
   
    printf("Hello world\n");
    fprintf(stdout,"hello fprintf\n");
    write(1,"hello write\n",12);
    return 0;



}
