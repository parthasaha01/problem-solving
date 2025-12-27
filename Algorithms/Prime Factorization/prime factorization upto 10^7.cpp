#include<bits/stdc++.h>
using namespace std;
#define mx 100000000
#define sq 10000
long prime[100];
int num[mx];
void sieve()
{
    long i,j;

    for(i=4; i<=mx; i+=2)
        num[i]=2;

    for(i=3; i<=sq; i+=2)
    {
        if(num[i]==0)
        {
            //num[i]=i;
            for(j=i+i; j<=mx; j+=i)
            {
                num[j]=i;
            }
        }
    }
}
int main()
{
    sieve();
    long N,k,i;
    while(cin >> N && N)
    {
        cout << N << " = ";
        if(N==1)
        {
            cout << "1" << endl;
            continue;
        }

        k=0;

        while(N!=1)
        {
            if(num[N]==0)//N is prime &&
            {
                prime[k++]=N;
                break;
            }
            prime[k++]=num[N];
            N/=num[N];
        }
        sort(prime,prime+k);

        printf("%ld",prime[0]);

        for(i=1; i<k; i++)
        {
            printf(" * %ld",prime[i]);
        }
        cout << endl;
    }

    return 0;
}
