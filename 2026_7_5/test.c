#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* agrv[])
{
    /*int i = 0;
    extern char** environ;
    
    for(;environ[i];i++)
    {
        printf("%s\n",environ[i]);
        
    }

    return 0;
    */
    
    char* env = getenv("MYENV");
    
    if(env)
    {
        printf("%s\n",env);
    }
    else
    {
        printf("sorry,it don't exist");
    }
    return 0;
}
