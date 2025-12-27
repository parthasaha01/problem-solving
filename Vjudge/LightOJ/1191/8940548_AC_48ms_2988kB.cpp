#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[55][55][55];
int n,k,m;
ll fun(int pos,int bar)
{
    if(pos==0 && bar==0)return 1;
    if(pos==0 && bar!=0)return 0;
    if(pos<0 || bar<0)  return 0;

    if(dp[pos][bar][m]!=-1)
        return dp[pos][bar][m];

    ll ret=0;
    for(int i=1; i<=m; i++)
        ret+=fun(pos-i,bar-1);

    return dp[pos][bar][m] = ret;
}
int main()
{
    int tt; scanf("%d",&tt);
    memset(dp,-1,sizeof(dp));
    
    for(int ks=1; ks<=tt; ks++)
    {
        scanf("%d%d%d",&n,&k,&m);
        ll ans = fun(n,k);
        printf("Case %d: %lld\n",ks,ans);
    }
    return 0;
}
