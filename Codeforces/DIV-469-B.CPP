#include<bits/stdc++.h>
using namespace std;
#define ll long long int
map<ll,int>mp;
int main()
{
    ll n,m;
    scanf("%I64d %I64d",&n,&m);

    ll sum = 0;
    mp.clear();
    for(ll i=1; i<=n; i++)
    {
        ll x; scanf("%I64d",&x);
        sum += x;
        mp[sum] = 1;
    }

    ll cnt = 0;
    ll ans = 0;
    for(ll i=1; i<=m; i++)
    {
        ll x; scanf("%I64d",&x);
        cnt += x;
        if(mp.find(cnt)!=mp.end())ans++;
    }

    printf("%I64d\n",ans);

    //main();

    return 0;
}
