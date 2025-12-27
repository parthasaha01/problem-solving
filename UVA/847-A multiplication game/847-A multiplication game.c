#include<stdio.h>
int main()
{
    long long N, P, k;

    while(scanf("%lld", &N)==1)
    {
        P=1;
        k=1;

        while(P<N)
        {
            if(k&1)         //k is odd
                P = P*9;
            else
                P = P*2;

            k++;
        }

        if(k&1)     //k is odd
            printf("Ollie wins.\n");
        else
            printf("Stan wins.\n");
    }

    return 0;
}
