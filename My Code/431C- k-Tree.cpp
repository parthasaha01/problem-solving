#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007LL
int n,k,d;
ll dp[105][2];
ll fun(int p, int f)
{
    if(p<0)return 0LL;
    if(p==0 && f==1)return 1LL;
    if(p==0 && f==0)return 0LL;

    if(dp[p][f]!=-1)return dp[p][f];

    ll ret = 0;
    for(int i=1; i<=k; i++)
    {
        ret += fun(p-i,f|(i>=d))%MOD;
        ret %= MOD;
    }
    return dp[p][f] = ret;
}
int main()
{
    cin>>n>>k>>d;
    memset(dp,-1,sizeof(dp));
    ll ans = fun(n,0);
    cout << ans << endl;
    return 0;
}
