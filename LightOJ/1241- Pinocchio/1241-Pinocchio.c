#include<stdio.h>
int main()
{
    long int T, N, i, result, test=0;

    scanf("%ld", &T);

    while(T--)
    {
        scanf("%ld", &N);
        result = 0;

        long int ara[N];

        ara[0] = 2;

        for(i=1; i<=N; i++)
        {
            scanf("%ld", &ara[i]);

            if(ara[i-1] < ara[i])
                result += ((ara[i]-ara[i-1]-1)/5)+1;
        }

        printf("Case %ld: %ld\n", ++test, result);

    }

    return 0;
}
