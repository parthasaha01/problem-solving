#include<stdio.h>
int main()
{
    long int C,N,i,j,sum,R;
    double avg,ans;

    scanf("%ld",&C);
    for(i=1; i<=C; i++)
    {
        sum=0;
        R=0;
        scanf("%ld",&N);
        long int ara[N];

        for(j=0; j<N; j++)
        {
            scanf("%ld",&ara[j]);
            sum += ara[j];
        }

        avg=sum/(double)N;

        for(j=0; j<N; j++)
        {
            if(ara[j] > avg)
            {
                ++R;
            }
        }

        ans=(R*100)/(double)N;

        printf("%.3lf%%\n",ans);

    }

    return 0;
}
