#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100005
ll a[mx];
int main()
{
    int tt; scanf("%d",&tt);

    for(int ks=1; ks<=tt; ks++)
    {
        ll n;
        scanf("%lld",&n);

        for(int i=1; i<=n; i++){
            scanf("%lld",&a[i]);
        }

        ll xr = 0L;

        for(int i=1; i<=n; i++){
            xr ^= a[i];
        }

        ll ans = 9223372036854775807;

        for(int i=1; i<=n; i++)
        {
            ll cn = xr^a[i];
            cn = abs(a[i]-cn);
            ans = min(ans,cn);
        }

        printf("%lld\n",ans);
    }

    return 0;
}
