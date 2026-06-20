#include "Processbar.h"
#include <string.h>
#define Length 101
#define Style '#'

const char* label = "|/-\\";

void ProcBar(double total,double current)
{
    char bar[Length];//进度条本身
    memset(bar,'\0',sizeof(bar));//初始化进度条空间
    int len = strlen(label);
    
    int cnt = 0;
    double rate = (current*100.0)/total; //*100 - 0.75->75%
    int loop_count = (int)rate; //循环次数
    while(cnt <= loop_count)
    {
        bar[cnt++] = Style;
    }
    printf("[%-100s][%.1lf%%][%c]\r",bar,rate,label[cnt%len]);
    fflush(stdout);
}
