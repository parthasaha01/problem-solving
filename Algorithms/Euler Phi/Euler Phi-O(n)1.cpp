#include<bits/stdc++.h>
using namespace std;
#define mx 1000002
int lp[mx+5];   //lp[i] minimal prime divisor of i.
int phi[mx+5];  //phi[mx+5]-phi Table upto mx
vector<int>pr;  // all prime upto mx
void sieve()
{
    phi[1] = 1;
    for (int i=2; i<=mx; i++)
    {
        if (lp[i]==0)
        {
            lp[i] = i;
            phi[i] = i-1;
            pr.push_back(i);
        }
        else //Calculating phi
        {
            if (lp[i]==lp[i/lp[i]])
                phi[i] = phi[i/lp[i]] * lp[i];
            else
                phi[i] = phi[i/lp[i]] * (lp[i]-1);
        }
        int sz=pr.size();
        for (int j=0; j<sz && pr[j]<=lp[i] && i*pr[j]<=mx; j++)
        {
            lp[i*pr[j]] = pr[j];
        }
    }
}
int main()
{
    sieve();

    int t; scanf("%d",&t);

    while(t--)
    {
        int n; scanf("%d",&n);
        printf("%d\n",phi[n]);
    }
    return 0;
}

