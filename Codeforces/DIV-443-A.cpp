#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define mx 100005
ll n,s[1005],d[1005];
int main()
{
    ll n; scanf("%I64d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%I64d %I64d",&s[i],&d[i]);
    }

    ll ans = 0;
    ll pre = 0;
    for(ll i=1; i<=n; i++)
    {
        ll x = s[i];
        ll y = d[i];

        while(x<=pre)
        {
            x = x+y;
        }
        pre = x;
        ans = x;
    }

    printf("%I64d",ans);

    return 0;
}
