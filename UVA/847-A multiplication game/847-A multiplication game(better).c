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
            if(k&1)
                P += P << 3;
            else
                P = P << 1;

            k++;
        }

        if(k&1)
            printf("Ollie wins.\n");
        else
            printf("Stan wins.\n");
    }

    return 0;
}
