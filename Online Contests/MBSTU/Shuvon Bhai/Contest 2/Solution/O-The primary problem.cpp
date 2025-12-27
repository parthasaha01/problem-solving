#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int FindPos(const vector<long int>& primes, int valueWanted)
{
    int min(0), max(primes.size() - 1), mid;

    while (min < max)
    {
        mid = (min + max) / 2;

        if (primes[mid] > valueWanted)
            max = mid-1;    // max = mid, its also work
        else if (primes[mid] < valueWanted)
            min = mid + 1;
        else
            return mid;
    }

    return min;
}
int main()
{
    vector<bool> isPrime(1000000, true);
    vector<long int> primes;
    primes.push_back(2);

    for (long long i=3; i<1000000; i+=2)
    {
        if (isPrime[i])
        {
            primes.push_back(i);

            long long doubleI = i * 2;

            for (long long j=i*i; j<1000000; j+=doubleI)
                isPrime[j] = false;

        }
    }

    long int N,sum,flag,i,j;

    while (scanf("%ld",&N) && N)
    {
        int max=FindPos(primes, N);

        if (primes[max] > N)
            --max;

        flag=0;
        i=0;
        j=max;

        while(i<max && i<=j)
        {
            sum = primes[i]+primes[j];

            if(sum<N)
            {
                i++;
            }
            else if(sum>N)
            {
                j--;
            }
            else
            {
                flag = 1;
                break;
            }
        }

        if(flag)
        {
            printf("%ld:\n%ld+%ld\n",N,primes[i],primes[j]);
        }
        else
        {
            printf("%ld:\nNO WAY!\n",N);
        }

    }

    return 0;
}
