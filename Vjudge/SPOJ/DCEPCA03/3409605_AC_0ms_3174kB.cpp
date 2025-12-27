#include <cstdio>
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
#define Mx 10002
bool notPrime[Mx+1];
long long int phi[Mx+1];
void TotientPhi()
{
    long int i,j;
    phi[1]=1;

    for(i=2; i<=Mx; i+=2)
        phi[i]=(i>>1);    //i/2

    for(i=3; i<=Mx; i+=2)
        phi[i]=i;

    for (i=3; i<=Mx; i+=2)
    {
        if(!notPrime[i])//if i is prime
        {
            phi[i]=i-1;

            for (j=i+i; j<=Mx; j+=i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);

                notPrime[j]=true;
            }

        }
    }

    //partial_sum(phi,phi + (Max+1),phi);
    for(int i = 1; i<=Mx;i++)
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
