#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll dp[105][105],cum[105],a[105];
ll MCM(int b,int e)
{
    if(b==e)return 0LL;
    if(dp[b][e]!=-1)return dp[b][e];

    ll ret=100000000000000000;
    for(int i=b; i<e; i++)
    {
        ll ret1 = MCM(b,i);
        ll ret2 = MCM(i+1,e);
        ll sum = ret1+ret2+(((cum[i]-cum[b-1])%100)*((cum[e]-cum[i])%100));
        ret = min(ret,sum);
    }

    return dp[b][e] = ret;
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        cum[0]=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            cum[i]=cum[i-1]+a[i];
        }

        memset(dp,-1,sizeof(dp));
        ll ans = MCM(1,n);
        printf("%lld\n",ans);
    }
    return 0;
}
