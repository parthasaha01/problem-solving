#include<stdio.h>
int main()
{
    long int T, N, P, Q, i, result, weight, test=1;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld %ld %ld", &N, &P, &Q);

        long int ara[N];

        for(i=0; i<N; i++)
            scanf("%ld", &ara[i]);

        result = 0;
        weight=0;

        if(P>N)
            P=N;

        for(i=0; i<P; i++)
        {
            weight += ara[i];

            if(weight > Q)
                break;

            ++result;
        }

        printf("Case %ld: %ld\n", test++, result);
    }

    return 0;
}
