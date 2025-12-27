#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    long long N, Q, i, j, S, T, a[50000], b[25000], num, L, H, M;

    while(scanf("%lld", &N)==1)
    {
            for(j=0; j<N; j++)
                scanf("%lld", &a[j]);

            scanf("%lld", &Q);

            for(i=0; i<Q; i++)
            {
                    scanf("%lld", &b[i]);

                    num = b[i]-1;
                    L=0;
                    H=N-1;

                    while(L<=H)
                    {
                        M = (L+H)/2;

                        if(num < a[M])
                        {
                            H=M-1;
                        }
                        else if(num > a[M])
                        {
                            L=M+1;
                        }
                        else
                        {
                            S=a[M];
                            break;
                        }
                    }

                    if(L>H)
                    {
                        S=a[H];
                    }

                    while(L<N)
                    {
                        if(a[L] > b[i])
                        {
                            T=a[L];
                            break;
                        }
                        L++;
                    }

                    if(H<0)
                        printf("X ");
                    else
                        printf("%lld ", S);

                    if(L<N)
                        printf("%lld\n", T);
                    else
                        printf("X\n");
            }
    }

    return 0;
}
