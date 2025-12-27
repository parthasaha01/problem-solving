#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000005],p,q,n;
ll fun(ll v)
{
    ll ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]<v){
            ans += (p*(v-a[i]));
        }
        else{
            ans += (q*(a[i]-v));
        }
    }
    return ans;
}
int main()
{
    int t; scanf("%d",&t);

    for(int ks=1; ks<=t; ks++)
    {
        ll mn=1000000000000,mx=0;
        scanf("%lld %lld %lld",&n,&p,&q);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&a[i]);
            mn = min(mn,a[i]);
            mx = max(mx,a[i]);
        }

        ll ans = 1000000000000000005;

        ll lo = mn;
        ll hi = mx;

        while(lo<=hi)
        {
            ll md1 = lo+(hi-lo)/3;
            ll md2 = hi-(hi-lo)/3;

            ll v1 = fun(md1);
            ll v2 = fun(md2);

            ans = min(ans,v1);
            ans = min(ans,v2);

            if(v1>v2){
                lo = md1+1;
            }
            else{
                hi = md2-1;
            }
        }

        printf("%lld\n",ans);
    }
    return 0;
}
