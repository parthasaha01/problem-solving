#include<bits/stdc++.h>
using namespace std;
#define Mx 4000002
bool notPrime[Mx+1];
long phi[Mx+1];
void TotientPhi()
{
    long int i,j;
    phi[1]=1;

    for(i=2; i<=Mx; i+=2)
        phi[i]=(i>>1);    //i/2

    for(i=3; i<=Mx; i+=2)
        phi[i]=i;

    for (i=3; i<=Mx; i+=2)
    {
        if(!notPrime[i])//if i is prime
        {
            phi[i]=i-1;

            for (j=i+i; j<=Mx; j+=i)
            {
                phi[j] /= i;
                phi[j] *= (i-1);

                notPrime[j]=true;
            }

        }
    }
}
long long ExtremeGcd(long N)
{
    long i,d,n;
    long long sum=0;
    for(d=2; d<=N/2; d++)
    {
        n=(N/d);
        i=(n*(n+1))/2;
        sum += phi[d]*i;    // sum += d*phi((i*d)/d)
    }
    for(d=(N/2)+1; d<=N; d++)
    {
        sum += phi[d];
    }

    return sum;
}
int main()
{
    TotientPhi();
    long N;
    long long sum;

    while(cin >> N && N)
    {
        sum=ExtremeGcd(N);
        cout << sum << endl;
    }

    return 0;
}
