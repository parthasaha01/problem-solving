#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define Mx 1000002
#define sq 1000
vector<bool> isPrime(Mx, true);
vector<long> primes;
int Mxdiff = 115;
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
int FindPos(long value)
{
    int lb,ub,mid;
    lb=0;
    ub=primes.size()-1;

    while (lb < ub)
    {
        mid = (lb + ub) / 2;

        if (primes[mid] > value)
            ub = mid-1;    // ub = mid, its also work
        else if (primes[mid] < value)
            lb = mid + 1;
        else
            return mid;
    }

    return lb;
}
int main()
{
    sieve();
    int T;
    long LB,UB,i;

    cin >> T;

    while (T--)
    {
        cin >> LB >> UB;

        int Min=FindPos(LB);
        int Max=FindPos(UB);


        if (primes[Min] < LB)
            ++Min;

        if (primes[Max] > UB)
            --Max;

        vector<int> diffCnt(Mxdiff, 0);

        for (i=Min+1; i<=Max; i++)
        {
            ++diffCnt[primes[i]-primes[i-1]];
        }

        int highest = 0, number = -1;

        for (i=0; i < Mxdiff; ++i)
        {
            if (diffCnt[i]>highest)
            {
                highest = diffCnt[i];
                number = i;
            }
            else if (diffCnt[i]==highest)
                number = -1;
        }

        if(number == -1)
            cout << "No jumping champion" << endl;
        else
            cout << "The jumping champion is " << number << endl;
    }

    return 0;
}
