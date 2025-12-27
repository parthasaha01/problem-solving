#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[50005],s[50005],r[50005],cn[1000005];
int main()
{
    ll tt; scanf("%lld",&tt);

    for(ll ks=1; ks<=tt; ks++)
    {
        ll d,n; scanf("%lld%lld",&d,&n);

        for(ll i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
        }

        s[0]=0;
        for(ll i=1; i<=n; i++)
        {
            s[i] = s[i-1]+a[i];
        }

        r[0]=0;
        for(ll i=1; i<=n; i++)
        {
            r[i] = s[i]%d;
        }

        memset(cn,0,sizeof(cn));
        ll ans = 0;
        for(ll i=n; i>=1; i--)
        {
            cn[r[i]]++;
            ll v = r[i-1];
            ans += cn[v];
        }

        printf("%lld\n",ans);
    }
    return 0;
}

