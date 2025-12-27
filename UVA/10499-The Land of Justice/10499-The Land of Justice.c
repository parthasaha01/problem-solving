#include<stdio.h>
int main()
{
    long long N, profit;

    while(scanf("%lld", &N) && N > 0)
    {
        if(N==1)
            profit = 0;
        else
            profit = N*25;
        printf("%lld%%\n", profit);
    }

    return 0;
}
