#include <unistd.h>
#include "Processbar.h"

double bandwidth = 1024*1024*1.0;

void download(double filesize,callback_t cb)
{
   double current = 0.0;

   printf("download begin,current: %lf\n",current);
   while(current <= filesize)
   {
     cb(filesize,current);
     usleep(20000);
     current += bandwidth;
   }
   printf("\ndownload done,filesize: %lf\n",filesize);
   
}

int main()
{
    download(10*1024*1024,ProcBar);
    return 0;
}
