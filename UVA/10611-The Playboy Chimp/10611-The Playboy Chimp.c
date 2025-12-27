#include<stdio.h>
int main()
{
    long long N, Q, i, j, S, T, a[50000], b[25000];

    while(scanf("%lld", &N)==1)
    {
                for(i=0; i< N; i++)
                    scanf("%lld", &a[i]);

                scanf("%lld", &Q);

                for(i=0; i<Q; i++)
                {

                    scanf("%lld", &b[i]);

                    S = 0;
                    T = 4294967297;

                    for(j=0; j<N; j++)
                    {
                        if(a[j] < b[i] && a[j] > S)
                        {
                            S = a[j];
                        }
                        else if(a[j] > b[i] && a[j] < T)
                        {
                            T = a[j];
                            break;
                        }
                    }

                if(S==0 && T != 4294967297)
                    printf("X %lld\n", T);
                else if(S != 0 && T == 4294967297)
                    printf("%lld X\n", S);
                else if(S == 0 && T == 4294967297)
                    printf("X X\n");
                else
                    printf("%lld %lld\n", S, T);
            }
    }

    return 0;
}
