#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//int main()
//{
//    int fd = open("log.txt",O_RDONLY);
//    
//    if(fd < 0)
//    {
//        perror("open failed");
//        return 1;
//    }
//
//    if(dup2(fd,0) < 0)
//    {
//        perror("dup2 failed");
//        close(fd);
//        return 2;
//    }
//    //close(fd);
//    char buffer[128];
//    while(fgets(buffer,sizeof(buffer),stdin)!=NULL)
//    {
//        printf("读取到:%s",buffer);
//    }
//    close(fd);
//
//    return 0;
//i}
//
//

int main()
{
    printf("Hello world\n");
    printf("Hello world\n");
    printf("Hello world\n");
    printf("Hello world\n");
    printf("Hello world\n");
}
