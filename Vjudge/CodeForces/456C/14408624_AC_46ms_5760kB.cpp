#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[100005],cnt[100005],dp[100005];
ll fun(ll pos)
{
    if(pos>100000)return 0LL;
    if(dp[pos]!=-1)return dp[pos];
    ll ret = 0;
    ret = max(ret,(pos*cnt[pos]) + fun(pos+2));
    ret = max(ret,fun(pos+1));
    return dp[pos] = ret;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)cin>>a[i];
    for(int i=1; i<=n; i++)cnt[a[i]]++;

    memset(dp,-1,sizeof(dp));
    ll ans = fun(1);
    cout << ans << endl;
    return 0;
}
