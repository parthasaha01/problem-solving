#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
#define Max 32000
#define sqt 178

int isPrime[Max];
vector<int> primes;
void seive()
{
    long int i,j,doubleI;
    primes.push_back(2);

    for (i=3; i<=sqt; i+=2)
    {
        if(!isPrime[i])
        {
            primes.push_back(i);

            doubleI = i<<1; //i/2

            for (j=i*i; j<Max; j+=doubleI)
                isPrime[j] = 1;

        }
    }
    for(i=sqt+1; i<=Max; i+=2)
    {
        if(!isPrime[i])
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

    int T;
    cin >> T;

    while (T--)
    {
        long int m,n,i,j,temp,flag;
        cin >> m >> n;

        if(n<=32000)
        {
            int min=FindPos(m);

            if (primes[min] < m)
                ++min;

            for(i=min; primes[i]<=n; i++)
            {
                cout << primes[i] << endl;
            }
        }
        else
        {
            if(m<3)
            {
                cout << "2" << endl;
                m=3;
            }

            if((m&1)==0)
                m++;

            for(i=m; i<=n; i+=2)
            {
                flag=0; //prime

                temp=sqrt(i);

                for(j=0; primes[j]<=temp; j++)
                {
                    if(i%primes[j] == 0)
                    {
                        flag=1; //not prime
                        break;
                    }
                }

                if(flag==0)
                    cout << i << endl;
            }


        }

        cout << endl;
    }

    return 0;
}
