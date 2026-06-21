#include <stdio.h>

int AddToTarget(int start,int end)
{
    int total = 0;
    for(int i = start;i <= end;i++)
    {
        total += i;
    }
    return total;
}


int main()
{
    int sum = AddToTarget(1,100);
    printf("%d\n",sum);
    return 0;
}
