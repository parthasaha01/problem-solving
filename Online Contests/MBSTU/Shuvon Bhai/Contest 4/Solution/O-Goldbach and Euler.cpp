#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
#define Max 100000000
#define sq 10000
bool isPrime[Max];
vector<long> primes;
void seive()
{
    long int i,j,doubleI;
    primes.push_back(2);

    for(i=1;i<=Max;i+=2)
        isPrime[i]=true;

    for (i=3; i<=sq; i+=2)
    {
        if(isPrime[i])
        {
            primes.push_back(i);

            doubleI = i<<1;

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
int FindPos(long int valueWanted)
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
    seive();

    long int N,diff,i,HN,pos,num1,num2;

    while(scanf("%ld",&N)==1)
    {
        bool flag=false;

        if(N>4)
        {
            if(N&1) // N is ODD
            {
                diff=N-2;   // diff is always odd
                if(isPrime[diff]==true)
                {
                    flag=true;
                    num1=2;
                    num2=diff;
                }

            }
            else    // N is Even
            {
                HN=(N>>1)-1;    // HN = (N/2)-1
                pos=FindPos(HN);

                if (primes[pos] > HN)
                    --pos;

                for(i=pos; i>=0; i--)
                {
                    diff=N-primes[i];

                    if((diff&1)==1 && isPrime[diff]==true)
                    {
                        flag=true;
                        num1=primes[i];
                        num2=diff;
                        break;
                    }
                }
            }

        }


        if(flag==true)
            printf("%ld is the sum of %ld and %ld.\n",N,num1,num2);
        else
            printf("%ld is not the sum of two primes!\n",N);
    }

    return 0;
}

