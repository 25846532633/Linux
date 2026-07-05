#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
   extern char** environ;
   for(int i = 0; environ[i];i++)
   {
	printf("env[%d]->%s\n",i,environ[i]);
   }
}
