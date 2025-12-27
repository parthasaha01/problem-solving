#include<bits/stdc++.h>
using namespace std;
#define Mx 1000005
#define sq 1000
vector<bool> isPrime(Mx, true);
vector<long> primes;
void sieve()
{
    long i,j;
    primes.push_back(2);
    for (i=3; i<=sq; i+=2){
        if (isPrime[i]){
            primes.push_back(i);
            for (j=i*i; j<=Mx; j+=i+i)
                isPrime[j] = false;
        }
    }
    for(i=sq+1; i<=Mx; i+=2)
        if(isPrime[i])
            primes.push_back(i);
}
int main()
{
    sieve();
    int T,i,Min,Max;
    long LB,UB;

    cin >> T;

    while (T--)
    {
        cin >> LB >> UB;

        Min=lower_bound(primes.begin(),primes.end(),LB) - primes.begin();
        Max=lower_bound(primes.begin(),primes.end(),UB) - primes.begin();

        if(primes[Max]>UB)
            --Max;

        for(i=Min; i<=Max; i++)
            cout << primes[i] << endl;
        cout << endl;
    }

    return 0;
}

