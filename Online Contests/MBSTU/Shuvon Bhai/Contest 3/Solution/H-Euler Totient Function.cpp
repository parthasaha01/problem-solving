#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define Max 1000000
#define sq 1000
long int isPrime[Max];
void seive()
{
    long int i,j;
    isPrime[1]=1;

    for(i=4; i<=Max; i+=2)
    {
        isPrime[i] = i/2;
    }

    for (i=3; i<=Max/2; i+=2)
    {
        if(!isPrime[i])
        {

            for (j=i+i; j<=Max; j+=i)
            {
                if(isPrime[j]!=0)
                {
                    isPrime[j] /= i;
                    isPrime[j] *= (i-1);
                }
                else
                {
                    isPrime[j] = j/i;
                    isPrime[j] *= (i-1);
                }
            }

        }
    }

}
int main()
{
    seive();

    long int n,diff,i,T;

    scanf("%ld",&T);
    while(T--)
    {
        scanf("%ld",&n);

        if(isPrime[n]==0)
        {
            printf("%ld\n",n-1);
        }
        else
        {
            printf("%ld\n",isPrime[n]);
        }
    }

    return 0;
}
