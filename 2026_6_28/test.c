#include <stdio.h>

int Circulate(int x,int y)
{
    int i = 0;
    int sum = 0;
    for(i = x;i <= y;i++)
    {
        sum += i;
    }
    return sum;
}


int main()
{
    int a = 10,b = 20;
    printf("%d",Circulate(a,b));
    return 0;
}
