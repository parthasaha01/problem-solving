#include<cstdio>
#include<cmath>
using namespace std;
int num[1000], prime[170];
void sieve(void)
{
    int i, j, p=3;

    prime[1]=1;
    prime[2]=2;

    for(i=3; i <= 31; i+=2)
    {
        if(!num[i])
        {
            prime[p++]= i;
            for(j=i*i; j<=1000; j+=(i<<1))
            {
                num[j]=1;
            }
        }
    }

    for(i=33; i<=1000; i+=2)
    {
            if(!num[i])
            {
               // printf("%d ",i);
               prime[p++] = i;
            }
    }
}
int main()
{
    int N, C, p, i, m, j;

    sieve();

    while(scanf("%d %d", &N, &C)==2)
    {

        printf("%d %d:", N, C);

        if(N<2)
            p=1;
        else
            p=2;

        for(i=3; i<=N; i+=2)
        {
            if(!num[i])//prime
            {
               ++p;
            }
        }

        //printf("\n%d\n", p);

        if(p&1)             // if p is odd
            C = (C<<1)-1;   //c/2 - 1
        else
            C = (C<<1);         // C = C/2

        if(C>=p)
            m=0;
        else
            m = (p-C) >> 1; // (p-c)*2

        j=0;

        for(i=m+1; j<C && j<p; i++)
        {
            printf(" %d",prime[i]);
            ++j;
        }
        printf("\n\n");
    }

    return 0;
}
