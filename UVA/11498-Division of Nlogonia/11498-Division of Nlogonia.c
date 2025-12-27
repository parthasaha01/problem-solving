#include<stdio.h>
int main()
{
    long int K, N, M, X, Y, P, Q;

    while(scanf("%ld", &K) && K)
    {
        scanf("%ld %ld", &N, &M);

        while(K--)
        {
            scanf("%ld %ld", &X, &Y);

            P = X-N;
            Q=Y-M;

            if(P == 0 || Q == 0)
                printf("divisa\n");
            else if(P>0 && Q>0)
                printf("NE\n");
            else if(P>0 && Q<0)
                printf("SE\n");
            else if(P<0 && Q>0)
                printf("NO\n");
            else
                printf("SO\n");
        }
    }

    return 0;
}
