#include <cstdio>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#define Max 100002
#define HMax 5001
#define sq 100
int isPrime[Max+1];
long long int phi[Max+1];
void TotientPhi()
{
    long int i,j;
    phi[1]=1;

    for(i=2; i<=Max; i+=2)
    {
        phi[i]=(i>>1);    //i/2
    }

    for (i=3; i<=Max; i+=2)
    {
        if(!isPrime[i])//if i is prime
        {
            phi[i]=i-1;

            for (j=i+i; j<=Max; j+=i)
            {
                if(phi[j]!=0)
                {
                    phi[j] /= i;
                    phi[j] *= (i-1);
                }
                else
                {
                    phi[j] = j/i;
                    phi[j] *= (i-1);
                }

                isPrime[j]=1;
            }

        }
    }

    //partial_sum(phi,phi + (Max+1),phi);
    for(int i = 1; i<=Max;i++)
        phi[i] += phi[i-1];
}
int main()
{
    TotientPhi();

    int n,T;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);

        printf("%lld\n",phi[n]*phi[n]);
    }

    return 0;
}
