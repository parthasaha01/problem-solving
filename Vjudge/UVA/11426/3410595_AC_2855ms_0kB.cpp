#include<bits/stdc++.h>
using namespace std;
#define Mx 4000002
bool notPrime[Mx+1];
long phi[Mx+1];
long long result[Mx+1];
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
void ExtremeGcd()
{
    long i,d;
    for(d=1; d<=Mx/2; d++)
    {
        for(i=2; i*d<=Mx; i++)
        {
            result[i*d] += d*phi[i];    // result[i*d] += d*phi((i*d)/d)
        }
    }

    for(i=2; i<=Mx; i++)
        result[i]+=result[i-1];
}
int main()
{
    TotientPhi();
    ExtremeGcd();
    long N;

    while(cin >> N && N)
    {
        cout << result[N] << endl;
    }

    return 0;
}
