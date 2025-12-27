#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll dp[805][2005];
ll fun(int b,int r)
{
    if(b==0){
        if(r<=0)return 1;
        else return 0;
    }
    if(r<=0)return 1;

    if(dp[b][r]!=-1)return dp[b][r];

    ll ret=0;
    for(int i=0; i<=6; i++){
        ret += fun(b-1,r-i);
    }
    return dp[b][r] = ret%mod;
}
int main()
{
    int tt; scanf("%d",&tt);
    memset(dp,-1,sizeof(dp));

    for(int ks=1; ks<=tt; ks++)
    {
        int b,r; scanf("%d%d",&b,&r);
        ll ans = fun(b,r);
        printf("Case %d: %lld\n",ks,ans);
    }

    return 0;
}
