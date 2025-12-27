#include<stdio.h>
int main()
{
    long int N,X=0,Y,a,b,i;

    while(scanf("%ld",&N)==1 && N != 0)
    {
        ++X;
        long int ara[N];
        a=0;
        b=0;
        for(i=0; i<N; i++)
        {
            scanf("%ld",&ara[i]);
            if(ara[i] != 0)
            {
                ++a;
            }
            else
            {
                ++b;
            }
        }
        Y=a-b;
        printf("Case %ld: %ld\n",X,Y);
    }

    return 0;
}
