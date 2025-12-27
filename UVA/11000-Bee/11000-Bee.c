#include<stdio.h>
int main()
{
    long long N, i, temp, male, total;

    while(scanf("%lld", &N) & N != -1)
    {
        male = 0;
        total = 1;
        for(i=1; i<=N; i++)
        {
            temp = total;
            total += male+1;
            male = temp;
        }

        printf("%lld %lld\n", male, total);
    }

    return 0;
}
