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
    //phi[0]=1;
    phi[1]=1;

    for(i=2; i<=Max; i+=2)
    {
        phi[i]=(i>>1);    //i/2
    }

    for (i=3; i<=Max; i+=2)
    {
        if(!isPrime[i])
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

    partial_sum(phi,phi + (Max+1),phi);
}
/*void ExtremeTotient()
{
    long int i,j,num;
    long long H;

    for(num=1; num<=Max; num++)
    {
        H=0;
        for(i=1; i<=num; i++)
        {
            H += phi[i]*phi[i];

            for(j=i+1; j<=num; j++)
            {
                H += 2*phi[i]*phi[j];
            }
        }

        phi[num]=H;
    }
} */
int main()
{
    TotientPhi();
    //ExtremeTotient();

    long int n,diff,i,T;

    scanf("%ld",&T);
    while(T--)
    {
        scanf("%ld",&n);

        printf("%lld\n",phi[n]*phi[n]);
    }

    return 0;
}
