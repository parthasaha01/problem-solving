#include<stdio.h>
int main()
{
    long int N,X,Y,P,i=0;

    while(scanf("%ld", &N)==1 && N>0)
    {
        ++i;
        P=1;
        Y=0;
        while(P<N)
        {
            ++Y;
            P=2*P;
        }
        printf("Case %d: %ld\n",i,Y);
    }

    return 0;
}
