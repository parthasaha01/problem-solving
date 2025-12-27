#include<stdio.h>
int main()
{
    long long N, i, odd, even, result;

    while(scanf("%lld", &N)==1 && N != 0)
    {
        odd = 0;
        even = 0;

        long long ara1[N], ara2[N];

        for(i=0; i<N; i++)
        {
            scanf("%lld", &ara1[i]);

            if(ara1[i] % 2 == 0)
            {
                ++even;
            }
        }
        for(i = 0; i<N; i++)
        {
            scanf("%lld", &ara2[i]);

            if(ara2[i] % 2 == 1)
            {
                ++odd;
            }
        }

        result = even - odd;

        if(result < 0)
            result = -result;

        printf("%lld\n", result);

    }

    return 0;
}