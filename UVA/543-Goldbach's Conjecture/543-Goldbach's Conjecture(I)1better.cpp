#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define Max 1000000
#define sq 1000
bool isPrime[Max];
vector<long> primes;
void seive()
{
    long int i,j,doubleI;

    primes.push_back(2);

    for(i=3;i<=Max;i+=2)
        isPrime[i]=true;

    for (i=3; i<=sq; i+=2)
    {
        if(isPrime[i])
        {
            primes.push_back(i);

            doubleI = i * 2;

            for (j=i*i; j<Max; j+=doubleI)
                isPrime[j] = false;

        }
    }
    for(i=sq+1; i<=Max; i+=2)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
        }
    }
}
int main()
{
    seive();

    long int n,diff,i;

    while(scanf("%ld",&n) && n)
    {
        bool flag=false;

        for(i=0; primes[i]+primes[i]<=n; i++)
        {
            diff=n-primes[i];

            if(diff&1==1 && isPrime[diff]==true)
            {
                printf("%ld = %ld + %ld\n", n, primes[i], diff);
                flag=true;
                break;
            }
        }

        if(flag==false)
            printf("Goldbach's conjecture is wrong.\n");
    }

    return 0;
}
