#include<stdio.h>
int main()
{
    long int N, i, odd, even, result;

    while(scanf("%ld", &N)==1)
    {
        if(N == 0)
            break;

        odd = 0;
        even = 0;

        long int ara1[N], ara2[N];

        for(i=0; i<N; i++)
        {
            scanf("%ld", &ara1[i]);

            if(ara1[i] % 2 == 0)
            {
                ++even;
            }
        }
        for(i = 0; i<N; i++)
        {
            scanf("%ld", &ara2[i]);

            if(ara2[i] % 2 == 1)
            {
                ++odd;
            }
        }

        result = even - odd;

        if(result < 0)
            result = -result;

        printf("%ld\n", result);

    }

    return 0;
}