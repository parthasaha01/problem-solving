#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define Max 20000000
#define sq 4472
bool isPrime[Max];
vector<long> primes;
vector<long> twinprimes;
void seive()
{
    long int i,j,doubleI,p=0;

    primes.push_back(2);

    for(i=3;i<=Max;i+=2)
        isPrime[i]=true;

    for (i=3; i<=sq; i+=2)
    {
        if(isPrime[i]==true)
        {
            primes.push_back(i);
            p++;

            if(primes[p]-primes[p-1]==2)
            {
                twinprimes.push_back(p-1);
            }

            doubleI = i * 2;

            for (j=i*i; j<Max; j+=doubleI)
                isPrime[j] = false;

        }
    }
    for(i=sq+1; i<=Max; i+=2)
    {
        if(isPrime[i]==true)
        {
            primes.push_back(i);
            p++;

            if(primes[p]-primes[p-1]==2)
            {
                twinprimes.push_back(p-1);
            }
        }
    }
}
int main()
{
    seive();

    long int S,i,res;

    while(scanf("%ld",&S)==1)
    {
        res=twinprimes[S-1];
        //res=S;
        printf("(%ld, %ld)\n",primes[res],primes[res+1]);
    }

    return 0;
}
