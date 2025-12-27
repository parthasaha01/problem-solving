#include<stdio.h>
int main()
{
    long long int N, n_last, sum;

    while(scanf("%lld", &N)==1)
    {
        n_last = (N*(N+2)) / 2;

        sum = (n_last*3) - 6;

        printf("%lld\n", sum);
    }

    return 0;
}
