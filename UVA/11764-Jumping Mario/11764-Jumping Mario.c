#include<stdio.h>
int main()
{
    long int T,N,i,j,high,low;

    scanf("%ld",&T);
    for(i=1; i<=T; i++)
    {
        high=0;
        low=0;
        scanf("%ld",&N);

        long int ara[N];

        for(j=0; j<N; j++)
        {
            scanf("%ld",&ara[j]);
        }
        for(j=1; j<N; j++)
        {
            if(ara[j-1] < ara[j])
            {
                ++high;
            }
            else if(ara[j-1] > ara[j])
            {
                ++low;
            }
        }
        printf("Case %ld: %ld %ld\n",i,high,low);

    }

    return 0;
}
