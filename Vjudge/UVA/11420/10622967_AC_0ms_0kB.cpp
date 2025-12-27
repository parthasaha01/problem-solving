#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[70][70][2];
int n,s;
ll fun(int p,int k,int f)
{
    if(k<0)return 0LL;

    if(p==0){
        if(k==0)return 1LL;
        return 0LL;
    }

    if(dp[p][k][f]!= -1)return dp[p][k][f];

    ll ret = 0;
    ret += fun(p-1,k,0);

    if(f==0)ret += fun(p-1,k,1);
    else ret += fun(p-1,k-1,1);

    return dp[p][k][f] = ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));

    while(scanf("%d%d",&n,&s)==2)
    {
        if(n<0&&s<0)break;

        ll ans = fun(n,s,1);

        printf("%lld\n",ans);
    }

    return 0;
}
