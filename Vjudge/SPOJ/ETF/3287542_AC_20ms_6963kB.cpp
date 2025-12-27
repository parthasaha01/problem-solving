#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define Max 1000000
#define sq 1000
long int isPrime[Max];
//vector<long> isPrime;
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
            //isPrime[i]=i-1;
            //if(i==79)
                //printf("%ld\n",i*8599);
            //if(i==8599)
                    //printf("i=%ld, j=%ld\n",i,j);

            for (j=i+i; j<=Max; j+=i)
            {
                //printf("1.%ld\n",isPrime[j]);
                if(isPrime[j]!=0)
                {

                    isPrime[j] /= i;
                    //printf("2.%ld\n",isPrime[j]);
                    isPrime[j] *= (i-1);
                    //printf("3.%ld\n",isPrime[j]);

                    //if(j==679321)
                        //printf("i=%ld, j=%ld\n",i,j);
                }
                else
                {
                    isPrime[j] = j/i;
                    //printf("4.%ld\n",isPrime[j]);
                    isPrime[j] *= (i-1);
                    //printf("5.%ld\n",isPrime[j]);
                }
            }

        }
    }
    /*for(i=sq+1; i<=Max; i+=2)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
        }
    } */

    //printf("%ld\n",isPrime[8599]);
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
