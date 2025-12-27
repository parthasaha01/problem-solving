#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
int lp[mx+5];
int phi[mx+5];
vector<int>prime;
void sieve()
{
    phi[1] = 1;
    for (int i=2; i<=mx; i++)
    {
        if (lp[i]==0)
        {
            lp[i] = i;
            phi[i] = i-1;
            prime.push_back(i);
        }
        else //Calculating phi
        {
            if (lp[i]==lp[i/lp[i]])
            {
                phi[i] = phi[i/lp[i]] * lp[i];
            }
            else
            {
                phi[i] = phi[i/lp[i]] * (lp[i]-1);
            }
        }

        for (int j=0; j<prime.size() && prime[j]<=lp[i] && i*prime[j]<=mx; j++)
        {
            lp[i*prime[j]] = prime[j];
        }
    }
}
int main()
{
    sieve();

    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",phi[n]);
    }

    return 0;
}
