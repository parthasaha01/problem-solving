#include<stdio.h>
int main()
{
    long int T, n, P, Q, weight[31], i, j, egg, sum;

    scanf("%ld", &T);

    for(i=1; i<=T; i++)
    {
        scanf("%ld %ld %ld", &n, &P, &Q);

        for(j=0; j<n; j++)
        {
            scanf("%ld", &weight[j]);
        }

        sum = 0;
        egg = 0;

        for(j=0; j<P && j<n; j++)
        {
            sum += weight[j];

            if(sum > Q)
                break;

            ++egg;
        }

        printf("Case %ld: %ld\n", i, egg);
    }

    return 0;
}
