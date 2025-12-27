#include<stdio.h>
int main()
{
    long int T,C,d,i;
    double dc;

    scanf("%ld",&T);
    for(i=1; i<=T; i++)
    {
        scanf("%ld %ld",&C,&d);
        dc=((5/9.0)*d)+C;

        printf("Case %ld: %.2lf\n",i,dc);
    }

    return 0;
}
