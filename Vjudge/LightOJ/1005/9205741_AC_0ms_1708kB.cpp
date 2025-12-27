#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
ll ncr[35][35],npr[35][35];
void preCalculation()
{
    ncr[0][0]=1, ncr[0][1]=0;
    for(int n=1; n<=30; n++){
        ncr[n][0]=1;
        for(int r=1; r<=n; r++){
            ncr[n][r] = ncr[n-1][r] + ncr[n-1][r-1];
        }
    }

    for(int n=1; n<=30; n++){
        npr[n][0]=1;
        for(int r=1; r<=n; r++){
           ll sum = 1;
           for(ll k=n-r+1; k<=n; k++) sum*=k;
           npr[n][r] = sum;
        }
    }
}
int main()
{
    preCalculation();

    int tt; scanf("%d",&tt);
    for(int ks=1; ks<=tt; ks++)
    {
        ll n,k; scanf("%llu%llu",&n,&k);
        if(k>n){ printf("Case %d: 0\n",ks); continue; }
        ll ans = ncr[n][k] * npr[n][k];
        printf("Case %d: %llu\n",ks,ans);
    }
    return 0;
}
