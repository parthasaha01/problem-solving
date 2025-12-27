#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005],s[5005],dp[5005];
ll fun(ll pos)
{
    if(pos>n)return 0LL;

    if(dp[pos]!=-1)return dp[pos];

    ll ret=0,maxx=0;
    for(ll i=0; pos+i<=n; i++)
    {
        ll v = s[pos+i]^s[pos-1];
        ret = v + fun(pos+i+1);
        maxx = max(maxx,ret);
    }

    return dp[pos] = maxx;
}
int main()
{
    while(scanf("%I64d",&n)==1)
    {

        for(ll i=1; i<=n; i++){
            scanf("%I64d",&a[i]);

        }

        s[0]=0;
        for(ll i=1; i<=n; i++){
            s[i] = s[i-1]^a[i];
        }

        memset(dp,-1,sizeof(dp));

        ll ans = fun(1);

        printf("%I64d\n",ans);

    }
    return 0;
}
